#include <iostream>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

using namespace std;

int main()
{
    sem_t Semafor1;
    sem_t Semafor2;

    int protection = PROT_READ | PROT_WRITE;

    int visibility = MAP_SHARED | MAP_ANONYMOUS;

    int *shmem = (int*)mmap(NULL,1000,protection,visibility,0,0);

    if(shmem == MAP_FAILED)
    {
        cout << "Mapping failed";
        return 1;
    }

    int i=0;
    int pid = fork();
    cout << "start";
    while(i<=1000)
    {
        if (pid == 0)
        {
            int r1 = rand()%2;
            if(r1 == 2)
            {
                int sem_wait(sem_t* Semafor2);
                shmem[i]=i;
                i++;
                cout << "success";
                int sem_post(sem_t* Semafor2);
            }

        }
        else
        {
            int r2 = rand()%2;
            if(r2 == 2)
            {
                int sem_wait(sem_t* Semafor1);
                shmem[i]=i;
                i++;
                int sem_post(sem_t* Semafor1);
            }
        }
    }
}
