#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"




int main(int argc,  char *argv[])
{

    int Total_threads = 0;
    int pass = 0;
    if (argc >= 2) {
        Total_threads = atoi(argv[1]);
        pass = atoi(argv[2]);
    }
    printf("%d threads, %d pass", Total_threads, pass);

    // lock_init(&lock);

    // for(int i = 0; i < Total_threads; i++){
    //     // thread_create((void*)player, (void*)&i);
    //     // sleep(10);
    // }

    exit(0);

     
}
