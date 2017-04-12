/*
 * list.h
 * Name / StudentID
 * An implementation of a Linked List containg Cells
 */

#ifndef _LIST_H_
#define _LIST_H_

#include "cell.h"

#include <stdio.h>

struct ListNode;

typedef struct {
    struct ListNode* head;
    int size;
} List;

typedef struct ListNode {
    Cell data;
    struct ListNode* next;
} ListNode;

/*
 * Output:
 *      Returns a newly allocated List
 * Summary:
 *      Allocates space for an empty new List and returns it
 */
List* List_Create();

/*
 * Input:
 *      Cell data, data for the ListNode
 *      ListNode* node, the next node after the ListNode
 * Output:
 *      A ListNode* to a newly allocated ListNode
 * Summary:
 *      Allocates space for a ListNode and initializes its
 *      data and node members
 */
ListNode* ListNode_Create(Cell data, ListNode* node);

/*
 * Input:
 *      FILE* fp, a file pointer pointing to a read-only open file
 * Output:
 *      Returns a newly allocated list
 * Summary:
 *      Reads Cells from a file and puts them in a new List
 */
List* List_Read(FILE* fp);

/*
 * Input:
 *      List* list, the List to delete
 * Summary:
 *      Calls free on every node to deallocate memory
 *      used by the nodes of the List, then deallocates
 *      the list itself
 */
void List_Delete(List* list);

/*
 * Input:
 *      List* list, a List to add data to
 *      Cell data, data to add to the list
 * Output:
 *      The size of list after adding data
 * Summary:
 *      Adds data to the front of list
 */
int List_PushFront(List* list, Cell data);

/*
 * Input:
 *      List* list, a List to print
 * Summary:
 *      Prints elements from list, starting with the head
 */
void List_Print(List* list);

#endif  /* _LIST_H_ */
