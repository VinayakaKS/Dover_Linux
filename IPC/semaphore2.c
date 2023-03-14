#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<semaphore.h>

int main(){

    sem_t *sem;
    int sval;
    sem = sem_open("/sem1",O_CREAT|O_RDWR,0660,1);


    if(sem ==SEM_FAILED){
        perror("P2 Sem open failed\n");
        return -1;
    }
    else
        printf("P2 Sem open success\n");

    sem_getvalue(sem, &sval);
    printf("P2 Sem value initially - %d\n",sval);

    sem_wait(sem);
    sem_getvalue(sem, &sval);
    printf("P2 Sem value after wait - %d\n",sval);

    printf("Process 2 : critical section executing\n");
    sleep(15);

    sem_post(sem);
    sem_getvalue(sem, &sval);
    printf("P2 Sem value after post - %d\n",sval);
    sem_unlink("/sem1");
    return 0;
}