#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"
#include "../TimeLimit/TimeLimit.h"
#include "../Mole/Mole.h"

TimeLimit timeLimit;
Mole mole;

int score;		//�X�R�A
int viewScore;	//�\���p�X�R�A

float scoreAddCountTime; //�X�R�A���Z�J�E���g

//�摜

//BGM

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// �Q�[���v���C������
void ScenePlay::InitPlay() 
{
	//�J�E���g���Z�b�g
	scoreAddCountTime = 0.0f;
	//�X�R�A���Z�b�g
	score = 0;
	viewScore = 0;

	//���Ԑ���
	timeLimit.Init();
	//���O��
	mole.Init();

	// �v���C�摜�̓Ǎ�
		
	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �Q�[���v���C�ʏ폈��
void ScenePlay::StepPlay() 
{
	timeLimit.Step();	//���Ԑ���
	mole.Step();	//���O��

	//�X�R�A���Z�̃J�E���g
	scoreAddCountTime += 1.0f / FRAME_RATE;
	//�w��̎��ԂɂȂ�����
	if (scoreAddCountTime >= 0.1f)
	{
		//�J�E���g�����Z�b�g
		scoreAddCountTime = 0.0f;
		//�\���p���X�R�A��菬����������
		if (score > viewScore)
		{
			//���Z
			viewScore++;
		}
		//�\���p���X�R�A���傫��������
		else if (score < viewScore)
		{
			//���Z
			viewScore--;
		}
		//�\���p�ƃX�R�A��������������
		else
		{
			//�Œ�
			viewScore = score;
		}
	}
}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() 
{
	//�摜�`��
	timeLimit.Draw();	//���Ԑ���
	mole.Draw();	//���O��

	//�����̑傫���ύX
	SetFontSize(40);
	DrawFormatString(650, 50, GetColor(255, 255, 255), "�X�R�A");
	SetFontSize(30);
	DrawFormatString(700, 100, GetColor(255, 255, 255), "%d",viewScore);
	//�����̑傫�������ɖ߂�
	SetFontSize(20);
}

//�Q�[���v���C�I������
void ScenePlay::FinPlay() 
{
	timeLimit.Fin();
	mole.Fin();

	//BGM�㏈��

	//�N���A�t���O���m�F���đJ�ڐ������
	/*if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}*/
}

void ScenePlay::InitScreen()
{
	//ScreenX = PlayerX - SCREEN_SIZE_X / 2;
}

//�X�N���[���̃��[���h���W
void ScenePlay::StepScreen()
{
	//ScreenX = PlayerX + 200 - SCREEN_SIZE_X / 2;
}
