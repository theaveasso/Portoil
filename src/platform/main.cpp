#include <cstdlib>

#include <raylib.h>
#include <vector>

#include "app.h"
#include "checksum.h"
#include "command.h"
#include "entity.h"
#include "input.h"
#include "loop.h"
#include "pt_math.h"
#include "sprite_atlas.h"
#include "world.h"
#include <cassert>

#if defined(PT_PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr const char *APP_TITLE = "LanternWatch";
constexpr const int TARGET_FPS = 60;

constexpr int MAX_COMMANDS = 8;

constexpr int PLAYER_COUNT = 3;

struct frame_state
{
  loop_state LoopState = {};
  world World = {};
#if not defined(NDEBUG)
  world Shadow = {};
#endif
  Texture2D Atlas = {};
  input_frame Input = {};
  std::vector<command> Commands;
  int ControlledPlayer = 0;
  int TickCounted = 0;
  int TickPerSecond = 0;
  float SecondTimer = 0;
};

static Camera2D GetCamera()
{
  Camera2D Result = {};
  Result.zoom = Min(static_cast<float>(GetScreenWidth()) / ARENA_WIDTH, static_cast<float>(GetScreenHeight()) / ARENA_HEIGHT);
  Result.offset = {
    .x = (static_cast<float>(GetScreenWidth()) - (ARENA_WIDTH * Result.zoom)) / 2,
    .y = (static_cast<float>(GetScreenHeight()) - (ARENA_HEIGHT * Result.zoom)) / 2,
  };
  return Result;
};

static void UpdateDrawFrame(void *Args)
{
  frame_state &State = *static_cast<frame_state *>(Args);
  BeginDrawing();
  ClearBackground(BLACK);

  int Tick = LoopAdvance(State.LoopState, GetFrameTime());
  State.TickCounted += Tick;
  State.SecondTimer += GetFrameTime();
  if (State.SecondTimer > 1) {
    State.TickPerSecond = State.TickCounted;
    State.TickCounted = 0;
    State.SecondTimer -= 1;
  }

  if (IsKeyPressed(KEY_TAB)) { State.ControlledPlayer = (State.ControlledPlayer + 1) % State.World.PlayerCount; }
  entity &Player = State.World.Entities[State.ControlledPlayer];
  GatherInput(State.Input, GetCamera(), Player.Transform.CurrPosition);
  for (int Index = 0; Index < Tick; ++Index) {
    State.Commands.clear();
    TakeTickCommands(State.Input, State.ControlledPlayer, State.Commands);
    TickWorld(State.World, State.Commands);
#if not defined(NDEBUG)
    TickWorld(State.Shadow, State.Commands);
    assert(GetWorldChecksum(State.World) == GetWorldChecksum(State.Shadow));
#endif
  }

  BeginMode2D(GetCamera());
  DrawRectangleLines(0, 0, ARENA_WIDTH, ARENA_HEIGHT, GRAY);
  for (entity &Entity : State.World.Entities) {
    vec2 Position = Vec2Lerp(Entity.Transform.PrevPosition, Entity.Transform.CurrPosition, LoopAlpha(State.LoopState));
    DrawCircleV(Vector2{ .x = Position.X, .y = Position.Y }, Entity.Transform.Radius, Entity.Health.Hp > 0 ? BLUE : RED);
  }
  for (projectile &Item : State.World.Projectiles.Items) {
    if (!Item.Active) { continue; }
    vec2 ItemPosition = Vec2Lerp(Item.PrevPosition, Item.CurrPosition, LoopAlpha(State.LoopState));
    DrawCircleV(Vector2{ .x = ItemPosition.X, .y = ItemPosition.Y }, PROJECTILE_RADIUS, RED);
  }

  DrawCircleV(Vector2{ .x = State.World.Hearth.Position.X, .y = State.World.Hearth.Position.Y }, 50, YELLOW);
  EndMode2D();
  EndDrawing();
}

int main()
{
  const app_def AppDef = { .Width = WINDOW_WIDTH, .Height = WINDOW_HEIGHT, .Title = APP_TITLE, .TargetFPS = TARGET_FPS };
  InitApp(&AppDef);

  frame_state State;

  world_def WorldDef = { .Width = ARENA_WIDTH, .Height = ARENA_HEIGHT, .PlayerCount = PLAYER_COUNT };

  InitWorld(&WorldDef, State.World);
#if not defined(NDEBUG)
  InitWorld(&WorldDef, State.Shadow);
#endif

  State.Atlas = LoadTexture("assets/0x72_dungeon.png");
  SetTextureFilter(State.Atlas, TEXTURE_FILTER_POINT);

  State.Commands.reserve(MAX_COMMANDS);
#if defined(PT_PLATFORM_WEB)
  emscripten_set_main_loop_arg(UpdateDrawFrame, &State, 0, true);
#else
  while (!AppShouldClose()) { UpdateDrawFrame(&State); }
#endif

  UnloadTexture(State.Atlas);
  ShutdownApp();
  return EXIT_SUCCESS;
}
