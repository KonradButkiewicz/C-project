#include <iostream>
#include <conio.h>
#include "Figure.h"
using namespace std;


int main() {
	int c = 0;

start:

	Figure figure1;
	figure1.console_height();
	figure1.console_width();

	figure1.choose();
	cout << "\nTo proceed, click 'k' or to correct, click 'x'";
	figure1.centred();
	figure1.build();
sw:

	switch ((c = _getch()))	//Options to continue or go back
	{
	case 'k':
		figure1.clear();
		goto cont;
	case 'x':
		figure1.clear();
		goto start; 
	default:
		goto sw;
	}
cont:

	while (1)
	{
	cout << "Size of the console:       Keyboard: \n";
	cout << "x: " << figure1.console_width() << "                     Move =  Arrows keys, Scale = Decreasing: '-' ; Increasing: 'shift' + '='"  << endl; 
	cout << "y: " << figure1.console_height() << endl;
	figure1.build();
	figure1.size_move();
	figure1.clear();
	}

}