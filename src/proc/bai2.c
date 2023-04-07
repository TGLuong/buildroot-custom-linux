#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include "proc.h"

sem_t mutex;
struct proc_info *list_proc = NULL;

void *thread_handler_1(void *arg)
{
    while (1)
    {
        sem_wait(&mutex);
        free_proc(&list_proc);
        get_proc(&list_proc);
        sem_post(&mutex);
        sleep(1);
    }
}

void *thread_handler_2(void *arg)
{
    while (1)
    {
        sem_wait(&mutex);
        system("clear");
        for_each_proc(proc, list_proc) {
            printf("PROCESS_ID: %10d | PROCESS_NAME: %s\n", proc->pid, proc->name);
        }
        sem_post(&mutex);
        sleep(1);
    }
}

int main()
{
    sem_init(&mutex, 0, 1);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_handler_1, NULL);
    pthread_create(&t2, NULL, thread_handler_2, NULL);

    while (1) {

    }
    return 0;
}