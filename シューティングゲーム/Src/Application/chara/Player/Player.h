#pragma once
#include"Application/chara/charaBase/CharaBase.h"

class Player :public CharaBase
{
public:
	Player() { Init(); }
	~Player() override { Release(); }

	void Init()		override;
	void Update()	override;
	void DrawSprite()	override;

	//=======================================
	//セッター
	//=======================================
	
	//プレイヤーの基本情報

	//void SetPlayer(
	//	Math::Vector2 pos,
	//	Math::Vector2 move,
	//	Math::Vector2 scale) 
	//{
	//	pos = m_pos;
	//	move = m_move;
	//	scale = m_scale;
	//}
	//void SetPlayerAlive(bool flg)
	//{
	//	flg = aliveFlg;
	//}

	//=======================================
	//ゲッター
	//=======================================
	//Math::Vector2 GetPlayer()
	//{
	//	return m_pos;
	//	return m_move;
	//	return m_scale;
	//}

	//bool GetPlayerAlive()
	//{
	//	return aliveFlg;
	//}

private:

	void Release();

	KdTexture m_tex;

	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix m_mat;

	bool aliveFlg;	//生存フラグ
	float movePow;	//移動量（増減）
};
