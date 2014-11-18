void hfmaker(struct node* node){
	int l=0,r=0;
	if(node->left == NULL && node->right== NULL)
		l=r=-1;
	if(node->left == NULL){
		l = (node->right->hf);
	}
	else if(node->right == NULL){
		r = (node->left->hf);
	}
	else{
		l = (node->left->hf);
		r = (node->right->hf);
	}
		node->hf = (l >= r) ? l+1 : r+1;
}


struct node* rotator(struct node* node,int bal)
{
	if(bal == -2){
		struct node* tmp = NULL;
		tmp = node;
		node = node->right->left;
		tmp->right->left = node->right;
		node->right = tmp->right;
		tmp->right = node->left;
		node->left = tmp;

		hfmaker(node->left);
		hfmaker(node->right);
		hfmaker(node);
	}
	return node;
}







int balance(struct node* node)

{
	int l,r,b,l1,l2;
	if(node->left == NULL){
		l = -1;
	}
	else l = node->left->hf;

	if(node->right == NULL)
		r= -1;
	else r = node->right->hf;
	
	b= l-r;
	if(b==0|| b==1|| b==-1)
		return b;
	else if(b==2){
		l1 = balance(node->left);
		return (b+l1)*2;
	}
	else if(b==-2){
		printTree(node->right);
		
		l2 = balance(node->right);
		return -2;
	}
	else return (b+l2)*2;
}


	





struct node* Insert(struct node* node, int data)
{
	int bal=0;
	struct node* tmp;
	if(node == NULL){
		return (NewNode(data));
	}
	else{
		if(data <= node->data){
		   	node->left = Insert(node->left,data);
		}
		else  node->right = Insert(node->right,data);

		bal = balance(node);
		printf("BAL:%d-----%d\n",bal,node->data);
		if(bal == -2){
			printTree(node);
			printf(">>>>>>>>>>>>>>>>>>>>>>");
			printTree(node);
			tmp = rotator(node,bal);
		//	printTree(tmp);
		//	printPaths(tmp);
		}
		else tmp = node;
/*update hf*/
	
		 hfmaker(tmp);
		 
		return (tmp);
	}


}
