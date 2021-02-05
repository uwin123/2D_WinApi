#include "Bullet.h"

#pragma once
class Unit
{

public:
	// 영역
	RECT rect;
	//재생성 영역
	RECT rebornSite;
	
	// 이미지
	string imgUnitKey;
	string imgBulletKey;
	string imgSkillBulletKey;

	// 스텟
	float speed;
	int hp;
	int currentHp;
	bool skillFire;
	POINT dir;

	// 상태값
	bool isAppear;
	bool isDead;
	bool playerDead = false;
	bool isMonster;
	bool isPlayer;
	bool isReborn;
	bool isBoss;
	bool isgameOver;
	bool isFrameImage;
	int rebornCount;
	bool showAttackEffect;

	int bloodcount = 0;
	

	// 애니메이션
	int _count;			//프레임 돌릴 카운트 (속도조절)
	int currentFrameX;
	int currentFrameY;
	int maxFrameX;
	int maxFrameY;

public:
	void hurt(int p_num);
	void dead();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void animation();
	void collision();
	
	RECT GetRect() 
	{
		return rect;
	}
	

};

