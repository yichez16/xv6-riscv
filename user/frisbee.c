#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/thread.h"



int Total_threads;
int passnum;





int main( int argc , char * argv [])
{
    if(argc >= 2)
    {
        Total_threads = atoi(argv[1]);
        passnum = atoi(argv[2]);
    }
    printf("%d threads, %d pass", Total_threads, pass);
}