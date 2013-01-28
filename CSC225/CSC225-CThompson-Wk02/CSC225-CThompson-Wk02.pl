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
    my $average ;  ## Used by Avg subroutine to pass back the average value
    my $sum ;  ## Used by Sum subroutine to pass back sum
    my $length = 1; ## Holds length of hash %numbers
    my $CompareResult ;    ## Used by Compare subroutine to hold >, <, or = value
    my $thisLine ;  ## Holds current line being read from file.
    my %numbers = (
        1 => 1,
    );	## Hash for holding numbers as they are read in

    
##
## This section is the program's main function. 
## 
    while ($thisLine = <>) {    
        $thisLine =~ s/[\r\n]//g ;  ## Strips out newlines and carriage return
        $numbers{$thisLine} = $thisLine ;  ## adds the contents of $thisLine to
                                       ##  %numbers
        $length++ ;
    }
	print $length ;
    &Sum(%numbers) ;    ## Calls subroutine Sum with argument %numbers.
	print $sum ;
    $average = &Avg($sum, $length) ;    ## Calls subroutine Avg with arguments $sum and $length.  Also works.
 
    $~ = "MAIN_OUTPUT" ;    ## Writes the contents of the MAIN_OUTPUT format
    write ;                 ##  definition.
 
    ##
    ## Writes the contents of the NUMBER_OUTPUT
    ##   variable for each element in @numbers.
    ##
    for($i = 0; $i < $length; $i=$i+1){
        $CompareResult = &Compare($numbers[$i], $average);
        $~ = "NUMBER_OUTPUT" ;
        write ;
    }
  
format MAIN_OUTPUT =
Number Count: @>>
$length
Number Sum:   @>>
$sum
Average:      @>>
$average
 
Number    Above/Below Average
.
 
format NUMBER_OUTPUT =
 @>           @<<<<<<
$numbers{$i}, $CompareResult
.
###############################################################################
#############  END OF MAIN  ###################################################
###############################################################################
 
 
###############################################################################
##
## Subroutine: Avg
##   variables passed:
##       $a  is the sum of the numeric values to be averaged
##       $b  is the number of numbers
##   purpose:
##       This subroutine returns the average of all numbers
##   variables returned:
##       the return value is the average of all numbers the global variable 
##       $average is updated
###############################################################################
 
sub Avg {
    my $avg;
    $avg = ($_[0] / $_[1]) ;
	return $avg;
}
 
###############################################################################
##
## Subroutine: Sum
##   variables passed:
##       @elements  The array of numbers to be added
##   purpose:
##       This subroutine returns the sum of all numbers
##   variables returned:
##       the return value is the sum of all numbers the global variable 
##       $sum is updated
###############################################################################
 
sub Sum {
    ($sum+=$_) for @_; 
}
 
###############################################################################
##
## Subroutine: Compare
##   variables passed:
##       $comparee  The number to be compared
##   purpose:
##       This subroutine returns a value "below", "average", or "above" based
##          on relation to the $average global variable
##   variables returned:
##       the return value is the relation to $average.  The global variable 
##       $CompareResult is updated
###############################################################################
 
sub Compare {
my ($val, $avg) = @_;

    if ($val < $avg){
        $result = "below" ;
    }
    elsif ($val > $avg) {
        $result = "above" ;
    }
    elsif ($val == $avg) {
        $result = "average" ;
    }
	return $result

}