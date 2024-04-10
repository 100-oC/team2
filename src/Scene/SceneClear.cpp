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
	// ゲームオーバー画像の読込
	handle = LoadGraph(resultImagePath);

	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// ゲームクリア通常処理
void SceneClear::StepClear() 
{
	//エンターかスペースを押したら
	if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE) ||
		Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneId = SCENE_ID_FIN_CLEAR;
	}
}

// ゲームクリア描画処理
void SceneClear::DrawClear() 
{
	//画像描画
	DrawGraph(0, 0, handle, true);

	//文字の大きさ変更
	SetFontSize(60);
	DrawFormatString(300, 250, GetColor(0, 0, 0), "スコア");
	SetFontSize(50);
	DrawFormatString(370, 320, GetColor(0, 0, 0), "%d", viewScore);
	//文字の大きさを元に戻す
	SetFontSize(20);
}

//ゲームクリア終了処理
void SceneClear::FinClear() 
{

	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
