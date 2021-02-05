#pragma once
#include "gameNode.h"
#include "camera.h"
#include "player.h"
#include"monster.h"
#include"monster2.h"
#include"monster3.h"
#include"boss.h"



#define UNIT_MAX 33
#define MON2_MAX 6
#define MON3_MAX 3
#define BOSS_MAX 1


class mainGame : public gameNode
{
private:
	camera* _camera;	 //ī�޶� Ŭ���� ����
	player* _player;	 //�÷��̾� Ŭ���� ����
	player* _player2;	 //�÷��̾� Ŭ���� ����
	monster _monster[UNIT_MAX]; //����1 Ŭ���� ��
	monster2 _monster2[MON2_MAX]; //����2 Ŭ���� ����
	monster3 _monster3[MON3_MAX];	//����3 Ŭ���� ����
	boss _boss[BOSS_MAX];	//���� Ŭ���� ����

	image* _blood;

	
	int frameCount;
	int _loopX, _loopY;	//�����ñ� �ӵ�
	int _alpha;
	int _alpha2;
	int _alpha3;
	int _count;
	int _count2;
	int _count3;
	bool gameOver = false;
	
public:
	HRESULT init();
	void release();
	void update();
	void render();
	//�̰��� �Լ� ����
	

	mainGame() {}
	~mainGame() {}
};