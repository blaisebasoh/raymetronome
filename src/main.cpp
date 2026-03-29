#include "app.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

bool showMessageBox = false;
int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RayMetronome");
  SetTargetFPS(60);

  // attempting to center the WindowShouldClose
  SetWindowPosition((GetScreenWidth() / 2 * 3.5), GetScreenHeight() / 2);

  while (!WindowShouldClose()) {
    // physics stuffs?
    {
    }

    // rendering stuffs?
    {
      BeginDrawing();
      ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

      // raygui stuffs?
      {
        if (GuiButton((Rectangle){24, 24, 120, 30}, "#191#Show Message"))
          showMessageBox = true;
        if (showMessageBox) {
          int result =
              GuiMessageBox((Rectangle){85, 70, 250, 100}, "#191#Message Box",
                            "Hi! This is a message!", "Nice;Cool");
          if (result >= 0)
            showMessageBox = false;
        }
      }

      // actual drawing stuffs?
      {
        DrawText("RayMetronome", (SCREEN_WIDTH / 2 - 100), SCREEN_HEIGHT / 2,
                 30, BLUE);
      }
      EndDrawing();
    }
  }
  return 0;
}
