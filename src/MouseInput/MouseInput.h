#pragma once

class Mouse
{
private:
	int MousePosX;	//マウスのX座標
	int MousePosY;	//マウスのY座標

	int GetMousePoint(int* XBuf, int* YBuf); //マウスカーソルの位置を取得する

public:
	Mouse();	//コンストラクタ
	~Mouse();	//デストラクタ

	void MouseInit();	//マウスの初期化処理
	void MouseStep();	//マウスの通常処理
	void MouseDraw();	//マウスの描画処理
	void MouseFin();	//マウスの終了処理

};
