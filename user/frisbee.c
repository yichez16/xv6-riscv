#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/thread.h"

struct lock_t *lock;
void* worker();
static int output =0;
static int numofthread;
static int passnum;
static int workpid=0;

typedef struct arg_struct {
  int *numPasses;
  struct lock_t *lock;
} lol_struct;

void* worker(void *arg){
    int pidnum = (int)arg;
	while(output < passnum)
	{
		lock_acquire(lock);
		if(output==passnum)
			break;
		if(pidnum==workpid)
		{
			output++;
			printf("pass number no:%d is thread %d is passing the token to ",output,pidnum);
			workpid++;
			if(workpid ==  numofthread)// because thread num is start from 0 
				workpid = 0 ;	
			printf(" %d\n",workpid);
			lock_release(lock);
		 	sleep(1);
		}
		else
		{
			//printf(1,"this is not a correct workpid\n");
			lock_release(lock);
			sleep(1);
		}
	}    
}

int main(int argc, char *argv[]) 
{
    int numofthread =atoi(argv[1]);
    int passnum = atoi(argv[2]);
    lock_init(lock);
    for(int i = 0;i < numofthread; i++)
	{
		thread_create(worker,(void *)i);
	}

  exit(0);
}

