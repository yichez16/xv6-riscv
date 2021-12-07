struct stat;
struct rtcdate;
//struct for thread lib
struct lock_t {
  uint flag;
};
typedef struct lock_t lock_t;

// system calls
int fork(void);
int exit(int) __attribute__((noreturn));
int wait(int*);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int hello(int); // hello
int lab1(int); // lab1
int sched_statistics(int,int); // lab2
int allocateTickets(int); //lab 2
int clone(void*, int); //lab 3
void *thread_create(void *(*start_routine)(void*), void *);
void lock_init( lock_t*);
void lock_acquire( lock_t*);
void lock_release( lock_t*);
void texit(void) __attribute__((noreturn));


// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...);
void printf(const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
int memcmp(const void *, const void *, uint);
void *memcpy(void *, const void *, uint);





