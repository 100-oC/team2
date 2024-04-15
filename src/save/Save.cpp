#include"DxLib.h"
#include"Save.h"

SaveData playData;
SaveAndLoad SAL;

char saveDataFilePath[] =
{
	"data/score.bin",
};

void SaveAndLoad::Save()
{
	FILE* fp;
	fopen_s(&fp, saveDataFilePath, "wb");
	if (fp != NULL)
	{
		fwrite(&playData, sizeof(playData), 1, fp);
		fclose(fp);
	}
}

void SaveAndLoad::Load()
{
	FILE* fp;
	fopen_s(&fp, saveDataFilePath, "rb");
	if (fp != NULL)
	{
		fread(&playData, sizeof(playData), 1, fp);
		fclose(fp);
	}
}