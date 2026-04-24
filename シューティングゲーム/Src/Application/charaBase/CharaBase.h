#pragma once
class CharaBase
{
public:
	CharaBase() { Init(); };
	~CharaBase() { Release(); }

	void Update();

	void Draw2D();

	void Init();

protected:
	void Release();

	KdTexture *m_playerTex;
	KdTexture *m_enemyTex;
	KdTexture *m_bossTex;

	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix m_mat;

	bool playerFlg;
	bool enemyFlg;
	bool bossFlg;
};