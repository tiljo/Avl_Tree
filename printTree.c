
void printTree(struct node* node)
{
	if(node == NULL) return;
	
	else{
		printTree(node->left);
		printf("%d_%d	",node->data,node->hf);
		printTree(node->right);
	}
}
