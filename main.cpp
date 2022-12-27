#include "Node.h"

// Functions For BFS Solve :
bool contains(std::queue<Node *> q, Node *n);
void solveBFS(Node init, std::vector<int> goalState, int noOfDepths);
// ***************************************************
// Functions For DFS Solve :
bool contains_DFS(std::stack<Node *> q, Node *n);
void solveDFS(Node init, std::vector<int> goalState, int noOfDepths);

int main()
{
    std::string input0;
    std::vector<int> init{};
    std::vector<int> goalState{};
    int input_key{};
    int inputKey1{};
    std::cout << BOLDMAGENTA << "Choose the way you want to play : \033[0m" << std::endl;
    std::cout << '\n'
              << BOLDCYAN << "1)Solve a random 8 puzzle\033[0m" << '\n'
              << BOLDCYAN << "2)Solve your Custom 8 puzzle\033[0m" << '\n'
              << BOLDCYAN << "3)Solve your normal 8 puzzle\033[0m" << '\n'
              << '\n'
              << BOLDMAGENTA << "Please Press a Key (1 or 2 or 3) : \033[0m";
    std::cin >> input_key;
    std::cout << '\n';
    if (input_key != 1 && input_key != 2 && input_key != 3)
    {
        while (true)
        {
            std::cerr << "\033[48;5;253m" << BOLDRED << "Eror ! No matching key please try again...\033[0m" << std::endl;
            std::cout << '\n'
                      << BOLDMAGENTA << "Please Press a Key (1 or 2 or 3) : \033[0m" << '\n';
            std::cin >> input_key;
            std::cout << '\n';
            if (input_key == 1 || input_key == 2 || input_key == 3)
                break;
        }
    }
    // Random puzzle :
    // **************************
    if (input_key == 1)
    {
        std::cout << "\033[48;5;253m" << BOLDRED << "Creating a random puzzle...\033[0m" << std::endl;
        std::cout << '\n';
        for (size_t i{}; i < 9; i++)
        {
            while (true)
            {
                srand(time(NULL));
                int randVal{};
                randVal = rand() % 9;
                if (randVal >= 0 && randVal < 9 && std::find(goalState.begin(), goalState.end(), randVal) == goalState.end())
                {
                    goalState.push_back(randVal);
                    break;
                }
            }
        }
        std::cout << BOLDCYAN << "I can solve ir with \033[4m\033[31mBFS\033[0m\033[36m \033[4m\033[31m(1)\033[0m\033[36m and \033[4m\033[31mDFS\033[0m\033[36m \033[4m\033[31m(2)\033[0m\033[36m.if \033[4m\033[31mBFS\033[0m\033[36m  press key \033[4m\033[31m1\033[0m\033[36m else press \033[4m\033[31m2.\033[0m" << std::endl;
        std::cout << '\n'
                  << BOLDMAGENTA << "Please press a key : \033[0m";
        std::cin >> inputKey1;
        std::cout << '\n';
        if (inputKey1 != 1 && inputKey1 != 2)
        {
            while (true)
            {
                std::cerr << "\033[48;5;253m" << BOLDRED << "Eror ! No matching key please try again...\033[0m" << std::endl;
                std::cout << '\n'
                          << BOLDMAGENTA << "Please Press a Key (1 or 2) : \033[0m";
                std::cin >> inputKey1;
                std::cout << '\n';
                if (inputKey1 == 1 || inputKey1 == 2)
                    break;
            }
        }
        // ********************************************
        if (inputKey1 == 1)
        {
            std::queue<Node *> openList0;
            std::queue<Node *> closedList0;
            Node *GOAL = new Node(goalState, NULL);
            openList0.push(GOAL);
            Node *initial = nullptr;
            srand(time(NULL));
            int noOfMoves = rand() % 100 + 100;
            int count{};
            while (count != noOfMoves)
            {
                Node *currentNode = openList0.front();
                closedList0.push(currentNode);
                openList0.pop();
                currentNode->moveLeft();
                currentNode->moveRight();
                currentNode->moveDown();
                currentNode->moveUp();
                for (auto i : currentNode->children)
                {
                    Node *currentChild = i;
                    if (!contains(openList0, currentChild) && !contains(closedList0, currentChild))
                    {
                        openList0.push(currentChild);
                    }
                }
                initial = currentNode;
                count++;
            }
            Node NewRoot = Node(initial->puzzle, NULL);
            std::vector<int> NewGoalSate{GOAL->puzzle};
            solveBFS(NewRoot, NewGoalSate, count);
        }
        if (inputKey1 == 2)
        {
            std::queue<Node *> openList0;
            std::queue<Node *> closedList0;
            Node *GOAL = new Node(goalState, NULL);
            openList0.push(GOAL);
            Node *initial = nullptr;
            srand(time(NULL));
            int noOfMoves = rand() % 7 + 20;
            int count{};
            while (count != noOfMoves)
            {
                Node *currentNode = openList0.front();
                closedList0.push(currentNode);
                openList0.pop();
                currentNode->moveLeft();
                currentNode->moveRight();
                currentNode->moveDown();
                currentNode->moveUp();
                for (auto i : currentNode->children)
                {
                    Node *currentChild = i;
                    if (!contains(openList0, currentChild) && !contains(closedList0, currentChild))
                    {
                        openList0.push(currentChild);
                    }
                }
                initial = currentNode;
                count++;
            }
            Node NewRoot = Node(initial->puzzle, NULL);
            std::vector<int> NewGoalSate{GOAL->puzzle};
            solveDFS(NewRoot, NewGoalSate, 26);
        }
    }
    // ********************************************
    if (input_key == 2)
    {
        std::cout << BOLDCYAN << "Please initial your init puzzle to solve : \033[0m" << std::endl;
        std::cout << '\n';
        int value{};
        for (size_t i{}; i < 9; i++)
        {
            while (true)
            {
                std::cout << BOLDMAGENTA << "Please input " << i + 1 << "'th number of your init puzzle : \033[0m";
                std::cin >> value;
                if (value >= 0 && value < 9 && std::find(init.begin(), init.end(), value) == init.end())
                {
                    init.push_back(value);
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    std::cout << '\n'
                              << "\033[48;5;253m" << BOLDRED << "EROR ! you probably entered out of range or repeated number ! please try another number between 0 and 9\033[0m" << std::endl;
                    std::cout << '\n';
                }
            }
        }
        // *******************************************************
        std::cout << '\n';
        std::cout << BOLDCYAN << "Please initial your GOAL puzzle to solve : \033[0m" << std::endl;
        std::cout << '\n';
        for (size_t i{}; i < 9; i++)
        {
            while (true)
            {
                std::cout << BOLDMAGENTA << "Please input " << i + 1 << "'th number of your GOAL puzzle : \033[0m";
                std::cin >> value;
                if (value >= 0 && value < 9 && std::find(goalState.begin(), goalState.end(), value) == goalState.end())
                {
                    goalState.push_back(value);
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    std::cout << '\n'
                              << "\033[48;5;253m" << BOLDRED << "EROR ! you probably entered out of range or repeated number ! please try another number between 0 and 9\033[0m" << std::endl;
                    std::cout << '\n';
                }
            }
        }
        std::cout << "\033[36mWe have \033[4m\033[31m2\033[0m\033[36m algorithms to solve puzzle called \033[4m\033[31mBFS\033[0m\033[36m and \033[4m\033[31mDFS\033[0m\033[36m :D " << '\n';
        std::cout << '\n'
                  << "if you want to slove it with \033[4m\033[31mBFS\033[0m\033[36m please press key \033[4m\033[31m1\033[0m\033[36m and if you want to solve it with \033[4m\033[31mDFS\033[0m\033[36m  press key \033[4m\033[31m2\033[0m" << std::endl;
        std::cout << '\n'
                  << "\033[32mPlease press a key : \033[0m";
        std::cin >> inputKey1;
        std::cout << '\n';
        if (inputKey1 != 1 && inputKey1 != 2)
        {
            while (true)
            {
                std::cerr << "\033[48;5;253m" << BOLDRED << "Eror ! No matching key please try again...\033[0m" << std::endl;
                std::cout << '\n'
                          << "\033[32mPlease Press a Key (1 or 2) : \033[0m";
                std::cin >> inputKey1;
                std::cout << '\n';
                if (inputKey1 == 1 || inputKey1 == 2)
                    break;
            }
        }
        if (inputKey1 == 1)
        {
            int depth{};
            std::cout << "\033[36mPlease enter depth of your \033[4m\033[31mBFS\033[0m\033[36m algorithm : \033[0m";
            std::cin >> depth;
            std::cout << '\n';
            Node initial = Node(init, NULL);
            solveBFS(initial, goalState, depth);
        }
        if (inputKey1 == 2)
        {
            int depth{};
            std::cout << "\033[36mPlease enter depth of your \033[4m\033[31mDFS\033[0m\033[36m algorithm : \033[0m";
            std::cin >> depth;
            std::cout << '\n';
            Node initial = Node(init, NULL);
            solveDFS(initial, goalState, depth);
        }
    }
    if (input_key == 3)
    {
        std::cout << BOLDCYAN << "Please initial your init puzzle to solve : \033[0m" << std::endl;
        std::cout << '\n';
        int value{};
        for (size_t i{}; i < 9; i++)
        {
            while (true)
            {
                std::cout << BOLDMAGENTA << "Please input " << i + 1 << "'th number of your init puzzle : \033[0m";
                std::cin >> value;
                if (value >= 0 && value < 9 && std::find(init.begin(), init.end(), value) == init.end())
                {
                    init.push_back(value);
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    std::cout << '\n'
                              << "\033[48;5;253m" << BOLDRED << "EROR ! you probably entered out of range or repeated number ! please try another number between 0 and 9\033[0m" << std::endl;
                    std::cout << '\n';
                }
            }
        }
        std::vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};
        std::cout << "\033[36mWe have \033[4m\033[31m2\033[0m\033[36m algorithms to solve puzzle called \033[4m\033[31mBFS\033[0m\033[36m and \033[4m\033[31mDFS\033[0m\033[36m :D " << '\n';
        std::cout << '\n'
                  << "if you want to slove it with \033[4m\033[31mBFS\033[0m\033[36m please press key \033[4m\033[31m1\033[0m\033[36m and if you want to solve it with \033[4m\033[31mDFS\033[0m\033[36m  press key \033[4m\033[31m2\033[0m" << std::endl;
        std::cout << '\n'
                  << "\033[32mPlease press a key : \033[0m";
        std::cin >> inputKey1;
        std::cout << '\n';
        if (inputKey1 != 1 && inputKey1 != 2)
        {
            while (true)
            {
                std::cerr << "\033[48;5;253m" << BOLDRED << "Eror ! No matching key please try again...\033[0m" << std::endl;
                std::cout << '\n'
                          << "\033[32mPlease Press a Key (1 or 2) : \033[0m";
                std::cin >> inputKey1;
                std::cout << '\n';
                if (inputKey1 == 1 || inputKey1 == 2)
                    break;
            }
        }
        if (inputKey1 == 1)
        {
            int depth{};
            std::cout << "\033[36mPlease enter depth of your \033[4m\033[31mBFS\033[0m\033[36m algorithm : \033[0m";
            std::cin >> depth;
            std::cout << '\n';
            Node initial = Node(init, NULL);
            solveBFS(initial, goalState, depth);
        }
        if (inputKey1 == 2)
        {
            int depth{};
            std::cout << "\033[36mPlease enter depth of your \033[4m\033[31mDFS\033[0m\033[36m algorithm : \033[0m";
            std::cin >> depth;
            std::cout << '\n';
            Node initial = Node(init, NULL);
            solveDFS(initial, goalState, depth);
        }
    }
    return 0;
}

// Functions For BFS Solve :
bool contains(std::queue<Node *> q, Node *n)
{
    bool exist = false;
    while (!q.empty())
    {
        if (q.front()->puzzle == n->puzzle)
            exist = true;
        q.pop();
    }
    return exist;
}

void solveBFS(Node init, std::vector<int> goalState, int noOfDepths)
{
    std::queue<Node *> openList;
    std::queue<Node *> closedList;
    openList.push(&init);
    bool goalFound = false;
    int count0 = 0;
    std::vector<Node *> solution;
    std::vector<Node *> vecForCheck;
    std::cout << "\033[48;5;253m" << BOLDRED << "Searching for BFS solution...\033[30;40m" << WHITE << std::endl;
    std::cout << '\n';
    while (!openList.empty() && !goalFound)
    {
        Node *currentNode = openList.front();
        closedList.push(currentNode);
        openList.pop();
        currentNode->moveUp();
        currentNode->moveDown();
        currentNode->moveRight();
        currentNode->moveLeft();
        for (auto i : currentNode->children)
        {
            Node *currentChild = i;
            if (currentChild->puzzle == goalState)
            {
                std::cout << "\033[32;1;4mGoal Found :D \033[0m" << std::endl;
                std::cout << '\n';
                // Once the goal is found the path is traced by recursively iterating through the parent nodes starting from goal node till the inital node is found
                Node *curr = currentChild;
                int count{0};
                solution.push_back(currentChild);
                while (curr->parent != NULL)
                {
                    count++;
                    curr = curr->parent;
                    solution.push_back(curr);
                }
                std::reverse(solution.begin(), solution.end());
                std::cout << BOLDCYAN << "printing solutionution :\033[0m" << std::endl;
                std::cout << '\n';
                std::cout << BOLDRED << "Problem : \033[0m" << std::endl;
                solution[0]->printPuzzle();
                std::cout << '\n';
                for (size_t i{1}; i < solution.size(); i++)
                {
                    int zeroPosition0 = solution[i - 1]->findZero();
                    int zeroPosition1 = solution[i]->findZero();
                    if ((zeroPosition1 - zeroPosition0) == 3)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Down\033[0m" << std::endl;
                    if ((zeroPosition1 - zeroPosition0) == -3)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Up\033[0m" << std::endl;
                    if ((zeroPosition1 - zeroPosition0) == 1)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Right\033[0m" << std::endl;
                    if ((zeroPosition1 - zeroPosition0) == -1)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Left\033[0m" << std::endl;
                    solution[i]->printPuzzle();
                    std::cout << std::endl;
                }
                std::cout << "\033[38;5;12mNo. of depths : " << count << WHITE << std::endl;
                goalFound = true;
            }
            if (currentChild->puzzle != goalState)
            {
                int count1{0};
                Node *curr = currentChild;
                while (curr->parent != NULL)
                {
                    count1++;
                    curr = curr->parent;
                }
                if (count1 > noOfDepths)
                {
                    std::cout << "\033[1m\033[31mFound no answer until depth you have entered :(\033[37m" << std::endl;
                    std::cout << '\n';
                    goalFound = true;
                    break;
                }
            }
            if (!contains(openList, currentChild) && !contains(closedList, currentChild))
            {
                openList.push(currentChild);
            }
        }
        count0++;
    }
    std::cout << "\033[38;5;4mNo. of nodes in closed list: " << count0 << WHITE << std::endl;
    std::cout << '\n';
}

// Functions For DFS Solve :

bool contains_DFS(std::stack<Node *> q, Node *n)
{
    bool exist = false;
    while (!q.empty())
    {
        if (q.top()->puzzle == n->puzzle)
            exist = true;
        q.pop();
    }
    return exist;
}

void solveDFS(Node init, std::vector<int> goalState, int noOfDepths)
{
    std::stack<Node *> openList;
    std::stack<Node *> closedList;
    openList.push(&init);
    bool goalFound = false;
    int count0 = 0;
    std::vector<Node *> solution;
    std::vector<Node *> vecForCheck;
    std::cout << "\033[48;5;253m" << BOLDRED << "Searching for DFS solution...\033[30;40m" << WHITE << std::endl;
    std::cout << '\n';
    while (!openList.empty() && !goalFound)
    {
        Node *currentNode = openList.top();
        closedList.push(currentNode);
        openList.pop();
        currentNode->moveUp();
        currentNode->moveDown();
        currentNode->moveRight();
        currentNode->moveLeft();
        for (auto i : currentNode->children)
        {
            Node *currentChild = i;
            if (currentChild->puzzle == goalState)
            {
                std::cout << "\033[32;1;4mGoal Found :D \033[0m" << std::endl;
                std::cout << '\n';
                // Once the goal is found the path is traced by recursively iterating through the parent nodes starting from goal node till the inital node is found
                Node *curr = currentChild;
                int count{0};
                solution.push_back(currentChild);
                while (curr->parent != NULL)
                {
                    count++;
                    curr = curr->parent;
                    solution.push_back(curr);
                }
                std::reverse(solution.begin(), solution.end());
                std::cout << BOLDCYAN << "printing solutionution :\033[0m" << std::endl;
                std::cout << '\n';
                std::cout << BOLDRED << "Problem : \033[0m" << std::endl;
                solution[0]->printPuzzle();
                std::cout << '\n';
                for (size_t i{1}; i < solution.size(); i++)
                {
                    int zeroPosition0 = solution[i - 1]->findZero();
                    int zeroPosition1 = solution[i]->findZero();
                    if ((zeroPosition1 - zeroPosition0) == 3)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Down\033[0m" << std::endl;
                    if ((zeroPosition1 - zeroPosition0) == -3)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Up\033[0m" << std::endl;
                    if ((zeroPosition1 - zeroPosition0) == 1)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Right\033[0m" << std::endl;
                    if ((zeroPosition1 - zeroPosition0) == -1)
                        std::cout << BOLDCYAN << "move \033[0m" << BOLDRED << i << BOLDCYAN << " to solve :" << BOLDRED << " Left\033[0m" << std::endl;
                    solution[i]->printPuzzle();
                    std::cout << std::endl;
                }
                std::cout << "\033[38;5;12mNo. of depths : " << count << WHITE << std::endl;
                goalFound = true;
            }
            if (currentChild->puzzle != goalState)
            {
                int count1{0};
                Node *curr = currentChild;
                while (curr->parent != NULL)
                {
                    count1++;
                    curr = curr->parent;
                }
                if (count1 > noOfDepths)
                {
                    currentNode = openList.top();
                    openList.pop();
                    if (openList.empty())
                    {
                        std::cout << "\033[1m\033[31mFound no answer until depth you have entered :(\033[37m" << std::endl;
                        std::cout << '\n';
                        goalFound = true;
                        break;
                    }
                }
            }
            if (!contains_DFS(openList, currentChild) && !contains_DFS(closedList, currentChild))
            {
                openList.push(currentChild);
            }
        }
        count0++;
    }
    std::cout << "\033[38;5;4mNo. of nodes in closed list: " << count0 << WHITE << std::endl;
    std::cout << '\n';
}
