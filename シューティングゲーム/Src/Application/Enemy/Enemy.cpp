#include"Enemy.h"

void Enemy::Draw2D()
{
	for (int e = 0;e < enemyNum;e++)
	{
		if (aliveFlg == true)
		{
			SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle(0, 0, 64, 64));
		}
	}

}

void Enemy::Init()
{
	m_tex->Load("Texture/enemy.png");
	m_pos = {};
	m_move = {};
	m_scale = {};
}

void Enemy::Update()
{
	//ç¿ïWçXêV
	m_pos += m_move;

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 1.0f);
	m_mat = m_scaleMat * m_transMat;

}

