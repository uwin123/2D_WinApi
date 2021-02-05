#pragma once
#include "Unit.h"
#include "player.h"


#define PI 3.1415926f

class monster :	public Unit
{
private : 

	player* _player;
	
	int fireCount;		//���� �� ������ �Ѿ� ��� �غ� ī��Ʈ 
	int currentFireCount;
	int waitCount;
	int currentWaitCount;
	int stopmakerugalCount;
	bool canFire;
	bool isAimTarget;

	
public : 
	HRESULT init(string p_imgUnitKey, string p_imgBulletKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY,
		int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY, int fireRate, int p_waitTime, player *p_player, bool p_isAimTarget);
	//fireRate == ���� �Ѿ� ����� ��Ÿ�� 
	//p_waitTime == ���� ������ ��Ÿ�� 
	//p_plaayer == �÷��̾� ���ؼ� ����ְԱ� �����ϱ����� 
	
	void update() override;
	void render(HDC hdc) override;

	//���� ���� �Լ�
	void monsterMove();		//���� ������ ��, ���� �ð� ����
	void monsterFire();		//������ �Ѿ˹߻� �Լ� 
	float SetFireToPlayer();	//�÷��̾ ���� �߻�
	
};

