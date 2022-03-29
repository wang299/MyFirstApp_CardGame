#pragma once
#include"common.h"

class Windows
{
public:
	Windows(int width, int height, string imgURL);
	void Refresh();
	void Show();
	~Windows();

protected:
	int width;
	int height;
	IMAGE* img;
	string imgURL;
};