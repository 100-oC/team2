#include "DxLib.h"						//DxLib.h�̃C���N���[�h
#include "../Scene/Scene.h"				//Scene.h�̃C���N���[�h
#include "../MouseInput/MouseInput.h"	//MouseInput.h�̃C���N���[�h

//�R���X�g���N�^
Mouse::Mouse(){}
//�f�X�g���N�^
Mouse::~Mouse() {}

void Mouse::MouseInit() {
	
}

void Mouse::MouseStep() {
	GetMousePoint(&MousePosX, &MousePosY);
}

void Mouse::MouseDraw() {

}

void Mouse::MouseFin() {

}