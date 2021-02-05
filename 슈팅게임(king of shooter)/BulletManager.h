#pragma once
#include "singletonBase.h"
#include "Bullet.h"

#define BULLET_MAX 700

class BulletManager : public singletonBase<BulletManager>
{
private:

	Bullet _bullets[BULLET_MAX];
	Bullet _playerBullet;
	Bullet _playerSkillBullet;
	Bullet _monsterBullet;
	Bullet _geonitzBullet;
	Bullet _mukaiBullet;
	Bullet _ioriBullet;


public:
	HRESULT init();
	void update();
	void render(HDC hdc);


	void BulletSetting(string p_imgBulletKey, int p_posX, int p_posY, bool p_isAngle, 
		float p_angle);
	void finishBullet(int p_index);
	Bullet getBullet(int p_index) { return _bullets[p_index]; }
};

