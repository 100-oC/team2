#pragma once

enum RISULT_IMAGE
{
	RISULT_BACKGROIND,
	
	RISULT_MO1,
	RISULT_MO2,
	RISULT_MO3,
	RISULT_MO4,

	RISULT_GROIND,

	RISULT_MAX_NUM,
};

const char RISULT_IMAGE_PATH[RISULT_MAX_NUM][255] =
{
	"data/result/backGround.png",
	"data/result/mo1.png",
	"data/result/mo2.png",
	"data/result/mo3.png",
	"data/result/mo4.png",
	"data/result/ground.png",
};

class SceneClear {
private:
	int handle[RISULT_MAX_NUM];
	int y[RISULT_MAX_NUM];

	int scoreY;

	int progress;

	int fade;

public:
	SceneClear();
	~SceneClear();

	void InitClear();		// �N���A������

	void StepClear();		// �N���A�ʏ폈��

	void DrawClear();		// �N���A�`�揈��

	void FinClear();		//�N���A�I������

};
