#include "stdafx.h"
#include "Unit.h"

void Unit::hurt(int p_num)
{
	if (!isDead) 
	{
		currentHp -= p_num;
		if (currentHp <= 0) 
		{
			dead();
		}
	}	
}

void Unit::dead()
{
	isDead = true;
	isAppear = false;
}

void Unit::update()
{
	animation();
	if (showAttackEffect)
	{
		bloodcount++;
		if (bloodcount > 10)
		{
			bloodcount = 0;
			showAttackEffect = false;
		}
	}
	collision();
}

void Unit::render(HDC hdc)
{
	IMAGEMANAGER->frameRender(imgUnitKey, hdc, rect.left, rect.top, currentFrameX, currentFrameY);

	if (showAttackEffect)
	IMAGEMANAGER->render("피", hdc, (rect.left + rect.right) / 2-70, (rect.top + rect.bottom) / 2-100);

}

void Unit::animation()
{
	if (isAppear) 
	{
		if (++_count > 5) 
		{
			_count = 0;
			if (++currentFrameX >= maxFrameX)
				currentFrameX = 0;
		}
	}
}

void Unit::collision()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		Bullet t_bullet = BULLETMANAGER->getBullet(i);

		if (!t_bullet.isFire) continue;							// 발사 안 된 총알은 무시
		if (imgBulletKey == t_bullet.imgBulletKey) continue;	// 내게 부딪친 총알이 내가 쏜 총알과 같다면 패스
		if (t_bullet.isMonsterFire == isMonster) continue;		//몬스터가 쏜 총알이 몬스터들과 같을때,(몬스터 총알이 몬스터 맞을때)
		RECT temp;
		if (IntersectRect(&temp, &rect, &t_bullet.rect))
		{
			if (isMonster) 
			{
				showAttackEffect = true;
				hurt(10);
				
				BULLETMANAGER->finishBullet(i);
				break;
			}
			if (!isDead)
			{
				if (isPlayer) 
				{
					showAttackEffect = true;
					hurt(10);
					BULLETMANAGER->finishBullet(i);
					break;
				}
			}
		}
	}
}


