#pragma once
#include "gameNode.h"

class soundTestScene : public gameNode
{
public:
	bool stopMusic;
	
	HRESULT init();
	void release();
	void update();
	void render();
};

