/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ana Barrera Novas LOGIN 1: ana.barrera@udc.es
 * AUTHOR 2: Javier Carballal Morgade LOGIN 2: javier.carballal.morgade@udc.es
 * GROUP: 6.0
 * DATE: 13 / 04 / 23
 */

#include "participant_list.h"
#include <stdlib.h>
#include <string.h>

void createEmptyListP(tListP *L)
{
    *L = NULLP;
}

bool createNode(tPosP* q)
{
    *q = malloc(sizeof(tNode));
    return *q != NULLP;
}

tPosP findPositionP(tParticipantName nombre, tListP L)
{
    tPosP p;
    for(p = L; (strcmp(p -> next -> data.participantName, nombre) <= 0) && (p -> next -> next != NULLP); p = p -> next);
    return p;
}

bool insertItemP(tItemP d, tListP* L)
{
    tPosP q, p;
    if(!createNode(&q)){  //If it wasn't able to create a node to insert the item, it returns false
        return false;
    }

    q->data = d; //Establishes a node with the data and a pointer to NULL (which will change in case the position isn't the lastP
    q->next = NULLP;

    if(*L == NULLP){ //There doesn't exist a list, insert the item as its firstP element
        *L = q;
    }
    else if(strcmp(d.participantName, (*L) -> data.participantName) < 0) { //The name of the new data is less than the first data, insert at the beginning
        q -> next = *L;
        *L = q;
    }
    else{ //Search for the correct position
        p = findPositionP(d.participantName, *L); //Pointer to the last node smaller than d
        if(strcmp(d.participantName, p -> next -> data.participantName) > 0){ //The data has to be inserted at the end
            p -> next -> next = q;
        }
        else{
            q -> next = p -> next;
            p -> next = q;
        }
    }
    return true;
}

tPosP firstP(tListP L)
{
    return L;
}

tPosP lastP(tListP L)
{
    tPosP i;
    for(i = L; i->next != NULLP; i = i -> next){ //Go through the list until i->nextP is null (which will be the lastP element)
    }
    return i;
}

tItemP getItemP(tPosP p, tListP L)
{
    return p->data;
}

void updateItemP(tItemP d , tPosP p, tListP* L)
{
    p -> data = d;
}

tPosP nextP(tPosP p, tListP L)
{
    return p -> next;
}

tPosP previousP(tPosP p, tListP L)
{
    tPosP q;
    if (p == L){  //If the position is the firstP, return NULL
        return NULLP;
    }
    else{
        for(q = L; q->next != p; q = q -> next){ //Go through the list until q->nextP is p (which will be the element previousP to p)
        }
        return q;
    }
}

tPosP findItemP(tParticipantName d, tListP L)
{
    tPosP p;
    for(p = L; (p != NULLP); p = p -> next){
        int comparison = strcmp(p->data.participantName, d);
        if(comparison == 0){
            return p;
        }
        else if(comparison > 0){
            break;
        }
    } // Go through the list until p is NULL (lastP element) or the elements compared are equal and return p (NULL or the position searched)
    return NULLP;
}

bool isEmptyListP(tListP L)
{
    return L == NULLP;
}

void deleteListP(tListP* L)
{
    tPosP p;
    while(*L == NULLP) //Go through the list freeing the memory element by element
    {
        p = *L;
        *L = (*L) -> next;
        free(p);
    }
}

void deleteAtPositionP(tPosP p, tListP* L)
{
    tPosP q;
    if(p == *L){ //if the position is the first, change the pointer to its nextP element and free the memory of the original firstP element
        *L = (*L) -> next;
    }
    else if(p -> next == NULLP){ //if the position is the last, make the previousP position point to null so it becomes the lastP element
        previousP(p, *L)->next = NULLP;
    }
    else{
        q = p -> next;
        p -> data = q -> data;
        p -> next = q -> next;
        p = q;
    }
    free(p);
}

bool copyListP(tListP L, tListP* M)
{
    tPosP p = NULLP,q,r;
    bool success = true;
    createEmptyListP(M);
    if(isEmptyListP(L) == false){
        p = L;
        while((p != NULLP) && (createNode(&r) == true)){ //Go through original list
            r -> data = p -> data;
            r -> next = NULLP; //Creates a node with info of p (node in the original list)
            if(p == L){ //we are at the firstP position
                *M = r;
            }
            else{
                q -> next = r;
            }
            q = r; //store info of r in q before r changes, so that in the next iteration you can link q to the nextP r
            p = p -> next;
        }
    }
    if(p != NULLP){ //the list didn't copy correctly
        success = false;
    }
    return success;
}