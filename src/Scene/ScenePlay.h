#pragma once

enum PLAY_IMAGE
{
	PLAY_BACKGR,
	PLAY_FRAME,

	PLAY_IMAGE_MAX_NUM,
};

const char PLAY_IMAGE_PATH[2][255] =
{
	"data/play/background.png",
	"data/play/frame.png",
};

class ScenePlay {
private:
	int handle[PLAY_IMAGE_MAX_NUM];	//画像ハンドル

public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		// クリア初期化

	void StepPlay();		// クリア通常処理

	void DrawPlay();		// クリア描画処理

	void FinPlay();			//プレイ終了処理

	void InitScreen();
	void StepScreen();
};