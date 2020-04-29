#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
struct Process{
		char name[32];
		int readyT;
		int execT;
		pid_t pid;
};