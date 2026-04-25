#include"Enemy.h"

Enemy::Enemy()
{
	m_enemyTex->Load("Texture/enemy.png");
	m_pos = {};
	m_move = {};
	m_scale = {};
}

void Enemy::Draw2D()
{
	for (int e = 0;e < enemyNum;e++)
	{
		if (aliveFlg == true)
		{
			SHADER.m_spriteShader.DrawTex(m_enemyTex, Math::Rectangle(0, 0, 64, 64));
		}
	}

}

void Enemy::Update()
{
}

