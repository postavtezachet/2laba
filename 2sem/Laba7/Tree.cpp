#include<stdio.h>
struct Tree {
	char word[100];
	char ru_word[100];
	int n;
};
struct Node {
	Tree tree;
	Node* left;
	Node* right;
};
