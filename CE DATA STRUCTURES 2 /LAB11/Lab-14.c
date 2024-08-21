#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 14
#define HASH_SIZE 10

typedef struct HASH_TABLE_s *HASH_TABLE;
typedef struct HASH_TABLE_s{
	int key;
	void *value;
	int flag;
} HASH_TABLE_t[1];

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s {
	LINKED_LIST_NODE next;
	void *data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s {
	LINKED_LIST_NODE head;
} LINKED_LIST_t[1], *LINKED_LIST;

LINKED_LIST linked_list_init() {
	LINKED_LIST new;
	new = (LINKED_LIST) malloc(sizeof(LINKED_LIST_t));
	if (new != NULL) {
		new->head = NULL;
	} else {
		printf("Error @ linked_stack_init: Memory allocation.");
	}
	return new;
}

void linked_list_append(LINKED_LIST list, void *data) {
	LINKED_LIST_NODE node = (LINKED_LIST_NODE)list;
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = malloc(sizeof(LINKED_LIST_NODE_t));
	node->next->data = data;
	node->next->next = NULL;
}

void linked_list_print(LINKED_LIST list) {
	LINKED_LIST_NODE node = list->head;
	while (node != NULL) {
		printf("%d ", *(int *)node->data);
		node = node->next;
	}
}

HASH_TABLE init_hashtable(){
	// Fill here
	HASH_TABLE hashTable = (HASH_TABLE)malloc(sizeof(HASH_TABLE_t)*HASH_SIZE);
	for (int i = 0; i < HASH_SIZE; i++)
	{
		hashTable[i].flag = 0;
		hashTable[i].key = 0;
		hashTable[i].value = NULL;
	}
	
	return hashTable;
}

int hash(int key){ // n^2 mod HASH_SIZE
	// Fill here 

	return (key*key)%HASH_SIZE;
}

void put(HASH_TABLE htable, int key, void *value){
	// Fill here
	int location = hash(key);

	if(htable[location].value == NULL)
	{
		htable[location].key = key;
		htable[location].value = value;
	}

	else if(htable[location].flag == 0){
		LINKED_LIST list = linked_list_init();

		linked_list_append(list, htable[location].value);
		linked_list_append(list, value);

		htable[location].flag = 1;
		htable[location].value = list;
	}
	else if(htable[location].flag == 1){
		LINKED_LIST list = htable[location].value;
		linked_list_append(list, value);

	}

	return;
}

void print_HashTable(HASH_TABLE h1){
	// Fill here
	for (int i = 0; i < HASH_SIZE; i++)
	{
		printf("KEY : %d -> ", i+1);
		if(h1[i].value != NULL)
		{
			if(h1[i].flag == 0)
			{
				printf("%d", *(int*)(h1[i].value));
			}

			else if(h1[i].flag == 1)
			{
				LINKED_LIST list = h1[i].value;
				linked_list_print(list);
			}		
		}

		printf("\n");
	}
	
}

int main(void) {

	HASH_TABLE h1 = init_hashtable();

	int keyArr[ARR_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	int valArr[ARR_SIZE] = { 3, 12, 18, 22, 23, 33, 38, 45, 73, 82, 97, 98, 99, 100};

	for (int i = 0; i < ARR_SIZE; ++i) {
		put(h1, keyArr[i], &valArr[i]);
	}

	print_HashTable(h1);

	return 1;
}
