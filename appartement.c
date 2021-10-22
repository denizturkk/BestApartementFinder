/*
 * appartement.c
 *
 *  Created on: 14/08/2021

 *      Author:Deniz Turk
 */


#include<stdio.h>
#include<stdlib.h>
#include "appartement.h"

void create_linked_list(struct appartements** head , struct appartements** rear,char fileName[])
{

    FILE *fptr;
    fptr =fopen(fileName,"r");

    int apNo;
    int pool;
    int gym;
    int school;
    int neighbor;

    if(fptr == NULL)
    {
        printf(" error code 1 \n ");
        exit(1);
    }

    //printf("address of head create_linked_list %d pointing address %d  \n",&(*head),*head);

    int counter=0;
    while(!feof(fptr))
    {


        if (counter%5==0)
        {
           fscanf(fptr,"%d,",&apNo);

        }

        else if (counter%5==1)
        fscanf(fptr,"%d,",&pool);

        else if (counter%5==2)
        fscanf(fptr,"%d,",&gym);

        else if (counter%5==3)
        fscanf(fptr,"%d,",&school);

        else if (counter%5==4)
        {
            fscanf(fptr,"%d,",&neighbor);
            add_appartements_to_linkedlist(&(*head),&(*rear),apNo,pool,gym,school,neighbor);


        }
        counter++;
    }

}



void add_appartements_to_linkedlist(struct appartements** head,struct appartements **rear,int apNo,int pool,int gym,int school,int neighbor)
{
    struct appartements* block;


    // printf("address of head add_appartements_to_linkedlist %d pointing address %d \n",&(*head),*head);

    if(*rear==NULL && *head==NULL)
    {
        block =(struct appartements*)malloc(sizeof(struct appartements));
        block->apNo= apNo;
        block->pool= pool;
        block->gym= gym;
        block->school= school;
        block->neighbor= neighbor;
        block->next =NULL;
        block->previous=NULL;
        *head=block;
        *rear=block;
        //printf("address of head  if %d pointing address %d \n",&(*head));
    }

    else
    {
        block =(struct appartements*)malloc(sizeof(struct appartements));
        block->apNo= apNo;
        block->pool= pool;
        block->gym= gym;
        block->school= school;
        block->neighbor= neighbor;

        block->next =NULL;
        block->previous=*rear;
        (*rear)->next =block;
        *rear=block;
    }


}

void print_linked_list(struct appartements* head)
{
    while(head!=NULL)
    {
        printf("apNo:%d   pool:%d  gym :%d  school:%d  neighbor:%d \n",head->apNo,head->pool,head->gym,head->school ,head->neighbor);

        head=head->next;
    }
}

void data_creator(char fileName[], int numberOfAppartements)
{

  FILE* fptr;

  fptr = fopen(fileName,"w");

    for(int i =1 ; i<=numberOfAppartements;i++)
    {
        fprintf(fptr,"%d",i);

        for(int x =0 ; x<4 ;x++)
        {
           fprintf(fptr,",%d",rand()%2);

        }

        if(i!=numberOfAppartements)
        fprintf(fptr,"\n");

    }
        fclose(fptr);
}

//pooli = pool importance
void find_best_appartement(appartements* head,int pooli,int gymi,int schooli, int neighbori,const N)
{

    printf("\n\nfind best apartement head pointing address %d \n\n",head);


    int scores[N][4];
    int score=0;
    int appNoCounter=0;

    appartements* templhead;
    appartements* temprhead;



    while(head!=NULL)
    {
        int leftpCounter=0;
        int rightpCounter=0;

        int leftgCounter=0;
        int rightgCounter=0;

        int leftsCounter=0;
        int rightsCounter=0;

        int leftnCounter=0;
        int rightnCounter=0;

        //printf("address pointing of head, Rhead, Lhead %d %d %d \n",head,temprhead,templhead);

        //-------------------CALCULATIONS FOR POOL---------------------
        templhead=head;
        temprhead = head;

        //The order of loop conditions is very important. In case that second condition comes first
        //the program may will not work as we want. The reason behind this is that when templhead is pointing
        //NULL we cant access the templhead->pool because there is no more node to access.This mean we cant access the
        //unexiste  node's  pool variable.So program will crash if one of the first Node's or last nodes variable is equal to 0 because
        //in this case templhead will point to NULL but the program will search for pool variable and it will crash.
        //this is only one example, there is more case that will crash the program if it's not in true order
        //if the order is true algorithm will not check if templhead->pool beacuse it will allready out the loop.



        while(templhead!=NULL && templhead->pool!=1 )
        {

            templhead=templhead->previous;
            leftpCounter++;

        }



        while( temprhead!=NULL && temprhead->pool!=1 )
        {

            temprhead=temprhead->next;
            rightpCounter++;

        }


        if(leftpCounter>=rightpCounter)
        {
            score+=(rightpCounter*pooli);

        }


        else if(leftpCounter<rightpCounter)
        {
            score+=(leftpCounter*pooli);
        }


        scores[appNoCounter][0]=score;
        score=0;

   //--------- CALCULATIONS FOR GYM------------

        templhead=head;
        temprhead = head;


        while(templhead!=NULL && templhead->gym!=1 )
        {
            templhead=templhead->previous;
            leftgCounter++;
        }


        while(temprhead!=NULL &&  temprhead->gym!=1)
        {
            temprhead=temprhead->next;
            rightgCounter++;

        }

        if(leftgCounter>=rightgCounter)
        {
            score+=(rightgCounter*gymi);
        }

        else if(leftgCounter<rightgCounter)
        {
            score+=(leftgCounter*gymi);
        }

        scores[appNoCounter][1]=score;
        score=0;
        //-------------CALCULATIONS FOR SCHOOL-----------------//
        templhead=head;
        temprhead = head;


        while(templhead!=NULL &&templhead->school!=1)
        {
            templhead=templhead->previous;
            leftsCounter++;


        }

        while(temprhead!=NULL &&  temprhead->school!=1   )
        {
            temprhead=temprhead->next;
            rightsCounter++;


        }

        if(leftsCounter>=rightsCounter)
        {
            score+=(rightsCounter*schooli);
        }

        else if(leftgCounter<rightsCounter)
        {
            score+=(leftsCounter*schooli);
        }

        scores[appNoCounter][2]=score;
        score=0;
    //-------------CALCULATIONS FOR NEIGHBOR   ---------

        templhead=head;
        temprhead = head;

        while(templhead!=NULL && templhead->neighbor!=1  )
        {
            templhead=templhead->previous;
            leftnCounter++;
        }

        while(temprhead!=NULL&&temprhead->neighbor!=1)
        {
            temprhead=temprhead->next;
            rightnCounter++;

        }

        if(leftnCounter>=rightnCounter)
        {
            score+=(rightnCounter*neighbori);
        }

        else if(leftnCounter<rightnCounter)
        {
            score+=(leftnCounter*neighbori);
        }

        scores[appNoCounter][3]=score;
        score=0;

       appNoCounter++;

       head=head->next;
    }

    for(int x =0; x<N ;x++)
    {
        printf("appartement  no:%d score:%d \n",x+1,scores[x][0] +scores[x][1] +scores[x][2] +scores[x][3]);

    }
}

