/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
#include "BST.h"
using namespace std;


//BST::BST()
//	: myRoot(0)
//{}
int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   //BST::BinNode *root;
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing search()
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   }
   cout << "======Preorder Traversal:======\n";
   intBST.preorder(intBST.tree());
   cout << "======Inorder Traversal:======\n";
   intBST.Inorder(intBST.tree());
   int nodeCount = intBST.nodeCount(intBST.tree());
   cout <<"\nNode Count:"<< nodeCount << "\n";
   cout << "\n=====Delete item from tree====="<< endl;
   for (;;)
   {
	   cout << "Enter item to be deleted:";
	   cin >> number;
	   if (number == -999) break;
	   intBST.Inorder(intBST.deleteNode(intBST.tree(), number));
   }
   intBST.initialize();
   cout << "\n======Insert item for AVL tree=====" << endl;
   for (;;)
   {
	   cout << "Enter item for insert:";
	   cin >> number;
	   if (number == -999) break;
	   intBST.avlinsert(number);
   }
   cout << "======Inorder Traversal:======\n";
   intBST.Inorder(intBST.tree());
   cout << "\n=====Delete item from AVL tree=====" << endl;
   for (;;)
   {
	   cout << "Enter item for delete:";
	   cin >> number;
	   if (number == -999) break;
	   intBST.avldelete(number);
   }
   cout << "======Inorder Traversal:======\n";
   intBST.Inorder(intBST.tree());
   getchar();
   system("pause");
   return 0;
}
