#pragma once
//ƒL[ó‘ÔE“ü—Í‚ğŠÇ—
class Input
{
private:
    char key[256] = {};
    char oldKey[256] = {};

public:
    void Update();

    bool Press(int keyCode);     // ‰Ÿ‚µ‚½uŠÔ
    bool Trigger(int keyCode);   // ‰Ÿ‚µ‚Á‚Ï‚È‚µ
};

