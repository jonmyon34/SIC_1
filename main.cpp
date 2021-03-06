#include"all.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	player *pl = new player();
	block *bl = new block();

	bool spaceFlg = false;
	int testback;
	double rad = 0;
	int rad_rand;
	testback = LoadGraph("SIC_1_back_test1.png");


	SetFontSize(128);
	int color = GetColor(0, 155, 250);



	srand((unsigned)time(NULL));


	while (ProcessMessage() != -1)
	{
		DrawRotaGraph(WINDOW_X / 2, WINDOW_Y / 2, 1.0, rad, testback, true, false);


		//printfDx("%d", pl->acceleration);

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			delete pl;

			exit(true);

		}


		if (CheckHitKey(KEY_INPUT_SPACE) && spaceFlg == false)
		{
			//初期位置調整
			//pl->directionMode++;
			//rad_rand = rand() % 4;
			//rad = (DX_PI / 2)* rad_rand;
			//pl->pos_x = direction_pl_pos_x(rad_rand);
			//pl->pos_y = direction_pl_pos_y(rad_rand);


			//ブロック
			bl->blockFlg = true;


			spaceFlg = true;
		}

		//縦の状況の当たり判定
		if (pl->pos_y + PL_WIDTH > bl->pos_y && bl->pos_y + BLOCK_HEIGHT > pl->pos_y && !pl->invincibleFlg)
		{
			pl->hitFlg = checkHitBlock(pl->pos_x, bl->pos_x);
			bl->blockExistMode--;
		}

		if (pl->hitFlg&&pl->pos_y < bl->pos_y)
		{
			pl->invincibleFlg = true;
		}
		else if (!pl->damageFlg && pl->invincibleFlg)
		{
			pl->invincibleFlg = false;
		}

		//ブロックフラグ管理
		if (bl->blockFlg)
		{
			bl->Move();
			bl->ExistCheck();
			bl->View();

			if (bl->pos_y < BLOCK_OUT_POS_Y)
			{
				bl->blockFlg = false;
				bl->GetPos();
			}
		}





		if (!CheckHitKey(KEY_INPUT_SPACE))
		{
			spaceFlg = false;
		}



		pl->All();

		ScreenFlip();
		ClearDrawScreen();
	}


	delete pl;


	DxLib_End();

	return 0;
}