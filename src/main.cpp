//ウィンドウを表示するプログラム（ひな形）

#include"DxLib.h"	//DXライブラリのインクルード
#include"Scene/Scene.h"
#include "Scene/SceneTitle.h"
#include "Scene/ScenePlay.h"
#include "Scene/SceneClear.h"
#include "Scene/SceneGameOver.h"

// 現在のシーンID
SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//ウィンドウの名前を変える
	SetMainWindowText("もぐらたたき");

	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く

	Input::Init();
	SceneTitle  Title;			// クラス宣言
	ScenePlay   Play;
	SceneClear clear;
	SceneGameOver gameover;


	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//フレームレート管理
		if (FPS())
		{
			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//エスケープキーが押されたら終了
				break;
			}

			//画面に表示されたものを初期化
			ClearDrawScreen();

			Input::Step();

			//-----------------------------------------
			//ここからゲームの本体を書くことになる
			//-----------------------------------------
			switch (g_CurrentSceneId)
			{
			case SCENE_ID_INIT_TITLE:
			{
				// タイトルの初期化
				Title.InitTitle();
			}
			break;
			case SCENE_ID_LOOP_TITLE:
			{
				// タイトルの通常処理
				Title.StepTitle();

				// タイトルの描画処理
				Title.DrawTitle();
			}
			break;
			case SCENE_ID_FIN_TITLE:
			{
				// タイトルの初期化
				Title.FinTitle();
			}
			break;
			case SCENE_ID_INIT_PLAY:
			{
				// プレイ画面初期化
				Play.InitPlay();

				//スクリーン座標初期化
				Play.InitScreen();


			}
			break;
			case SCENE_ID_LOOP_PLAY:
			{
				// プレイの通常処理
				Play.StepPlay();

				// プレイの描画処理
				Play.DrawPlay();

				//スクリーン座標の設定
				Play.StepScreen();
			}
			break;
			case SCENE_ID_FIN_PLAY:
			{
				// プレイ終了
				Play.FinPlay();
			}
			break;
			case SCENE_ID_INIT_CLEAR:
			{
				// クリア画面初期化
				clear.InitClear();
			}
			break;
			case SCENE_ID_LOOP_CLEAR:
			{
				// クリア画面通常処理
				clear.StepClear();

				// クリア画面の描画
				clear.DrawClear();
			}
			break;
			case SCENE_ID_FIN_CLEAR:
			{
				// プレイ終了
				clear.FinClear();
			}
			break;
			case SCENE_ID_INIT_GAMEOVER:
			{
				// ゲームオーバー画面初期化
				gameover.InitGameOver();
			}
			break;
			case SCENE_ID_LOOP_GAMEOVER:
			{
				// ゲームオーバー画面通常処理
				gameover.StepGameOver();

				// ゲームオーバー画面の描画
				gameover.DrawGameOver();
			}
			break;
			case SCENE_ID_FIN_GAMEOVER:
			{
				// プレイ終了
				gameover.FinGameOver();
			}
			break;
			default:
				break;
			}




			//-----------------------------------------
			//ループの終わりに

			//FPS計算
			CalcFPS();

			//FPS表示（デバック用）
			DrawFPS();

			//フリップ関数
			ScreenFlip();
		}
	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

