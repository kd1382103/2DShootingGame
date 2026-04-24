#pragma once

class CharaBase
{
public:
	CharaBase(){}
	~CharaBase() { Release(); }

	void Update();
	void Draw2D();

	void GetPos(Math::Vector2 _pos)
	{
		m_pos = _pos;
	}

protected:

	void Release();

	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix m_mat;

private:

};