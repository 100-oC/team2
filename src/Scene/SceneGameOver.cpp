#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneGameOver.h"
#include "../Input/Input.h"

//�摜

//BGM

SceneGameOver::SceneGameOver() {}

SceneGameOver::~SceneGameOver() {}

// �Q�[���I�[�o�[������
void SceneGameOver::InitGameOver() {
	// �Q�[���I�[�o�[�摜�̓Ǎ�

	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_GAMEOVER;
}

// �Q�[���I�[�o�[�ʏ폈��
void SceneGameOver::StepGameOver() {

}

// �Q�[���I�[�o�[�`�揈��
void SceneGameOver::DrawGameOver() {
	//�摜�`��

}

//�Q�[���I�[�o�[�I������
void SceneGameOver::FinGameOver() {

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
