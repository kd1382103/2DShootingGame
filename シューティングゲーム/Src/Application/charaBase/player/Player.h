#pragma once

#include "../CharaBase.h"

class Player :public CharaBase
{
public:
	Player();
	~Player() { Release(); }


	void Update();

	void Draw2D();

	void SetTex(KdTexture* tex) { m_playerTex = tex; }

	void SetPos(float posX,float posY) { m_pos.x, m_pos.y = posX,posY; };

private:
	CharaBase* charaBase;

	//プレイヤー(自機)の変数
	//int playerSpeedBoostFlg = false;	//移動速度加速フラグ
	//int playerSpeedDecreaseFlg = false;	//移動速度減少フラグ

};
