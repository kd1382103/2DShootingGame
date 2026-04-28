#include"Enemy.h"
#include"Application/chara/CharaManager.h"

void Enemy::DrawSprite()
{
	Math::Rectangle rc;
	rc = { 0, 0, 64, 64 };
	for (int e = 0;e < enemyNum;e++)
	{
		KdShaderManager::GetInstance().m_spriteShader.DrawTex(&m_tex, rc, 1.0f),m_pos[e];
	}
}

void Enemy::Init()
{
	m_tex.Load("Texture/enemy.png");
	for (int e = 0;e < enemyNum;e++) 
	{
		m_pos[e] = {640 + 32,static_cast<float>(rand() % (720 + 1 - 64) - (360 - 32))};
		//static_cast ・・・縮小変換（キャスト変換）
		m_move[e] = {0,0};
		m_scale[e] = {1,1};
		movePow = 5;
		aliveFlg = true;
	}
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	for (int e = 0;e < enemyNum;e++) 
	{
		if (aliveFlg) 
		{
			m_pos[e].x -= movePow;
			if (m_pos[e].x <= -screenEdge.x / 2 - charaRadius)
			{
				m_pos[e].x = screenEdge.x / 2 - charaRadius;
			}
		}
	}
}

