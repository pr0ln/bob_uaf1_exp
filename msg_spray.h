#ifndef MSG_SPRAY
#define MSG_SPRAY
#include <sys/msg.h>
#include <mqueue.h>
void spray_mqueue(mqd_t mqdes, char *msgptr, int spray_size);
int gather_mqueue_nosave(mqd_t mqdes, int gather_size);
#endif