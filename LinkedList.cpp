#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}
void LinkedList::nodeInsertionSort(int arrayLength)
{
    Node* tempSwap =this->head;
    Node* theFollower = this->head;
    Node* currNode = this->head;
        
        
        for(int i=0;i<arrayLength;i++)
        {
        tempSwap = tempSwap->getNextNode(); //temp = 13

        cout<<" here" ;
            //
            if(tempSwap->getPayload()<theFollower->getPayload())
            {         
                //currNode = theFollower->getPayload()
                //tempSwap->getPayload()=theFollower->getPayload();
                
                
                cout<<tempSwap->getPayload()<<endl;                

                
                
                cout<<" hello ";
                //tempSwap = currNode;
               // tempSwap = tempSwap->getNextNode();
                //cout<<theFollower->getPayload()<<endl;
            }
           else
            {
                cout<<" not working ";
                //tempSwap = tempSwap->getNextNode();
                //theFollower = theFollower->getNextNode();
            }
                






        /*Node* n = new Node(10);
        n->setNextNode(this->head);  randomness
        this->head = n;
        */
        }

    
/*
    //int tempSwap;
    //int theFollower;
    for(int currStart = 0; currStart < arrayLength; currStart++)
    {
        theFollower = currStart;
        while(theFollower > 0 && ar[theFollower] < ar[theFollower-1])
        {
            tempSwap = ar[theFollower];
            ar[theFollower] = ar[theFollower-1];
            ar[theFollower-1] = tempSwap;
            theFollower--;
        }
    }*/
}
void LinkedList::addAtIndex(int value, int index)
{
    if(index == 0)
    {
        this->addFront(value);
    }
    else if(index == this->count)
    {
        this->addEnd(value);
    }
    else
    {
        Node* dude2Add = new Node(value);
        Node* prevDude = this->head;
        for(int i = 0; i < (index-1); i++)
        {
            prevDude = prevDude->getNextNode();
        }
        dude2Add->setNextNode(prevDude->getNextNode());
        prevDude->setNextNode(dude2Add);
        this->count++;
    }
    
}

int LinkedList::removeAtIndex(int index)
{
    if(this->head)
    {
        if(index < 0 || index >= this->count)
        {
            cout << "ArrayIndexOutOfBoundException!!!!" << endl;
        }
        else
        {
            //I actuall have something to remove
            if(index == 0)
            {
                return this->removeFront();
            }
            else if(index == this->count-1)
            {
                return this->removeEnd();
            }
            else
            {
                //we are removing from somewhere in the middle
                Node* prevDude = this->head;
                Node* dude2Remove = this->head;

                //How do I get prevDude and dude2Remove set in a single loop?
                //run dude2Remove to the correct index
                for(int i = 0; i < index; i++)
                {
                    dude2Remove = dude2Remove->getNextNode();
                }

                //now make preDude point to the node right before dude2Remove
                while(prevDude->getNextNode() != dude2Remove)
                {
                    prevDude = prevDude->getNextNode();
                }

                /* Identical result as the while loop above
                //what is another way we could have written the while loop above?
                for(int i = 0; i < index-1; i++)
                {
                    prevDude = prevDude->getNextNode();
                }
                */

               //Now everything is position and we are ready to operate!!!
               prevDude->setNextNode(dude2Remove->getNextNode());
               dude2Remove->setNextNode(NULL);
               int value2Return = dude2Remove->getPayload();
               delete(dude2Remove);
               this->count--;
               return value2Return;
            }
            
        }
        
    }
    else
    {
        cout << "Nothing to Remove from the Empty List" << endl;
    }
    
}

void LinkedList::addFront(int value)
{
    if(this->head)
    {
        //add it to the front
        Node* n = new Node(value);
        n->setNextNode(this->head);
        this->head = n;
         this->count++;
    }
    else
    {
        //we have an empty list, so addFront and addEnd mean the same thing
        this->addEnd(value);
    }
}

int LinkedList::removeFront()
{
    if(this->head)
    {
        Node* currFront = this->head;
        this->head = this->head->getNextNode();
        currFront->setNextNode(NULL);
        int valueToReturn = currFront->getPayload();
        delete(currFront);
        this->count--;
        return valueToReturn;
    }
    
}

void LinkedList::addEnd(int value)
{
    Node* n = new Node(value);
    if(head == NULL)
    {
        //we have the empty list
        this->head = n;
        this->tail = n;
    }
    else
    {
        //we have a list with at least one element in it, and we know that tail
        //points to the end of that list.
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::removeEnd()
{
    if(this->count > 0)
    {
        Node* n = this->tail;
        int value = n->getPayload();
        if(this->count == 1)
        {
            this->head = NULL;
            this->tail = NULL;
            
        }
        else
        {
            Node* currNode = this->head;
            while(currNode->getNextNode() != this->tail)
            {
                currNode = currNode->getNextNode();
            }
            this->tail = currNode;
            this->tail->setNextNode(NULL);
        }
        this->count--;
        delete(n); //if we didn't do this, we technically have a memory leak
        return value;
    }
    
}
void LinkedList::display()
{
    if(this->count == 0)
    {
        cout << "the empty list" << endl;
    }
    else
    {
        Node* currNode = this->head;
        while(currNode->getNextNode() != NULL)
        {
            cout << currNode->getPayload() << " -> ";
            currNode = currNode->getNextNode();
        }
        cout << currNode->getPayload() << endl;
    }
    
}