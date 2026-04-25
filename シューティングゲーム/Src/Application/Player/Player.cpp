#include "Player.h"

void Player::Init()
{
	m_tex.Load("Texture/player.png");
	m_pos = { 0,-200 };
	m_move = { 0,0 };
	m_scale = { 1,1 };
	movePow = 2;
	aliveFlg == true;
}

void Player::Update()
{
	int enemyMove = 3;
	int bulletMove = 15;

	charaBase->Update();

	if (aliveFlg == true) {
		//自機移動処理・加速・減速
		//加速
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			m_move += {movePow, movePow};
		}
		//減速
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

	//座標更新
	m_pos += m_move;

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 1.0f);
	m_mat = m_scaleMat * m_transMat;

}

void Player::Draw2D()
{
	if (aliveFlg == true)
	{
		//SHADER.m_spriteShader.DrawTex(m_playerTex, Math::Rectangle(0, 0, 64, 64));
		KdShaderManager::GetInstance().m_spriteShader.DrawTex(&m_tex, m_pos.x, m_pos.y);
	}
}

void Player::Release()
{
}