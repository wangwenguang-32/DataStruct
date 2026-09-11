#ifndef GRAPH_H
#define GRAPH_H

#include<stdbool.h>
#include<stdint.h>

#define MAX_NODE  100

typedef struct
{
	uint32_t index;
	void* data;
	bool valid;
}Node;

typedef struct
{
	Node nodes[101];
	uint32_t num;
	uint32_t edges[101][101];
}Graph;

Graph* InitGraph();
Node* AddNode(Graph* graph, int data);
Node* GetFirstNeighbor(Graph* graph, Node* node);
Node* GetNextNeighbor(Graph* graph, Node* node1, Node* node2);


#endif
