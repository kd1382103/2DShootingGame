#include "CharaBase.h"

void CharaBase::Draw2D()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_playerTex, Math::Rectangle(0, 0, 64, 64));
	SHADER.m_spriteShader.DrawTex(m_enemyTex, Math::Rectangle(0, 0, 64, 64));
	SHADER.m_spriteShader.DrawTex(m_bossTex, Math::Rectangle(0, 0, 64, 64));
}

void CharaBase::Update()
{
	//ç¿ïWçXêV
	m_pos += m_move;

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 1.0f);
	m_mat = m_scaleMat * m_transMat;
}

void CharaBase::Init()
{
	return;
}

void CharaBase::Release()
{
}