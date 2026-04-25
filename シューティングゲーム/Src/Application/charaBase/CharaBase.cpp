#include "CharaBase.h"

void CharaBase::Init()
{

}

void CharaBase::Draw2D()
{
}

void CharaBase::Update()
{
	//ç¿ïWçXêV
	m_pos += m_move;

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1.0f);
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 1.0f);
	m_mat = m_scaleMat * m_transMat;
}

void CharaBase::Release()
{
}