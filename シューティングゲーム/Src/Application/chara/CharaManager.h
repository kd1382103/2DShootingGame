#pragma once

class CharaBase;

class CharaManager
{
public:

	void PreUpdate();
	void Update();
	void DrawSprite();

private:
	void Init();
	void Release();

	std::shared_ptr<CharaBase>m_charaBase;
private:
	
	//シングルトンパターン

	CharaManager() { Init(); }
	~CharaManager() { Release(); }

public:
	static CharaManager& Instance()
	{
		static CharaManager	instance;
		return instance;
	}
};