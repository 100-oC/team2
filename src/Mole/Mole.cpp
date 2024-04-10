#include"DxLib.h"
#include"../Scene/Scene.h"
#include"Mole.h"

//初期化
void Mole::Init()
{
	//画像読み込み
	for (int i = 0; i < MOLE_MAX_NUM; i++)
	{
		moleHandle[i] = LoadGraph(MOLE_IMAGE_PATH[i]);		//モグラ
		groundHandle[i] = LoadGraph(GROUND_IMAGE_PATH[i]);	//地面
	}

	//各モグラの変数初期化
	for (int i = 0; i < 9; i++)
	{
		y[i] = 0;				//座標
		isUse[i] = false;		//使用フラグ
		outTime[i] = 0.0f;		//出ている時間
		moleNum[i] = 0;			//モグラの種類
		isAttack[i] = false;	//たたいたフラグ
	}

	//出現インターバル
	popCountTime = 0.0f;
}

//通常処理
void Mole::Step()
{
	Pop();	//出現
	Move();	//動き
}

//描画
void Mole::Draw()
{
	//モグラ789
	if (isUse[6])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2 - 150, 180 - y[6], 1.0f, 0.0f, moleHandle[moleNum[6]], true);
	}
	if (isUse[7])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, 180 - y[7], 1.0f, 0.0f, moleHandle[moleNum[7]], true);
	}
	if (isUse[8])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2 + 150, 180 - y[8], 1.0f, 0.0f, moleHandle[moleNum[8]], true);
	}
	
	//地面789
	DrawRotaGraph(SCREEN_SIZE_X / 2, 200, 1.0f, 0.0f, groundHandle[2], true);

	//=================================

	//モグラ456
	if (isUse[3])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2 - 150, 330 - y[3], 1.0f, 0.0f, moleHandle[moleNum[3]], true);
	}
	if (isUse[4])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, 330 - y[4], 1.0f, 0.0f, moleHandle[moleNum[4]], true);
	}
	if (isUse[5])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2 + 150, 330 - y[5], 1.0f, 0.0f, moleHandle[moleNum[5]], true);
	}
	
	//地面456
	DrawRotaGraph(SCREEN_SIZE_X / 2, 350, 1.0f, 0.0f, groundHandle[1], true);

	//==================================
	
	//モグラ123
	if (isUse[0])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2 - 150, 480 - y[0], 1.0f, 0.0f, moleHandle[moleNum[0]], true);
	}
	if (isUse[1])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, 480 - y[1], 1.0f, 0.0f, moleHandle[moleNum[1]], true);
	}
	if (isUse[2])
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2 + 150, 480 - y[2], 1.0f, 0.0f, moleHandle[moleNum[2]], true);
	}
	
	//地面123
	DrawRotaGraph(SCREEN_SIZE_X / 2, 500, 1.0f, 0.0f, groundHandle[0], true);

}

//終了処理
void Mole::Fin()
{

}

//出現
void Mole::Pop()
{
	//カウント
	popCountTime += 1.0f / FRAME_RATE;

	//指定の時間になったら
	if (popCountTime >= 0.3f)
	{
		popCountTime = 0.0f;	//時間のリセット

		//2分の一で出現
		if (GetRand(1) == 0)
		{
			int popNum = GetRand(8);	//出現番号

			//出現番号が使用中でなければ以下
			if (!isUse[popNum])
			{
				isUse[popNum] = true;	//使用中
				y[popNum] = 0;	//出現用座標

				outTime[popNum] = GetRand(1) + 1;	//出現してる時間(1~2)

				//モグラの種類を設定
				int moleN = GetRand(9);	//0~9

				if		(moleN >= 0 && moleN <= 6)
				{
					moleNum[popNum] = NORMAL_MOLE;	//ノーマルモグラ
				}

				else if (moleN >= 7 && moleN <= 8)
				{
					moleNum[popNum] = DAMAGE_MOLE;	//ダメージモグラ
				}

				else if ( moleN <= 9)
				{
					moleNum[popNum] = SPECIAL_MOLE;	//スペシャルモグラ
				}
				
			}
		}
	}
}

//動き
void Mole::Move()
{
	//穴の個数回す
	for (int i = 0; i < 9; i++)
	{
		//使用されていたら以下
		if (isUse[i])
		{
			//出現
			if (y[i] < 30&& outTime[i]>0)
			{
				y[i] += 4;
			}

			//出現していたら
			else
			{
				//出現時間を減少
				outTime[i] -= 1.0f / FRAME_RATE;

				//0以下になったら
				if (outTime[i] <= 0)
				{
					//地面に戻る
					if (y[i] > 0)
					{
						y[i] -= 5;
					}

					//戻ったら
					else
					{
						//座標を固定
						y[i] = 0;
						//使用フラグを折る
						isUse[i] = false;
					}
				}

				//出現中
				else
				{
					//出ているところが押されていたら
					if (i == KeyPush())
					{
						//たたかれたことにする
						isAttack[i] = true;
					}
				}
			}
		}

		//たたかれていたら
		if (isAttack[i])
		{
			//引っこ抜く
			if (y[i] < 50)
			{
				y[i] += 5;
			}
			else
			{
				//フラグ折る
				isUse[i] = false;
				isAttack[i] = false;

				//得点を加算及び減算
				switch (moleNum[i])
				{
				case NORMAL_MOLE:

					score += NORMAL_POINT;

					break;

				case SPECIAL_MOLE:

					score += SPECIAL_POINT;

					break;

				case DAMAGE_MOLE:

					score += DAMAGE_POINT;

					break;

				default:
					break;
				}
			}
		}
	}
}

//どのキーを押されていたか（テンキー対応）
int Mole::KeyPush()
{
	if (Input::Key::Push(KEY_INPUT_NUMPAD1))
	{
		return 0;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD2))
	{
		return 1;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD3))
	{
		return 2;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD4))
	{
		return 3;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD5))
	{
		return 4;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD6))
	{
		return 5;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD7))
	{
		return 6;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD8))
	{
		return 7;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD9))
	{
		return 8;
	}

	return -1;
}