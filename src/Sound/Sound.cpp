#include"sound.h"
#include"DxLib.h"

int Sound::Bgm::handle[BGM_MAX_NUM];
int Sound::Se::handle[SE_MAX_NUM];

//BGMのパス
char bgmSoundPath[BGM_MAX_NUM][255] =
{
	//音楽
	"data/sound/bgm/titleBGM.mp3",	//タイトル
	"data/sound/bgm/playBGM.mp3",	//プレイ
	"data/sound/bgm/resultBGM.mp3",	//リザルト

	//環境音
	"data/sound/bgm/kankyou.mp3",	//畑
};

//音量
int soundVolume_bgm[BGM_MAX_NUM] =
{
	70,	//タイトル
	50,	//プレイ
	70,	//リザルト

	70,		//畑
};

//SEのパス
char seSoundPath[SE_MAX_NUM][255] =
{
	"data/sound/se/start.mp3",		//開始
	"data/sound/se/piko.mp3",		//ピコハン
	"data/sound/se/special.mp3",	//スペシャルもぐら
	"data/sound/se/time.mp3",		//時間加算
	"data/sound/se/bakuha.mp3",		//爆発
	"data/sound/se/timeLimit.mp3",	//時間制限
	"data/sound/se/finish.mp3",		//ゲーム終了
};

//音量
int soundVolume_se[SE_MAX_NUM] =
{
	70,			//システム
	70,			//釣り竿
	70,			//ルアー着水
	70,			//魚がルアーに反応
	70,			//魚を釣った
	100,		//時間制限
	100,		//ゲーム終了
};

//サウンドまとめ初期化
void Sound::Init()
{
	Bgm::Init();
	Se::Init();
}

//BGMの初期化
void Sound::Bgm::Init()
{
	for (int i = 0; i < BGM_MAX_NUM; i++)
	{
		//読み込み
		handle[i] = LoadSoundMem(bgmSoundPath[i]);
		//ボリュームの設定
		ChangeVolumeSoundMem(255 * soundVolume_bgm[i] / 100, handle[i]);
	}
}
//BGMの通常処理：種類
void Sound::Bgm::Play(int type)
{
	//BGMの再生
	PlaySoundMem(handle[type], DX_PLAYTYPE_LOOP, true);
}
//BGMの音量調節：種類,音量(ﾊﾟｰｾﾝﾃｰｼﾞ)
void Sound::Bgm::SetVolume(int type, int volume)
{
	//音量の設定（0～255）（↓はvolume％の音量で出力）
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}
//BGMの停止：種類
void Sound::Bgm::StopSound(int type)
{
	//BGMの停止
	StopSoundMem(handle[type]);
}

//SEの初期化
void Sound::Se::Init()
{
	for (int i = 0; i < SE_MAX_NUM; i++)
	{
		//読み込み
		handle[i] = LoadSoundMem(seSoundPath[i]);
		//ボリュームの設定
		int vo = soundVolume_se[i];
		SetVolume(i, vo);
	}
}
//SEの通常処理：種類
void Sound::Se::Play(int type)
{
	//効果音の再生
	PlaySoundMem(handle[type], DX_PLAYTYPE_BACK, true);
}
//SEの音量調節：種類,音量(ﾊﾟｰｾﾝﾃｰｼﾞ)
void Sound::Se::SetVolume(int type, int volume)
{
	//音量の設定（0～255）（↓はvolume％の音量で出力）
	ChangeVolumeSoundMem(255 * volume / 100, handle[type]);
}