#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _employee{
    char name[32];
    unsigned char age;
} Employee;

int compareEmployee(Employee *e1, Employee *e2) {
    return strcmp(e1->name, e2->name);
}
typedef int(*COMPARE)(void*, void*);

void displayEmployee(Employee* employee) {
    printf("    --> %s\t%d\n", employee->name, employee->age);
}
typedef void(*DISPLAY)(void*);

typedef struct _node {
    void *data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

void initializeList(LinkedList*);
void addHead(LinkedList*, void*);
void addTail(LinkedList*, void*);
void delete(LinkedList*, Node*);
Node *getNode(LinkedList*, COMPARE, void*);
void displayLinkedList(LinkedList*, DISPLAY);

void initializeList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(LinkedList *list, void* data) {

}

void addTail(LinkedList *list, void* data) {

}




Node *getNode(LinkedList *list, COMPARE compare , void* data) {

}



void delete(LinkedList *list, Node *node) {

}



void displayLinkedList(LinkedList *list, DISPLAY display) {
    printf("\n  Liste chainée : \n");

    printf("\n");
}


void main(void) {
    // Créer une liste

    // Créer un employé "Samuel"

    // Créer un employé "Sally"

    // Initialiser la liste

    // Ajouter samuel et sally à la liste

    // Chercher un sally

    // Supprimer sally

    // Afficher la liste

}