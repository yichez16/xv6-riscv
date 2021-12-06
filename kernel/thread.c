#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "mmu.h"
#include "thread.h"


int thread_create(void* start_routine(void*), void* arg) {
  void *t_stack = malloc(8192);
  int tid = clone(t_stack, 8192);

  if (tid == 0)
    (start_routine)(arg);
    exit()
}
void lock_init(struct lock_t* l) {
  l->held = 0;

}
void lock_acquire(struct lock_t* l) {
  while(xchg(&l->held, 1) != 0)
    ;
}
void lock_release(struct lock_t* l) {
  if(l->held){
    xchg(&l->held, 0);
  }
}