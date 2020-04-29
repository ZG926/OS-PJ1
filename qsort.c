#include "header.h"
int cmp(const void *a,const void *b){
	return ((struct Process*)a)->readyT - ((struct Process*)b)->readyT;
}

//int main(){
//	return 0;
//}