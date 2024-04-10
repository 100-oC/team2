#pragma once

const int MOLE_POP_TIME = 1;	//出現時間

enum MOLE
{
	NORMAL_MOLE,
	SPECIAL_MOLE,
	DAMAGE_MOLE,

	MOLE_MAX_NUM,
};

const int NORMAL_POINT = 1;
const int SPECIAL_POINT = 5;
const int DAMAGE_POINT = -3;

const char MOLE_IMAGE_PATH[3][255] =
{
	"data/play/normalMole.png",
	"data/play/specialMole.png",
	"data/play/damageMole.png",
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
	int groundHandle[3];	//地面の画像ハンドル

	int y[9];	//座標
	int moleNum[9];	//モグラの種類
	bool isUse[9];	//使用フラグ
	bool isAttack[9];	//たたいたフラグ

	float outTime[9];	//出現してる時間

	float popCountTime;	//出現時間カウント

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	int KeyPush();
	void Pop();
	void Move();

};