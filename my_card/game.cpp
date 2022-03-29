#include "game.h"
#include "windows.h"
#include"card.h"
#define _CRT_SECURE_NO_WARNINGS 1 

game::game():win(new Windows(8*WIDTH+20,4*HEIGHT+20,"img//background.jpg"))
{
	int start = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j += 2)
		{
			map[i][j] = start;
			map[i][j + 1] = start;
			start++;
		}
	}
}

void game::game_init()
{
	string imgURL;
	string coverURL = "img//cover.jpg";
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			int x = 10 + WIDTH * j;
			int y = 10 + HEIGHT * i;
			imgURL = "img//" + to_string(map[i][j]) + ".jpg";
			pcard.push_back(new Card(x, y, imgURL, coverURL));
		}
	}
	win->Show();
}

void game::game_show()
{
	win->Refresh();
	for (auto v : pcard)
	{
		v->Show();
	}
}

void game::in_Mouse(ExMessage msg)
{
	int result;
	if (is_open.size() < 2)
	{
		result = click_game(msg);
		if (result != -1)
		{
			pcard[result]->SetState(Card::CardState::Open);
			is_open.push_back(result);
		}
	}
	clear();
}

int game::click_game(ExMessage msg)
{
	for (int i = 0; i < pcard.size(); i++)
	{
		if (pcard[i]->ClickCard(msg) == true)
		{
			return i;
		}
	}
	return -1;
}

void game::clear()
{
	if (is_open.size() == 2)
	{
		if (is_open[0] != is_open[1] && pcard[is_open[0]]->getURL() == pcard[is_open[1]]->getURL())
		{
			pcard[is_open[0]]->SetState(Card::CardState::No);
			pcard[is_open[1]]->SetState(Card::CardState::No);
		}
		else
		{
			pcard[is_open[0]]->SetState(Card::CardState::Close);
			pcard[is_open[1]]->SetState(Card::CardState::Close);
		}
		pcard.clear();
	}
}
	