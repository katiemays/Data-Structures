#include "ItemType.h"
#include "TreeType.h"



int main(){

    TreeType firstTree, mirrorTree;

    ItemType x;
    ItemType item;

    item.Initialize('B');
    x.Initialize('F');

    firstTree.InsertItem(x);
    if (firstTree.IsEmpty() == false)
       cout<<"the first item is inserted"<<endl;

    cout<<"After inserting the first item "<<x<<" into the tree"<<endl;
    firstTree.Print();

    x.Initialize('A');
    firstTree.InsertItem(x);
    x.Initialize('C');
    firstTree.InsertItem(x);
    x.Initialize('B');
    firstTree.InsertItem(x);
    x.Initialize('E');
    firstTree.InsertItem(x);

    cout<<"After inserting five items into the tree"<<endl;
    firstTree.Print();

    int count = firstTree.GetLength();
    cout<<"The tree has "<<count<<"  elements"<<endl;

    if (count !=0)
    {
        cout<<"Show the tree in Post_order"<<endl;
        firstTree.ResetTree(POST_ORDER);
        bool finished = false;

        while(finished == false)
       {
         ItemType thisItem;
         firstTree.GetNextItem(thisItem, POST_ORDER, finished);
         cout<<thisItem<<"  ";         
       }    
       cout<<endl;


        cout<<"Show the tree in Pre_order"<<endl;
        firstTree.ResetTree(PRE_ORDER);
        finished = false;
        while(finished == false)
        {

         ItemType thisItem;
         firstTree.GetNextItem(thisItem, PRE_ORDER, finished);
         cout<<thisItem<<"  ";         
        }    
        cout<<endl;

	cout << "*NEW*: New tree that mirrors this firstTree  " << endl;
	firstTree.Swap(mirrorTree);
	mirrorTree.Print();

	cout << "*NEW*: The tree has " << firstTree.GetLeafCount() << " leaf nodes" << endl;

        cout<<"Delete an item with *NEW* delete function : "<<x<<endl;       

        bool find = false;
        firstTree.RetrieveItem(x,find);
        if ( find == true)
            firstTree.DeleteItem(x);

        cout<<"After deleting "<<x<<" from the tree"<<endl;
        count = firstTree.GetLength();
        cout<<"The tree has "<<count<<" elements"<<endl;

        firstTree.Print();

	cout << "*NEW*: The tree has " << firstTree.GetLeafCount() << " leaf nodes" << endl;

	cout << "*NEW*: The node " <<item<< " ancestors are ";
	firstTree.Ancestors(item);
	cout << endl;
    }
    
    firstTree.MakeEmpty();
    cout<<"After emptying the tree"<<endl;
    firstTree.Print();

    return 0;
}

/* original output

[@storm week7]$ ./test.out
the first item is inserted
After inserting the first item F into the tree
Binary Search Tree: (in-order)
F  
After inserting five items into the tree
Binary Search Tree: (in-order)
A  B  C  E  F  
The tree has 5  elements
Show the tree in Post_order
B  E  C  A  F  
Show the tree in Pre_order
F  A  C  B  E  
Delete an item : E
After deleting E from the tree
The tree has 4 elements
Binary Search Tree: (in-order)
A  B  C  F  
After empty the tree
Binary Search Tree: (in-order)

*/
