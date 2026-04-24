#include "main.h"
#include "Scene.h"
#include"charaBase/CharaBase.h"


//↓一秒間に６０回のペースで繰り返し実行される（６０FPS）
void Scene::Draw2D()
{
	//先に書いたものから描画される

	//背景(1)
	SHADER.m_spriteShader.SetMatrix(backMat1);
	SHADER.m_spriteShader.DrawTex(&backgroundTex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);
	//背景(2)
	SHADER.m_spriteShader.SetMatrix(backMat2);
	SHADER.m_spriteShader.DrawTex(&backgroundTex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);

	//爆発の表示
	for(int ex=0;ex<expNum;ex++){
		if (expFlg [ex] == true) {
			SHADER.m_spriteShader.SetMatrix(expMat[ex]);
			SHADER.m_spriteShader.DrawTex(&expTex, Math::Rectangle{ (int)expAnimCnt[ex] * 64,0,64,64 }, 1.0f);
		}
	}
	//弾の表示
	for (int bu = 0;bu < bulletNum;bu++) {
		if (bulletFlg[bu] == true) {
			SHADER.m_spriteShader.SetMatrix(bulletMat[bu]);
			SHADER.m_spriteShader.DrawTex(&bulletTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
	}

	//boss
	if (bossFlg == true) {
		SHADER.m_spriteShader.SetMatrix(bossMat);
		SHADER.m_spriteShader.DrawTex(&bossTex, Math::Rectangle{ (int)bossAnimeCnt * 224,0,224,240 }, 1.0f);
	}

	//m_charaBase->Draw2D();
	
	//この下にDrawStringを書く----------------------------------------------------------------------------------

	//①文字列格納用の配列作成
	char text[200];

	//②textの中に" "内の文字列を格納する
	sprintf_s(text, sizeof(text), "Score:%d", score);

	//③text配列の中身を表示
	SHADER.m_spriteShader.DrawString(-640, 360, text, Math::Vector4(1, 1, 0, 1));//文字を表示させる

	//ゲームオーバー
	if (playerFlg == false) {
		SHADER.m_spriteShader.DrawString(0, 0, "YOU DEAD", Math::Vector4(1, 0, 0, 1));
	}
	if (backX < -screenEdgeX )
	{
		backX = 0;
	}
	

}
//↓一秒間に６０回のペースで繰り返し実行される（６０FPS）
void Scene::Update()
{
	int enemyMove = 3;
	int bulletMove = 15;

	////両端判定
	//if (playerX > screenEdgeX / 2 - charaRadius) {
	//	playerX = screenEdgeX / 2 - charaRadius;
	//}
	//if (playerX < -screenEdgeX / 2 - charaRadius) {
	//	playerX = -screenEdgeX / 2 - charaRadius;
	//}
	//弾発射(スペースキー）
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (shotWait == 0) {
			for (int bu = 0;bu < bulletNum;bu++) {
				if (bulletFlg[bu] == false) {
					bulletFlg[bu] = true;
					/*bulletX[bu] = playerX;
					bulletY[bu] = playerY;*/
					shotWait = 10;
					break;
				}
			}
		}
	}
	//自機のアニメーション
	playerAnimeCnt += playerFrame;
	if (playerAnimeCnt >= playerAnimeCntMax) {
		playerAnimeCnt = 0;
	}
	//bossのアニメーション
	bossAnimeCnt += bossFrame;
	if (bossAnimeCnt >= bossAnimeCntMax) {
		bossAnimeCnt = 0;
	}

	//敵
	for (int e = 0;e < enemyNum;e++) {
		if (enemyFlg[e] == 1) {
			enemyX[e] -= enemyMove;
			if (enemyX[e] <= -screenEdgeX / 2 - charaRadius) {
				enemyX[e] = screenEdgeX / 2 - charaRadius;
			}


			if (playerFlg == 1) {
				//自機との当たり判定
				//float a = enemyX[e] - playerX;//底辺
				//float b = enemyY[e] - playerY;//高さ
				//float c = sqrt(a * a + b * b);//斜辺（sqrt→ルート）

				//if (c < charaRadius + charaRadius) {//衝突していたら(斜辺＜半径+半径)
					//enemyFlg[e] = false;//敵を倒す
					//playerFlg = false;
					//Explosion(playerX,playerY);
				//}
			}
		}

	}
	//弾発射後の処理
	for (int bu = 0;bu < bulletNum;bu++) {
		if (bulletFlg[bu] == true)
		{
			bulletX[bu] += bulletMove;
			//弾が画面から出たら未発射状態に戻す
			if (bulletX[bu] > screenEdgeX + bulletRadius) {
				bulletFlg[bu] = false;
			}

			//弾との当たり判定

			for (int e = 0;e < enemyNum;e++) {
				if (enemyFlg[e] == true) {
					float a = enemyX[e] - bulletX[bu];//底辺
					float b = enemyY[e] - bulletY[bu];//高さ
					float c = sqrt(a * a + b * b);//斜辺（sqrt→ルート）
					if (c < 32 + 8) {//衝突していたら(斜辺＜半径+半径)
						enemyFlg[e] = false;//敵を倒す
						bulletFlg[bu] = false;//弾を消す
						score += 100;
						Explosion(enemyX[e], enemyY[e]);
					}
				}
			}

			//ボスと弾の当たり判定
			if (bossFlg == true) {
				float a = bossX - bulletX[bu];//底辺
				float b = bossY  - bulletY[bu];//高さ
				float c = sqrt(a * a + b * b);//斜辺（sqrt→ルート）
				if (c < bossRadius + bulletRadius) {//衝突していたら(斜辺＜半径+半径)
					bossHP -= 1;
					bulletFlg[bu] = false;//弾を消す
					Explosion(bulletX[bu], bulletY[bu]);
				}
			}

		}
	}
	//確率で敵復活
	if (rand() % 100 + 1 <= 90) {
		for (int e = 0;e < enemyNum;e++) {
			if (enemyFlg[e] == false) {
				enemyFlg[e] = true;
				enemyX[e] = 640 + 32;
				enemyY[e] = rand() % (720 + 1 - 64) - (360 - 32);
				break;
			}
		}
	}
	//弾の発射待機時間
	shotWait--;
	if (shotWait <= 0) {
		shotWait = 0;
	}
	//リセット
	RESET();

	//背景スクロール
	backX -= 3;
	if (backX < -1280) {
		backX = 0;
	}

	//ボス
	if (score >= 50 && bossHP > 0) {
		bossFlg = 1;
	}
	if (bossFlg == true) {
		bossX -= 2;
		if (bossX <= 320) {
			bossX = 320;
		}
		////毎フレーム1度ずつ回転
		//bossAngle += 1;
		//// ３６０度以上になったら－３６０にする
		//if (bossAngle >= 360) {
		//	bossAngle -= 360;
		//}
		//ボスのHPチェック
		if (bossHP <= 0) {
			bossFlg = 0;
			Explosion(bossX, bossY);
			score += 5000;
		}
	}
	//↓Updateの最後に行列作成↓↓
	//自機
	//m_player =Math::Matrix::CreateTranslation(playerX, playerY, 0);
	//敵機
	for (int e = 0;e < enemyNum;e++) {
		enemyMat[e] = Math::Matrix::CreateTranslation(enemyX[e], enemyY[e], 0);
	}
	//弾
	for (int bu = 0;bu < bulletNum;bu++) {
		bulletMat[bu] = Math::Matrix::CreateTranslation(bulletX[bu], bulletY[bu], 0);
	}
	//背景
	backMat1 = Math::Matrix::CreateTranslation(backX, 0, 0);
	backMat2 = Math::Matrix::CreateTranslation(backX + 1280, 0, 0);

	//敵が倒されたら爆発する
	for (int ex = 0;ex < expNum;ex++) {

		expMat[ex] = Math::Matrix::CreateTranslation(expX[ex], expY[ex], 0);

		//アニメーション
		if (expFlg[ex] == true) {
			expAnimCnt[ex] += 0.1f;//アニメーションを次の駒に進める
		}
		//終了チェック
		if (expAnimCnt[ex] > 7) {
			expFlg[ex] = 0;
		}
	};
	//boss
	Math::Matrix trans = Math::Matrix::CreateTranslation(bossX, bossY, 0);//移動行列
	Math::Matrix scale=Math::Matrix::CreateScale(bossSiz, bossSiz, 0);//拡縮行列
	                                                           //↓ラジアン単位に変換
	//Math::Matrix rotate= Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(bossAngle));//回転行列
	//bossMat = scale * rotate * trans;//拡縮　*　回転　*　移動	
	bossMat = scale * trans;//拡縮　*　回転　*　移動	
}

//ゲーム開始時、最初の1フレームのみ実行
void Scene::Init()
{
	//乱数の初期化(※必ずInitに一度だけ書く)
	srand(time(0));
	// 画像の読み込み処理
	backgroundTex.Load("Texture/back.png");
	bossTex.Load("Texture/sozai/bossEnemy.png");
	bulletTex.Load("Texture/bullet.png");
	expTex.Load("Texture/explosion.png");
	//hitPointTex.Load("Texture/sozai/hitPoint.png");

	//自機の初期化処理
	/*playerX = 0;
	playerY = -200;*/
	playerFlg = 1;
	playerAnimeCnt=0;

	//敵の初期化処理
	for (int e = 0;e < enemyNum;e++) {
		enemyX[e] = 640 + 32;
		enemyY[e] = rand() % (720 + 1 - 64) - (360 - 32);
		enemyFlg[e] = 1;
	}

	//弾の初期値
	for (int bu = 0;bu < bulletNum;bu++) {
		bulletX[bu] = 0;
		bulletY[bu] = 0;
		bulletFlg[bu] = false;
	}
	shotWait = 0;
	score = 0;

	//爆発の初期値
	for (int ex = 0;ex < expNum;ex++) {
		expFlg[ex] = 0;
		expX[ex];
		expY[ex];
		expAnimCnt[ex];
	}
	//boss
	bossX = 640+32;
	bossY = 0;
	bossFlg = 0;
	bossSiz = 1.5f;
	bossRadius = 112* bossSiz;
	bossHP = 10;
	//bossAngle = 45;
}

//↓最後の1フレームで実行される
void Scene::Release()
{
	// 画像の解放処理
	//charaTex.Release();
	backgroundTex.Release();
	//enemyTex.Release();
	bossTex.Release();
	bulletTex.Release();
	expTex.Release();
	//hitPointTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
//爆発
void Scene::Explosion(float x, float y)
{
	for (int ex = 0;ex < expNum;ex++) {
		if (expFlg[ex] == false) {//[未発生]状態の爆発があるか
			expFlg[ex] = true;
			expX[ex] = x;
			expY[ex] = y;
			expAnimCnt[ex] = 0;
			//爆発は一つだけ発生させる
			break;
		}
	}
}

void Scene::RESET()
{
	//リセット
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			for (int e = 0;e < enemyNum;e++) {
				enemyFlg[e] = 1;
				enemyX[e] = rand() % (1280 + 1 - 64) - (640 - 32);
				enemyY[e] = 360 + 32;
			}
			playerFlg = 1;
			/*playerX = 0;
			playerY = -200;*/
			score = 0;
		}
}
