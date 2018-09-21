#pragma once

class rect
{
public:
	rect(int x, int y, int w, int h);//iniate with all fields
	rect(); //defult make
	void display();//prints the varibles for esasy viewing
	
	//colision

	bool colision(rect other);//uses other colision functions to detect overlap
	bool verticalOverLap(rect other);
	bool horizantalOverLap(rect other);


	//advanced setting and getting
	int* getCenter(); // returns center of shape rounded down
	void setCenter(int x,int y); // sets center 
	int left();	//give the x value of left edge
	void left(int l); //sets x value of left edge
	int right(); // sets x value of right edge
	void right(int r);
	int top();
	void top(int t);
	int bottom();
	void bottom(int b);
	//basic setting and getting these replace the core variables
	int getx();
	int gety();
	int getw();
	int geth();
	void setx(int x);
	void sety(int y);
	void setw(int w);
	void seth(int h);


private:
	int xpos, ypos, width, height;
};

