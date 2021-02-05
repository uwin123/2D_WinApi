#include "stdafx.h"
#include "camera.h"

HRESULT camera::init()
{
	//백그라운드 이미지 초기화
	_img  = IMAGEMANAGER->addImage("백그라운드", "배경1.bmp", 5600, 800);

	//카메라 렉트 위치 초기화
	_rcCam = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, CAMSIZEX, CAMSIZEY);
	//_rcCam = RectMakeCenter(0,0,WINSIZEX,WINSIZEY);

	
	mapTimer = 0;
	mapChangeCounter = 0;
	return S_OK;
}

void camera::release()
{
}

void camera::update()
{
	mapTimer++;
	{
		_img->setX(_img->getX() + 1);
		
	}

}

void camera::render()
{
	//백그라운 렌더
	_img->render(getMemDC(), _rcCam.left, _rcCam.top, _img->getX() + _rcCam.left, _img->getY() + _rcCam.top, CAMSIZEX, CAMSIZEY);


	//_img->render(getMemDC(), _rcCam.left, _rcCam.top);

	//카메라 렌더
	FrameRect(getMemDC(), _rcCam, RGB(255, 255, 0));
}
