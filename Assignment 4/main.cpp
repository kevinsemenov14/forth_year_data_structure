

#include "tree.h"


int main()
{

	char input;
	cin >> input;



	bSearchTreeType<int> tree;
//Store the following elements:
	//88, 12, 24, 49, 7, 25, 55, 18, 19, 13, 109, 18, 44, 1001
cout << "Kevin semenov cs1D " << endl;
cout << "This program will Implement a binary search tree using an array, vector or linked list." << endl;
cout << "The program will also Perform the in-order, post-order, pre-order, breadth-first traversals." << endl;
cout << "Lastly the program will print out the binary search tree by level." << endl << endl;
cout << "Inserting 88 into the tree" << endl;
tree.insert(88);
cout << "Inserting 12 into the tree" << endl;
tree.insert(12);
cout << "Inserting 24 into the tree" << endl;
tree.insert(24);
cout << "Inserting 49 into the tree" << endl;
tree.insert(49);
cout << "Inserting 7 into the tree" << endl;
tree.insert(7);
cout << "Inserting 25 into the tree" << endl;
tree.insert(25);
cout << "Inserting 55 into the tree" << endl;
tree.insert(55);
cout << "Inserting 18 into the tree" << endl;
tree.insert(18);
cout << "Inserting 19 into the tree" << endl;
tree.insert(19);
cout << "Inserting 13 into the tree" << endl;
tree.insert(13);
cout << "Inserting 109 into the tree" << endl;
tree.insert(109);
cout << "Inserting 18 into the tree" << endl;
tree.insert(18);
cout << "Inserting 44 into the tree" << endl;
tree.insert(44);
cout << "Inserting 1001 into the tree" << endl << endl;
tree.insert(1001);
cout << endl;
cout << "The trees height is "<< tree.treeHeight() << endl;
cout << "performing the inorder traversal on the tree" << endl;
tree.inorderTraversal();
cout << endl;
cout << "performing the postorder Traversal  on the tree" << endl;
tree.postorderTraversal();
cout << endl;
cout << "performing the preorder Traversal  on the tree" << endl;
tree.preorderTraversal();
cout << endl;
cout << "performing the preathFirst Traversal on the tree" << endl;
tree.breathfirst();
cout << endl;
cout<< "there are " << tree.leavesCount() << " leaves on the tree";
cout << endl;

cout << endl << endl;
cout << setw(60) << 88;
cout << endl;
cout << endl;
cout << setw(50) << 12; cout << setw(20) << 109;
cout << endl;
cout << endl;
cout << setw(40) << 7;cout << setw(15) << 24;cout << setw(25) << 1001;
cout << endl;
cout << endl;
cout << setw(50) << 18;cout << setw(10) << 49;
cout << endl;
cout << endl;
cout << setw(45) << 13;cout << setw(7) << 19;cout << setw(6) << 25;cout << setw(5) << 55;
cout << endl;
cout << endl;
cout << setw(60) << 44;

	return 0;
}
