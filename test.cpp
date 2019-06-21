/*
Name: Hamed Mirlohi
Program to read the last K line from a file 
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define LINES 6

struct node
{
    string line;    // each node will contain a line
    node* next;
};

int main()
{
    ifstream rF;
    rF.open("test.txt");

    if(!rF)   // if file not succeeded to open
    {
        cout<<"couldnt open the file"<<endl;
        return -1;
    }


     // building my Circular Linked List
    node* head = nullptr;
    node* temp = nullptr;
    int count = 0;

    while(count < LINES)    
    {
        if(head == nullptr)
        {
            head = new node;
            head->next = nullptr;
            temp = head;
        }
        else
        {
            temp->next = new node;
            temp = temp->next;
            temp->next = nullptr;
            
        }
        ++count;
    }

    if(temp != nullptr)         // connect last node to first node
        temp->next = head;
    
    string readLine;
    node* readFromhere = head;  // pointer which specifies the beginning of the read
    
    // as long as we are reading lines from the file
    while(rF >> readLine)
    {
        readFromhere->line = readLine;          // insert the line in the node
        readFromhere = readFromhere->next;      // move pointer forward
    }

    // displaying the circular linked list
    temp = readFromhere;                    // temp holds the beginning 
    while(temp->next != readFromhere)
    {
        cout<<temp->line<<endl;
        temp = temp->next;
    }
    cout<<temp->line<<endl;
}