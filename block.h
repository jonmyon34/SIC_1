class block
{
public:
	int pos_x, pos_y, width, height;
	int speed;
	int block_gh;


	bool blockFlg;

	block()
	{
		pos_x = WINDOW_X / 2;
		pos_y = WINDOW_Y;

		width = 64;
		height = 15;
		
		speed = 12;

		block_gh = LoadGraph("block.png");


		blockFlg = false;
	}

	void ReStart()
	{
		pos_x = WINDOW_X / 2;
		pos_y = WINDOW_Y;
	}

	void Move()
	{
		pos_y = pos_y - speed;
	}

	void View()
	{
		DrawExtendGraph(pos_x, pos_y, pos_x + width, pos_y + height, block_gh, true);
	}
};