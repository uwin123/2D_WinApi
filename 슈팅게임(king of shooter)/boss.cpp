#include "stdafx.h"
#include "boss.h"

HRESULT boss::init(string p_imgUnitKey, string p_imgBulletKey, int p_posX, int p_posY, int p_sizeX, 
	int p_sizeY, int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY, int fireRate, 
	int p_waitTime, player * p_player, bool p_isAimTarget)
{
	//임시
	_player = p_player;

	//영역
	rect = RectMakeCenter(p_posX, p_posY, p_sizeX, p_sizeY);
	//재생 성
	if(remakeBoss)
	rebornSite = RectMakeCenter(p_posX, p_posY, p_sizeX, p_sizeY);
	
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
	isBoss = false;
	isPlayer = false;
	isAimTarget = p_isAimTarget;
	bossDead = false;
	mukaiCount = 0;
	bossCount = 0;
	bossCount2 = 0;
	bossCount3 = 0;
	bossCount4 = 0;
	bossCount5 = 0;
	bossCount6 = 0;
	bossCount7 = 0;
	//remakeBoss = false;
	//isAfterMons1 = false;

	//애니메이션
	_count = 0;
	currentFrameX = p_maxFrameX - 1;
	currentFrameY = 0;
	maxFrameX = p_maxFrameX;
	maxFrameY = p_maxFrameY;
	fireCount = fireRate;
	currentFireCount = 0;
	stopmakerugalCount = 0;
	canFire = true;
	angleCount = 0;
	waitCount = p_waitTime;
	currentWaitCount = 0;


	return S_OK;
}

void boss::update()
{
	if (!isDead)
	{
		if (!isAppear)
		{
			currentWaitCount++;
			if (currentWaitCount >= waitCount)
			{
				currentWaitCount = 0;
				isAppear = true;
			}
		}
		if (isAppear)
		{
			Unit::update();
			this->monsterMove();
			this->monsterFire();

		}
	}
	else
		bossDead = true;
}

void boss::render(HDC hdc)
{
	if (isAppear)
		Unit::render(hdc);
	if(bossDead)
		IMAGEMANAGER->render("게임오버", hdc, WINSIZEX / 2 - 200, WINSIZEY / 2);

}

void boss::monsterMove()
{
	// 등장했을 경우, 움직임.
	if (isAppear)
	{
		if (rect.left > WINSIZEX / 2 + 300)
		{
			OffsetRect(&rect, -speed, 0);
			this->monsterFire();
		}
		
		bossCount++;
		if (bossCount > 100&&bossCount<200 )
		{
			if(rect.left>WINSIZEX/2-400)
			OffsetRect(&rect, -speed * 5, 0);
		}
		bossCount2++;
		if (bossCount2 > 200&& bossCount2<400)
		{
			if (rect.left < WINSIZEX / 2 + 400)
			OffsetRect(&rect, speed * 5, 0);
		}
		bossCount3++;
		if (bossCount3 > 400 && bossCount3 < 600)
		{
			if (rect.left > WINSIZEX / 2 - 400)
				OffsetRect(&rect, -speed * 5, 0);
		}
		bossCount4++;
		if (bossCount4 > 600 && bossCount4 < 800)
		{
			if (rect.left < WINSIZEX / 2 + 400)
				OffsetRect(&rect, speed * 5, 0);
		}
		bossCount5++;
		if (bossCount5 > 800 && bossCount5 < 1000)
		{
			if (rect.left > WINSIZEX / 2 - 400)
				OffsetRect(&rect, -speed * 5, 0);
		}
		bossCount6++;
		if (bossCount6 > 1000 && bossCount6 < 1200)
		{
			if (rect.left < WINSIZEX / 2 + 400)
				OffsetRect(&rect, speed * 5, 0);
		}
		
	}

}

void boss::monsterFire()
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

					//빙글빙글 슛

						float t_angle = PI * (15 * angleCount) / 180;
						angleCount++;
						BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, true, t_angle);

					//for (int i = 0; i < 10; i++)
					//{
					//	float t_angle = 0;
					//	t_angle += PI * 36 * i / 180;
					//	BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, true, t_angle);
					//}
					// 조준 발사
					//if (isAimTarget) {
					//	BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, true,
					//		SetFireToPlayer());
					//}
					//else
					//	BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, false,
					//		100);

				}
			}

		}
	}
}

float boss::SetFireToPlayer()
{
	int l = rect.left;
	int r = rect.right;
	int t = rect.top;
	int b = rect.bottom;

	int cX = l + (r - l) / 2;			//몬스터3 중심 좌표x
	int cY = t + (b - t) / 2;			//몬스터3 중심 좌표y

	int pL = _player->rect.left;
	int pR = _player->rect.right;
	int pT = _player->rect.top;
	int pB = _player->rect.bottom;

	int cPx = pL + (pR - pL) / 2;	//플레이어 중심 x좌표 
	int cPy = pT + (pB - pT) / 2;	//플레이어 중심 y좌표 

	return atan2((cPy - cY), (cPx - cX));
}

void boss::animation()
{
	if (isAppear)
	{
		if (++_count > 3)
		{

			if (--currentFrameX < 0)
				currentFrameX = maxFrameX - 1;
			_count = 0;
		}
		
	}
}
