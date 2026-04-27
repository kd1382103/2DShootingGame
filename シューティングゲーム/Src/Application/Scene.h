#pragma once

class CharaManager;

class Scene
{

public:

	// 初期設定
	void Init();

	// 更新処理
	void Update();

	// 描画処理
	void DrawSprite();

	//プレイヤーの座標取得
	void GetPlayerPos() { Math::Vector2 m_pos; };

	// GUI処理
	void ImGuiUpdate();
	
	//関数宣言後「ALT+Enter」で関数定義を作成する

	//爆発
	void Explosion(float x, float y);

	//リセット
	void RESET();

	void Release();

private:


	// テクスチャ ・・・ 画像データ
	KdTexture bossTex;

	KdTexture backgroundTex;
	KdTexture bulletTex;
	KdTexture expTex;
	//KdTexture hitPointTex;

	//スコア
	int score;

	//爆発の変数
	static const int expNum = 10;

	Math::Matrix expMat[expNum];
	float expX[expNum];
	float expY[expNum];
	int expFlg[expNum];
	float expAnimCnt[expNum];

	//弾の変数
	static const int bulletNum = 5;
	Math::Matrix bulletMat[bulletNum];//行列...座標・回転・拡縮を管理
	float bulletX[bulletNum];//自機のX座標管理
	float bulletY[bulletNum];
	int bulletFlg[bulletNum];
	int shotWait;//発射待機時間

	//プレイヤー(自機)の変数
	int playerFlg;
	int playerSpeedBoostFlg = false;	//移動速度加速フラグ
	int playerSpeedDecreaseFlg = false;	//移動速度減少フラグ

	float playerAnimeCnt;
	float playerAnimeCntMax = 4;
	float playerFrame = 0.25f;

	//エネミー（敵機）の変数
	static const int enemyNum = 10;//敵の数(書き換え不可)

	Math::Matrix enemyMat[enemyNum];//行列...座標・回転・拡縮を管理
	float enemyX[enemyNum];//敵機のX座標管理
	float enemyY[enemyNum];
	int enemyFlg[enemyNum];//敵の生存（1.生存 0.死亡）

	//エネミーボスの変数
	Math::Matrix bossMat;
	float bossX;
	float bossY;
	int bossFlg;
	float bossSiz;//拡大率
	float bossRadius;//半径
	int bossHP;//HP
	float bossAngle;
	float bossAnimeCnt;
	float bossAnimeCntMax = 15;
	float bossFrame = 0.25f;

	//背景
	Math::Matrix backMat1;
	Math::Matrix backMat2;
	float backX;

	////画面橋
	float screenEdgeX = 1280;//画面端X
	float screenEdgeY = 720;//画面端Y

	////キャラ半径
	float charaRadius = 32;

	//弾半径
	float bulletRadius;

	CharaManager* m_charaManager = nullptr;

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
