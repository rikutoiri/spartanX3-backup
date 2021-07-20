#pragma once

#define PI 3.1415926535897932384626433832795f

extern struct ENEMY mEnemy;
struct ENEMY {
	bool dashLeft;			//左に移動する判定
	bool dashRight;			//右に移動する判定
	int x,y;				//x,y座標
	float move;				//移動係数
	int oldchar;			//前の画像を入れる
	int xcount,ycount;		//横方向と縦方向のカウント数
	int ix,iy,result;		//添字用変数

	bool gekiha;				//テスト敵の撃破判定
	int y_temp, y_prev;		//テスト敵の撃破少し浮く
	int angle;
};

//エネミー
static int ene[8];

extern void Enemy_Initialize();
extern void Enemy_Finalize();
extern void Enemy_Update();
extern void Enemy_Draw();