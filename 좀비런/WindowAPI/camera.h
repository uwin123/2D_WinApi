#pragma once
#include "gameNode.h"
#include "itemManager.h"

#define CAMSIZEX 1400
#define CAMSIZEY 800

class camera : public gameNode
{
private:
	image* _img;		//��׶��� �̹���
	image* _img2;		//��׶��� �̹���
	image* _img3;		//��׶��� �̹���
	image* _img4;		//��׶��� �̹���
	RECT _rcCam;		//ī�޶� ��Ʈ
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

