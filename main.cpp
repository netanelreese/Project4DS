//
// Created by reese on 4/10/2021.
//

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

const char INSERT = 'I';
const char PRINT = 'P';
const char FIND = 'F';
const char BALY = 'Y';
//const char BALX = 'X';
const char RANGESEARCH = 'S';
const char REMOVE = 'R';

template<class DataType>
BinarySearchTree<DataType>* GlobalRebalance(BinarySearchTree<DataType>** inOrderArray, int l, int r)
{
    int mid = 0;
    BinarySearchTree<DataType>* temp = new BinarySearchTree<DataType>();

    if(l <= r)
    {
        mid = ((l + r) / 2);
        temp = inOrderArray[mid];
        temp->left(GlobalRebalance(inOrderArray, l, mid - 1));
        temp->right(GlobalRebalance(inOrderArray, mid + 1, r));
    }

    return temp;
}

int main() {
    char command;
    int x, y, id;
    int xRange1, xRange2, yRange1, yRange2;

    BinarySearchTree<int>* InputBST = new BinarySearchTree<int>();

    while (cin >> command) {
        if (command == INSERT) {
            cin >> x >> y >> id;

            //cout << "Insert: " << "(" << x << "," << y << ")" << "ID:" << id << endl; this was a tester thing for my main method, ignore this


            InputBST->insert(x, y, id); //inserting the x and y value into the bst with the id
            cout << x << " " << y << " " << id << endl;
        }
        else if (command == FIND) {
            cin >> x >> y;
            //cout << "Find: " << x << " " << y << endl;
            InputBST->find(x);
        }
        else if (command == PRINT) {
            cout << "Print" << endl;
            InputBST->display();
            cout << endl;
        }
        else if (command == BALY) {
            cin >> y;
            cout << "Y tree rebalance" << endl;

        }
        else if (command == RANGESEARCH) {
            cin >> xRange1 >> xRange2 >> yRange1 >> yRange2;

            cout << "Range search" << endl;
            cout << xRange1 << " " << xRange2 << " " << yRange1 << " " << yRange2 << endl;
            InputBST->rangeSearch(xRange1, xRange2);
            InputBST->getYTree()->rangeSearch(yRange1, yRange2);
        }
        else if (command == REMOVE) {
            cin >> x >> y;

            cout << "Remove :" << x << " " << y << endl;
            //InputBST.remove(x);
        }
        else {
            cout << "Invalid Command." << endl;
        }
    }

    //delete [] InputBST;

    return 1;
}