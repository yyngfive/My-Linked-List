#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int num;
	struct node *next;
};

typedef struct node node;

node *list_init(node *head);

bool list_create(node **head);

bool list_print(node *head);

bool list_clear(node **head);

int list_get_length(node *head);

int* list_get_num_of_idx(node *head,int idx);

int list_get_idx_of_num(node *head,int number);

bool list_sort(node **head);

bool list_empty(node *head);

bool list_modify_num(node **head,int idx,int n);

bool list_add_end(node **head,int value);

bool list_add_idx(node **head,int idx,int value);

bool list_add_head(node **,int value);

bool list_del_all(node **head);

bool list_del_head(node **head);

bool list_del_end(node **head);

bool list_del_idx(node **head,int idx);

bool list_del_num(node **head,int first_num);

