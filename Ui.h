#pragma once
#include "Variables.h"
#include "Handles.h"
#include <string>
static const int  buttonSize = 64;

struct LetterUi {
	Vector2 pos;
	const char* text = nullptr;
	int font = -1;
	unsigned int color = -1;

	void Draw() {
		//文字の幅を取得
		int width = GetDrawStringWidthToHandle(text, (int)strlen(text),font);
		int x = pos.x - width / 2;
		DrawStringToHandle(x, pos.y,text,color,font);
	}
};

struct Button {
	Vector2 pos;
	int w = buttonSize, h = buttonSize;
	int GHandle = -1;

	void SetButton(const Vector2& ppos, int handle) {
		pos = ppos;
		GHandle = handle;
	}

	void Draw() {
		DrawGraph(pos.x, pos.y, GHandle, TRUE);
	}

	//マウスが上に乗っているか
	bool IsHovered(Vector2 mouse) {
		return (mouse.x >= pos.x && mouse.x <= pos.x + w &&
			mouse.y >= pos.y && mouse.y <= pos.y + h);
	}

	//押されたか
	bool IsClicked(Vector2 mouse) {
		if (!IsHovered(mouse)) return false;

		static int prevMouse = 0;
		int nowMouse = GetMouseInput();

		bool clicked = (nowMouse & MOUSE_INPUT_LEFT) && !(prevMouse & MOUSE_INPUT_LEFT);

		prevMouse = nowMouse;

		return clicked;
	}
};


struct TwoLayerUi
{
private:
	Vector2 pos{ screenWIDTH / 2, screenHEIGHT / 2 };
	int w = 500, h = 200; //レイヤー１
	int w2 = 500, h2 =50; //レイヤー２
	std::string text;

	//箱の大きさ・位置
	int left = pos.x - w / 2;
	int right = pos.x + w / 2;
	int top = pos.y - h / 2;
	int bottom = pos.y + h / 2;
public:
	Button menuButton;
	Button PlayButton;

public:
	void SetTwoLayerUi(const std::string& ttext) {
		text = ttext; //文字をセット

		menuButton.SetButton(
			{ left , bottom  - buttonSize  - 18}, //微調整の18
			MenuGHandle
		);

		PlayButton.SetButton(
			{ right - buttonSize - 18, bottom - buttonSize -18},
			PlayGHandle
		);
	}


	void Draw() {

		// ===== メインボックス =====
		DrawBox(left, top, right, bottom, GetColor(255, 250, 240), TRUE);

		// ===== 上の小さいボックス =====
		int left2 = pos.x - w2 / 2;
		int right2 = pos.x + w2 / 2;

		int top2 = top - h2;     // 上にくっつける
		int bottom2 = top;          // メインの上端に接する

		DrawBox(left2, top2, right2, bottom2, GetColor(255, 150, 160), TRUE);

		// ===== 文字（レイヤー2中央）=====
		int strWidth = GetDrawStringWidth(text.c_str(), (int)text.size());
		int strHeight = 16; // フォントサイズに合わせる

		int centerY = (top2 + bottom2) / 2;

		DrawString(
			pos.x - strWidth / 2,
			centerY - strHeight / 2,
			text.c_str(),
			GetColor(255, 255, 255)
		);

		//ボタン
		menuButton.Draw();
		PlayButton.Draw();
	}
};