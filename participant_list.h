/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ana Barrera Novas LOGIN 1: ana.barrera@udc.es
 * AUTHOR 2: Javier Carballal Morgade LOGIN 2: javier.carballal.morgade@udc.es
 * GROUP: 6.0
 * DATE: 13 / 04 / 23
 */

#ifndef PARTICIPANT_LIST_H
#define PARTICIPANT_LIST_H

#include "types.h"

#define NULLP NULL

typedef struct tNode{
    tItemP data;
    struct tNode* next;
}tNode;

typedef tNode* tPosP;
typedef tPosP tListP;

void createEmptyListP(tListP* L);
/* Generator {
Goal: Creates an empty list and initializes it
Input
Output: An empty list
Postcondition: The list has no elements
}*/

bool insertItemP(tItemP d, tListP* L);
/* Generator{
Goal: Inserts an element in the list.
    - The element is inserted in the position that corresponds following the order of participantName
Input:
    - Item: Content of the element to be inserted
    - List: List where we are inserting
Output:
    - List: Modified list
    - True if the element could be inserted, false otherwise
Postcondition: the positions of the elements in the list subsequent to the inserted
one will vary
} */

bool copyListP(tListP L, tListP* M);
/* Modifier{
 *Goal: Copies one list into another
Input:
    - Original List (L) to be copied
Output:
    - New list (M), copy of the original
    - True if the copy was successful, false otherwise
Precondition: the initial list (L) is initialized
 }*/

void updateItemP(tItemP d , tPosP p, tListP* L);
/* Modifier{
Goal: Changes the content of an element of the list
Input:
    - Item: new content to be assigned to the element at Position
    - Position: position of the element that we wish to modify
    - List: The list to be modified
Output:
    - List: List with the content of the element modified
Precondition: the position is valid in the given list
 }*/

void deleteAtPositionP(tPosP p, tListP* L);
/* Destructor{
Goal: Deletes the element with the given position from the list
Input:
    - Position: position of the element to delete
    - List: list to be modified
    - Output:
    - List: List without the element that was located at Position
Precondition: position is valid in the given list
Postcondition: the positions of the elements of the list subsequent to the deleted
one will vary (unless the position given is the lastP one)
}*/
void deleteListP(tListP* L);
/* Destructor{
Goal: Removes all the elements of the list
Input: List to be deleted
Output: Empty list
}*/

tPosP findItemP(tParticipantName d, tListP L);
/* Observer{
Goal: Finds the firstP element with a specified content in the list
Input:
    - Item (name): Content of the element to search for
    - List: List where the search is to be made
Output: Position of the element found, or null if it is not found
 }*/

bool isEmptyListP(tListP L);
/* Observer{
Goal: Determines whether the list is empty or not
Input: List to be checked
Output: True if the list is empty, false otherwise
 }*/

tItemP getItemP(tPosP p, tListP L);
/* Observer{
Goal: Retrieves the content of an element of the list
Input:
    - Position: Position of the desired element
    - List: List from where the item is to be retrieved
Output: Content of the element located at Position
Precondition: position is valid in the list
 }*/
tPosP firstP(tListP L);
/* Observer{
Goal: Returns the position of the first element of the list
Input: List to be handled
Output: Position of its firstP element
Precondition: The list is not empty
 }*/

tPosP lastP(tListP L);
/* Observer{
Goal: Returns the position of the last element of the list
Input: List to be handled
Output: Position of its lastP element
Precondition: The list is not empty
 */

tPosP previousP(tPosP p, tListP L);
/* Observer{
Goal: Returns the position of the element preceding the current
one
Input:
    - Position: Position of the current element
    - List: List to be handled
Output: Position of its previousP element, or null if the given element
was the firstP one
Precondition: position is valid in the list
 }*/

tPosP nextP(tPosP p, tListP L);
/* Observer{
Goal: Returns the position of the element that follows the current
one
Input:
    - Position: Position of the current element
    - List: List to be handled
Output: Position of the nextP element, or null if the given element was
the lastP one
Precondition: Position is valid in the list
 }*/

#endif
