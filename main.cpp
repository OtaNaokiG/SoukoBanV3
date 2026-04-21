#include "DxLib.h"

#include"SceneManager.h"
#include"Handles.h"
#include"Variables.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    SetWindowText("Soukoban");
    SetGraphMode(screenWIDTH, screenHEIGHT, 32);
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;
    SetBackgroundColor(245, 235, 210);
    SetDrawScreen(DX_SCREEN_BACK);

    LoadImages();//âÊëúÇì«Ç›çûÇﬁ
    SceneManager sceneManager;

    while (true) {

        if (ProcessMessage() == -1) break;
        if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

        ClearDrawScreen();

        sceneManager.Update();
        sceneManager.Draw();

        ScreenFlip();

        WaitTimer(1000 / 60);
    }

    DxLib_End();
    return 0;
}