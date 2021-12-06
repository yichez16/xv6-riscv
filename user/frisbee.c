#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/thread.h"

uint num_threads;
uint num_pass;
struct frisbee
{
    uint token;
    uint pass_value;
    struct lock_t sl;
}spin;


struct data
{
   int tid;
};


void* pass_frisbee(void* arg) {
    struct data *fdata = (struct data *)arg;
    int thid = fdata->tid;
    while(spin.pass_value < num_pass){
        lock_acquire(spin.sl);
        if(thid == spin.token && spin.pass_value < num_pass){
            spin.pass_value++;
            spin.token++;
            if(spin.token == num_threads){
                spin.token = 0;
            }
            printf("Pass number no: %d, Thread %d is passing the token to thread %d\n", spin.pass_value, thid,  spin.token);
        }
        lock_release(spin.sl);
    }
    return 0;
}

int main(int argc, char *argv[]) {
  struct data *tdata; 
  num_threads = atoi(argv[1]);
  num_pass = atoi(argv[2]);
  spin.token  = 0;
  spin.pass_value = 0;
  lock_init(spin.sl);
  tdata = malloc(sizeof(struct data) * num_threads);
  for(int i = 0; i < num_threads; i++){
      tdata[i].tid = i;
  }

  for(int i = 0; i < num_threads; i++){
      thread_create((void *)pass_frisbee, (void *)&tdata[i]);
  }
  printf("Simulation of Frisbee game has finished, %d rounds were played in total! ", num_pass);  

  return 0;
}
