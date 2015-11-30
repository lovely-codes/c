#include <stdio.h>

int main(){
	char *m = "Hello world";
	char *n = m;
	int pi[] = {1,2,3,5,0};
	int *pscan = pi;

	while(1) {
		if(*pscan){
			printf("%d\n",*pscan);	
		} else {
			break;	
		}
		pscan++;
	}

	while(1){
		if(*n){
			printf("%c\n",*n);	
		} else {
			break;	
		}
		n++;
	}

	return 0;
}
