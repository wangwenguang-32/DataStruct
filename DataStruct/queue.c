#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"

Queue* InitQueue()
{
	Queue*queue= (Queue*)malloc(sizeof(Queue));
	queue->head = 0;
	queue->tail = 0;
	return queue;
}

bool Empty(Queue* queue)
{
	if (queue->head == queue->tail)
	{
		return true;
	}
	return false;
}

bool Full(Queue* queue)
{
	if ((queue->tail + 1) % MAX_QUEUE == queue->head)
	{
		return true;
	}
	return false;
}

bool EnQueue(Queue* queue, void* data)
{
	if (Full(queue))
		return false;

	queue->arr[queue->tail] = data;
	queue->tail = (queue->tail + 1) % MAX_QUEUE;
	return true;
}

void* DeQueue(Queue* queue)
{
	if (Empty(queue))
		return NULL;

	void*temp=queue->arr[queue->head];
	queue->head = (queue->head + 1) % MAX_QUEUE;
	return temp;
}

