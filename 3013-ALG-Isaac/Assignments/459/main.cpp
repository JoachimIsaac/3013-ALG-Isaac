

///////////////////////////////////////////////////////////////////////////////
//
// Author:           Joachim Isaac 
// Email:            joachimvivian3@gmail.com
// Label:            UVA Problem 459 (Graph Connectivity)
// Title:            459(Graph Connectivity)
// Course:           3013
// Semester:         Spring 2020
//
// Description: Problem asked to could the number of disconnected graphs
//              for many test cases. 
//       
//       
//      
//
/////////////////////////////////////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

typedef vector<int> vi;    // vector of integers
typedef pair<int, int> ii; // pair of integers
typedef vector<ii> vii;    // vector of pairs
typedef vector<string> vc;

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;     // container to keep track of who get visited
vector<vii> AdjList; // AdjList stores our edge lists
       


/**
 * Depth First Search
 * 
 * Params:
 *  int u - starting node id
 * 
 */
void dfs(int u) {
    // In DFS we use a stack structure to keep track of who to visit next.
    // Recursive acts just like a stack so we dont need to declare any
    // structure to keep track for us, we let the recursive calls do it for us

    been_visited[u] = VISITED; // mark u as visited
    // cout << u << " ";// write u to stdout

    // Loop overadjacency list looking for connections
    for (int j = 0; j < (int)AdjList[u].size(); j++) {

        // v is a pair representing a neighbor and the
        // weight of the edge from u->v
        ii v = AdjList[u][j];

        // check to see if our neighbor was visited
        if (been_visited[v.first] == UNVISITED) {
            dfs(v.first);  
        }
    }
}

/**
 * Breadth First Search
 * 
 * Params:
 *     int u - starting node id
 */
void bfs(int u) {
    // This is an iterative solution, so we declare a
    // queue to keep track of who gets visited next
    queue<int> q;

    // Add u to our q
    q.push(u);

    // While q has nodes in it
    while (!q.empty()) {

        int s = q.front(); // remove front node

        been_visited[s] = VISITED; // visit front node
        q.pop();                   // remove from queue

        // cout << s << " "; // output

        // look for any unvisited neighbors of u
        for (int t = 0; t < (int)AdjList[s].size(); t++) {

            // v is a pair representing a neighbor and the
            // weight of the edge from s->v
            ii v = AdjList[s][t];

            // If neighbor hasn't been visited, add to queue
            // and mark as visited
            if (been_visited[v.first] == UNVISITED) {
                q.push(v.first);
                been_visited[v.first] = VISITED;
            }
        }
    }
}

/**
 * greedy - A greedy traversal needs some value to choose
 *          if its going to be a "greedy" choice. So un-weighted 
 *          graphs will not work.
 * 
 * 
 * 
 */
void greedy() {
}

int main(int argc, char **argv) {

    int numberOfCases;
    char largest;
    int n;
    string vertexConnection = "####";
   
    string temp_case;
    vc letter_container;


    cin >> numberOfCases; //Reads in Number of Cases.

    
    //Load all the connections into a vector to be processed. 
    while (cin >> vertexConnection)
        letter_container.push_back(vertexConnection);


    //Loop over the all connections.
    for (int i = 0; i < letter_container.size(); i++) {
    
        //Connection of only length one Represents the largest vertex.
        if (letter_container[i].size() == 1) {
           
            //Store largest vertex.
            largest = letter_container[i].at(0);

            
            //Change largest to int
            n = int(largest) - int('A');

            
            //Resize AdjList vector and been_visted vector.
            AdjList.resize(n + 1);
            been_visited.resize(n + 1, UNVISITED);

            //Connection of length two Represents a connection.
            //connections are inserted into the adjcentcy list.
        } else if (letter_container[i].size() == 2) {
            
            //Store pair of characters, representing the connection.
            vertexConnection = letter_container[i];
           
            //Seperate them to characters and convert them to ints.
            int firstNode = int(vertexConnection.at(0)) - int('A');
            int secondNode = int(vertexConnection.at(1)) - int('A');

           

            //Load in adjacency list.
            AdjList[firstNode].push_back(make_pair(secondNode, 10));
            AdjList[secondNode].push_back(make_pair(firstNode, 10));

        }
        
        // If we are at the end of a test case run 
        // or at the end of the connections array, run bfs.
        if (letter_container[i + 1].size() == 1 || i == letter_container.size() - 1) {
            

            int numberOfSubgraphs = 0;//Number of subgraphs.

            for (int i = 0; i < been_visited.size(); i++) {

                if (been_visited[i] == UNVISITED) {
            
                    bfs(i);
                    numberOfSubgraphs++;
                }
            }
            cout << numberOfSubgraphs << endl;
            
        
            been_visited.clear();//empty out the been_visted array so that ir can be resized.
            AdjList.clear();//empty out the AdjList array so that ir can be resized.

            //Only adds a space to the output if 
            //we are not at the end of a test case.
            //Need an endline at the end of debug tool but not 
            // for the submission on UVA site.
            if (!(i == letter_container.size() - 1)) {
              cout << endl;
            
            }
        }
    }
    
}

//Ends here
//./main < input1
//./main < input2
//./main < input3



// g++ = compile my program

// g++ <program to compile> -o <whats my output file>

// g++ main.cpp -o whateveryouwant
