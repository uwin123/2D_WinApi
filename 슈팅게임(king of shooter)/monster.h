#pragma once
#include "Unit.h"
#include "player.h"


#define PI 3.1415926f

class monster :	public Unit
{
private : 

	player* _player;
	
	int fireCount;		//몬스터 딱 나오고 총알 쏘는 준비 카운트 
	int currentFireCount;
	int waitCount;
	int currentWaitCount;
	int stopmakerugalCount;
	bool canFire;
	bool isAimTarget;

	
public : 
	HRESULT init(string p_imgUnitKey, string p_imgBulletKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY,
		int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY, int fireRate, int p_waitTime, player *p_player, bool p_isAimTarget);
	//fireRate == 몬스터 총알 재생성 쿨타임 
	//p_waitTime == 몬스터 나오는 쿨타임 
	//p_plaayer == 플레이어 향해서 쏠수있게금 설정하기위해 
	
	void update() override;
	void render(HDC hdc) override;

	//몬스터 관련 함수
	void monsterMove();		//몬스터 움직임 및, 등장 시간 조율
	void monsterFire();		//몬스터의 총알발사 함수 
	float SetFireToPlayer();	//플레이어를 향해 발사
	
};

