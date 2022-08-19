#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "msg_spray.h"

#define BUFFER 1024
void spray_mqueue(mqd_t mqdes, char *msgptr, int spray_size)
{

	unsigned rvprio, sdprio = 1;
	struct timespec ts;
	int unresolved = 0;
	int priority = 0;
#ifdef MSG_DEBUG
    printf("[*] spraying mqueue %d, size: %d, loop: %d\n", num_msg, size, loop);
#endif
    for(int i=0; i<spray_size; i++)
        if (mq_send(mqdes, msgptr, strlen(msgptr), sdprio) != 0)
            perror("mq_send");
}

int gather_mqueue_nosave(mqd_t mqdes, int gather_size)
{
    int priority = 0;
    char msg[BUFFER];
#ifdef MSG_DEBUG
    printf("[*] gathering mqueue...\n");
#endif
    for(int i=0; i<gather_size; i++)
        mq_receive(mqdes, (char*) &msg, BUFFER, NULL);

    return 0;
}