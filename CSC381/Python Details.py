#Optional semicolons
"""
Python doesn't require that the programmer use semicolons at the end
of lines, but for those of us who are used to C style languages which
do require a semicolon, it is kind enough to ignore them if they are
at the end of the line. Semicolons do serve a purpose in Python,
however.  If they are used at the end of an expression, another
expression can be written on the same line.
"""
def OptionalSemicolons():
    x = 1
    y = 2;
    print(x); print(y)


#Raw Python Strings
"""
Python has a feature similar to C# which allows for string literals,
which do not require escape characters for many special characters,
such as backslashes '\', which are themselves escape characters.
Placing a lowercase 'r' before an opening quotation mark '"' will make
the string a string literal.
"""
def RawStrings():
    string = "This is a regular string \n\
it respects newline characters and allows for \
multiline definition with the \\ delimiter."
    rawString = r"This is a rather long string containing\n\
several lines of text but is a raw string as\
                defined by the r before the opening \"."
    print("String: \n" + string)
    print("Raw String: \n" + rawString)

#String Formatting
"""
Much like .NET, Python supports string formatting with placeholders in
the form of curly bracket arguments.  Unline .NET, these arguments can
be named, such as {name}, rather than only numbered with arguments
after the string in the right order.  Python also supports "dotting"
off of a string itself, rather than .NET's String.Format("format
string", arg0, ..., argn). Format arguments can contain logic, and
nesting of format strings is also supported.
"""
def FormatString():
    print(str.format("Hello, {name}, you look no older than {0} years old.", 35, name = "Phill"))
    print(str.format("1 + 2 = {0}", 1 + 2))
    print(str.format("This string has {formattedString}", formattedString = \
                     "{adjective} {noun}.".format(adjective = "nested", noun = "formatting")))


#Simple Syntax
"""
Unlike C++, where a simple Hello World would be:
    #include <iostream>
    using namespace std;
    int main()
    {
        cout << "Hello World!" << endl;
        return 0;
    }
Or even C#:
    using System;
    public class Hello
    {
       public static void Main()
       {
          Console.WriteLine("Hello, World!");
       }
    }
Python has a very simple syntax for almost anything.  In fact, even
using functions the program is only 2 lines long. Here is the Python
HelloWorld program:
"""
def HelloWorld():
    print("Hello, World!")

#Function Aliasing
"""
Python allows for transparant aliasing of one function to another, in
the form of assignment of the target to the aliased name.  This can be
done both with existing functions and with any given name.
"""
def Foo():
    print("I am function Foo.")
def Bar():
    print("I am function Bar.")
    
#String Translate
"""
Python's string class is extremely robust.  The format function itself
has already been gone over here, but only the tip of the iceburg.
Format has its own sublanguage just to get exactly what the programmer
wants out of a string, not unlike Perl.  Here is an example of another
string function, translate, which in this case performs a simple
alphabetical shift cypher on a string.
"""
import string
from string import maketrans
def StringTranslate(string = """g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr
amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw
rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb."""):
    intab = "abcdefghijklmnopqrstuvwxyz"
    outtab = "cdefghijklmnopqrstuvwxyzab"

    print(string.translate(maketrans(intab, outtab)))

#Math
"""
Python has a fairly robust built in math library.  It's called math.
Here are some functions using the math library to show it off.  
"""
import math
def Maths():
    print math.pow(3,4) # return 3 to the 4th power (i.e., 81)
    print math.log(8,2) # return the logarithm of 8, with base 2 (i.e., 3)
    print math.pi       # return the value of pi


print("Optional Semicolons:")
OptionalSemicolons()
print("\nRaw Strings:")
RawStrings()
print("\nFormat String:")
FormatString()
print("\nSimple Syntax:")
HelloWorld()
print("\nFunction Aliasing:")
#Vanilla function Foo
Foo()
#Alias Bar to Foo
Foo = Bar
#This now points to Bar
Foo()
print("\nString Translate:")
StringTranslate()
print("\nMath:")
Maths()



