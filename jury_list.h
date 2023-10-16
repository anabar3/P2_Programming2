/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ana Barrera Novas LOGIN 1: ana.barrera@udc.es
 * AUTHOR 2: Javier Carballal Morgade LOGIN 2: javier.carballal.morgade@udc.es
 * GROUP: 6.0
 * DATE: 13 / 04 / 23
 */

#ifndef JURY_LIST_H
#define JURY_LIST_H

#include "types.h"
#include "participant_list.h"

#include <stdbool.h>

#define NULLJ (-1)
#define MAX 10

typedef struct tItemJ {
    tJuryName juryName;
    tNumVotes totalVoters;
    tNumVotes validVotes;
    tNumVotes nullVotes;
    tListP participantList;
} tItemJ;

typedef int tPosJ;

typedef struct tListJ{
    tItemJ data[MAX];
    tPosJ lastpos; //Used to refer to the last valid position of the list (from then on everything is garbage)
}tListJ;

void createEmptyListJ(tListJ* L);
/* Generator {
Goal: Creates an empty list and initializes it
Input
Output: An empty list
Postcondition: The list has no elements
}*/

bool insertItemJ(tItemJ d, tListJ* L);
/* Generator{
Goal: Inserts an element in the list.
    - If the last position is the maximum, it doesn't insert the item
    - Otherwise, the item will be placed in its correct position according to the order
Input:
    - Item: Content of the element to be inserted
    - List: List where we are inserting
Output:
    - List: Modified list
    - True if the element could be inserted, false otherwise
Postcondition: the positions of the elements in the list subsequent to the inserted
one will vary
} */

bool copyListJ(tListJ L, tListJ* M);
/* Modifier{
 *Goal: Copies one list into another
Input:
    - Original List (L) to be copied
Output:
    - New list (M), copy of the original
    - True if the copy was successful, false otherwise
Precondition: the initial list (L) is initialized
 }*/

void updateItemJ(tItemJ d , tPosJ p, tListJ* L);
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

void deleteAtPositionJ(tPosJ p, tListJ* L);
/* Destructor{
Goal: Deletes the element with the given position from the list
Input:
    - Position: position of the element to delete
    - List: list to be modified
    - Output:
    - List: List without the element that was located at Position
Precondition: position is valid in the given list and the participant list of that jury is empty
Postcondition: the positions of the elements of the list subsequent to the deleted
one will vary (unless the position given is the last one)
}*/
void deleteListJ(tListJ* L);
/* Destructor{
Goal: Removes all the elements of the list
Input: List to be deleted
Output: Empty list
}*/

tPosJ findItemJ(tParticipantName d, tListJ L);
/* Observer{
Goal: Finds the first element with a specified content in the list
Input:
    - Item (name): Content of the element to search for
    - List: List where the search is to be made
Output: Position of the element found, or null if it is not found
 }*/

bool isEmptyListJ(tListJ L);
/* Observer{
Goal: Determines whether the list is empty or not
Input: List to be checked
Output: True if the list is empty, false otherwise
 }*/

tItemJ getItemJ(tPosJ p, tListJ L);
/* Observer{
Goal: Retrieves the content of an element of the list
Input:
    - Position: Position of the desired element
    - List: List from where the item is to be retrieved
Output: Content of the element located at Position
Precondition: position is valid in the list
 }*/
tPosJ firstJ(tListJ L);
/* Observer{
Goal: Returns the position of the first element of the list
Input: List to be handled
Output: Position of its first element
Precondition: The list is not empty
 }*/

tPosJ lastJ(tListJ L);
/* Observer{
Goal: Returns the position of the last element of the list
Input: List to be handled
Output: Position of its last element
Precondition: The list is not empty
 */

tPosJ previousJ(tPosJ p, tListJ L);
/* Observer{
Goal: Returns the position of the element preceding the current
one
Input:
    - Position: Position of the current element
    - List: List to be handled
Output: Position of its previous element, or null if the given element
was the first one
Precondition: position is valid in the list
 }*/

tPosJ nextJ(tPosJ p, tListJ L);
/* Observer{
Goal: Returns the position of the element that follows the current
one
Input:
    - Position: Position of the current element
    - List: List to be handled
Output: Position of the next element, or null if the given element was
the last one
Precondition: Position is valid in the list
 }*/


#endif
