/*
 *    Data Structures Featuring C++  (c) 2021 Sridhar Radhakrishnan
 */

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main()
{
    BinarySearchTree<int> bst (100);

    cout <<"Initially the tree has  "<< bst << endl;

    bst.setYTree(new BinarySearchTree<int>(100));

    bst._insert (20);
    cout <<"After Insertion of 20:  "<< bst << endl;

    bst._insert (10);
    cout <<"After Insertion of 10:  "<< bst << endl;

    bst._insert (200);
    cout <<"After Insertion of 200:  "<< bst << endl;

    bst._insert (25);
    cout <<"After Insertion of 25:  "<< bst << endl;

    bst._insert (30);
    cout <<"After Insertion of 25:  "<< bst << endl;

    cout << "Trying to find 30..." << endl;
    try {
        bst.find(30);
        cout<<endl;
    }
    catch (BinarySearchTreeNotFound e) {
        cout << "Element 30 not found!!" << endl;
    }

    bst.remove(25);
    cout<<"After removal of 25:"<<bst<<endl;

    cout << "Trying to find 25..." << endl;
    try {
        bst.find(25);
    }
    catch (BinarySearchTreeNotFound e) {
        cout << "Element 25 not found!!" << endl;
    }

    bst.remove(100);
    cout<<"After removal of 100:"<<bst<<endl;

    bst.remove(20);
    cout<<"After removal of 20:"<<bst<<endl;

    bst.remove(10);
    cout<<"After removal of 10:"<<bst<<endl;

    bst.display();

    return 0;
}