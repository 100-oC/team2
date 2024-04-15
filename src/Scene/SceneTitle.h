#pragma once

enum TITLE_IMAGE
{
	TITLE_BACKGROUND,
	TITLE_TITLE,
	TITLE_GROUND,
	TITLE_GEMESTART,

	TITLE_MAX_NUM,
};

const char TITLE_IMAGE_PATH[TITLE_MAX_NUM][255] =
{
	"data/title/backGround.png",
	"data/title/title.png",
	"data/title/ground.png",
	"data/title/gameStart.png",
};

//�^�C�g���N���X
class SceneTitle {
private:
	int handle[TITLE_MAX_NUM];

	int y[TITLE_MAX_NUM];

	int fade;

	bool lighting;
	int progress;

public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// �^�C�g��������

	void StepTitle();		// �^�C�g���ʏ폈��

	void DrawTitle();		// �^�C�g���`�揈��

	void FinTitle();		// �^�C�g���I������
};