#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mytoc.h"

#define BUFF_LIMIT 100
#define DELIM_LIMIT 1

void freeMemory(char *str, char *delim, char **tokedVec){
    int index = 0;
    while(tokedVec[index]){
        free(tokedVec[index]);
        index++;
    }
    free(str);
    free(delim);
    free(tokedVec);
    
}
void readInput(char *buffer, int size){
    
    
}
int main(){
	
    int index;
    char **tokedVec;
        
    printf("\n=====================================================\n");
    printf("====       Lab Assignment I: My Toc Program       ===\n");
    printf("=====================================================\n\n");
    
    printf("Enter [Crtl + d] to exit the program\n");
    while(1){
        char str[BUFF_LIMIT], delim[DELIM_LIMIT];
        printf("Enter String: ");
        readInput(str, BUFF_LIMIT);
        printf("Enter Delimer: ");
        readInput(delim, DELIM_LIMIT);
        
        tokedVec = tokenize(str,*delim);
        
        printf("\nGiven String: %s\n", str);
        printf("Token Vector => \n");
	

        index = 0;
        while(tokedVec[index]){
            printf("\t\t: %s \n", tokedVec[index]);
            index++;
        }
        printf(":");
        //freeMemory(str, delim, tokedVec);
           
        
    }
    return 0;
	
}
