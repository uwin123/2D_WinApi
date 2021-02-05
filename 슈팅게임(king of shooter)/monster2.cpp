#include "stdafx.h"
#include "monster2.h"

HRESULT monster2::init(string p_imgUnitKey, string p_imgBulletKey, int p_posX, int p_posY, int p_sizeX,
	int p_sizeY, int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY,
	int fireRate, int p_waitTime, player * p_player, bool p_isAimTarget)
{
	//임시
	_player = p_player;

	//영역
	rect = RectMakeCenter(p_posX, p_posY, p_sizeX, p_sizeY);
	//재생성 영역 표시

	//monsterRebornSite = RectMakeCenter(p_posX,p_posY, p_sizeX, p_sizeY);
	//이미지
	imgUnitKey = p_imgUnitKey;
	imgBulletKey = p_imgBulletKey;

	//스텟
	hp = p_hp;
	currentHp = hp;
	speed = p_speed;

	//상태값
	isDead = false;
	isAppear = false;
	isMonster = true;
	isPlayer = false;
	isAimTarget = p_isAimTarget;
	moving2Count = 0;
	//isAfterMons1 = false;

	//애니메이션
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
	// 등장했을 경우, 움직임.
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
	// 등장한 경우-
	if (isAppear)
	{
		// 발사 가능한 경우-
		if (canFire)
		{
			if (rect.left < WINSIZEX - 100)
			{
				// 딜레이
				currentFireCount++;
				if (currentFireCount >= fireCount)
				{
					currentFireCount = 0;
					int halfHeight = rect.top + (rect.bottom - rect.top) / 2;

					// 조준 발사
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
