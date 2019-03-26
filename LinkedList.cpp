#include "LinkedList.h"

//constructor

LinkedList::LinkedList()
{
  length=0;
  listData = NULL;
}

//destructor

LinkedList::~LinkedList()
{
  MakeEmpty();
}


int LinkedList::GetLength() const
{
  return length;
} 


bool LinkedList::IsFull() const
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (std::bad_alloc e)
  {
    return true;
  }
}

bool LinkedList::IsEmpty() const
{
   return (listData== NULL)? true: false;

}


void LinkedList::MakeEmpty() 
{
  NodeType *tempPtr;
  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
  listData = NULL;
}

// Pre: list is not full and item is not in list.
// Post: item is in the list; length has been incremented.

void LinkedList::InsertItem ( ItemType  item ) 
{    
  NodeType * location;
 	// obtain and fill a node
  location = new  NodeType;
  location->info = item;
  location->next = listData;
  listData = location;
  length++;

}

// Pre: Key member of item is initialized.
// Post: If found, item�s key matches an element�s key in the list and a copy of that
// element has been stored in item; otherwise, item is unchanged.
/*
void  LinkedList::RetrieveItem( ItemType&  item, bool&  found )  
{  
   bool  moreToSearch;
	NodeType*  location;
   location = listData;
	found = false ;
	moreToSearch = ( location  !=  NULL ) ;
	while ( moreToSearch  &&  !found ) 
	{  
          if ( item.ComparedTo(location->info ))             // match here
          { 
                found = true;
   	        item  = location->info;
	  }
	  else				    // advance pointer 
	  { 
               location = location->next;  
               moreToSearch = ( location  !=  NULL );
          }   
   }     
}


//pre: item's key has been initialized. An element in the list has a key that matches item's
//Post: no element in the list has a key that matches item's

void LinkedList::DeleteItem(ItemType item)
{
NodeType* location = listData;
NodeType* tempLocation;
// Find the item
if (item.ComparedTo(listData->info) == EQUAL) 
{ // item in first location
  tempLocation = location;
  listData = listData->next; //move the head of the list
}
else{ 
      //let location points to the node before the matching node
      while (item.ComparedTo((location->next)->info) != EQUAL)
                location = location->next;

      //remove the middle one, connect the two ends
       tempLocation = location->next;
       location->next = (location ->next)->next;
     
}
delete tempLocation;
length--;


}
*/


void LinkedList::ResetList()
{ 
  currentPos = NULL;
}

//Pre: the item at the current position is not the last in the list
//Post: current position has been updated. Item is current item. Does not check for running off the end of the lsit

void LinkedList::GetNextItem(ItemType& item)
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;

  item = currentPos->info;
}
