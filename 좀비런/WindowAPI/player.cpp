#include "stdafx.h"
#include "player.h"
#include "obstacle.h"

HRESULT player::init(string p_imgPlayerKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY,
	int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY)
{
	_player = RectMakeCenter(p_posX, p_posY, p_sizeX, p_sizeY);

	_player2 = RectMake(10, 290, 250,370);

	_gameOverBar = RectMake(0, 780, WINSIZEX, 20);

	IMAGEMANAGER->addFrameImage("좀비걷기", "좀비걷기.bmp", 1028 , 257 , 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("좀비점프", "좀비점프.bmp", 1200, 300 , 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("좀비슬라", "좀비슬라.bmp", 800, 170, 3, 1, true, RGB(255, 0, 255));



	IMAGEMANAGER->addFrameImage("거대좀비걷기", "좀비걷기.bmp", 1028 * 2.0, 257 * 1.5, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("거대좀비점프", "좀비점프.bmp", 1200 * 2.0, 300 * 1.5, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("거대좀비슬라", "좀비슬라.bmp", 800 * 2.0, 170 * 1.5, 3, 1, true, RGB(255, 0, 255));
	//_zombieWalk = IMAGEMANAGER->findImage("좀비걷기");
	_zombieJump = IMAGEMANAGER->findImage("좀비점프");
	_zombieSlide = IMAGEMANAGER->findImage("좀비슬라");

	//

	

	_count = 0;
	_count2 = 0;
	_count3 = 0;
	_jumpCount = 0;

	_index = 0;
	_index2 = 0;

	_gravity = 0.25f;
	_playerG = 0.0f;

	_gravity2 = 0.25f;
	_playerG = 0.0f;

	currentFrameX = 0;
	currentFrameY = 0;
	maxFrameX = p_maxFrameX;
	maxFrameY = p_maxFrameY;
	_speed = p_speed;
	_isGround = false;
	_isJump = false;
	_isSlide = false;
	_pressA = false;
	_pressL = false;
	_stopWalkingWhileSliding = false;
	_touchGround = false;
	_isAppear = false;
	_drinkGiantPotion = false;						
	_drinkMagneticPotion = false;
	playerGravity = false;
	setGameOver = false;
	//_isGameOver = false;

	_currentHp = _maxHp = 100;
	
	


	return S_OK;
}

void player::release()
{

}

void player::update()
{
	if (!setGameOver)
	{
		if (_player.top > WINSIZEY)
		{
			setGameOver = true;
		}

		if (_currentHp < 0)
		{
			setGameOver = true;
		}
		RECT temp;
		playerGravity = false;
		for (int i = 0; i < _obstacle->getFloorRect().size(); i++)
		{
			if (IntersectRect(&temp, &_player, &_obstacle->getFloorRect()[i]->_rc))
			{
				playerGravity = true;
			}
		}

		playerJumpingMove();
		if (_currentHp > _maxHp)
		{
			_currentHp = _maxHp;
			
		}
		animation2();
		playerControll();
		playerCollision();
		//gameOver();
	}
	
}

void player::render()
{
	//흰색 빈 비트맵 (이것은 렌더에 그냥 두기)
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	if(setPlayerWithGiant)
	{
		//Rectangle(getMemDC(), _player);
		switch (_state)
		{
		case WALK:
			IMAGEMANAGER->frameRender("좀비걷기", getMemDC(), _player.left, _player.top, currentFrameX, currentFrameY);
			break;
		case SLIDE:
			IMAGEMANAGER->frameRender("좀비슬라", getMemDC(), _player.left, _player.top + 80);
			break;
		case JUMP:
			IMAGEMANAGER->frameRender("좀비점프", getMemDC(), _player.left, _player.top - 40);
			break;
		}
	}
	
	else 
	{
		//Rectangle(getMemDC(), _player2);
		switch (_state)
		{
		case WALK:
			IMAGEMANAGER->frameRender("거대좀비걷기", getMemDC(), _player2.left, _player2.top, currentFrameX, currentFrameY);
			break;
		case SLIDE:
			IMAGEMANAGER->frameRender("거대좀비슬라", getMemDC(), _player2.left, _player2.top + 80);
			break;
		case JUMP:
			IMAGEMANAGER->frameRender("거대좀비점프", getMemDC(), _player2.left, _player2.top - 40);
			break;
		}
	}
	
	//if (setGameOver)
	//{
	//	IMAGEMANAGER->findImage("겜오버");
	//}

	//=============================================================
	//백버퍼의 내용을 화면DC에 그린다 (이것도 렌더에 그냥 두기)
	this->getBackBuffer()->render(getHDC());
}



void player::animation2()
{
	switch (_state)
	{
	case WALK:
	{
		if (++_count > 5)
		{
			_count = 0;
			if (++currentFrameX >= maxFrameX)
				currentFrameX = 0;
		}
	}
	break;

	case SLIDE:
		if (_isSlide)
		{
			_stopWalkingWhileSliding = true;
			_count2++;
			_zombieSlide->setFrameY(0);

			if (_count2 % 10 == 0)
			{
				_index--;
				if (_index < 0)
				{
					_index = 3;
				}
				_zombieSlide->setFrameX(_index);
			}
		}
		break;
	case JUMP:
		if (_isJump)
		{
			_count3++;
			_zombieJump->setFrameY(0);

			if (_count3 % 10 == 0)
			{
				_index2--;
				if (_index2 < 0)
				{
					_index2 = 7;
				}
				_zombieJump->setFrameX(_index2);
			}
		}
		break;
	default:
		break;
	}
}

void player::playerJumpingMove()
{
	if (setPlayerWithGiant)
	{
		if (_isJump && !_isGround || !playerGravity)			//점프하고, 땅에 안붙어있을 때, 
		{
			_playerG += _gravity;
			OffsetRect(&_player, 0, _playerG);
		}
	}
	
	else
	{
		if (_isJump && !_isGround || !playerGravity)			//점프하고, 땅에 안붙어있을 때, 
		{
			_playerG2 += _gravity2;
			OffsetRect(&_player2, 0, _playerG2);
		}
	}
	
}

void player::playerControll()
{
	if (_jumpCount < 1)
	{
		if (INPUT->GetKeyDown('A'))
		{
			_jumpCount++;
			_pressA = true;
			{
				_state = JUMP;
				_isJump = true;
				_playerG = -10.0f;
				_playerG2 = -10.0f;
			}
		}
	}
	
		
	if (INPUT->GetKey('L'))
	{
		_pressL = true;
		{
			_state = SLIDE;
			_isSlide = true;
		}
	}
	if (INPUT->GetKeyUp('L'))
	{
		_isSlide = false;			// 슬라이드가 트루가 되는데, 다시 false로 바꿔주는 애가 없어서 그랫다.... 
		_state = WALK;
	}
}

void player::playerCollision()
{
	RECT temp;
	if (setPlayerWithGiant)
	{
		_isGround = false;
		for (int i = 0; i < _obstacle->getFloorRect().size(); i++)
		{
			if (_obstacle->getFloorRect()[i]->num == 3)
			{
				if (_obstacle->getFloorRect()[i]->_rc.top > _player.bottom - 40)
				{
					if (IntersectRect(&temp, &_player, &_obstacle->getFloorRect()[i]->_rc))
					{
						_jumpCount = 0;
						if (!_isSlide)
						{
							_state = WALK;
						}
						int width = temp.right - temp.left;
						int height = temp.bottom - temp.top;

						if (_player.bottom > _obstacle->getFloorRect()[i]->_rc.top && _player.bottom <= _obstacle->getFloorRect()[i]->_rc.bottom)
						{
							if (_playerG >= 0)
							{
								_isGround = true;
								_isJump = false;
								_playerG = 0.0f;

								if (_obstacle->getFloorRect()[i]->_rc.left < (_player.left + _player.right) / 2 &&
									_obstacle->getFloorRect()[i]->_rc.right >(_player.left + _player.right) / 2)
								{
									OffsetRect(&_player, 0, -height + 1);
								}
							}
						}
						else
						{
							_playerG = 0.0f;
							OffsetRect(&_player, 0, height);
						}
					}
				}
			}
			else
			{
				if (IntersectRect(&temp, &_player, &_obstacle->getFloorRect()[i]->_rc))
				{

					_jumpCount = 0;
					if (!_isSlide)
					{
						_state = WALK;
					}
					int width = temp.right - temp.left;
					int height = temp.bottom - temp.top;

					if (_player.bottom > _obstacle->getFloorRect()[i]->_rc.top && _player.bottom <= _obstacle->getFloorRect()[i]->_rc.bottom)
					{
						if (_playerG >= 0)
						{
							_isGround = true;
							_isJump = false;
							_playerG = 0.0f;


							if (_obstacle->getFloorRect()[i]->_rc.left < (_player.left + _player.right) / 2 &&
								_obstacle->getFloorRect()[i]->_rc.right >(_player.left + _player.right) / 2)
							{
								OffsetRect(&_player, 0, -height + 1);
							}
						}
					}
					else
					{
						_playerG = 0.0f;
						OffsetRect(&_player, 0, height);
					}
				}
			}

		}

	}
	else
	{
		_isGround = false;
		for (int i = 0; i < _obstacle->getFloorRect().size(); i++)
		{
			if (_obstacle->getFloorRect()[i]->num == 3)
			{
				if (_obstacle->getFloorRect()[i]->_rc.top > _player2.bottom - 40)
				{
					if (IntersectRect(&temp, &_player2, &_obstacle->getFloorRect()[i]->_rc))
					{
						_jumpCount = 0;
						if (!_isSlide)
						{
							_state = WALK;
						}
						int width = temp.right - temp.left;
						int height = temp.bottom - temp.top;

						if (_player2.bottom > _obstacle->getFloorRect()[i]->_rc.top && _player2.bottom <= _obstacle->getFloorRect()[i]->_rc.bottom)
						{
							if (_playerG2 >= 0)
							{
								_isGround = true;
								_isJump = false;
								_playerG2 = 0.0f;

								if (_obstacle->getFloorRect()[i]->_rc.left < (_player2.left + _player2.right) / 2 &&
									_obstacle->getFloorRect()[i]->_rc.right >(_player2.left + _player2.right) / 2)
								{
									OffsetRect(&_player2, 0, -height + 1);
								}
							}
						}
						else
						{
							_playerG2 = 0.0f;
							OffsetRect(&_player2, 0, height);
						}
					}
				}
			}
			else
			{
				if (IntersectRect(&temp, &_player2, &_obstacle->getFloorRect()[i]->_rc))
				{

					_jumpCount = 0;
					if (!_isSlide)
					{
						_state = WALK;
					}
					int width = temp.right - temp.left;
					int height = temp.bottom - temp.top;

					if (_player2.bottom > _obstacle->getFloorRect()[i]->_rc.top && _player2.bottom <= _obstacle->getFloorRect()[i]->_rc.bottom)
					{
						if (_playerG2 >= 0)
						{
							_isGround = true;
							_isJump = false;
							_playerG2 = 0.0f;


							if (_obstacle->getFloorRect()[i]->_rc.left < (_player2.left + _player2.right) / 2 &&
								_obstacle->getFloorRect()[i]->_rc.right >(_player2.left + _player2.right) / 2)
							{
								OffsetRect(&_player2, 0, -height + 1);
							}
						}
					}
					else
					{
						_playerG2 = 0.0f;
						OffsetRect(&_player2, 0, height);
					}
				}
			}
		}

	}
}

//void player::gameOver()
//{
//	if (_player.top > WINSIZEY)
//	{
//		
//	}
//}
