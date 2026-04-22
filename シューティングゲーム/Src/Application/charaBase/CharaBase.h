#pragma once
class CharaBase
{
public:
	CharaBase();
	~CharaBase() { Release(); }

	void Update();

	void Draw2D();

	void Init();

private:
	void Release();

	KdTexture m_tex;
	Math::Vector3 m_pos = {};
	bool m_aliveFlg;
};