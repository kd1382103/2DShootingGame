#pragma once
#include"Application/chara/charaBase/CharaBase.h"

class Enemy :public CharaBase
{
public:
	Enemy() { Init(); }
	~Enemy() override { Release(); }

	void Update()		override;
	void DrawSprite()	override;
	void Init()			override;

private:
	void Release()	override;

	KdTexture m_tex;

	static const int enemyNum = 10;

	Math::Vector2	m_pos		[enemyNum];
	Math::Vector2	m_move		[enemyNum];
	Math::Vector2	m_scale		[enemyNum];
	Math::Matrix	m_scaleMat	[enemyNum];
	Math::Matrix	m_transMat	[enemyNum];
	Math::Matrix	m_mat		[enemyNum];

	bool aliveFlg;
	float movePow;

};