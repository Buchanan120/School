#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	cout << "=== CONSTRUCTORS ===================================\n\n";
	
	cout << " >>> MyString s1;\n";
	MyString s1;

	cout << " >>> MyString s2(\"abc 123\");\n";
	MyString s2("abc 123");

	cout << " >>> MyString s3(10);\n";
	MyString s3(10);

	cout << " >>> MyString s4(s2);\n";
	MyString s4(s2);

	cout << "\n s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n";
	cout << " s4 = [" << s4 << "]\n\n";

	cout << "=== METHODS ========================================\n";

	cout << "\n--- APPEND -----------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n";
	cout << " s4 = [" << s4 << "]\n\n";

	s1.Append("xyz");
	cout << " >>> s1.Append(\"xyz\");                    s1 = [" << s1 << "]\n";
	s1.Append("");
	cout << " >>> s1.Append(\"\");                       s1 = [" << s1 << "]\n";
	s2.Append(s1);
	cout << " >>> s2.Append(s1);                s2 = [" << s2 << "]\n";
	s3.Append("12345678901234567890");
	cout << " >>> s3.Append(\"12345678901234567890\");\n";
	cout << "                         s3 = [" << s3 << "]\n";
	s4.Append(s4);
	cout << " >>> s4.Append(s4);            s4 = [" << s4 << "]\n";

	cout << "\n--- ASSIGN -----------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n";
	cout << " s4 = [" << s4 << "]\n\n";

	s1.Assign(s2);
	cout << " >>> s1.Assign(s2);                  s1=[" << s1 << "]\n";
	s2.Assign("pink pony");
	cout << " >>> s2.Assign(\"pink pony\");        s2 = [" << s2 << "]\n";
	s3.Assign(s3);
	cout << " >>> s3.Assign(s3);      s3 = [" << s3 << "]\n";
	s4.Assign("");
	cout << " >>> s4.Assign(\"\");                          s4 = [" << s4 << "]\n";


	cout << "\n--- AT ---------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n\n";

	cout << " >>>                                  s1.At(4) = [" << s1.At(4) << "]\n";

	cout << "\n--- Clear ------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n\n";

	s1.Clear();
	cout << " >>> s1.Clear();                             s1 = [" << s1 << "]\n";
	s2.Clear(10);
	cout << " >>> s2.Clear(10);                           s2 = [" << s2 << "]\n";

	cout << "\n--- Compare ----------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n";
	cout << " s4 = [" << s4 << "]\n\n";

	cout << " >>>                            s1.Compare(s2) = [" << s1.Compare(s2) << "]\n";
	cout << " >>>                            s3.Compare(s4) = [" << s3.Compare(s4) << "]\n";
	cout << " >>>                           s4.Compare(s3) = [" << s4.Compare(s3) << "]\n";
	cout << " >>>                            s4.Compare(s4) = [" << s4.Compare(s4) << "]\n";
	cout << " >>>        s3.Compare(\"12345678901234567890\") = [" << s3.Compare("12345678901234567890") << "]\n";

	cout << "\n--- Equals -----------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n";
	cout << " s4 = [" << s4 << "]\n\n";

	cout << " >>>                             s1.Equals(s2) = [" << s1.Equals(s2) << "]\n";
	cout << " >>>                             s3.Equals(s4) = [" << s3.Equals(s4) << "]\n";
	cout << " >>>                             s4.Equals(s4) = [" << s4.Equals(s4) << "]\n";
	cout << " >>>         s3.Equals(\"12345678901234567890\") = [" << s3.Equals("12345678901234567890") << "]\n";

	cout << "\n--- Find -------------------------------------------\n\n";

	cout << " s3 = [" << s3 << "]\n";
	cout << " s4 = [" << s4 << "]\n\n";

	cout << " >>>                            s3.Find(\"456\") = [" << s3.Find("45") << "]\n";
	cout << " >>>                              s3.Find(s4) = [" << s3.Find(s4) << "]\n";
	cout << " >>>                               s3.Find(s3) = [" << s3.Find(s3) << "]\n";


	cout << "\n--- Insert -----------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n";
	cout << " s4 = [" << s4 << "]\n\n";

	s1.Insert("xxx", 0);
	cout << " >>> s1.Insert(\"xxx\", 0);                 s1 = [" << s1 << "]\n";
	s1.Insert(s1, 1);
	cout << " >>> s1.Insert(s1, 1);                 s1 = [" << s1 << "]\n";
	s2.Insert(s4, 0);
	cout << " >>> s2.Insert(s4, 0);                       s2 = [" << s2 << "]\n";
	s3.Insert(s2, 5);
	cout << " >>> s3.Insert(s2, 5);   s3 = [" << s3 << "]\n";

	cout << "\n--- Length -----------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n\n";

	cout << " >>>                               s1.Length() = [" << s1.Length() << "]\n";
	cout << " >>>                               s2.Length() = [" << s2.Length() << "]\n";
	cout << " >>>                              s3.Length() = [" << s3.Length() << "]\n";

	cout << "\n--- Replace ----------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s3 = [" << s3 << "]\n\n";

	s3.Replace(3, 4, s1);
	cout << " >>> s3.Replace(3, 4, s1);  s3=[" << s3 << "]\n";
	s3.Replace(0, 1, s1);
	cout << " >>> s3.Replace(0, 1, s1);  s3=[" << s3 << "]\n";
	s3.Replace(19, 1, s1);
	cout << " >>> s3.Replace(19, 1, s1); s3=[" << s3 << "]\n";

	cout << "\n--- SubStr ------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n\n";

	s1 = s3.SubStr(0, 4);
	cout << " >>> s1 = s3.SubStr(0, 4);               s1 = [" << s1 << "]\n";
	s2 = s3.SubStr(6, 14);
	cout << " >>> s2 = s3.SubStr(6, 14);    s2 = [" << s2 << "]\n";
	s3 = s3.SubStr(2, 6);
	cout << " >>> s3 = s3.SubStr(2, 6);             s3 = [" << s3 << "]\n";

	cout << "\n=== OPERATORS ======================================\n";

	cout << "\n--- = ----------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n\n";

	s1 = s2;
	cout << " >>> s1 = s2;                  s1 = [" << s1 << "]\n";
	s2 = "Howdy!";
	cout << " >>> s2 = \"Howdy!\";                    s2 = [" << s2 << "]\n";
	s3 = s3;
	cout << " >>> s3 = s3;                          s3 = [" << s3 << "]\n";

	cout << "\n--- + ----------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n\n";

	s1 = s1 + s2;
	cout << " >>> s1 = s1 + s2;       s1 = [" << s1 << "]\n";
	s2 = s2 + "Howdy!";
	cout << " >>> s2 = s2 + \"Howdy!\";         s2 = [" << s2 << "]\n";
	s3 = s3 + s3;
	cout << " >>> s3 = s3 + s3;               s3 = [" << s3 << "]\n";


	cout << "\n--- += ---------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n";
	cout << " s3 = [" << s3 << "]\n\n";

	s1 += s2;
	cout << " >>> s1 += s2; s1=[" << s1 << "]\n";
	s2 += "Howdy!";
	cout << " >>> s2 += \"Howdy!\";         s2=[" << s2 << "]\n";
	s3 += s3;
	cout << " >>> s3 += s3;         s3=[" << s3 << "]\n\n";

	cout << "\n--- [] ---------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n\n";

	cout << " >>>	                                 s1[0] = [" << s1[0] << "]\n";
	cout << " >>>                                     s1[3] = [" << s1[3] << "]\n";
	cout << " >>>                                    s1[31] = [" <<s1[31] << "]\n\n";

	s1[0] = '&';
	s1[3] = '&';
	s1[31] = '&';
	cout << "s1[0] = '&';  s1[3] = '&';  s1[31] = '&';\n\n";

	cout << " >>>	                                 s1[0] = [" << s1[0] << "]\n";
	cout << " >>>                                     s1[3] = [" << s1[3] << "]\n";
	cout << " >>>                                    s1[31] = [" << s1[31] << "]\n";

	cout << "\n--- > ----------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n\n";

	cout << " >>>                                   s1 > s2 = [" << (s1 > s2) << "]\n";
	cout << " >>>                                s1 > \"xyz\" = [" << (s1 > "xyz") << "]\n";
	cout << " >>>                                   s1 > s1 = [" << (s1 > s1) << "]\n";

	cout << "\n--- < ----------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n\n";

	cout << " >>>                                   s1 < s2 = [" << (s1 < s2) << "]\n";
	cout << " >>>                                s1 < \"xyz\" = [" << (s1 < "xyz") << "]\n";
	cout << " >>>                                   s1 < s1 = [" << (s1 < s1) << "]\n";

	cout << "\n--- >= ---------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n\n";

	cout << " >>>                                 s1 >= s2 = [" << (s1 >= s2) << "]\n";
	cout << " >>>                              s1 >= \"xyz\" = [" << (s1 >= "xyz") << "]\n";
	cout << " >>>                                 s1 >= s1 = [" << (s1 >= s1) << "]\n";

	cout << "\n--- <= ---------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n\n";

	cout << " >>>                                 s1 <= s2 = [" << (s1 <= s2) << "]\n";
	cout << " >>>                              s1 <= \"xyz\" = [" << (s1 <= "xyz") << "]\n";
	cout << " >>>                                 s1 <= s1 = [" << (s1 <= s1) << "]\n";

		cout << "\n--- == ---------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n\n";

	cout << " >>>                                 s1 == s2 = [" << (s1 == s2) << "]\n";
	cout << " >>>                              s1 == \"xyz\" = [" << (s1 == "xyz") << "]\n";
	cout << " >>>                                 s1 == s1 = [" << (s1 == s1) << "]\n";

	cout << "\n--- != ---------------------------------------------\n\n";

	cout << " s1 = [" << s1 << "]\n";
	cout << " s2 = [" << s2 << "]\n\n";

	cout << " >>>                                 s1 != s2 = [" << (s1 != s2) << "]\n";
	cout << " >>>                              s1 != \"xyz\" = [" << (s1 != "xyz") << "]\n";
	cout << " >>>                                 s1 != s1 = [" << (s1 != s1) << "]\n";

	cout << "\n--- >> ---------------------------------------------\n\n";

	cout << "\n>>> cin >> s1;\n";
	cout << " Press ENTER >";
	cin >> s1;

	cout << "                                            s1 = [" << s1 << "]\n";

	cout << "\n>>> cin >> s1;\n";
	cout << " Enter the following \"123\' >";
	cin >> s1;

	cout << "                                         s1 = [" << s1 << "]\n";

	cout << "\n>>> cin >> s1;\n";
	cout << " Enter the following \"123 456\' >";
	cin >> s1;

	cout << "                                     s1 = [" << s1 << "]\n";

	cout << "\n>>> cin >> s1;\n";
	cout << " Enter three lines of text >\n";
	cin >> s1;

	cout << "s1 = [\n" << s1 << "\n]\n";

	cout << "\nPress Enter to continue...";
	cin >> s1;

	return 0;
}