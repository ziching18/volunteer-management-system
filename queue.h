#include <iostream>
#include <fstream>
#pragma once
using namespace std;

// Structure of Node.
class Queue{
    public:
        Queue();
        ~Queue();

        bool isEmpty();
        void enqueue(string newItem);
        void dequeue();
        string getFront();
        void displayQueue();
        void outputQueue(string fileName);

    private:
        struct QueueNode
        {
            string item;
            QueueNode* link;
        };  // end QueueNode

        QueueNode* backPtr;
        QueueNode* frontPtr;
};

Queue::Queue() : backPtr(NULL), frontPtr(NULL)
{}

Queue::~Queue()
{
    while (!isEmpty())
        dequeue();
}


//Function to check if queue is empty or not
bool Queue::isEmpty()
{
     if(frontPtr == NULL && backPtr == NULL)
     return true;
     else
     return false;
}

//function to enter elements in queue
void Queue::enqueue ( string newItem )
{
     QueueNode *tempPtr = new QueueNode;
     tempPtr->item= newItem;
     tempPtr->link = NULL;

     //If inserting the first element/node
     if( frontPtr == NULL )
     {
      frontPtr = tempPtr;
      backPtr = tempPtr;
     }
     else
     {
      backPtr ->link = tempPtr;
      backPtr = tempPtr;
     }
}

//function to delete/remove element from queue
void Queue::dequeue ( )
{
     if( isEmpty() )
     cout<<"Queue is empty\n";
     else
     if( frontPtr == backPtr)
     {
      frontPtr = backPtr = NULL;
     }
     else
     {
      QueueNode *tempPtr = frontPtr;
      frontPtr = frontPtr->link;
      free(tempPtr);
     }
}

//function return the element at front
string Queue::getFront()
{
     if( isEmpty()){
     return "Queue is empty\n";
     }else{
     return frontPtr->item;}
}

//function to display queue
void Queue::displayQueue()
{
     if (isEmpty())
      cout<<"Queue is empty\n";
     else
     {
      QueueNode *tempPtr = frontPtr;
      while( tempPtr != NULL)
      {
       cout << tempPtr->item << " ";
       tempPtr = tempPtr->link;
      }
     }
}

//function to output queue to file
void Queue::outputQueue(string fileName)
{
     ofstream output(fileName);
     if (isEmpty())
     if (isEmpty())
      cout<<"Queue is empty\n";
     else
     {
      QueueNode *tempPtr = frontPtr;
      while( tempPtr != NULL)
      {
       output << tempPtr->item << ";";
       tempPtr = tempPtr->link;
      }
      output.close();
     }
}

//reference: slides, lab & https://www.codewhoop.com/queue/queue-using-linked-list.html
