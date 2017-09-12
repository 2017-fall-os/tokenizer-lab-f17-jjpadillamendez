/****************************************************/
/* Lab Assignment 1: Tokenizer   Date: 09/10/2017   */
/* Author: Jesus Padilla    Class: Operating System */
/* Prof: Dr. Freudenthal    TA: Adrian Veliz        */
/* This class implements a user interface used to   */
/* test a tokenizer program.                        */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "assert2.h"
#include "mytoc.h"
#include "test.h"
#include "strlib2.h"

#define BUFFERLIMIT 102                             // Include space for '/n' and '/0'

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
    printf("===  Limit of input string is 100 \n"); 
    printf("=======\n");
                                                        
    delim = askForDelimit();                                // Ask for a specific delimit
    
    printf(";start\n");
    while(1){
        str = getUserInput();                               // Get input string

        tokenVec = tokenize(str,delim);                     // Generate token vector
    
        printf("Token Vector => \n");
 	
        for(int i=0; tokenVec[i]; i++){                      // Print token vector 
             printf("\t\t: %s \n", tokenVec[i]);            
        }
        free(str);                                           // Free memory for next loop
        freeVector(tokenVec); 
        printf(";next\n");
        
    }
       
    return 0;
	
}
/** Returns an string which contains the input of the user
 */
char *getUserInput(){    
    char *str = (char *)malloc(BUFFERLIMIT);
    int len;
    
    write(1, "$ ", 2);                           // Read user input
    len = read(0, str, BUFFERLIMIT);
    assert2(len < BUFFERLIMIT, "Limit of string length was overpassed");              
    
    rmCharIn(str, '\n');                         // Remove new line char, replace it for '\0'
    str = (char *)realloc(str, len);
    
    if(strcomp(str, "exit"))                     // Check if the user wants to exit
        exit(0);
    
    return str;
    
}
/** Returns the delimit to be used by the tokenizer; it asks the user to enter
 *  a specific delimit. If not, the default delimit is an space.
 */
char askForDelimit(){
    char *input;
    char delim = ' ';                            // default delimit is an space [' ']
    
    while(1){
        printf("Optional: Would you like to set a special delimit (y,n)? \n");
        input = getUserInput();
        
        if(strlen2(input) == 1){          
            if(input[0] == 'y'){
                while(1){
                   free(input);                       // Free input to ask again for a user input
                   printf("Enter Delimit: \n"); 
                   input = getUserInput(); 
                   if(strlen2(input) == 1){           // delimer is a single char
                       delim = input[0];
                       break;                         // break inside while loop
                   }
                   printf("Error: Delimit is a single char, please try it again \n");
                }
                break;                                // if inside while was broken then outside while too
            }           
            else if(input[0] == 'n'){
                break;
            }
        }
        free(input);                                
    }
    free(input);                                    // input pointer will not be used again
    return delim;
    
}
/** Free the given vector of strings. First, it frees each string
 *  then the empty vector.
 */
void freeVector(char **tokenVec){
    for(int i=0; tokenVec[i] != '\0'; i++){
        free(tokenVec[i]);
    }
    free(tokenVec);
    
}
