#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"


//画像

//BGM

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// ゲームプレイ初期化
void ScenePlay::InitPlay() {
	// プレイ画像の読込
		
	//BGM読込

	//BGM再生

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// ゲームプレイ通常処理
void ScenePlay::StepPlay() {

}

// ゲームプレイ描画処理
void ScenePlay::DrawPlay() {
	//画像描画
}

//ゲームプレイ終了処理
void ScenePlay::FinPlay() {
	//BGM後処理

	//クリアフラグを確認して遷移先を決定
	if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}
}

void ScenePlay::InitScreen()
{
	ScreenX = PlayerX - SCREEN_SIZE_X / 2;
}

//スクリーンのワールド座標
void ScenePlay::StepScreen()
{
	ScreenX = PlayerX + 200 - SCREEN_SIZE_X / 2;
}
