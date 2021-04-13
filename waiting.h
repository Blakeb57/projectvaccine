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
        int size(const node *head);
        Appointment find(std::string target)const;
        double avg_wait_time(node *head);
        int waiting()const;
        unsigned longest_wait()const;
        unsigned average_wait()const;
        unsigned oldest()const;
        unsigned youngest()const;
        unsigned average_age()const;
        void save(std::ostream& outs)const;
        void load(std::istream& ins);

    private:
        node *head;
        int used;
};