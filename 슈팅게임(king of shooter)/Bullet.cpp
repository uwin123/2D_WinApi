#include "stdafx.h"
#include "Bullet.h"

void Bullet::init(string p_bulletKey, int sizeX, int sizeY, int p_speed, 
	int p_offsetX, POINT p_dir, bool p_isAngle, bool p_isMonsterFire, bool p_isBoss)
{
	// 영역
	rect = RectMakeCenter(0, 0, sizeX, sizeY);

	// 이미지
	imgBulletKey = p_bulletKey;
	
	// 스테이터스
	speed = p_speed;
	angle = 0;
	dir = p_dir;
	offsetX = p_offsetX;
	cycleCount = 0;
	timer = 0;

	// 상태값
	isFire = false;
	isAngle = p_isAngle;
	isMonsterFire = p_isMonsterFire;
	isBoss = p_isBoss;
	_count = 0;
	//맥스 프레임값 해쥐
	maxFrameX = 0;
}

void Bullet::fire(int p_posX, int p_posY)
{
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	RECT t_rc = RectMakeCenter(p_posX + offsetX, p_posY, width, height);
	rect = t_rc;

	isFire = true;
}

void Bullet::update()
{
	moveBullet();
	outBullet();

	if (isBoss) {
		_count++;
		if (_count >= 5)
		{
			_count = 0;
			currentFrameX++;
			if (currentFrameX > maxFrameX)
				currentFrameX = 0;
		}
	}
	animation();
	//if (skillFire) {
	//	_count2++;
	//	if (_count2 >= 10)
	//	{
	//		_count2 = 0;
	//		currentFrameX++;
	//		if (currentFrameX > maxFrameX)
	//			currentFrameX = 0;
	//	}
	//}
	animation2();
}

void Bullet::render(HDC hdc)
{
	if (isFire) 
	{
		
		if (isBoss)
			IMAGEMANAGER->frameRender(imgBulletKey, hdc, rect.left, rect.top);
		else {
			if (imgBulletKey == "치즈루 스킬 총알")
			{
				IMAGEMANAGER->frameRender("치즈루 스킬 총알", hdc, (rect.right+rect.left)/2, (rect.top + rect.bottom) / 2-300);
			}
			else 
				IMAGEMANAGER->render(imgBulletKey, hdc, rect.left, rect.top);
		}
		
			
	}
}

void Bullet::moveBullet()
{
	if (isFire) {

		if (!isAngle)//각도가 주어지지 않을 때, 일반 직선 공격한다. 
		{
			OffsetRect(&rect, speed * dir.x, speed * dir.y);
		}
		
		else if (isAngle)//각도가 주어질 때,  설정한 x,y 식으로 움직인다. 
		{
				/*timer++;
				if (timer < 300)
				{
					float t_angle;
					t_angle = angle * (PI / 180)*cycleCount * 8;
					cycleCount++;
				
					float x = speed * cosf(t_angle);
					float y = speed * sinf(t_angle);
					OffsetRect(&rect, x, y);
				}
				if (timer >= 300)
				
					OffsetRect(&rect, speed * dir.x, speed * dir.y)*/;

			float x = speed * cosf(angle);
			float y = speed * sinf(angle);
			OffsetRect(&rect, x, y);
				
		}
	}
	return;
}

void Bullet::outBullet()
{
	if (isFire) {
		if (rect.left > WINSIZEX)
			isFire = false;
		else if (rect.right < 0)
			isFire = false;
	}
}

void Bullet::animation()
{
	_count++;
	if (_count > 40)
	{
		_index--;
		_count = 0;
		if (_index < 0)
			_index = 3;
		IMAGEMANAGER->findImage("이오리 총알")->setFrameX(_index);

	}
}

void Bullet::animation2()
{
	if (skillFire) {
		_count2++;
		if (_count2 > 80)
		{
			_index2--;
			_count2 = 0;
			if (_index2 < 0)
				_index2 = 3;
			IMAGEMANAGER->findImage("치즈루 스킬 총알")->setFrameX(_index2);

		}
	}
	
}

