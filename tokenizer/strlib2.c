/****************************************************/
/* Lab Assignment 1: Tokenizer   Date: 09/10/2017   */
/* Author: Jesus Padilla    Class: Operating System */
/* Prof: Dr. Freudenthal    TA: Adrian Veliz        */
/* This class implements a string library, which    */
/* includes useful procedures to manage strings     */
/****************************************************/
#include "strlib2.h"

/* Return the number of characters in the given string
 */
int strlen2(char *str){
    char *tmpstr = str;
    while(*tmpstr != '\0')
        tmpstr++;
    return (tmpstr - str);          // since char is a byte       
    
}

/* Removes chToRm and the tail after it of the given string
 */
void rmCharIn(char *str, char chToRm){
    int i=0;
    while(str[i] != chToRm && str[i] != '\0')
        i++;
    str[i] = 0;
    
}

/* Compares two strings and returns whether they are equal 
 * or not. [equal = 1, not equal = 0]
 */
int strcomp(char *str, char *str2){
    char areEqual = 1;
    if(strlen2(str) == strlen2(str2)){     // To be equal, must be of the same length
        char *tmpstr = str;
        char *tmpstr2 = str2;
        while(*tmpstr != '\0'){
            if(*tmpstr != *tmpstr2)        // Each char and its position must be equal
                areEqual = 0;
            tmpstr++;
            tmpstr2++;
        }
        
    }else{
        areEqual = 0;
    }
    return areEqual;
    
}
