#include "GameController.h"

GameController::GameController()
	:m_board{ 20,20 }
{
	//g_Board를 초기화한다. (다운/업 캐스팅 개념 학습 필요)
	//벽을 초기화 한다.
	m_board.setUnit(new Wall{ 0,0 });
	m_board.setUnit(new Wall{ 0,1 });
	m_board.setUnit(new Wall{ 0,2 });
	//...나머지 벽들도 초기화 한다.

	//지렁이를 초기화 한다.
	m_board.setUnit(new Worm{ 5,5 });

	//... 
}
