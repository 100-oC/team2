#pragma once
#include"../FrameRate/FrameRate.h"
#include"../Input/Input.h"
#include"../Sound/Sound.h"
#include"../MathPlus/MathPlus.h"

#include"../TimeLimit/TimeLimit.h"

// define
#define	SCREEN_SIZE_X	800	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	600	// Y方向の画面サイズを指定

enum SCENE_ID
{
	//タイトルシーンID
	SCENE_ID_INIT_TITLE,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//プレイシーンID
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//クリアシーンID
	SCENE_ID_INIT_CLEAR,
	SCENE_ID_LOOP_CLEAR,
	SCENE_ID_FIN_CLEAR,

	//ゲームオーバーシーンID
	SCENE_ID_INIT_GAMEOVER,
	SCENE_ID_LOOP_GAMEOVER,
	SCENE_ID_FIN_GAMEOVER,
};

//　現在のシーンID
extern SCENE_ID g_CurrentSceneId;

extern int score;		//スコア
extern int viewScore;	//表示用スコア