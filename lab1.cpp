//Author: Katie Mays
//Lab One

#include "ItemType.h"
#include "UnsortedType.h"

void PrintList( UnsortedListByArray& list)
// Pre:  list has been initialized.         
// Post: Each component in list has been written. 
// 
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
    
    if (counter < length)
      cout<<" | ";
  }
  cout<<endl;
}

int main(){

    // Variables
    UnsortedListByArray L, listOne, listTwo;
    bool done; // used in InsertItem()
    ItemType a,b,c,d,e,f,g, key;

    // Initializing items
    a.Initialize(1);
    b.Initialize(3);
    c.Initialize(5);
    d.Initialize(12);
    e.Initialize(10);
    f.Initialize(0);
    // Inserting items
    L.InsertItem(a); 
    L.InsertItem(b);
    L.InsertItem(c);
    L.InsertItem(d);
    L.InsertItem(e);
    L.InsertItem(d); // insert copy of '12'
    L.InsertItem(f);
    L.InsertItem(d); // insert copy of '12'

    cout << "TESTING DELETE ALL ITEMS FUNCTION" << endl;
    cout << "List L:" << endl;
    PrintList( L );
    cout << "Deleting all copies of '12' in list ..." << endl;    
    L.DeleteAllItems(d);
    PrintList( L );

    // Cleaning up
    L.MakeEmpty();
    L.InsertItem(a);
    L.InsertItem(b);
    L.InsertItem(c);
    L.InsertItem(d);
    L.InsertItem(e);

    cout << "TESTING *NEW* INSERT FUNCTION" << endl;
    cout << "List L - Case A:" << endl;
    PrintList( L );
    cout << "Attempting to insert '12' ..." << endl;
    L.InsertItem(d,done);
    cout << "List L - Case A:" << endl;
    PrintList( L );
    if (!done) // checking
       cout << "Not done." << endl;

    // Cleaning up
    L.DeleteItem(d);
    L.DeleteItem(e);

    cout << "List L - Case B:" << endl;
    PrintList( L );
    cout << "Attempting to insert '12' ..." <<endl;
    L.InsertItem(d,done);
    cout << "List L - Case B:" << endl;
    PrintList( L );
    if (!done) // checking
       cout << "Not done." <<endl;

    // Cleaning up, inserting
    L.MakeEmpty();
    key.Initialize(4);
    g.Initialize(2);
    L.InsertItem(a);
    L.InsertItem(b);
    L.InsertItem(c);
    L.InsertItem(g);
    L.InsertItem(e);
    L.InsertItem(d);
    L.InsertItem(f);

    cout << "TESTING SPLIT LIST FUNCTION" << endl;
    cout << "List L:" << endl;
    PrintList( L );
    cout << "Splitting lists at '4' ..." << endl;
    L.SplitList( key, listOne, listTwo );
    cout << "listOne:" << endl;
    PrintList( listOne );
    cout << "listTwo:" << endl;
    PrintList( listTwo );

    // Cleaning up
    L.MakeEmpty();

    cout << "TESTING MERGE LIST FUNCTION" << endl;
    cout << "Merging lists ..." << endl;
    L.MergeList( listOne, listTwo );
    cout << "List L:" << endl;
    PrintList( L );

    // Cleaning up
    listOne.MakeEmpty();
    listTwo.MakeEmpty();
    L.MakeEmpty();
    
    return 0;
}
