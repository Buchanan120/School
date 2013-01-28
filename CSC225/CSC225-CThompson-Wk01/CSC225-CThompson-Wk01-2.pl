#!/usr/bin/perl
###################################
##  Caleb  Thompson   CalThomp@uat.edu
##  Date of initial creation: 2009-09-10
##  Date of last edit: 2009-09-10
## 
##  Descript:  This script is designed to
##             get a list of numbers from a useprint
##             and use them to perform some functions
###################################

print "Input your numbers seperated by returns/newlines." ;
chomp(@number = <STDIN>) ; ## @number is the same as a C notation $number[]
			   ## it is an array of numerical input.
print lengthof(@number) ;

print sum(@number) ;

print sum(@number) / lengthof(@number) ;

@numbers = sort @number ;
foreach $number (@number) {
	print "$number " ;
}
