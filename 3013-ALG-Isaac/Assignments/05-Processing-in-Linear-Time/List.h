
//File: List.cpp

#pragma once
#include <iostream>
using namespace std;



/**
 * Class Name
 * 
 * Description:
 *      Tempalted Linked list class with Node struct which
 *		holds the both a word and a definition.
 * 
 * Public Methods:
 *      - List()
 *      - List(List &other)
 *      - ~List()
 *		- void ClearList()
 *		- void ClearList()
 * 		- void SwapLists(List &other)
 *		- void ResetCursor()
 *		- bool CursorAtEnd()
 *		- void GetCurrentItem(ItemType &Item)
 *		- string GetCurrentItem()
 *		- void UpdateCurrentItem(const ItemType &Item)
 *		- void AdvanceCursor()
 *		- void InsertItem(const ItemType &Item)
 *		- void DeleteItem()
 *		- int getCount()
 * 
 * Private memeber data:
 *      - wordNode *head;
 *	    - wordNode *cursor;
 *	    - int count;
 * 
 * Usage: 
 * 
 *       List<string> wordNodeList;
 *		 wordNodeList.InsertItem(word,definition);
 *		 cout<< wordNodeList.getCount<<"\n';
 *		 cout<< Here is the current item: <<wordNodeList.GetCurrentItem()<<"\n";
 *		 
 *      
 */
template <class ItemType>
class List
{
	struct wordNode 
	{
		ItemType word;
		ItemType definition;
		wordNode *next;
	};

public:
	//Default templated constructor.
	List();

	//Templated copy constructor.
	List(List &other);

	//Destructor
	~List();

	//Clears every node in the list besides the dummy node.
	void ClearList();

	//except that cursors are at heads
	//Swaps the values between two link lists.
	void SwapLists(List &other);

	//First item in the sequence, and the sequence is unchanged.
	//Resets the cursor(sets it back to head)
	void ResetCursor();

	//Returns a boolean value whether
	//the cursor is at the end or not.
	bool CursorAtEnd();

	//Loads a Item with a value(obj,int,string,etc.)
	//and passes it by reference.
	void GetCurrentItem(ItemType &Item);

	string GetCurrentItem();
	//Sets a new item into a node.
	void UpdateCurrentItem(const ItemType &Item);
	


	//Sets a new item into a node.
	void AdvanceCursor();

	//Inserts and Item into the list.
	void InsertItem(const ItemType &Item);

	//Inserts and two pieces of data int into one node.
	//and inserts it into the list.
	void InsertItem(const ItemType &Item, const ItemType &Def);

	//Deletes an item in the list.
	void DeleteItem();

	//Gets the current size of the list.
	int getCount();

private:
	wordNode *head;
	wordNode *cursor;
	int count;
};

#include "List.cpp"