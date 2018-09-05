#include"all.h"

bool checkHitObject(int acceleration, int object)
{
	if (acceleration == 0 && object == true)
	{
		return true;
	}

	return false;
}

void checkHitEnemy()
{

}

int direction_pl_pos_x(int rad_rand)
{
	switch (rad_rand)
	{
	case 0:
		return PL_UP_FIRST_X;

	case 1:
		return PL_LEFT_FIRST_X;

	case 2:
		return PL_DOWN_FIRST_X;

	case 3:
		return PL_RIGHT_FIRST_X;

	default:
		break;
	}
}

int direction_pl_pos_y(int rad_rand)
{
	switch (rad_rand)
	{
	case 0:
		return PL_UP_FIRST_Y;

	case 1:
		return PL_LEFT_FIRST_Y;

	case 2:
		return PL_DOWN_FIRST_Y;

	case 3:
		return PL_RIGHT_FIRST_Y;

	default:
		break;
	}
}


void invincible()
{

}