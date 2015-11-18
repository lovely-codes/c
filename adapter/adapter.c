#include <stdio.h>

//#define A 
//#define B
//#define C

#ifdef A 
	#include "adapter_a.c"
#else
	#ifdef B
	#include "adapter_b.c"
	#else
	#include "adapter_c.c"
	#endif
#endif

int main(int argc,char** argv){
	adapter_run(argc,argv);
	return 0;
}
