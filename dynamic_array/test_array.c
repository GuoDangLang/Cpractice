#include "array.h"

void print_array(array* x) {
	int len = size(x);
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", at(x, i));
	}
	printf("\n");
	printf("The size: %d\n", size(x));
	printf("The capacity: %d\n", capacity(x));
}
int main() {
	array* x = get_dynamic_array();
	printf("%d\t",is_empty(x));
	push(x, 10);
	push(x, 20);
	printf("%d\t",size(x));
	printf("%d\t",capacity(x));
	printf("%d\t",at(x, 0));
	printf("%d\t",at(x, 1));
	at(x,3);
	printf("Insertion\n");
	insert(x, 0, 30);
	insert(x, 3, 40);
	insert(x, 2, 50);
	insert(x, 1,23);
	insert(x, 2,43);
	insert(x, 3, 44);
	print_array(x);
	prepend(x,100);
	print_array(x);
	delete(x, 1);
	print_array(x);
	delete(x, 7);
	delete(x,3);
	print_array(x);
	remove_array(x, 100);
	remove_array(x, 10);
	print_array(x);
	printf("Test Find\n");
	printf("%d\t",find(x, 43));
	printf("%d\t",find(x, 50));
	printf("\n");
	printf("Test pop\n");
	printf("%d \t",pop(x));
	printf("%d \t",pop(x));
	printf("\n");
	print_array(x);
}
