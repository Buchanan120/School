#!/usr/bin/perl
###############################################################################
##  Caleb  Thompson   CalThomp@uat.edu
##  Date of initial creation: 2009-09-19
##  Date of last edit: 2009-09-26
## 
##  Descript:  This script is designed to read in a list of numbers from a file
##             and output various data on the numbers based on a layout given 
##             in the course shell.  This script will use no arrays, in favor
##             of hashes.
###############################################################################
 
##
## Declarations 
##  

my $thisLine;	    ## Holds current line being read from file.
my $lineNumber;     ## Counter for line number in input file.
my @names;          ## Array to hold names from input file.
my @phoneNumbers;   ## Array to hold ph. numbers from input file.
my $searchTerm;     ## User-input search term.
my %phonebook;      ## Hash phonebook holds the name as key and the phone
                    ##  number as value.

##
## This section handles the collection of the names and phone numbers from the
## input file.  It uses arrays to hold each type of data.
##

while(<>) {
    $lineNumber++;
    $_ =~ s/[\r\n]//g;  ## Strips out newlines and carriage return.
	if($lineNumber % 2) {
        push(@names, $_);
    }else {
        push(@phoneNumbers, $_);
    }
}

##
## Convert the two arrays into a %phonebook hash.
##

@phonebook{ @names } = @phoneNumbers;

##
## This section handles user input of a search term and searches the hash for
## the search term.  If there is not an exact match, it outputs an error.
##

print "What name would you like to search for?\n";
$searchTerm = <STDIN>;
if (exists $phonebook{$searchTerm}) {
    print "$searchTerm: $phonebook{$searchTerm}\n";
}else {
    print "no such name";
}
    