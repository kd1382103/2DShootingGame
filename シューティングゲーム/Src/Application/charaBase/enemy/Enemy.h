#pragma once

class CharaBase;

class Enemy
{
public:
	Enemy();
	~Enemy() {}

	void Release();

	void Update();

	void Draw2D();

private:
	CharaBase* charaBase;

	//エネミー（敵機）の変数
	static const int enemyNum = 10;//敵の数(書き換え不可)
};