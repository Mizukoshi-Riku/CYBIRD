//=============================================================================
//
// メイン処理 [main.cpp]
// Author : HAL東京 ゲーム学科 2年 水越 陸
//
//=============================================================================

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include "main.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/

#define					GENKIN_TICKET_FEE (130);	//現金の場合の料金
#define					DENSHI_TICKET_FEE (124);	//電子マネーの場合の料金

/*******************************************************************************
* グローバル変数
*******************************************************************************/

int					denshi_initial = 1000;			//電子マネーの残高

BILL			g_syozikin;							//初めから持っているお金の枚数
BILL			g_kazu;								//支払いで使うお金の枚数

//現金の合計を計算するときに使用
int Precess_Bil(BILL b)
{
	return(10 * b.ten) + (50 * b.fifty) + (100 * b.one_hd) + (500 * b.five_hd)
		+ (1000 * b.one_thd) + (5000 * b.five_thd) + (10000 * b.ten_thd);
}



//お釣りの計算を行う
int Get_Process_Oturi(int ticket_SUM)
{
	return Precess_Bil(g_kazu) - ticket_SUM;
}

//現金の場合の処理
void Process_Real_Money(void)
{
	printf("現金ですね、かしこまりました\n");

	Precess_Bil(g_kazu);								//最初の所持金の合計を計算

	printf("現在の所持枚数\n10円：%d枚　50円：%d枚　100円：%d枚　500円：%d枚　1000円：%d枚　5000円：%d枚　10000円：%d枚\n合計：%d円\n"
		, g_syozikin.ten, g_syozikin.fifty, g_syozikin.one_hd, g_syozikin.five_hd, g_syozikin.one_thd, g_syozikin.five_thd, g_syozikin.ten_thd, Precess_Bil(g_syozikin));

	int kazu;				//切符の枚数
	printf("何枚購入しますか？\n→");
	scanf("%d", &kazu);
	printf("%d枚ですね\nかしこまりました。",kazu);

	int	ticket_SUM;						//購入時の料金
	ticket_SUM = kazu * GENKIN_TICKET_FEE;					//現金の場合の料金と選択された枚数をかけて合計をだす
	printf("\n%d円になります\n", ticket_SUM);

	int bigger = 0;


	printf("どのお金を使おう...（使用する枚数を入力）\n");

	//所持枚数より多かった場合はもう一度
	while (bigger != 1)
	{
		printf("\n10円→");
		scanf("%d", &g_kazu.ten);
		if (g_syozikin.ten >= g_kazu.ten)
		{
			g_syozikin.ten = g_syozikin.ten - g_kazu.ten;
			bigger = 1;
		}
		else
		{
			printf("所持数を超えています");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n50円→");
		scanf("%d", &g_kazu.fifty);
		if (g_syozikin.fifty >= g_kazu.fifty)
		{
			g_syozikin.fifty = g_syozikin.fifty - g_kazu.fifty;
			bigger = 1;
		}
		else
		{
			printf("所持数を超えています\n");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n100円→");
		scanf("%d", &g_kazu.one_hd);
		if (g_syozikin.one_hd >= g_kazu.one_hd)
		{
			g_syozikin.one_hd = g_syozikin.one_hd - g_kazu.one_hd;
			bigger = 1;
		}
		else
		{
			printf("所持数を超えています\n");
			_getch();
		}
	}
	bigger = 0;


	while (bigger != 1)
	{
		printf("\n500円→");
		scanf("%d", &g_kazu.five_hd);
		if (g_syozikin.five_hd >= g_kazu.five_hd)
		{
			g_syozikin.five_hd = g_syozikin.five_hd - g_kazu.five_hd;
			bigger = 1;
		}
		else
		{
			printf("所持数を超えています\n");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n1000円→");
		scanf("%d", &g_kazu.one_thd);
		if (g_syozikin.one_thd >= g_kazu.one_thd)
		{
			g_syozikin.one_thd = g_syozikin.one_thd - g_kazu.one_thd;
			bigger = 1;

		}
		else
		{
			printf("所持数を超えています\n");
			_getch();
		}
	}
	bigger = 0;

	while (bigger != 1)
	{
		printf("\n5000円→");
		scanf("%d", &g_kazu.five_thd);
		if (g_syozikin.five_thd >= g_kazu.five_thd)
		{
			g_syozikin.five_thd = g_syozikin.five_thd - g_kazu.five_thd;
			bigger = 1;
		}
		else
		{
			printf("所持数を超えています\n");
			_getch();
		}
	}
	bigger = 0;


	while (bigger != 1)
	{
		printf("\n10000円→");
		scanf("%d", &g_kazu.ten_thd);
		if (g_syozikin.ten_thd >= g_kazu.ten_thd)
		{
			g_syozikin.ten_thd = g_syozikin.ten_thd - g_kazu.ten_thd;
			bigger = 1;
		}
		else
		{
			printf("所持数を超えています\n");
			_getch();
		}
	}
	bigger = 0;






	//使う分のお金の合計の計算
	Precess_Bil(g_kazu);

	printf("\n%d円分使用", Precess_Bil(g_kazu));
	_getch();
	system("cls");	// 画面クリア


	if (ticket_SUM <= Precess_Bil(g_kazu))
	{


		int oturi = Get_Process_Oturi(ticket_SUM);



		g_syozikin.ten_thd = g_syozikin.ten_thd + (oturi / 10000);
		oturi = oturi % 10000;											//oturiはお釣りを1万から割っていってその値をいれる
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


		printf("現在の所持枚数\n10円：%d枚　50円：%d枚　100円：%d枚　500円：%d枚　1000円：%d枚　5000円：%d枚　10000円：%d枚\n合計：%d円\n"
			, g_syozikin.ten, g_syozikin.fifty, g_syozikin.one_hd, g_syozikin.five_hd, g_syozikin.one_thd, g_syozikin.five_thd, g_syozikin.ten_thd, Precess_Bil(g_syozikin));
		_getch();
	}
	else
	{
		printf("投入金額が不足している為、購入できません。");
		_getch();
		system("cls");// 画面クリア

	}
}

//電子マネーの場合の処理
void Process_Denshi_Money(void)
{
	int kazu;			//切符の枚数
	printf("電子マネーですね、かしこまりました\n現在の所持金%d円\n何枚購入しますか？\n→", denshi_initial);
	scanf("%d", &kazu);
	system("cls");// 画面クリア
	int	ticket_SUM;						//購入時の料金
	ticket_SUM = kazu * DENSHI_TICKET_FEE;					//電子マネーの場合の料金と選択された枚数をかけて合計をだす
	if (ticket_SUM <= denshi_initial)
	{
		printf("%d枚ですね\nかしこまりました\n%d円になります\n", kazu, ticket_SUM);

		denshi_initial = denshi_initial - ticket_SUM;
		_getch();
		system("cls");// 画面クリア

	}
	else
	{
		printf("残金が不足している為、購入できません。");
		_getch();
		system("cls");// 画面クリア

	}
}



int main(void)
{



	printf("CYBIRD プログラミング課題\n");
	printf("HAL東京 ゲーム学科2年 水越 陸\n");
	printf("press any Key\n");
	_getch();
	system("cls");	// 画面クリア



	int com = 0;							//切符を買うか買わないか

	while (com != 2)
	{
		printf("券売機へようこそ\n");
		printf("切符を購入しますか？\n１．はい　２．いいえ→");
		scanf("%d", &com);
		if (com == 2)				//購入しないなら抜ける
		{
			break;
		}
		system("cls");// 画面クリア

		int	money;							//現金か電子マネーか	
		printf("現金か電子マネーか選択してください\n");
		printf("料金：現金:130円　電子マネー:124円\n\n１．現金　２．電子マネー →");
		scanf("%d", &money);
		system("cls");// 画面クリア
		switch (money)
		{
		case(1):			//現金だった場合
			Process_Real_Money();
			break;
		case(2):			//電子マネーだった場合
			Process_Denshi_Money();
			break;
		}

		printf("\n残り所持金\n現金:%d円　電子マネー:%d円\n", Precess_Bil(g_syozikin), denshi_initial);
		_getch();

		printf("まだ購入しますか？\n１．はい　２．いいえ→");
		scanf("%d", &com);
		system("cls");// 画面クリア

	}
	system("cls");// 画面クリア
	printf("またのお越しをお待ちしております。");
	// キー入力待ち(おまじない)
	rewind(stdin);
	_getch();

	return 0;
}
