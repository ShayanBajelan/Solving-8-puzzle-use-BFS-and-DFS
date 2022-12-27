#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <stack>
#include <string>
#include <cstdlib>
#define BOLDBLACK "\033[38;5;0m"   /* Bold Black */
#define BLUE "\033[34m"               /* Blue */
#define WHITE "\033[37m"              /* White */
#define RED     "\033[31m"      /* Red */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */


class Node
{
public:
    std::vector<Node *> children;
    std::vector<int> puzzle;
    Node *parent;
    Node(std::vector<int> puzzle, Node *parent);
    ~Node() = default;
    void printPuzzle();
    int findZero();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};

#endif