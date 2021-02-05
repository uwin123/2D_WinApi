#pragma once
#define PI 3.1415926f
class Bullet
{
public:
	string imgBulletKey;
	RECT rect;
	float angle;
	float speed;
	float cycleAngle;
	POINT dir;

	int offsetX;
	bool isFire;
	bool isAngle;
	int bulletDamage;
	bool isMonsterFire;
	bool isBoss;
	int cycleCount;
	int timer;
	bool isAppear;
	bool skillFire;
	//프레임이미지 애니메이션
	int _count = 0;
	int _count2 = 0;
	int _index = 4;
	int _index2 = 3;

	int currentFrameX;
	int currentFrameY;
	int maxFrameX;
	int maxFrameY;
	
	

public:
	void init(string p_bulletKey, int sizeX, int sizeY, int p_speed, 
		int p_offsetX, POINT p_dir, bool p_isAngle, bool p_isMonsterFire, bool p_isBoss);

	void update();
	void render(HDC hdc);
	
	void fire(int p_posX, int p_posY);

	void moveBullet();
	
	void outBullet();
	void animation();
	void animation2();
	
};

