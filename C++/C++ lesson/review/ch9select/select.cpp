// 文件：select.cpp
// 包括机器选择和玩家选择函数的实现
#include <select.h>

#include <cstdlib>
#include <iostream>
using namespace std;

Selection select_by_player() {
	char c;
	Selection player_choice;

	prn_help();
	cout << "please select: ";
	cin >> c;
	switch (c)
	{
		case 'p':
			player_choice = paper;
			cout << "You are paper. ";
			break;
		case 'r':
			player_choice = rock;
			cout << "you are rock. ";
			break;
		case 's':
			player_choice = scissor;
			cout << "you are scissor. ";
			break;
		case 'g':
			player_choice = game;
			break;
		case 'q':
			player_choice = quit;
			break;
		default:
			player_choice = help;
			break;
	}
    return player_choice;
}

Selection select_by_machine() {
	int select = (rand() * 3 / (RAND_MAX + 1));
	cout << "I am ";
	switch (select) {
		case 0:
			cout << "paper. ";
			break;
		case 1:
			cout << "rock. ";
			break;
		case 2:
			cout << "scissor. ";
			break;
	}
	return ((Selection)select);
}
