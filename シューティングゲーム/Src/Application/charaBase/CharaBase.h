#pragma once

class Player;

class Enemy;

class CharaBase
{
public:
	CharaBase() { Init(); }
	~CharaBase() { Release(); }

	virtual void Init();
	virtual void Update();
	virtual void Draw2D();
	virtual void Release();

	void GetPos(Math::Vector2 _pos)
	{
		m_pos = _pos;
	}

protected:


	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix m_mat;

private:

};