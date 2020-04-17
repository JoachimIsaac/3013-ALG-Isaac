///////////////////////////////////////////////////////////////////////////////
//
// Author:           Joachim Isaac 
// Email:            joachimvivian3@gmail.com
// Label:            UVA(1112) Mice and Maze
// Title:            Shortest Path UVA(1112)
// Course:           3013
// Semester:         Spring 2020
//
// Description:  Problem based on mice in a maze, we want to find the shortest
//               path to exsit the maze. 
//
//
//      
/////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <iterator>
#include <vector> 
#include <map> 
#include<string>  
using namespace std;





const int FLAG = 1000000000;//Acts as an indicator for absence of a connection.

int maxVertexes = 100 + 10;

int testCases, vertexes, edges, exitCells, t;

int u, v, w;

// Nested vectors (Adjacency list)
vector<vector<int>> AdjList(maxVertexes , vector<int>(maxVertexes));

//Floyd warshall algorthim to help solve the problem.
void floyd_warshall(){
    for(int k = 0; k < vertexes; k++){
        for(int i = 0; i < vertexes; i++){
            for(int j = 0; j < vertexes; j++){
                //Compares the currenct vertex connection with the intermediate vertex connection
                //then takes the minimum.
                AdjList[i][j] = min(AdjList[i][j], AdjList[i][k] + AdjList[k][j]);

            }
        }
    }

}


int main(int argc, char **argv) {

    string answer = ""; // variable that holds answer 

    cin >> testCases; // Take intest cases first. 


    while(testCases > 0){ // While testCases variable is great than 0 we loop.

        cin >> vertexes; // read in the number of cells in the grid.

        cin >> exitCells; // read in the the number of the exit cell.

        exitCells = exitCells - 1; // minus 1 from it and store it again.

        cin >> t;//read in time

        cin >> edges;// read in number of connections.

        //Load the flag in every postion [i][j]
        //then load 0 at [i][i] 
        for(int i = 0; i < vertexes; i++){
            for(int j = 0; j < vertexes; j++){
                
                AdjList[i][j] = FLAG;
            }

            AdjList[i][i] = 0;// this eliminates the possiblity of loops.
        }

        // This is where we start to load the 
        // adjaceny list values.
        for( int i = 0; i < edges; i++){
            cin >> u; //row

            u = u - 1;//row

            cin >> v;//col

            v = v - 1;//col

            cin >> w;//value
            
            AdjList[u][v] = w; // value stored
        }

        floyd_warshall();

        int count = 0;// counter for how long the path is.

        for(int i = 0; i < vertexes; i++){
            if(AdjList[i][exitCells] <= t) count++;
        }

        answer += to_string(count) + "\n";
        
        //Only adds a space to the output if 
        //we are not at the end of a test case.
        //adds a space to the end of the string 
        //reduces the number of test cases 
        //in this case because this is how 
        //UVA will accept it based on presentation.
        //the debug tool would need 'testCases--;' to be 
        //at the end. 
        testCases--; 
        if(testCases != 0) answer += '\n';
        //testCases--;  
        
       
    }

 cout << answer;

}

//Ends here
//./main < input1
//./main < input2
//./main < input3

// continue looping.

// g++ = compile my program