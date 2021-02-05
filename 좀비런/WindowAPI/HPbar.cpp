#include "stdafx.h"
#include "HPbar.h"

HRESULT HPbar::init(const char* frontImg, const char* backImg, const char* bonusFront, const char* bonusBack)
{
	//_hpBarRc = RectMake(50, 30, 700, 50);
	//IMAGEMANAGER->addImage("체력바", "체력바.bmp", 750, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("체력바1", "체력바(뒤).bmp", 750, 80, true, RGB(255, 0, 255));

	//체력바 이미지 초기화
	_progressBarFront = IMAGEMANAGER->findImage(frontImg);
	_progressBarBack = IMAGEMANAGER->findImage(backImg);

	_bonusbarFront = IMAGEMANAGER->findImage(bonusFront);
	_bonusbarBack = IMAGEMANAGER->findImage(bonusBack);


	//체력바 위치 초기화
	_x = _progressBarBack->getX();
	_y = _progressBarBack->getY();



	//체력바 가로, 세로길이 초기화
	_width = _progressBarBack->getWidth();
	_height = _progressBarBack->getHeight();

	//체력바 렉트 초기화
	_rcProgress = RectMake(_x, _y, _width, _height);

	_bX = _bonusbarFront->getX()+900;
	_bY = _bonusbarFront->getY()+20;


	_bWidth = _bonusbarFront->getWidth();
	_bHeight = _bonusbarFront->getHeight();

	_rcBonus = RectMake(_bX, _bY, _bWidth, _bHeight);

	return S_OK;
}

void HPbar::release()
{
}

void HPbar::update()
{
	//체력바 렉트 업데이트
	_rcProgress = RectMake(_x, _y, _width, _height);

	_rcBonus = RectMake(_bX, _bY, _bWidth, _bHeight);
}

void HPbar::render()
{
	
	//렌더링 되는 순서에 의해서 렌더가 되니까 피통부터 렌더 시킨다
	_progressBarBack->render(getMemDC(), _x, _y);
	//앞에 보여지는 체력바 이미지
	_progressBarFront->render(getMemDC(), _x, _y, 0, 0, _width, _height);



	_bonusbarFront->render(getMemDC(), _bX, _bY);

	_bonusbarBack->render(getMemDC(), _bX, _bY, 0, 0, _bWidth, _bHeight);


	

}

//체력바 게이지 세팅하기
void HPbar::setGauge(float maxHp, float currentHp)
{
	_width = (currentHp / maxHp) * _progressBarBack->getWidth();
}

void HPbar::setBonusGauge(float maxBonus, float currentBonus)
{
	_bWidth = (currentBonus / maxBonus) * _bonusbarFront->getWidth();

}

