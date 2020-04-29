#define _GNU_SOURCE
#include "qsort.h"
#include "header.h"
#include "scheduling.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>



static int cur_time;
static int t_last;
static int running;
static int fin_count;//finish count

int next_process(int n,struct Process *process){
	//printf("hello\n");
	int ret = -1;
	if(running == -1){
		for(int i = 0;i < n;i++){
			if(process[i].pid != -1 &&process[i].execT>0){
				ret = i;
				break;
			}
		}
	}
	else if((cur_time- t_last)%500==0){
		for(int i = 0;i < n;i++){

			if(i != running){
				ret = i;
				if(process[ret].pid == -1||process[ret].execT==0){
					ret = (i+1)%n;
				}
			}
		}
		ret = running;
	}
	else{
		ret = running;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	struct Process *process;
	process = (struct Process *)malloc(n*sizeof(struct Process));	
	for(int i  = 0;i <n;i++ ){
		scanf("%s",process[i].name);
		scanf("%d",&process[i].readyT);
		scanf("%d",&process[i].execT);
	}
	qsort(process,n,sizeof(struct Process),cmp);
	for(int i = 0;i < n;i++){
		process[i].pid = -1;
	}
	assign_cpu(getpid(),0);
	wakeup_proc(getpid());

	//initialize scheduler
	cur_time=0;
	running=-1;
	fin_count =0;
	while(1){

		//check whether a running process finished
		if(running!=-1&&process[running].execT==0){
			waitpid(process[running].pid,NULL,0);
			printf("%s %d\n",process[running].name,process[running].pid);
			fflush(stdout);
			running = -1;
			fin_count++;
			//all finished
			if(fin_count== n){
				break;
			}
		}

		//check any process is ready
		for(int i = 0;i <n;i++ ){
			if(process[i].readyT == cur_time){
				process[i].pid = exec_proc(process[i]);
				block_proc(process[i].pid);

			}
		}

		//select next runninf process
		int next_p = next_process(n,process);
		if(next_p!=-1){
			//context switch
			if(running != next_p){
				wakeup_proc(process[next_p].pid);
				block_proc(process[running].pid);
				
				if(process[running].execT != 0){
					process[running].readyT = cur_time+1;
					qsort(process,n,sizeof(struct Process),cmp);
				}
				running = next_p;
				t_last = cur_time;
			}
		}
		volatile unsigned long j;
		for(j = 0;j < 1000000UL;j++);
		if(running != -1){
			process[running].execT--;
		}	
		cur_time++;
	}

	exit(0);
}
