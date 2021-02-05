#pragma once
#include "gameNode.h"

class startScene : public gameNode
{
private:
	RECT _rc;
	RECT _starRc;

public:
	HRESULT init();
	void release();
	void update();
	void render();
};

