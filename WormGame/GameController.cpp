#include "GameController.h"

GameController::GameController()
	:m_board{ 20,20 }
{
	//g_Board�� �ʱ�ȭ�Ѵ�. (�ٿ�/�� ĳ���� ���� �н� �ʿ�)
	//���� �ʱ�ȭ �Ѵ�.
	m_board.setUnit(new Wall{ 0,0 });
	m_board.setUnit(new Wall{ 0,1 });
	m_board.setUnit(new Wall{ 0,2 });
	//...������ ���鵵 �ʱ�ȭ �Ѵ�.

	//�����̸� �ʱ�ȭ �Ѵ�.
	m_board.setUnit(new Worm{ 5,5 });

	//... 
}
