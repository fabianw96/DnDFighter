//
// Created by wittg on 19/09/2024.
//

#include "WindowManager.h"

void WindowManager::CreateGameWindow()
{
    InitWindow(screenWidth, screenheight, "DnDFighter");    
    SetTargetFPS(60);

    ManageGameWindow();
}

void WindowManager::ManageGameWindow()
{
    GameScreen currentScreen = GS_LOGO;

    char name[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;

    Rectangle textBox = { screenWidth/2.0f - 100,180,450,50 };
    bool mouseOnText = false;

    int framesCounter = 0;
    
    while (!WindowShouldClose())
    {
        //Update
        
        switch (currentScreen)
        {
        case GS_LOGO:
            {
                framesCounter++;
                if (framesCounter > 120)
                {
                    currentScreen = GS_TITLE;
                }
            }
            break;
        case GS_TITLE:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GS_GAMEPLAY;
                }

                if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
                else mouseOnText = false;

                if (mouseOnText)
                {
                    SetMouseCursor(MOUSE_CURSOR_IBEAM);

                    int key = GetCharPressed();

                    while (key > 0)
                    {
                        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                        {
                            name[letterCount] = static_cast<char>(key);
                            name[letterCount + 1] = '\0';
                            letterCount++;
                        }

                        key = GetCharPressed();
                    }

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCount--;
                        if (letterCount < 0) letterCount = 0;
                        name[letterCount] = '\0';
                    }
                }
                else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

                if (mouseOnText) framesCounter ++;
                else framesCounter = 0;
            }
            break;
        case GS_GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GS_ENDING;
                }
            }
            break;
        case GS_ENDING:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GS_TITLE;
                }
            }
            break;
        }

        //Drawing
        BeginDrawing();

        switch (currentScreen)
        {
        case GS_LOGO:
            {
                DrawText("LOGO SCREEN", 20, 20, 40,LIGHTGRAY);
                DrawText("Wait for 2 Seconds...", screenWidth / 2.0f, screenheight / 2.0f, 20, GRAY);
            }
            break;
        case GS_TITLE:
            {
                DrawRectangle(0,0,screenWidth,screenheight, GREEN);
                DrawText("Title Screen", 20,20,40,DARKGREEN);
                DrawText("Hover over the Text box and enter you name.", textBox.x,textBox.y - 20,20, DARKGREEN);
                
                //Input box
                DrawRectangleRec(textBox, LIGHTGRAY);
                if (mouseOnText) DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, RED);
                else DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, DARKGRAY);

                DrawText(name, textBox.x + 5, textBox.y + 8, 40, MAROON);

                if (mouseOnText)
                {
                    if (letterCount < MAX_INPUT_CHARS)
                    {
                        if (((framesCounter/20) % 2) == 0) DrawText("_", textBox.x + 8 + MeasureText(name, 40), textBox.y + 12, 40, MAROON);
                    }
                    else DrawText("Press BACKSPACE to delete chars", textBox.x, textBox.y + 70, 20, GRAY);

                }
                
                DrawText("Click Enter to continue.", textBox.x,textBox.y + 90,20, DARKGREEN);
            }
            break;
        case GS_GAMEPLAY:
            {
                DrawRectangle(0,0,screenWidth,screenheight, PURPLE);
                DrawText("Gameplay Screen", 20,20,40,MAROON);
                DrawText(name, 120,220,20, MAROON);
            }
            break;
        case GS_ENDING:
            {
                DrawRectangle(0,0,screenWidth,screenheight, BLUE);
                DrawText("Ending Screen", 20,20,40,DARKBLUE);
                DrawText("Press Enter or Click to jump to next Screen", 120,220,20, DARKBLUE);
            }
            break;
        }
        
        EndDrawing();
    }

    CloseWindow();
}

