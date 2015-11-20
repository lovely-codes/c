#ifndef __TESTHELP_H
#define __TESTHELP_H

#include <stdlib.h>

#ifndef GREEN_OPEN 
#define GREEN_OPEN "\033[0;32m"
#endif

#ifndef RED_OPEN 
#define RED_OPEN "\033[0;31m"
#endif

#ifndef COLOR_CLOSE 
#define COLOR_CLOSE "\033[0;0m"
#endif

int __failed_tests = 0;
int __test_num = 0;

#define test_cond(descr,_c) do { \
    __test_num++; printf("%d - %s: ", __test_num, descr); \
    if(_c) printf( GREEN_OPEN "PASSED\n" COLOR_CLOSE ); else {printf( RED_OPEN "FAILED %s : %d\n" COLOR_CLOSE , __FILE__ , __LINE__ ); __failed_tests++;} \
} while(0) 

#define test_report() do { \
    printf("\n%d tests, %d passed, %d failed\n", __test_num, \
                    __test_num - __failed_tests, __failed_tests); \
    if (__failed_tests) { \
        printf("=== WARNING === We have failed tests here...\n"); \
        exit(1); \
    } \
} while(0)

#endif
