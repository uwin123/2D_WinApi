#include "stdafx.h"
#include "startScene.h"


HRESULT startScene::init()
{
	//��Ʈ ��ġ �ʱ�ȭ
	_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, 200, 100);
	_starRc = RectMake(0, 0, 1400, 800);
	IMAGEMANAGER->addImage("�׽���ȭ��", "�׽���ȭ��.bmp", 1400, 800);
	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
	if (INPUT->GetKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_rc, _ptMouse))
		{
			SCENEMANAGER->loadScene("����ȭ��");
		}
	}
}

void startScene::render()
{
	IMAGEMANAGER->render("�׽���ȭ��", getMemDC(), 0, 0);

	//Rectangle(getMemDC(), _rc);
	TextOut(getMemDC(), _rc.left + 80, _rc.top + 50, "START", strlen("START"));


}
