#include "Player.h"

void Player::Init()
{
	m_playerTex.Load("Texture/player.png");
	m_pos = { 0,-200 };
	m_move = { 0,0 };
	m_scale = { 1,1 };
	movePow = 2;
}

void Player::Update()
{
	int enemyMove = 3;
	int bulletMove = 15;

	charaBase->Update();

	if (aliveFlg == true) {
		//é©ã@à⁄ìÆèàóùÅEâ¡ë¨ÅEå∏ë¨
		//â¡ë¨
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			m_move += {movePow, movePow};
		}
		//å∏ë¨
		if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
		{
			m_move -= {-movePow, -movePow};
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

void Player::Draw2D()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	if (aliveFlg == true)
	{
		//SHADER.m_spriteShader.DrawTex(m_playerTex, Math::Rectangle(0, 0, 64, 64));
		KdShaderManager::GetInstance().m_spriteShader.DrawTex(&m_playerTex, m_pos.x, m_pos.y);

	}
}

void Player::Release()
{
}