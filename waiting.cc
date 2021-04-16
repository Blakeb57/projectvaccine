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

Appointment Waiting::find(std::string target) const
{
    node *cursor;

    for(node* cursor = head; cursor != NULL; cursor = cursor -> link())
    {
        if(cursor -> data().get_name() == target)
        {
            return cursor->data();
        }
    }

    return Appointment();
}

int Waiting::waiting()const
{
    int count = 0;

    for(node *tmp = head; tmp != NULL; tmp = tmp->link())
    {
        ++count;
    }
    cout << "Total number of people waiting: " << count << endl;
    return count;
}

unsigned Waiting::longest_wait()const
{
    node *ptr = head;
    unsigned max = 0;

    if(head == NULL)
    {
        cout << "Empty List." << endl;
        return max;
    }
    max = ptr->data().minutes_waiting();
    return max;
}

unsigned Waiting::average_wait()const
{
    int count = 0;
    double average = 0;
    double sum = 0;
    
    for(node *ptr = head; ptr != NULL; ptr = ptr->link())
    {
        count++;
        sum += ptr->data().minutes_waiting();
    }
    average = sum / count;
    return average;
}

node* Waiting::oldest()const
{
    node* oldest = head;
    Date tmp = head->data().get_bday();
    Date today;
    today.make_today();
    
    for(node *ptr = head; ptr != NULL; ptr = ptr->link())
    {
        if(tmp > ptr->data().get_bday())
        {
            oldest = ptr;
            tmp = ptr->data().get_bday();
        }
    }
    return oldest;
}

node* Waiting::youngest()const
{
    node* young;
    Date tmp;
    Date today;
    today.make_today();

    for(node *ptr = head; ptr != NULL; ptr = ptr->link())
    {
        if(tmp < ptr->data().get_bday())
        {
            young = ptr;
            tmp = ptr->data().get_bday();
        }
    }
    return young;
}

unsigned Waiting::average_age()const
{
    int count = 0;
    double average = 0;
    double sum = 0;
    Date tday;
    tday.make_today();
    
    for(node *ptr = head; ptr != NULL; ptr = ptr->link())
    {
        count++;
        sum += ptr->data().get_bday().age(tday);
    }
    average = sum / count;
    return average;
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

void Waiting::load(istream& fin)
{
    Appointment tmp;
    node *cursor;

    tmp.input(fin);
    while(!fin.eof())
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
        tmp.input(fin);
    }
}