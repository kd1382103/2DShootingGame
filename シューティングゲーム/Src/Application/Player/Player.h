#pragma once

#include"Application/charaBase/CharaBase.h"
class Player :public CharaBase
{
public:
	Player();
	~Player() {}

	void Update();

	void Draw2D();

	void SetTex(KdTexture* tex) { m_playerTex = tex; }

	void SetPos(float posX, float posY) { m_pos.x, m_pos.y = posX, posY; };

private:
	KdTexture *m_playerTex;

	std::shared_ptr<CharaBase>charaBase;


	bool aliveFlg;
	float movePow;

	//プレイヤー(自機)の変数
	//int playerSpeedBoostFlg = false;	//移動速度加速フラグ
	//int playerSpeedDecreaseFlg = false;	//移動速度減少フラグ

};
