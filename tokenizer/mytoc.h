#ifndef mytoc		// prevent multiple inclusion
#define mytoc

typedef struct TokenDetaill {
	char *truestr;
	int  *infotok;
} TokenDetail;

int length(int *p);

char ** mytoc(char *str, char delim);

TokenDetail *rmMultConsToks(char *str, char delim);

int lengthof(char *str);

int sumlist(int *infotok);


#endif 
