#include "app.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

double nextBeatTime = GetTime();
float beatsPerMinute = 60.0f;
float bpm = beatsPerMinute;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RayMetronome");
  InitAudioDevice();
  SetTargetFPS(60);

  // TODO: Get a better tick sound
  Sound tickSound = LoadSound("res/sound/tick_sound.ogg");

  // set window ontop every window
  SetWindowState(FLAG_WINDOW_TOPMOST);

  // attempting to center the WindowShouldClose
  SetWindowPosition((GetScreenWidth() / 2 * 3.5), GetScreenHeight() / 2);

  while (!WindowShouldClose()) {
    // physics stuffs?
    {

      // calculate timing and play beat
      double currentTime = GetTime(); // gets time in which program started
      if (currentTime >= nextBeatTime) {
        PlaySound(tickSound);
        nextBeatTime += 60.0 / bpm;
      }
    }

    // rendering stuffs?
    {
      BeginDrawing();
      ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

      // raygui stuffs?
      {
        // draw bpm value
        DrawText(TextFormat("BPM: %.0f", bpm), (SCREEN_WIDTH / 2) - 50,
                 (SCREEN_HEIGHT / 2) - 50, 30, BLACK);

        //  Draw bpm slider
        GuiSlider(
            (Rectangle){(SCREEN_WIDTH / 2) - 50, SCREEN_HEIGHT / 2, 100, 20},
            "0", "200", &bpm, 0.0f, 200.0f);
      }

      // actual drawing stuffs?
      {
      }
      EndDrawing();
    }
  }
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
