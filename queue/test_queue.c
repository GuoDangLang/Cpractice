#include<stdio.h>
#include"queue_linked_list.h"
#include<stdlib.h>

void display_queue() {
	node *temp = head;
	while(temp != NULL) {
		printf("%d \t",temp -> data);
		temp = temp -> next;
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
