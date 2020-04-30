
#include <cstdio>
#include <cstring>
#include <iostream> 
using namespace std;

bool leftSide[2001][10001];
int cars[2001], previous[2001][10001];


void printDecision(int now, int length){ // prints whether the car should go on starboard 
                                            // or port
  if(!now){
    return;
  }
  else{
    printDecision(now - 1, previous[now][length]);

    puts(previous[now][length] == length ? "starboard" : "port");
  }
}


int main(){


  int numberOfTestCases;

  cin >> numberOfTestCases;//reads in number of test cases. 

  while(numberOfTestCases--){// while number of test cases is not zero.
    
    int lengthLimit;

    cin >> lengthLimit; 

    lengthLimit *= 100; // convert car length to centimeters. 

    
    memset(leftSide, false, sizeof(leftSide));//set all of the left side array to false.
    
    
    leftSide[0][0] = true; // load starting position as true.

    int now = 1, currSum = 0, last = 0, length;

  //while there is something to read and the present position is
  //is not zero.
    while(cin>>cars[now] && cars[now]){

      currSum += cars[now];// adds the current position to the current sum.

      
      for(int index = 0; index <= lengthLimit; index++){

          //if the current sum does not pass the lengthLimit and the previous
          //position(now-1) on the left side is true.
          if(currSum - index <= lengthLimit && leftSide[now - 1][index]){

            leftSide[now][index] = true;

            previous[now][index] = index;

            last = now;

            length = index;
          }
          //if the present index is greater than the current car length and 
          //the previous car on the leftSide.
          else if(index >= cars[now] && leftSide[now - 1][index - cars[now]]){
            leftSide[now][index] = true;
            previous[now][index] = index - cars[now];
            last = now;
            length = index;
          }

      }
      now++;
    }

// cout<<last <<"\n";
printf("%d\n", last);
printDecision(last,length);
if(numberOfTestCases){
  puts("");
}


  }
return  0;
}



//Ends here
//./main < input1
//./main < input2
//./main < input3

// continue looping.

// g++ = compile my program

// g++ <program to compile> -o <whats my output file>

// g++ main.cpp -o whateveryouwant

//passes the Online judge but not the first test case for the UVA debugger.