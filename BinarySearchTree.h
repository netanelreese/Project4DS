/*
 *    Data Structures Featuring C++  (c) 2021 Sridhar Radhakrishnan
 */

#include <iostream>
using namespace std;

#ifndef __BINARYSEARCHTREE__H
#define __BINARYSEARCHTREE__H

#include <cstdlib>


int max (int a, int b)
{
	if (a < b) return b;
	else return a;
}

class Exception {};

class BinaryTreeException : Exception {};
class BinaryTreeMemory : BinaryTreeException {};
class BinaryTreeEmptyTree : BinaryTreeException {};

class BinarySearchTreeException: BinaryTreeException {};
//class BinarySearchTreeChangedSubtree : BinarySearchTreeException {};
class BinarySearchTreeNotFound : BinarySearchTreeException {};

template <class DataType>
class BinarySearchTree;

template <class DataType>
ostream& operator << (ostream& s,  BinarySearchTree<DataType>& X);

// /////////////////////////////////////////////////////////////
template <class DataType>
class BinarySearchTree
// /////////////////////////////////////////////////////////////
{
	friend ostream& operator<< <DataType> (ostream& s,  BinarySearchTree<DataType>& X);
protected:
	DataType* _root; //data inside the root node
	BinarySearchTree<DataType>* _left; //left child
	BinarySearchTree<DataType>* _right; // right child
	BinarySearchTree<DataType>* _yTree; //y nodes
	int id; //identifier for tree
	bool _subtree; //???
	virtual BinarySearchTree<DataType>* makeSubtree();
	virtual void _makeNull ();

public:
	BinarySearchTree (); //default constructor
    virtual void copyTree (BinarySearchTree<DataType>* bst); //copies a tree into the tree its called on
	BinarySearchTree (const DataType& data); //nondefault constructor for bst
    BinarySearchTree(DataType& X, DataType& Y, int ID); //constructor to take in x, y and id
    BinarySearchTree(BinarySearchTree<DataType>* copy);
	virtual ~BinarySearchTree ();
	virtual bool isEmpty();
    // returns true if tree is empty,
    // but otherwise returns false
    virtual int getID();
    //returns the id of the thing
	virtual int height ();
    // returns the height (or depth) of the tree
	virtual int size ();
    // returns the number of nodes in the tree
	virtual DataType& root ();
    // returns data from the root
	virtual BinarySearchTree<DataType>* left ();
    // returns the left subtree
	virtual BinarySearchTree<DataType>* right ();
    // returns the right subtree
	virtual bool subtree();
	virtual void makeEmpty ();
    BinarySearchTree<DataType>* _find (const DataType& data);
    //finds the data in the respective tree
	virtual void find_coord(DataType& X, DataType& Y);
	//finds a given coordinate
	virtual void _remove (const DataType& data);
	//removes data from the respective tree
    virtual void remove (DataType& X, DataType& Y);
    //removes a given coordinate from the whole tree
	virtual void rangeSearch (const DataType& low, const DataType& high);
	//range search for ytree
    void rangesearch(DataType& X1, DataType& X2, DataType& Y1, DataType& Y2);
    //range search for whole tree, prints a statement with the coordinate within the range (using rangeSearch for the yTree)
	virtual BinarySearchTree<DataType>* _insert (const DataType& data);
	//inserts data on the tree it is called on
	virtual void insert(DataType& x, DataType& y, int ID);
	//inserts a coordinate with a given identifier
	virtual BinarySearchTree<DataType>* getYTree();
	//getter for yTree
	virtual void display();
	//display method using preorder() and inorder() displaying the tree in Inorder first, then Preorder
    virtual void preorder(); //displays tree in preorder form
    virtual void inorder(); //displays tree in inorder form
    virtual void yInorder(); //displays ytree in inorder form
    virtual void yPreorder(); //displays ytree in preorder form
    virtual int getInorderTraversal(BinarySearchTree<DataType>* node, BinarySearchTree<DataType>** inOrderArray, int index);
    //gets array of nodes in inorder form
    virtual BinarySearchTree<DataType>* GlobalRebalance(BinarySearchTree<DataType>** inOrderArray, int l, int r);
    //rebalances the ytree


};
template <class DataType>
ostream& operator<< (ostream& s,  BinarySearchTree<DataType>& X) {

	if (!X.isEmpty()) {
		s << *(X.left ()) << " " << X.root () << " " << *(X.right());
	}
	return s;
}

// ==============================================================
template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree ()
{
	_root = NULL;
	_left = NULL;
	_right = NULL;
	_yTree = NULL;
	_subtree = false;
	id = -1;
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree (const DataType& data)
{
	_subtree = false;
	_root = new DataType(data);
	//if (data == NULL) throw BinaryTreeMemory();
	_left = makeSubtree ();
	_right = makeSubtree ();
}
// --------------------------------------------------------------
template <class DT>
BinarySearchTree<DT>::BinarySearchTree(DT& X, DT& Y, int ID) {
    _subtree = false;
    _root = new BinarySearchTree(X);
    _yTree = new BinarySearchTree(Y);
    _left = makeSubtree();
    _right = makeSubtree();
    id = ID;
    _yTree->id = ID;
}
// --------------------------------------------------------------
template <class DT>
BinarySearchTree<DT>::BinarySearchTree(BinarySearchTree<DT>* copy) {

    _root = copy->_root;
    _left = copy->_left;
    _right = copy->_right;
    id = copy->id;

    if (!(copy->_yTree->isEmpty())) {
        _yTree = copy->_yTree;
        _yTree->id = id;
    }
    else {
        _yTree = new BinarySearchTree();
        _yTree->id = id;
    }
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::makeSubtree()
{
	BinarySearchTree<DataType>* bst = new BinarySearchTree<DataType> ();
	bst->_subtree = true;
	return bst;
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>::~BinarySearchTree ()
{
	if (_root != NULL)
        delete _root;
    _root = NULL;
	if (_left != NULL)
        delete _left;
    _left = NULL;
	if (_right != NULL)
        delete _right;
    _right = NULL;
}
// --------------------------------------------------------------
template <class DataType>
bool BinarySearchTree<DataType>::isEmpty()
{
	return (_root == NULL);
}
// --------------------------------------------------------------
template <class DataType>
int BinarySearchTree<DataType>::height ()
{
	if (isEmpty()) return 0;
    return (1 + max (_left->height(), _right->height()));
   	// max() is in stdlib.h
}
// --------------------------------------------------------------
template <class DataType>
int BinarySearchTree<DataType>::size ()
// returns the number of nodes in the tree
{
	if (isEmpty())
		return 0;
	return (1 + _left->size() + _right->size());
}
// --------------------------------------------------------------
template <class DataType>
DataType& BinarySearchTree<DataType>::root ()
{
	if (isEmpty()) throw BinaryTreeEmptyTree();
	return *_root;
}
// returns data from the root
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::left () { return _left; }
// returns the left subtree
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::right (){ return _right; }
// returns the right subtree
// --------------------------------------------------------------
template <class DataType>
bool BinarySearchTree<DataType>::subtree() { return _subtree; }
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::getYTree() {return _yTree;}
//returns the yTree member
// --------------------------------------------------------------
template <class DataType>
int BinarySearchTree<DataType>::getID() {
    return id;
}
//---------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::makeEmpty ()
{
	//if (_subtree) throw BinarySearchTreeChangedSubtree();
	if (_root != NULL)
   		delete _root;
    _root = NULL;
	if (_left != NULL)
	   	delete _left;
    _left = NULL;
	if (_right != NULL)
	   	delete _right;
    _right = NULL;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::copyTree(BinarySearchTree<DataType>* bst) //supplied code
{
	_root = bst->_root;
	_left = bst->_left;
	_right = bst->_right;
	_yTree = bst->_yTree;
	id = bst->getID();
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::_makeNull () //supplied code
{
	_root = NULL;
	_left = NULL;
	_right = NULL;
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_find (const DataType& data) // supplied code
{
	BinarySearchTree<DataType>* bst = this;
	while (true)
	{
		if (bst->isEmpty())
			return bst;
		if (*(bst->_root) < data)
		{
			bst = bst->_right;
		}
		else if (*(bst->_root) > data)
		{
            bst = bst->_left;
		}
		else
		{
			return bst;
		}
	}
}
// --------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::find_coord (DT& X, DT& Y) { //method to find coordinates
    BinarySearchTree<DT> *tempX = _find(X); //using this to easily call _find and isEmpty on X
    if (!(tempX->isEmpty())) { //if x is not empty then go into ytree and try to find y
        BinarySearchTree<DT> *tempY = tempX->_yTree->_find(Y);//same thing as tempX but for Y
        if (!(tempY->isEmpty())) { //if Y is found in the tree then cout the statement
            cout << "The coordinates " << X << ", " << Y << " is found in the tree with ID value " << tempY->id << endl;
        } else { //else the coordinate is not found
            cout << "Sorry!!! Coordinate is not found in the X tree" << endl;
        }
    } else { //else the coordinate is not found
        cout << "Sorry!!! Coordinate is not found in the X tree" << endl;
    }
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_insert (const DataType& data) //this is the supplied code
{
	//if (_subtree) throw BinarySearchTreeChangedSubtree();
	BinarySearchTree<DataType>* bst = _find (data);
	if (bst->isEmpty())
	{
		bst->_root = new DataType (data);
		bst->_left = makeSubtree ();
		bst->_right = makeSubtree ();
	}
	else
	{
        delete bst->_root;
		bst->_root = new DataType (data);
	}
	return bst;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::insert(DataType& X, DataType& Y, int ID) { //insert method uses supplied _insert method
    BinarySearchTree<DataType>* temp1 = new BinarySearchTree<DataType>(); //initializes temp variable
    temp1 = this->_find(X); //sets it equal to the find method return variable to make it easy to call methods on
    if(temp1->isEmpty()){ //if is empty then insert X
        BinarySearchTree<DataType>* BST1 = _insert(X);
        if (BST1->getYTree() == NULL) { //if ytree is null then create a new bst to initialize the ytree then insert Y
            BST1->_yTree = new BinarySearchTree<DataType>();
            BST1->_yTree->_insert(Y);
            BST1->_yTree->id = ID;
            //this->_find(X)->_yTree->id = ID;
        }
        else { //else add another ynode to the existing ytree
            BinarySearchTree<DataType>* BST2 = new BinarySearchTree<DataType>();
            BST2 = getYTree()->_insert(Y);
            this->_find(X)->_yTree->id = ID;
        }
    }
    else { //else go into the x tree
        if(temp1->getYTree() == NULL) { //then if ytree is null make a new bst and initialize it and insert y
            this->_find(X)->_yTree = new BinarySearchTree<DataType>();
            this->_find(X)->_yTree->_insert(Y);
            this->_find(X)->getYTree()->id = ID;
        }
        else { //if ytree exists add a new ynode to ytree
            BinarySearchTree<DataType>* BST2 = new BinarySearchTree<DataType>();
            BST2 = temp1->getYTree()->_insert(Y);
            temp1->getYTree()->_find(Y)->id = ID;
        }
    }

}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::_remove (const DataType& data)
{
	//if (_subtree) throw BinarySearchTreeChangedSubtree();
	BinarySearchTree<DataType>* bst;
	BinarySearchTree<DataType>* bst2;
	BinarySearchTree<DataType>* bst3;

	bst = _find (data);
	if (bst->isEmpty()) throw BinarySearchTreeNotFound();

    // dispose of the existing data; the pointer will be overwritten
    delete bst->_root;

    // .............................................................
	if (bst->_left->isEmpty())
	{
        // the left subtree exists, but the pointer will be overwritten,
        // so we must dispose of it
        delete bst->_left;
        bst2 = bst->_right;		// save the pointer to the right subtree
		bst->copyTree (bst2);	// copy the right subtree;
        // this empties tree if right empty
        bst2->_makeNull ();		// prepare right subtree for deletion
        delete bst2;				// delete right subtree to avoid garbage
	}

	else if (bst->_right->isEmpty())
	{
        // the right subtree exists, but the pointer will be overwritten,
        // so we must dispose of it
        delete bst->_right;
        bst2 = bst->_left;		// save the pointer to the left subtree
		bst->copyTree (bst2);	// copy the left subtree
        bst2->_makeNull ();		// prepare left subtree for deletion
        delete bst2;				// delete left subtree to avoid garbage
	}

	else		// both subtrees non-empty
	{
        // move to the right
		bst2 = bst->_right;
        // then move down to the left as far as possible
		while (!bst2->_left->isEmpty()) bst2 = bst2->_left;
        // overwrite the data pointer
		bst->_root = bst2->_root;

        // bst2's left child is known to be empty and pointer will be overwritten
     	delete bst2->_left;
        // now bst2's right child is copied into it
		if (bst2->_right->isEmpty())
        {
	     	delete bst2->_right;
            bst2->_makeNull();
        }
		else
        {
            bst3 = bst2->_right;
            bst2->copyTree(bst2->_right);
            bst3->_makeNull ();
            delete bst3;
        }
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::remove (DataType& X, DataType& Y) {
    BinarySearchTree<DataType>* tempX = _find(X); //sets xnode equal to the thing to make calls easier
    if (!(tempX->isEmpty())) { //checks to see if xnode is empty, if so then display the error message
        BinarySearchTree<DataType>* tempY = tempX->_yTree->_find(Y); //sets the ynode equal to tempy to call functions on
        if(!(tempY->isEmpty())) { //checks to see if the node is empty, if not displays the error message
            tempY->id = 0; //sets the id of the node to 0, basically deleting it
            tempY->_remove(Y); //removes the ynode
            if (tempX->_yTree->size() == 0) {
                tempX -> _remove(X); //if the ytree is size zero then delete the xnode
            }
        }
        else {
            cout << "The element you are trying to remove is not in the tree " << endl; //if not in ytree then cout this
        }
    }
    else {
        cout << "The element you are trying to remove is not in the tree " << endl; //if not in xtree then cout this
    }
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::rangeSearch (const DataType& low, const DataType& high) //searches the y tree for a node within the range
{
	if (isEmpty()) return;
	if (*_root >= low)
    {
        _left->rangeSearch(low,high);
		if (*_root <= high)
		{
			cout << *_root << "  ";
		}
    }
	if (*_root <= high)
        _right->rangeSearch(low,high);
}
// -----------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::rangesearch(DT& X1, DT& X2, DT& Y1, DT& Y2) { //if the xnode is within the range the
    //method calls rangeSearch on the yTree with the y1 and 2 ranges and cout's the schtuff
    if (isEmpty()) return;
    if ((*_root >= X1))
    {
        _left->rangesearch(X1,X2, Y1, Y2);
        if (*_root <= X2){
            cout << *_root << " : ";
            _yTree->rangeSearch(Y1, Y2);
            cout << endl;
        }
    }
    if (*_root <= X2)
        _right->rangesearch(X1,X2, Y1, Y2);
}
// -----------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::display() { // calling the respective display methods to display the bst
    cout << "INORDER TRAVERSAL: " << endl;
    this->inorder();
    cout << "PREORDER TRAVERSAL: " << endl;
    this->preorder();
}
// ------------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::preorder() {
    if (!(isEmpty())) {//displaying the binary tree in root left right format for inorder using leeft and right pointers then displaying
        // the ytree with the xtree root
        cout << this->root() << ": " << endl;
        (this->getYTree()->yPreorder());
        cout << endl;
        (this->left()->preorder());
        (this->right()->preorder());;

    }
}
// --------------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::inorder() {
    if (!(isEmpty())) { //displaying the binary tree in left root right format for inorder using leeft and right pointers then displaying
        // the ytree with the xtree root
        (this->left()->inorder());
        cout << this->root() << ": " << endl;
        (this->getYTree()->yInorder());
        cout << endl;
        (this->right()->inorder());
    }
}
// --------------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::yInorder() { //inorder cout statements of ytree, left root right
    if (!(isEmpty())) {
        (this->left()->yInorder());
        cout << " " << this->root() << "(" << getID() << ") ";
        (this->right()->yInorder());

    }
}
// --------------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::yPreorder() { //preorder cout statements of the ytree, root left right
    if (!(isEmpty())) {
        cout << " " << this->root() << "(" << getID() << ") ";
        (this->left()->yPreorder());
        (this->right()->yPreorder());
    }
}
// --------------------------------------------------------------
template <class DataType>
int BinarySearchTree<DataType>::getInorderTraversal(BinarySearchTree<DataType>* node, BinarySearchTree<DataType>** inOrderArray, int index)
{ //i honestly dont know how this method works cause it was given to me lololol
    try{
        if (node->isEmpty()) throw BinarySearchTreeNotFound();
    }
    catch(BinarySearchTreeNotFound e){
        cout << "No tree for inorder traversal" << endl;
        return index;
    }


    if (!this->isEmpty()) {
        if(node->left()->_root != NULL)
        {
            index = node->left()->getInorderTraversal(node->left(), inOrderArray, index);
        }

        inOrderArray[index++] = node;

        if(node->right()->_root != NULL)
        {
            index = node->right()->getInorderTraversal(node->right(), inOrderArray, index);
        }
    }
    return index;
}
// ----------------------------------------------------------------------------------------------------------------------------------
template<class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::GlobalRebalance(BinarySearchTree<DataType>** inOrderArray, int l, int r)
{
    int mid = 0;
    BinarySearchTree<DataType>* temp = new BinarySearchTree<DataType>(); //initializing temporary variable

    if(l <= r)
    {
        mid = ((l + r) / 2);
        temp->copyTree(inOrderArray[mid]); //set the root as the middle of l and r
        temp->_left = GlobalRebalance(inOrderArray, l, mid - 1); //balance the left nodes
        temp->_right = GlobalRebalance(inOrderArray, mid + 1, r); //balance all of the right nodes
    }

    return temp; //returns the ynode with the correctly balanced nodes
}
// ----------------------------------------------------------------------------------------------------------------------------------




#endif
