#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
	int data;
	struct node* left;
	struct node* right;	
};

struct node* newNode(int data){
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

struct node* insert(struct node* node, int data){
	if(node == NULL)
		return newNode(data);
	if(data <= node->data)
		node->left = insert(node->left, data);
	else 
		node->right = insert(node->right, data);
	return node;
}

int size(struct node* node){	
	if (node == NULL)
		return 0;
	return (1+size(node->left))+
	       (size(node->right));	
}

//PUEDE QUE ESTE MAL, buscar la hoja mas larga, max entre sub iz o sub der
/*int maxDepth(struct node* node){
	if (node == NULL)
		return 0;
	else
		return 1+max(maxDepth(node->left),
				maxDepth(node->right));
}*/

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
		printf("%d ",node->data);
		printTree(node->right);

	}

}

void printPostOrder(struct node* node){
	if(node == NULL){return;}
}
//Tiene que mostrar verdadero si el valor de sum es igual a la suma de cualquiera de los caminos hacia las ramas
int hasPathSum(struct node* node, int sum){
	/*//cbase
	if(node == NULL)
		return 0;
	
	if(node->left == NULL && node->right == NULL && sum-(node->data)==0)
		return 1;
	else{
	hasPathSum(node->left, sum-(node->data));
	hasPathSum(node->right, sum - (node->data));
	}*/
	if(node == NULL)
		return(sum == 0);
	else{
		int subSum = sum - node->data;
		return (hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum));
	}
}

struct node** treeToList(struct node** root){
	assert(*root);
	//si es hoja
	if(!(*root->left) && !(*root->right)){
		root->left=root;
		root->right=root;
	}
	else{
		//NECESITO guardar el padre? no creo
		//creo temporales que guarden la posicion mas pequeña y la
		//mas grande, y uno que itere por el arbol
		struct node* current= root;
		struct node* pequenio;
		struct node* grande;
		//antes ver si llego a una hoja  ???
		if(!(current->left) && !(current->right))
			pequenio = current;
		//trabajar con el padre de la hoja izquierdo y derecho
		if(!(current->left->left) && !(current->left->right))
			pequenio=current->left->left;
			current->left->right=current;
		if(!(current->right->left) && !(current->right->right))
			
			
		//recorro el arbol
		treeToList(current->left);
		treeToList(current->right);
		//problema, para lista circular si es solo 1 elemento, en recursion va a llegar al caso base y no funciona solo para 1
	}
}

// busqueda InOrder: itera sobre el arbol de forma recursiva, para ir a sub--arboles izquierdos al padre y a subarboles derechos para cada subarbol.
int main(){
	struct node* node= newNode(5);
	insert(node,4);
	insert(node,6);
	insert(node,8);
	insert(node,7);
	//insert(node, 9);
	struct node* root =NULL;
	printTree(node);
	printf("%d \n",hasPathSum(node,26));
	return 0;

}




























