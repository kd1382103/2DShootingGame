#include "Player.h"

Player::Player()
{
	m_pos = {0,-200};
	m_move = {0,0};
	m_scale = {1,1};
}

void Player::Draw2D()
{
	charaBase->Draw2D();
}

void Player::Update()
{
	int enemyMove = 3;
	int bulletMove = 15;

	charaBase->Update();

	if (playerFlg == true) {
		//é©ã@à⁄ìÆèàóùÅEâ¡ë¨ÅEå∏ë¨
		//â¡ë¨
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			m_move += {2, 2};
		}
		//å∏ë¨
		if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
		{
			m_move -= {-2, -2};
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_pos.x += m_move.x;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_pos.x -= m_move.x;
		}	
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_pos.y += m_move.y;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_pos.y -= m_move.y;
		}
	}
}

