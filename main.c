#include <stdio.h>
#include <stdlib.h>
#include "appartement.h"
#define N 300

// error 1 = given file is not exist in the current directory
int main()
{


    char fileName[50];
    //getting file name from user
    printf("enter the filename \n");
    scanf("%s",fileName);
    strcat(fileName,".txt");

    //printing file name
    printf("file name is %s \n",fileName);

    //function to create data


   // data_creator(fileName,N);


    appartements* head=NULL;
    appartements* rear=NULL;
    printf("address of head %d main \n",&head);
    create_linked_list(&head,&rear,fileName);
    print_linked_list(head);


    find_best_appartement(head,30,30,25,15,N);
    printf("head pointing address %d main2 \n",head);
    printf("head-> previous = %d",head->previous);


}


