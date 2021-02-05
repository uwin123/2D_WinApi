#pragma once
#include "gameNode.h"

class obstacle;

enum STATE
{
	WALK,
	SLIDE,
	JUMP
};
class player : public gameNode
{
private:
	obstacle* _obstacle;
	item* _item;
	//player* _playerHp;
private:
	image* _zombieWalk;		//걷는 프레임이미지 6*1
	image* _zombieRun;		//달리는 프레임이미지 6*1
	image* _zombieJump;		//점프하는 프레임이미지 
	image* _zombieSlide;		//점프하는 프레임이미지 

	


	//플레이어 상태값
	bool _isLeft;
	bool _isMove;
	bool _isRun;
	bool _isGround;
	bool _isJump;
	bool _isSlide;
	bool _isAppear;
	bool _pressA;
	bool _pressL;
	bool _stopWalkingWhileSliding;
	bool _touchGround;
	bool _drinkGiantPotion;
	
	bool _drinkMagneticPotion;
	int _jumpCount;
	STATE _state;

	//플레이어 스탯
	//float _currentHp, _maxHp;
	float _x, _y;
	float _speed;
	float _currentSpeed;

	//환경 변수
	float _gravity;
	float _playerG;			//플레이어 중력 가속도

	float _gravity2;
	float _playerG2;

	//애니메이션
	int _count;				//프레임 돌릴 카운트(속도 조절)
	int _count2;				//프레임 돌릴 카운트(속도 조절)
	int _count3;				//프레임 돌릴 카운트(속도 조절)
	int _index;				//프레임 이미지 인덱스
	int _index2;				//프레임 이미지 인덱스
	int currentFrameX;
	int currentFrameY;
	int maxFrameX;
	int maxFrameY;

	bool playerGravity;

	float _maxHp, _currentHp;

	//영역 설정
	RECT _player;			//플레이어 렉트.
	RECT _player2;			//거대플레이어 렉트.
	RECT _gameOverBar;		//닿으면 뒤지는 렉트 



public:
	HRESULT init(string p_imgPlayerKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY,
		int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY);
	void release();
	void update();
	void render();

	//플레이어 + 장애물 충돌 상호참조 
	void setObstacle(obstacle* obstacle) { _obstacle = obstacle; }
	//플레이어 + 아이템 충돌 상호참조 
	void setItem(item* item) { _item = item; }

	
	void animation2();
	void playerJumpingMove();
	void playerControll();
	void playerCollision();
	void gameOver();
	

	float getPlayerMaxHp() { return _maxHp; }

	float getPlayerCurrentHp() { return _currentHp; }
	void setCurrentPlayerHp(float _hp) { _currentHp += _hp; }

	bool setPlayerWithGiant;
	bool getDrinkGiant() { return setPlayerWithGiant; }

	bool setGameOver;
	bool getGameOver() { return setGameOver; }


	bool _isGameOver;

	//void getPlayerDrinkPotions(bool _drinkGiantPotion) { return _drinkGiantPotion; }

	//void getDrinkMagnetic(bool playerMagnetic) { setPlayerWithMagnetic = playerMagnetic; }
	
	void setDrinkGiant(bool playerGiant) { setPlayerWithGiant = playerGiant; }

	void setPlayerRc(RECT _playerRc) { _player = _playerRc; }
	RECT getPlayer2Rc() { return _player2; }

	RECT getPlayerRc() { return _player; }

};

