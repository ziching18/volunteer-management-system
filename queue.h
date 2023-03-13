#include <iostream>
#include <fstream>
#pragma once
using namespace std;

// structure of Node
class Queue
{
    public:
        Queue();    // constructor
        ~Queue();   // destructor

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
        };

        QueueNode* backPtr;
        QueueNode* frontPtr;
};

Queue::Queue() : backPtr(NULL), frontPtr(NULL)
{}

Queue::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

// check if queue is empty
bool Queue::isEmpty()
{
     if(frontPtr == NULL && backPtr == NULL)
     {
         return true;
     }
     else
     {
         return false;
     }
}

// enter elements into queue
void Queue::enqueue (string newItem)
{
     QueueNode *tempPtr = new QueueNode;
     tempPtr->item = newItem;
     tempPtr->link = NULL;

     // inserting the first element/node
     if(frontPtr == NULL)
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

// delete/remove element from queue
void Queue::dequeue ()
{
    if(isEmpty())
    {
        cout << "\n\t\t\tQueue is empty!";
    }
    else
    {
        if( frontPtr == backPtr)   // only 1 element in queue
        {
            frontPtr = backPtr = NULL;
        }
        else
        {
            QueueNode *tempPtr = frontPtr;
            frontPtr = frontPtr->link;
            free(tempPtr);    // delete tempPtr
        }
    }
}

// return the element at front
string Queue::getFront()
{
    if(isEmpty())
    {
        return "\n\t\t\tQueue is empty!";
    }
    else
    {
        return frontPtr->item;
    }
}

// display queue
void Queue::displayQueue()
{
    if(isEmpty())
    {
        cout << "\n\t\t\tQueue is empty!";
    }
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

// output queue to file
void Queue::outputQueue(string fileName)
{
    ofstream output(fileName);
    if(isEmpty())
    {
        cout<<"\n\t\t\tQueue is empty";
    }
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
