#include<stdio.h>
#include"queue_array.h"
#include<stdlib.h>

void display_queue() {
	int i;
	if (read > write) {
		for (i = read; i < MAX_SIZE; i++) {
			printf("%d\t", queue[i]);
		}
		for (i = 0; i < write; i++) {
			printf("%d\t", queue[i]);
		}
	}
	else if (read == write) printf("Error: Empty queue!\n");
	else {
		for(i = read; i < write; i++) {
			printf("%d\t", queue[i]);
		}
	}
	printf("\n");
}

int main() {
	int ch;
	do {
		printf("\n\n\t 0.exit");
		printf("\n\n\t 1.enqueue");
		printf("\n\n\t 2.dequeue");
		printf("\n\n\t 3.empty");
		printf("\n\n\t 4.display");
		printf("\nPLease input your Choice:");
		scanf("%d", &ch);
		int val;
		printf("***************\n");
		switch (ch) {
			case 0: 
				exit(1);
				break;
			case 1:
				printf("Please input the value:");
				scanf("%d", &val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				empty();
				break;
			case 4:
				display_queue();
				break;
			default:
				printf("No such option,please retry...");
		}
		printf("***************\n");
	}while (ch != 0);
}
