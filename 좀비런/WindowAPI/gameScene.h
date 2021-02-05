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
	player* _player;		//�÷��̾� Ŭ���� 
	obstacle* _obstacle;	//��ֹ� �� ���� Ŭ����
	item* _item;			//������ Ŭ���� 
	camera* _camera;

	image* _gameOverImg;


	HPbar* _hpBar;
	float _currentHp, _maxHp;		//�÷��̾� ����ü��, �ִ�ü��

	tagPointBox _pointBox[4];
	

public:
	int itemCount;
	int itemCount1;
	int itemCount2;
	int itemCount3;
	int itemCount4;

	//���ʽ�
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

	//������
	void hitDamage();

	void setCurrentHp(float _hp) { _currentHp += _hp; }

};

