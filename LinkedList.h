#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ItemType.h"


struct NodeType {
     ItemType info;
     NodeType * next;
};


class  LinkedList		// declares a class data type
{			
public : 			
  LinkedList();
  ~LinkedList();
  void MakeEmpty( );        // 8 public member functions
  bool IsFull( ) const;
  bool IsEmpty( ) const;              
  int  GetLength( ) const;  // returns length of list
  //void RetrieveItem( ItemType&  item, bool&  found );
  void InsertItem( ItemType item ); 	
  //void DeleteItem( ItemType  item ); 	
  void ResetList( );
  void GetNextItem( ItemType & item ); 	
private:		
  NodeType* listData;
  int length;
  NodeType* currentPos;
};	


#endif
