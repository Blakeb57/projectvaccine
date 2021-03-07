/***************************************************
      The implementation for the Appointment class
	John Dolan	Ohio Universtiy		School of EECS
			Spring 2021
*******************************************************/
#include<iostream>
#include<string>
#include<ctime>
#include "appointment.h"

using namespace std;

// default constructor
Appointment::Appointment()
{   
    name = "NA";
}


void Appointment::input(istream& ins)
{
        if(&ins == &cin)
        {
            cout << "Enter the patient's name: ";
            while(ins.peek() == '\n' || ins.peek() == '\r')
                ins.ignore();
            getline(ins, name);
            cout << "Enter their date of birth: ";
            ins >> bday;
            cout << "Enter the date and time of patient called:\n";
            called.input(ins);
        }
        else{
            while(ins.peek() == '\n' || ins.peek() == '\r')
                ins.ignore();
            getline(ins, name);
            ins >> bday;
            called.input(ins);
        }
}


void Appointment::output(ostream& outs)const
{
 	outs << name << endl;
	outs << bday << endl;
	called.output(outs);
}

unsigned Appointment::minutes_waiting()const
{
	unsigned nowminutes = time(NULL)/60;
//cout<<"Minutes since 1970 = "<<nowminutes<<endl;
	nowminutes -= 659;
  return nowminutes - called.minutes_since_1970();
}

void convert_minutes(unsigned minutes)
{
 	int days = minutes/1440;
	minutes %= 1440;
	int hours = minutes/60;
  minutes %= 60;
  cout << days << " Days, " << hours << " hours, " << minutes << " minutes.\n";
}

// Input and output operarators for those who might want to use them
istream& operator >>(istream& ins, Appointment & ap)
{
	ap.input(ins);
	return ins;
}

ostream& operator <<(ostream& outs, const Appointment& ap)
{
	ap.output(outs);
	return outs;
}
