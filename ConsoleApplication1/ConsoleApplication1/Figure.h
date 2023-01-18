#include <iostream>
using namespace std;

class Figure {
public:
	char character;

	int tail;
	int start_tail;
	int wings;
	int start_wings;


	int x = 0;
	int y = 0;

	int x_centre;
	int y_centre;

	int height;
	int start_width;
	int w = 0;
	int width;
	int start_height;
	int h = 0;


	void choose(); //Options
	void build(); //Figure build with parametrs
	void centred(); //Centering
	void size_move(); //Sizing and moving
	int console_height(); //Getting height
	int console_width(); //Getting width
	void clear();
};

