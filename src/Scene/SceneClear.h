#pragma once

class SceneClear {
private:
	int handle;

public:
	SceneClear();
	~SceneClear();

	void InitClear();		// �N���A������

	void StepClear();		// �N���A�ʏ폈��

	void DrawClear();		// �N���A�`�揈��

	void FinClear();		//�N���A�I������

};
