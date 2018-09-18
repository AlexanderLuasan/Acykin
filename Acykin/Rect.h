#pragma once

class rect
{
public:
	rect(int x, int y, int w, int h);
	void display();
	
	//colision

	bool colision(rect other);
	bool verticalOverLap(rect other);
	bool horizantalOverLap(rect other);


	//advanced setting and getting
	int* getCenter();
	void setCenter(int x,int y);
	int left();
	void left(int l);
	int right();
	void right(int r);
	int top();
	void top(int t);
	int bottom();
	void bottom(int b);
	//basic setting and getting
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

