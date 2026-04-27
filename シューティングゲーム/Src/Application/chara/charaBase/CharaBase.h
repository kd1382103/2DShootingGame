#pragma once

class CharaBase
{
public:
	CharaBase() {}
	virtual ~CharaBase() { Release(); }

	virtual void Init();
	virtual void Update();
	virtual void DrawSprite();

protected:

	virtual void Release();

	//‰æ–Ê‹´
	Math::Vector2 screenEdge = { 1280,720 };
	//ƒLƒƒƒ‰”¼Œa
	float charaRadius = 32;

private:


};