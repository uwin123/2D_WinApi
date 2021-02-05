#pragma once
#include "gameNode.h"
class HPbar : public gameNode
{
	image* _progressBarFront;		//체력바 앞 이미지(렉트변경됨)
	image* _progressBarBack;		//체력바 뒤 이미지(변경안함)

	image* _bonusbarFront;
	image* _bonusbarBack;

	RECT _rcBonus;
	RECT _rcProgress;				//체력바 렉트
	float _x, _y;					//체력바 위치좌표
	float _width;					//체력바 가로길이
	float _height;					//체력바 세로길이

	float _bX, _bY;
	float _bWidth;
	float _bHeight;

private:

public:
	RECT _hpBarRc;


	HRESULT init(const char* frontImg, const char* backImg, const char* bonusFront, const char* bonusBack);
	void release();
	void update();
	void render();


	//체력바 위치 세팅하기
	void setPos(float x, float y) { _x = x; _y = y; }

	void setGauge(float maxHp, float currentHp);


	void setBonusGauge(float maxBonus, float currentBonus);

};

