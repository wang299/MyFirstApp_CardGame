#pragma once
#include"common.h"
#include"windows.h"
#include"card.h"
#include"game.h"
int main()
{
	game g;
	g.game_init();
	BeginBatchDraw();
	while (1)
	{
		g.game_show();
		FlushBatchDraw();
	}EndBatchDraw();
}
