#include<stdio.h>
#include<Windows.h>
#include<string.h>
struct Game {

	int price;
	char* name;
	int r;
	union {
		char genre[20];
		int max_players;
	}un;
	Game* point;
};