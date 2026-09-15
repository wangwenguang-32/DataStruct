#ifndef TREE_H
#define TREE_H

#include<stdint.h>

struct BiTree
{
	int32_t data;
	struct BiTree* left;
	struct BiTree* right;
};

typedef struct BiTree BiTree;


#endif
