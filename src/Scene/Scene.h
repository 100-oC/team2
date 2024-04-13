#pragma once
#include"../FrameRate/FrameRate.h"
#include"../Input/Input.h"
#include"../Sound/Sound.h"
#include"../MathPlus/MathPlus.h"

#include"../TimeLimit/TimeLimit.h"

// define
#define	SCREEN_SIZE_X	800	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	600	// Y�����̉�ʃT�C�Y���w��

enum SCENE_ID
{
	//�^�C�g���V�[��ID
	SCENE_ID_INIT_TITLE,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//�v���C�V�[��ID
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//�N���A�V�[��ID
	SCENE_ID_INIT_CLEAR,
	SCENE_ID_LOOP_CLEAR,
	SCENE_ID_FIN_CLEAR,

	//�Q�[���I�[�o�[�V�[��ID
	SCENE_ID_INIT_GAMEOVER,
	SCENE_ID_LOOP_GAMEOVER,
	SCENE_ID_FIN_GAMEOVER,
};

//�@���݂̃V�[��ID
extern SCENE_ID g_CurrentSceneId;

extern int score;		//�X�R�A
extern int viewScore;	//�\���p�X�R�A