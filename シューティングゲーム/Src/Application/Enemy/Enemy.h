#pragma once
#include"Application/charaBase/CharaBase.h"

class Enemy :public CharaBase
{
public:
	Enemy();
	~Enemy() { }

	void Update()override;

	void Draw2D()override;

	void SetTex(KdTexture* tex) { m_enemyTex = tex; }

	/*void SetNum(int enemyNum)
	{
		enemyNum = ;
	}

	void GetNum()
	{
		;
	}*/

	void SetPos(float posX, float posY) { m_pos.x, m_pos.y = posX, posY; };
	
private:
	std::shared_ptr<CharaBase>charaBase;

	KdTexture* m_enemyTex;

	bool aliveFlg;
	static const int enemyNum = 10;

};