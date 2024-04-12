#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    int shmIDArray[]={32768,32769,32770,32771,32772,32777,32778,32779,32780,32782,32783,32786,32787,32795,32796,31,32800,32801,32805,32808,32809,32810,47,53};
    for(int i=0; i<sizeof(shmIDArray)/sizeof(int); i++)
    {
        if(shmctl(shmIDArray[i], IPC_RMID, NULL) < 0)
        {
            fprintf(stderr, "remove error for shmid=%d: %s\n", shmIDArray[i], strerror(errno));
        }else{
            printf("delete %d\n", shmIDArray[i]);
        }
    }
    return 0;
}

