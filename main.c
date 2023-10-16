/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ana Barrera Novas LOGIN 1: ana.barrera@udc.es
 * AUTHOR 2: Javier Carballal Morgade LOGIN 2: javier.carballal.morgade@udc.es
 * GROUP: 6.0
 * DATE: ** / ** / **
 */

#include    <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "jury_list.h"

#define MAX_BUFFER 255


void create(char *commandNumber, char command, char *param1, char *param2, tListJ *ListaJ)
{
    printf("%s %c: jury %s totalvoters %s\n", commandNumber, command, param1, param2);
    tItemJ item; //create a node with the information asked
    tListP ListaP;
    createEmptyListP(&ListaP);
    item.participantList=ListaP;
    strcpy(item.juryName, param1);
    item.totalVoters = atoi(param2);

    if(insertItemJ(item, ListaJ)) { //insert the new node in the list
        printf("* Create: jury %s totalvoters %s\n", param1, param2);
    }else printf("+ Error: Create not possible");
}

void new(char *commandNumber, char command, char *param1, char *param2, char *param3, tListJ *ListaJ)
{
    printf("%s %c: jury %s participant %s location %s\n", commandNumber, command, param1, param2, param3);
    tItemP item2; //create a node with the information of the participant to add

    strcpy(item2.participantName, param2);
    item2.numVotes = 0;
    if(strcmp(param3, "eu")==0){
        item2.EUParticipant=true;
    } else item2.EUParticipant=false;

    tPosJ jurypos = findItemJ(param1, *ListaJ);
    tItemJ juryitem= getItemJ(jurypos, *ListaJ); //save the jury item to update in a variable

    if(findItemP(param2, juryitem.participantList) != NULLP) { //ARREGLAR FALLO CON ESTO, DA ERROR TODO EL RATO
        if (insertItemP(item2,&juryitem.participantList)) { //insert the new item in the jury item (participant list)
            updateItemJ(juryitem, jurypos, ListaJ);
            printf("* New: jury %s participant %s location %s\n", param1, param2, param3);
            break; //YA NO
        }
    }
    printf("+ Error: New not possible\n");
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListJ *ListaJ) {
    printf("********************\n");
    switch (command) {
            case 'C':
                create(commandNumber, command, param1, param2, ListaJ);
                break;
            case 'N':
                new(commandNumber, command, param1, param2, param3, ListaJ);
                break;
            case 'V':
                break;
            case 'D':
                break;
            case 'S':
                break;
            case 'R':
                break;
            case 'W':
                break;
            default:
                break;
    }
}

void readTasks(char *filename, tListJ *ListaJ) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, ListaJ);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "create.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    file_name = "new.txt"; //BORRAR
    tListJ ListaJ;
    createEmptyListJ(&ListaJ);

    readTasks(file_name, &ListaJ);

    return 0;
}
