#include "stdafx.h"
#include "gameScene.h"

HRESULT gameScene::init()
{
	IMAGEMANAGER->addImage("생명물약", "생명물약.bmp", 97, 77, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("젤리1", "젤리1.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스피드물약", "스피드물약.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("자석물약", "자석물약.bmp", 70, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("거대물약", "거대물약.bmp", 70, 70, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("비", "비.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("오", "오.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("엔", "엔.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유", "유.bmp", 80, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에스", "에스.bmp", 80, 80, true, RGB(255, 0, 255));

	

	

	//체력바 앞뒤이미지 초기화
	IMAGEMANAGER->addImage("progressBarFront", "체력바.bmp", 750, 80,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("progressBarBack", "체력바(뒤).bmp", 750, 80, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("보너스", "보너스.bmp", 450, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("보너스뒤", "보너스뒤.bmp", 450, 100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("백그라운드", "배경1.bmp", 1400, 800);
	//wholeMapRc = RectMake(WINSIZEX, WINSIZEY, 2800, 800);

	//카메라 클래스 초기화
	_camera = new camera;
	_camera->init();

	//플레이어 클래스 초기화
	_player = new player;
	_player->init("좀비걷기", 100, WINSIZEY / 2 + 150, 171, 237, 100, 10, 6, 1);

	//장애물 및 벽들 클래스 초기화 
	_obstacle = new obstacle;
	_obstacle->init(0, 650, 700, 200);
	_player->setObstacle(_obstacle);	//위에다가 갖다쓰면, new ~init 하기도전에 써버린다는 거니께~ 형태가 없어서 인식을 모탄다~

	ITEMMANAGER->init(4,1);
	ITEMMANAGER->playerInfo(_player);
	ITEMMANAGER->itemSetting("생명물약", 1350, 300, 97, 77);
	ITEMMANAGER->itemSetting("젤리1", 800, 600, 70, 70);
	ITEMMANAGER->itemSetting("스피드물약", 1000, 600, 70, 70);
	ITEMMANAGER->itemSetting("자석물약", 1300, 600, 70, 70);
	ITEMMANAGER->itemSetting("거대물약", 700, 600, 70, 70);
	//_player->setItem(_item);			
	

	//체력바 초기화 
	_hpBar = new HPbar;
	_hpBar->init("progressBarFront", "progressBarBack","보너스","보너스뒤");
	//겜오버 
	_gameOverImg = new image;
	_gameOverImg->init("겜오버.bmp", 1400, 800);
	//IMAGEMANAGER->addImage("겜오버", "겜오버.bmp", 1400, 800);

	
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
	//플레이어 해제
	_player->release();
	SAFE_DELETE(_player);
	//장애물 및 벽 해제 
	_obstacle->release();
	SAFE_DELETE(_obstacle);

	//카메라 클래스 해제
	_camera->release();
	SAFE_DELETE(_camera);

	//체력바 해제
	_hpBar->release();
	SAFE_DELETE(_hpBar);

	//ITEMMANAGER->release();
}

void gameScene::update()
{
	if (_player->getGameOver() == false)
	{
		//플레이어 업데이트
		_player->update();

		//장애물 및 벽 업데이트
		_obstacle->update();

		//카메라 클래스 업데이트
		_camera->update();

		//체력바 업데이트
		_hpBar->update();

		//체력바 위치 피통도 업데이트 해줘야 한다
		_hpBar->setGauge(_player->getPlayerMaxHp(), _player->getPlayerCurrentHp());

		itemCount++;
		if (itemCount > 500)
		{
			ITEMMANAGER->itemSetting("생명물약", WINSIZEX, RANDOM->range(200, 400), 97, 77);
			itemCount = 0;
		}
		itemCount1++;
		if (itemCount1 > 5)
		{
			ITEMMANAGER->itemSetting("젤리1", WINSIZEX, RANDOM->range(100, 600), 70, 70);
			itemCount1 = 0;
		}
		itemCount2++;
		if (itemCount2 > 400)
		{
			ITEMMANAGER->itemSetting("스피드물약", WINSIZEX, RANDOM->range(400, 600), 70, 70);
			itemCount2 = 0;
		}
		itemCount3++;
		if (itemCount3 > 700)
		{
			ITEMMANAGER->itemSetting("자석물약", WINSIZEX, RANDOM->range(200, 300), 70, 70);
			itemCount3 = 0;
		}
		itemCount4++;
		if (itemCount4 > 800)
		{
			ITEMMANAGER->itemSetting("거대물약", WINSIZEX, RANDOM->range(200, 400), 70, 70);
			itemCount4 = 0;
		}
		bonusCount1++;
		if (bonusCount1 == 300)
		{
			ITEMMANAGER->itemSetting("비", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount2++;
		if (bonusCount2 == 700)
		{
			ITEMMANAGER->itemSetting("오", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount3++;
		if (bonusCount3 == 1200)
		{
			ITEMMANAGER->itemSetting("엔", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount4++;
		if (bonusCount4 == 1800)
		{
			ITEMMANAGER->itemSetting("유", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		bonusCount5++;
		if (bonusCount5 == 2500)
		{
			ITEMMANAGER->itemSetting("에스", WINSIZEX, RANDOM->range(100, 600), 80, 80);
		}
		ITEMMANAGER->update();

		hitDamage();
	}
}

void gameScene::render()
{
	//카메라 클래스 렌더
	_camera->render();
	
	
	//체력바 렌더 
	_hpBar->render();
	//장애물 및 벽 렌더
	_obstacle->render();
	
	ITEMMANAGER->render(getMemDC());
	
	

	//플레이어 렌더
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

