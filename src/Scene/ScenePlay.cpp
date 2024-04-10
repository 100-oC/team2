#include "DxLib.h"
#include "../Scene/Scene.h"
#include "ScenePlay.h"
#include "../Input/Input.h"


//�摜

//BGM

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

// �Q�[���v���C������
void ScenePlay::InitPlay() {
	// �v���C�摜�̓Ǎ�
		
	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �Q�[���v���C�ʏ폈��
void ScenePlay::StepPlay() {

}

// �Q�[���v���C�`�揈��
void ScenePlay::DrawPlay() {
	//�摜�`��
}

//�Q�[���v���C�I������
void ScenePlay::FinPlay() {
	//BGM�㏈��

	//�N���A�t���O���m�F���đJ�ڐ������
	if (!isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_GAMEOVER;
	}
	if (isClear) {
		g_CurrentSceneId = SCENE_ID_INIT_CLEAR;
	}
}

void ScenePlay::InitScreen()
{
	ScreenX = PlayerX - SCREEN_SIZE_X / 2;
}

//�X�N���[���̃��[���h���W
void ScenePlay::StepScreen()
{
	ScreenX = PlayerX + 200 - SCREEN_SIZE_X / 2;
}
