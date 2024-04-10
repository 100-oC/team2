#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//画像読込

//BGM

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// タイトル初期化
void SceneTitle::InitTitle() {
	// タイトル画像の読込

	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle() {

}

// タイトル描画処理
void SceneTitle::DrawTitle() {
	//画像描画

}

//タイトル終了処理
void SceneTitle::FinTitle() {
	//BGM後処理

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
