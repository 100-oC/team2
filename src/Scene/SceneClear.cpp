#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneClear.h"
#include "../Input/Input.h"

SceneClear::SceneClear() {}

SceneClear::~SceneClear() {}

// �Q�[���N���A������
void SceneClear::InitClear() {
	// �Q�[���I�[�o�[�摜�̓Ǎ�

	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// �Q�[���N���A�ʏ폈��
void SceneClear::StepClear() {

}

// �Q�[���N���A�`�揈��
void SceneClear::DrawClear() {

}

//�Q�[���N���A�I������
void SceneClear::FinClear() {

	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
