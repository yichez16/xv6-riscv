struct lock_t {
  uint held;
};


int thread_create(void *(*start_routine)(void*), void *arg);
void lock_init(struct lock_t l);
void lock_acquire(struct lock_t l);
void lock_release(struct lock_t l);



