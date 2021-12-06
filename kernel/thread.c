#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "mmu.h"
#include "thread.h"


int thread_create(void *(*start_routine)(void*), void *arg) {
  void *stack = malloc(8192);
  int tid = clone(stack, 8192);

  if (!tid)
    (*start_routine)(arg);
  return tid;
}

void lock_init(struct lock_t *lock) {
  lk->locked = 0;

}
void lock_acquire(struct lock_t *lock) {
  while(xchg(&lock->locked, 1) != 0)
    ;
}
void lock_release(struct lock_t *lock) {
  xchg(&lock->locked, 0);
}