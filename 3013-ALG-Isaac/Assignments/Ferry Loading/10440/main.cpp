
#include<iostream>
#include <algorithm>
using namespace std;
#include <vector>

#define ll long long

int main(){


int numberOfTestCases, numberOfCars, timeTakenToCarry,numbersOfCarsInCase ; 

cin >> numberOfTestCases;

while(numberOfTestCases){

  cin >> numberOfCars >> timeTakenToCarry >> numbersOfCarsInCase;

  vector<int>cars(numbersOfCarsInCase);




 for(int& currCar:cars)cin>>currCar; //load the cars arrival times.
 

  //positon of the first car 
  int first = numbersOfCarsInCase % numberOfCars;

  int current;


  if(first != 0){
  
     current = cars[first-1] + timeTakenToCarry;
  }
  else{
  
  current = -timeTakenToCarry;

  }

  int trips = first != 0;

  for(int j = first; j < numbersOfCarsInCase; j+= numberOfCars){

    current += timeTakenToCarry;
    trips++;
    current = max(cars[j + numberOfCars - 1],current) + timeTakenToCarry;
 
  }

 
  cout << current << " " << trips << "\n";

numberOfTestCases--;
}


}


//Ends here
//./main < input1
//./main < input2
//./main < input3

// continue looping.

// g++ = compile my program

// g++ <program to compile> -o <whats my output file>

// g++ main.cpp -o whateveryouwant
