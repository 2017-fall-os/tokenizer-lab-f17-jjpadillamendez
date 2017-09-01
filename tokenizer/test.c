#include <stdio.h>
#include "mytoc.h"

int main(){
	
	//char *str = "Jesus Jose                      neirvbiroiroiboPadilla Mendez Lalo         ";
	char *str = "Jesus         Jose Padilla Mendez";
	printf(str);

	printf("\n");
	char **tokedstr = tokenize(str,' ');
	
	int i=0;
	while(tokedstr[i]){
		printf("%s \n", tokedstr[i]);
		i++;
	}
	
}