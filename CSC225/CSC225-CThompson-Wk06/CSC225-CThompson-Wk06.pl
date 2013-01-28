#!/usr/bin/perl
###############################################################################
##  Caleb  Thompson   CalThomp@uat.edu
##  Date of initial creation: 2009-09-19
##  Date of last edit: 2009-09-26
## 
##  Descript:  This script is designed to install the Module::CoreList
##             module from CPAN.  It will then print a list of all modules that
##             come with Pel 5.008.
###############################################################################

use strict; 
use Module::CoreList;

my %modules = %{ $Module::CoreList::version{5.008} };

print @modules;

###############################################################################
#############  END OF MAIN  ###################################################
###############################################################################
 