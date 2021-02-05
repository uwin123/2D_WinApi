#include "stdafx.h"
#include "monster3.h"

HRESULT monster3::init(string p_imgUnitKey, string p_imgBulletKey, int p_posX, 
	int p_posY, int p_sizeX, int p_sizeY, int p_hp, int p_speed, int p_maxFrameX, 
	int p_maxFrameY, int fireRate, int p_waitTime, player * p_player, bool p_isAimTarget)
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
	mukaiCount = 0;
	mukaiCount2 = 0;
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
	angleCount = 0;
	waitCount = p_waitTime;
	currentWaitCount = 0;
	

	return S_OK;
}

void monster3::update()
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

void monster3::render(HDC hdc)
{
	if (isAppear)
		Unit::render(hdc);
}

void monster3::monsterMove()
{
	// �������� ���, ������.
	if (isAppear)
	{
		if (rect.left > WINSIZEX / 2+300)
		{
			OffsetRect(&rect, -speed, 0);
			this->monsterFire();
		}
		mukaiCount++;
		if (mukaiCount > 100 && mukaiCount < 200)
		{
			if (rect.left > WINSIZEX / 2 - 200)
				OffsetRect(&rect, -speed * 2, 0);
		}
		mukaiCount2++;
		if (mukaiCount2 > 200 && mukaiCount2 < 400)
		{
			if (rect.left < WINSIZEX / 2 + 400)
				OffsetRect(&rect, speed * 2, 0);
		}

	}
}

void monster3::monsterFire()
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

					//���ۺ��� ��
					
						//float t_angle = PI * (20 * angleCount) / 180;
						//angleCount++;
						//BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, true, t_angle);
						
					for (int i = 0; i < 10; i++) 
					{
						float t_angle = 0;
						t_angle += PI * 36 * i / 180;
						BULLETMANAGER->BulletSetting(imgBulletKey, rect.left, halfHeight, true, t_angle);
					}
						
					
				}
			}

		}
	}
}

float monster3::SetFireToPlayer()
{
	int l = rect.left;
	int r = rect.right;
	int t = rect.top;
	int b = rect.bottom;

	int cX = l + (r - l) / 2;			//����3 �߽� ��ǥx
	int cY = t + (b - t) / 2;			//����3 �߽� ��ǥy

	int pL = _player->rect.left;
	int pR = _player->rect.right;
	int pT = _player->rect.top;
	int pB = _player->rect.bottom;

	int cPx = pL + (pR - pL) / 2;	//�÷��̾� �߽� x��ǥ 
	int cPy = pT + (pB - pT) / 2;	//�÷��̾� �߽� y��ǥ 

	return atan2((cPy - cY), (cPx - cX));
}

//float monster3::AutoFireAttack()
//{
//
//	int l = rect.left;
//	int r = rect.right;
//	int t = rect.top;
//	int b = rect.bottom;
//
//	int cX = l + (r - l) / 2;
//	int cY = t + (b - t) / 2;
//
//	return atan2((cX - WINSIZEX), (cY - WINSIZEY));
//	
//
//	return 0.0f;
//}
