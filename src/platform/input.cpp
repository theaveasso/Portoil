#include "input.h"
#include "pt_math.h"
#include <raylib.h>

void GatherInput(input_frame &Input)
{
  Input.Move = vec2{
    .X = static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A)),
    .Y = static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W)),
  };
  Input.Fire = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
  Input.DashPressed |= IsKeyPressed(KEY_SPACE);
  Input.HurtPressed |= IsKeyPressed(KEY_H);
}

void TakeTickCommands(input_frame &Input, std::vector<command> &Out)
{
  Out.clear();
  Out.push_back({ .Type = command_type::MOVE, .Direction = Input.Move });
  if (Input.Fire) { Out.push_back({ .Type = command_type::FIRE }); }
  if (Input.DashPressed) {
    Out.push_back({ .Type = command_type::DASH });
    Input.DashPressed = false;
  }
  if (Input.HurtPressed) {
    Out.push_back({ .Type = command_type::DEBUG_HURT });
    Input.HurtPressed = false;
  }
}
