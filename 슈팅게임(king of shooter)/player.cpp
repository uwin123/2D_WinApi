#include "stdafx.h"
#include "player.h"

HRESULT player::init(string p_imgUnitKey, string p_imgBulletKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY,
	int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY, bool p_skillFire)
{
	//영역
	rect = RectMakeCenter(p_posX, p_posY, p_sizeX, p_sizeY);

	//이미지
	
	imgUnitKey = p_imgUnitKey;
	if (!p_skillFire)
	{
		imgBulletKey = p_imgBulletKey;
	}
	else 
	{
		imgSkillBulletKey = p_imgBulletKey;
	}
	

	//스텟
	hp = p_hp;
	currentHp = hp;
	speed = p_speed;
	skillFire = p_skillFire;


	//상태값
	isDead = false;
	isAppear = true;
	isMonster = false;
	isPlayer = true;
	playerDead = false;
	rebornCount = 0;
	skillfire = false;
	pressD = false;
	//애니메이션
	_count = 0;
	currentFrameX = 0;
	currentFrameY = 0;
	maxFrameX = p_maxFrameX;
	maxFrameY = p_maxFrameY;
	
	return S_OK;
}

void player::update()
{
		Unit::update();
		if (!isDead)
			playerController();
		else
		{
			isAppear = false;
			playerDead= true;
		}
}

void player::render(HDC hdc)
{
	if (!isDead)
		Unit::render(hdc);
	if(playerDead)
		IMAGEMANAGER->render("게임오버", hdc, WINSIZEX / 2 - 200, WINSIZEY / 2);
}

void player::playerController()
{
	// 플레이어의 움직임

	// 왼쪽
	if (INPUT->GetKey(VK_LEFT)&&rect.left>0) 
	{
		currentFrameY = 1;
		dir.x = -2;
	}
	// 오른쪽
	else if (INPUT->GetKey(VK_RIGHT)&& rect.right<WINSIZEX)
	{
		currentFrameY = 0;
		dir.x = 2;
	}
	else {
		dir.x = 0;
	}

	// 위 아래
	if (INPUT->GetKey(VK_UP)&&rect.top>0 || INPUT->GetKey(VK_DOWN)&&rect.bottom<WINSIZEY-20) 
	{
		currentFrameY = 2;
		if (INPUT->GetKey(VK_UP))
			dir.y = -2;
		else if (INPUT->GetKey(VK_DOWN))
			dir.y = 2;
	}
	else
		dir.y = 0;

	// 무빙 실행
	OffsetRect(&rect, speed * dir.x, speed * dir.y);

	// 발사
	if (INPUT->GetKeyDown('A')) 
	{
		// 발사
		{
			int halfHeight = rect.top + (rect.bottom - rect.top) / 2;
			BULLETMANAGER->BulletSetting(imgBulletKey, rect.right, halfHeight, false, false);
		}
	}
	//스킬 1 발사 
	if (INPUT->GetKeyUp('D')) 
	{
		pressD = true;
		if (skillFire) 
		{
			int halfHeight = rect.top + (rect.bottom - rect.top) / 2;
			BULLETMANAGER->BulletSetting(imgSkillBulletKey, rect.right, halfHeight, false, false);
		}
	}
}