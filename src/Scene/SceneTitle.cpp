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
	// �^�C�g���摜�̓Ǎ�
	handle = LoadGraph(titleImagePath);

	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle() 
{
	//�G���^�[���X�y�[�X����������
	if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE)||
		Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle() 
{
	//�摜�`��
	DrawGraph(0, 0, handle,true);
}

//�^�C�g���I������
void SceneTitle::FinTitle() 
{
	//BGM�㏈��

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}
