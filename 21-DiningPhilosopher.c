#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum)%N
#define RIGHT (phnum+1)%N

int state[N];
int phil[N]={0,1,2,3,4};
sem_t mutex;
sem_t s[N];


void test(int phnum)
{
	if((state[phnum]==HUNGRY) && (state[LEFT]!=EATING) && (state[RIGHT]!=EATING))
	{
		state[phnum]=EATING;
		sleep(2);
		printf("philosopher %d takes fork %d and %d\n",phnum,LEFT,RIGHT);
		printf("Philosopher %d is eating!!\n",phnum);
		sem_post(&s[phnum]);
	}

}

void takeFork(int phnum)
{
	sem_wait(&mutex);
	state[phnum]=HUNGRY;
	printf("Philosopher %d is hungry!!\n",phnum);
	test(phnum);
	sem_post(&mutex);
	sem_wait(&s[phnum]);
	sleep(1);

}

void putDown(int phnum)
{
	sem_wait(&mutex);
	state[phnum]=THINKING;
	printf("Philosopher %d has put down %d and %d\n",phnum,LEFT,RIGHT);
	printf("Philosopher %d is now thinking!!\n",phnum);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void * philosopher(void *num)
{
	while(1)
	{
		int *i=num;
		sleep(1);
		takeFork(*i);
		sleep(1);
		putDown(*i);
	}
}

int main()
{
	int i;
	pthread_t tid[N];
  
	sem_init(&mutex,0,1);
  
	for(i=0;i<N;i++)
	  sem_init(&s[i],0,0);
  
	for(i=0;i<N;i++){
		pthread_create(&tid[i],NULL,philosopher,&phil[i]);
		printf("Philosopher %d is thinking!!\n",i);
	}
  
	for(i=0;i<N;i++)
	  pthread_join(tid[i],NULL);

	return 0;
}

