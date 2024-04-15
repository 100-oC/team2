#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Mole/Mole.h"

TimeLimit timeLimit;
Mole mole;

int score;		//スコア
int viewScore;	//表示用スコア

float scoreAddCountTime; //スコア加算カウント

//画像

//BGM

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// ゲームプレイ初期化
void ScenePlay::InitPlay() 
{
	//カウントリセット
	scoreAddCountTime = 0.0f;
	//スコアリセット
	score = 0;
	viewScore = 0;

	//時間制限
	timeLimit.Init();
	//モグラ
	mole.Init();

	for (int i = 0; i < PLAY_IMAGE_MAX_NUM; i++)
	{
		handle[i] = LoadGraph(PLAY_IMAGE_PATH[i]);
	}

	Effect::Init();
	Effect::Load(EFFECT_TYPE_PIKO, 10);
	Effect::Load(EFFECT_TYPE_PIKOHAN, 10);
		
	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() 
{
	timeLimit.Step();	//時間制限
	mole.Step();	//モグラ

	//スコア加算のカウント
	scoreAddCountTime += 1.0f / FRAME_RATE;
	//指定の時間になったら
	if (scoreAddCountTime >= 0.1f)
	{
		//カウントをリセット
		scoreAddCountTime = 0.0f;
		//表示用がスコアより小さかったら
		if (score > viewScore)
		{
			//加算
			viewScore++;
		}
		//表示用がスコアより大きかったら
		else if (score < viewScore)
		{
			//減算
			viewScore--;
		}
		//表示用とスコアが同じだったら
		else
		{
			//固定
			viewScore = score;
		}
	}

	Effect::Step();
}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() 
{
	for (int i = 0; i < PLAY_IMAGE_MAX_NUM; i++)
	{
		DrawGraph(0, 0, handle[i], true);
	}

	//画像描画
	timeLimit.Draw();	//時間制限
	mole.Draw();	//モグラ

	Effect::Draw();

	//文字の大きさ変更
	SetFontSize(40);
	DrawFormatString(650, 50, GetColor(255, 255, 255), "スコア");
	SetFontSize(30);
	DrawFormatString(700, 100, GetColor(255, 255, 255), "%d",viewScore);
	//文字の大きさを元に戻す
	SetFontSize(20);
}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() 
{
	timeLimit.Fin();
	mole.Fin();

	//BGM後処理

	//クリアフラグを確認して遷移先を決定
	/*if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}*/
}

void ScenePlay::InitScreen()
{
	//ScreenX = PlayerX - SCREEN_SIZE_X / 2;
}

//スクリーンのワールド座標
void ScenePlay::StepScreen()
{
	//ScreenX = PlayerX + 200 - SCREEN_SIZE_X / 2;
}
