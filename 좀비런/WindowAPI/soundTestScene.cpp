#include "stdafx.h"
#include "soundTestScene.h"


HRESULT soundTestScene::init()
{
	//사운드 추가
	
	//BGM일경우
	//SOUNDMANAGER->addSound("사운드1", "Sound/브금.mp3", true, true);
	
	//효과음일경우
	SOUNDMANAGER->addSound("사운드1", "Sound/쿠키런겜브금.mp3");
	SOUNDMANAGER->addSound("사운드2", "Sound/내이야기브금.mp3");

	//"Sound/내이야기브금.mp3"
	//시작하자마자 플레이하기
	SOUNDMANAGER->play("사운드1");

	stopMusic = false;
	return S_OK;
}

void soundTestScene::release()
{
}

void soundTestScene::update()
{
	//효과음은 그냥 충돌될때 플레이만 하면 된다
	//브금은 현재 플레이중인지 체크해서 정지후 플레이를 해야 한다
	//그렇지 않을경우 돌림노래처럼 사운드가 나오게 된다
	if (INPUT->GetKeyDown(VK_LBUTTON)&& !stopMusic)
	{
		if (!stopMusic) 
		{
			if (SOUNDMANAGER->isPlaySound("사운드1"))		//만약에 사운드1이 나오고잇을때 클릭 하면 사운드 1이 멈추게 한다. 
			{
				SOUNDMANAGER->stop("사운드1");
			}
			SOUNDMANAGER->play("사운드2");
			stopMusic = true;
		}
		else
		{
			stopMusic = true;
		}
	}
}

void soundTestScene::render()
{
	//매크로펑션에 추가해둠 (텍스트 출력 편하게 사용하기)
	textOut(getMemDC(), 10, 10, "사운드테스트");
}
