#include "stdafx.h"
#include "itemManager.h"
#include "player.h"
#include "camera.h"


HRESULT itemManager::init(int p_maxFrameX, int p_maxFrameY)
{
	ItemTimer = 0;
	itemSpeed = -3; 
	itemSpeedX = 8;
	itemSpeedCount = 0;
	motionCount = 0;
	giantCount = 0;
	_pointPlus = 0;

	itemEat = false;
	_isDrinkGiant = false;

	currentFrameX = 0;
	currentFrameY = 0;
	maxFrameX = p_maxFrameX;
	maxFrameY = p_maxFrameY;

	item* _i = new item;
	_i->imgItemKey = "비";
	_i->isShowBonusImg = false;

	_vBonusImg.push_back(_i);

	_i = new item;
	_i->imgItemKey = "오";
	_i->isShowBonusImg = false;

	_vBonusImg.push_back(_i);

	_i = new item;
	_i->imgItemKey = "엔";
	_i->isShowBonusImg = false;

	_vBonusImg.push_back(_i);

	_i = new item;
	_i->imgItemKey = "유";
	_i->isShowBonusImg = false;

	_vBonusImg.push_back(_i);

	_i = new item;
	_i->imgItemKey = "에스";
	_i->isShowBonusImg = false;

	_vBonusImg.push_back(_i);

	



	for (int i = 0; i < 10; i++)
	{
		_angleNum[i] = new image;
	}

	IMAGEMANAGER->addImage("0", "0.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("1", "1.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("2", "2.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("3", "3.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("4", "4.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("5", "5.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("6", "6.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("7", "7.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("8", "8.bmp", 40, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("9", "9.bmp", 40, 50, true, RGB(255, 0, 255));

	
	IMAGEMANAGER->addFrameImage("젤리모션", "젤리모션.bmp", 320, 80,4,1, true, RGB(255, 0, 255));

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	if (itemSpeedX == 15)
	{
		itemSpeedCount++;
		if (itemSpeedCount > 40)
		{
			itemSpeedCount = 0;
			itemSpeedX = 8;
		}
	}
	
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->update();
	}
	collision();
	jellyMotionEffect();
	if (_isDrinkGiant)
	{
		giantCount++;
		if (giantCount > 100)
		{
			giantCount = 0;
			_isDrinkGiant = false;
			_p->setDrinkGiant(true);
			//_p->setPlayerRc(_p->getPlayerRc);
			_p->setPlayerRc(RectMake((_p->getPlayer2Rc().left+ _p->getPlayer2Rc().right)/2,
				(_p->getPlayer2Rc().top + _p->getPlayer2Rc().bottom) / 2-50, 171, 237));
		}
	}
}

void itemManager::render(HDC hdc)
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		_vItem[i]->render(hdc);
	}

	for (int i = 0; i < _vMotionItem.size(); i++)
	{
		IMAGEMANAGER->frameRender("젤리모션", hdc, _vMotionItem[i]->getRect().left, _vMotionItem[i]->getRect().top);
	}
		

	int i = 0;
	int score = _pointPlus;
	while (score!=NULL)				//스코어가 NULL값이 아닐때까지 돌아라~
	{
		switch (score%10)			//스코어를 10으로 나눈 나머지 : 1의자리가 무엇인가.?
		{
		case 0:
			IMAGEMANAGER->findImage("0")->render(hdc, 1200 - i * 50, 150);
			break;
		case 1:
			IMAGEMANAGER->findImage("1")->render(hdc, 1200 - i * 50, 150);
			break;
		case 2:
			IMAGEMANAGER->findImage("2")->render(hdc, 1200 - i * 50, 150);
			break;
		case 3:
			IMAGEMANAGER->findImage("3")->render(hdc, 1200 - i * 50, 150);
			break;
		case 4:
			IMAGEMANAGER->findImage("4")->render(hdc, 1200 - i * 50, 150);
			break;
		case 5:
			IMAGEMANAGER->findImage("5")->render(hdc, 1200 - i * 50, 150);
			break;
		case 6:
			IMAGEMANAGER->findImage("6")->render(hdc, 1200 - i * 50, 150);
			break;
		case 7:
			IMAGEMANAGER->findImage("7")->render(hdc, 1200 - i * 50, 150);
			break;
		case 8:
			IMAGEMANAGER->findImage("8")->render(hdc, 1200 - i * 50, 150);
			break;
		case 9:
			IMAGEMANAGER->findImage("9")->render(hdc, 1200 - i * 50, 150);
			break;
		}
		i++;
		score /= 10;			//스코어 10으로 나눈 남은값. 백의 자리였으면 ->십의 자리. 
	}
	//cout << _vBonusImg.size() << endl;
	for (int j = 0; j < _vBonusImg.size()-5; j++)
	{
		if (_vBonusImg[j]->isShowBonusImg == false)continue;
		//if (_vBonusImg[j]->isShowBonusImg == true)
		{
			IMAGEMANAGER->findImage(_vBonusImg[j]->imgItemKey)->render(hdc, 900+j*90, 30);
		}
	}
}

void itemManager::itemSetting(string p_itemKey, int p_posX, int p_posY, int sizeX, int sizeY)
{
	item* _item = new item;	
	_item->init(p_itemKey, p_posX, p_posY, sizeX, sizeY,_p);
	_vItem.push_back(_item);
}

void itemManager::collision()
{
	RECT temp;
	for (int i = 0; i < _vItem.size(); i++)
	{
		itemEat = true;
		if (IntersectRect(&temp, &_p->getPlayerRc(), &_vItem[i]->getRect()))
		{
			_pointPlus += 1000;

			if (_vItem[i]->imgItemKey == "스피드물약")
			{
				ITEMMANAGER->itemSpeedX = 15;
			}
			
			else if (_vItem[i]->imgItemKey == "생명물약")			
			{
				_p->setCurrentPlayerHp(20);
			}
			
			else if (_vItem[i]->imgItemKey == "자석물약")
			{
				for (int k = 0; k < _vItem.size(); k++)
				{
					_vItem[k]->getDrinkMagnetic(true);
				}
			}
			
			else if (_vItem[i]->imgItemKey == "거대물약")
			{
				_p->setDrinkGiant(false);
				_isDrinkGiant = true;
			}

			else if (_vItem[i]->imgItemKey == "비")
			{
				_pointPlus += 5000;
				for (int k = 0; k < _vBonusImg.size(); k++)
				{
					if (_vBonusImg[k]->imgItemKey == "비")
					{
						_vBonusImg[k]->isShowBonusImg = true;
					}
					
				}
			}
			else if (_vItem[i]->imgItemKey == "오")
			{
				_pointPlus += 5000;
				for (int k = 0; k < _vBonusImg.size(); k++)
				{
					if (_vBonusImg[k]->imgItemKey == "오")
					{
						_vBonusImg[k]->isShowBonusImg = true;
					}

				}
			}
			else if (_vItem[i]->imgItemKey == "엔")
			{
				_pointPlus += 5000;
				for (int k = 0; k < _vBonusImg.size(); k++)
				{
					if (_vBonusImg[k]->imgItemKey == "엔")
					{
						_vBonusImg[k]->isShowBonusImg = true;
					}

				}
			}
			else if (_vItem[i]->imgItemKey == "유")
			{
				_pointPlus += 5000;
				for (int k = 0; k < _vBonusImg.size(); k++)
				{
					if (_vBonusImg[k]->imgItemKey == "유")
					{
						_vBonusImg[k]->isShowBonusImg = true;
					}
				}
			}
			else if (_vItem[i]->imgItemKey == "에스")
			{
				_pointPlus += 5000;
				for (int k = 0; k < _vBonusImg.size(); k++)
				{
					if (_vBonusImg[k]->imgItemKey == "에스")
					{
						_vBonusImg[k]->isShowBonusImg = true;
					}

				}
			}

			_vMotionItem.push_back(_vItem[i]);
			removeItem(i);
			
														//템 구별먼저 하고, 삭제 (삭제 해버리고 나서 템구별하는거는 터져버림!!)
			break;										//하나 삭제 하면 저멀리 나오는 아이템들 충돌하기도 전에 먼저 나서서 검사할필요가없어서....
		}
	}


	for (int i = 0; i < _vItem.size(); i++)
	{
		if (_vItem[i]->getRect().right < 0)
		{
			removeItem(i);
		}
	}
}

void itemManager::jellyMotionEffect()
{
	
	for (int i = 0; i < _vMotionItem.size(); i++)
	{
		_vMotionItem[i]->motionCount++;
		if (_vMotionItem[i]->motionCount > 5)
		{
			_vMotionItem[i]->motionCount = 0;
			_vMotionItem[i]->index++;
			if (_vMotionItem[i]->index > 4)
			{
				motionRemonve(i);
				break;

			}
			IMAGEMANAGER->findImage("젤리모션")->setFrameX(_vMotionItem[i]->index);
		}
	}
}

void itemManager::removeItem(int index)
{
	_vItem.erase(_vItem.begin() + index);
}

void itemManager::motionRemonve(int index)
{
	_vMotionItem.erase(_vMotionItem.begin() + index);
}




