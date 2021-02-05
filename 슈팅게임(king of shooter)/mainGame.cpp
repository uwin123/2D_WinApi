#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## 초기화 ## init()
//=============================================================
HRESULT mainGame::init()
{
	gameNode::init();

	//이곳에서 초기화를 한다

	IMAGEMANAGER->addImage("피", "피.bmp", 130, 111, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("게임오버", "게임오버.bmp", 360, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("백그라운드", "루갈맵.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("백그라운드1", "킹옾맵1.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("백그라운드2", "킹옾맵2.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("백그라운드3", "킹옾맵3.bmp", WINSIZEX, WINSIZEY);
	
	IMAGEMANAGER->addFrameImage("치즈루", "치즈루1.bmp", 180, 240, 3, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("루갈", "루갈1.bmp", 180, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("게닛츠", "게닛츠.bmp", 1000, 180, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("무카이", "무카이1.bmp", 1813, 158, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("이오리", "이오리 등장.bmp", 8960, 900, 14, 1, true, RGB(255, 0, 255));

	//플레이어 클래스 초기화
	_player = new player;

	_player->init("치즈루", "치즈루 총알", 150, WINSIZEY / 2, 80, 60, 1000, 5, 3, 4, false);
	
	_player->init("치즈루", "치즈루 스킬 총알", 150, WINSIZEY / 2, 80, 60, 1000, 5, 3, 4, true);
	//100 80
	//몬스터 클래스 초기화
	//여기서 몬스터들의 출현 속도, 발사 속도 등 조절 
	//=====================루갈==========================//
	_monster[0].init("루갈", "루갈 총알", WINSIZEX + 200, WINSIZEY/2, 60, 120, 20, 2, 3, 1, 120, 0, _player, false);
	_monster[1].init("루갈", "루갈 총알", WINSIZEX + 200, 150, 60, 120, 20, 2, 3, 1, 120, 15, _player, false);
	_monster[2].init("루갈", "루갈 총알", WINSIZEX + 200, 250, 60, 120, 20, 2, 3, 1, 120, 30, _player, false);
	//_monster[3].init("루갈", "루갈 총알", WINSIZEX + 200, 350, 60, 120, 20, 2, 3, 1, 120, 45, _player, false);
	_monster[4].init("루갈", "루갈 총알", WINSIZEX + 200, 450, 60, 120, 20, 2, 3, 1, 120, 60, _player, false);
	_monster[5].init("루갈", "루갈 총알", WINSIZEX + 200, 550, 60, 120, 20, 2, 3, 1, 120, 75, _player, false);
	//_monster[6].init("루갈", "루갈 총알", WINSIZEX + 200, 650, 60, 120, 20, 2, 3, 1, 120, 90, _player, false);
	_monster[7].init("루갈", "루갈 총알", WINSIZEX + 200, 750, 60, 120, 20, 2, 3, 1, 120, 105, _player, true);
	
	//_monster[8].init("루갈", "루갈 총알", WINSIZEX + 200, 750, 60, 120, 10, 5, 3, 1, 10, 130, _player,true);
	//_monster[9].init("루갈", "루갈 총알", WINSIZEX + 200, 650, 60, 120, 10, 5, 3, 1, 10, 145, _player, false);
	//_monster[10].init("루갈", "루갈 총알", WINSIZEX + 200, 550, 60, 120, 10, 5, 3, 1, 10, 160, _player,false);
	//_monster[11].init("루갈", "루갈 총알", WINSIZEX + 200, 450, 60, 120, 10, 5, 3, 1, 10, 175, _player,false);
	//_monster[12].init("루갈", "루갈 총알", WINSIZEX + 200, 350, 60, 120, 10, 5, 3, 1, 10, 190, _player,false);
	//_monster[13].init("루갈", "루갈 총알", WINSIZEX + 200, 250, 60, 120, 10, 5, 3, 1, 10, 205, _player,false);
	////_monster[14].init("루갈", "루갈 총알", WINSIZEX + 200, 150, 60, 120, 10, 5, 3, 1, 10, 220, _player,false);
	////_monster[15].init("루갈", "루갈 총알", WINSIZEX + 200, 50, 60, 120, 10, 5, 3, 1, 10, 235, _player,true);
	////
	////_monster[16].init("루갈", "루갈 총알", WINSIZEX + 200, 50, 60, 120, 10, 5, 3, 1, 10, 260, _player,true);
	////_monster[17].init("루갈", "루갈 총알", WINSIZEX + 200, 150, 60, 120, 10, 5, 3, 1, 10, 275, _player,false);
	_monster[18].init("루갈", "루갈 총알", WINSIZEX + 200, 250, 60, 120, 20, 2, 3, 1, 120, 290, _player,false);
	_monster[19].init("루갈", "루갈 총알", WINSIZEX + 200, 350, 60, 120, 20, 2, 3, 1, 120, 305, _player,false);
	//_monster[20].init("루갈", "루갈 총알", WINSIZEX + 200, 450, 60, 120, 20, 5, 3, 1, 50, 320, _player,false);
	_monster[21].init("루갈", "루갈 총알", WINSIZEX + 200, 550, 60, 120, 20, 2, 3, 1, 120, 335, _player,false);
	//_monster[22].init("루갈", "루갈 총알", WINSIZEX + 200, 650, 60, 120, 20, 5, 3, 1, 50, 350, _player,false);
	_monster[23].init("루갈", "루갈 총알", WINSIZEX + 200, 750, 60, 120, 20, 2, 3, 1, 120, 365, _player,false);
	
	_monster[24].init("루갈", "루갈 총알", WINSIZEX + 200, 750, 60, 120, 20, 2, 3, 1, 120, 260, _player,true);
	_monster[25].init("루갈", "루갈 총알", WINSIZEX + 200, 650, 60, 120, 20, 2, 3, 1, 120, 275, _player,false);
	_monster[26].init("루갈", "루갈 총알", WINSIZEX + 200, 550, 60, 120, 20, 2, 3, 1, 120, 290, _player,false);
	_monster[27].init("루갈", "루갈 총알", WINSIZEX + 200, 450, 60, 120, 20, 2, 3, 1, 120, 305, _player,false);
	_monster[28].init("루갈", "루갈 총알", WINSIZEX + 200, 350, 60, 120, 20, 2, 3, 1, 120, 320, _player,false);
	_monster[29].init("루갈", "루갈 총알", WINSIZEX + 200, 250, 60, 120, 20, 2, 3, 1, 120, 335, _player,false);
	_monster[30].init("루갈", "루갈 총알", WINSIZEX + 200, 150, 60, 120, 20, 2, 3, 1, 120, 350, _player,false);
	_monster[31].init("루갈", "루갈 총알", WINSIZEX + 200, 50, 60, 120, 20, 2, 3, 1, 120, 365, _player, true);
	////======================게닛츠================================//
	_monster2[0].init("게닛츠", "게닛츠 총알", WINSIZEX + 200, 100, 60, 120, 40, 5, 8, 5, 50, 500, _player, true);
	_monster2[1].init("게닛츠", "게닛츠 총알", WINSIZEX + 200, 300, 60, 120, 40, 5, 8, 5, 50, 600, _player, true);
	_monster2[2].init("게닛츠", "게닛츠 총알", WINSIZEX + 200, 500, 60, 120, 40, 8, 8, 5, 50, 700, _player, true);
	_monster2[3].init("게닛츠", "게닛츠 총알", WINSIZEX + 200, 200, 60, 120, 40, 8, 8, 5, 50, 800, _player, true);
	_monster2[4].init("게닛츠", "게닛츠 총알", WINSIZEX + 200, 400, 60, 120, 40, 8, 8, 5, 50, 900, _player, true);
	_monster2[5].init("게닛츠", "게닛츠 총알", WINSIZEX + 200, 600, 60, 120, 40, 8, 8, 5, 50, 1000, _player, true);
	//======================무카이================================//
	_monster3[0].init("무카이", "무카이 총알", WINSIZEX + 200, WINSIZEY/2-200, /*사이즈*/60, /*사이즈*/120, /*체력*/120, /*속도*/8, 13, 1, /*총알발사 쿨*/40, 1500, _player, false);
	_monster3[1].init("무카이", "무카이 총알", WINSIZEX + 200, WINSIZEY/2, 60, 120, 120, 8, 13, 1, 40, 1600, _player, false);
	_monster3[2].init("무카이", "무카이 총알", WINSIZEX + 200, WINSIZEY/2+200, 60, 120, 120, 8, 13, 1, 40, 1700, _player, false);
	//======================이오리=================================//
	_boss[0].init("이오리", "이오리 총알", WINSIZEX + 200, 300, 300, 900, 1000, 5, 14, 1, 10, 3000, _player, true);
	//카메라 클래스 초기화
	//_camera = new camera;
	//_camera->init();
	

	//루프용 변수 초기화 
	_loopX = _loopY = 0;
	
	//알파블랜딩 변수 초기화
	_alpha = 0;
	_alpha2 = 0;
	_alpha3 = 0;
	_count = 0;
	_count2 = 0;
	_count3 = 0;

	return S_OK;
}

//=============================================================
//	## 해제 ## release()
//=============================================================
void mainGame::release()
{
	gameNode::release();
	//이미지 클래스를 나갈때까진 사용할 일 없다
	//동적할당 new를 사용했다면 이곳에서 SAFE_DELETE() 사용한다

	//플레이어 클래스 해제 
	SAFE_DELETE(_player);

	//카메라 클래스 해제
	//_camera->release();
	//SAFE_DELETE(_camera);
}

//=============================================================
//	## 업데이트 ## update()
//=============================================================
void mainGame::update()
{
	gameNode::update();
	//이곳에서 계산식, 키보드, 마우스등등 업데이트를 한다
	//간단하게 이곳에서 코딩한다고 생각하면 된다
	//충돌처리
	
	//플레이어 클래스 업데이트
	_player->update();


	//몬스터 클래스 업데이트
	for (int i = 0; i < UNIT_MAX; i++) {
		_monster[i].update();
	}
	for (int i = 0; i < MON2_MAX; i++) {
		_monster2[i].update();
	}
	for (int i = 0; i < MON3_MAX; i++) {
		_monster3[i].update();
	}
	for (int i = 0; i < BOSS_MAX; i++) {
		_boss[i].update();
	}
	//카메라 클래스 업데이트
	//_camera->update();

	//불렛 매니저 업데이트
	BULLETMANAGER->update();

	_loopX++;
	
	
}

//=============================================================
//	## 렌더 ## render()
//=============================================================
void mainGame::render()
{
	//흰색 빈 비트맵 (이것은 렌더에 그냥 두기)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//백그라운드 루프렌더
	RECT rc = RectMake(0, 0, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->loopRender("백그라운드", getMemDC(), &rc, _loopX, _loopY);
	
	
	_count++;
	if (_count > 400)
	{
		_alpha++;
		if (_alpha > 255)
			_alpha = 255;
		RECT rc2 = RectMake(0, 0, WINSIZEX, WINSIZEY);
		
		//IMAGEMANAGER->alphaRender("백그라운드1", getMemDC(), _alpha);
		//IMAGEMANAGER->loopRender("백그라운드1", getMemDC(), &rc, _loopX, _loopY);
		IMAGEMANAGER->loopAlphaRender("백그라운드1", getMemDC(), &rc, _loopX, _loopY, _alpha);
		
	}
	_count2++;
	if (_count2 > 1200)
	{
		_alpha2++;
		if (_alpha2 > 255)
			_alpha2 = 255;
		RECT rc3 = RectMake(0, 0, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->loopAlphaRender("백그라운드2", getMemDC(), &rc, _loopX, _loopY, _alpha2);
	}
	_count3++;
	if (_count3 > 2800)
	{
		_alpha3++;
		if (_alpha3 > 255)
			_alpha3 = 255;
		RECT rc4 = RectMake(0, 0, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->loopAlphaRender("백그라운드3", getMemDC(), &rc, _loopX, _loopY, _alpha3);
	}

	//string strKey, HDC hdc, BYTE alpha
	//불렛 매니저 렌더;
	BULLETMANAGER->render(getMemDC());

	//플레이어 렌더 
	_player->render(getMemDC());
	
	//몬스터 렌더
	for (int i = 0; i < UNIT_MAX; i++) {
		_monster[i].render(getMemDC());
	}
	for (int i = 0; i < MON2_MAX; i++) {
		_monster2[i].render(getMemDC());
	}
	for (int i = 0; i < MON3_MAX; i++) {
		_monster3[i].render(getMemDC());
	}
	for (int i = 0; i < BOSS_MAX; i++) {
		_boss[i].render(getMemDC());
	}
	this->getBackBuffer()->render(getHDC());
}




