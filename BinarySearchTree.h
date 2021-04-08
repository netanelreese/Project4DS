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
class BinarySearchTreeChangedSubtree : BinarySearchTreeException {};
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
	DataType* _root;
	BinarySearchTree<DataType>* _left;
	BinarySearchTree<DataType>* _right;
	BinarySearchTree<DataType>* _yTree;
	int id;
	bool _subtree;
	virtual BinarySearchTree<DataType>* makeSubtree();
	virtual void copyTree (BinarySearchTree<DataType>* bst);
	virtual void _makeNull ();
	BinarySearchTree<DataType>* _find (const DataType& data);
public:
	BinarySearchTree ();
	BinarySearchTree (const DataType& data);
    BinarySearchTree(DataType& X, DataType& Y, int ID);
    BinarySearchTree(BinarySearchTree<DataType>& copy);
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
	virtual DataType find (const DataType& q);
	virtual void remove (const DataType& data);
	virtual void rangeSearch (const DataType& low, const DataType& high);
	virtual BinarySearchTree<DataType>* _insert (const DataType& data);
	virtual void insert(DataType& x, DataType& y, int ID);
	virtual BinarySearchTree<DataType>* getYTree();
	//virtual void global_rebalance(BinarySearchTree<DataType>* IA, int left, int right);
	virtual void display();
    virtual void preorder();
    virtual void inorder();
    virtual void setYTree(BinarySearchTree<DataType>* yTree);

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
	_subtree = false;
	id = 0;
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
BinarySearchTree<DT>::BinarySearchTree(BinarySearchTree<DT>& copy) {
    if (copy._subtree) {
        _subtree = true;
    }
    else {
        _subtree = false;
    }
    _root = copy._root;
    _yTree = copy._yTree;
    _left = copy._left;
    _right = copy._right;
    id = copy.id;
    _yTree->id = ID;
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
	if (_subtree) throw BinarySearchTreeChangedSubtree();
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
void BinarySearchTree<DataType>::copyTree(BinarySearchTree<DataType>* bst)
{
	_root = bst->_root;
	_left = bst->_left;
	_right = bst->_right;
	_yTree = bst->_yTree;
	id = bst->getID();
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::_makeNull ()
{
	_root = NULL;
	_left = NULL;
	_right = NULL;
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_find (const DataType& data)
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
template <class DataType>
DataType BinarySearchTree<DataType>::find (const DataType& q)
{
	BinarySearchTree<DataType>* bst = _find (q);
	try{
		if (bst->isEmpty()) throw BinarySearchTreeNotFound();
		cout<<"\nThe element "<<bst->root()<<" is found in the tree"<<endl;
		return bst->root();
	}
	catch(Exception e)
	{
		cout<<"\nSorry!!! Element is not found in the tree"<<endl;
		return q; //We need to fix this
	}
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_insert (const DataType& data)
{
	if (_subtree) throw BinarySearchTreeChangedSubtree();
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
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::insert(DataType& X, DataType& Y, int ID) {
    BinarySearchTree<DataType>* temp1 = new BinarySearchTree<DataType>();
    temp1 = _find(X);
    if(temp1 == NULL) temp1 = _insert(X);
    (*temp1).id = -1;
    BinarySearchTree<DataType>* temp2 = ((*temp1).getYTree())->_insert(Y);
    (*temp2).id = ID;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::remove (const DataType& data)
{
	if (_subtree) throw BinarySearchTreeChangedSubtree();
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
void BinarySearchTree<DataType>::rangeSearch (const DataType& low, const DataType& high) //TODO
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
// ---------------------------------------------------------------
//TODO: GLOBAL REBALANCE
// -----------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::display() {
    cout << "Preorder Traversal:" << endl;
    preorder();
    inorder();
}
// ------------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::preorder() {
    if (_root != NULL) {
        cout << _root << " ";
        if (_yTree != NULL) {
            _yTree->preorder();
        }
        (*_left).preorder();
        (*_right).preorder();

    }
}
// --------------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::inorder() {
    if (_root != NULL) {
        (*_left).inorder();
        if (_yTree != NULL) {
            _yTree->inorder();
        }
        cout << _root << " ";
        (*_right).inorder();
    }
}
// --------------------------------------------------------------------
template <class DT>
void BinarySearchTree<DT>::setYTree(BinarySearchTree<DT>* yTree) {
    _yTree = new BinarySearchTree<DT>();
    _yTree->copyTree(yTree);
}

#endif
