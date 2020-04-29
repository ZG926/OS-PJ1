#include <linux/linkage.h>
#include <linux/kernel.h>

asmlinkage void myprintk(int pid, long start_t,long end_t){
	static const long BASE = 1000000000;
	printk(KERN_INFO "[Project 1] %d %ld.%09ld %ld.%09ld\n",pid,start_t/BASE,start_t%BASE,end_t/BASE,end_t %BASE);
}
