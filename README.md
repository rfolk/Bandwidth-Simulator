Bandwidth Fulfillment Simulator
===============================

This simulator assumes that there is a 1 Mbps link that grants users a 100 Kbps
connection when they are active. The service has 35 subscribers with only 10%
being active (on average) at one time. This simulator will calculate the
probability that more than 10 users will attempt to utilize the service at one
time and thus experience connection issues.

Configuration
-------------
User must have a compiler supporting C11 functionality in order to run this
program.
From the directory of the installation run the command 'make'.
To remove temporary object files run the command 'make clean'.
To remove all executable files run the command 'make remove'.

Installation
------------
Compile and run the code with the supplied Makefile.
In the base directory, type make. The executable will be located in the bin
directory.
In order to compile the source, the following directories should be present in
the root directory:
* bin/
* docs/
* include/
* obj/
* src/
* test/

Operation
---------
This program is made to be run from the command line. Initialization flags are
used to calculate the required variables but if they are not provided at
initialization the program will requisition the missing values. The following
flags are used.
<dl>
  <dt>-b_</dt>
  <dd>integer</dd>
  <dd>The total amount of bandwidth available to the connection.</dd>
  <dt>-r_</dt>
  <dd>integer</dd>
  <dd>The amount of bandwidth required by an active user.</dd>
  <dt>-n_</dt>
  <dd>positive integer &#x3C;= 100</dd>
  <dd>The total number of subscribers to the service.</dd>
  <dt>-x_</dt>
  <dd>positive integer &#x3C;= n</dd>
  <dd>The number of active users utilizing the connection.</dd>
  <dt>-p_</dt>
  <dd>double floating point precision 0 &#x3C; p &#x3C; 1</dd>
  <dd>The probability that a user is active.</dd>
</dl>

File Manifest
-------------
<dl>
  <dt>Makefile</dt>
  <dd>GNU Makefile for completely configured compilation.</dd>
  <dt>README.md</dt>
  <dd>Basic documentation file.</dd>
  <dt>bin/</dt>
  <dd>Stores compiled executable files.</dd>
  <dt>docs/LICENSE.md</dt>
  <dd>BSD 2-Clause license information</dd>
  <dt>include/binomial_probability.h</dt>
  <dd>Header file for binomial probability functionality.</dd>
  <dt>include/combinations.h</dt>
  <dd>Header file for combinations (nCx) functionality.</dd>
  <dt>include/factorial.h</dt>
  <dd>Header file for partial factorial functionality.</dd>
  <dt>include/main.h</dt>
  <dd>Header file for main functionality.</dd>
  <dt>obj/</dt>
  <dd>Stores copies of the compiled object files for linking to create the
    simulator program. These files may be removed after compilation is
    completed.</dd>
  <dt>src/binomial_probability.c</dt>
  <dd>Source file that provides the user with the ability to calculate the
    probability of a Binomial series when supplied with a determined n &#x3C;= 100,
    x &#x3C;= n, and 0 &#x3C; p &#x3C; 1.
  <dt>src/combinations.c</dt>
  <dd>Source file that provides the user with the ability to calculate the
    combination n Choose x (nCx).</dd>
  <dt>src/factorial.c</dt>
  <dd>Source file that provides the user with the ability to calculate a
    classic or partial factorials of a given start to end range.</dd>
  <dt>test/binomial_probability_test.c</dt>
  <dd>A C11 program to test a limited number of cases for binomial probability
    functionality and see that they are being calculated correctly. Values are
    checked against the results on Wolfram Alpha.</dd>
  <dt>test_combinations_test.c</dt>
  <dd>A C11 program to test a limited number of cases for combinations (nCx)
    and see that they are being calculated correctly. Values are checked
    against the results on Wolfram Alpha.</dd>
  <dt>test/test_factorial_test.c</dt>
  <dd>A C11 program to test a limited number of cases for partial and
    traditional factorials and see that they are being calculated correctly.
    Values are checked against the results on Wolfram Alpha.</dd>
</dl>

Copyright & License
-------------------
Refer to LICENSE.md for all pertinent licensing information.

Contact Information
-------------------
Russell Folk  
rfolk@nmsu.edu  
C S 484 – Fall 2013

Known Bugs
----------
None.

Troubleshooting
---------------


Credits & Acknowledgments
-------------------------
Dr. Satyajayant ‘Jay’ Misra for the challenge of building the program.
Dr Pepper for providing the caffeine needed to keep me going.

Changelog
---------
<dl>
  <dt>v1.0.0</dt>
  <dd>Fully functional program, complete with all the requested features.</dd>
  <dd>Changed the requirements to C11, up from C99.</dd>
  <dd>Implementing only standard data types.</dd>
  <dt>v0.0.2</dt>
  <dd>Added partial factorial functionality.</dd>
  <dd>Added combination (nCx) functionality.</dd>
  <dd>Added C99 requirement to configuration because of “unsigned long long”
  functionality.</dd>
  <dt>v0.0.1</dt>
  <dd>Initial README file. Mostly filled out, will be added to as I complete
  the project.</dd>
  <dd>Initial LICENSE file. Completed and finalized.</dd>
  <dd>Initial .gitignore file added.</dd>
</dl>
