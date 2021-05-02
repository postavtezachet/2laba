
#include<stdio.h>
#include<Windows.h>
#include<string.h>
struct Game {

	int price;
	char* name;
	int union_trigger;
	union {
		char genre[20];
		int max_players;
	}un;
};
struct Node {
	Game game;
	Node* left;
	Node* right;
};