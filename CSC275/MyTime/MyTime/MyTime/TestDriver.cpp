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
	TestMethod(0, t0.GetTicks(), 
		"MyTime t0;");
	
	cout << "\n--- Parameterized Constructors ----\n";
	MyTime t1(12, 45, 30, 10); 
    TestMethod(4593010, t1.GetTicks(), 
		"MyTime t1(12, 45, 30, 10);");
	MyTime t2(1, 30, 10);
	TestMethod(541000, t2.GetTicks(), 
		"MyTime t2(1, 30, 10);");
	MyTime t3(2, 56);
	TestMethod(1056000, t3.GetTicks(), 
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
	TestMethod(2, t3.GetHours(), 
		"t3.GetHours();");
	t1.SetHours(4);
	TestMethod(4, t1.GetHours(), 
		"t1.SetHours(1);, t1.GetHours();");
	t2.SetMinutes(0);
	TestMethod(0, t2.GetMinutes(), 
		"t2.SetMinutes(0);, t2.GetMinutes();");
	t3.SetSeconds(13);
	TestMethod(13, t3.GetSeconds(), 
		"t3.SetSeconds(13);, t3.GetSeconds();");
	t4.SetTicks(50);
	TestMethod(50, t4.GetTicks(), 
		"t4.SetTicks(50);, t4.GetTicks();");
	t4.SetTicks(t4.GetTicks());
	TestMethod(50, t4.GetTicks(), 
		"t4.SetTicks(t4.GetTicks());");

	cout << "\n--- SetTimes ---------------------\n";
	t1.SetTime(4, 30, 25, 3);
	TestMethod(1622503, t1.GetTicks(), 
		"t1.SetTime(4, 30, 25, 3);");
	t2.SetTime(3, 22, 11);
	TestMethod(1213100, t2.GetTicks(), 
		"t2.SetTime(3, 22, 11);");
	t3.SetTime(2, 56);
	TestMethod(1056000, t3.GetTicks(), 
		"t3.SetTime(2, 56);");
	t4.SetTime(23456);
	TestMethod(23456, t4.GetTicks(), 
		"t4.SetTime(23456);");
	t4.SetTime(t4);
	TestMethod(23456, t4.GetTicks(), 
		"t4.SetTime(t4);");

	//cout << "\n--- Now() ------------------------\n";
	//t0 = MyTime::Now();
	//cout << "t0 = MyTime::Now();";
	//cout << t0.GetHours() << ":" << t0.GetMinutes() << 
	//	":" << t0.GetSeconds() << "." << t0.GetTicks();

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
	cout << "Now testing operator <<.");
	cout << "This should be 16:30:47.12.");
	t3.SetTicks(5944712);
	cout << t3;
	cout << "This should be 0:0:0.0");
	t3.SetTicks(0);
	cout << t3;
	cout << "Not testing operator >>.\n");
	cout << "Press Enter";
	cin >> t0;
	TestMethod(
	cout << "Enter: \"12:30:45.56\"\n";
	cin >> t0;
	TestMethod(4504556, t0.GetTicks(),
		"cin >> t0;");


	/*
	cout << "\n***************************************************************************\n";
	cout << "\n******** MyDate ***********************************************************\n";
	cout << "\n***************************************************************************\n\n";
	
	*/
	return 0;
} 