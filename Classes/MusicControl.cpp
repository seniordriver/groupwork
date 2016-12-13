#include "MusicControl.h"

bool MusicControl::isStop = false;
int MusicControl::music = 1;

void MusicControl::playBackgroundMusic()
{
	if (music == 1)
	{
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm.wav");
		if (isStop == false)
		{
			//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.wav", true);

		}
		else
		{
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		}
	}
	else
	{
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("celebrate.mp3");
		if (isStop == false)
		{
			//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			SimpleAudioEngine::getInstance()->playBackgroundMusic("celebrate.mp3", true);

		}
		else
		{
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		}

	}

}

void MusicControl::changeisStop()
{
	if (isStop == false)
	{
		isStop = true;
	}
	else
	{
		isStop = false;
	}
}

bool MusicControl::getisStop()
{
	return isStop;
}

void MusicControl::changemusic(int a)
{
	music = a;
}
//void MusicControl::menuMusicCallback(Ref* pSender)
//{
//	if (isStop == false)
//	{
//		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
//		isStop = true;
//	}
//	else
//	{
//		SimpleAudioEngine::getInstance()->playBackgroundMusic(Music_File, true);
//		isStop = false;
//	}
//}