#include "DxLib.h"
#include "../Scene/Scene.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//�摜�Ǎ�

//BGM

SceneTitle::SceneTitle() {}

SceneTitle::~SceneTitle() {}

// �^�C�g��������
void SceneTitle::InitTitle() {
	// �^�C�g���摜�̓Ǎ�

	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle() {

}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle() {
	//�摜�`��

}

//�^�C�g���I������
void SceneTitle::FinTitle() {
	//BGM�㏈��

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
