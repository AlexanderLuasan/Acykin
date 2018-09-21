#pragma once
#include "allegro5/allegro.h"
#include <string>
#include "Rect.h"
using namespace std;



class spritesheet // made to cut an image of many iamges into properslices
{
public:
	spritesheet(); // never use please
	spritesheet(const char * filename,int w,int h); //give the file name and the square the defines the first section width of hiehgt of first tile
	ALLEGRO_BITMAP *getFrame(int x, int y);  // get frame based on x and y from top corrner


private:
	int width, height; //width of heigt of images
	ALLEGRO_BITMAP *sheet; // the loaded bitmap


};


class plate //a compination image for esay drawing
{
public:
	plate();
	plate(int width, int height);//start a plate with a certain with and height
	void placeshape(ALLEGRO_BITMAP * shape, rect box); // add a bitmaped image to the plate
	ALLEGRO_BITMAP * getI(); // return the image for drawing
private:
	ALLEGRO_BITMAP * image; // the saved location of the image
};

