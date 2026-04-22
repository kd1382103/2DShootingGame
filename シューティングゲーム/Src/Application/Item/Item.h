#pragma once

class Item
{
public:
	Item();
	~Item() { Release(); }

	void Update();

	void Draw2D();

private:

	void Release();

};
