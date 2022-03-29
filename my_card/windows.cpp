#include "windows.h"

Windows::Windows(int width, int height, string imgURL)
{
	//³õÊ¼»¯ÊôÐÔ
	this->width = width;
	this->height = height;
	this->imgURL = imgURL;
	if (imgURL.size() != 0)
	{
		img = new IMAGE;
		loadimage(img, imgURL.c_str(), width, height);
	}
}

void Windows::Refresh()
{
	if (imgURL.size() == 0)
		cleardevice();
	else
		putimage(0, 0, img);
}

void Windows::Show()
{
	initgraph(this->width, this->height);
	
	if (imgURL.size() != 0)
		putimage(0, 0, img);
}

Windows::~Windows()
{
	delete[] img;
}
