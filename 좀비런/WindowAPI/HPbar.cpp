#include "stdafx.h"
#include "HPbar.h"

HRESULT HPbar::init(const char* frontImg, const char* backImg, const char* bonusFront, const char* bonusBack)
{
	//_hpBarRc = RectMake(50, 30, 700, 50);
	//IMAGEMANAGER->addImage("ü�¹�", "ü�¹�.bmp", 750, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("ü�¹�1", "ü�¹�(��).bmp", 750, 80, true, RGB(255, 0, 255));

	//ü�¹� �̹��� �ʱ�ȭ
	_progressBarFront = IMAGEMANAGER->findImage(frontImg);
	_progressBarBack = IMAGEMANAGER->findImage(backImg);

	_bonusbarFront = IMAGEMANAGER->findImage(bonusFront);
	_bonusbarBack = IMAGEMANAGER->findImage(bonusBack);


	//ü�¹� ��ġ �ʱ�ȭ
	_x = _progressBarBack->getX();
	_y = _progressBarBack->getY();



	//ü�¹� ����, ���α��� �ʱ�ȭ
	_width = _progressBarBack->getWidth();
	_height = _progressBarBack->getHeight();

	//ü�¹� ��Ʈ �ʱ�ȭ
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
	//ü�¹� ��Ʈ ������Ʈ
	_rcProgress = RectMake(_x, _y, _width, _height);

	_rcBonus = RectMake(_bX, _bY, _bWidth, _bHeight);
}

void HPbar::render()
{
	
	//������ �Ǵ� ������ ���ؼ� ������ �Ǵϱ� ������� ���� ��Ų��
	_progressBarBack->render(getMemDC(), _x, _y);
	//�տ� �������� ü�¹� �̹���
	_progressBarFront->render(getMemDC(), _x, _y, 0, 0, _width, _height);



	_bonusbarFront->render(getMemDC(), _bX, _bY);

	_bonusbarBack->render(getMemDC(), _bX, _bY, 0, 0, _bWidth, _bHeight);


	

}

//ü�¹� ������ �����ϱ�
void HPbar::setGauge(float maxHp, float currentHp)
{
	_width = (currentHp / maxHp) * _progressBarBack->getWidth();
}

void HPbar::setBonusGauge(float maxBonus, float currentBonus)
{
	_bWidth = (currentBonus / maxBonus) * _bonusbarFront->getWidth();

}

