#define _CRT_SECURE_NO_WARNINGS 1 
#include"common.h"
class Card;
class Windows;
class game
{
public:
	game();
	void game_init();
	void game_show();
	void in_Mouse(ExMessage msg);
	int click_game(ExMessage msg);
	void clear();
protected:
	array<array<int, 8>, 4> map;
	vector<Card*>pcard;
	Windows* win;
	vector<int> is_open;
};