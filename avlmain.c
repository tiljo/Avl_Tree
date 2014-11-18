#include"avl.h"

#include"printTree.c"
#include"printPaths.c"
#include"avlinsertion.h"
//#include"avlinsertb.c"

int main()
{
	struct node* node = NULL;
	int bal =0;
	node = NewNode(18);
	node = Insert(node,14);

	printf("after inserting\n");
	printPaths(node);
	node = Insert(node,19);

	printf("after inserting\n");
	printPaths(node);
	node = Insert(node,12);

	printf("after inserting\n");
	printPaths(node);
	node = Insert(node,16);

	printf("after inserting\n");
	printPaths(node);
	node = Insert(node,15);
	printf("after inserting\n");
	printPaths(node);
	printf("first completed\n");

	//	printf("BAL:%d\n",balance(node));
	/*node = Insert(node,27);

	printf("after inserting\n");
	printPaths(node);
	node = Insert(node,25);

	printf("after inserting\n");
	printPaths(node);
	node = Insert(node,28);
	
	printf("after inserting\n");
	printPaths(node);
	node = Insert(node,29);*/

	printf("after inserting\n");
	printPaths(node);
	printTree(node);
	printf("\n");
	return 0;
}
