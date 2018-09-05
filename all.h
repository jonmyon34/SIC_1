#include"DxLib.h"

#include<stdlib.h>
#include<time.h>


#define WINDOW_X 1280
#define WINDOW_Y 736

#define PL_SIZE_X 32
#define PL_SIZE_Y 32
#define PL_SPEED_MAX 9
#define PL_SPEED_INC 0.2


#define PL_UP_FIRST_X WINDOW_X/2
#define PL_UP_FIRST_Y WINDOW_Y/3

#define PL_DOWN_FIRST_X WINDOW_X/2
#define PL_DOWN_FIRST_Y WINDOW_Y/3*2

#define PL_LEFT_FIRST_X WINDOW_X/4
#define PL_LEFT_FIRST_Y WINDOW_Y/2

#define PL_RIGHT_FIRST_X WINDOW_X/4*3
#define PL_RIGHT_FIRST_Y WINDOW_Y/2
//å¸Ç´Ç…ëŒÇµÇƒÇÃèâä˙à íu

#define FLASHCNT_MAX 70

#include"player.h"
#include"block.h"
