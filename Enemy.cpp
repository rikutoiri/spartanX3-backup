#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Enemy.h"

struct ENEMY mEnemy;

static int mImageEnemy;

void Enemy_Initialize() {

	//mImageEnemy = LoadDivGraph("images/enemy1.png", 8, 2, 4, 70, 95, ene,TRUE);	//画像のロード
	LoadDivGraph("images/enemy1clear.png", 8, 2, 4, 70, 95, ene);

	mEnemy.dashLeft = true;			//左に移動する判定
	mEnemy.dashRight = true;			//右に移動する判定
	mEnemy.x = 800;
	mEnemy.y = 395;				//x,y座標
	mEnemy.move = 1.0f;				//移動係数
	mEnemy.oldchar = 0;			//前の画像を入れる
	mEnemy.xcount = 0;
	mEnemy.ycount = 0;		//横方向と縦方向のカウント数
	mEnemy.ix = 0;
	mEnemy.iy = 0;
	mEnemy.result = 0;		//添字用変数

	mEnemy.gekiha = false; 
	mEnemy.y_temp;
	mEnemy.y_prev;
	mEnemy.angle = 0;

}
void Enemy_Finalize() {
	DeleteGraph(mImageEnemy); //画像の解放
}
void Enemy_Update() {



	////テスト
	//if (mEnemy.gekiha == true) {			//ジャンプフラグがtrueになったら
	//	mEnemy.y_temp = mEnemy.y;					//tempに360を代入
	//	mEnemy.y += (mEnemy.y - mEnemy.y_prev) + 1;		//yに(y - y_prev) + 1を足す
	//	mEnemy.y_prev = mEnemy.y_temp;			//prevにtemp（360）を代入
	//	if (mEnemy.y == 370)				//yが360なら								//360
	//		mEnemy.gekiha = false;			//フラグをfalseにする
	//}
	//if (CheckHitKey(KEY_INPUT_Z) == 1 && mEnemy.gekiha == false) {
	//	mEnemy.gekiha = true;			//ジャンプフラグをtrueにする
	//	mEnemy.y_prev = mEnemy.y;				//prevに360を代入
	//	mEnemy.y = mEnemy.y - 15;				//yに340を代入

	//	if (mEnemy.gekiha == true) {	//フラグがtrueなら
	//		mEnemy.ix = 1;			//[1]の画像を表示(ジャンプの画像)
	//		mEnemy.result = mEnemy.ix;		//
	//	}
	//}
	
	//テスト
	if (mEnemy.gekiha == true) {			//撃破フラグがtrueになったら

		mEnemy.angle = 1;	//敵を傾ける

		mEnemy.y_prev = mEnemy.y;				//prevに360を代入
		mEnemy.y_temp = mEnemy.y;					//tempに360を代入
		mEnemy.y = mEnemy.y + 15;				//yに340を代入

		mEnemy.y +=/* (mEnemy.y - mEnemy.y_prev) + */1;		//yに(y - y_prev) + 1を足す
		mEnemy.y_prev = mEnemy.y_temp;			//prevにtemp（360）を代入


		if (mEnemy.y == 370)				//yが360なら								//360
			mEnemy.gekiha = false;			//フラグをfalseにする

	}

	//if (mEnemy.gekiha == true) {			//ジャンプフラグがtrueになったら

	//	mEnemy.y_prev = mEnemy.y;				//prevに360を代入
	//	mEnemy.y = mEnemy.y - 15;				//yに340を代入

	//	mEnemy.y_temp = mEnemy.y;					//tempに360を代入
	//	mEnemy.y += (mEnemy.y - mEnemy.y_prev) + 1;		//yに(y - y_prev) + 1を足す
	//	mEnemy.y_prev = mEnemy.y_temp;			//prevにtemp（360）を代入

	//	if (mEnemy.y == 370)				//yが360なら								//360
	//		mEnemy.gekiha = false;			//フラグをfalseにする

	//	if (mEnemy.gekiha == true) {	//フラグがtrueなら
	//		mEnemy.ix = 1;			//[1]の画像を表示(ジャンプの画像)
	//		mEnemy.result = mEnemy.ix;		//
	//	}
	//}






	if (mEnemy.x >= 765) {//エネミーの位置が左端なら
		mEnemy.dashLeft = true;//dashLeftをtrueにする
		mEnemy.dashRight = false;//dashRightをfalseにする
	}
	else if (mEnemy.x <= 35) {//エネミーの位置が左端なら
		mEnemy.dashRight = true;//dashRightをtrueにする
		mEnemy.dashLeft = false;//dashLeftをfalseにする
	}

	if (mEnemy.dashLeft == true) {//dashLeftがtrueなら
		mEnemy.x -= (int)2 * mEnemy.move;//左に移動する
	}
	if (mEnemy.dashRight == true) {//dashRightがtrueなら
		mEnemy.x += (int)2 * mEnemy.move;//右に移動する
	}

	//画面移動制御
	if (mEnemy.x + (70 / 2) > 800)
		mEnemy.x = 800 - (70 / 2);
	if (mEnemy.x < (70 / 2))
		mEnemy.x = (70 / 2);
	//if (enemyx < (49 / 2))
	//	enemyx = (49 / 2);

	if (mEnemy.dashLeft == true) {			//移動した際にモーションをつける
		if (mEnemy.xcount > 0)
			mEnemy.xcount = 0;
		--mEnemy.xcount;

	}
	if (mEnemy.dashRight == true) {		//移動した際にモーションをつける
		if (mEnemy.xcount < 0)
			mEnemy.xcount = 0;
		++mEnemy.xcount;

	}

	//
	//ix = abs(xcount) % 30 / 10;	//画像3枚パラパラ
	//iy = abs(ycount) % 30 / 10;
	mEnemy.ix = abs(mEnemy.xcount) % 20 / 10;		//画像2枚パラパラ
	mEnemy.iy = abs(mEnemy.ycount) % 20 / 10;

	//
	if (mEnemy.xcount > 0) {
		mEnemy.ix += 0;
		mEnemy.result = mEnemy.ix;
		mEnemy.oldchar = mEnemy.ix;
		if (mEnemy.x >= 190 && mEnemy.x <= 400) {//エネミー左から来てxが190に入ると威嚇モーションにする
			mEnemy.ix += 4;	//威嚇画像
			mEnemy.result = mEnemy.ix;
			mEnemy.oldchar = mEnemy.ix;
		}
	}
	else if (mEnemy.xcount < 0) {
		mEnemy.ix += 2;
		mEnemy.result = mEnemy.ix;
		mEnemy.oldchar = mEnemy.ix;
		if (mEnemy.x >= 400 && mEnemy.x <= 610) {//エネミー右から来てxが610に入ると威嚇モーションにする
			mEnemy.ix += 4;	//威嚇画像
			mEnemy.result = mEnemy.ix;
			mEnemy.oldchar = mEnemy.ix;
		}
	}
	
	//DrawGraph(mEnemy.x - (70 / 2), mEnemy.y - (95 / 2),ene[mEnemy.result], TRUE);

	DrawRotaGraph(mEnemy.x, mEnemy.y,1.2,mEnemy.angle, ene[mEnemy.result], TRUE);

	//押されてなければカウントをゼロにする
	if (mEnemy.dashLeft != true && mEnemy.dashRight != true) {
		mEnemy.xcount = 0;
	}

}
void Enemy_Draw() {
}