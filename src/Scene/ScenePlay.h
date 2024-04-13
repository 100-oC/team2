#pragma once

enum PLAY_IMAGE
{
	PLAY_BACKGR,
	PLAY_FRAME,

	PLAY_IMAGE_MAX_NUM,
};

const char PLAY_IMAGE_PATH[2][255] =
{
	"data/play/background.png",
	"data/play/frame.png",
};

class ScenePlay {
private:
	int handle[PLAY_IMAGE_MAX_NUM];	//�摜�n���h��

public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		// �N���A������

	void StepPlay();		// �N���A�ʏ폈��

	void DrawPlay();		// �N���A�`�揈��

	void FinPlay();			//�v���C�I������

	void InitScreen();
	void StepScreen();
};