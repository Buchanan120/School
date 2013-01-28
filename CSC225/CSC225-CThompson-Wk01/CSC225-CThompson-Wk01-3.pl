#!/usr/bin/perl
###################################
##  Caleb  Thompson   CalThomp@uat.edu
##  Date of initial creation: 2009-09-10
##  Date of last edit: 2009-09-10
## 
##  Descript:  This script is designed to
##             calculate the area and circumference
##             of a user-defined rectangle
###################################

print "Input rectangle's height:\n" ;
$height = <STDIN> ;	## holds user input of height for rectangle

print "Input rectangle's width:\n" ;
$width = <STDIN> ;	## holds user input of width for rectangle

##if (($height * $width) > 0) {
if (($height > 0) && ($width > 0)) {
	print "Your rectangle's circumference is equal to"
	print ((2 * $width) + (2 * $height)) ;
	print "\tand the area is equal to"
	print $width;# * $height ;
}else {
	print "One of your values was zero or less.  Please enter a nonzero positive integer.\n" ;
}
