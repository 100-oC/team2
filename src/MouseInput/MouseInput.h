#pragma once

class Mouse
{
private:
	int MousePosX;	//�}�E�X��X���W
	int MousePosY;	//�}�E�X��Y���W

	int GetMousePoint(int* XBuf, int* YBuf); //�}�E�X�J�[�\���̈ʒu���擾����

public:
	Mouse();	//�R���X�g���N�^
	~Mouse();	//�f�X�g���N�^

	void MouseInit();	//�}�E�X�̏���������
	void MouseStep();	//�}�E�X�̒ʏ폈��
	void MouseDraw();	//�}�E�X�̕`�揈��
	void MouseFin();	//�}�E�X�̏I������

};
