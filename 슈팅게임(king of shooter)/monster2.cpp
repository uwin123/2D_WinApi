#include "stdafx.h"
#include "monster2.h"

HRESULT monster2::init(string p_imgUnitKey, string p_imgBulletKey, int p_posX, int p_posY, int p_sizeX,
	int p_sizeY, int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY,
	int fireRate, int p_waitTime, player * p_player, bool p_isAimTarget)
{
	//�ӽ�
	_player = p_player;

	//����
	rect = RectMakeCenter(p_posX, p_posY, p_sizeX, p_sizeY);
	//����� ���� ǥ��

	//monsterRebornSite = RectMakeCenter(p_posX,p_posY, p_sizeX, p_sizeY);
	//�̹���
	imgUnitKey = p_imgUnitKey;
	imgBulletKey = p_imgBulletKey;

	//����
	hp = p_hp;
	currentHp = hp;
	speed = p_speed;

	//���°�
	isDead = false;
	isAppear = false;
	isMonster = true;
	isPlayer = false;
	isAimTarget = p_isAimTarget;
	moving2Count = 0;
	//isAfterMons1 = false;

	//�ִϸ��̼�
	_count = 0;
	currentFrameX = 0;
	currentFrameY = 0;
	maxFrameX = p_maxFrameX;
	maxFrameY = p_maxFrameY;
	fireCount = fireRate;
	currentFireCount = 0;
	stopmakerugalCount = 0;
	canFire = true;

	waitCount = p_waitTime;
	currentWaitCount = 0;


	return S_OK;
}

void monster2::update()
{
	if (!isDead) {
		if (!isAppear) {
			currentWaitCount++;
			if (currentWaitCount >= waitCount) {
				currentWaitCount = 0;
				isAppear = true;
			}
		}
		if (isAppear) {
			Unit::update();
			this->monsterMove();
			this->monsterFire();
		}
	}

}

void monster2::render(HDC hdc)
{
	if (isAppear)
		Unit::render(hdc);

}

void monster2::monsterMove()
{
	// �������� ���, ������.
	if (isAppear) 
	{
		if (rect.left > WINSIZEX / 2)
		{
			OffsetRect(&rect, -speed, 0);
			this->monsterFire();
		}
		moving2Count++;
		if (moving2Count > 400)
		{
			OffsetRect(&rect, 0, speed);
			canFire = false;
		}

	}
}

void monster2::monsterFire()
{
	// ������ ���-
	if (isAppear)
	{
		// �߻� ������ ���-
		if (canFire)
		{
			if (rect.left < WINSIZEX - 100)
			{
				// ������
				currentFireCount++;
				if (currentFireCount >= fireCount)
				{
					currentFireCount = 0;
					int halfHeight = rect.top + (rect.bottom - rect.top) / 2;

					// ���� �߻�
					if (isAimTarget) {
						BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, true, SetFireToPlayer());
					}
					else
						BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, false, 0.0f);
				}
			}
			
		}
	}
}

float monster2::SetFireToPlayer()
{
	int l = rect.left;
	int r = rect.right;
	int t = rect.top;
	int b = rect.bottom;

	int cX = l + (r - l) / 2;
	int cY = t + (b - t) / 2;

	int pL = _player->rect.left;
	int pR = _player->rect.right;
	int pT = _player->rect.top;
	int pB = _player->rect.bottom;

	int cPx = pL + (pR - pL) / 2;
	int cPy = pT + (pB - pT) / 2;

	return atan2((cPy - cY), (cPx - cX));
}
