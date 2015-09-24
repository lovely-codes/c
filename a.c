#include<stdio.h>

void helloworld(){
	printf("this is hello world function \n");
}

void add_test_real(void (*fn_name) () ) {
	fn_name();
}

int main(){
	printf("Hello world... \n");
	add_test_real(helloworld);
	return 0;
}
