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
	camera* _camera;	 //카메라 클래스 선언
	player* _player;	 //플레이어 클래스 선언
	player* _player2;	 //플레이어 클래스 선언
	monster _monster[UNIT_MAX]; //몬스터1 클래스 선
	monster2 _monster2[MON2_MAX]; //몬스터2 클래스 선언
	monster3 _monster3[MON3_MAX];	//몬스터3 클래스 선언
	boss _boss[BOSS_MAX];	//보스 클래스 선언

	image* _blood;

	
	int frameCount;
	int _loopX, _loopY;	//루프시길 속도
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
	//이곳에 함수 선언
	

	mainGame() {}
	~mainGame() {}
};