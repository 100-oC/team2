#pragma once

const int MOLE_POP_TIME = 1;	//�o������

//���O���̎��
enum MOLE
{
	NORMAL_MOLE,	//����
	SPECIAL_MOLE,	//����
	DAMAGE_MOLE,	//��Q

	MOLE_MAX_NUM,	//��ސ�
};

//���_
const int NORMAL_POINT = 1;
const int SPECIAL_POINT = 5;
const int DAMAGE_POINT = -3;

//�摜�p�X
const char MOLE_IMAGE_PATH[3][255] =
{
	"data/play/normalMole.png",
	"data/play/specialMole.png",
	"data/play/damageMole.png",
};

const char GROUND_IMAGE_PATH[3][255] =
{
	"data/play/ground1.png",
	"data/play/ground2.png",
	"data/play/ground3.png",
};

class Mole
{
private:
	int moleHandle[MOLE_MAX_NUM];	//������n���h��
	int groundHandle[3];	//�n�ʂ̉摜�n���h��

	int y[9];	//���W
	int moleNum[9];	//���O���̎��
	bool isUse[9];	//�g�p�t���O
	bool isAttack[9];	//���������t���O

	float outTime[9];	//�o�����Ă鎞��

	float popCountTime;	//�o�����ԃJ�E���g

public:
	void Init();	//������
	void Step();	//�ʏ폈��
	void Draw();	//�`��
	void Fin();		//�I������

	int KeyPush();	//�ǂ̃L�[��������
	void Pop();		//�o��
	void Move();	//����

};