#pragma once
#include"../CharaBase.h"

class Enemy:public CharaBase
{
public:
	Enemy();
	~Enemy() { Release(); }

	void Update();

	void Draw2D();

	void SetTex(KdTexture* tex) { m_enemyTex = tex; }

	void SetNum(int enemyNum)
	{
		enemyNum = m_enemyNum;
	}

	//void GetNum() {};

private:
	CharaBase* charaBase;


	//エネミー（敵機）の変数
	static const int m_enemyNum = 10;//敵の数(書き換え不可)
};