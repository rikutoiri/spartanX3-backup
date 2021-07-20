#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"
#include "Enemy.h"

struct ENEMY mEnemy;

static int mImageEnemy;

void Enemy_Initialize() {

	//mImageEnemy = LoadDivGraph("images/enemy1.png", 8, 2, 4, 70, 95, ene,TRUE);	//�摜�̃��[�h
	LoadDivGraph("images/enemy1clear.png", 8, 2, 4, 70, 95, ene);

	mEnemy.dashLeft = true;			//���Ɉړ����锻��
	mEnemy.dashRight = true;			//�E�Ɉړ����锻��
	mEnemy.x = 800;
	mEnemy.y = 395;				//x,y���W
	mEnemy.move = 1.0f;				//�ړ��W��
	mEnemy.oldchar = 0;			//�O�̉摜������
	mEnemy.xcount = 0;
	mEnemy.ycount = 0;		//�������Əc�����̃J�E���g��
	mEnemy.ix = 0;
	mEnemy.iy = 0;
	mEnemy.result = 0;		//�Y���p�ϐ�

	mEnemy.gekiha = false; 
	mEnemy.y_temp;
	mEnemy.y_prev;
	mEnemy.angle = 0;

}
void Enemy_Finalize() {
	DeleteGraph(mImageEnemy); //�摜�̉��
}
void Enemy_Update() {



	////�e�X�g
	//if (mEnemy.gekiha == true) {			//�W�����v�t���O��true�ɂȂ�����
	//	mEnemy.y_temp = mEnemy.y;					//temp��360����
	//	mEnemy.y += (mEnemy.y - mEnemy.y_prev) + 1;		//y��(y - y_prev) + 1�𑫂�
	//	mEnemy.y_prev = mEnemy.y_temp;			//prev��temp�i360�j����
	//	if (mEnemy.y == 370)				//y��360�Ȃ�								//360
	//		mEnemy.gekiha = false;			//�t���O��false�ɂ���
	//}
	//if (CheckHitKey(KEY_INPUT_Z) == 1 && mEnemy.gekiha == false) {
	//	mEnemy.gekiha = true;			//�W�����v�t���O��true�ɂ���
	//	mEnemy.y_prev = mEnemy.y;				//prev��360����
	//	mEnemy.y = mEnemy.y - 15;				//y��340����

	//	if (mEnemy.gekiha == true) {	//�t���O��true�Ȃ�
	//		mEnemy.ix = 1;			//[1]�̉摜��\��(�W�����v�̉摜)
	//		mEnemy.result = mEnemy.ix;		//
	//	}
	//}
	
	//�e�X�g
	if (mEnemy.gekiha == true) {			//���j�t���O��true�ɂȂ�����

		mEnemy.angle = 1;	//�G���X����

		mEnemy.y_prev = mEnemy.y;				//prev��360����
		mEnemy.y_temp = mEnemy.y;					//temp��360����
		mEnemy.y = mEnemy.y + 15;				//y��340����

		mEnemy.y +=/* (mEnemy.y - mEnemy.y_prev) + */1;		//y��(y - y_prev) + 1�𑫂�
		mEnemy.y_prev = mEnemy.y_temp;			//prev��temp�i360�j����


		if (mEnemy.y == 370)				//y��360�Ȃ�								//360
			mEnemy.gekiha = false;			//�t���O��false�ɂ���

	}

	//if (mEnemy.gekiha == true) {			//�W�����v�t���O��true�ɂȂ�����

	//	mEnemy.y_prev = mEnemy.y;				//prev��360����
	//	mEnemy.y = mEnemy.y - 15;				//y��340����

	//	mEnemy.y_temp = mEnemy.y;					//temp��360����
	//	mEnemy.y += (mEnemy.y - mEnemy.y_prev) + 1;		//y��(y - y_prev) + 1�𑫂�
	//	mEnemy.y_prev = mEnemy.y_temp;			//prev��temp�i360�j����

	//	if (mEnemy.y == 370)				//y��360�Ȃ�								//360
	//		mEnemy.gekiha = false;			//�t���O��false�ɂ���

	//	if (mEnemy.gekiha == true) {	//�t���O��true�Ȃ�
	//		mEnemy.ix = 1;			//[1]�̉摜��\��(�W�����v�̉摜)
	//		mEnemy.result = mEnemy.ix;		//
	//	}
	//}






	if (mEnemy.x >= 765) {//�G�l�~�[�̈ʒu�����[�Ȃ�
		mEnemy.dashLeft = true;//dashLeft��true�ɂ���
		mEnemy.dashRight = false;//dashRight��false�ɂ���
	}
	else if (mEnemy.x <= 35) {//�G�l�~�[�̈ʒu�����[�Ȃ�
		mEnemy.dashRight = true;//dashRight��true�ɂ���
		mEnemy.dashLeft = false;//dashLeft��false�ɂ���
	}

	if (mEnemy.dashLeft == true) {//dashLeft��true�Ȃ�
		mEnemy.x -= (int)2 * mEnemy.move;//���Ɉړ�����
	}
	if (mEnemy.dashRight == true) {//dashRight��true�Ȃ�
		mEnemy.x += (int)2 * mEnemy.move;//�E�Ɉړ�����
	}

	//��ʈړ�����
	if (mEnemy.x + (70 / 2) > 800)
		mEnemy.x = 800 - (70 / 2);
	if (mEnemy.x < (70 / 2))
		mEnemy.x = (70 / 2);
	//if (enemyx < (49 / 2))
	//	enemyx = (49 / 2);

	if (mEnemy.dashLeft == true) {			//�ړ������ۂɃ��[�V����������
		if (mEnemy.xcount > 0)
			mEnemy.xcount = 0;
		--mEnemy.xcount;

	}
	if (mEnemy.dashRight == true) {		//�ړ������ۂɃ��[�V����������
		if (mEnemy.xcount < 0)
			mEnemy.xcount = 0;
		++mEnemy.xcount;

	}

	//
	//ix = abs(xcount) % 30 / 10;	//�摜3���p���p��
	//iy = abs(ycount) % 30 / 10;
	mEnemy.ix = abs(mEnemy.xcount) % 20 / 10;		//�摜2���p���p��
	mEnemy.iy = abs(mEnemy.ycount) % 20 / 10;

	//
	if (mEnemy.xcount > 0) {
		mEnemy.ix += 0;
		mEnemy.result = mEnemy.ix;
		mEnemy.oldchar = mEnemy.ix;
		if (mEnemy.x >= 190 && mEnemy.x <= 400) {//�G�l�~�[�����痈��x��190�ɓ���ƈЊd���[�V�����ɂ���
			mEnemy.ix += 4;	//�Њd�摜
			mEnemy.result = mEnemy.ix;
			mEnemy.oldchar = mEnemy.ix;
		}
	}
	else if (mEnemy.xcount < 0) {
		mEnemy.ix += 2;
		mEnemy.result = mEnemy.ix;
		mEnemy.oldchar = mEnemy.ix;
		if (mEnemy.x >= 400 && mEnemy.x <= 610) {//�G�l�~�[�E���痈��x��610�ɓ���ƈЊd���[�V�����ɂ���
			mEnemy.ix += 4;	//�Њd�摜
			mEnemy.result = mEnemy.ix;
			mEnemy.oldchar = mEnemy.ix;
		}
	}
	
	//DrawGraph(mEnemy.x - (70 / 2), mEnemy.y - (95 / 2),ene[mEnemy.result], TRUE);

	DrawRotaGraph(mEnemy.x, mEnemy.y,1.2,mEnemy.angle, ene[mEnemy.result], TRUE);

	//������ĂȂ���΃J�E���g���[���ɂ���
	if (mEnemy.dashLeft != true && mEnemy.dashRight != true) {
		mEnemy.xcount = 0;
	}

}
void Enemy_Draw() {
}