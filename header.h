/*======================Header File====================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*======================Structure====================*/

typedef struct st
{
    int rollNo;
    char name[20];
    float marks;
    struct st *next;
} SLL;

/*====================== Function Prototype ====================*/

void stud_add(SLL **);        // 1.
void stud_del(SLL **ptr);     // 2.
void stud_show(SLL *);        // 3.
void stud_mod(SLL **ptr);     // 4.
void save_list(SLL *ptr);     // 5.
void sort_list(SLL **);       // 7.
void stud_delete_all(SLL **); // 8.
void stud_rev(SLL **);        // 9.
int stud_count(SLL *);        // 10.
void search_node(SLL *ptr);   // 11.
