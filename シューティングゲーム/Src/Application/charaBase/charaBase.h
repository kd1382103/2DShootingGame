#pragma once

class CharaBase
{
public:

	CharaBase();
	~CharaBase() {}

	void Release();

	void Update();

	void Draw2D();

private:
	KdTexture charaTex;
	Math::Matrix charaMat;

	float charaX;
	float charaY;
	float charaFlg;
	float charaAnimeCnt;
	float charaAnimeCntMax;
	float charaFrame;

};