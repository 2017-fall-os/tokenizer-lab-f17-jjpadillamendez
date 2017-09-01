#include "mytoc.h"
#include <stdio.h>
#include <stdlib.h>

char ** mytoc(char *str, char delim){
	int *infotok;
	char *truestr;
	char **tokedstr;

	TokenDetail *tokdetail = rmMultConsToks(str, delim);
		
	infotok = tokdetail->infotok;
	truestr = tokdetail->truestr;

	tokedstr = (char **)malloc(length(infotok) + sumlist(infotok)); 

	int i, j;
	for(i=0; infotok[i] != -1; i++){
		tokedstr[i] = (char *)malloc(infotok[i] + 1); 
		for(j=0; j < infotok[i]; j++){
			tokedstr[i][j] = *truestr;
			truestr++;
		}
		tokedstr[i][j] = '\0';
		
	}
	tokedstr[i] = (char *)malloc(1); 
	tokedstr[i] = 0;

	free(tokdetail);
	return tokedstr;

}
int sumlist(int *infotok){
	int *temp = infotok;
	int tsum = 0;
	while(*temp != -1){
		tsum += *temp;
		temp++;
	}
	return tsum;

}
int length(int *p){
	/*** Returns the length of the given pointer of chars (string) ***/
	int *temp = p;

	while(*temp != -1)					    // getting length of the string
		temp++;

	return (temp - p);				
}
int lengthof(char *str){
/*** Returns the length of the given pointer of chars (string) ***/
	char *tempstr = str;

	while(*tempstr != '\0')					    // getting length of the string
		tempstr++;

	return (tempstr - str);

}
TokenDetail *rmMultConsToks(char *str, char delim){
	char *tempstr, *truestr, istokend; 
	int *infotok; 
	int numtoks, truetoks, toklen, i, j;
	
	tempstr = str;
	while(*tempstr == delim)						//removes delims at the beginning
		tempstr++;

	// counting number of all tokens except single tokens in between chars
	numtoks = 0;
	truetoks = 0;
	istokend = 0;
	for(i=0; tempstr[i] != '\0'; i++){
		if(tempstr[i] == delim){
			for( ; tempstr[i] == delim; i++)
				numtoks++;
			if(tempstr[i] == '\0'){					// avoiding end tokens
				istokend = 1;
				break;
			}
			else
				truetoks++;							// token in between char are valid, while start OR end tokens are not
		}
	}

	if(!istokend)
		truetoks++;

	// building a string without multiple consecutive tokens
	truestr = (char *)malloc(lengthof(str) - numtoks + 1);
	infotok = (int *)malloc(truetoks + 1);
	
	i=0, j=0;
	toklen = 0;
	while(*tempstr != '\0'){
		truestr[i] = *tempstr;
		tempstr++;
		i++;
		toklen++;
		if(*tempstr == delim){
			while(*tempstr == delim)
				tempstr++;
			infotok[j] = toklen;
			toklen = 0;
			j++;
			
			if(*tempstr == '\0')					// avoiding end tokens
				break;
		} 
		
	}
	if(!istokend){
		infotok[j] = toklen;
		j++;
	}

	truestr[i] = '\0';		
	infotok[j] = -1;

	TokenDetail *tokendetail = (TokenDetail *)malloc(sizeof(TokenDetail));
	tokendetail->truestr = truestr;
	tokendetail->infotok = infotok;

	return tokendetail;

}
