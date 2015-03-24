#include <stdio.h>

struct list_node{
	char name[100];
	struct list_node *next;
};

struct list_node *head = 0;


