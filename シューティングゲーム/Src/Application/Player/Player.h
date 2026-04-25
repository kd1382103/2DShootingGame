#pragma once

#include"Application/charaBase/CharaBase.h"
class Player :public CharaBase
{
public:
	Player() { Init(); }
	~Player() {}

	void Update()override;
	void Draw2D()override;
	void Init()override;
	void Release()override;

	void SetAlive(bool flg) 
	{
		flg = aliveFlg;
	}

	bool GetAlive()
	{
		return aliveFlg;
	}

private:

	KdTexture m_tex;

	std::shared_ptr<CharaBase>charaBase;

	bool aliveFlg;	//生存フラグ
	float movePow;	//移動量（増減）

	//プレイヤー(自機)の変数
	//int playerSpeedBoostFlg = false;	//移動速度加速フラグ
	//int playerSpeedDecreaseFlg = false;	//移動速度減少フラグ

};
