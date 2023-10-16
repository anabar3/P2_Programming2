/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ana Barrera Novas LOGIN 1: ana.barrera@udc.es
 * AUTHOR 2: Javier Carballal Morgade LOGIN 2: javier.carballal.morgade@udc.es
 * GROUP: 6.0
 * DATE: 13 / 04 / 23
 */

#include "jury_list.h"
#include "participant_list.h"
#include "string.h"

void createEmptyListJ(tListJ* L)
{
    L -> lastpos = NULLJ;
}

tPosJ findPositionJ(tJuryName nombre, tListJ L)
{
    tPosJ p;
    for(p = 0; p <= L.lastpos; p++){
        int comparison = strcmp(L.data[p].juryName, nombre);
        if(comparison >= 0){
            return p;
        }
    }
    return NULLJ;
}

bool insertItemJ(tItemJ d, tListJ* L)
{
    if(L->lastpos == MAX-1){
        return false;  //If the last position is the maximum it doesn't let insert an item
    }
    else{
        L->lastpos++; //Increase the position of the last valid number of the list
        if(L->lastpos == NULLJ+1){ //If the list is empty, inserts the value as its first and only
            L->data[L->lastpos] = d;
        }
        else{
            tPosJ i;
            for(i = L->lastpos; i>0 && (strcmp(d.juryName, L->data[i-1].juryName) < 0); i--){ //Move every value from the last position until p to the right to leave place to the new item
                L->data[i] = L->data[i-1];
            }
            L->data[i] = d; //Insert the item in the position
        }
        return true;
    }
}

tItemJ getItemJ(tPosJ p, tListJ L)
{
    return L.data[p];
}

bool isEmptyListJ(tListJ L)
{
    return L.lastpos == NULLJ; //Returns true if lastpos is null (just like when creating an empty list)
}

tPosJ firstJ(tListJ L)
{
    return 0;
}

tPosJ lastJ(tListJ L)
{
    return L.lastpos;
}

tPosJ previousJ(tPosJ p, tListJ L)
{
    return p-1; //It isn't necessary to specify to return NULLJ when p is 0 because NULLJ is already stablished as -1.
}

tPosJ nextJ(tPosJ p, tListJ L)
{
    if(p == L.lastpos){
        return NULLJ;
    }
    return p+1;
}

void updateItemJ(tItemJ d , tPosJ p, tListJ* L)
{
    L->data[p] = d;
}

void deleteAtPositionJ(tPosJ p, tListJ* L)
{
    L->lastpos--; //Reduce the size of the list (valid elements, not garbage)
    for(int i = p; i <= L->lastpos; i++){ //Substitute all the elements from p on by their next one
        L->data[i] = L->data[i+1];
    }
}

tPosJ findItemJ(tJuryName d, tListJ L)
{
    //binary search
    int left = 0, right = L.lastpos;
    while(left <= right){
        int middle = (left + right)/2;
        int comparison = strcmp(L.data[middle].juryName, d);
        if(comparison == 0){
            return middle;
        }
        else if(comparison < 0){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    return NULLJ;
}

bool copyListJ(tListJ L, tListJ* M)
{
    for(tPosJ p = 0; p<=L.lastpos; p++){ //Copies element by element
        M->data[p] = L.data[p];
    }
    M->lastpos = L.lastpos; //Establishes the same lastpos value
    return true;
}

void deleteListJ(tListJ* L)
{
    L->lastpos = NULLJ;
}