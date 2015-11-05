#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if defined(__APPLE__) 
#include <malloc/malloc.h>
#define PREFIX_SIZE 0
#endif

#ifdef __linux__
#define PREFIX_SIZE sizeof(size_t)
size_t malloc_size(void *ptr) {
	return (size_t) *((size_t*)(ptr - PREFIX_SIZE));
}
#endif


static size_t memory_used = 0 ;

void *zmalooc(size_t size) {
	void *ptr = malloc(size + PREFIX_SIZE);
	*((size_t *)ptr) = size + PREFIX_SIZE;
	return ptr + PREFIX_SIZE;
}

void zfree(void *ptr) {
	void *realptr = ptr - PREFIX_SIZE;
	free((void*)(ptr - PREFIX_SIZE));
}

int main(int argc,char **argv){
	char *str = (char*) zmalooc(sizeof(char) * 20);
	//mac系统下存在malloc_size函数
	printf("REAL SIZE : %ld \n",malloc_size(str));
	strcpy(str,"Hello world\n");
	printf("%s\n",str);
	zfree(str);
	return 0;
}
