#include<stdio.h>
#include<pthread.h>
#define days 40

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long answer = 1;


void* counting_thread(void *arg)
{
	int offset = *(int *) arg;
	for(int i = 0; i < days/4; i++){

		pthread_mutex_lock(&mutex);

		answer = answer*offset;

		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t id1;
	int offset1 = 2;
	pthread_create(&id1,NULL,counting_thread,&offset1);

	pthread_t id2;
	pthread_create(&id2, NULL , counting_thread,&offset1);

	pthread_t id3;
	pthread_create(&id3, NULL , counting_thread,&offset1);

	pthread_t id4;
	pthread_create(&id4, NULL , counting_thread,&offset1);

	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_join(id3, NULL);
	pthread_join(id4, NULL);

	printf("%lld\n",answer/2);
	return 0;
}