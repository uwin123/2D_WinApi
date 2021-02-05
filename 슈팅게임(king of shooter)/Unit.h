#include "Bullet.h"

#pragma once
class Unit
{

public:
	// ����
	RECT rect;
	//����� ����
	RECT rebornSite;
	
	// �̹���
	string imgUnitKey;
	string imgBulletKey;
	string imgSkillBulletKey;

	// ����
	float speed;
	int hp;
	int currentHp;
	bool skillFire;
	POINT dir;

	// ���°�
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
	

	// �ִϸ��̼�
	int _count;			//������ ���� ī��Ʈ (�ӵ�����)
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

