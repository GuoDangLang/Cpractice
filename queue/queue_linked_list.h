#include<stdio.h>
#include<stdlib.h>

#define SUCCEED printf("Succeed!\n");

struct node {
	int data;
	struct node * next;
};

typedef struct node node;

node* tail = NULL;
node* head = NULL;

void enqueue(int val) {
	node *new_node = malloc(sizeof(node));
	new_node -> data = val;
	new_node -> next = NULL;
	if (head == NULL) {
		head = new_node;
		tail = head;
		SUCCEED;
	}
	else {
		tail -> next = new_node;
		tail = tail -> next;
		SUCCEED;
	}
}

void dequeue() {
	if (head == NULL) printf("Error: Empty Queue!\n");
	else {
	       	int val = head -> data;
	       	node *temp = head;
		head = head -> next;
		free(temp);
	       	printf("pop : %d\n", val);
	}
}

int empty() {
	if (head == NULL) {
		printf("Empty\n");
		return 1;
	}
	else {
		printf("Nonempty\n");
		return -1;
	}
}

