#include <iostream>
#include <string>
#include "MyArray.h"

using namespace std;

MyArray<string> LSystem(MyArray<string> rules, string axiom, int generations);

int main()
{
	MyArray<string> rules;
	string axiom;
	int i, generations;
	cout << "Welcome to Caleb Thompson's L-Systems Explorer.\n";
	cout << "All input will be accepted without verification \nso ensure that you use proper form.\n\n";
	cout << "Please input a rule or rules.  Enter \"done\" when you have finished.\nEnter \"oops\" if you make a mistake.\n";
	
	i = 0;

	string temp;
	while(true)
	{
		cin >> temp;
		if (temp == "done") break; 
		else if (temp == "oops") rules.RemoveAt(rules.Size() - 1);
		else rules.Add(temp);
	}

	cout << "\n\nPlease input an axiom.\n";
	cin >> axiom;
	cout << "\n\nHow many generations?\n";
	cin >> generations;

	MyArray<string> system = LSystem(rules, axiom, generations);
	for(int i = 0; i < system.Size(); i++)
	{
		cout << endl << i << ": " << system[i];
	}
}

MyArray<string> LSystem(MyArray<string> rules, string axiom, int generations)
{
	string currentGeneration = axiom;
	MyArray<string> result;

	for (int i = 0; i < generations; i++)
	{
		result.Add("");
		for each (char c in currentGeneration)
		{
			bool foundRule = false;
			for (int j = 0; j < rules.Size(); j++)//each (string rule in rules)
			{
				string rule = rules[j];
				if (rule[0] == c)
				{
					// because of the format of the rules,
					// will always be from index 3 to the end of the string.
					result[i].append(rule.substr(3));
					foundRule = true;
					//break;
				}
			}
			if (!foundRule) result[i].append(1,c);
		}
		currentGeneration = result[i];
	}
	// inserting before the logic above sets everything off by one.
	result.Insert(axiom, 0);
	return result;
}