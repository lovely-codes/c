#include <stdio.h>

typedef int* ilist;

struct sdi {
	int len;
	int items[];
};

ilist newilit(int l) {
	struct sdi *ptr =  malloc(sizeof(struct sdi) + sizeof(int) * l);
	ptr->len = l;
	while(l--) {
		ptr->items[l]	= l;
	}
	ptr->items[0] = 0;
	return (ilist)ptr->items;
}

int ilist_len(ilist p){
	struct sdi *m = (void*) p - sizeof(struct sdi);
	return m->len;
}

int main(){
	ilist my_list = newilit(10);
	int pos = 0;
	for( ; pos < 10 ; pos++){
		printf("%d\n",my_list[pos]);	
	}
	printf("Len is %d \n ",ilist_len(my_list));
	return 0;
}
