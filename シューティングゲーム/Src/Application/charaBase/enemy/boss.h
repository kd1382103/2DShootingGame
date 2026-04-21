#pragma once

class CharaBase;

class Boss
{
public:
	Boss();
	~Boss() {}

	void Release();

	void Update();

	void Draw2D();

private:
	CharaBase* charaBase;

	//エネミーボスの変数
	float bossSiz;//拡大率
	float bossRadius;//半径
	int bossHP;//HP
	float bossAngle;

};