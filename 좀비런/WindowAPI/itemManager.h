#pragma once
#include "singletonBase.h"
#include "item.h"


struct tagPointBox
{
	RECT _pointBoxRc;
};


class player;
class item;
class itemManager : public singletonBase<itemManager>
{


private :
	//아이템 구조체를 담을 벡터 선언
	vector<item*> _vItem;
	vector<item*> _vMotionItem;


	vector<item*> _vBonusImg;

	player* _p;

	int itemSpeedCount;
	tagPointBox _pointBox[4];
	image *_angleNum[10];
	
public:

	HRESULT init(int p_maxFrameX, int p_maxFrameY);
	void release();
	void update();
	void render(HDC hdc);

	void itemSetting(string p_itemKey, int p_posX, int p_posY, int sizeX, int sizeY);

	int _pointPlus;
	void playerInfo(player* p) { _p = p; }
	//player* getplayer() { return _p; }

	//벡터의 아이템 가져오기 
	vector<item*> getvItem() { return _vItem; }
	

	int ItemTimer;
	int itemSpeed;
	bool itemMove;
	bool itemEat;
	int motionCount;
	int giantCount;
	int currentFrameX;
	int currentFrameY;
	int maxFrameX;
	int maxFrameY;
	bool _isDrinkGiant;

	//int itemUnusable;

	float itemSpeedX;
	
	void collision();
	
	void jellyMotionEffect();

	bool itemEatMotion() { return itemEat; }
	void removeItem(int index);
	void motionRemonve(int index);
	//void itemMove();


};

