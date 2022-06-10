
#include <iostream>
#include "List.h"
using namespace std;
LList::~LList()
{
    while (HEAD != nullptr) // Пока по адресу хоть что-то есть
    {
        Store *temp = HEAD -> next; // Запишем указатель на адрес следующего элемента структуры
        delete HEAD; // Освобождаем память по месту начала списка
        HEAD = temp; // Меняем адрес начала списка
    }
}

bool LList::is_empty() {
    return HEAD == nullptr;
}

/* Given a reference (pointer to pointer)
to the head of a list
and an int, inserts a new node on the
front of the list. */
void LList::add(Store st)
{
    Store** head_ref = &HEAD;
    /* 1. allocate node */
    Store* new_node = new Store(st);

    /* 3. Make next of new node as head
    and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

struct Store* swap(struct Store* ptr1, struct Store* ptr2)
{
    struct Store* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void sortedInsert(struct Store** head_ref, struct Store* newNode)
{
    struct Store* current;

    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newNode;

        // if the node is to be inserted at the beginning
        // of the doubly linked list
    else if ((*head_ref)->get_name() >= newNode->get_name()) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

        // locate the node after which the new node
        // is to be inserted
        while (current->next != NULL &&
               current->next->get_name() < newNode->get_name())
            current = current->next;

        /*Make the appropriate links */

        newNode->next = current->next;

        // if the new node is not inserted
        // at the end of the list
        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}

void sortedInsert_two_fields(struct Store** head_ref, struct Store* newNode)
{
    struct Store* current;

    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newNode;

        // if the node is to be inserted at the beginning
        // of the doubly linked list
    else if (
                (*head_ref)->get_name() > newNode->get_name() ||
                (
                    (*head_ref)->get_name() == newNode->get_name()
                    &&
                    (*head_ref)->get_cost() > newNode->get_cost()
                )
            )
    {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

        // locate the node after which the new node
        // is to be inserted
        while (current->next != NULL &&
               current->next->get_name() < newNode->get_name())
            current = current->next;

        /*Make the appropriate links */

        newNode->next = current->next;

        // if the new node is not inserted
        // at the end of the list
        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}

// function to sort a doubly linked list using insertion sort
void LList::sort()
{
    struct Store** head_ref = &HEAD;
    // Initialize 'sorted' - a sorted doubly linked list
    struct Store* sorted = NULL;

    // Traverse the given doubly linked list and
    // insert every node to 'sorted'
    struct Store* current = *head_ref;
    while (current != NULL) {

        // Store next for next iteration
        struct Store* next = current->next;

        // removing all the links so as to create 'current'
        // as a new node for insertion
        current->prev = current->next = NULL;

        // insert current in 'sorted' doubly linked list
        sortedInsert(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted doubly linked list
    *head_ref = sorted;
}

/* Function to sort the list */
void LList::sort_by_two()
{
    struct Store** head_ref = &HEAD;
    // Initialize 'sorted' - a sorted doubly linked list
    struct Store* sorted = NULL;

    // Traverse the given doubly linked list and
    // insert every node to 'sorted'
    struct Store* current = *head_ref;
    while (current != NULL) {

        // Store next for next iteration
        struct Store* next = current->next;

        // removing all the links so as to create 'current'
        // as a new node for insertion
        current->prev = current->next = NULL;

        // insert current in 'sorted' doubly linked list
        sortedInsert(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted doubly linked list
    *head_ref = sorted;
}

void LList::insert_after(Store* prev_node, Store *mass)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }

    /* 2. allocate new node */
    Store* new_node = mass;


    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void LList::add_sorted(Store mass)
{
    Store *p = new Store(mass); // Выделяем память под новую структуру
    if (is_empty()) {
        HEAD = p;
        TAIL = p;
        return;
    }
    if ( (HEAD->next == nullptr) && (HEAD->get_name() >= mass.get_name()) ){
        p->next = HEAD;
        HEAD = p;
        return;
    }
    Store *temp=HEAD->next, *temp_prev=HEAD;
    while(temp){
        if (temp->get_name() >= mass.get_name()){
            insert_after(temp_prev, p);
            return;
        }
        temp_prev = temp;
        temp = temp->next;
    }
    insert_after(temp_prev, p);
    TAIL = p;
}

void LList::print()
{
    if (is_empty()) return;
    Store *temp = HEAD; // объявляем указатель и пусть он указывает на начало списка
    while (temp){ // пока есть на что указывать
        cout << *temp;
        temp = temp->next;
    }
}

void LList::print_names()
{
    if (is_empty()) return;
    Store *temp = HEAD; // объявляем указатель и пусть он указывает на начало списка
    while (temp){ // пока есть на что указывать
        cout << temp->get_name() << " ";
        temp = temp->next;
    }
    cout << endl;
}

Store* LList::find(string _val) {
    Store* p = HEAD;
    while (p && p->get_name() != _val) p = p->next;
    return (p && p->get_name() == _val) ? p : nullptr;
}

void LList::remove(std::string _val) {
    Store** head_ref = &HEAD;
    Store* del = find(_val);
    if (*head_ref == NULL || del == NULL) {
        return;
    }
    if (*head_ref == del) {
        *head_ref = del->next;
    }
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    free(del);
    return;
}


