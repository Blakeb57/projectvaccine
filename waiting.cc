#include <iomanip>
#include <ctime>
#include <string>
#include "waiting.h"
using namespace std;

Waiting::Waiting()
{
    head = NULL;
}

Waiting::Waiting(const Waiting& other)
{
    if(other.head == NULL)
    {
        head = NULL;
    }
    else{
        head = new node(other.head -> data());
        node *aptr = other.head -> link();
        node *bptr = head;

        while(aptr != NULL)
        {
            bptr -> set_link(new node(aptr -> data()));
            bptr = bptr -> link();
            aptr = aptr -> link();
        }
    }
}
Waiting::~Waiting()
{
    node *rmpoint;

    while(head != NULL)
    {
        rmpoint = head;
        head = head -> link();
        delete rmpoint;
    }
}

Waiting& Waiting::operator = (const Waiting& other)
{
    node *tmp;
    if(this == &other)
    {
        return *this;
    }

    while(head != NULL)
    {
        tmp = head;
        head = head->link();
        delete tmp;
    }

    if(other.head == NULL)
    {
        head = NULL;
    }
    else{
        node *aptr, *bptr;
        head = new node(other.head->data());
        aptr = other.head->link();
        bptr = head;

        while(aptr != NULL)
        {
            bptr->set_link(new node(aptr->data()));
            bptr = bptr->link();
            aptr = aptr->link();
        }
    }
    return *this;
}

void Waiting::add(Appointment tmp)
{
    node *cursor;

    if(head == NULL)
    {
        head = new node;
        head -> set_data(tmp);
        head -> set_link(NULL);;
    }
    else{
        for(cursor = head; cursor -> link() != NULL; cursor = cursor -> link());

        cursor -> set_link(new node);
        cursor = cursor -> link();
        cursor -> set_data(tmp);
        cursor -> set_link(NULL);
    }
}

void Waiting::display(ostream &outs)const
{
    const node * cursor = head;

    while(cursor !=  NULL)
    {
        cout << cursor->data() << endl;
        cursor = cursor->link();
    }
    cout << endl;
}

void Waiting::remove(string target)
{
    node *rmpoint = head;
    node *previous;

    if(head->data().get_name() == target)
    {
        node *rmpoint = head;
        head = head->link();
        delete rmpoint;
    }
    else{
        while(rmpoint != NULL && rmpoint->data().get_name() != target)
        {
            previous = rmpoint;
            rmpoint = rmpoint->link();
        }

        if(rmpoint != NULL)
        {
            previous->set_link(rmpoint->link());
            delete rmpoint;
        }
    }
}

int Waiting::size(const node *head)
{
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL)
    {
  	    count++;
	    cursor = cursor -> link();
	}
	return count;
}

Appointment Waiting::find(std::string target) const
{
    node *cursor;

    for(node* cursor = head; cursor != NULL; cursor = cursor -> link())
    {
        if(cursor -> data().get_name() == target)
        {
            return cursor->data() ;
        }
    }

    return Appointment();
}

double Waiting::avg_wait_time(node *head)
{

}

int Waiting::waiting()const
{
    int total = 0;

    for(node *tmp = head; tmp != NULL; tmp = tmp->link())
    {
        total += stoi(tmp->data().get_name());
    }
    cout << "Total number of people waiting: " << total << endl;
}

unsigned Waiting::longest_wait()const
{
    DateTime max;
    
    if(head == NULL)
    {
        cout << "Error" << endl;
        return 0;
    }
    node *ptr = head;
    
    while (ptr != NULL)
    {
        if(max < ptr->data().get_callin())
        {
            max = ptr->data().get_callin();
        }
        ptr = ptr->link();
    }

    return max.minutes_since_1970(); 
    

    /*
    if(head == NULL)
    {
        return;
    }
    else{
        for(ptr = head; ptr->link() != NULL; ptr = ptr->link())
        {
            for(ptr2 = ptr->link(); ptr2 != NULL; ptr2 = ptr2->link())
            {
                if(ptr->size() > ptr2->size())
                {

                }
            }
        }
    }
    */
}

unsigned Waiting::average_wait()const
{

}

unsigned Waiting::oldest()const
{

}

unsigned Waiting::youngest()const
{

}

unsigned Waiting::average_age()const
{

}

void Waiting::save(ostream& outs)const
{
    const node * cursor = head;

    if(head == NULL)
    {
        cout << "The file is empty" << endl;
    }

    while(cursor != NULL)
    {
        outs << cursor -> data();
        outs << endl;
        cursor = cursor -> link();
    }
}

void Waiting::load(std::istream& ins)
{
    Appointment tmp;
    node *cursor;

    while(!ins.eof())
    {   
        if(head == NULL)
        {
            head = new node;
            head -> set_data(tmp);
            head -> set_link(NULL);
        }
        else{
            cursor = head;

            while(cursor -> link() != NULL)
            {
                cursor = cursor -> link();
            }
            cursor -> set_link(new node);
            cursor = cursor -> link();
            cursor -> set_data(tmp);
            cursor -> set_link(NULL);
        }
        tmp.input(ins);
    }
}