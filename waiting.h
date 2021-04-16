#include <iostream>
#include <string>
#include "appointment.h"
#include "node.h"

class Waiting
{
    public:
        //default constructor
        Waiting();

        //the big 3
        ~Waiting();
        Waiting(const Waiting& other);
        Waiting& operator = (const Waiting& other);

        //functions
        void add(Appointment tmp);
        void display(std::ostream &outs)const;
        void remove(std::string target);
        Appointment find(std::string target)const;
        int waiting()const;
        unsigned longest_wait()const;
        unsigned average_wait()const;
        node* oldest()const;
        node* youngest()const;
        unsigned average_age()const;
        void save(std::ostream& outs)const;
        void load(std::istream& fin);

    private:
        node *head;
};