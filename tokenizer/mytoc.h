#ifndef mytoc		// prevent multiple inclusion
#define mytoc


char ** tokenize(char *str, char delim);

char * headAfter(char *str, char delim);

int countToks(char *str, char delim);

int countTokLen(char *str, char delim);


#endif 
