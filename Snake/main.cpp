#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
using namespace std;

int napravleniye = 0;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score;
enum edirection { stop = 0, lleft, rright, up, down };
edirection dir;
bool peresek = false;

int tailx[100], taily[100];
int dlinxvosta = 0;

void setup() {
	gameover = false;
	dir = stop;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % 18 + 1;
	fruity = rand() % 18 + 1;
	score = 0;
}

void draw() {
	system("cls");//system("clear");
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (i == 0 || i == 19 || j == 0 || j == 19)
				cout << "#";
			else if (i == y && j == x)
				cout << "0";
			else if (i == fruity && j == fruitx)
				cout << char(2);
			else
			{
				bool print = false;

				for (int k = 0; k < dlinxvosta; k++)
				{

					if (tailx[k] == j && taily[k] == i)
					{
						cout << "o";
						print = true;
					}
				}

				if (print == false)				
					cout << " ";
				
			}
		}
		cout << endl;
	}
	cout << endl; cout << endl; cout << endl;
	cout << "your score:" << score;
}

void input() {
	int keyb_input = 0;
	if (_kbhit())
	{
		keyb_input = _getch();
		if (keyb_input != 224 && keyb_input != 65)
		{
			switch (keyb_input)
			{
			case 'w':dir = up;
				break;
			case 'a':dir = lleft;
				break;
			case 's':dir = down;
				break;
			case 'd':dir = rright;
				break;
			case 'x':gameover = true;
				break;
			}
		}
		else
		{
			switch (_getch()) {

			case 72:
				if (dlinxvosta == 0)
				{
					dir = up;
				}
				else if (taily[0] == y)
				{
					dir = up;
				}
				break;
			case 75:
				if (dlinxvosta == 0)
				{
					dir = lleft;
				}
				else if (tailx[0] == x)
				{
					dir = lleft;
				}
				break;
			case 80:if (dlinxvosta == 0)
			{
				dir = down;
			}
				   else if (taily[0] == y)
			{
				dir = down;
			}
				   break;
			case 77:
				if (dlinxvosta == 0)
				{
					dir = rright;
				}
				else if (tailx[0] == x)
				{
					dir = rright;
				}
				break;

			}
		}
	}

}

void logic() {

	int xvostx = x;//j;
	int xvosty = y;//i;
	int xvostx1;
	int xvosty1;
	for (int i = 0; i < dlinxvosta; i++)
	{
		xvostx1 = tailx[i];
		xvosty1 = taily[i];
		taily[i] = xvosty;
		tailx[i] = xvostx;
		xvostx = xvostx1;
		xvosty = xvosty1;

	}

	switch (dir)
	{
	case lleft:x--;
		break;
	case rright:x++;
		break;
	case up:y--;
		break;
	case down:y++;
		break;
	}
	if (x >= width - 1) { x = 1; }
	else if (x <= 0)
	{
		x = 18;
	}

	if (y >= width - 1)
	{
		y = 1;
	}
	else if (y <= 0) { y = 18; }

	for (int i = 0; i < dlinxvosta; i++)
	{
		if (x == tailx[i] && y == taily[i])
		{
			gameover = true;
		}
	}

	if (x == fruitx && y == fruity)
	{
		fruitx = rand() % 18 + 1;
		fruity = rand() % 18 + 1;
		score += 10;
		dlinxvosta++;
	}
}

int main() {

	srand(time(NULL));
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
		Sleep(10);
		if (gameover)
		{
			cout << endl << "game over";
		}
	}

}