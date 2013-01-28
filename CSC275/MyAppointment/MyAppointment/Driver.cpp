#include "MyAppointment.h"
#include <fstream>

using namespace std;

MyArray<MyAppointment> appointments;

int MainScreen()
{
	int inputMainScreen;
	MyTime currentTime;
	currentTime = currentTime.Now();
	MyDate currentDate;
	currentDate = currentDate.Now();

	system("cls");
	cout << "Currently " << appointments.Size() << " appointments.\t\t\t"
		<< currentTime << "\t"
		<< currentDate << "\n"
		<< "1) New Appointment\n"
		<< "2) View Appointments\n"
		<< "3) Range of Dates\n"
		<< "4) Change Appointment\n"
		<< "5) Delete Appointment\n"
		<< "6) Exit\n\n>> ";

	while(!(cin >> inputMainScreen))
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\n>> ";
	}
	return inputMainScreen;
}

void DoStuff(int inputFromMain)
{
	MyAppointment aMyAppointment;
	MyDate first, second;
	MyArray<MyAppointment> insideRange;
	int input = -99;

	switch(inputFromMain)
	{
	case 1:
		// Create a new appointment
		try
		{
			cin.ignore();
			cout << "Title: ";
			aMyAppointment.SetTitle();
			cout << endl << "Description: ";
			aMyAppointment.SetDescription();
			cout << endl << "Date (DD/MM/YYYY): ";
			aMyAppointment.SetDate();
			cout << endl << "Time (24Hr H:MM): ";
			aMyAppointment.SetTime();
		}
		catch(exception e)
		{
			cout << "I'M LATE! I'M LATE!  That didn't work quite right...\n";
			cout << e.what() << endl;
		}
		aMyAppointment.Display();
		cout << "Press any key to continue";
		cin.ignore();
		appointments.Add(aMyAppointment);
		break;
	case 2:
		// View appointments
		for (int i = 0; i < appointments.Size(); i++)
		{
			cout << i << ") " << appointments[i].GetTitle() << "\t" 
				<< appointments[i].GetDate() << endl;
		}
		while(input != -1)
		{
			cout << "Which appointment would you like to view ('-1' returns to Main Menu)?\n>> ";
			cin >> input;
			if(input >= 0 && input < appointments.Size())
			{
				appointments[input].Display();
			}
		}
		break;
	case 3:
		// Range of dates
		cout << "Enter first date.\n>> ";
		cin >> first;
		cout << "\nEnter second date.\n>> ";
		cin >> second;
		for(int i = 0; 9 < appointments.Size(); i++)
		{
			if(appointments[i].GetDate() > first && appointments[i].GetDate() < second)
				insideRange.Add(appointments[i]);
		}
		for (int i = 0; i < insideRange.Size(); i++)
		{
			cout << i << ") " << insideRange[i].GetTitle() << "\t" 
				<< insideRange[i].GetDate() << endl;
		}
		if (insideRange.Size() <= 0)
		{
			cout << "No appointments in range.";
		} 
		else
		{
			while(input != -1)
			{
				cout << "Which appointment would you like to view ('-1' returns to Main Menu)?\n>> ";
				cin >> input;
				if(input >= 0 && input < insideRange.Size())
				{
					insideRange[input].Display();
				}
			}
		}
		break;
	case 4:
		// Change appointment
		for (int i = 0; i < appointments.Size(); i++)
		{
			cout << i << ") " << appointments[i].GetTitle() << "\t" 
				<< appointments[i].GetDate() << endl;
		}
		while(input < -1 || input > appointments.Size())
		{
			cin.ignore();
			cout << "Which appointment would you like to change ('-1' returns to Main Menu)?\n>> ";
			cin >> input;
			if(input == -1) break;
		}
		if(input != -1)
		{
			appointments[input].Display();
			try
			{
				cin.ignore();
				cout << "Title: ";
				appointments[input].SetTitle();
				cout << endl << "Description: ";
				appointments[input].SetDescription();
				cout << endl << "Date (DD/MM/YYYY): ";
				appointments[input].SetDate();
				cout << endl << "Time (H:MM): ";
				appointments[input].SetTime();
			}
			catch(exception e)
			{
				cout << "\nI'M LATE! I'M LATE!  That didn't work quite right...\n";
				cout << e.what() << endl;
			}
			appointments[input].Display();
			cout << "Press any key to continue";
			cin.ignore();
		}
		break;
	case 5:
		// delete appointment
		for (int i = 0; i < appointments.Size(); i++)
		{
			cout << i << ") " << appointments[i].GetTitle() << "\t" 
				<< appointments[i].GetDate() << endl;
		}
		while(input < -1 || input > appointments.Size())
		{
			cout << "Which appointment would you like to delete ('-1' returns to Main Menu)?\n>> ";
			cin >> input;
			if(input == -1) break;
		}
		if(input == -1)
			break;
		appointments.RemoveAt(input);
		break;
	default:
		break;
	}
}
int main()
{
	int inputMain = -1;

	// Read from file
	MyAppointment temp;
	ifstream in;
	in.open("appointments.txt"/*, ios::in*/);
	if(in)
	{
		MyString buffer;
		long dateTime;
		while(!in.eof() && in.peek() != '\0')
		{
			if(in.peek() == '\n' || in.peek() == ' ') in.ignore();
			in >> buffer;
			temp.SetTitle(buffer);
			if(in.peek() == '\n' || in.peek() == ' ') in.ignore();
			in >> buffer;
			temp.SetDescription(buffer);
			if(in.peek() == '\n' || in.peek() == ' ') in.ignore();
			in >> dateTime;
			temp.SetDate(dateTime);
			if(in.peek() == '\n' || in.peek() == ' ') in.ignore();
			in >> dateTime;
			temp.SetTime(dateTime);
			appointments.Add(temp);
		}
		in.close();
	}
	else
	{
		cout << "I'M LATE! I'M LATE! File open failed.";
		cin.ignore();
	}

	// User interaction
	while(inputMain != 0)
	{
		inputMain = MainScreen();
		if(inputMain == 6)
			return 0;
		DoStuff(inputMain);
	}

	// Dump back to file
	ofstream out;
	out.open("appointments.txt"/*, ios::trunc*/);
	if(out)
	{
		//out.clear();
		for(int i = 0; i < appointments.Size(); i++)
		{
			out << appointments[i].GetTitle() << "\n";
			out << appointments[i].GetDescription() << "\n";
			out << appointments[i].GetDateSerial() << "\n";
			out << appointments[i].GetTimeSerial() << "\n";	
		}
	}
	else
	{
		cout << "I'M LATE! I'M LATE!  File write error.";
		cin.ignore();
	}
	out.close();

	return 0;
}
