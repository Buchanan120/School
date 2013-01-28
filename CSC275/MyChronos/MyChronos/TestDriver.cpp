// TestDriver.cpp defines the entry point for the MyChron project

#include <iostream>
using namespace std;

#include "MyTime.h"
#include "MyDate.h"

void TestMethod(long expected, long actual, char* message) {
	if (expected != actual) {
        cout << "*****FAILED***** " << message
             << " [expected = " << expected << " actual = " << actual << "]\n";
	}else
        cout << "PASSED " << message << "\n";
}

int main () {

	cout << "\n***************************************************************************\n";
	cout << "\n******** MyTime ***********************************************************\n";
	cout << "\n***************************************************************************\n\n";

	cout << "\n======== CONSTRUCTORS =====================================================\n";
	cout << "\n--- Default Constructor -----------\n";
	MyTime t0;
	TestMethod(0, t0.GetTicks(), // Default is no ticks
		"MyTime t0;");
	
	cout << "\n--- Parameterized Constructors ----\n";
	MyTime t1(12, 45, 30, 10); 
    TestMethod(4593010, t1.GetTicks(), // 4593010 from Ticks Calculator for 12:45:30.10
		"MyTime t1(12, 45, 30, 10);");
	MyTime t2(1, 30, 10);
	TestMethod(541000, t2.GetTicks(),  // 541000 from Ticks Calculator for 1:30:10
		"MyTime t2(1, 30, 10);");
	MyTime t3(2, 56);
	TestMethod(1056000, t3.GetTicks(), // 1056000 from Ticks Calculator for 2:56
		"MyTime t3(2, 56);");
	
	cout << "\n--- Ticks -------------------------\n";
	MyTime t4(10000);
	TestMethod(10000, t4.GetTicks(), 
		"MyTime t4(10000);");
	
	cout << "\n--- Copy Constructor --------------\n";
	MyTime t5(t2);
	TestMethod(t2.GetTicks(), t5.GetTicks(), 
		"MyTime t5(t2);");

	cout << "\n======== METHODS ==========================================================\n";
	cout << "\n--- Accessors and Mutators --------\n";
	TestMethod(2, t3.GetHours(), // Previously set to two hours
		"t3.GetHours();");
	t1.SetHours(4);
	TestMethod(4, t1.GetHours(), 
		"t1.SetHours(4);, t1.GetHours();");
	t2.SetMinutes(0);
	TestMethod(0, t2.GetMinutes(), 
		"t2.SetMinutes(0);, t2.GetMinutes();");
	t3.SetMinutes(0);
	t3.SetSeconds(90);
	TestMethod(1, t3.GetMinutes(), // Rollover from SetSeconds(90)
		"t3.SetSeconds(90), t3.GetMinutes();");
	TestMethod(30, t3.GetSeconds(), 
		"t3.SetSeconds(90);, t3.GetSeconds();");
	t4.SetTicks(50);
	TestMethod(50, t4.GetTicks(), 
		"t4.SetTicks(50);, t4.GetTicks();");
	t4.SetTicks(t4.GetTicks());
	TestMethod(50, t4.GetTicks(), 
		"t4.SetTicks(t4.GetTicks());");

	cout << "\n--- SetTimes ---------------------\n";
	t1.SetTime(4, 30, 25, 3);
	TestMethod(1622503, t1.GetTicks(), // 1622503 from Ticks Calculator for 4:30:25.03
		"t1.SetTime(4, 30, 25, 3);");
	t2.SetTime(3, 22, 11);
	TestMethod(1213100, t2.GetTicks(), // 1213100 from Ticks Calculator for 3:22:11
		"t2.SetTime(3, 22, 11);");
	t3.SetTime(2, 56);
	TestMethod(1056000, t3.GetTicks(), // 1056000 from Ticks Calculator for 2:56
		"t3.SetTime(2, 56);");
	t4.SetTime(23456);
	TestMethod(23456, t4.GetTicks(), 
		"t4.SetTime(23456);");
	t4.SetTime(t4);
	TestMethod(23456, t4.GetTicks(), 
		"t4.SetTime(t4);");

	cout << "\n--- Add --------------------------\n";
	t0.SetTime(0,0,0,0);
	cout << "t0.SetTime(0,0,0,0);\n";
	t0.AddHours(1);
	TestMethod(360000, t0.GetTicks(), 
		"t0.AddHours(1);");
	t0.AddMinutes(30);
	TestMethod(540000, t0.GetTicks(), 
		"t0.AddMinutes(30);");
	t0.AddSeconds(45);
	TestMethod(544500, t0.GetTicks(), 
		"t0.AddSeconds(45);");
	t0.AddTicks(12);
	TestMethod(544512, t0.GetTicks(), 
		"t0.AddTicks(12);");
	t0.AddTime(t0);
	TestMethod(1089024, t0.GetTicks(), 
		"t0.AddTime(t0);");
    
	cout << "\n--- Compare ----------------------\n";
	t0.SetTime(1,2,3,4);
	cout << "t0.SetTime(1,2,3,4);\n"; 
	t1.SetTime(5,6,7,8);
	cout << "t1.SetTime(5,6,7,8);\n";
	t2.SetTime(0,1,2,3);
	cout << "t2.SetTime(0,1,2,3);\n";
	t3.SetTime(t0);
	cout << "t3.SetTime(t0);\n";
	
	TestMethod(0, t0.Compare(t3), 
		"t0.SetTime(1,2,3,4);, t3.SetTime(t0);, t0.Compare(t3)");
	TestMethod(1, t0.Compare(t2), 
		"t0.SetTime(1,2,3,4);, t2.SetTime(0,1,2,3);, t0.Compare(t2)");
	TestMethod(-1, t2.Compare(t1), 
		"t2.SetTime(0,1,2,3);, t1.SetTime(5,6,7,8);, t2.Compare(t1)");

	cout << "\n--- Equals -----------------------\n";
	TestMethod(1, t0.Equals(t3), 
		"t0.Equals(t3)");
	TestMethod(1, t0.Equals(t0), 
		"t0.Equals(t0)");
	TestMethod(0, t2.Equals(t3), 
		"t2.Equals(t3)");

	cout << "\n--- Subtract ---------------------\n";
	t1.SubtractHours(2);
	TestMethod(3, t1.GetHours(), 
		"t1.SubtractHours(2);");
	t1.SubtractMinutes(3);
	TestMethod(3, t1.GetMinutes(), 
		"t1.SubtractMinutes(3);");
	t1.SubtractSeconds(4);
	TestMethod(3, t1.GetSeconds(), 
		"t1.SubtractSeconds(4);");
	t1.SubtractTicks(5);
	TestMethod(1098303, t1.GetTicks(), 
		"t1.SubtractTicks(5);");
	t1.SubtractTime(t2);
	TestMethod(1092100, t1.GetTicks(), 
		"t1.SubtractTime(t2);");

	cout << "\n--- Overloaded Operators ---------\n";
	cout << "Now testing operator <<.\n";
	cout << "This should be 16:30:47.12.\n";
	t3.SetTicks(5944712);
	cout << t3 << endl;
	cout << "This should be 0:0:0.0\n";
	t3.SetTicks(0);
	cout << t3 << endl;
	cout << "Test insertion operator?  0 or 1 \n";
	bool test;
	cin >> test;
	if (test){
		cout << "Not testing operator >>.\n";
		cout << "Enter 0:0\n";
		cin >> t0;
		TestMethod(0, t0.GetTicks(),
			"cin >> t0; (Default Case)");
		cout << "Enter: \"12:30:45.56\"\n";
		cin >> t0;
		TestMethod(4504556, t0.GetTicks(),
			"cin >> t0;(12:30:45.56)");
		cout << "Enter: \"1:54\"\n";
		cin >> t0;
		TestMethod(684000, t0.GetTicks(),
			"cin >> t0;(11:54)");
	}

	cout << "Now testing operator >>.\n";
	cout << "Is this Now()?\n";
	t0.Now();
	cout << t0;


	
	cout << "\n***************************************************************************\n";
	cout << "\n******** MyDate ***********************************************************\n";
	cout << "\n***************************************************************************\n\n";
	
	cout << "\n--- Default Constructor -----------\n";
	MyDate d0;
	TestMethod(0, d0.GetDateSerial(), 
		"MyDate d0;");

	cout << "\n--- Parameterized Constructors ----\n";
	MyDate d1(1, 1, 1970);
	cout << "The next two lines should be identical." << endl;
	cout << "01/01/1970" << endl;
	cout << d1 << endl;
	MyDate d2(1000);
	TestMethod(1000, d2.GetDateSerial(),
		"MyDate d2(1000);");
	MyDate d3(d2);
	TestMethod(d2.GetDateSerial(), d3.GetDateSerial(),
		"MyDate d3(d2);");
	d3.SetYear(2009);
	d3.SetMonth(10);
	d3.SetDay(30);

	cout << "\n------ IsLeapYear -----------------\n";
	TestMethod(false, d1.IsLeapYear(),
		"d1.IsLeapYear(); (1970)");
	TestMethod(true, d1.IsLeapYear(2000),
		"d1.IsLeapYear(2000);");
	TestMethod(false, d2.IsLeapYear(d2),
		"d2.IsLeapYear(d2);");

	cout << "\n------ GetDay ---------------------\n";
	TestMethod(1, d1.GetDay(),
		"d1.GetDay(); (1)");
	TestMethod(28, d2.GetDay(),
		"d2.GetDay(); (28)");
	TestMethod(30, d3.GetDay(),
		"d3.GetDay(); (30)");

	cout << "\n------ GetMonth -------------------\n";
	TestMethod(1, d1.GetMonth(),
		"d1.GetMonth(); (1)");
	TestMethod(9, d2.GetMonth(),
		"d2.GetMonth(); (9)");
	TestMethod(10, d3.GetMonth(),
		"d3.GetMonth(); (10)");

	cout << "\n------ GetYear --------------------\n";
	TestMethod(1969, d1.GetYear(),
		"d1.GetYear(); (1970)");
	TestMethod(2, d2.GetYear(),
		"d2.GetYear(); (3)");
	TestMethod(2008, d3.GetYear(),
		"d3.GetYear(); (2009)");

	cout << "\n------ GetDayName -----------------\n";
	char dayName[9];
	d1.GetDayName(dayName);
	cout << "This should be\nFriday" << endl;
	cout << dayName << endl;

	cout << "\n------ GetMonth Name --------------\n";
	char monthName[10];
	d1.GetMonthName(monthName);
	cout << "This should be\nJanuary" << endl;
	cout << monthName << endl;

	cout << "\n------ SetDate --------------------\n";
	d2.SetDate(2000);
	TestMethod(2000, d2.GetDateSerial(),
		"d2.SetDate(2000);");
	try {
		d2.SetDate(-1);
	} catch (exception &e) {
		cout << "Caught: " << e.what() << endl;
	}
	d2.SetDate(d1);
	TestMethod(d1.GetDateSerial(), d2.GetDateSerial(),
		"d2.SetDate(d1);");
	d2.SetDate(10, 9, 1989); // My birthday
	TestMethod(726356, d2.GetDateSerial(), /// one year off  // Date 726356 calculated online
		"d2.SetDate(10, 9, 1989);");

	cout << "\n------ Now ------------------------\n";
	d2 = d2.Now();
	cout << "Is this today?\n";
	cout << d2 << endl;

	cout << "\n------ Add ------------------------\n";
	d2.SetDate(726356); // My birthday from before
	d2.AddDate(d1);
	TestMethod((d1.GetDateSerial() + 726356), d2.GetDateSerial(),
		"d2.AddDate(d1);");
	d2.SetDate(0);
	d2.AddDays(5000); // 09/09/0014
	TestMethod(5000, d2.GetDateSerial(),
		"d2.SetDate(0); d2.AddDays(5000);");
	d2.AddMonths(4); // 01/09/0015
	TestMethod(5122, d2.GetDateSerial(), //123 days in Oct, Nov, Dec + remainer of Sep
		"d2.AddMonths(4);");
	d2.AddYears(25); // 01/09/0040
	TestMethod(39, d2.GetYear(),
		"d2.AddYears(25);");
	cout << d2 << endl;

	cout << "\n------ Compare --------------------\n";
	TestMethod(0, d2.Compare(d2),
		"d2.Compare(d2);");
	TestMethod(-1, d2.Compare(d1),
		"d2.Compare(d1); (01/01/0040 vs 01/01/1970)");
	TestMethod(1, d3.Compare(d2),
		"d3.Compare(d2); (UNIX epoch vs Today.)");

	cout << "\n------ Equals ---------------------\n";
	TestMethod(false, d2.Equals(d1),
		"d2.Equals(d1)");
	TestMethod(false, d1.Equals(d2),
		"d1.Equals(d2)");
	d1.SetDate(d2);
	TestMethod(true, d1.Equals(d2),
		"d1.SetDate(d2); d1.Equals(d2);");

	cout << "\n------ Subtract -------------------\n";
	d1.SetDate(10,10,10);
	cout << "d1 == " << d1 << endl;
	d1.SubtractDays(9);
	TestMethod(1, d1.GetDay(),
		"d1.SubtractDays(9);");
	cout << "d1 == " << d1 << endl;
	d1.SubtractMonths(9);
	TestMethod(1, d1.GetMonth(),
		"d1.SubtractMonths(9);");
	cout << "d1 == " << d1 << endl;
	d1.SubtractYears(9);
	TestMethod(1, d1.GetYear(),
		"d1.SubtractYears(9);");

cout << "\n--- Overloaded Operators ---------\n";
	cout << "Now testing operator =.\n";
	d1 = d2;
	TestMethod(d2.GetDateSerial(), d1.GetDateSerial(),
		"d1 = d2;");

	cout << "\nNow testing operator +.\n";
	d1 = d1 + d2;
	TestMethod(d2.GetDateSerial() * 2, d1.GetDateSerial(),
		"d1 = d1 + d2;");

	cout << "\nNow testing operators = and +=.\n";
	d1 = d2;
	d1 += d2;
	TestMethod(d2.GetDateSerial() * 2, d1.GetDateSerial(),
		"d1 = d2; d1 += d2;");

	cout << "\nNow testing operator <.\n";
	TestMethod(true, d2 < d1,
		"d2 < d1");
	TestMethod(false, d1 < d2,
		"d1 < d2");

	cout << "\nNow testing operator >.\n";
	TestMethod(false, d2 > d1,
		"d2 < d1");
	TestMethod(true, d1 > d2,
		"d1 < d2");

	cout << "\nNow testing operator <=.\n";
	TestMethod(false, d2 <= d1,
		"d2 <= d1");
	TestMethod(true, d1 <= d2,
		"d1 <= d2");
	TestMethod(true, d2 <= d2,
		"d2 <= d2");

	cout << "\nNow testing operator >=.\n";
	TestMethod(true, d2 >= d1,
		"d2 >= d1");
	TestMethod(false, d1 >= d2,
		"d1 >= d2");
	TestMethod(true, d1 >= d1,
		"d1 >= d1");
	

	cout << "\nNow testing operator ==.\n";
	TestMethod(false, d1 == d2,
		"d1 == d2");
	TestMethod(true, d2 == d2,
		"d2 == d2");

	cout << "\nNow testing operator !=.\n";
	TestMethod(true, d1 != d2,
		"d1 != d2");
	TestMethod(false, d2 != d2,
		"d2 != d2");

cout << "\n--- >> ---------------------------\n";
	cout << "Play with input until you are convinced it works.\n";
	MyDate dInput;
	while(true) {
		cin >> dInput;
		cout << dInput << endl << endl;
	}

	return 0;
} 