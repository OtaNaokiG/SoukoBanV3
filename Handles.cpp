#include "Handles.h"

int BoxGHandle;
int GreenBoxGHandle;
int GreenSpotGHandle;
int GroundGHandle;
int WallGHandle;

//Uiたち
int GoBackGHandle;
int PauseGHandle;
int RetryGHandle;
int MenuGHandle;
int PlayGHandle;
int PlayButtonGHandle;

//プレイヤー画像
int PFront;
int PBack;
int PLeft;
int PRight;

void LoadImages() {
    BoxGHandle = LoadGraph("Images/Inviroment/Box.png");
    GreenBoxGHandle = LoadGraph("Images/Inviroment/GreemBox.png");
    GreenSpotGHandle = LoadGraph("Images/Inviroment/GreenSpot.png");
    GroundGHandle = LoadGraph("Images/Inviroment/Ground.png");
    WallGHandle = LoadGraph("Images/Inviroment/Wall.png");
    //プレイヤー画像
    PFront = LoadGraph("Images/Player/PFront.png");
    PBack = LoadGraph("Images/Player/PBack.png");
    PLeft = LoadGraph("Images/Player/PLeft.png");
    PRight = LoadGraph("Images/Player/PRight.png");
    //UI
    GoBackGHandle = LoadGraph("Images/Ui/GoBack.png");
    PauseGHandle = LoadGraph("Images/Ui/Pause.png");
    RetryGHandle = LoadGraph("Images/Ui/Retry.png");
    MenuGHandle = LoadGraph("Images/Ui/Menu.png");
    PlayGHandle = LoadGraph("Images/Ui/Play.png");
    PlayButtonGHandle = LoadGraph("Images/Ui/PlayButton.png");
}