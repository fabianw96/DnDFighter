//
// Created by wittg on 19/09/2024.
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "raylib.h"
#define MAX_INPUT_CHARS 9


class WindowManager {
private:
    typedef enum E_GameScreen
    {
        GS_LOGO = 0,
        GS_TITLE,
        GS_GAMEPLAY,
        GS_ENDING
    } GameScreen;
    
    const int screenWidth = 1920;
    const int screenheight = 1080;
public:
    void CreateGameWindow();
    void ManageGameWindow();
};



#endif //WINDOWMANAGER_H
