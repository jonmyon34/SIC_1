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
	testback = LoadGraph("clear_1.png");

	srand((unsigned)time(NULL));


	while (ProcessMessage() != -1)
	{
		DrawRotaGraph(WINDOW_X / 2, WINDOW_Y / 2, 1.0, rad, testback, true, false);

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

		if (bl->blockFlg)
		{
			bl->Move();
			bl->View();

			if (bl->pos_y < -60)
			{
				bl->blockFlg = false;
				bl->ReStart();
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