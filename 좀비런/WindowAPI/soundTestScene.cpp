#include "stdafx.h"
#include "soundTestScene.h"


HRESULT soundTestScene::init()
{
	//���� �߰�
	
	//BGM�ϰ��
	//SOUNDMANAGER->addSound("����1", "Sound/���.mp3", true, true);
	
	//ȿ�����ϰ��
	SOUNDMANAGER->addSound("����1", "Sound/��Ű���׺��.mp3");
	SOUNDMANAGER->addSound("����2", "Sound/���̾߱���.mp3");

	//"Sound/���̾߱���.mp3"
	//�������ڸ��� �÷����ϱ�
	SOUNDMANAGER->play("����1");

	stopMusic = false;
	return S_OK;
}

void soundTestScene::release()
{
}

void soundTestScene::update()
{
	//ȿ������ �׳� �浹�ɶ� �÷��̸� �ϸ� �ȴ�
	//����� ���� �÷��������� üũ�ؼ� ������ �÷��̸� �ؾ� �Ѵ�
	//�׷��� ������� �����뷡ó�� ���尡 ������ �ȴ�
	if (INPUT->GetKeyDown(VK_LBUTTON)&& !stopMusic)
	{
		if (!stopMusic) 
		{
			if (SOUNDMANAGER->isPlaySound("����1"))		//���࿡ ����1�� ������������ Ŭ�� �ϸ� ���� 1�� ���߰� �Ѵ�. 
			{
				SOUNDMANAGER->stop("����1");
			}
			SOUNDMANAGER->play("����2");
			stopMusic = true;
		}
		else
		{
			stopMusic = true;
		}
	}
}

void soundTestScene::render()
{
	//��ũ����ǿ� �߰��ص� (�ؽ�Ʈ ��� ���ϰ� ����ϱ�)
	textOut(getMemDC(), 10, 10, "�����׽�Ʈ");
}
