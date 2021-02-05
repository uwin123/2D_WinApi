#pragma once
#include "gameNode.h"

struct FLOORRC
{
	RECT _rc;
	int num;					//1���̸� ������,. 2���̸� �ٴ�~ 




};
class obstacle : public gameNode
{

private:
	int speedX;
	
	vector < FLOORRC*> _vFloor;			//�ٴ� and ��ħ�� 


	




public:
	//�� �ٴ�. 
	RECT gameFloor;
	RECT gameProp;
	//RECT _gameOverBar;


	HRESULT init(int p_posX, int p_posY,int p_sizeX,int p_sizeY);
	void release();
	void update();
	void render();
	int posX, posY;
	int sizeX, sizeY;
	int jumpFloorCount;

	bool _isHole;
	bool _isProp;

	bool _makingFloor;


	//RECT getFloorRect() { return gameFloor; }
	//RECT getPropRect() { return gameProp; }

	vector < FLOORRC*> getFloorRect() { return _vFloor; }

	void floorMove();
	void floorDisappear(int index);


	void floorSetting();
};

