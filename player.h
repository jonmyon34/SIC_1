class player
{
public:
	int x, y, pos_x, pos_y, width, height;
	float speed;
	int fallVelocity;
	int acceleration;

	int hp;

	int item;

	bool hitFlg;

	int directionMode;
	bool invincibleFlg;

	int player_gh;
	int flashCnt;

	bool plLiveFlg;

	player()
	{
		x = WINDOW_X / 2;
		y = WINDOW_Y / 3;
		pos_x = WINDOW_X / 2;
		pos_y = WINDOW_Y / 3;
		width = 32;
		height = 32;

		hitFlg = false;
		directionMode = 0;
		invincibleFlg = false;

		speed = 0;

		player_gh = LoadGraph("Ps_pl.png");

		flashCnt = 0;
	}

	void Move()
	{

		switch (directionMode % 2)
		{
		case 0:

			if (CheckHitKey(KEY_INPUT_LEFT))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_x = pos_x - speed;
			}

			if (CheckHitKey(KEY_INPUT_RIGHT))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_x = pos_x + speed;
			}

			if (!CheckHitKey(KEY_INPUT_RIGHT) && !CheckHitKey(KEY_INPUT_LEFT))
			{
				speed = 0;
			}


			break;


		case 1:

			if (CheckHitKey(KEY_INPUT_UP))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_y = pos_y - speed;
			}

			if (CheckHitKey(KEY_INPUT_DOWN))
			{
				if (speed < PL_SPEED_MAX)
				{
					speed += PL_SPEED_INC;
				}

				pos_y = pos_y + speed;
			}

			if (!CheckHitKey(KEY_INPUT_UP) && !CheckHitKey(KEY_INPUT_DOWN))
			{
				speed = 0;
			}


			break;


		default:
			break;
		}

	}

	void View()
	{
		switch (hitFlg)
		{
		case false:
		DrawExtendGraph(pos_x, pos_y, pos_x + width, pos_y + height, player_gh, true);
		break;

		case true:
			if (((flashCnt / 10) % 2)&&flashCnt<FLASHCNT_MAX)
			{
				DrawExtendGraph(pos_x, pos_y, pos_x + width, pos_y + height, player_gh, true);
				flashCnt++;
			}
			else if (flashCnt >= FLASHCNT_MAX)
			{
				hitFlg = false;
				flashCnt = 0;
			}
			else
			{
				flashCnt++;
			}

		}
	}

	void All()
	{
		Move();
		View();
	}



};



int direction_pl_pos_x(int);
int direction_pl_pos_y(int);

