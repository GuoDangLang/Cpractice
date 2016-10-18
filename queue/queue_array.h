#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 3

int queue[MAX_SIZE];
int read,write = 0;

void enqueue(int val) {
	       	if (((write + 1) % MAX_SIZE) == read) printf("Error : The queue is filled!\n");
	       	else {
		       	queue[write++] = val;
			write = write % MAX_SIZE;
			printf("Succeed!\n");
	       	}	
}

void dequeue() {
	read = read % MAX_SIZE;
	if (read == write) printf("Error : Empty queue\n");
	else {
		printf("Value : %d\n",queue[read++]);
	}
}

void empty() {
	if (read == write) printf("Empty queue!\n");
	else {
		printf("Nonempty queue\n");
	}
}




