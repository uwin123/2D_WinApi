#pragma once
#include "gameNode.h"
#include "itemManager.h"

#define CAMSIZEX 1400
#define CAMSIZEY 800

class camera : public gameNode
{
private:
	image* _img;		//백그라운드 이미지
	image* _img2;		//백그라운드 이미지
	image* _img3;		//백그라운드 이미지
	image* _img4;		//백그라운드 이미지
	RECT _rcCam;		//카메라 렉트
	vector<item*> _vItem;


public:
	int mapTimer; 
	int mapChangeCounter;
	


	HRESULT init();
	void release();
	void update();
	void render();


	

	camera() {}
	~camera() {}
};

