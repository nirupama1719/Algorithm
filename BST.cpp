#include <iostream>
//#include <iomanip>
# include <cstdlib>
using namespace std;

#include "BST.h"

//--- Definition of constructor
bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
BST::BinNode * BST::findMinNode(BinNode * tree)
{
	BinNode * current = tree;
	while (current->left != NULL)
		current = current->left;

	return current;
}

BST::BinNode * BST::deleteNode(BinNode * tree, const int & item) {
	BinNode * locptr = tree;   
	BinNode * parent;
	if (locptr == NULL) {
		cout << "No item to delete";
		return locptr;
	}
	else if (item < locptr->data)
	{
		locptr->left = deleteNode(locptr->left, item);
	}
	else if (item > locptr->data)
	{
		locptr->right = deleteNode(locptr->right, item);
	}
	else
	{
		if (locptr->right && locptr->left)
		{
			parent = findMinNode(locptr->right);
			locptr->data = parent->data;
			locptr->right = deleteNode(locptr->right, parent->data);
		}
		else
		{ 
			parent = locptr;
			if (locptr->left == NULL)
				locptr = locptr->right;
			else if (locptr->right == NULL)
				locptr = locptr->left;
			free(parent);
		}
	}
	return locptr;
}
void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   
   BinNode * parent = 0;       
   bool found = false;     
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}
BST::BinNode * BST::newItem(int key)
{
	BinNode *tree =new BinNode(key);
	tree->data = key;
	tree->left = NULL;
	tree->right = NULL;
	tree->height = 1;  
	return(tree);
}
BST::BinNode * BST::deleteAVL(BinNode *tree, const int & item)
{
	if (tree == NULL) {
		cout << "No item to delete";
		return tree;
	}
	else if (item < tree->data)
		tree->left = deleteAVL(tree->left, item);
	else if (item > tree->data)
		tree->right = deleteAVL(tree->right, item);
	else {
		if ((tree->left == NULL) || (tree->right == NULL)) {
			BinNode * tree1;
			if (tree->left) {
				tree1 = tree->left;
			}
			else
				tree1 = tree->right;
			if (tree1 == NULL) {
				tree1 = tree;
				tree = NULL;
			}
			else
				*tree = *tree1;
			free(tree1);
		}
		else {
			BinNode *tree1 = findMinNode(tree->right);
			tree->data = tree1->data;
			tree->right = deleteAVL(tree->right,tree1->data);
		}
	}
	if (tree == NULL) return tree;
	tree->height= +max(height(tree->left), height(tree->right));
	int checkBalance = getBalance(tree);
	if (checkBalance > 1 && getBalance(tree->left) >= 0)
		return rightRotate(tree);
	if (checkBalance > 1 && getBalance(tree->left) < 0)
	{
		tree->left = leftRotate(tree->left);
		return rightRotate(tree);
	}
	if (checkBalance < -1 && getBalance(tree->right) <= 0)
		return leftRotate(tree);
	if (checkBalance < -1 && getBalance(tree->right) > 0)
	{
		tree->right = rightRotate(tree->right);
		return leftRotate(tree);
	}
	return tree;
}
BST::BinNode * BST::insertAVL(BinNode *tree,const int & item)
{
		if (tree == NULL) {
			return newItem(item);
		}           	
		else if (item < tree->data)  
			tree->left = insertAVL(tree->left, item);
		else if (item > tree->data)                       
			tree->right = insertAVL(tree->right, item);
		else
			return tree;
		tree->height= 1 + max(height(tree->left),height(tree->right));
		int checkBalance= getBalance(tree);
		if (checkBalance > 1 && item < tree->left->data)
			return rightRotate(tree);

		if (checkBalance < -1 && item > tree->right->data)
			return leftRotate(tree);

		if (checkBalance > 1 && item > tree->left->data)
		{
			tree->left = leftRotate(tree->left);
			return rightRotate(tree);
		}
		if (checkBalance < -1 && item < tree->right->data)
		{
			tree->right = rightRotate(tree->right);
			return leftRotate(tree);
		}
		return tree;
}
void BST::initialize() {
	myRoot = 0;
}
void BST::avlinsert(int item) {
	myRoot = insertAVL(myRoot,item);
}
void BST::avldelete(int item) {
	myRoot = deleteAVL(myRoot, item);
}
int BST::height(BinNode * tree)
{
	if (tree == NULL)
		return 0;
	return tree->height;
}
int BST::getBalance(BinNode * tree)
{
	if (tree == NULL)
		return 0;
	return height(tree->left) - height(tree->right);
}
BST::BinNode * BST::rightRotate(BinNode * tree)
{
	BinNode *a = tree->left;
	BinNode *b = a->right;
	a->right = tree;
	tree->left = b;
	tree->height = max(height(tree->left), height(tree->right)) + 1;
	a->height = max(height(a->left), height(a->right)) + 1;
	return a;
}
BST::BinNode * BST::leftRotate(BinNode *tree)
{
	BinNode *a = tree->right;
	BinNode *b = a->left;
	a->left = tree;
	tree->right = b;
	tree->height = max(height(tree->left), height(tree->right)) + 1;
	a->height = max(height(a->left), height(a->right)) + 1;
	return a;
}

void BST::preorder(BinNode * tree)
{
	if (tree == NULL) return;
	cout << tree->data << "\n";
	preorder(tree->left);
	preorder(tree->right);
}

void BST::Inorder(BinNode * tree)
{
	if (tree == NULL) return;
	Inorder(tree->left);
	cout << tree->data << "\n";
	Inorder(tree->right);
}
int BST::nodeCount(BinNode * tree)
{
	int count = 1;
	if (tree == NULL)
		return 0;//if we are not at a leaf
	else{
		count+=nodeCount(tree->left);//recurisvly call the function and increment the count
		count+=nodeCount(tree->right);
		return count;
	}
}

BST::BinNode * BST::tree()
{
	BinNode *locptr = myRoot;
	return locptr;
}


