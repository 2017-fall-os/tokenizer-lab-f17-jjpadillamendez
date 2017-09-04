#include <stdio.h>
#include <stdlib.h>
#include "mytoc.h"


char ** tokenize(char *str, char delim){
    char **tokenVec;
    char *tmpstr;
    int tokNum, tokLen, entry, index;
    
    if(*str != 0){
        tokNum = countToks(str, delim);                 // Count number of tokens inside the given string
        tokenVec = (char **)calloc(tokNum + 1, sizeof(char *));
        
        tmpstr = headAfter(str, delim);                 // Remove delimers at the begginng 
        entry = 0;                                      // entry refers to the index of the next token to be copied
        while(*tmpstr != '\0'){
            tokLen = countTokLen(tmpstr, delim);        // Count length of the next token to be copied
            if(tokLen > 0){
                tokenVec[entry] = (char *)malloc(tokLen + 1);     // Copy token into the vector of tokens
                for(index=0; index < tokLen; index++){
                    tokenVec[entry][index] = *tmpstr;                   
                    tmpstr++;
                }
                tokenVec[entry][index] = '\0';
                entry++;                                // <- Ready for next possible token
            }else{
                tmpstr++;                                       // Avoid delimers from being copied 
            }
        }
   }
   else{
       tokNum = 0;                                     //Empty string == Empty Vector
       tokenVec = (char **)calloc(1, sizeof(char *));    
   }
   tokenVec[tokNum] = (char *)0;
   
   return tokenVec;
   
}
/**
 * Returns the address of the first char, after removing
 * delim at the beginning of the string.
 */
char * headAfter(char *str, char delim){
    char *tmpstr = str;
    while(*tmpstr == delim)        // avoiding delimers at the beginning of the string
        tmpstr++;
    
    return tmpstr;
    
}
/**
 * Count the number of caracthers until it finds delim OR the end
 * of the string
 */
int countTokLen(char *str, char delim){
    char *tmpstr = str;
    int toklen = 0;
    
    while(*tmpstr != delim && *tmpstr != '\0'){
        toklen++;      
        tmpstr++;        
    }
    
    return toklen;
    
}
/**
 *  Count number of tokens for the given string and delimer
 *  character. In order words, this method counts number of non
 *  -consecutive delim inside the string plus one.
 */
int countToks(char *str, char delim){
    int tokNum = 1;
    char *tmpstr = headAfter(str, delim);   // removes delimers at the begginng, only inbetween counts
    
    while(*tmpstr != '\0'){
        if(*tmpstr == delim){
            tmpstr = headAfter(tmpstr, delim);      // removes consecutive delimers
            
            if(*tmpstr == '\0')                      // avoids delimers at the end of the string
                break;
            
            tokNum++;            
        }
        tmpstr++;
    }
    
    return tokNum;
    
}
