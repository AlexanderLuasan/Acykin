#include "wall.h"
#include "Rect.h"
using namespace std;


wall::wall(rect me){
	this->self = me;
}

rect wall::getColisionBox() {
	return self;
}

rect wall::getDrawingBox() {
	return self;
}