#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneGameOver.h"
#include "../Input/Input.h"

//画像

//BGM

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {}

// ゲームオーバー初期化
void SceneGameOver::InitGameOver() {
	// ゲームオーバー画像の読込

	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_GAMEOVER;
}

// ゲームオーバー通常処理
void SceneGameOver::StepGameOver() {

}

// ゲームオーバー描画処理
void SceneGameOver::DrawGameOver() {
	//画像描画

}

//ゲームオーバー終了処理
void SceneGameOver::FinGameOver() {

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
