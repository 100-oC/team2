#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"

//画像読込
const char titleImagePath[] = { "data/title/title.png" };

//BGM

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// タイトル初期化
void SceneTitle::InitTitle() 
{
	for (int i = 0; i < TITLE_MAX_NUM; i++)
	{
		// タイトル画像の読込
		handle[i] = LoadGraph(TITLE_IMAGE_PATH[i]);
		y[i] = 0;
	}

	y[TITLE_TITLE] = 400;
	y[TITLE_GROUND] = 100;

	fade = 0;
	lighting = false;
	progress = 0;

	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle() 
{
	switch (progress)
	{
	case 0:	//画面作り

		//地面
		if (y[TITLE_GROUND] <= 0)
		{
			y[TITLE_GROUND] = 0;
		}
		else
		{
			y[TITLE_GROUND] -= 2.0f;
		}

		//タイトル
		if (y[TITLE_TITLE] <= 0)
		{
			y[TITLE_TITLE] = 0;
		}
		else
		{
			y[TITLE_TITLE] -= 5.0f;
		}

		//以上が完成していると進行
		if (y[TITLE_GROUND] == 0 && y[TITLE_TITLE] == 0)
		{
			progress++;
		}

		break;

	case 1:	//入力待ち

		//UIの点滅
		//現れる
		if (lighting)
		{
			fade += 5;

			if (fade >= 255)
			{
				lighting = false;
			}
		}
		//消える
		else
		{
			fade -= 5;

			if (fade <= 0)
			{
				lighting = true;
			}
		}

		//エンターかスペースを押したら
		if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE) ||
			Input::Mouse::Push(MOUSE_INPUT_LEFT)|| Input::Key::Push(KEY_INPUT_NUMPADENTER))
		{
			g_CurrentSceneId = SCENE_ID_FIN_TITLE;
		}

		break;


	default:
		break;
	}

	//画面未完成時に左クリックで完成
	if (progress != 1)
	{
		if (Input::Mouse::Push(MOUSE_INPUT_LEFT) || Input::Key::Push(KEY_INPUT_RETURN)||
			Input::Key::Push(KEY_INPUT_NUMPADENTER))
		{
			//座標の設定
			y[TITLE_GROUND] = 0;
			y[TITLE_TITLE] = 0;

			//入力待ちへ
			progress = 1;
		}
	}
	
}

// タイトル描画処理
void SceneTitle::DrawTitle() 
{
	for (int i = 0; i < TITLE_MAX_NUM-1; i++)
	{
		//画像描画
		DrawGraph(0, y[i], handle[i], true);
	}
	

	//fadeで透明度変更
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	DrawGraphF(0, y[TITLE_GEMESTART], handle[TITLE_GEMESTART], true);	//タイトル
	//表示を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//タイトル終了処理
void SceneTitle::FinTitle() 
{
	//BGM後処理

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
