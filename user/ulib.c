#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#define PGSIZE 4096




// thread library
void lock_init(lock_t *lock) {
  lock->locked = 0;
}

void lock_acquire(lock_t *lock) {
  while(__sync_lock_test_and_set(&(lock->locked), 1) != 0);
}

void lock_release(lock_t *lock) {
  __sync_lock_test_and_set(&(lock->locked), 0);
}
// void lock_init(struct lock_t *lk, char *name)
// {
//   lk->name = name;
//   lk->locked = 0;
//   lk->cpu = 0;
// }


// void lock_acquire(struct lock_t *lk)
// {
//   push_off(); // disable interrupts to avoid deadlock.
//   if(holdingByitself(lk)) panic("acquire");
//   while(__sync_lock_test_and_set(&lk->locked, 1) != 0);
//   __sync_synchronize();
//   lk->cpu = mycpu();
// }


// void lock_release(struct lock_t *lk)
// {

//   if(!holdingByitself(lk))panic("release");
//   lk->cpu = 0;
//   __sync_synchronize();
//   __sync_lock_release(&lk->locked);

//   pop_off();
// }

// int holdingByitself(struct lock_t *lk)
// {
//   int r;
//   r = (lk->locked && lk->cpu == mycpu());
//   return r;
// }


int thread_create(void*(start_routine)(void*), void *arg) {
  void *stack = malloc(2 * PGSIZE);

  // if((uint)stack % PGSIZE)
	// stack = stack + (PGSIZE - (uint)stack % PGSIZE);
  
  int size = 8;  // arg is a pointer which is 8 bytes in riscv64. 
  int tid = clone(stack, size);

  if (tid < 0) {
      printf("Clone failed\n");
      return 0;
  }

  return 0;
}






char*
strcpy(char *s, const char *t)
{
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
    ;
  return os;
}

int
strcmp(const char *p, const char *q)
{
  while(*p && *p == *q)
    p++, q++;
  return (uchar)*p - (uchar)*q;
}

uint
strlen(const char *s)
{
  int n;

  for(n = 0; s[n]; n++)
    ;
  return n;
}

void*
memset(void *dst, int c, uint n)
{
  char *cdst = (char *) dst;
  int i;
  for(i = 0; i < n; i++){
    cdst[i] = c;
  }
  return dst;
}

char*
strchr(const char *s, char c)
{
  for(; *s; s++)
    if(*s == c)
      return (char*)s;
  return 0;
}

char*
gets(char *buf, int max)
{
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    cc = read(0, &c, 1);
    if(cc < 1)
      break;
    buf[i++] = c;
    if(c == '\n' || c == '\r')
      break;
  }
  buf[i] = '\0';
  return buf;
}

int
stat(const char *n, struct stat *st)
{
  int fd;
  int r;

  fd = open(n, O_RDONLY);
  if(fd < 0)
    return -1;
  r = fstat(fd, st);
  close(fd);
  return r;
}

int
atoi(const char *s)
{
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
    n = n*10 + *s++ - '0';
  return n;
}

void*
memmove(void *vdst, const void *vsrc, int n)
{
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  if (src > dst) {
    while(n-- > 0)
      *dst++ = *src++;
  } else {
    dst += n;
    src += n;
    while(n-- > 0)
      *--dst = *--src;
  }
  return vdst;
}

int
memcmp(const void *s1, const void *s2, uint n)
{
  const char *p1 = s1, *p2 = s2;
  while (n-- > 0) {
    if (*p1 != *p2) {
      return *p1 - *p2;
    }
    p1++;
    p2++;
  }
  return 0;
}

void *
memcpy(void *dst, const void *src, uint n)
{
  return memmove(dst, src, n);
}
