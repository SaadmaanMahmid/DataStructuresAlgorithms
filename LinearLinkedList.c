/******** All sorts of functionalities in a linear linked list in a fun way ********/
/*Author: Choudhury S. Mahmid (Sandy)
 * Date: 29 June, 2017
 * */

#include <stdio.h>


typedef struct node{
    int member_number;
    struct node *next;
} node_mockr;

struct node_mockr *head = NULL;
struct node_mockr *current = NULL;

void print_list(node_mockr *head);
void insert_first(node_mockr **head, int member_number);
void insert_last(node_mockr *head, int member_number);
int delete_first(node_mockr **head);
int delete_last(node_mockr *head);
int delete_specific(node_mockr **head, int index);


int main() {
}

//
