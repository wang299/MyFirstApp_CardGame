#include"common.h"
#include "card.h"


Card::Card(int x, int y, string imgURL, string imgyURL)
{
	this->x = x;
	this->y = y;
	this->imgURL = imgURL;
	this->imgyURL = imgyURL;
	this->state = CardState::Close;

	image = new IMAGE[2];
	loadimage(image, imgyURL.c_str(), width, HEIGHT);
	loadimage(image+1, imgURL.c_str(), width, HEIGHT);
}
string Card::getURL()
{
	return imgURL;
}
void Card::SetState(CardState state)
{
	this->state = state;
}

bool Card::InMouse(ExMessage msg)
{
	if (msg.x >= this->x && msg.x <= this->x + this->width &&
		msg.y >= this->y && msg.y <= this->y + this->height &&
		this->state!=CardState::No&&this->state!=CardState::Open)
	{
		return true;
	}
	return false;
}
bool Card::ClickCard(ExMessage msg)
{
	if (this->state != CardState::No && InMouse(msg) && msg.message == WM_LBUTTONDOWN)
	{
		this->state = CardState::Open;
		return true;
	}
	return false;
}
void Card::Show()
{
	switch (this->state)
	{
	case CardState::Close:
		putimage(x, y, image);
		break;
	case CardState::Open:
		putimage(x, y, image + 1);
		break;
	case CardState::No:
		break;
	}
}
