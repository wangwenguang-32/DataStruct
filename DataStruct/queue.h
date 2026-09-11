#ifndef QUEUE_H
#define QUEUE_h

#include<stdint.h>
#include<stdbool.h>

#define MAX_QUEUE 100
typedef struct
{
	uint32_t head;
	uint32_t tail;
	void* arr[100];
}Queue;

Queue* InitQueue();
bool Empty(Queue* queue);
bool Full(Queue* queue);
bool EnQueue(Queue* queue, void* data);
void* DeQueue(Queue* queue);



#endif // !QUEUE_H
