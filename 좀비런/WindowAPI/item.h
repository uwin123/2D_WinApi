#pragma once
//#include "gameNode.h"

#define PI 3.1415926f



//아이템 구조체
//struct  tagItem
//{
//	image* itemImg;
//	//RECT rc;
//	float x, y;
//	float speed;
//	float angle;
//	float radius;
//	int count;
//	bool isMove;
//	bool isMagnetic;
//	bool isSpeedPotion;
//	bool isBigPotion;
//};

class player;
class item 
{
public :
	string imgItemKey;
	RECT _itemRc;
	

private:
	
private:
	//string _imgItem;			//아이템 이미지 이름
	int _itemMax;				//아이템 최대 갯수
	player*_player;
	
	


public:
	HRESULT init(string p_itemKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY,player* _p);
	void release();
	void update();
	void render(HDC hdc);

	int ItemTimer;
	float itemSpeed;
	int posX, posY;
	int sizeX, sizeY;
	int _currentItemSpeed;

	float speed;
	float angle;

	
	bool isMove;
	bool isMagnetic;
	bool isSpeedPotion;
	bool isBigPotion;
	bool isGetAngle;
	bool isAppear;
	bool isShowBonusImg;

	int motionCount;
	int index;


	int magneticCount;

	bool setPlayerWithMagnetic;
	bool setPlayerWithGiant;

	void itemMove();
	void setCurrentPlayerSpeed(float _speed) { _currentItemSpeed+= _speed; }
	float itemFollowPlayer();
	void getDrinkMagnetic(bool playerMagnetic) { setPlayerWithMagnetic = playerMagnetic; }
	void getDrinkGiant(bool playerGiant) { setPlayerWithGiant = playerGiant; }

	//void setPlayerInfo(player* _p) { _player = _p; }
	
	RECT getRect() { return _itemRc; }
};

