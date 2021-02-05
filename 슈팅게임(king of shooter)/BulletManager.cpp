#include "stdafx.h"
#include "BulletManager.h"

HRESULT BulletManager::init()
{
	//�Ѿ˵��� �ӵ��� ���Ͱ� ��� ������, ������ ����Ǵ��� �Ǵ�
	_playerBullet.init("ġ��� �Ѿ�", 40, 40, 10, 25, { 1, 0 }, false, false,false);
	_playerSkillBullet.init("ġ��� ��ų �Ѿ�", 200, 500, 3, 25,{1, 0},false,false,false);
	_monsterBullet.init("�簥 �Ѿ�", 20, 20, 8, -25, { -1,0  }, true, true, false);
	_geonitzBullet.init("�Դ��� �Ѿ�", 92, 224, 8, -25, { -1, 0 }, true, true, false);
	_mukaiBullet.init("��ī�� �Ѿ�", 42, 65, 10, -25, { -1, 0 }, true, true, false);
	_ioriBullet.init("�̿��� �Ѿ�", 50, 100, 15, -25, { -1, 0 }, true, true, true);

	for (int i = 0; i < BULLET_MAX; i++) {
		_bullets[i].init("temp", 0, 0, 0, 0, { 0, 0 }, false,false,false);
	}

	IMAGEMANAGER->addImage("ġ��� �Ѿ�", "�Ѿ�1.bmp", 40, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�簥 �Ѿ�", "�簥�Ѿ�1.bmp", 20, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Դ��� �Ѿ�", "�Դ��� �Ѿ�.bmp", 92, 224, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ī�� �Ѿ�", "��ī�� �Ѿ�.bmp", 42, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�̿��� �Ѿ�", "�̿��� �Ѿ�.bmp", 800, 100, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ġ��� ��ų �Ѿ�", "�ϰ��ʻ�4.bmp", 800, 400, 4, 1, true, RGB(255, 0, 255));

	return S_OK;
}

void BulletManager::update()
{
	for (int i = 0; i < BULLET_MAX; i++) {
		_bullets[i].update();
	}
}

void BulletManager::render(HDC hdc)
{
	for (int i = 0; i < BULLET_MAX; i++) 
	{
		_bullets[i].render(hdc);	
	}
}

void BulletManager::BulletSetting(string p_imgBulletKey, int p_posX, int p_posY, bool p_isAngle, 
	float p_angle)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!_bullets[i].isFire) {
			
			if (p_imgBulletKey == _monsterBullet.imgBulletKey)
				_bullets[i] = _monsterBullet;

			if (p_imgBulletKey == _playerBullet.imgBulletKey)
				_bullets[i] = _playerBullet;

			if (p_imgBulletKey == _playerSkillBullet.imgBulletKey)
				_bullets[i] = _playerSkillBullet;

			if (p_imgBulletKey == _geonitzBullet.imgBulletKey)
				_bullets[i] = _geonitzBullet;

			if (p_imgBulletKey == _mukaiBullet.imgBulletKey)
				_bullets[i] = _mukaiBullet;

			if (p_imgBulletKey == _ioriBullet.imgBulletKey)
				_bullets[i] = _ioriBullet;

			_bullets[i].isAngle = p_isAngle;
			_bullets[i].angle = p_angle;
			_bullets[i].fire(p_posX, p_posY);
			
			break;
		}
	}

}

void BulletManager::finishBullet(int p_index)
{
	_bullets[p_index].isFire = false;
}


