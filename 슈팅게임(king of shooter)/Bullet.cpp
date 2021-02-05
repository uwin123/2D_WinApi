#include "stdafx.h"
#include "Bullet.h"

void Bullet::init(string p_bulletKey, int sizeX, int sizeY, int p_speed, 
	int p_offsetX, POINT p_dir, bool p_isAngle, bool p_isMonsterFire, bool p_isBoss)
{
	// ����
	rect = RectMakeCenter(0, 0, sizeX, sizeY);

	// �̹���
	imgBulletKey = p_bulletKey;
	
	// �������ͽ�
	speed = p_speed;
	angle = 0;
	dir = p_dir;
	offsetX = p_offsetX;
	cycleCount = 0;
	timer = 0;

	// ���°�
	isFire = false;
	isAngle = p_isAngle;
	isMonsterFire = p_isMonsterFire;
	isBoss = p_isBoss;
	_count = 0;
	//�ƽ� �����Ӱ� ����
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
			if (imgBulletKey == "ġ��� ��ų �Ѿ�")
			{
				IMAGEMANAGER->frameRender("ġ��� ��ų �Ѿ�", hdc, (rect.right+rect.left)/2, (rect.top + rect.bottom) / 2-300);
			}
			else 
				IMAGEMANAGER->render(imgBulletKey, hdc, rect.left, rect.top);
		}
		
			
	}
}

void Bullet::moveBullet()
{
	if (isFire) {

		if (!isAngle)//������ �־����� ���� ��, �Ϲ� ���� �����Ѵ�. 
		{
			OffsetRect(&rect, speed * dir.x, speed * dir.y);
		}
		
		else if (isAngle)//������ �־��� ��,  ������ x,y ������ �����δ�. 
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
		IMAGEMANAGER->findImage("�̿��� �Ѿ�")->setFrameX(_index);

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
			IMAGEMANAGER->findImage("ġ��� ��ų �Ѿ�")->setFrameX(_index2);

		}
	}
	
}

