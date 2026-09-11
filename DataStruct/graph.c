#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdio.h>
#include"graph.h"
#include"queue.h"
#include"common.h"


Graph* InitGraph()
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->num = 0;
	for (int i = 0; i < MAX_NODE; i++) 
	{
		graph->nodes[i].valid = false;
		for (int j = 0; j < MAX_NODE; j++) 
		{
			graph->edges[i][j] = 0;
		}
	}
	return graph;
}

bool AddEdge(Graph*graph, Node* node1, Node* node2,uint32_t data)
{
	if (node1->valid == false || node2->valid == false)
	{
		return false;
	}
	graph->edges[node1->index][node2->index] = data;
	graph->edges[node2->index][node1->index] = data;
	return true;

}

uint32_t GetEdgeData(Graph* graph, Node* node1, Node* node2)
{
	return graph->edges[node1->index][node2->index];
}

Node* AddNode(Graph* graph, void*data)
{
	int i = 1;
	for (i; i <= MAX_NODE; i++)
	{
		if (!graph->nodes[i].valid)
		{
			graph->nodes[i].valid = true;
			graph->nodes[i].index = i;
			graph->nodes[i].data = data;
			graph->num++;
			return &graph->nodes[i];
		}
	}

	return NULL;
}

Node* GetFirstNeighbor(Graph* graph, Node* node)
{
	int index=1;
	int i = node->index;
	for (index; index <= MAX_NODE; index++)
	{
		if (graph->edges[i][index])
		{
			return &graph->nodes[index];
		}
	}
	return NULL;
}



Node* GetNextNeighbor(Graph* graph, Node* node1,Node*node2)
{
	int index = node2->index+1;
	int i = node1->index;
	for (index; index <= MAX_NODE; index++)
	{
		if (graph->edges[i][index])
		{
			return &graph->nodes[index];
		}
	}
	return NULL;
}

void graph_bfs(Graph* graph, void (*visit)(Node* node), Node* node)
{
	bool arr[MAX_NODE] = { false };
	Queue* queue = InitQueue();
	Node* root = node;
	if (!node->valid)
		return;
	visit(root);
	arr[root->index] = true;
	EnQueue(queue, root);
	while (!Empty(queue))
	{
		Node* n = (Node*)DeQueue(queue);
		for (Node* i = GetFirstNeighbor(graph, n); i != NULL; i = GetNextNeighbor(graph, n, i))
		{
			if (!arr[i->index])
			{
				visit(i);
				arr[i->index] = true;
				EnQueue(queue, i);
			}
		}
	}
}
bool arr[MAX_NODE] = { false };

void graph_dfs(Graph* graph, void(*visit)(Node* node), Node* node)
{
	
	visit(node);
	arr[node->index] = true;
	for (Node* i = GetFirstNeighbor(graph, node); i != NULL; i = GetNextNeighbor(graph, node, i))
	{
		if (!arr[i->index])
		{
			DFS(graph, visit, i);
		}
		
	}


}

void Prim(Graph* graph,Node*root)
{
	bool visit[MAX_NODE];
	uint32_t distance[MAX_NODE];
	Node* node = root;

	
	loop(MAX_NODE)
	{
		visit[i] = false;
	}
	loop(MAX_NODE)
	{
		distance[i] = -1;
	}

	visit[node->index] = true;
	distance[node->index] = 0;

	loop(graph->num-1)
	{
		for (Node* n = GetFirstNeighbor(graph, node); n != NULL; n = GetNextNeighbor(graph, node, n))
		{
			if (visit[n->index])
			{
				continue;
			}
			distance[n->index] = min(GetEdgeData(graph, node, n),distance[n->index]);
		}
		uint32_t min = -1;
		uint32_t index;
		int j = 1;
		for (j; j <= graph->num; j++)
		{
			if (visit[j])
			{
				continue;
			}
			if (distance[j] < min)
			{
				index = j;
				min = distance[j];
			}
		}
		node = &graph->nodes[index];
		visit[node->index] = true;
	}

	loop(graph->num)
	{
		printf("%u ", distance[i + 1]);
	}
}


//void visit(Node* node)
//{
//	printf("%d ", *((uint32_t*)(node->data)));
//}
//
//int main()
//{
//	Graph* graph = InitGraph();
//	int data1 = 1;
//	int data2 = 2;
//	int data3 = 3;
//	int data4 = 4;
//	int data5 = 5;
//	int data6 = 6;
//	Node* node1 = AddNode(graph, &data1);
//	Node* node2 = AddNode(graph, &data2);
//	Node* node3 = AddNode(graph, &data3);
//	Node* node4 = AddNode(graph, &data4);
//	Node* node5 = AddNode(graph, &data5);
//	Node* node6 = AddNode(graph, &data6);
//
//	AddEdge(graph, node1, node2,6);
//	AddEdge(graph, node1, node3,5);
//	AddEdge(graph, node1, node4,1);
//	AddEdge(graph, node2, node4,5);
//	AddEdge(graph, node3, node4,4);
//	AddEdge(graph, node2, node5,3);
//	AddEdge(graph, node4, node5,6);
//	AddEdge(graph, node4, node6,4);
//	AddEdge(graph, node3, node6,2);
//	AddEdge(graph, node6, node5,6);
//
//	//BFS(graph, visit, node3);
//	//DFS(graph, visit, node2);
//	Prim(graph, node1);
//
//}