#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneClear.h"
#include "../Input/Input.h"

//画像読込
const char resultImagePath[] = { "data/result/result.png" };

SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// ゲームクリア初期化
void SceneClear::InitClear() 
{
	for (int i = 0; i < RISULT_MAX_NUM; i++)
	{
		// ゲームクリア画像の読込
		handle[i] = LoadGraph(RISULT_IMAGE_PATH[i]);

		y[i] = 0;
	}

	scoreY = -300;

	y[RISULT_MO1] = 400;
	y[RISULT_MO2] = 400;
	y[RISULT_MO3] = 400;
	y[RISULT_MO4] = 400;
	
	y[RISULT_GROIND] = 200;

	progress = 0;

	fade = 0;

	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// ゲームクリア通常処理
void SceneClear::StepClear() 
{
	switch (progress)
	{
	case 0:	//スコア表示

		if (y[RISULT_GROIND] <= 0)
		{
			y[RISULT_GROIND] = 0;
		}
		else
		{
			y[RISULT_GROIND] -= 3;
		}

		//モグラ１
		if (y[RISULT_MO1] <= 0)
		{
			y[RISULT_MO1] = 0;
		}
		else
		{
			y[RISULT_MO1] -= 5;
		}

		if (y[RISULT_MO1] < 200)
		{
			if (y[RISULT_MO2] <= 0)
			{
				y[RISULT_MO2] = 0;
			}
			else
			{
				y[RISULT_MO2] -= 5;
			}
		}

		if (y[RISULT_MO2] < 200)
		{
			if (y[RISULT_MO3] <= 0)
			{
				y[RISULT_MO3] = 0;
			}
			else
			{
				y[RISULT_MO3] -= 5;
			}
		}

		if (y[RISULT_MO3] < 200)
		{
			if (y[RISULT_MO4] <= 0)
			{
				y[RISULT_MO4] = 0;
			}
			else
			{
				y[RISULT_MO4] -= 5;
			}
		}

		//以上が指定通りなら進行
		if (y[RISULT_MO4] == 0)
		{
			progress++;
		}

		break;

	case 1:

		//スコアの透明度
		if (fade >= 255)
		{
			fade = 255;
		}
		else
		{
			fade += 2;
		}
		//スコアの座標
		if (scoreY >= 0)
		{
			scoreY = 0;
		}
		else
		{
			scoreY += 1;
		}

		//以上が指定通りなら進行
		if (fade == 255 && scoreY == 0)
		{
			progress++;
		}

		break;

	case 2:	//入力待ち

		//エンターかスペースを押したら
		if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE) ||
			Input::Mouse::Push(MOUSE_INPUT_LEFT) || Input::Key::Push(KEY_INPUT_NUMPADENTER))
		{
			g_CurrentSceneId = SCENE_ID_FIN_CLEAR;
		}

		break;


	default:
		break;
	}
	
}

// ゲームクリア描画処理
void SceneClear::DrawClear() 
{
	for (int i = 0; i < RISULT_MAX_NUM; i++)
	{
		//画像描画
		DrawGraph(0, y[i], handle[i], true);
	}

	//fadeで透明度変更
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	//文字の大きさ変更
	SetFontSize(60);
	DrawFormatString(300, 150+ scoreY, GetColor(0, 0, 0), "スコア");
	SetFontSize(50);
	DrawFormatString(370, 220+ scoreY, GetColor(0, 0, 0), "%d", viewScore);
	//文字の大きさを元に戻す
	SetFontSize(20);
	//表示を元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//ゲームクリア終了処理
void SceneClear::FinClear() 
{

	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
