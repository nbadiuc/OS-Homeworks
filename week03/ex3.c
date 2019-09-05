#include <stdio.h>
#include <stdlib.h>

struct Node {
    int nbr;
    struct Node *next;
};

typedef struct Node Node;
typedef struct Node* List;

void print_list(List* l) {
    Node* current_node = *l;
    while(current_node != NULL) {
        printf("%d ", current_node -> nbr);
        current_node = current_node -> next;
    }
}

void insert_node(int n, List* l) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> nbr = n;
    new_node -> next = NULL;
    Node* current_node = *l;
    if (current_node == NULL) {
        *l = new_node;
    }
    else {
        while (current_node -> next != NULL) {
            current_node = current_node -> next;
        }
        current_node -> next = new_node;
    }
}

void delete_node(int n, List* l) {
    Node* current_node = *l;
    if (current_node -> nbr == n) {
        *l = current_node -> next;
    }
    else {
        while(current_node -> next != NULL) {
            if ((current_node -> next) -> nbr == n) {
                Node *to_delete = current_node -> next;
                current_node -> next = (current_node -> next) -> next;
                free(to_delete);
            }
            current_node = current_node -> next;
        }
    }
}

int main() {
    List a = NULL;
    insert_node(5, &a);
    print_list(&a);
    insert_node(8, &a);
    insert_node(1, &a);
    print_list(&a);
    delete_node(8, &a);
    print_list(&a);
}
