#include "Player.h"

Player::Player()
{
	charaBase->Init();
}

void Player::Draw2D()
{
	charaBase->Draw2D();
}

void Player::Update()
{
	charaBase->Update();
}

void Player::Release()
{
}