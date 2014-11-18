void hfmaker(struct node* node)
{
	int l=0,r=0;
	if(node->left == NULL && node->right== NULL){
		l=r=-1;
	}
	else if(node->left == NULL){
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
		printf("rotating %d\n",node->data);
		struct node* tmp = NULL;
		tmp = node;
		if(bal == -2){

			node = node->right->left;
			tmp->right->left = node->right;
			node->right = tmp->right;
			tmp->right = node->left;
			node->left = tmp;
		}
		else if(bal==-6){
			node = tmp->right;
			tmp->right = node->left;
			node->left = tmp;
		}
		else if(bal == 2){
			
			node = node->left->right;
			printf(".............\n");
			tmp->left->right = node->left;
			node->left = tmp->left;
			tmp->left = node->right;
			node->right = tmp;
		}
		else if(bal==6){
			node = tmp->left;
			tmp->left = node->right;
			node->right = tmp;
		}
			hfmaker(node->left);
			hfmaker(node->right);
			hfmaker(node);
			return node;
}

int balance(struct node* node)
{
	int l,r;
	if(node->left == NULL){
		l = -1;
	}
	else l = node->left->hf;

	if(node->right == NULL)
		r= -1;
	else r = node->right->hf;
	
	return (l-r);
}

struct node* Insert(struct node* node, int data)
{
	int bal;
	if(node == NULL){
		return (NewNode(data));
	}

	if(data <= node->data){
	   	node->left = Insert(node->left,data);
	}
	else  node->right = Insert(node->right,data);

	bal = balance(node);
	if(bal<-1 && data<(node->right->data))
		node = rotator(node,-2);
	else if(bal<-1 && data>(node->right->data))
		node = rotator(node,-6);
	else if(bal>1 && data<(node->left->data))
		node = rotator(node,6);
	else if(bal>1 && data>(node->left->data))
		node = rotator(node,2);


	hfmaker(node);

	return node;
}

