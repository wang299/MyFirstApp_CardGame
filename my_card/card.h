#pragma once
#include"common.h"
class Card
{
public:
	enum class CardState{Close,Open,No};
	Card(int x,int y,string imgURL,string imgyURL);
	string getURL();
	void SetState(CardState state);
	bool InMouse(ExMessage msg);
	bool ClickCard(ExMessage msg);
	void Show();

protected:
	int x;
	int y;
	int width = WIDTH;
	int height = HEIGHT;
	IMAGE* image;
	string imgURL;
	string imgyURL;
	CardState state;

};
