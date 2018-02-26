#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "windows.h"
#include "time.h"


// GLOBAL CONSTANTS
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13
#define ESC 27

static int Xpos;
static int Ypos;
static int Xfood;
static int Yfood;
static int direction = 80; //down
static int hits = 0;
static int wait = 500;
static int lives = 3;
static int speed = 1;

static char HEADER[4][25] =
{ "___________ __________",
"|    A SNAKE GAME    |",
"|********************|",
"___________ __________",
};
static char FOOTER[25] =
{
	"----------------------"
};
static char MAP[15][25] =
{
	"|                    |",
	"|                    |" ,
	"|                    |" ,
	"|                    |" ,
	"|                    |" ,
	"|                    |" ,
	"|                    |" ,
	"|                    |" ,
	"|                    |" ,
	"|                    |" ,
};


void InitMap()
{

	Xpos = (rand() % 20) + 1;
	Ypos = (rand() % 8) + 1;

	Xfood = (rand() % 20) + 1;
	Yfood = (rand() % 8) + 1;

	MAP[Yfood][Xfood] = 'o';

}
int DrawMap()
{
	switch (direction)
	{
	case UP:
		if (Ypos <= 0)
			return 0;
		else
			Ypos--;
		break;
	case DOWN:
		if (Ypos >= 9)
			return 0;
		else
			Ypos++;
		break;
	case LEFT:
		if (Xpos <= 1)
			return 0;
		else
			Xpos--;
		break;
	case RIGHT:
		if (Xpos >= 20)
			return 0;
		else
			Xpos++;
		break;
	}

	MAP[Ypos][Xpos] = '*';

	for (int i = 0; i < 4; i++)
		puts(HEADER[i]);

	for (int i = 0; i < 10; i++)
		puts(MAP[i]);

	puts(FOOTER);

	printf("\n\nScore: %d", hits);
	printf("\nLives: %d", lives);
	printf("\nSpeed: %d", speed);





	Sleep(wait);
	MAP[Ypos][Xpos] = ' ';

}

void GetInput()
{
	/**/
	if (_kbhit())
	{
		direction = _getch();
	}
}

void EatFood()
{
	if (Ypos == Yfood && Xpos == Xfood)
	{
		hits++;

		Xfood = (rand() % 20) + 1;
		Yfood = (rand() % 8) + 1;

		MAP[Yfood][Xfood] = 'o';
		if (hits == 5)
		{
			wait = 200;
			speed++;
		}
		else if (hits == 7)
		{
			wait = 100;
			speed++;
		}
		else if (hits == 9)
		{
			wait = 0;
			speed++;
		}

	}

}


void Die(int a)
{
	if (!a)
	{
		lives--;

		Xpos = (rand() % 20) + 1;
		Ypos = (rand() % 8) + 1;
	}
}



int main()
{
	

	srand(time(0));

	InitMap();

	while (lives)
	{
		Die(DrawMap());
		GetInput();
		EatFood();
		system("cls");

	}


}