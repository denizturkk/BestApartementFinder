/*
 * appartement.h
 *
 *  Created on: 14/08/2021

 *      Author:Deniz Turk
 */

#ifndef appartement_h_
#define appartement_h_

typedef struct appartements
{
    int apNo;
    int pool;
    int gym;
    int school;
    int neighbor;
    struct  appartements *previous;
    struct appartements  *next;

}appartements;

 void create_linked_list(struct appartements** head , struct appartements** rear,char fileName[]);
 void add_appartements_to_linkedlist(struct appartements** head,struct appartements **rear,int apNo,int pool,int gym,int school,int neighbor);
 void print_linked_list(struct appartements* head);
 void data_creator(char fileName[], int numberOfAppartements);
 void find_best_appartement(appartements* head,int pooli,int gymi,int schooli, int neighbori,const N);





#endif
