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

    BinarySearchTree<int> InputBST = *new BinarySearchTree<int>();

    while (cin >> command) {
        if (command == INSERT) {
            cin >> x, y, id;
            InputBST.insert(x, y, id);
        }
        else if (command == FIND) {
            cin >> x, y;
            InputBST.find(x);
        }
        else if (command == PRINT) {
            InputBST.display();
        }
        else if (command == BALY) {
            cin >> y;
            InputBST.g
        }
        else if (command == RANGESEARCH) {
            cin >> xRange1, xRange2, yRange1, yRange2;
        }
        else if (command == REMOVE) {

        }
        else {
            cout << "Invalid Command." << endl;
        }
    }

    return 1;
}
