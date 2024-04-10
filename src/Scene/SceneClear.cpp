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
	// �Q�[���I�[�o�[�摜�̓Ǎ�
	handle = LoadGraph(resultImagePath);

	//BGM�Ǎ�

	//BGM�Đ�

	g_CurrentSceneId = SCENE_ID_LOOP_CLEAR;
}

// �Q�[���N���A�ʏ폈��
void SceneClear::StepClear() 
{
	//�G���^�[���X�y�[�X����������
	if (Input::Key::Push(KEY_INPUT_RETURN) || Input::Key::Push(KEY_INPUT_SPACE) ||
		Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneId = SCENE_ID_FIN_CLEAR;
	}
}

// �Q�[���N���A�`�揈��
void SceneClear::DrawClear() 
{
	//�摜�`��
	DrawGraph(0, 0, handle, true);

	//�����̑傫���ύX
	SetFontSize(60);
	DrawFormatString(300, 250, GetColor(0, 0, 0), "�X�R�A");
	SetFontSize(50);
	DrawFormatString(370, 320, GetColor(0, 0, 0), "%d", viewScore);
	//�����̑傫�������ɖ߂�
	SetFontSize(20);
}

//�Q�[���N���A�I������
void SceneClear::FinClear() 
{

	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}
