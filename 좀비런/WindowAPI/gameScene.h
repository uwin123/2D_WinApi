#pragma once
#include "gameNode.h"
#include "player.h"
#include "obstacle.h"
#include "item.h"
#include "camera.h"
#include "HPbar.h"




class gameScene : public gameNode
{
private:
	player* _player;		//플레이어 클래스 
	obstacle* _obstacle;	//장애물 및 벽들 클래스
	item* _item;			//아이템 클래스 
	camera* _camera;

	image* _gameOverImg;


	HPbar* _hpBar;
	float _currentHp, _maxHp;		//플레이어 현재체력, 최대체력

	tagPointBox _pointBox[4];
	

public:
	int itemCount;
	int itemCount1;
	int itemCount2;
	int itemCount3;
	int itemCount4;

	//보너스
	int bonusCount1;
	int bonusCount2;
	int bonusCount3;
	int bonusCount4;
	int bonusCount5;
	//int itemCount4;

	int floorCount;
	bool itemEat;

	int _pointPlus;

	HRESULT init();
	void release();
	void update();
	void render();

	//피통깍기
	void hitDamage();

	void setCurrentHp(float _hp) { _currentHp += _hp; }

};

