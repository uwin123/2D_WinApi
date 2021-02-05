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
	image* _zombieWalk;		//�ȴ� �������̹��� 6*1
	image* _zombieRun;		//�޸��� �������̹��� 6*1
	image* _zombieJump;		//�����ϴ� �������̹��� 
	image* _zombieSlide;		//�����ϴ� �������̹��� 

	


	//�÷��̾� ���°�
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

	//�÷��̾� ����
	//float _currentHp, _maxHp;
	float _x, _y;
	float _speed;
	float _currentSpeed;

	//ȯ�� ����
	float _gravity;
	float _playerG;			//�÷��̾� �߷� ���ӵ�

	float _gravity2;
	float _playerG2;

	//�ִϸ��̼�
	int _count;				//������ ���� ī��Ʈ(�ӵ� ����)
	int _count2;				//������ ���� ī��Ʈ(�ӵ� ����)
	int _count3;				//������ ���� ī��Ʈ(�ӵ� ����)
	int _index;				//������ �̹��� �ε���
	int _index2;				//������ �̹��� �ε���
	int currentFrameX;
	int currentFrameY;
	int maxFrameX;
	int maxFrameY;

	bool playerGravity;

	float _maxHp, _currentHp;

	//���� ����
	RECT _player;			//�÷��̾� ��Ʈ.
	RECT _player2;			//�Ŵ��÷��̾� ��Ʈ.
	RECT _gameOverBar;		//������ ������ ��Ʈ 



public:
	HRESULT init(string p_imgPlayerKey, int p_posX, int p_posY, int p_sizeX, int p_sizeY,
		int p_hp, int p_speed, int p_maxFrameX, int p_maxFrameY);
	void release();
	void update();
	void render();

	//�÷��̾� + ��ֹ� �浹 ��ȣ���� 
	void setObstacle(obstacle* obstacle) { _obstacle = obstacle; }
	//�÷��̾� + ������ �浹 ��ȣ���� 
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

