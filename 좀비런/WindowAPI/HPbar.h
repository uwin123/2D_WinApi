#pragma once
#include "gameNode.h"
class HPbar : public gameNode
{
	image* _progressBarFront;		//ü�¹� �� �̹���(��Ʈ�����)
	image* _progressBarBack;		//ü�¹� �� �̹���(�������)

	image* _bonusbarFront;
	image* _bonusbarBack;

	RECT _rcBonus;
	RECT _rcProgress;				//ü�¹� ��Ʈ
	float _x, _y;					//ü�¹� ��ġ��ǥ
	float _width;					//ü�¹� ���α���
	float _height;					//ü�¹� ���α���

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


	//ü�¹� ��ġ �����ϱ�
	void setPos(float x, float y) { _x = x; _y = y; }

	void setGauge(float maxHp, float currentHp);


	void setBonusGauge(float maxBonus, float currentBonus);

};

