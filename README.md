# Solving-8puzzle-use-BFS-and-DFS

This project consists of two parts:
1)Node class
2)main

1.1) In this class, I create the platform necessary to solve the puzzle. In this class, I have defined functions as follows, which I will explain.

2.1) After creating the necessary platform for our puzzle, we go to the implementation of algorithms. I have defined the game algorithms in the same way as the exercise solving class in main, because I think they belong to main. In the below, I will describe the functions and algorithms used to solve the puzzle.

2.2)BFS algorithm

![image](https://user-images.githubusercontent.com/61280030/209734584-4f344557-cc92-4556-99c3-79708d546b1b.png)

2.2.1)The solveBFS function works in such a way that the user gives it 3 inputs. The first input is the initial Node or actually the puzzle that the user wants to solve. The second input is the final state vector that the user wants to reach. The third input is the depth that the user wants the program to check up to that depth. It also works in this way that from the initial Node that the user enters, we start creating all the movement states for the user's Node and then the child. We check the results that are stored in the children vector (so it checks every depth in a linear way, so the algorithm used in it is a form of the BFS algorithm).Now, if we find the answer, we store the route taken and the nodes whose changes caused us to reach the answer in a chain-like manner in the solution vector, and then using the reverse function and also the printPuzzle function, we start to Print the necessary steps that must be taken to get the answer. Now, if we do not get the answer, first we check whether the number of depths we have checked is greater than the depth entered by the user or not. It has not arrived. Now, if we had checked less than the number of depths entered by the user, we will get help from the contains function. Now I will discuss how the contains function is a function.

2.2.2)contains function: Suppose I move zero down in the current node. When I get the child resulting from this node, I move its zero up, I will reach the parent node again, and so I will count it as a duplicate! With the help of the contains function, I will check that this does not happen. Now we will put the desired children in the openList and then we will go through this process again.

2.3)DFS algorithm

![image](https://user-images.githubusercontent.com/61280030/209734699-988cfc98-057e-4df7-aeab-21d23988c4c9.png)

2.3.1)Everything is similar to solveBFS and contains, but with the difference that by changing the types of openList and closedList from queue to stack, I prepare the ground to have a deep check instead of a surface check, and if we do not get the answer to the desired depth of the user, check Nodes stored in openList, I will start building the rest of the tree up to that depth and I will start checking the depth of each of the branches. As all the branches were checked in depth and we did not get the answer to the depth of the user's content, it will be printed. Sorry I haven't got the answer yet.


3)Tets

![image](https://user-images.githubusercontent.com/61280030/209735313-33cb2f08-77b8-41f6-b046-7658e484c5d4.png)

