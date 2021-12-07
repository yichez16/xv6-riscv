
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"

void lock_init(lock_t *l) {
  l->held = 0;

}
void lock_acquire(lock_t *l) {
  while(__sync_lock_test_and_set(&l->held, 1) != 0)
    ;
}
void lock_release(lock_t *l) {
//   if(l->held){
//     __sync_lock_test_and_set(&l->held, 0);
//   }
    l->held = 0;
}

void *thread_create(void* start_routine(void*), void* arg) {
  void *t_stack = malloc(8192);
  int tid = clone(t_stack, 8192);

  if (tid == 0){
    (start_routine)(arg);
    return 0;
  }
  texit();
  return 0;
}