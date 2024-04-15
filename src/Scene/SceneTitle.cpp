#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"

//�摜�Ǎ�
const char titleImagePath[] = { "data/title/title.png" };

//BGM

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// �^�C�g��������
void SceneTitle::InitTitle() 
{
	for (int i = 0; i < TITLE_MAX_NUM; i++)
	{
		// �^�C�g���摜�̓Ǎ�
		handle[i] = LoadGraph(TITLE_IMAGE_PATH[i]);
		y[i] = 0;
	}

	y[TITLE_TITLE] = 400;
	y[TITLE_GROUND] = 100;

	fade = 0;
	lighting = false;
	progress = 0;

	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle() 
{
	switch (progress)
	{
	case 0:	//��ʍ��

		//�n��
		if (y[TITLE_GROUND] <= 0)
		{
			y[TITLE_GROUND] = 0;
		}
		else
		{
			y[TITLE_GROUND] -= 2.0f;
		}

		//�^�C�g��
		if (y[TITLE_TITLE] <= 0)
		{
			y[TITLE_TITLE] = 0;
		}
		else
		{
			y[TITLE_TITLE] -= 5.0f;
		}

		//�ȏオ�������Ă���Ɛi�s
		if (y[TITLE_GROUND] == 0 && y[TITLE_TITLE] == 0)
		{
			progress++;
		}

		break;

	case 1:	//���͑҂�

		//UI�̓_��
		//�����
		if (lighting)
		{
			fade += 5;

			if (fade >= 255)
			{
				lighting = false;
			}
		}
		//������
		else
		{
			fade -= 5;

			if (fade <= 0)
			{
				lighting = true;
			}
		}

		//�G���^�[���X�y�[�X����������
		if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE) ||
			Input::Mouse::Push(MOUSE_INPUT_LEFT)|| Input::Key::Push(KEY_INPUT_NUMPADENTER))
		{
			g_CurrentSceneId = SCENE_ID_FIN_TITLE;
		}

		break;


	default:
		break;
	}

	//��ʖ��������ɍ��N���b�N�Ŋ���
	if (progress != 1)
	{
		if (Input::Mouse::Push(MOUSE_INPUT_LEFT) || Input::Key::Push(KEY_INPUT_RETURN)||
			Input::Key::Push(KEY_INPUT_NUMPADENTER))
		{
			//���W�̐ݒ�
			y[TITLE_GROUND] = 0;
			y[TITLE_TITLE] = 0;

			//���͑҂���
			progress = 1;
		}
	}
	
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle() 
{
	for (int i = 0; i < TITLE_MAX_NUM-1; i++)
	{
		//�摜�`��
		DrawGraph(0, y[i], handle[i], true);
	}
	

	//fade�œ����x�ύX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	DrawGraphF(0, y[TITLE_GEMESTART], handle[TITLE_GEMESTART], true);	//�^�C�g��
	//�\�������ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�^�C�g���I������
void SceneTitle::FinTitle() 
{
	//BGM�㏈��

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
