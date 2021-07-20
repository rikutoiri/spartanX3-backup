#pragma once

#define PI 3.1415926535897932384626433832795f

extern struct ENEMY mEnemy;
struct ENEMY {
	bool dashLeft;			//���Ɉړ����锻��
	bool dashRight;			//�E�Ɉړ����锻��
	int x,y;				//x,y���W
	float move;				//�ړ��W��
	int oldchar;			//�O�̉摜������
	int xcount,ycount;		//�������Əc�����̃J�E���g��
	int ix,iy,result;		//�Y���p�ϐ�

	bool gekiha;				//�e�X�g�G�̌��j����
	int y_temp, y_prev;		//�e�X�g�G�̌��j��������
	int angle;
};

//�G�l�~�[
static int ene[8];

extern void Enemy_Initialize();
extern void Enemy_Finalize();
extern void Enemy_Update();
extern void Enemy_Draw();