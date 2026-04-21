#pragma once

class CharaBase;

class Player
{
public:
	Player();
	~Player() {}

	void Release();

	void Update();

	void Draw2D();

private:
	CharaBase* charaBase;

	//プレイヤー(自機)の変数
	int playerSpeedBoostFlg = false;	//移動速度加速フラグ
	int playerSpeedDecreaseFlg = false;	//移動速度減少フラグ

};