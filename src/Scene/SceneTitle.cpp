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
	// タイトル画像の読込
	handle = LoadGraph(titleImagePath);

	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle() 
{
	//エンターかスペースを押したら
	if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE)||
		Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void SceneTitle::DrawTitle() 
{
	//画像描画
	DrawGraph(0, 0, handle,true);
}

//タイトル終了処理
void SceneTitle::FinTitle() 
{
	//BGM後処理

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
