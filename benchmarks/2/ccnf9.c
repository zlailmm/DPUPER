/*  */
extern void abort(void);
void reach_error(){}
void assume_abort_if_not(int cond) {
    if(!cond) {abort();}
}

#include <pthread.h>
#include <assert.h>

int a=0;
int b=0;
int c=0;
int d=0;

void *t1(void *arg){a=1;}
void *t2(void *arg){a=2;}
void *t3(void *arg){b=1;}
void *t4(void *arg){b=2;}
void *t5(void *arg){c=1;}
void *t6(void *arg){c=2;}
void *t7(void *arg){d=1;}
void *t8(void *arg){d=2;}

int main()
{
  pthread_create(id1, NULL, t1, NULL);
  pthread_create(id2, NULL, t2, NULL);
  pthread_create(id3, NULL, t3, NULL);
  pthread_create(id4, NULL, t4, NULL);
  pthread_create(id5, NULL, t5, NULL);
  pthread_create(id6, NULL, t6, NULL);
  pthread_create(id7, NULL, t7, NULL);
  pthread_create(id8, NULL, t8, NULL);
}
