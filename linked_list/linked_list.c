#include<stdio.h>
#include<stdlib.h>


#define succ printf("Succeeded!\n")
#define uninitialized printf("Sorry,Please initialize list first...\n")
#define outofbound printf("Out of bound...\n")

struct node{
	int data;
	struct node* next;
};
typedef struct node node;

node *head = NULL;
//node* tail = NULL;

void create_list() {
	if (head == NULL) {
	       	head = (node *)malloc(sizeof(node));
	       	head -> data = 0; //size
	       	head -> next = NULL;
		succ;
       	}
	else {
		printf("You already created a list");
	}
}

void size() {
	if (head == NULL) {
		uninitialized;
	}
	else {
		printf("The size of Your list : %d\n", head -> data);
	}
}

void empty() { //error : -1  empty : 1 not_empty : 0
	if (head == NULL) 
		uninitialized;
	else {
		if (head -> data == 0) printf("True\n");
		else {
			printf("False\n");
		}
	}
}

node* traverse(int index) {
	node* list = head -> next;
	int i = index;
	while(i > 0) {
		list = list -> next;
		i--;
	}
	return list;
}

void value_at(int index) { // -1 : no suck list 0 : out of bound
	if (head == NULL) {
		uninitialized;
	}
	else if (index >= head -> data) outofbound;
	else {
		node* list = traverse(index);
		printf("Value at %dth of Your list is : %d\n", index, list->data);
	}
}

void display_list() {
	if (head == NULL) uninitialized;
	else {
		if (head -> data == 0) printf("Empty list\n");
		else {
			int i;
			node *list = head -> next;
			for (i = 0; i < head -> data; i++) {
				printf("%d\t", list -> data);
				list = list -> next;
			}
			printf("\n");
		}
	}
}

void push_front(int val) { 
	if (head == NULL) uninitialized;
	else {
	       	node* temp = malloc(sizeof(node)); 
		temp -> data = val; 
		temp -> next = head -> next;
	       	head -> next = temp;
	       	head -> data += 1; // increase the size of Linkedlist
		succ;
	}
}

void pop_front() {
	if (head == NULL) uninitialized;
	else if (head -> data == 0) outofbound;
	else {
		node* list = head -> next;
		node* post = list -> next;
		head -> next = post;
		head -> data -= 1;
		int val = list -> data;
		free(list -> next);
		printf("Fron item's value : %d\n", val);
	}
}

void push_back(int val) {
	if (head == NULL) uninitialized;
	else {
	       	int len = head -> data;
	       	node *temp = malloc(sizeof(node));
	       	temp -> next = NULL;
		temp -> data = val; 
		if (len == 0) {
			head -> data += 1;
			head -> next = temp;
			succ;
		}
		else {
		       	node *tail = traverse(len - 1);
		       	tail -> next = temp;
		       	head -> data += 1;
		       	succ;
	       	}
	}
}

void pop_back() {
	if (head == NULL) uninitialized;
	else {
	       	int len = head -> data;
		if (len == 0) outofbound;
		else if (len == 1) {
			int val = (head -> next) -> data;
			node* temp = head -> next;
			free(temp);
			head -> next = NULL;
			head -> data = 0;
			printf("The Back item's value : %d\n", val);
		} 
		else {
			node *pre_tail = traverse(len - 2);
		       	node *temp = pre_tail -> next;
		       	int val = temp -> data;
		       	free(temp);
			pre_tail -> next = NULL;
			head -> data -= 1;
			printf("The Back item's value : %d\n", val);
		}
	}
}

void front() {
	if (head == NULL) uninitialized;
	else {
		int len = head -> data;
		if (len == 0) outofbound;
		else {
			printf("The Front value is : %d\n", (head -> next) -> data);
		}
	}
}

void back() {
	if (head == NULL) uninitialized;
	else {
		int len = head -> data;
		if (len == 0) outofbound;
		else {
			node* temp = traverse(len - 1);
			printf("The Back value is: %d\n", (temp -> data));
		}
	}
}

void insert(int index, int val) {
	if (head == NULL) uninitialized;
	else {
		int len = head -> data;
		if (index + 1 > len) outofbound;
		else {
	       	node *temp = traverse(index - 1);
	       	node *new = malloc(sizeof(node));
	       	new -> next = temp -> next;
	       	new -> data = val;
	       	temp -> next = new;
	       	head -> data += 1;
		succ;
	       	}
	}
}

void erase(int index) {
	node *pre = traverse(index - 1);
	node *post = traverse(index + 1);
	node *curr = pre -> next;
	pre -> next = post;
	free(curr);
	succ;
}

void value_n_from_end(int n) {
	if (head == NULL) uninitialized;
	else {
	       	int len = head -> data;
		if (n > len) outofbound;
		else {
		       	int index = len - n;
			node* curr = traverse(index);
			printf("The %dth item from the end of your list is: %d\n", n, curr->data);
		}
	}
}


void reverse() {
	node *front, *mid, *end;
	front = head -> next;
	mid = front -> next;
	end = mid -> next;
	front -> next = NULL;
	while (end != NULL) {
		mid -> next = front;
		front = mid;
		mid = end;
		end = end -> next;
	}
	mid -> next = front;
	head -> next = mid;
	succ;
}


int main() {
	int val,index,n;
	int ch;
	do {
	printf("\n\n\t 1.Create a linked list");
	printf("\n\n\t 2.Return linked list size");
	printf("\n\n\t 3.Test if list empty");
	printf("\n\n\t 4.Return value at Index");
	printf("\n\n\t 5.Add item to the front of the list");
	printf("\n\n\t 6.Remove front item and return its val");
	printf("\n\n\t 7.Add item to the end of list");
	printf("\n\n\t 8.Remove end item and return its val");
	printf("\n\n\t 9.Get the value of front item");
	printf("\n\n\t 10.Get the value of end item");
	printf("\n\n\t 11.Insert value at index");
	printf("\n\n\t 12.Remove item at given index");
	printf("\n\n\t 13.Get the nth item from the end");
	printf("\n\n\t 14.Reverse the linkedlist");
	printf("\n\n\t 15.Display it");
	printf("\n");
	printf("Please input your choice: ");
	scanf("%d", &ch);
	printf("***********************\n");
	switch (ch) {
		case 0: exit(1);
		case 1:
			create_list();
			break;
		case 2:
			size();
			break;
		case 3:
			empty();
			break;
		case 4:
			printf("Please input the index:");
			scanf("%d",&index);
			value_at(index);
			break;
		case 5:
			printf("Please input the value to add:");
			scanf("%d",&val);
			push_front(val);
			break;
		case 6:
			pop_front();
			break;
		case 7:
			printf("Please input the value to add:");
			scanf("%d",&val);
			push_back(val);
			break;
		case 8:
			pop_back();
			break;
		case 9:
			front();
			break;
		case 10:
			back();
			break;
		case 11:
			printf("Please input the index and value:");
			scanf("%d, %d",&index, &val);
			insert(index, val);
			break;
		case 12:
			printf("Please input the index:");
			scanf("%d",&index);
			erase(index);
			break;
		case 13:
			printf("Please input the index:");
			scanf("%d", &n);
			value_n_from_end(n);
			break;
		case 14:
			reverse();
			break;
		case 15:
			display_list();
			break;
		default:
			printf("No such option,Please try again...\n");
			break;
       	}
	printf("***********************\n");
	}while(ch != 0);
}

