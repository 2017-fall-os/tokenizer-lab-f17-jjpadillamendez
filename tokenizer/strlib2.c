#include "strlib2.h"

int strlen2(char *str){
    char *tmpstr = str;
    while(*tmpstr != '\0')
        tmpstr++;
    return (tmpstr - str);
    
}
void rmCharIn(char *str, char chToRm){
    int i=0;
    while(str[i] != chToRm && str[i] != '\0')
        i++;
    str[i] = 0;
    
}
int strcomp(char *str, char *str2){
    char areEqual = 1;
    if(strlen2(str) == strlen2(str2)){
        char *tmpstr = str;
        char *tmpstr2 = str2;
        while(*tmpstr != '\0'){
            if(*tmpstr != *tmpstr2)
                areEqual = 0;
            tmpstr++;
            tmpstr2++;
        }
        
    }else{
        areEqual = 0;
    }
    return areEqual;
    
}
