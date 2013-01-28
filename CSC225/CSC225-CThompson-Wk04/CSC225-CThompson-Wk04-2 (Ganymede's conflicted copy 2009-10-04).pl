#!/usr/bin/perl
###############################################################################
##  Caleb  Thompson   CalThomp@uat.edu
##  Date of initial creation: 2009-09-19
##  Date of last edit: 2009-09-26
## 
##  Descript:  This script is designed to read in phone book entries from a
##             file and use hashes to output entries based on complete or
##             partial name input.  Program ends when user enters "done" in
##             any case.
###############################################################################

use strict; 

##
## Declarations 
## 

my $i = 0;          ## Counter variable
my $userInput;      ## Holds user input for searches
my $searchResult;   ## Result of user search in form of %addressBook key
my @thisLine;       ## Holds current line being read from file.
my @arrayToHash;    ## Array of hash entries
my $hashKey;        ## Current hash key
my %addressBook;    ## Main hash for holding entries via other hashes.
my %firstName;      ## Hash for first names
my %lastName;       ## Hash for last names
my %phone;          ## Hash for phone numbers
my %street;         ## Hash for street addresses
my %city;           ## Hash for cities
my %state;          ## Hash for states
my %zip;            ## Hash for zip codes

##
## This section is the program's main function. 
## 

while ($thisLine = <>) {    
    $thisLine =~ s/[\r\n]//g;  ## Strips out newlines and carriage return
	@arrayToHash = split /,/, $thisLine;
##
## Convert entries to hash keys and values
##
    $hashKey = $arrayToHash[1]$arrayToHash[2];
    $hashKey =~ tr/a-z/A-Z/;
    $addressBook{$hashKey} = $arrayToHash[1] + $arrayToHash[2]
    $firstName{$hashKey} = $arrayToHash[1];
    $lastName{$hashKey} = $arrayToHash[2];
    $phone{$hashKey} = $arrayToHash[3];
    $street{$hashKey} = $arrayToHash[4];
    $city{$hashKey} = $arrayToHash[5];
    $state{$hashKey} = $arrayToHash[6];
    $zip{$hashKey} = $arrayToHash[7];

##
## Get user input and output resultant entry.
##
while ($userInput != "DONE") {
    print "Please input full or partial search string.\n
    If only one result is available, it will be printed.\n
    Otherwise, this message will appear again\n\t
        and you must refine your search.\n
    When you are finished, enter 'done'.";
    $userInput = <STDIN>;
	if ($userInput =~ /\D/) {
        $userInput =~ tr/a-z/A-Z/;
    } else {
        break;
    }
    if ($userInput == "DONE") {
        break;
    }
    $searchResult ## = search hash keys for userInput
    $~ = DISPLAY;
	write;
}
	
	
##
## Formats for formatted output
##

format DISPLAY =
Display: @>>
$searchResult
    First:   @>>
%firstName{$searchResult}
    Last:    @>>
%lastName{$searchResult}
    Phone:   @>>
%address{$searchResult}
    Street:  @>>
%street{$searchResult}
    City:    @>>
%city{$searchResult}
    State:   @>>
%state{$searchResult}
    Zip:     @>>
%zip{$searchResult}
.