//=============================================================================
//
// ���C������ [main.cpp]
// Author : HAL���� �Q�[���w�� 2�N ���z ��
//
//=============================================================================

/*******************************************************************************
* scanf ��warning�h�~
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* �C���N���[�h�t�@�C��
*******************************************************************************/
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include "main.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/

#define					GENKIN_TICKET_FEE (130);	//�����̏ꍇ�̗���
#define					DENSHI_TICKET_FEE (124);	//�d�q�}�l�[�̏ꍇ�̗���

/*******************************************************************************
* �O���[�o���ϐ�
*******************************************************************************/

int					denshi_initial = 1000;			//�d�q�}�l�[�̎c��

BILL			g_syozikin;							//���߂��玝���Ă��邨���̖���
BILL			g_kazu;								//�x�����Ŏg�������̖���

//�����̍��v���v�Z����Ƃ��Ɏg�p
int Precess_Bil(BILL b)
{
	return(10 * b.ten) + (50 * b.fifty) + (100 * b.one_hd) + (500 * b.five_hd)
		+ (1000 * b.one_thd) + (5000 * b.five_thd) + (10000 * b.ten_thd);
}



//���ނ�̌v�Z���s��
int Get_Process_Oturi(int ticket_SUM)
{
	return Precess_Bil(g_kazu) - ticket_SUM;
}

//�����̏ꍇ�̏���
void Process_Real_Money(void)
{
	printf("�����ł��ˁA�������܂�܂���\n");

	Precess_Bil(g_kazu);								//�ŏ��̏������̍��v���v�Z

	printf("���݂̏�������\n10�~�F%d���@50�~�F%d���@100�~�F%d���@500�~�F%d���@1000�~�F%d���@5000�~�F%d���@10000�~�F%d��\n���v�F%d�~\n"
		, g_syozikin.ten, g_syozikin.fifty, g_syozikin.one_hd, g_syozikin.five_hd, g_syozikin.one_thd, g_syozikin.five_thd, g_syozikin.ten_thd, Precess_Bil(g_syozikin));

	int kazu;				//�ؕ��̖���
	printf("�����w�����܂����H\n��");
	scanf("%d", &kazu);
	printf("%d���ł���\n�������܂�܂����B",kazu);

	int	ticket_SUM;						//�w�����̗���
	ticket_SUM = kazu * GENKIN_TICKET_FEE;					//�����̏ꍇ�̗����ƑI�����ꂽ�����������č��v������
	printf("\n%d�~�ɂȂ�܂�\n", ticket_SUM);

	int bigger = 0;


	printf("�ǂ̂������g����...�i�g�p���閇������́j\n");

	//����������葽�������ꍇ�͂�����x
	while (bigger != 1)
	{
		printf("\n10�~��");
		scanf("%d", &g_kazu.ten);
		if (g_syozikin.ten >= g_kazu.ten)
		{
			g_syozikin.ten = g_syozikin.ten - g_kazu.ten;
			bigger = 1;
		}
		else
		{
			printf("�������𒴂��Ă��܂�");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n50�~��");
		scanf("%d", &g_kazu.fifty);
		if (g_syozikin.fifty >= g_kazu.fifty)
		{
			g_syozikin.fifty = g_syozikin.fifty - g_kazu.fifty;
			bigger = 1;
		}
		else
		{
			printf("�������𒴂��Ă��܂�\n");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n100�~��");
		scanf("%d", &g_kazu.one_hd);
		if (g_syozikin.one_hd >= g_kazu.one_hd)
		{
			g_syozikin.one_hd = g_syozikin.one_hd - g_kazu.one_hd;
			bigger = 1;
		}
		else
		{
			printf("�������𒴂��Ă��܂�\n");
			_getch();
		}
	}
	bigger = 0;


	while (bigger != 1)
	{
		printf("\n500�~��");
		scanf("%d", &g_kazu.five_hd);
		if (g_syozikin.five_hd >= g_kazu.five_hd)
		{
			g_syozikin.five_hd = g_syozikin.five_hd - g_kazu.five_hd;
			bigger = 1;
		}
		else
		{
			printf("�������𒴂��Ă��܂�\n");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n1000�~��");
		scanf("%d", &g_kazu.one_thd);
		if (g_syozikin.one_thd >= g_kazu.one_thd)
		{
			g_syozikin.one_thd = g_syozikin.one_thd - g_kazu.one_thd;
			bigger = 1;

		}
		else
		{
			printf("�������𒴂��Ă��܂�\n");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n5000�~��");
		scanf("%d", &g_kazu.five_thd);
		if (g_syozikin.five_thd >= g_kazu.five_thd)
		{
			g_syozikin.five_thd = g_syozikin.five_thd - g_kazu.five_thd;
			bigger = 1;
		}
		else
		{
			printf("�������𒴂��Ă��܂�\n");
			_getch();
		}
	}
	bigger = 0;


	while (bigger != 1)
	{
		printf("\n10000�~��");
		scanf("%d", &g_kazu.ten_thd);
		if (g_syozikin.ten_thd >= g_kazu.ten_thd)
		{
			g_syozikin.ten_thd = g_syozikin.ten_thd - g_kazu.ten_thd;
			bigger = 1;
		}
		else
		{
			printf("�������𒴂��Ă��܂�\n");
			_getch();
		}
	}
	bigger = 0;






	//�g�����̂����̍��v�̌v�Z
	Precess_Bil(g_kazu);

	printf("\n%d�~���g�p", Precess_Bil(g_kazu));
	_getch();
	system("cls");	// ��ʃN���A


	if (ticket_SUM <= Precess_Bil(g_kazu))
	{


		int oturi = Get_Process_Oturi(ticket_SUM);



		g_syozikin.ten_thd = g_syozikin.ten_thd + (oturi / 10000);
		oturi = oturi % 10000;											//oturi�͂��ނ��1�����犄���Ă����Ă��̒l�������
		g_syozikin.five_thd = g_syozikin.five_thd + (oturi / 5000);
		oturi = oturi % 5000;
		g_syozikin.one_thd = g_syozikin.one_thd + (oturi / 1000);
		oturi = oturi % 1000;
		g_syozikin.five_hd = g_syozikin.five_hd + (oturi / 500);
		oturi = oturi % 500;
		g_syozikin.one_hd = g_syozikin.one_hd + (oturi / 100);
		oturi = oturi % 100;
		g_syozikin.fifty = g_syozikin.fifty + (oturi / 50);
		oturi = oturi % 50;
		g_syozikin.ten = g_syozikin.ten + (oturi / 10);
		oturi = oturi % 10;


		printf("���݂̏�������\n10�~�F%d���@50�~�F%d���@100�~�F%d���@500�~�F%d���@1000�~�F%d���@5000�~�F%d���@10000�~�F%d��\n���v�F%d�~\n"
			, g_syozikin.ten, g_syozikin.fifty, g_syozikin.one_hd, g_syozikin.five_hd, g_syozikin.one_thd, g_syozikin.five_thd, g_syozikin.ten_thd, Precess_Bil(g_syozikin));
		_getch();
	}
	else
	{
		printf("�������z���s�����Ă���ׁA�w���ł��܂���B");
		_getch();
		system("cls");// ��ʃN���A

	}
}

//�d�q�}�l�[�̏ꍇ�̏���
void Process_Denshi_Money(void)
{
	int kazu;			//�ؕ��̖���
	printf("�d�q�}�l�[�ł��ˁA�������܂�܂���\n���݂̏�����%d�~\n�����w�����܂����H\n��", denshi_initial);
	scanf("%d", &kazu);
	system("cls");// ��ʃN���A
	int	ticket_SUM;						//�w�����̗���
	ticket_SUM = kazu * DENSHI_TICKET_FEE;					//�d�q�}�l�[�̏ꍇ�̗����ƑI�����ꂽ�����������č��v������
	if (ticket_SUM <= denshi_initial)
	{
		printf("%d���ł���\n�������܂�܂���\n%d�~�ɂȂ�܂�\n", kazu, ticket_SUM);

		denshi_initial = denshi_initial - ticket_SUM;
		_getch();
		system("cls");// ��ʃN���A

	}
	else
	{
		printf("�c�����s�����Ă���ׁA�w���ł��܂���B");
		_getch();
		system("cls");// ��ʃN���A

	}
}



int main(void)
{



	printf("CYBIRD �v���O���~���O�ۑ�\n");
	printf("HAL���� �Q�[���w��2�N ���z ��\n");
	printf("press any Key\n");
	_getch();
	system("cls");	// ��ʃN���A



	int com = 0;							//�ؕ��𔃂�������Ȃ���

	while (com != 2)
	{
		printf("�����@�ւ悤����\n");
		printf("�ؕ����w�����܂����H\n�P�D�͂��@�Q�D��������");
		scanf("%d", &com);
		if (com == 2)				//�w�����Ȃ��Ȃ甲����
		{
			break;
		}
		system("cls");// ��ʃN���A

		int	money;							//�������d�q�}�l�[��	
		printf("�������d�q�}�l�[���I�����Ă�������\n");
		printf("�����F����:130�~�@�d�q�}�l�[:124�~\n\n�P�D�����@�Q�D�d�q�}�l�[ ��");
		scanf("%d", &money);
		system("cls");// ��ʃN���A
		switch (money)
		{
		case(1):			//�����������ꍇ
			Process_Real_Money();
			break;
		case(2):			//�d�q�}�l�[�������ꍇ
			Process_Denshi_Money();
			break;
		}

		printf("\n�c�菊����\n����:%d�~�@�d�q�}�l�[:%d�~\n", Precess_Bil(g_syozikin), denshi_initial);
		_getch();

		printf("�܂��w�����܂����H\n�P�D�͂��@�Q�D��������");
		scanf("%d", &com);
		system("cls");// ��ʃN���A

	}
	system("cls");// ��ʃN���A
	printf("�܂��̂��z�������҂����Ă���܂��B");
	// �L�[���͑҂�(���܂��Ȃ�)
	rewind(stdin);
	_getch();

	return 0;
}
