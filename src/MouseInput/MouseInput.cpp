#include "DxLib.h"						//DxLib.hのインクルード
#include "../Scene/Scene.h"				//Scene.hのインクルード
#include "../MouseInput/MouseInput.h"	//MouseInput.hのインクルード

//コンストラクタ
Mouse::Mouse(){}
//デストラクタ
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