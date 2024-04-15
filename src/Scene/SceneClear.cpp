#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneClear.h"
#include "../Input/Input.h"

//�摜�Ǎ�
const char resultImagePath[] = { "data/result/result.png" };

SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// �Q�[���N���A������
void SceneClear::InitClear() 
{
	for (int i = 0; i < RISULT_MAX_NUM; i++)
	{
		// �Q�[���N���A�摜�̓Ǎ�
		handle[i] = LoadGraph(RISULT_IMAGE_PATH[i]);

		y[i] = 0;
	}

	scoreY = -300;

	y[RISULT_MO1] = 400;
	y[RISULT_MO2] = 400;
	y[RISULT_MO3] = 400;
	y[RISULT_MO4] = 400;
	
	y[RISULT_GROIND] = 200;

	progress = 0;

	fade = 0;

	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// �Q�[���N���A�ʏ폈��
void SceneClear::StepClear() 
{
	switch (progress)
	{
	case 0:	//�X�R�A�\��

		if (y[RISULT_GROIND] <= 0)
		{
			y[RISULT_GROIND] = 0;
		}
		else
		{
			y[RISULT_GROIND] -= 3;
		}

		//���O���P
		if (y[RISULT_MO1] <= 0)
		{
			y[RISULT_MO1] = 0;
		}
		else
		{
			y[RISULT_MO1] -= 5;
		}

		if (y[RISULT_MO1] < 200)
		{
			if (y[RISULT_MO2] <= 0)
			{
				y[RISULT_MO2] = 0;
			}
			else
			{
				y[RISULT_MO2] -= 5;
			}
		}

		if (y[RISULT_MO2] < 200)
		{
			if (y[RISULT_MO3] <= 0)
			{
				y[RISULT_MO3] = 0;
			}
			else
			{
				y[RISULT_MO3] -= 5;
			}
		}

		if (y[RISULT_MO3] < 200)
		{
			if (y[RISULT_MO4] <= 0)
			{
				y[RISULT_MO4] = 0;
			}
			else
			{
				y[RISULT_MO4] -= 5;
			}
		}

		//�ȏオ�w��ʂ�Ȃ�i�s
		if (y[RISULT_MO4] == 0)
		{
			progress++;
		}

		break;

	case 1:

		//�X�R�A�̓����x
		if (fade >= 255)
		{
			fade = 255;
		}
		else
		{
			fade += 2;
		}
		//�X�R�A�̍��W
		if (scoreY >= 0)
		{
			scoreY = 0;
		}
		else
		{
			scoreY += 1;
		}

		//�ȏオ�w��ʂ�Ȃ�i�s
		if (fade == 255 && scoreY == 0)
		{
			progress++;
		}

		break;

	case 2:	//���͑҂�

		//�G���^�[���X�y�[�X����������
		if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE) ||
			Input::Mouse::Push(MOUSE_INPUT_LEFT) || Input::Key::Push(KEY_INPUT_NUMPADENTER))
		{
			g_CurrentSceneId = SCENE_ID_FIN_CLEAR;
		}

		break;


	default:
		break;
	}
	
}

// �Q�[���N���A�`�揈��
void SceneClear::DrawClear() 
{
	for (int i = 0; i < RISULT_MAX_NUM; i++)
	{
		//�摜�`��
		DrawGraph(0, y[i], handle[i], true);
	}

	//fade�œ����x�ύX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	//�����̑傫���ύX
	SetFontSize(60);
	DrawFormatString(300, 150+ scoreY, GetColor(0, 0, 0), "�X�R�A");
	SetFontSize(50);
	DrawFormatString(370, 220+ scoreY, GetColor(0, 0, 0), "%d", viewScore);
	//�����̑傫�������ɖ߂�
	SetFontSize(20);
	//�\�������ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�Q�[���N���A�I������
void SceneClear::FinClear() 
{

	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
