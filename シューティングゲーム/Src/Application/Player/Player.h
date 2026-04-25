#pragma once

#include"Application/charaBase/CharaBase.h"
class Player :public CharaBase
{
public:
	Player();
	~Player() {}

	void Update()override;

	void Draw2D()override;

	void Init()override;
	void Release()override;

private:
	KdTexture m_playerTex;

	std::shared_ptr<CharaBase>charaBase;


	bool aliveFlg;
	float movePow;

	//プレイヤー(自機)の変数
	//int playerSpeedBoostFlg = false;	//移動速度加速フラグ
	//int playerSpeedDecreaseFlg = false;	//移動速度減少フラグ

};
