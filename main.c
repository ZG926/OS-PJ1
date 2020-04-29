#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <errno.h>
//#include "scheduler.h"
#include "header.h"




int main(int argc, char const *argv[])
{
	char policy[32];
	scanf("%s",policy);
	fflush(stdin);
	if(policy[0]=='F'){
		execlp("./FIFO","./FIFO",NULL);
	}
	else if(policy[0]=='P'){
		execlp("./PSJF","./PSJF",NULL);
	}
	else if(policy[0]=='S'){
		execlp("./SJF","./SJF",NULL);
	}
	else if(policy[0]=='R'){
		execlp("./RR","./RR",NULL);
	}
	else{
		fprintf(stderr, "no such policy\n" );
	}

	//char policy[32];
	

	/*for(int i  = 0;i <n;i++ ){
		//printf("%s\n",policy );
		printf("%s ",process[i].name);
		printf("%d ",process[i].readyT);
		printf("%d\n",process[i].execT);
	}*/


	/*for(int i  = 0;i <n;i++ ){
		//printf("%s\n",policy );
		printf("%s ",process[i].name);
		printf("%d ",process[i].readyT);
		printf("%d\n",process[i].execT);
	}*/
	//startschedule(policy,n,process);
	return 0;
}




