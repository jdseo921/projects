#ifndef STD_MANAGE_H
#define STD_MANAGE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char last_name[20];
    char first_name[20];
    char email[30];
    int id;
    char contact[20];
} Student;

//Menu 1 and its entries
void manage_student_information();
void view_students();
void add_student();
void delete_student();
void modify_student();
void modify_student_payment();

//Menu 2 and its entries
void manage_student_payment();

//Action entries
void back();
void ret();

//Not implemented yet
void reserved_option();

#endif
