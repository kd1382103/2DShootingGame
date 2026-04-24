#include"Enemy.h"

Enemy::Enemy()
{
	m_pos = {};
	m_move = {};
	m_scale = {};
}

void Enemy::Draw2D()
{
	charaBase->Draw2D();
}

void Enemy::Update()
{
	charaBase->Update();
}

