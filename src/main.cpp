//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include"DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"Scene/Scene.h"
#include "Scene/SceneTitle.h"
#include "Scene/ScenePlay.h"
#include "Scene/SceneClear.h"
#include "Scene/SceneGameOver.h"

// ���݂̃V�[��ID
SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//�E�B���h�E�̖��O��ς���
	SetMainWindowText("÷İ");

	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���

	Input::Init();
	SceneTitle  Title;			// �N���X�錾
	ScenePlay   Play;
	SceneClear clear;
	SceneGameOver gameover;


	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		//�t���[�����[�g�Ǘ�
		if (FPS())
		{
			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			Input::Step();

			//-----------------------------------------
			//��������Q�[���̖{�̂��������ƂɂȂ�
			//-----------------------------------------
			switch (g_CurrentSceneId)
			{
			case SCENE_ID_INIT_TITLE:
			{
				// �^�C�g���̏�����
				Title.InitTitle();
			}
			break;
			case SCENE_ID_LOOP_TITLE:
			{
				// �^�C�g���̒ʏ폈��
				Title.StepTitle();

				// �^�C�g���̕`�揈��
				Title.DrawTitle();
			}
			break;
			case SCENE_ID_FIN_TITLE:
			{
				// �^�C�g���̏�����
				Title.FinTitle();
			}
			break;
			case SCENE_ID_INIT_PLAY:
			{
				// �v���C��ʏ�����
				Play.InitPlay();

				//�X�N���[�����W������
				Play.InitScreen();


			}
			break;
			case SCENE_ID_LOOP_PLAY:
			{
				// �v���C�̒ʏ폈��
				Play.StepPlay();

				// �v���C�̕`�揈��
				Play.DrawPlay();

				//�X�N���[�����W�̐ݒ�
				Play.StepScreen();
			}
			break;
			case SCENE_ID_FIN_PLAY:
			{
				// �v���C�I��
				Play.FinPlay();
			}
			break;
			case SCENE_ID_INIT_CLEAR:
			{
				// �N���A��ʏ�����
				clear.InitClear();
			}
			break;
			case SCENE_ID_LOOP_CLEAR:
			{
				// �N���A��ʒʏ폈��
				clear.StepClear();

				// �N���A��ʂ̕`��
				clear.DrawClear();
			}
			break;
			case SCENE_ID_FIN_CLEAR:
			{
				// �v���C�I��
				clear.FinClear();
			}
			break;
			case SCENE_ID_INIT_GAMEOVER:
			{
				// �Q�[���I�[�o�[��ʏ�����
				gameover.InitGameOver();
			}
			break;
			case SCENE_ID_LOOP_GAMEOVER:
			{
				// �Q�[���I�[�o�[��ʒʏ폈��
				gameover.StepGameOver();

				// �Q�[���I�[�o�[��ʂ̕`��
				gameover.DrawGameOver();
			}
			break;
			case SCENE_ID_FIN_GAMEOVER:
			{
				// �v���C�I��
				gameover.FinGameOver();
			}
			break;
			default:
				break;
			}




			//-----------------------------------------
			//���[�v�̏I����

			//FPS�v�Z
			CalcFPS();

			//FPS�\���i�f�o�b�N�p�j
			DrawFPS();

			//�t���b�v�֐�
			ScreenFlip();
		}
	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

