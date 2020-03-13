## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)


- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n^2), O(log n), O(n!)**, order the algorithms from fastest to slowest.
**Answer: Fastest to Slowest: O(1), O(log(n)), O(n) , O(n log(n)) , O(n^2) , O(n!)** 


- Suppose that the complexity of an algorithm is O(n^2). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? 
- **Answer: The time is directly propotional to n^2 So, T/10=(2*N)^2/N^2 T=40 seconds needed
So if the program was running in 10 seconds if you double the data size it would take about 40 seconds.**




- Complexities : **O(1), O(n log n), O(n), O(n^2), O(log n), O(n!) , O(h)**

- 1) Finding the max element in an unordered stack would require **O(n)** operations
**- 1) Explaination: This can be said because we have no idea where the max element would be
on the stack and so we would have to continiously pop off the stack to get to it.**

- 2) Finding the min element in an unordered queue would require **O(n)** operations
**- 2) Explaination: This can be said because we have no idea where the min element would be
on the queue and so we would have to continiously remove elements from the front of the queue to get 
to it.**

- 3) Finding some element in some Binary Search Tree would require **O(n)** operations
**- 3) Explaination: The time complexity of O(n) is valid in this case because it was not
specified wether or not the tree was balanced. If the tree was not blance then there is
a chance where it would have to search through a linked list shaped branch for it's target.**

- 4) Finding some element in a balanced Binary Search Tree would require **O(log(n))** operations
**- 4) Explaination: Since the tree is balanced every time a search is made it can be said that it eliminates
half of the search area and so this converges to a time complexity of Olog(n).**


- 5) Finding some element in an ordered linked list would require **O(n)** operations (worst case)
**- 5) Explaination: Whether or not the linked list is ordered or not doesn't change the nature of the data structure.
It does not inherently have indexes for each node and so remembering the location(index) of each node isn't really built into this data structure. Hence even though it is ordered there is no real way to eliminate half of the search base.
This keeps the linked list search time complexity to be O(n) in the worst case.**


- 6) Finding some element in an ordered linked list would require **O(n) or O(n/2) which would still be considered O(n) after the constant is ignored** operations (average case)
**- 6) Explaination: Whether or not the linked list is ordered or not doesn't change the nature of the data structure.
It does not inherently have indexes for each node and so remembering the location(index) of each node isn't really built into this data structure. Hence even though it is ordered there is no real way to eliminate half of the search base.
This keeps the linked list search time complexity to be O(n) in the average case. However if the target being searched for is in the middle of the linked list, it could be argued that the average time complexity is O(n/2), but this still converges to O(n).**

- 7) Finding some element in an unordered linked list would require **O(n)** operations (worst case)
**- 7) Explaination: Since we have no idea where the target is within the link list the best thing we can do is a linear search through the link list. At that point, worst case the time complexity will be O(n) (linear time).**



- 8) For each of the following, count the number of operations where some_statement is executed based on the loops

- 8A) **Answer: O(n^2) It's simple, each for loop runs at O(n), since they are nested you multiply**
**there complexities to get there overal time complexity O(n * n) is the same as O(n^2).** 
```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```



- 8B)**Answer: O(n/2 * n) the first for-loop increments by two and so it loops through (n) in half the time.** 
**this is why we have n/2 while the second for-loop takes O(n) time. Since the loops are nested we multiply complexities**
**and so we get O(n/2 * n).**
```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```



- 8C)**Answer: O(log(n) * n) Each iteration of the first for-loop multiplies the iterator by 2, this eliminates**
**('n' the search base/size) by half every time and so this gives the first for-loop a time complexity if O(log(n)). Since they are nested and the inner for-loop has a time complexity of O(n) the overall time complexity of the code is 
O(log(n) * n)**
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```

At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?
**Answer for vector question: It would take at most 10 comparisons to search a sorted vector of 1023 using binary search.
Why? Well binary search's time complexity is O(log(n)) and if you take the ceil(log(1023)) or you just round up log(1023)
you will get 10. (1023) the size of the vector  is 'n' in this case.**


In each of the following examples, please choose the best data structure(s).
- 9) Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- 10) Note that there may not be one clear answer.

- 10) You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
- 10) **Answer: In this case a Linked list or even a hash table could be used.Personally I'd go with the hash table since it uniquely identifies each feed and it also allows for dynamic resizing.I would assume that we have a feed class and we could create a hashtable with a key value of some identifier for a feed like a string with the feed's name i.e "funny cats" and the feed object. --> {'funny cat': feed_object}**

- 11) You need to store undo/redo operations in a word processor.
- 11) **Answer: A stack is the best Data structure for an undo and/redo word processor. Each time a state of a word is changed it's placed on the stack. If you undo you pop off the stack and go to the previous state and if you redo you push back the last popped value to the stack.**

- 12) You need to evaluate an expression (i.e., parse).
- 12) **Answer: You could use a stack or tree/trie to parse an expression, with the stack you could load the stack with the expresssion and then compare the what ever expression/word you are looking for by popping each value off, storing whatever is popped off and then comapring the two.** 


- 13) You need to store the friendship information on a social networking site. I.e., who is friends with who.
- 13) **Answer: Graph(each person is a point, and connections/friendships are an edge)**


- 14) You need to store an image (1000 by 1000 pixels) as a bitmap.
- 14) **Answer: Array (2-dimensional, 1000x1000, storing color values)**


- 15) To implement printer spooler so that jobs can be printed in the order of their arrival.
- 15) **Answer: Queue (like a queue/line of people waiting to get through a checkpoint). It follows first in first out struture and so this allows**


- 16) To implement back functionality in the internet browser.
- 16) **Answer: Stack or linked list Stack (you can add to the stack with each site visited, and pop off as necessary to go back, as long as you don't care about going forward. If you care about forward, this is the same scenario as the word processor, so linked list(doublely) is the best data structure in my opinion.)**


- 17) To store the possible moves in a chess game.
- 17) **Answer: Tree(can follow any game move by move, down from the root to the leaf. It would be a massive tree though)**


- 18) To store a set of fixed key words which are referenced very frequently.
- 18) **Answer: Hash table (If you want to use the keywords as keys, and get all things related to them, I would use a hash table.**


- 19) To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)
- 19) **Answer: Queue or Hash Table (if this is a drive thru, assuming people aren't cutting in front of one another, it's like the printer question so a Queue would be best first in first out. If customers are placing orders ahead of time, and can arrive in any order, a hash table would be much better, with an order number or customer name as the key and the order details as the value)**


- 20) To store the genealogy information of biological species.
- 20) **Answer: Tree, you could create Phylogentic Tree (A phylogenetic tree is a diagram that represents evolutionary relationships among organisms. Phylogenetic trees are hypotheses, not definitive facts. The pattern of branching in a phylogenetic tree reflects how species or other groups evolved from a series of common ancestors.)**


- 21) To store an alphabetized list of names in order to look up quickly.
- 21) **Answer: You could use a tree/trie or hash tables, but I'd use the hash table because of it's quick look up time.** 


## Deliverables

- Edit this file and add your answers using markdown!
- Create a folder called `H03` in your assignments folder.
- Put a copy of your markdown file in this folder, and call it README.md.
- Upload to github sometime close to the due date.
- Print out your banner ON ITS OWN PAGE

```
H03
3013
LASTNAME
```

- Print out a hard copy of the file as well. Do not print directly from github. Either use `gitprint` or make it a pdf and print it.
- Make sure you answer thoroughly using complexities where appropriate and/or explaining your choices etc.
