#pragma once

enum TITLE_IMAGE
{
	TITLE_BACKGROUND,
	TITLE_TITLE,
	TITLE_GROUND,
	TITLE_GEMESTART,

	TITLE_MAX_NUM,
};

const char TITLE_IMAGE_PATH[TITLE_MAX_NUM][255] =
{
	"data/title/backGround.png",
	"data/title/title.png",
	"data/title/ground.png",
	"data/title/gameStart.png",
};

//タイトルクラス
class SceneTitle {
private:
	int handle[TITLE_MAX_NUM];

	int y[TITLE_MAX_NUM];

	int fade;

	bool lighting;
	int progress;

public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// タイトル初期化

	void StepTitle();		// タイトル通常処理

	void DrawTitle();		// タイトル描画処理

	void FinTitle();		// タイトル終了処理
};