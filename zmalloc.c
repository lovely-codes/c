#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PREFIX_SIZE sizeof(size_t)

void *zmalooc(size_t size) {
	void *ptr = malloc(size + PREFIX_SIZE);
	//mac系统下存在malloc_size函数
	printf("REAL SIZE : %d\n",malloc_size(ptr));
	*((size_t *)ptr) = size + PREFIX_SIZE;
	return ptr + PREFIX_SIZE;
}

void zfree(void *ptr) {
	void *realptr = ptr - PREFIX_SIZE;
	free((void*)(ptr - PREFIX_SIZE));
}

int main(int argc,char **argv){
	char *str = (char*) zmalooc(sizeof(char) * 20);
	strcpy(str,"Hello world\n");
	printf("%s\n",str);
	zfree(str);
	return 0;
}
