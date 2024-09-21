#include <stdio.h>
#include "stdlib.h"
#include "RBTree.h"
#include "string.h"

#define RIGHT 0
#define LEFT 1
#define SUCCESS 1
#define FAILURE 0

//EX3 - RED BLACK TREES by yoav eshed 305384869

int deleteFromTree(Node *M, RBTree *tree);

/**
 * A function that checks if a nodes color is black, null nodes counts as black
 * @param node : the node which is being tested
 * @return : 1 if the node is black, 0 if not
 */
int isBlack(Node *node)
{
	if ((node == NULL) || (node->color == BLACK))
	{
		return SUCCESS;
	}
	return FAILURE;
}


/**
 * A function that checks if a nodes color is red
 * @param node : the node which is being tested
 * @return : 1 if the node is red, 0 if not
 */
int isRed(Node *node)
{
	if (node == NULL)
	{
		return FAILURE;
	}
	return node->color == RED;
}

/**
 * A function that retrieves the Parent node  of a node
 * @param node : the node whose Parent will be retrieved
 * @return: node if found , else returns NULL
 */
Node *getParent(Node *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	return node->parent;
}

/**
 * A function that retrieves the sibling of a node
 * @param node : the node whose sibling will be returned
 * @return: node if found , else returns NULL
 */
Node *getSibling(Node *node)
{
	Node *parent = getParent(node);

	if (parent == NULL)
	{
		return NULL;
	}
	if (node == parent->left)
	{
		return parent->right;
	}
	return parent->left;
}

/**
 * A function that retrieves the grandparent of the node
 * @param node :node
 * @return :the grand parent node
 */
Node *getUncle(Node *node)
{
	if (node != NULL)
	{
		return getSibling(getParent(node));
	}
	return NULL;
}

/**
 * A function that retrieves the grandparent of the node
 * @param node :node
 * @return :the grand parent node
 */
Node *getGrandParent(Node *node)
{
	if (node != NULL)
	{
		return getParent(getParent(node));
	}
	return NULL;
}

/**
 * A function that gets a successor for a node in an bst
 * @param node : the node that will get a successor
 * @return the successor node if found , null if not
 */
Node *getSuccessor(Node *node)
{
	if (node != NULL)
	{
		Node *successor = node;
		{
			while (successor->left != NULL)
			{
				successor = successor->left;
			}
			return successor;
		}
	}
	return NULL;
}

/**
 * A function that retrieves a node as a successor to a node in a bst
 * @param node: the node to find a successor to
 * @return: A node - if the node has two leaves the function returns the most left node
 * At the right sub tree, ,if the node has two leaves it returns null;
 */
Node *bstSuccessor(Node *node)
{
	if (node->left != NULL && node->right != NULL)
	{
		return getSuccessor(node->right);
	}
	if (node->left == NULL && node->right == NULL)
	{
		return NULL;
	}
	if (node->left != NULL)
	{
		return node->left;
	}
	return node->right;
}


/**
 * A function the rotates a node inside a tree by moving the node and its parent and grand parent
 * nodes to the right while conserving the tree balancing attributes of the tree
 * @param node: the node to be rotated
 */
void rotateRight(Node *node)
{
	Node *newNode = node->left;
	Node *P = node->parent;
	if (newNode->right != NULL)
	{
		newNode->right->parent = node;
	}
	node->left = newNode->right;
	node->parent = newNode;
	newNode->right = node;
	newNode->parent = P;
	if (P != NULL)
	{
		if (P->right == node)
		{
			P->right = newNode;
		}
		else
		{
			P->left = newNode;
		}
	}
}

/**
 * A function the rotates a node inside a tree by moving the node and its parent and grand parent
 * nodes to the left while conserving the tree balancing attributes of the tree
 * @param node: the node to be rotated
 */
void rotateLeft(Node *node)
{
	Node *newNode = node->right;
	Node *P = node->parent;
	if (newNode->left != NULL)
	{
		newNode->left->parent = node;
	}
	node->right = newNode->left;
	node->parent = newNode;
	newNode->left = node;
	newNode->parent = P;
	if (P != NULL)
	{
		if (P->left == node)
		{
			P->left = newNode;
		}
		else
		{
			P->right = newNode;
		}
	}
}

/**
 * A an aiding function for case 4 of insertion
 * @param tree:
 * @param node: the node to be inserted
 */
void caseFour(RBTree *tree, Node *node)
{
	Node *G = getGrandParent(node);
	Node *P = node->parent;
	//phase A
	if (node == P->left)
	{
		rotateRight(G);
		if (getGrandParent(node) == NULL)
		{
			tree->root = node->parent;
		}
	}
	else
		//phase B
	{
		rotateLeft(G);
		if (getGrandParent(node) == NULL)
		{
			tree->root = node->parent;
		}
	}
	//phase C
	P->color = BLACK;
	G->color = RED;
}

/**
 * A function the re-aligns a red black tree and repairs any violations
 * @param root : the tree root
 * @param curNode: the node that needs to be checked for violations
 */
void fixTree(RBTree *tree, Node *node)
{
	Node *U = getUncle(node);
	Node *P = getParent(node);
	Node *G = getGrandParent(node);
	//case 1
	if (tree->compFunc(tree->root->data, node->data) == 0)
	{
		node->color = BLACK;
	}
	//case 2
	else if (isBlack(P))
	{
		return;
	}
	//case 3
	else if (isRed(P) && isRed(U))//alarm
	{
		P->color = BLACK;
		U->color = BLACK;
		G->color = RED;
		fixTree(tree, G);
	}
	else
	{
		if (node == P->right && P == G->left)
		{
			rotateLeft(P);
			if (getGrandParent(node) == NULL)
			{
				tree->root = node->parent;
			}
			node = node->left;
		}
		else if (node == P->left && P == G->right)
		{
			rotateRight(P);
			if (getGrandParent(node) == NULL)
			{
				tree->root = node->parent;
			}
			node = node->right;
		}
		caseFour(tree, node);
	}
}

/**
 * An Aiding  function for inserting nodes into an bst search tree
 * @param root : root of the three
 * @param node: the node which is going to be inserted
 * @param tree : Red black tree object
 * @return: the node if the insertion is successful , NULL if not
 */

Node *insertNode(Node *root, Node *node, RBTree *tree)
{
	if (root == NULL)
	{
		return node;
	}
	int res = tree->compFunc(root->data, node->data);
	if (res > 0)
	{
		root->left = insertNode(root->left, node, tree);
		root->left->parent = root;
	}
	else if (res < 0)
	{
		root->right = insertNode(root->right, node, tree);
		root->right->parent = root;
	}
	return root;
}

/**
 * A function for removing a node entirely from a red black tree
 * @param root :three root
 * @param tree : Red black tree object
 */
void deleteNode(Node **root, RBTree *tree)
{
	if (*root == NULL)
	{
		return;
	}
	deleteNode(&(*root)->left, tree);
	deleteNode(&(*root)->right, tree);
	tree->freeFunc((*root)->data);
	free(*root);
}

/**
 * A function that swaps data between two nodes
 * @param a : first data object
 * @param b : second data object
 */
void swapNodes(Node *a, Node *b)
{
	if (a == NULL || b == NULL)
	{
		return;
	}
	void *tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

/**
 * A function that traverses the tree recursively and checks if there value exists in it.
 * @param root : the root of the tree been searched on.
 * @param data : that data that is being searched
 * @param compFunc: a comparison function
 * @return: 1 if the value exists in the tree, 0 if not.
 */
Node *searchTree(Node *root, const void *data, CompareFunc compFunc)
{
	if (root == NULL)
	{
		return NULL;
	}
	int res = compFunc(root->data, data);
	if (res == 0)
	{
		return root;
	}
	if (res > 0)
	{
		return searchTree(root->left, data, compFunc);
	}
	if (res < 0)
	{
		return searchTree(root->right, data, compFunc);
	}
	return EXIT_SUCCESS;
}

/**
 * A function that preforms in order traverse on the tree and executes a function for each node
 * @param root : A node of the tree
 * @param func : A function to be applied
 * @param args : Arguments to the function if it needs them
 */
void inOrderPass(Node *root, forEachFunc func, void *args)
{
	if (root == NULL)
	{
		return;
	}
	inOrderPass(root->left, func, args);
	func(root->data, args);
	inOrderPass(root->right, func, args);
}

/**
 * constructs a new RBTree with the given CompareFunc.
 * compFunc: a function two compare two variables.
 * freeFunc: a function that frees allocated memory
 */
RBTree *newRBTree(CompareFunc compFunc, FreeFunc freeFunc)
{
	if (compFunc == NULL || freeFunc == NULL)
	{
		return NULL;
	}
	RBTree *tree = (RBTree *) malloc(sizeof(RBTree));
	if (tree != NULL)
	{
		tree->root = NULL;
		tree->compFunc = compFunc;
		tree->freeFunc = freeFunc;
		tree->size = 0;
		return tree;
	}
	return NULL;
}

/**
 * add an item to the tree
 * @param tree: the tree to add an item to.
 * @param data: item to add to the tree.
 * @return: 0 on failure, other on success. (if the item is already in the tree - failure).
 */
int insertToRBTree(RBTree *tree, void *data)
{
	if (tree == NULL || data == NULL)
	{
		return FAILURE;
	}
	Node *new = (Node *) malloc(sizeof(Node));
	Node *tmp = tree->root;
	if (new == NULL)
	{
		return FAILURE;
	}
	if (RBTreeContains(tree, data))
	{
		free(new);
		return FAILURE;
	}
	new->data = data, new->color = RED, new->parent = NULL, new->left = NULL, new->right = NULL;
	if (tmp == NULL)
	{
		new->color = BLACK, tree->root = new;
		fixTree(tree, new);
		tree->size++;
		return SUCCESS;
	}
	if (insertNode(tree->root, new, tree))
	{
		fixTree(tree, new);
		tree->size++;
		return SUCCESS;
	}
	free(new);
	return FAILURE;
}

/**
 * check whether the tree RBTreeContains this item.
 * @param tree: the tree to add an item to.
 * @param data: item to check.
 * @return: 0 if the item is not in the tree, other if it is.
 */
int RBTreeContains(const RBTree *tree, const void *data)
{
	if (tree == NULL || data == NULL)
	{
		return FAILURE;
	}
	if (searchTree(tree->root, data, tree->compFunc) == NULL)
	{
		return FAILURE;
	}
	return SUCCESS;
}


/**
 * A function that disconnects A node from a treee
 * @param tree : Red black tree object
 * @param node :The node to be removed
 */
void disconnect(RBTree *tree, Node *node)
{
	Node *Parent = getParent(node);
	if (Parent->right == node)
	{
		Parent->right = NULL;
	}
	else if (Parent->left == node)
	{
		Parent->left = NULL;
	}
	tree->freeFunc(node->data);
}

/**
 * A function that handles the double black cases.
 * @param M: current node - the one marked double black
 * @param P: the node's parents node
 * @param S: the node's sibling node
 * @param C: the node's descendant node
 * @param tree : Red black tree object
 * @return: deleted node if deletion was successful , null if not
 */
Node *doubleBlack(Node *M, Node *P, Node *S, Node *C, RBTree *tree)
{
	//case A
	if (M->parent == NULL)
	{
		if (C != NULL)
		{
			return C;
		}
		return M;
	}
	//case B
	if ((S == NULL) || ((isBlack(S)) && (isBlack(S->left)) && (isBlack(S->right))))
	{
		if (isRed(P))
		{
			// case B.I
			P->color = BLACK;
			if (S != NULL)
			{
				S->color = RED;
			}
			return M;
		}
			// case B.II
		else if (isBlack(P))
		{
			S->color = RED;
			return doubleBlack(P, getParent(P), getSibling(P), bstSuccessor(P), tree);
		}
	}

		//case C
	else if (isRed(S))
	{
		Color temp = P->color;
		P->color = S->color;
		S->color = temp;
		if (M == P->left)
		{
			rotateLeft(P);
			rotateRight(P);
			return doubleBlack(M, P, S, C, tree);
		}
		else if (M == P->right)
		{
			rotateRight(P);
			return doubleBlack(M, P, S, C, tree);
		}
	}
	else
		//S is black
	{
		int direction = RIGHT;
		Node *SF = NULL;
		Node *SC = NULL;
		if (S == P->right)
		{
			SF = S->right;
			SC = S->left;
		}
		else if (S == P->left)
		{
			SF = S->left;
			SC = S->right;
			direction = LEFT;
		}
		//case 3.4
		if (isBlack(SF) == 1 && isRed(SC) == 1)
		{
			SC->color = BLACK;
			S->color = RED;

			if (S != NULL && S == P->right)
			{
				SF = S->right;
				SC = S->left;
			}
			else if (S != NULL && S == P->right)
			{
				SF = S->left;
				SC = S->right;
				direction = LEFT;
			}
			if (direction == RIGHT)
			{
				rotateRight(S);
			}
			else
			{
				rotateLeft(S);
			}
			S = getSibling(M);
			if (S != NULL && S == P->right)
			{
				SF = S->right;
				SC = S->left;
			}
			else if (S != NULL && S == P->right)
			{
				SF = S->left;
				SC = S->right;
				direction = LEFT;
			}
		}
		//case 3.5
		if (isRed(SF))
		{
			Color temp = P->color;
			P->color = S->color;
			S->color = temp;
			SF->color = BLACK;
			if (direction == RIGHT)
			{
				rotateLeft(P);
			}
			else
			{
				rotateRight(P);
			}
			return M;
		}
	}
	return NULL;
}


/**
 * A function that deletes a node from a tree
 * @param M : node to be replaced
 * @param tree : Red black tree object
 * @return
 */
int deleteFromTree(Node *M, RBTree *tree)
{
	Node *C = bstSuccessor(M); // descendant
	Node *P = M->parent;
	Node *S = getSibling(M);
	//Case A
	swapNodes(M, C);
	if (isRed(M))
	{
		if (C == NULL)
		{
			disconnect(tree, M);
			fixTree(tree, P);
			return SUCCESS;
		}
		disconnect(tree, C);
		fixTree(tree, M);
		return SUCCESS;

	}
	//Case B
	if ((isBlack(M) == 1) && (isRed(C) == 1))
	{
		disconnect(tree, C);
		return SUCCESS;
	}
	//Case C
	if ((isBlack(M) == 1) && (isBlack(C) == 1))
	{
		disconnect(tree, doubleBlack(M, P, S, C, tree));
		return SUCCESS;
	}
	return FAILURE;
}

/**
 * remove an item from the tree
 * @param tree: the tree to remove an item from.
 * @param data: item to remove from the tree.
 * @return: 0 on failure, other on success. (if data is not in the tree - failure).
 */
int deleteFromRBTree(RBTree *tree, void *data)
{
	Node *SUCCESSOR = searchTree(tree->root, data, tree->compFunc);
	if (SUCCESSOR == NULL || tree == NULL || data == NULL)
	{
		return FAILURE;
	}
	if (!RBTreeContains(tree, data))
	{
		return FAILURE;
	}
	if (!deleteFromTree(SUCCESSOR, tree))
	{
		return FAILURE;
	}
	tree->size--;
	return EXIT_SUCCESS;
}

/**
 * Activate a function on each item of the tree. the order is an ascending order. if one of the
 * activations of the
 * function returns 0, the process stops.
 * @param tree: the tree with all the items.
 * @param func: the function to activate on all items.
 * @param args: more optional arguments to the function (may be null if the given function
 * support it).
 * @return: 0 on failure, other on success.
 */
int forEachRBTree(const RBTree *tree, forEachFunc func, void *args)
{
	if (tree->root == NULL)
	{
		return FAILURE;
	}
	inOrderPass(tree->root, func, args);
	return SUCCESS;
}

/**
 * free all memory of the data structure.
 * @param tree: pointer to the tree to free.
 */
void freeRBTree(RBTree **tree)
{
	if (tree != NULL)
	{
		deleteNode(&(*tree)->root, *tree);
		free(*tree);
	}
}




