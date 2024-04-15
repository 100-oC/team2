#pragma once

struct SaveData
{
	int highScore;
};

extern SaveData playData;

class SaveAndLoad
{
public:
	void Save();
	void Load();
};
extern SaveAndLoad SAL;