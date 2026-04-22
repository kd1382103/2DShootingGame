#pragma once
#include"../CharaBase.h"

class Enemy:public CharaBase
{
public:
	Enemy();
	~Enemy() { Release(); }

	void Update();

	void Draw2D();

private:
	CharaBase* charaBase;

	void Release();

	//エネミー（敵機）の変数
	static const int enemyNum = 10;//敵の数(書き換え不可)
};