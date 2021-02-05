#include "stdafx.h"
#include "gameScene.h"

HRESULT gameScene::init()
{
	IMAGEMANAGER->addImage("������", "������.bmp", 97, 77, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����1", "����1.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ǵ幰��", "���ǵ幰��.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ڼ�����", "�ڼ�����.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ŵ빰��", "�Ŵ빰��.bmp", 70, 70, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��", "��.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "��.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "��.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "��.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "����.bmp", 80, 80, true, RGB(255, 0, 255));

	

	

	//ü�¹� �յ��̹��� �ʱ�ȭ
	IMAGEMANAGER->addImage("progressBarFront", "ü�¹�.bmp", 750, 80,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("progressBarBack", "ü�¹�(��).bmp", 750, 80, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("���ʽ�", "���ʽ�.bmp", 450, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ʽ���", "���ʽ���.bmp", 450, 100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("��׶���", "���1.bmp", 1400, 800);
	//wholeMapRc = RectMake(WINSIZEX, WINSIZEY, 2800, 800);

	//ī�޶� Ŭ���� �ʱ�ȭ
	_camera = new camera;
	_camera->init();

	//�÷��̾� Ŭ���� �ʱ�ȭ
	_player = new player;
	_player->init("����ȱ�", 100, WINSIZEY / 2 + 150, 171, 237, 100, 10, 6, 1);

	//��ֹ� �� ���� Ŭ���� �ʱ�ȭ 
	_obstacle = new obstacle;
	_obstacle->init(0, 650, 700, 200);
	_player->setObstacle(_obstacle);	//�����ٰ� ���پ���, new ~init �ϱ⵵���� ������ٴ� �Ŵϲ�~ ���°� ��� �ν��� ��ź��~

	ITEMMANAGER->init(4,1);
	ITEMMANAGER->playerInfo(_player);
	ITEMMANAGER->itemSetting("������", 1350, 300, 97, 77);
	ITEMMANAGER->itemSetting("����1", 800, 600, 70, 70);
	ITEMMANAGER->itemSetting("���ǵ幰��", 1000, 600, 70, 70);
	ITEMMANAGER->itemSetting("�ڼ�����", 1300, 600, 70, 70);
	ITEMMANAGER->itemSetting("�Ŵ빰��", 700, 600, 70, 70);
	//_player->setItem(_item);			
	

	//ü�¹� �ʱ�ȭ 
	_hpBar = new HPbar;
	_hpBar->init("progressBarFront", "progressBarBack","���ʽ�","���ʽ���");
	//�׿��� 
	_gameOverImg = new image;
	_gameOverImg->init("�׿���.bmp", 1400, 800);
	//IMAGEMANAGER->addImage("�׿���", "�׿���.bmp", 1400, 800);

	
	itemCount = 0;
	itemCount1 = 0;
	itemCount2 = 0;
	itemCount3 = 0;
	itemCount4 = 0;

	bonusCount1= 0;
	bonusCount2= 0;
	bonusCount3= 0;
	bonusCount4= 0;
	bonusCount5= 0;

	floorCount = 0;

	_pointPlus = 0;

	itemEat = false;

	return S_OK;
}

void gameScene::release()
{
	//�÷��̾� ����
	_player->release();
	SAFE_DELETE(_player);
	//��ֹ� �� �� ���� 
	_obstacle->release();
	SAFE_DELETE(_obstacle);

	//ī�޶� Ŭ���� ����
	_camera->release();
	SAFE_DELETE(_camera);

	//ü�¹� ����
	_hpBar->release();
	SAFE_DELETE(_hpBar);

	//ITEMMANAGER->release();
}

void gameScene::update()
{
	if (_player->getGameOver() == false)
	{
		//�÷��̾� ������Ʈ
		_player->update();

		//��ֹ� �� �� ������Ʈ
		_obstacle->update();

		//ī�޶� Ŭ���� ������Ʈ
		_camera->update();

		//ü�¹� ������Ʈ
		_hpBar->update();

		//ü�¹� ��ġ ���뵵 ������Ʈ ����� �Ѵ�
		_hpBar->setGauge(_player->getPlayerMaxHp(), _player->getPlayerCurrentHp());

		itemCount++;
		if (itemCount > 500)
		{
			ITEMMANAGER->itemSetting("������", WINSIZEX, RANDOM->range(200, 400), 97, 77);
			itemCount = 0;
		}
		itemCount1++;
		if (itemCount1 > 5)
		{
			ITEMMANAGER->itemSetting("����1", WINSIZEX, RANDOM->range(100, 600), 70, 70);
			itemCount1 = 0;
		}
		itemCount2++;
		if (itemCount2 > 400)
		{
			ITEMMANAGER->itemSetting("���ǵ幰��", WINSIZEX, RANDOM->range(400, 600), 70, 70);
			itemCount2 = 0;
		}
		itemCount3++;
		if (itemCount3 > 700)
		{
			ITEMMANAGER->itemSetting("�ڼ�����", WINSIZEX, RANDOM->range(200, 300), 70, 70);
			itemCount3 = 0;
		}
		itemCount4++;
		if (itemCount4 > 800)
		{
			ITEMMANAGER->itemSetting("�Ŵ빰��", WINSIZEX, RANDOM->range(200, 400), 70, 70);
			itemCount4 = 0;
		}
		bonusCount1++;
		if (bonusCount1 == 300)
		{
			ITEMMANAGER->itemSetting("��", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount2++;
		if (bonusCount2 == 700)
		{
			ITEMMANAGER->itemSetting("��", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount3++;
		if (bonusCount3 == 1200)
		{
			ITEMMANAGER->itemSetting("��", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount4++;
		if (bonusCount4 == 1800)
		{
			ITEMMANAGER->itemSetting("��", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount5++;
		if (bonusCount5 == 2500)
		{
			ITEMMANAGER->itemSetting("����", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		ITEMMANAGER->update();

		hitDamage();
	}
}

void gameScene::render()
{
	//ī�޶� Ŭ���� ����
	_camera->render();
	
	
	//ü�¹� ���� 
	_hpBar->render();
	//��ֹ� �� �� ����
	_obstacle->render();
	
	ITEMMANAGER->render(getMemDC());
	
	

	//�÷��̾� ����
	_player->render();


	if (_player->getGameOver() == true)
	{
		_gameOverImg->render(getMemDC(), 0,0);
	}
}

void gameScene::hitDamage()
{
	_player->setCurrentPlayerHp(-0.05f);
	
	
}

