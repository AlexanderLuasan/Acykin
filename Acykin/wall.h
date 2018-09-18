#pragma once
#include "Rect.h"

class wall
{
public:
	wall(rect me);
	rect getColisionBox();
	rect getDrawingBox();

private:
	rect self;
	
};



