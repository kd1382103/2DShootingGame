#pragma once

#include "../CharaBase.h"

class Player :public CharaBase
{
public:
	Player();
	~Player() { Release(); }


	void Update();

	void Draw2D();

private:
	CharaBase* charaBase;

	void Release();

	//プレイヤー(自機)の変数
	int playerSpeedBoostFlg = false;	//移動速度加速フラグ
	int playerSpeedDecreaseFlg = false;	//移動速度減少フラグ

};
