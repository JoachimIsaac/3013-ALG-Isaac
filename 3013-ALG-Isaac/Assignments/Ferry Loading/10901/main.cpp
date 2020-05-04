#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>
#define endl "\n"
using namespace std;





// Car struct --> contains: arrivalTime, bank;
struct Car{
  
  int arrivalTime, number;

Car(int x, int y) {
        number = x;
        arrivalTime = y;
        
    }
};


//What side of the lake we are on.
static const int LEFT = 0; 
static const int RIGHT = 1;


int main(int argc, char *argv[]){

  int testCases;

  cin >> testCases;


  while(testCases--){

  int numberOfCarToLoad, timeTakenToDropOff, numberOfCarsInCase;

  cin >> numberOfCarToLoad >> timeTakenToDropOff >> numberOfCarsInCase;

  /// Uses a vector of queues<Car> to store the cars.
  vector<queue<Car>>cars(2);

  vector<int>offloadedTimes(numberOfCarsInCase);


  //Load the cards in the cars queues.
  //Load all cars on the left in the queue at index 0.
  //Load al cars on the right in the queue at index 1.
  for(int i = 0; i < numberOfCarsInCase; ++i){
     

      int arrivalTime;
      string currBank;

       cin >> arrivalTime >> currBank;

      if(currBank == "left"){

        cars[LEFT].push(Car(i,arrivalTime));

      }
      else{
        cars[RIGHT].push(Car(i,arrivalTime));
      }

  }



  int time = 0; // ferry starts from the left bank. 

  int index = LEFT;

  //While there are cars to move across the banks. 
  while(!(cars[LEFT].empty() && cars[RIGHT].empty())){

    // Gets highest possible int. 
    int earliest_car = numeric_limits<int>::max();

      if(!cars[LEFT].empty()){
        //Take the car that has the higher priority on the left side. 
        earliest_car = cars[LEFT].front().arrivalTime;
      }
      
      if(!cars[RIGHT].empty()){
        //Take the car that has the higher priority on the right side.
        earliest_car = min(earliest_car,cars[RIGHT].front().arrivalTime);
      }

      time = max(time,earliest_car); // reset the time. 

       int carCount = 0;


    //While the current bank is not empty and the number of cars
    //on the bank donot exceed the number of cars we can load on 
    //the bank; and the arrival time is less than or equal to the
    //current time.
     while(!cars[index].empty() && carCount < numberOfCarToLoad
     && cars[index].front().arrivalTime <= time){

      // this is how we generate the time it takes to offload
      // we store all the times in this.
      offloadedTimes[cars[index].front().number] = time + timeTakenToDropOff;

      cars[index].pop();
      ++carCount;

     }

     time += timeTakenToDropOff;
     index ^= 1; //?  index ^= 1;


  }

    //Print the offload times 
    for(int i = 0; i < numberOfCarsInCase; i++){

        cout<< offloadedTimes[i]<<endl;

        //if we still have test cases print a space below.
        
    }
    
    if (testCases) cout << endl;
    
    
    
  }



return 0;



}







//Ends here
//./main < input1
//./main < input2
//./main < input3

// continue looping.

// g++ = compile my program

// g++ <program to compile> -o <whats my output file>

// g++ main.cpp -o whateveryouwant
// https://en.cppreference.com/w/cpp/types/numeric_limits