/* Adapted from: https://svn.sosy-lab.org/software/sv-benchmarks/trunk/c/pthread-atomic/szymanski_true-unreach-call.c */

/* void __VERIFIER_assume(int); */

/* Testcase from Threader's distribution. For details see:
   http://www.model.in.tum.de/~popeea/research/threader
*/
extern void abort(void);
void reach_error(){}


#include <pthread.h>
#include <assert.h>

int flag1 = 0;
int flag2 = 0; // integer flags 
int x; // boolean variable to test mutual exclusion

void *thr1(void * arg) {
  int aux=0;
  flag1 = 1;
  while(flag2 >= 3) {} // while (flag2 >= 3);
  flag1 = 3;
  if (flag2 == 1) {
    flag1 = 2;
    while(flag2 != 4) {} // while (flag2 != 4);
  }
  flag1 = 4;
  while(flag2 >= 2) {} // while (flag2 >= 2);
  // begin critical section
  x = 0;
  if(x > 0){
      reach_error();
      abort();
  }
  // end critical section
  aux=flag2;
  while(2 <= aux && flag2 <= 3) { aux=flag2; } // while (2 <= flag2 && flag2 <= 3);
  flag1 = 0;
}

void *thr2(void * arg) {
  int aux=0;
  flag2 = 1;
  while(flag1 >= 3) {} // while (flag1 >= 3);
  flag2 = 3;
  if (flag1 == 1) {
    flag2 = 2;
    while(flag1 != 4) {} // while (flag1 != 4);
  }
  flag2 = 4;
  while(flag1 >= 2) {} //  while (flag1 >= 2);
  // begin critical section
  x = 1;
  if ( x<1) {
      reach_error();
      abort();
  }
  // end critical section
  aux=flag1;
  while(2 <= aux && flag1 <= 3) { aux=flag1; } // while (2 <= flag1 && flag1 <= 3); 
  flag2 = 0;
}

int main() {
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, NULL, thr1, NULL);
  pthread_create(&t2, NULL, thr2, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}
