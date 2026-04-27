#include"CharaManager.h"
#include "Application/chara/Player/Player.h"
#include "Application/chara/Enemy/Enemy.h"

void CharaManager::PreUpdate()
{
}

void CharaManager::Update()
{
	m_charaBase->Update();
}

void CharaManager::DrawSprite()
{
	m_charaBase->DrawSprite();
}

void CharaManager::Init()
{
	m_charaBase->Init();
}

void CharaManager::Release()
{
}
