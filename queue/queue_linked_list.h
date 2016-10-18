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
	int val = tail -> data;
	node *temp = tail;
	node *travel = head;
	while (travel -> next != tail) {
		travel = travel -> next;
	}
	free(temp);
	tail = travel;
	tail -> next = NULL;
	printf("pop : %d\n", val);
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

