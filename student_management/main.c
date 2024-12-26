#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_manage.h"

int main() {
    char user_input[10];

    while (1) {
        printf("Enter your option:\n\n");
        printf("1. Manage a student's information\n");
        printf("2. Manage a student's payment\n");
        printf("3. Reserved\n");
        printf("Q. Quit\n\n");
        
        printf("Input: ");
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        if (strcmp(user_input, "1") == 0) {
            manage_student_information();
        } 
        else if (strcmp(user_input, "2") == 0) {
            reserved_option();
        } 
        else if (strcmp(user_input, "3") == 0) {
            reserved_option();
        } 
        else if (strcmp(user_input, "Q") == 0 || strcmp(user_input, "q") == 0) {
            printf("Exiting the program.\n");
            break;
        } 
        else {
            printf("Invalid option. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
