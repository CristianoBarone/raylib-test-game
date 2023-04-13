#include <iostream>
#include <raylib.h>
#include <vector>
#include "classes.h"
#include "textures.h"
#include "scenes.h"

int w = 1600,h = 900;
char volume = 85;
bool movingVolumeSlider = false;
int prevKey = 0;
int prevScene = 0x100;
bool followingSequence = false;
bool debugMenu = false;
unsigned int λ = 0;
SaveHandler saveHandler;
Blinker blinker;

void displayScene() {
    switch (scene) {
        case 0:
            if (prevScene != scene) {
                background = LoadTexture("resources/graphical/scene0.png");
                prevScene = scene;
            }
            mainMenu();
            break;
        default:
            break;
    }
}

void drawMenu() {
    DrawRectangle(0, λ-25, w, 25, Color{45,45,45,255});
    DrawRectangle(35, λ-14, 100, 3, Color{255,255,255,200});

    DrawTexture(textureAudio, 7, λ-25, Color{255,255,255,255});
    DrawRectangle(35+(volume-2), λ-20, 4, 15, Color{255,255,255,200});

    DrawTexture(textureSave, 145, λ-25, Color{255,255,255,255});
    DrawTexture(textureLoad, 180, λ-25, Color{255,255,255,255});
}

int main(void) {
    std::cout << "Starting the game" << std::endl;
    InitWindow(w, h, "TEST WINDOW");
    setTextures();
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    SetExitKey(0);
    while (!WindowShouldClose())
    {
        int key = GetKeyPressed();

        if (blinker.opacity > 1)
            blinker.opacity -= 2;

        if (blinker.opacity > 0)
            blinker.radius -= .3f;

        if (IsMouseButtonPressed(0) && λ == 25 && GetMouseX() > 145 && GetMouseX() < 170)
            saveHandler.Save();

        if (IsMouseButtonPressed(0) && λ == 25 && GetMouseX() > 180 && GetMouseX() < 205)
            saveHandler.Load();

        if (IsMouseButtonDown(0) && λ == 25 && GetMouseX() > 35 && GetMouseX() < 135)
            movingVolumeSlider = true;

        if (movingVolumeSlider) {
            if (λ != 25 || IsMouseButtonUp(0) || GetMouseX() < 35) {
                movingVolumeSlider = false;
            } else {
                int mx = GetMouseX();
                GetMouseX() > 160 ? mx = 135 : 0;
                volume = mx - 35;
                if (volume > 100) volume = 100;
            }
        } else {
            if (IsMouseButtonPressed(0) && GetMouseY() > 25) {
                blinker.opacity = 0xAE;
                blinker.coords.first = GetMouseX();
                blinker.coords.second = GetMouseY();
                blinker.radius = 20;
            }
        }

        if (GetMouseY() < 25) {
            if (λ > 25) λ = 0;
            λ!=25 ? λ++:0;
        } else λ--;

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(("TEST WINDOW "+std::to_string(scene)).c_str(), ((w/2)-(MeasureText("TEST WINDOW", 20)/2)), h/2, 20, RAYWHITE);

            displayScene();

            DrawCircle(blinker.coords.first, blinker.coords.second, blinker.radius, Color{255,255,255,blinker.opacity});

            drawMenu();
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
