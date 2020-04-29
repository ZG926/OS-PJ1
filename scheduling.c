#define _GNU_SOURCE
#include <sched.h>
#include "header.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include<errno.h>

int assign_cpu(int pid,int n){
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(n,&mask);
	if(sched_setaffinity(pid,sizeof(mask),&mask)<0){
		fprintf(stderr, "sched_setaffinity\n");
		exit(0);
	}
	return 0;
}

int exec_proc(struct Process process){
	int pid = fork();
	if(pid < 0){
		fprintf(stderr, "exec_proc fork failed\n" );
		perror("exec_proc failed");
		return -1;
	}
	if (pid==0){
		//fprintf(stderr, "child created\n" );
		long start_sec,end_sec;
		char toprint[512];
		start_sec = syscall(334);
		for(int i = 0;i < process.execT;i++){
			volatile unsigned long j;
			for(j = 0;j < 1000000UL;j++);
		}
		end_sec = syscall(334);
		syscall(335,getpid(),start_sec,end_sec);
		exit(0);
	}
	assign_cpu(pid,1);
	return pid;
}

int block_proc(int pid){

	struct sched_param parameter;
	parameter.sched_priority =0;
	int ret = sched_setscheduler(pid,SCHED_IDLE,&parameter);
	if(ret<0){
		fprintf(stderr, "sched_setscheduler failed\n");
	}
	return ret;
}

int wakeup_proc(int pid){
	struct sched_param parameter;
	parameter.sched_priority =0;
	int ret = sched_setscheduler(pid,SCHED_OTHER,&parameter);
	if(ret<0){
		fprintf(stderr, "sched_setscheduler failed\n" );
	}
	return ret;	

}



