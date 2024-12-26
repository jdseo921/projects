#include "std_manage.h"
#include <stdio.h>
#include <string.h>

void manage_student_information() {
    char user_input[10];

    printf("Enter your option:\n\n");
    printf("1. View all student's information\n");
    printf("2. Add a new student\n");
    printf("3. Delete a student\n");
    printf("4. Modify a student's information\n");
    printf("5. Modify a student's payment(Reserved)\n");
    printf("B. Back\n");
    printf("R. Return\n");

    printf("\nInput: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0';

    if (strcmp(user_input, "1") == 0) {
        view_students();
    } 
    else if (strcmp(user_input, "2") == 0) {
        add_student();
    } 
    else if (strcmp(user_input, "3") == 0) {
        reserved_option();
    } 
    else if (strcmp(user_input, "Q") == 0 || strcmp(user_input, "q") == 0) {
        printf("Exiting the program.\n");
        return;
    } 
    else if (strcmp(user_input, "B") == 0 || strcmp(user_input, "b") == 0) {
        printf("Return.\n");
        return;
    } 
    else {
        printf("Invalid option. Please try again.\n");
    }
}

void view_students() {
    FILE *file = fopen("students.csv", "r");

    if (file == NULL) {
        printf("\nError opening file\n");
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void add_student() {
    Student new_student;
    char num[20];
    int test;

    printf("\nEnter the new student details:\n");

    printf("Last Name: ");
    fgets(new_student.last_name, sizeof(new_student.last_name), stdin);
    new_student.last_name[strcspn(new_student.last_name, "\n")] = '\0';

    printf("First Name: ");
    fgets(new_student.first_name, sizeof(new_student.first_name), stdin);
    new_student.first_name[strcspn(new_student.first_name, "\n")] = '\0'; 

    printf("Email: ");
    fgets(new_student.email, sizeof(new_student.email), stdin);
    new_student.email[strcspn(new_student.email, "\n")] = '\0';

    printf("Student ID: ");
    fgets(num, sizeof(num), stdin);
    sscanf(num, "%d", &new_student.id);

    printf("Contact: ");
    fgets(new_student.contact, sizeof(new_student.contact), stdin);
    new_student.contact[strcspn(new_student.contact, "\n")] = '\0';

    FILE *file = fopen("students.csv", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%s,%d\n", new_student.last_name, new_student.first_name, new_student.email, new_student.contact, new_student.id);
    fclose(file);

    printf("\nStudent added:\n");
    printf("Last Name: %s\n", new_student.last_name);
    printf("First Name: %s\n", new_student.first_name);
    printf("Email: %s\n", new_student.email);
    printf("ID: %d\n", new_student.id);
    printf("Contact: %s\n", new_student.contact);
}

void delete_student() {
    int id;
    printf("\nEnter ID of the student to delete: ");
    scanf("%d", &id);

    FILE *file = fopen("students.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    FILE *temp_file = fopen("temp.csv", "w");
    if (temp_file == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return -1;
    }

    char line[1024];
    int student_found = 0;

    while (fgets(line, sizeof(line), "students.csv") != NULL) {
        char *token = strtok(line, ",");
        int column_count = 1;
        while (token != NULL) {
            if (column_count == 4) {
                if (strcmp(token, id) == 0) {
                    break;
                }
            }
            token = strtok(NULL, ",");
            column_count++;
        }
        if (token == NULL || column_count != 4 || strcmp(token, id) != 0) {
            fputs(line, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (remove("students.csv") != 0) {
        perror("Error removing the original file");
        return -1;
    }

    if (rename("temp.csv", "students.csv") != 0) {
        perror("Error renaming the temporary file");
        return -1;
    }

    printf("Student with ID %s has been deleted.\n", id);
    return 0;
}

void modify_student() {

}

void modify_student_payment() {

}

void manage_student_payment() {

}

void back() {

}

void ret() {
    
}

void reserved_option() {
    printf("Reserved option - currently not available.");
}