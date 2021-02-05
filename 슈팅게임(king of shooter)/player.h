#pragma once
#include "Unit.h"

class player : public Unit
{
private : 
	//��� �������� �����̴°�?
	bool _isLeft;		//�����̳�?
	bool _isUp;			//�����ΰ�?
	bool skillfire;
	bool pressD;

public : 
	HRESULT init(string p_imgUnitKey, string p_imgBulletKet, int p_posX, int p_posY, int p_sizeX, int p_sizeY,
				int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY, bool p_skillFire);
	void update() override;
	void render(HDC hdc) override;
	void playerController();
	
	

	player(){}
	~player(){}
};

