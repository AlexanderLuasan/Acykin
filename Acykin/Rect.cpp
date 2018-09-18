#include "Rect.h"
#include <iostream>
using namespace std;
rect::rect(int x, int y, int w, int h){
	xpos = x;
	ypos = y;
	width = w;
	height = h;

}
void rect::display() {
	cout << "ypos  :" << this->gety() << endl;
	cout << "xpos  :" << this->getx() << endl;
	cout << "height:" << this->geth() << endl;
	cout << "width :" << this->getw() << endl;
}


bool rect::colision(rect other) {
	if ((this->horizantalOverLap(other)) &( this->verticalOverLap(other))) {
		return true;
	}
	else {
		return false;
	}
}


bool rect::horizantalOverLap(rect other) {
	if ((this->left() < other.right()) & (this->right() > other.left())) {
		return true;
	}
	else if ((this->left() > other.right()) & (this->right() < other.left())) {
		return true;
	}
	else {
		return false;
	}
}

bool rect::verticalOverLap(rect other) {
	if ((this->top() < other.bottom()) & (this->bottom() > other.top())) {
		return true;
	}
	else if ((this->top() > other.bottom() )&( this->bottom() < other.right())) {
		return true;
	}
	else {
		return false;
	}
}






int* rect::getCenter() {
	int end[2];
	end[0] = this->getx() + this->getw() / 2;
	end[1] = this->gety() + this->geth() / 2;

	return end;
}
void rect::setCenter(int x,int y) {
	this->setx(x - this->getw()/2);
	this->sety(y - this->geth()/2);


}

int rect::left() {
	return xpos;
}
void rect::left(int l) {
	this->setx(l);
}

int rect::right() {
	return xpos+width;
}
void rect::right(int r) {
	this->setx(r-width);
}

int rect::top() {
	return ypos;
}
void rect::top(int t) {
	this->sety(t);
}

int rect::bottom() {
	return ypos + height;
}
void rect::bottom(int b) {
	this->sety(b-height);
}


//getter and setters
int rect::getx() {
	return xpos;
}

int rect::gety() {
	return ypos;
}

int rect::getw() {
	return width;
}

int rect::geth() {
	return height;
}

void rect::setx(int x) {
	xpos = x;
}

void rect::sety(int y) {
	ypos = y;
}

void rect::seth(int h) {
	height = h;
}

void rect::setw(int w) {
	width = w;
}