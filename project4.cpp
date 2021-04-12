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



int main() {
    char command;
    int x, y, id;
    int xRange1, xRange2, yRange1, yRange2;

    BinarySearchTree<int>* InputBST = new BinarySearchTree<int>();
    BinarySearchTree<int>** inorderArr;

    while (cin >> command) {
        if (command == INSERT) {
            cin >> x >> y >> id;

            //cout << "Insert: " << "(" << x << "," << y << ")" << "ID:" << id << endl; this was a tester thing for my main method, ignore this


            InputBST->insert(x, y, id); //inserting the x and y value into the bst with the id
            cout << x << " " << y << " " << id << endl; //displaying the coordinate inserted if it was successful
        }
        else if (command == FIND) {
            cin >> x >> y;
            cout << "Find: " << x << " " << y << endl; //displays the coordinate needed
            cout << endl;
            InputBST->find_coord(x, y); //finds the coordinate supplied
        }
        else if (command == PRINT) {
            cout << "Print" << endl;
            InputBST->display(); //displays the whole bst
            cout << endl; //adds and endl
        }
        else if (command == BALY) {
            cin >> y; //takes in the schtuff
            cout << "Y tree balance" << endl;
            cout << y << endl; //displays the ynode to balance
            int n = InputBST->_find(y)->getYTree()->size(); //sends the ytree size to a var
            inorderArr = new BinarySearchTree<int>*[n]; //creates a bst array with the size of the ytree
            BinarySearchTree<int>* yTree = InputBST->_find(y)->getYTree(); //creates a ytree
            InputBST->getInorderTraversal(InputBST->_find(y)->getYTree(), inorderArr, 0); //gets an array with an inorder representation of the ytree
            yTree->copyTree(InputBST->GlobalRebalance(inorderArr, 0, n-1)); //copies the balanced tree to the yTree
        }
        else if (command == RANGESEARCH) {
            cin >> xRange1 >> xRange2 >> yRange1 >> yRange2; //takes in range inputs

            cout << "Range search " << endl;
            cout << xRange1 << " " << xRange2 << " " << yRange1 << " " << yRange2 << endl; //displays the x and y range
            InputBST->rangesearch(xRange1, xRange2, yRange1, yRange2); //calls the range search
            //to get the coordinate within the range
        }
        else if (command == REMOVE) {
            cin >> x >> y; //takes in the coordinate to remove

            cout << "Remove: " << x << " " << y << endl;
            InputBST->remove(x, y); //removes the input coordinate
        }
        else {
            cout << "Invalid Command." << endl; //sends an output to the console telling user
            //they inputted an invalid command
        }
    }

    //delete [] InputBST;

    return 0;
}
