#include "stdafx.h"
#include "obstacle.h"


HRESULT obstacle::init(int p_posX, int p_posY, int p_sizeX, int p_sizeY)
{
	posX = p_posX;
	posY = p_posY;
	sizeX = p_sizeX;
	sizeY = p_sizeY;

	_isHole = false;
	_isProp = true;
	_makingFloor = false;

	jumpFloorCount = 500;

	speedX = 5;
	gameFloor = RectMake(posX, posY,WINSIZEX, sizeY);

	gameProp = RectMake(p_posX+300, p_posY-300, 300, p_sizeY-250);

	//0, 650, 700, 200);
	//_gameOverBar = RectMake(posX, posY + 120, WINSIZEX, sizeY);

	FLOORRC* _rc = new FLOORRC;
	_rc->_rc = gameFloor;				//���� ������ ��Ʈ �ֱ�
	_rc->num = 2;						//2�� �ٴ� �ǹ�
	_vFloor.push_back(_rc);

	IMAGEMANAGER->addImage("���ٴ�", "���ٴ�.bmp", 2000, 150);
	IMAGEMANAGER->addImage("��ħ��", "��ħ��.bmp", 300, 50,true,RGB(255,0,255));
	//cout << posX << endl;
	return S_OK;

	

}

void obstacle::release()
{

}

void obstacle::update()
{
	floorMove();

	

	floorSetting();



}

void obstacle::render()
{
	//IMAGEMANAGER->loopRender("���ٴ�", getMemDC(),&gameFloor,speedX,0 );
	//IMAGEMANAGER->findImage("���ٴ�")->setWidth(750);
	for (int i = 0; i < _vFloor.size(); i++)
	{
		switch (_vFloor[i]->num)
		{
		case 2: 
			IMAGEMANAGER->findImage("���ٴ�")->setWidth(_vFloor[i]->_rc.right - _vFloor[i]->_rc.left);
			//Rectangle(getMemDC(), gameFloor);
			IMAGEMANAGER->render("���ٴ�", getMemDC(), _vFloor[i]->_rc.left, _vFloor[i]->_rc.top);

			break;
		case 3:
			IMAGEMANAGER->findImage("��ħ��")->setWidth(_vFloor[i]->_rc.right - _vFloor[i]->_rc.left);
			//Rectangle(getMemDC(), gameProp);
			IMAGEMANAGER->render("��ħ��", getMemDC(), _vFloor[i]->_rc.left, _vFloor[i]->_rc.top);
			break;

		}
		
	}
	

}

void obstacle::floorMove()
{
	
	for (int i = 0; i < _vFloor.size(); i++)
	{
		_vFloor[i]->_rc.left -= speedX;
		_vFloor[i]->_rc.right -= speedX;
	}
	for (int i = 0; i < _vFloor.size(); i++)
	{
		if (_vFloor[i]->_rc.right < 0)
		{
			floorDisappear(i);
			break;							//�ϳ� ����� for�� ���߱�.
		}
	}
}

void obstacle::floorDisappear(int index)
{
	_vFloor.erase(_vFloor.begin() + index);
}

void obstacle::floorSetting()
{
	jumpFloorCount++;

	if (jumpFloorCount > 600)
	{
		jumpFloorCount = 0;
		FLOORRC* _rc = new FLOORRC;
		_rc->_rc = RectMake(WINSIZEX, posY-RANDOM->range(100,300), 300, 50);
		_rc->num = 3;				
		_vFloor.push_back(_rc);
	}
	if(_makingFloor)
	{
		if (_vFloor[_vFloor.size()-1]->_rc.right < WINSIZEX)		//������ �ִ� ��Ʈ�� ������ ��~
		{
			FLOORRC* _rc = new FLOORRC;
			_rc->_rc = RectMake(WINSIZEX+RANDOM->range(400,450), posY, RANDOM->range(1500,2000), sizeY);		//����(WINSIZEX+~~), ����(RANDOM->RANGE)	
			_rc->num = 2;												
			_vFloor.push_back(_rc);
			_makingFloor = false;
		}	
	}
	else
	{
		if (_vFloor[_vFloor.size() - 1]->_rc.right < WINSIZEX)
		{
			_makingFloor = true;
		}
	}



}
