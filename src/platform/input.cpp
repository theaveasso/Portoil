#include "input.h"
#include "config.h"
#include "pt_math.h"

void GatherInput(input_frame &Input, const Camera2D &Camera, const vec2 &PlayerPosition)
{
  Input.Move = vec2{
    .X = static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A)),
    .Y = static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W)),
  };
  Vector2 ScreenToWorld = GetScreenToWorld2D(GetMousePosition(), Camera);
  Input.Aim = Vec2Sub({ .X = ScreenToWorld.x, .Y = ScreenToWorld.y }, PlayerPosition);
  Input.Fire = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
  Input.DashPressed |= IsKeyPressed(KEY_SPACE);
  Input.HurtPressed |= IsKeyPressed(KEY_H);
}

void TakeTickCommands(input_frame &Input, int PlayerIndex, std::vector<command> &Out)
{
  Out.push_back({ .PlayerIndex = static_cast<uint8_t>(PlayerIndex), .Type = command_type::MOVE, .Direction = Input.Move });
  if (Vec2Length(Input.Aim) > PLAYER_RADIUS) {
    Out.push_back({ .PlayerIndex = static_cast<uint8_t>(PlayerIndex), .Type = command_type::AIM, .Direction = Input.Aim });
  }
  if (Input.Fire) { Out.push_back({ .PlayerIndex = static_cast<uint8_t>(PlayerIndex), .Type = command_type::FIRE }); }
  if (Input.DashPressed) {
    Out.push_back({ .PlayerIndex = static_cast<uint8_t>(PlayerIndex), .Type = command_type::DASH });
    Input.DashPressed = false;
  }
  if (Input.HurtPressed) {
    Out.push_back({ .PlayerIndex = static_cast<uint8_t>(PlayerIndex), .Type = command_type::DEBUG_HURT });
    Input.HurtPressed = false;
  }
}
