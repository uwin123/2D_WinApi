#include "stdafx.h"
#include "camera.h"

HRESULT camera::init()
{
	//��׶��� �̹��� �ʱ�ȭ
	_img  = IMAGEMANAGER->addImage("��׶���", "���1.bmp", 5600, 800);

	//ī�޶� ��Ʈ ��ġ �ʱ�ȭ
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
	//��׶�� ����
	_img->render(getMemDC(), _rcCam.left, _rcCam.top, _img->getX() + _rcCam.left, _img->getY() + _rcCam.top, CAMSIZEX, CAMSIZEY);


	//_img->render(getMemDC(), _rcCam.left, _rcCam.top);

	//ī�޶� ����
	FrameRect(getMemDC(), _rcCam, RGB(255, 255, 0));
}
