#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> 


int checkOperator(char *op) {
    // strcmp returns 0 if the strings are identical
    if (strcmp(op, "+") == 0) {
        printf("We have an addition operator.\n");
        return 1;
    } 
    else if (strcmp(op, "-") == 0) {
        printf("We have a subtraction operator.\n");
        return 1;
    } 
    else if (strcmp(op, "*") == 0) {
        printf("We have a multiplication operator.\n");
        return 1;
    } 
    else if (strcmp(op, "/") == 0) {
        printf("We have a division operator.\n");
        return 1;
    } 
    else {
        // This handles cases like "+q", "abc", or empty input
        printf("Invalid operator: '%s'. Please enter only +, -, *, or /.\n", op);
        return 0;
    }
}


void inspectString(const char *str) {
    int i = 0;
    printf("Inspecting string memory:\n");
    
    // Continue until we reach the null terminator
    while (1) {
        char c = str[i];
        printf("Index %d: ", i);
        if (c == '\0') {
            printf("'\\0' (Null Character)\n");
            break; // Stop at null terminator
        } else if (c == '\n') {
            printf("'\\n' (Newline)\n");
        } else {
            printf("'%c' (ASCII %d)\n", c, (int)c);
        }
        
        i++;
    }
}


void runCalculation(char *op, float *num1, float *num2, float *res) {
    if (strcmp(op, "+") == 0) {
        *res = *num1 + *num2;
    }
    if(strcmp(op, "-") == 0) {
       *res = *num1 - *num2; 
    }
     if(strcmp(op, "/") == 0) {
       *res = *num1 / *num2; 
    }

     if(strcmp(op, "*") == 0) {
       *res = *num1 * *num2; 
    }
}

int main() {
    char *welcomeMessage = "=== Simple C Calculator ===";
    printf("%s \n", welcomeMessage);
    bool loop_on = true;
    
    while(loop_on == true) {
        char op[3];
        char numBuffer[50];
        float num1;
        float num2;
        float res;
        printf("Please enter an operator:   ");
        // printf("Please enter an operator:   %s ", op);
        if (fgets(op, sizeof(op), stdin) != NULL) {
            // Remove the trailing newline character, if present
            op[strcspn(op, "\n")] = '\0';
        }

        int opCheck = checkOperator(op);
        if(opCheck == 0) break;

        // Lets get the two numbers
        printf("Please enter the two numbers with a whitespace between them:  ");
        if(fgets(numBuffer, sizeof(numBuffer), stdin) != NULL) {
            op[strcspn(op, "\n")] = '\0';

            int matches = sscanf(numBuffer, "%f %f", &num1, &num2);
            
            if(matches == 2) {
                if(num2 == 0 && (strcmp(op, "/") == 0)) {
                    printf("We can't divide a number by 0. Please try again. \n");
                    break;
                }
                runCalculation(op, &num1, &num2, &res);
                printf("The result for %f %s %f is %f\n", num1, op, num2, res);
            }
            else {
                printf("Please enter just two numbers \n");
                break;
            }
        }



        printf("Do you want to continue Y/N ?  ");
        char continueCalc[4];
        fgets(continueCalc, sizeof(continueCalc), stdin);
        continueCalc[strcspn(continueCalc, "\n")] = '\0';
        // 2. Convert the entire input to lowercase
        for (int i = 0; continueCalc[i] != '\0'; i++) {
            continueCalc[i] = tolower(continueCalc[i]);
        }
        if (strcmp(continueCalc, "y") == 0) {
            // Reset arrays to all zeros
            char op[3] = {0};
            char numBuffer[50] = {0};
            float num1 = 0.0f;
            float num2 = 0.0f;
            float res = 0.0f;
            continue;
        }
        else {
            printf("Thanks for using this calculator \n");
            break;
        }
    }
}