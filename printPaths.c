
void printPathRecur(struct node* node,int path[], int pathLen)
{
	if(node==0){
		return;
	}
	path[pathLen] = node->data;
        pathLen+=1;


	if((node->left ==0)&&(node->right==0)){
		int i;
		for(i=0;i<pathLen;i++){
			printf("%d-",path[i]);
		}
		printf("\n");
		return;
	}
	else {
		printPathRecur(node->left,path,pathLen);
		printPathRecur(node->right,path,pathLen);
		return;
	}	
}

void printPaths(struct node* node)
{
	int path[100];
	int pathLen = 0;
	printPathRecur(node,path,pathLen);
}		
