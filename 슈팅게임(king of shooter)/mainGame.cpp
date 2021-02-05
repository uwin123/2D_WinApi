#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init()
//=============================================================
HRESULT mainGame::init()
{
	gameNode::init();

	//�̰����� �ʱ�ȭ�� �Ѵ�

	IMAGEMANAGER->addImage("��", "��.bmp", 130, 111, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ӿ���", "���ӿ���.bmp", 360, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��׶���", "�簥��.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("��׶���1", "ŷ����1.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("��׶���2", "ŷ����2.bmp", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addImage("��׶���3", "ŷ����3.bmp", WINSIZEX, WINSIZEY);
	
	IMAGEMANAGER->addFrameImage("ġ���", "ġ���1.bmp", 180, 240, 3, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�簥", "�簥1.bmp", 180, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�Դ���", "�Դ���.bmp", 1000, 180, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ī��", "��ī��1.bmp", 1813, 158, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�̿���", "�̿��� ����.bmp", 8960, 900, 14, 1, true, RGB(255, 0, 255));

	//�÷��̾� Ŭ���� �ʱ�ȭ
	_player = new player;

	_player->init("ġ���", "ġ��� �Ѿ�", 150, WINSIZEY / 2, 80, 60, 1000, 5, 3, 4, false);
	
	_player->init("ġ���", "ġ��� ��ų �Ѿ�", 150, WINSIZEY / 2, 80, 60, 1000, 5, 3, 4, true);
	//100 80
	//���� Ŭ���� �ʱ�ȭ
	//���⼭ ���͵��� ���� �ӵ�, �߻� �ӵ� �� ���� 
	//=====================�簥==========================//
	_monster[0].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, WINSIZEY/2, 60, 120, 20, 2, 3, 1, 120, 0, _player, false);
	_monster[1].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 150, 60, 120, 20, 2, 3, 1, 120, 15, _player, false);
	_monster[2].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 250, 60, 120, 20, 2, 3, 1, 120, 30, _player, false);
	//_monster[3].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 350, 60, 120, 20, 2, 3, 1, 120, 45, _player, false);
	_monster[4].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 450, 60, 120, 20, 2, 3, 1, 120, 60, _player, false);
	_monster[5].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 550, 60, 120, 20, 2, 3, 1, 120, 75, _player, false);
	//_monster[6].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 650, 60, 120, 20, 2, 3, 1, 120, 90, _player, false);
	_monster[7].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 750, 60, 120, 20, 2, 3, 1, 120, 105, _player, true);
	
	//_monster[8].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 750, 60, 120, 10, 5, 3, 1, 10, 130, _player,true);
	//_monster[9].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 650, 60, 120, 10, 5, 3, 1, 10, 145, _player, false);
	//_monster[10].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 550, 60, 120, 10, 5, 3, 1, 10, 160, _player,false);
	//_monster[11].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 450, 60, 120, 10, 5, 3, 1, 10, 175, _player,false);
	//_monster[12].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 350, 60, 120, 10, 5, 3, 1, 10, 190, _player,false);
	//_monster[13].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 250, 60, 120, 10, 5, 3, 1, 10, 205, _player,false);
	////_monster[14].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 150, 60, 120, 10, 5, 3, 1, 10, 220, _player,false);
	////_monster[15].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 50, 60, 120, 10, 5, 3, 1, 10, 235, _player,true);
	////
	////_monster[16].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 50, 60, 120, 10, 5, 3, 1, 10, 260, _player,true);
	////_monster[17].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 150, 60, 120, 10, 5, 3, 1, 10, 275, _player,false);
	_monster[18].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 250, 60, 120, 20, 2, 3, 1, 120, 290, _player,false);
	_monster[19].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 350, 60, 120, 20, 2, 3, 1, 120, 305, _player,false);
	//_monster[20].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 450, 60, 120, 20, 5, 3, 1, 50, 320, _player,false);
	_monster[21].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 550, 60, 120, 20, 2, 3, 1, 120, 335, _player,false);
	//_monster[22].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 650, 60, 120, 20, 5, 3, 1, 50, 350, _player,false);
	_monster[23].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 750, 60, 120, 20, 2, 3, 1, 120, 365, _player,false);
	
	_monster[24].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 750, 60, 120, 20, 2, 3, 1, 120, 260, _player,true);
	_monster[25].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 650, 60, 120, 20, 2, 3, 1, 120, 275, _player,false);
	_monster[26].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 550, 60, 120, 20, 2, 3, 1, 120, 290, _player,false);
	_monster[27].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 450, 60, 120, 20, 2, 3, 1, 120, 305, _player,false);
	_monster[28].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 350, 60, 120, 20, 2, 3, 1, 120, 320, _player,false);
	_monster[29].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 250, 60, 120, 20, 2, 3, 1, 120, 335, _player,false);
	_monster[30].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 150, 60, 120, 20, 2, 3, 1, 120, 350, _player,false);
	_monster[31].init("�簥", "�簥 �Ѿ�", WINSIZEX + 200, 50, 60, 120, 20, 2, 3, 1, 120, 365, _player, true);
	////======================�Դ���================================//
	_monster2[0].init("�Դ���", "�Դ��� �Ѿ�", WINSIZEX + 200, 100, 60, 120, 40, 5, 8, 5, 50, 500, _player, true);
	_monster2[1].init("�Դ���", "�Դ��� �Ѿ�", WINSIZEX + 200, 300, 60, 120, 40, 5, 8, 5, 50, 600, _player, true);
	_monster2[2].init("�Դ���", "�Դ��� �Ѿ�", WINSIZEX + 200, 500, 60, 120, 40, 8, 8, 5, 50, 700, _player, true);
	_monster2[3].init("�Դ���", "�Դ��� �Ѿ�", WINSIZEX + 200, 200, 60, 120, 40, 8, 8, 5, 50, 800, _player, true);
	_monster2[4].init("�Դ���", "�Դ��� �Ѿ�", WINSIZEX + 200, 400, 60, 120, 40, 8, 8, 5, 50, 900, _player, true);
	_monster2[5].init("�Դ���", "�Դ��� �Ѿ�", WINSIZEX + 200, 600, 60, 120, 40, 8, 8, 5, 50, 1000, _player, true);
	//======================��ī��================================//
	_monster3[0].init("��ī��", "��ī�� �Ѿ�", WINSIZEX + 200, WINSIZEY/2-200, /*������*/60, /*������*/120, /*ü��*/120, /*�ӵ�*/8, 13, 1, /*�Ѿ˹߻� ��*/40, 1500, _player, false);
	_monster3[1].init("��ī��", "��ī�� �Ѿ�", WINSIZEX + 200, WINSIZEY/2, 60, 120, 120, 8, 13, 1, 40, 1600, _player, false);
	_monster3[2].init("��ī��", "��ī�� �Ѿ�", WINSIZEX + 200, WINSIZEY/2+200, 60, 120, 120, 8, 13, 1, 40, 1700, _player, false);
	//======================�̿���=================================//
	_boss[0].init("�̿���", "�̿��� �Ѿ�", WINSIZEX + 200, 300, 300, 900, 1000, 5, 14, 1, 10, 3000, _player, true);
	//ī�޶� Ŭ���� �ʱ�ȭ
	//_camera = new camera;
	//_camera->init();
	

	//������ ���� �ʱ�ȭ 
	_loopX = _loopY = 0;
	
	//���ĺ��� ���� �ʱ�ȭ
	_alpha = 0;
	_alpha2 = 0;
	_alpha3 = 0;
	_count = 0;
	_count2 = 0;
	_count3 = 0;

	return S_OK;
}

//=============================================================
//	## ���� ## release()
//=============================================================
void mainGame::release()
{
	gameNode::release();
	//�̹��� Ŭ������ ���������� ����� �� ����
	//�����Ҵ� new�� ����ߴٸ� �̰����� SAFE_DELETE() ����Ѵ�

	//�÷��̾� Ŭ���� ���� 
	SAFE_DELETE(_player);

	//ī�޶� Ŭ���� ����
	//_camera->release();
	//SAFE_DELETE(_camera);
}

//=============================================================
//	## ������Ʈ ## update()
//=============================================================
void mainGame::update()
{
	gameNode::update();
	//�̰����� ����, Ű����, ���콺��� ������Ʈ�� �Ѵ�
	//�����ϰ� �̰����� �ڵ��Ѵٰ� �����ϸ� �ȴ�
	//�浹ó��
	
	//�÷��̾� Ŭ���� ������Ʈ
	_player->update();


	//���� Ŭ���� ������Ʈ
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
	//ī�޶� Ŭ���� ������Ʈ
	//_camera->update();

	//�ҷ� �Ŵ��� ������Ʈ
	BULLETMANAGER->update();

	_loopX++;
	
	
}

//=============================================================
//	## ���� ## render()
//=============================================================
void mainGame::render()
{
	//��� �� ��Ʈ�� (�̰��� ������ �׳� �α�)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//��׶��� ��������
	RECT rc = RectMake(0, 0, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->loopRender("��׶���", getMemDC(), &rc, _loopX, _loopY);
	
	
	_count++;
	if (_count > 400)
	{
		_alpha++;
		if (_alpha > 255)
			_alpha = 255;
		RECT rc2 = RectMake(0, 0, WINSIZEX, WINSIZEY);
		
		//IMAGEMANAGER->alphaRender("��׶���1", getMemDC(), _alpha);
		//IMAGEMANAGER->loopRender("��׶���1", getMemDC(), &rc, _loopX, _loopY);
		IMAGEMANAGER->loopAlphaRender("��׶���1", getMemDC(), &rc, _loopX, _loopY, _alpha);
		
	}
	_count2++;
	if (_count2 > 1200)
	{
		_alpha2++;
		if (_alpha2 > 255)
			_alpha2 = 255;
		RECT rc3 = RectMake(0, 0, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->loopAlphaRender("��׶���2", getMemDC(), &rc, _loopX, _loopY, _alpha2);
	}
	_count3++;
	if (_count3 > 2800)
	{
		_alpha3++;
		if (_alpha3 > 255)
			_alpha3 = 255;
		RECT rc4 = RectMake(0, 0, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->loopAlphaRender("��׶���3", getMemDC(), &rc, _loopX, _loopY, _alpha3);
	}

	//string strKey, HDC hdc, BYTE alpha
	//�ҷ� �Ŵ��� ����;
	BULLETMANAGER->render(getMemDC());

	//�÷��̾� ���� 
	_player->render(getMemDC());
	
	//���� ����
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




