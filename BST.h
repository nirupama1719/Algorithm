#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  //BST();
  bool empty() const;
  bool search(const int & item) const;
  void insert(const int & item);
  
 private:
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data,height;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0),height(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0),height(0)
    {}	  
  };// end of class BinNode declaration
  
  /***** Data Members *****/
public:
  BST::BST()
	  : myRoot(0)
  {}
	BinNode * myRoot; 
	BinNode * leftRotate(BinNode * tree);
	int height(BinNode * myRoot);
	int getBalance(BinNode * myRoot);
	void preorder(BinNode * myRoot);
	void Inorder(BinNode * myRoot);
	int nodeCount(BinNode * tree);
	BinNode * tree();
	BinNode * deleteNode(BinNode * myRoot, const int & item);
	BinNode * findMinNode(BinNode * myRoot);
	BinNode * rightRotate(BinNode * myRoot);
	BinNode * newItem(int key);
	BinNode * deleteAVL(BinNode * tree, const int & item);
	BinNode * insertAVL(BinNode * tree, const int & item);
	void initialize();
	void avlinsert(int item);
	void avldelete(int item);
}; // end of class declaration

#endif
