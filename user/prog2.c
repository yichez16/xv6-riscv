#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int FUNCTION_SETS_NUMBER_OF_TICKETS(int a)
{

  return a/3;

}

int main(int argc,  char *argv[])
{


     int n = FUNCTION_SETS_NUMBER_OF_TICKETS(60); // write your own function here
     allocateTickets(n);
     printf("Prog2.c has been allocated %d Tickets\n",n);
     int i,k;
     const int loop=50000; // adjust this parameter depending on your system speed
     for(i=0;i<loop;i++)
     {
     asm("nop"); // to prevent the compiler from optimizing the for-loop
     for(k=0;k<loop;k++)
     {
     asm("nop");
     }
     }
     //printf("%s is performing a system call\n",argv[0]);
     sched_statistics(n,2); // your syscall
     exit(0);

     
}