#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Figure.h"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27

void Figure::choose() {
	cout << "Choose the character from which the figure will be made: ";
	cin >> character;
	cout << "Choose the size of the figure : Length of the tail and length of the wings(number of characters)\n";

	cout << "Size of the tail = ";
	cin >> tail;
	start_tail = tail;

	cout << "Size of the wing = ";
	cin >> wings;
	start_wings = wings;

	cout << "\nYour figure looks like this: \n\n";
}   

void Figure::build() {
	char space = ' ';

	for (int i = 0; i < y_centre + y; i++)
	{
		cout << endl;
	}

	for (int i = 0; i < wings; i++)
	{
		for (int k = 0; k < x_centre + tail + wings - i-1 + x; k++) //Building first wing of the figure
		{
			cout << space;
		}
		cout << character;
		cout << endl;
	}

	for (int i = 0; i < x_centre + x; i++) //Centering tail of the figure
	{
		cout << space;
	}

	for (int i = 0; i < tail; i++) //Building tail of the figure
	{
		cout << character;
	}
	cout << endl;

	for (int i = 0; i < wings; i++) //Building second wing
	{

		for (int k = 0; k < x_centre + tail + i + x; k++)
		{
			cout << space;
		}
		cout << character;

		if (i < wings-1) //Not writing endline after last character
		{
			cout << endl;
		}
	}
}

void Figure::size_move() {
	int b = 0;

	switch ((b = _getch())){
	case '+':	//Increasizing size of the figure with border paramets
		if (wings != ((height - start_height)+height)/2 - 3 - (height-start_height))
		{
			wings++;
			tail++;
			y_centre--;
		}
		break;
	case '-':	//decreasing size of the figure with border paramets
		if (wings > 1)
		{
			wings--;
			tail--;
			y_centre++;
		}
		break;
	case KEY_UP:	//Moving up	with border paramets
		if (y != -(start_height/2 - wings - 3))
		{
			y--;
		}
		break;
	case KEY_DOWN:	//Moving down with border paramets
		if (y != start_height/2 - wings - 1 + (height-start_height))
		{
			y++;
		}
		break;
	case KEY_RIGHT:	//Moving right with border paramets
		if (x != start_width/2 - tail + (width-start_width) - (tail - start_tail))
		{
			x++;
		}
		break;
	case KEY_LEFT:	//Moving left with border paramets
		if (x != -(start_width/2 - tail) - (tail - start_tail))	
		{
			x--;
		}
		break;
	}
}

int Figure::console_width() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	if (w == 0) //Getting start width of the console once
	{
		start_width = width;
	}
	w = 1;

	return width;
}   //Getting widht size of the console

int Figure::console_height() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	if (h == 0)	//Getting start	height of the console once
	{
		start_height = height;
	}
	h = 1;

	return height;
}	//Getting height size of the console

void Figure::centred() {
	x_centre = (width - tail) / 2 - (tail/2);
	y_centre = height / 2 - wings - 3;			
}	//Getting center of each dimension

void Figure::clear() {
	system("CLS");
}	//Clear method to use in Main file



