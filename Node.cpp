#include "Node.h"

Node::Node(std::vector<int> puzzle, Node *parent)
{
    this->puzzle = puzzle;
    this->parent = parent;
}

void Node::printPuzzle()
{
    std::cout << std::endl;
    std::cout << "\033[48;5;40m"
              << "\033[1m" << BOLDBLACK << puzzle[0] << ' ';
    std::cout << "\033[48;5;40m"
              << "\033[1m" << BOLDBLACK << puzzle[1] << ' ';
    std::cout << "\033[48;5;40m"
              << "\033[1m" << BOLDBLACK << puzzle[2] << "\033[30;40m" << std::endl;
    // **********************************************
    std::cout << "\033[48;5;60m"
              << "\033[1m" << BOLDBLACK << puzzle[3] << ' ';
    std::cout << "\033[48;5;60m"
              << "\033[1m" << BOLDBLACK << puzzle[4] << ' ';
    std::cout << "\033[48;5;60m"
              << "\033[1m" << BOLDBLACK << puzzle[5] << "\033[30;40m" << std::endl;
    // **********************************************
    std::cout << "\033[48;5;50m"
              << "\033[1m" << BOLDBLACK << puzzle[6] << ' ';
    std::cout << "\033[48;5;50m"
              << "\033[1m" << BOLDBLACK << puzzle[7] << ' ';
    std::cout << "\033[48;5;50m"
              << "\033[1m" << BOLDBLACK << puzzle[8] << "\033[30;40m";
    std::cout << WHITE << std::endl;
}

int Node::findZero()
{
    std::vector<int>::iterator it;
    it = std::find(puzzle.begin(), puzzle.end(), 0);
    auto zero = std::distance(puzzle.begin(), it);
    return (int)zero;
}

void Node::moveUp()
{
    int ZeroPosition = findZero();
    std::vector<int> temp{puzzle};
    if (ZeroPosition != 0 && ZeroPosition != 1 && ZeroPosition != 2)
    {
        std::swap(temp[ZeroPosition], temp[ZeroPosition - 3]);
    }
    Node *child = new Node(temp, this);
    children.push_back(child);
}

void Node::moveDown()
{
    int ZeroPosition = findZero();
    std::vector<int> temp{puzzle};
    if (ZeroPosition != 6 && ZeroPosition != 7 && ZeroPosition != 8)
    {
        std::swap(temp[ZeroPosition], temp[ZeroPosition + 3]);
    }
    Node *child = new Node(temp, this);
    children.push_back(child);
}

void Node::moveRight()
{
    int ZeroPosition = findZero();
    std::vector<int> temp{puzzle};
    if (ZeroPosition != 2 && ZeroPosition != 5 && ZeroPosition != 8)
    {
        std::swap(temp[ZeroPosition], temp[ZeroPosition + 1]);
    }
    Node *child = new Node(temp, this);
    children.push_back(child);
}

void Node::moveLeft()
{
    int ZeroPosition = findZero();
    std::vector<int> temp{puzzle};
    if (ZeroPosition != 0 && ZeroPosition != 3 && ZeroPosition != 6)
    {
        std::swap(temp[ZeroPosition], temp[ZeroPosition - 1]);
    }
    Node *child = new Node(temp, this);
    children.push_back(child);
}
