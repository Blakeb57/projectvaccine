/****************************************
   Just a little tester for my new age function
***********************************/
#include<iostream>
#include "date_time.h"
#include "appointment.h"

using namespace std;

int main()
{
   Date person, today;
   Appointment grandma;
   int age;
  
   // cout << "Enter the person's date of birth: ";
   // cin >> person;
   // cout << "Minutes since 1/1/1970: "<< person.minutes_since_1970() << endl;
   // cout << "Enter today's date: ";
   // cin >> today;

   today.make_today();
   cout << today << endl;
   // age = person.age(today);
   // cout << "That person is " << age << " years old.\n";

   grandma.input(cin);
   grandma.output(cout);
   cout << "\nGrandma is " << grandma.age(today) << " years old.\n";
   cout << "She has been waiting " << grandma.minutes_waiting() << " minutes.\n";
   convert_minutes(grandma.minutes_waiting());

return 0;
}
