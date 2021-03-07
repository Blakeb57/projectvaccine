/******************************************************
//	This is the main for Project 3, which asks you to
//    build a container that holds a list of people requesting
//    their coronavirus vaccines.
//    The Appointments, which are actually appoinment requests,
//    are always kept in order, so they never need
//    to be sorted since they are always inserted in the order
//    where they go. You will also need the files:
//	datetime.h
//	datetime.cc
//	appointment.h
//	apointment.cc
//	node.h
//    in order to do this project. You will be writing both the .h
//    and the .cc file for the container.
//	John Dolan			Spring 2021
**********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "appointment.h"
#include "node.h"
#include "waiting.h"

using namespace std;

// This function displays the menu and returns the user's choice
char menu();

int main()
{
    char choice, ch;
    Appointment ap;
    string patientname;
    ifstream fin;
    ofstream fout;
    string username,filename, fullname;

    cout << "Welcome to the Corona Virus Vaccine Manager.\n\n";
    cout << "Begin by entering your username: ";
    getline(cin,username);
    filename = username + ".txt";
  
    // The default constructor is called here
	Waiting superdrug;
    fin.open(filename.c_str());
  
    if(!fin.fail())
    {
        superdrug.load(fin);
        fin.close();
	}
  
	choice = menu();
	while(choice != '0')
    {
	    switch(choice)
        {
	        case '1':
                cout<<"Enter the appointment information.\n";
                cin>>ap;
                superdrug.add(ap);
                break;
            
	        case '2':
                superdrug.display(cout);
                break;
            
	        case '3':
		            cout<<"Enter the name of the person who is to be removed.\n ";
                while(cin.peek() == '\n' || cin.peek() == '\r')
                    cin.ignore();
                getline(cin, patientname);
                cout << superdrug.find(patientname);
                cout << "Do you want your remove this appointment request? (y/n)\n";
                cin >> ch;
            
                if(tolower(ch) == 'y')
                {
                    superdrug.remove(patientname);
                }
                break;
            
	        case '4':
		        cout << "Number waiting  = " << superdrug.waiting() << endl;
		        break;
            
	        case '5':
		            cout << "The longest wait = ";
		            convert_minutes(superdrug.longest_wait());
		            cout << endl;
		            break;
            
	        case '6':
		        cout << "The average wait time of all in line = ";
                convert_minutes(superdrug.average_wait());
                cout << endl;
		        break;
            
	        case '7':
                cout << "The oldest person in line is " << superdrug.oldest() << " years old.\n";
                break;
            
	        case '8':
                cout << "The youngest person in line is " << superdrug.youngest() << " years old.\n";
                break;
            
	        case '9':
                cout << "The average age of those in line is " << superdrug.average_age() << " years old.\n";
                break;
            
	        case '0':
                cout << "Thank you for using the Appointment Manager.\n";
                break;
            
            // copy constructor test
	        case 't':
            {
                Waiting apcopy(superdrug); // you must write all 3 of the Big 3
                cout << "Enter the name of the person who is to be removed.\n ";
              
                while(cin.peek() == '\n' || cin.peek() == '\r')
                    cin.ignore();
                getline(cin, patientname);
                apcopy.remove(patientname);
                apcopy.display();
                cout << "Number waiting = " << apcopy.waiting() << endl;
                break;
		    }  // copy goes out of scope
            
	        default:
                cout << "Not an option.\n";
                break;
            
	    } //bottom of the switch
      
	    choice = menu();
	}// bottom or the while loop, which is a senteniel loop

    fout.open(filename.c_str());
    if(!fout.fail())
	      superdrug.save(fout);
    else
	      cout<<"Problem with saving data!\n";
    fout.close();

return 0;
}

char menu()
{
    char choice;
    cout << "Choose from the following options:\n";
    cout << "1) Add an appointment request to the list.\n";
    cout << "2) Display all the appointment requests in the list.\n";
    cout << "3) Remove an appointment request.\n";
    cout << "4) Display number of people waiting in line.\n";
    cout << "5) Display wait time of longest waiting.\n";
    cout << "6) Average wait time for all currently in line.\n";
    cout << "7) Oldest person in the list. \n";
    cout << "8) Youngest person in the list. \n";
    cout << "9) Average age of those in the list. \n";
    cout << "0) Quit - saving all changes.\n";
    cin >> choice;

    return choice;
}
