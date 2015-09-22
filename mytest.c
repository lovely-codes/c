#include<stdio.h>

/* The following lines make up our testing "framework" :) */
static int tests = 0, fails = 0;
#define test(_s) { printf("#%02d ", ++tests); printf("%s\n",_s); }
#define test_cond(_c) if(_c) printf("\033[0;32mPASSED\033[0;0m\n"); else {printf("\033[0;31mFAILED\033[0;0m\n"); fails++;}

int main(){

	int i=0;
	test("Hello fail");
	test_cond(0);
	test("Hello ok");
	test_cond(1);


	printf("\n");
	for(i=0;i<14;i++)printf("+ ");
	printf("TEST RESULT");
	for(i=0;i<14;i++)printf(" +");
	printf("\n");
	if( 0 == fails) {
		printf("ALL PASSED\n");
	} else {
		printf("%d FAILED \n",fails);
	}

	return 0;
}
