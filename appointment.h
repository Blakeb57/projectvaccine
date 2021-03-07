/********************************************
//    This is the record of a person waiting for an appointment for their
//    COVID-19 vaccine. It includes the person's name, age and the date
//    and time when they called in to get the appointment.
//    Overloaded comparison operators compare the time they called in,
//    with less than meanng that the left operand has called in earlier
//    than the righ operand.
//          John Dolan		Ohio University		School of EECs
//				Spring 2021
***********************************************/
#include<iostream>
#include<string>
#include "date_time.h"
#ifndef APP_H
#define APP_H
class Appointment
{
   public:
	    Appointment();
	    std::string get_name()const{return name;}
	    Date get_bday()const{return bday;}
	    DateTime get_callin()const{return called;}
	    bool operator < (const Appointment& ap)const{return called < ap.called;}
	    bool operator >(const Appointment& ap)const{return ap.called < called;}
	    bool operator <= (const Appointment& ap)const{return !(ap.called < called);}
	    bool operator >= (const Appointment& ap) const{return !(called < ap.called);}
	    bool operator != (const Appointment& ap) const{return (called < ap.called || ap.called < called);}
	    bool operator == (const Appointment& ap) const{return !(called < ap.called || ap.called < called);}
  
	    int age(const Date& tday)const{return bday.age(tday);}
	    unsigned minutes_waiting()const;
	    void input(std::istream& ins);
	    void output(std::ostream& outs)const;
	
   private:
	    std::string name;
	    Date bday;
	    DateTime called;
};

// A useful non-member function
void convert_minutes(unsigned m);

// Input and Output Operators for those who want to use them.
std::istream& operator >>(std::istream& ins, Appointment & ap);
std::ostream& operator <<(std::ostream& outs, const Appointment& ap);

#endif