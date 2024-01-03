#include <iostream.h>


int size(struct node* node){	
	if (node == NULL)
		return 0;
	return (1+size(node->left))+
	       (size(node->right));	
}

//PUEDE QUE ESTE MAL, buscar la hoja mas larga, max entre sub iz o sub der
int maxDepth(struct node* node){
	if (node == NULL)
		return 0;
	else
		return 1+max(maxDepth(root->left),
				maxDepth(root->right));
}

int minValue(struct node* node){
	assert(node == NULL);
	if (node->left == NULL)
                return node->data;
        return minValue(node->left);	
}

void printTree(struct node* node){
	if(node == NULL)
		printf("\n");
	else{
		printTree(node->left);
		print("%d ",node->data);
		printTree(node->right);

	}

}

void printPostOrder(struct node* node){
	if(node == NULL)
}

int hasPathSum(struct node* node, int sum){
	int count= 0;
	if(node == NULL)
		return 0;
	hasPathSum(node->left, sum-(node->value));
	if(node->left == NULL && node->right == NULL)
		
	
}






























