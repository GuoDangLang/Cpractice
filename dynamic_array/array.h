#include<stdio.h>
#include<stdlib.h>

typedef struct new_array {
	int* data;
	int size;
	int capacity;
}array;

void resize(array* input, int new_capacity) {
	int *new_memo = malloc(new_capacity * sizeof(int));
	int *old_memo = input -> data;
	int *len = &(input -> size);
	int *cap = &(input -> capacity);
	int i;

	for(i = 0; i < *len; i++) {
		new_memo[i] = old_memo[i];
	}
	free(old_memo);
	input -> data = new_memo;
	*cap = new_capacity;
}
	
array* get_dynamic_array() {
	array *x = malloc(sizeof(array));
	x->capacity = 2;
	x->size = 0;
	x->data = malloc(x->capacity * sizeof(int));
	return x;
}

int size(array* input) {
	if (input == NULL) return -1;
	else {
		return input->size;
	}
}

int capacity(array* input) {
	if (input == NULL) return -1;
	else {
		return input->capacity;
	}
}

int is_empty(array* input) {
	if (input ==NULL) {
		printf("Array not exist.");
		return -1;
	}
	else {
		if (input -> size == 0) return 1;
		else return 0;
	}
}

int at(array* input, int pos) {
	int *len = &(input -> size);
	int *cap = &(input -> capacity);

	if ((*len) == (*cap)) resize(input, 2 * (*len));
	if ((*len) <= ((*cap) / 4)) resize(input, (*cap) / 2);
	if (input == NULL) {
		printf("Out of bound!");
		return -1;
	}
	else {
		if (*len < pos + 1) {
		       	printf("Out of bound!");
			return -1;
		}
		else {
			return (input -> data)[pos];
		}
	}
}

int push(array* input, int d) {
	if (input == NULL) return -1;
	else {
		int *len = &(input -> size);
		int *cap = &(input -> capacity);

		*((input -> data) + (*len)) = d;
		*len += 1;
		if (*len == *cap) {
			resize(input, 2 * (*cap));
		}
		return 1;
	}
}

int insert(array* input, int pos, int data_to_insert) {
	if (input == NULL) return -1;
	else {
		int *len = &(input -> size);
		int *cap = &(input -> capacity);

		int i;
		if (*len == pos) {
			input -> data[*len] = data_to_insert;
			*len += 1;
		       	if (*len == *cap) {
			       	resize(input, 2 * (*cap));
		       	} 
			return 1;
		}
		else if (*len > pos) {
		       	for(i = *len - 1; i >= pos; i--) {
				(input -> data)[i + 1] = (input -> data)[i];
			}
			(input -> data)[pos] = data_to_insert;
			*len += 1;
			if (*len == *cap) {
			       	resize(input, 2 * (*cap));
		       	}
			return 1;
		}
		else {
			printf("Unvalid Memroy access!");
			return -1;
		}
	}
}

int prepend(array* input, int data_to_prepend) {
	return insert(input, 0, data_to_prepend);
}

int pop (array* input) {
	if (input == NULL) return -1;
	else { 
		int *len = &(input -> size);
		int *cap = &(input -> capacity);
		int temp = (input -> data)[--(*len)];
		if ((*len) <= (*cap / 4)) resize(input, (*cap) / 2);
		return temp;
	}
}

int delete(array* input, int index) {
	int i;
	int *len = &(input -> size);
	int *cap = &(input -> capacity);

	if (index >= *len) {
		printf("Invalid index");
		return -1;
	}
	else if (index == (*len - 1) ) {
	       	(*len) -= 1;
		if (*len <= (*cap) / 4) resize(input, (*cap) / 2);
		return 1;
	}
	else {
		for (i = index; i < (*len) - 2; i++) {
			(input -> data)[i] = (input -> data)[i + 1];
		}
		*len -= 1;
		if (*len <= ((*cap) / 4)) resize(input, (*cap) / 2);
		return 1;
		}
}

int remove_array(array* input, int item) {
	int index = -1;
	int i;
	int *len = &(input -> size);
	int *cap = &(input -> capacity);

	for (i = 0; i < *len; i++) {
		if ((input -> data)[i] == item) index = i;
	}
	if (index == -1) {
		printf("No such item.");
		return index;
	}
	else {
		delete(input, index);
		return index;
	}
}

int find(array* input, int item) {
	int index = -1;
	int i;
	int *len = &(input -> size);
	int *cap = &(input -> capacity);

	for(i = 0; i < (*len); i++) {
		if ((input -> data)[i] == item) {
			index = i;
			break;
		}
	}

	return index;
}


			
	

