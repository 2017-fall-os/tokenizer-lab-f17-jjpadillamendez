#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "assert2.h"
#include "mytoc.h"
#include "test.h"
#include "strlib2.h"

#define BUFFERLIMIT 102

int main(){
	
    char **tokenVec;
    char *str;
    char delim;
        
    printf("\n=======================================================\n");
    printf("=====         Lab Assignment I: Toc Program       =====\n");
    printf("=======================================================\n");
    printf("== Instructions:\n");
    printf("===  Enter a string at the prompt to break it in tokens\n");
    printf("===  Enter [exit] to quit the program\n");
    printf("===  Default delimit is a space [' ']\n");
    printf("=======\n");
                                                        
    delim = askForDelimit();                                 // Ask for a special delimit
    
    printf(";start\n");
    while(1){
        str = getUserInput();

        tokenVec = tokenize(str,delim);                      // Generate token vector
    
        printf("Token Vector => \n");
 	
        for(int i=0; tokenVec[i]; i++){
             printf("\t\t: %s \n", tokenVec[i]);             // Print token vector 
        }
        free(str);                                           // Free memory for next loop
        freeVector(tokenVec); 
        printf(";next\n");
        
    }
       
    return 0;
	
}
char *getUserInput(){    
    char *str = (char *)malloc(BUFFERLIMIT);
    int len;
    
    write(1, "$ ", 2);                           // Read user input
    len = read(0, str, BUFFERLIMIT);
    assert2(len < BUFFERLIMIT, "Limit of string length was overpassed");              
    
    rmCharIn(str, '\n');                         // Remove new line char in the inputed string
    str = (char *)realloc(str, len);
    
    if(strcomp(str, "exit"))                     // Check if the user wants to exit
        exit(0);
    
    return str;
    
}
char askForDelimit(){
    char *input;
    char delim = ' ';                            // Default Delimit is an space [' ']
    
    while(1){
        printf("Optional: Would you like to set a special delimit (y,n)? \n");
        input = getUserInput();
        
        if(strlen2(input) == 1){          
            if(input[0] == 'y'){
                free(input);                        // Free input to ask again for a user input
                printf("Enter Delimit: \n");
                input = getUserInput();            
                if(strlen2(input) == 1){                   // Ask for a single char as Delimit
                    delim = input[0];
                    break;
                }
            }
            else if(input[0] == 'n'){
                break;
            }
        }
        free(input);                                // Input was not correct, then ask again
    }
    free(input);                                    // input pointer will not be used again
    return delim;
    
}
void freeVector(char **tokenVec){
    for(int i=0; tokenVec[i] != '\0'; i++){
        free(tokenVec[i]);
    }
    free(tokenVec);
    
}
