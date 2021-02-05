#include "stdafx.h"
#include "item.h"
#include "player.h"


//아이템 클래스에서 검사하려니깐, 아이템 매니져가 플레이어 정보 받아오고, 아이템 매니져에 아이템클래스의 정보를 준다.
//정보를 한번 주고 싶으면, 아이템 매니져에서 충돌처리. (아이템 헤더 에 겟렉트 만들어서, 아이템 매니져에서 충돌검사)


//생명물약..
HRESULT item::init(string p_itemKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY, player* _p)
{
	_player = _p;
	//영역 
	_itemRc = RectMake(p_posX, p_posY, p_sizeX, p_sizeY);

	//아이템 이미지 초기화
	imgItemKey	 = p_itemKey;
	//아이템 갯수
	
	posX		= p_posX;
	posY		= p_posY;
	sizeX		= p_sizeX;
	sizeY		= p_sizeY;
	speed = 3;
	magneticCount = 0;
	motionCount = 0;
	index = 0;

	isMagnetic = false;
	isSpeedPotion = false;
	isBigPotion = false;
	isMove = false;
	isAppear = true;
	isShowBonusImg = false;
	
	

	setPlayerWithMagnetic = false;
	ItemTimer = 0;
	itemSpeed = 3.0f;


	_currentItemSpeed = itemSpeed;

	

	return S_OK;
}

void item::release()
{
}

void item::update()
{
	itemMove();
}

void item::render(HDC hdc)
{
	//if(isAppear)
	IMAGEMANAGER->findImage(imgItemKey)->render(hdc, _itemRc.left, _itemRc.top);
	//Rectangle(hdc, _itemRc);
}

void item::itemMove()
{
	if(!setPlayerWithMagnetic)
	{
		posX -= ITEMMANAGER->itemSpeedX;
		_itemRc = RectMake(posX, posY, sizeX, sizeY);
	}
	else 
	{
		magneticCount++;
		if (magneticCount>900)
		{
			magneticCount = 0;
			setPlayerWithMagnetic = false;
		}
		 posX +=  cosf(itemFollowPlayer())*ITEMMANAGER->itemSpeedX;
		 posY +=  -sinf(itemFollowPlayer())*ITEMMANAGER->itemSpeedX;

		 //cout << itemFollowPlayer() << endl;


		 _itemRc = RectMake(posX, posY, sizeX, sizeY);
		
	}




}

float item::itemFollowPlayer()
{
	//int l	=	_itemRc.left;
	//int r	=	_itemRc.right;
	//int t	=	_itemRc.top;
	//int b	=	_itemRc.bottom;

	int cX = (_itemRc.left + _itemRc.right) / 2;
	int cY = (_itemRc.top + _itemRc.bottom) / 2;

	//int pL	=	_player->getPlayerRc().left;
	//int pR	=	_player->getPlayerRc().right;
	//int pT	=	_player->getPlayerRc().top;
	//int pB	=	_player->getPlayerRc().bottom;

	int cPx = (_player->getPlayerRc().left + _player->getPlayerRc().right) / 2;
	int cPy = (_player->getPlayerRc().top + _player->getPlayerRc().bottom) / 2;
	
	//return atan2((cY -cPy), (cX-cPx));


	return MY_UTIL::getAngle(cX, cY, cPx, cPy);


}


