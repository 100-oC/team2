#include"DxLib.h"
#include"../Scene/Scene.h"
#include"Mole.h"

//������
void Mole::Init()
{
	//�摜�ǂݍ���
	for (int i = 0; i < MOLE_MAX_NUM; i++)
	{
		moleHandle[i] = LoadGraph(MOLE_IMAGE_PATH[i]);		//���O��
		moleHandle2[i] = LoadGraph(MOLE_IMAGE_PATH2[i]);		//���O��
		
	}

	for (int i = 0; i < 3; i++)
	{
		groundHandle[i] = LoadGraph(GROUND_IMAGE_PATH[i]);	//�n��
	}

	//�e���O���̕ϐ�������
	for (int i = 0; i < 9; i++)
	{
		y[i] = 0;				//���W
		isUse[i] = false;		//�g�p�t���O
		outTime[i] = 0.0f;		//�o�Ă��鎞��
		moleNum[i] = 0;			//���O���̎��
		isAttack[i] = false;	//���������t���O
	}

	//�o���C���^�[�o��
	popCountTime = 0.0f;

	//���W�ݒ�
	x[0] = SCREEN_SIZE_X / 2 - 150;
	x[1] = SCREEN_SIZE_X / 2;
	x[2] = SCREEN_SIZE_X / 2 + 150;

	x[3] = SCREEN_SIZE_X / 2 - 150;
	x[4] = SCREEN_SIZE_X / 2;
	x[5] = SCREEN_SIZE_X / 2 + 150;

	x[6] = SCREEN_SIZE_X / 2 - 150;
	x[7] = SCREEN_SIZE_X / 2;
	x[8] = SCREEN_SIZE_X / 2 + 150;

	//���̈ʒuY
	defaultY[0] = 450;
	defaultY[1] = 450;
	defaultY[2] = 450;
	defaultY[3] = 300;
	defaultY[4] = 300;
	defaultY[5] = 300;
	defaultY[6] = 140;
	defaultY[7] = 140;
	defaultY[8] = 140;

}

//�ʏ폈��
void Mole::Step()
{
	Pop();	//�o��
	Move();	//����
}

//�`��
void Mole::Draw()
{
	//���O��789
	if (isUse[6])
	{
		if (!isAttack[6])
		{
			DrawRotaGraph(x[6], 140 - y[6], 1.0f, 0.0f, moleHandle[moleNum[6]], true);
			
		}
		else
		{
			DrawRotaGraph(x[6], 140 - y[6], 1.0f, 0.0f, moleHandle2[moleNum[6]], true);
		}
	}
	if (isUse[7])
	{
		if (!isAttack[7])
		{
			DrawRotaGraph(x[7], 140 - y[7], 1.0f, 0.0f, moleHandle[moleNum[7]], true);
		}
		else
		{
			DrawRotaGraph(x[7], 140 - y[7], 1.0f, 0.0f, moleHandle2[moleNum[7]], true);
		}
	}
	if (isUse[8])
	{
		if (!isAttack[8])
		{
			DrawRotaGraph(x[8], 140 - y[8], 1.0f, 0.0f, moleHandle[moleNum[8]], true);
		}
		else
		{
			DrawRotaGraph(x[8], 140 - y[8], 1.0f, 0.0f, moleHandle2[moleNum[8]], true);
		}
	}
	
	//�n��789
	DrawRotaGraph(SCREEN_SIZE_X / 2, 170, 1.0f, 0.0f, groundHandle[2], true);

	//=================================

	//���O��456
	if (isUse[3])
	{
		if (!isAttack[3])
		{
			DrawRotaGraph(x[3], 300 - y[3], 1.0f, 0.0f, moleHandle[moleNum[3]], true);
		}
		else
		{
			DrawRotaGraph(x[3], 300 - y[3], 1.0f, 0.0f, moleHandle2[moleNum[3]], true);
		}
	}
	if (isUse[4])
	{
		if (!isAttack[4])
		{
			DrawRotaGraph(x[4], 300 - y[4], 1.0f, 0.0f, moleHandle[moleNum[4]], true);
		}
		else
		{
			DrawRotaGraph(x[4], 300 - y[4], 1.0f, 0.0f, moleHandle2[moleNum[4]], true);
		}
	}
	if (isUse[5])
	{
		if (!isAttack[5])
		{
			DrawRotaGraph(x[5], 300 - y[5], 1.0f, 0.0f, moleHandle[moleNum[5]], true);
		}
		else
		{
			DrawRotaGraph(x[5], 300 - y[5], 1.0f, 0.0f, moleHandle2[moleNum[5]], true);
		}
	}
	
	//�n��456
	DrawRotaGraph(SCREEN_SIZE_X / 2, 330, 1.0f, 0.0f, groundHandle[1], true);

	//==================================
	
	//���O��123
	if (isUse[0])
	{
		if (!isAttack[0])
		{
			DrawRotaGraph(x[0], 450 - y[0], 1.0f, 0.0f, moleHandle[moleNum[0]], true);
		}
		else
		{
			DrawRotaGraph(x[0], 450 - y[0], 1.0f, 0.0f, moleHandle2[moleNum[0]], true);
		}
	}
	if (isUse[1])
	{
		if (!isAttack[1])
		{
			DrawRotaGraph(x[1], 450 - y[1], 1.0f, 0.0f, moleHandle[moleNum[1]], true);
		}
		else
		{
			DrawRotaGraph(x[1], 450 - y[1], 1.0f, 0.0f, moleHandle2[moleNum[1]], true);
		}
	}
	if (isUse[2])
	{
		if (!isAttack[2])
		{
			DrawRotaGraph(x[2], 450 - y[2], 1.0f, 0.0f, moleHandle[moleNum[2]], true);
		}
		else
		{
			DrawRotaGraph(x[2], 450 - y[2], 1.0f, 0.0f, moleHandle2[moleNum[2]], true);
		}
	}
	
	//�n��123
	DrawRotaGraph(SCREEN_SIZE_X / 2, 480, 1.0f, 0.0f, groundHandle[0], true);

}

//�I������
void Mole::Fin()
{

}

//�o��
void Mole::Pop()
{
	//�J�E���g
	popCountTime += 1.0f / FRAME_RATE;

	//�w��̎��ԂɂȂ�����
	if (popCountTime >= 0.2f)
	{
		popCountTime = 0.0f;	//���Ԃ̃��Z�b�g

		//2���̈�ŏo��
		if (GetRand(1) == 0)
		{
			int popNum = GetRand(8);	//�o���ԍ�

			//�o���ԍ����g�p���łȂ���Έȉ�
			if (!isUse[popNum])
			{
				isUse[popNum] = true;	//�g�p��
				y[popNum] = 0;	//�o���p���W

				//outTime[popNum] = GetRand(1);	//�o�����Ă鎞��(0~1)
				outTime[popNum] = 1.0f;	//�o�����Ă鎞��(0~1)

				//���O���̎�ނ�ݒ�
				int moleN = GetRand(10);	//0~11

				if		(moleN >= 0 && moleN <= 6)
				{
					moleNum[popNum] = NORMAL_MOLE;	//�m�[�}�����O��
				}

				else if (moleN >= 7 && moleN <= 8)
				{
					moleNum[popNum] = DAMAGE_MOLE;	//�_���[�W���O��
				}

				else if ( moleN <= 9)
				{
					moleNum[popNum] = SPECIAL_MOLE;	//�X�y�V�������O��
				}

				else if (moleN >= 10)
				{
					moleNum[popNum] = TIME_MOLE;	//�^�C���������O��
				}
				
			}
		}
	}
}

//����
void Mole::Move()
{
	//���̌���
	for (int i = 0; i < 9; i++)
	{
		//�g�p����Ă�����ȉ�
		if (isUse[i])
		{
			//�o��
			if (y[i] < 30&& outTime[i]>0)
			{
				y[i] += 4;
			}

			//�o�����Ă�����
			else if(!isAttack[i])
			{
				//�o�����Ԃ�����
				outTime[i] -= 1.0f / FRAME_RATE;

				//0�ȉ��ɂȂ�����
				if (outTime[i] <= 0)
				{
					//�n�ʂɖ߂�
					if (y[i] > 0)
					{
						y[i] -= 5;
					}

					//�߂�����
					else
					{
						//���W���Œ�
						y[i] = 0;
						//�g�p�t���O��܂�
						isUse[i] = false;
					}
				}

				//�o����
				else
				{
					//�o�Ă���Ƃ��낪������Ă�����
					if (i == KeyPush())
					{
						//�������ꂽ���Ƃɂ���
						isAttack[i] = true;

						Effect::Play(EFFECT_TYPE_PIKO, (float)x[i], (float)defaultY[i] + y[i]-130);
						Effect::Play(EFFECT_TYPE_PIKOHAN, (float)x[i]+30, (float)defaultY[i] + y[i]-200);

						Sound::Se::Play(SE_PIKO);
					}

					//�}�E�X�ł�����
					int mX, mY;
					if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
					{
						// �}�E�X�̈ʒu���擾
						GetMousePoint(&mX, &mY);

						if (GetDistance((float)x[i], (float)defaultY[i] + y[i]-100, (float)mX, (float)mY) < 50)
						{
							//�������ꂽ���Ƃɂ���
							isAttack[i] = true;

							Effect::Play(EFFECT_TYPE_PIKO, (float)x[i], (float)defaultY[i] + y[i] - 130);
							Effect::Play(EFFECT_TYPE_PIKOHAN, (float)x[i] + 30, (float)defaultY[i] + y[i] - 200);

							Sound::Se::Play(SE_PIKO);
						}
					}
				}
			}
		}

		//��������Ă�����
		if (isAttack[i])
		{
			//����������
			if (y[i] < 70)
			{
				y[i] += 5;
			}
			else
			{
				//�t���O�܂�
				isUse[i] = false;
				isAttack[i] = false;

				//���_�����Z�y�ь��Z
				switch (moleNum[i])
				{
				case NORMAL_MOLE:

					score += NORMAL_POINT;

					break;

				case SPECIAL_MOLE:

					score += SPECIAL_POINT;
					Sound::Se::Play(SE_SPECIAL);

					break;

				case DAMAGE_MOLE:

					score += DAMAGE_POINT;
					Sound::Se::Play(SE_BAKUHA);

					break;

				case TIME_MOLE:

					score += TIME_POINT;
					currentTime += 3;

					if (currentTime >= 99)
					{
						currentTime = 99;
					}

					Sound::Se::Play(SE_TIME);

					break;

				default:
					break;
				}
			}
		}
	}
}

//�ǂ̃L�[��������Ă������i�e���L�[�Ή��j
int Mole::KeyPush()
{
	if (Input::Key::Push(KEY_INPUT_NUMPAD1))
	{
		return 0;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD2))
	{
		return 1;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD3))
	{
		return 2;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD4))
	{
		return 3;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD5))
	{
		return 4;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD6))
	{
		return 5;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD7))
	{
		return 6;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD8))
	{
		return 7;
	}

	if (Input::Key::Push(KEY_INPUT_NUMPAD9))
	{
		return 8;
	}

	return -1;
}