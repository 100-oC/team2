#pragma once

const int MOLE_POP_TIME = 1;	//出現時間

//モグラの種類
enum MOLE
{
	NORMAL_MOLE,	//普通
	SPECIAL_MOLE,	//特別
	DAMAGE_MOLE,	//障害
	TIME_MOLE,		//時間増加

	MOLE_MAX_NUM,	//種類数
};

//得点
const int NORMAL_POINT = 1;
const int SPECIAL_POINT = 5;
const int DAMAGE_POINT = -3;
const int TIME_POINT = 2;

//画像パス
const char MOLE_IMAGE_PATH[MOLE_MAX_NUM][255] =
{
	"data/play/normalMole.png",
	"data/play/specialMole.png",
	"data/play/damageMole.png",
	"data/play/timeUpMole.png",
};
//叩いたあと
const char MOLE_IMAGE_PATH2[MOLE_MAX_NUM][255] =
{
	"data/play/normalMole2.png",
	"data/play/specialMole2.png",
	"data/play/damageMole2.png",
	"data/play/timeUpMole2.png",
};


const char GROUND_IMAGE_PATH[3][255] =
{
	"data/play/ground1.png",
	"data/play/ground2.png",
	"data/play/ground3.png",
};

class Mole
{
private:
	int moleHandle[MOLE_MAX_NUM];	//もぐらハンドル
	int moleHandle2[MOLE_MAX_NUM];	//もぐらハンドル
	int groundHandle[3];	//地面の画像ハンドル

	int y[9];	//座標
	int defaultY[9];	//元の座標
	int x[9];
	int moleNum[9];	//モグラの種類
	bool isUse[9];	//使用フラグ
	bool isAttack[9];	//たたいたフラグ

	float outTime[9];	//出現してる時間

	float popCountTime;	//出現時間カウント

public:
	void Init();	//初期化
	void Step();	//通常処理
	void Draw();	//描画
	void Fin();		//終了処理

	int KeyPush();	//どのキー押したか
	void Pop();		//出現
	void Move();	//動き
	
};
