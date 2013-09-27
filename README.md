Bandwidth Fulfillment Simulator
===============================

This simulator assumes that there is a 1 Mbps link that grants users a 100 Kbps
connection when they are active. The service has 35 subscribers with only 10%
being active (on average) at one time. This simulator will calculate the
probability that more than 10 users will attempt to utilize the service at one
time and thus experience connection issues.

Configuration
-------------
User must have a compiler supporting C99 functionality in order to run this
program. This program makes use of the long long number which is a 64-bit
integer data type supported by C99.

Installation
------------
Compile and run the code with the supplied Makefile.

Operation
---------


File Manifest
-------------
<dl>
  <dt>LICENSE.md</dt>
  <dd>BSD 2-Clause license information</dd>
  <dt>.gitignore</dt>
  <dd>Based off the Github default C .gitignore file with my binary locations
  added as well.</dd>
  <dt>factorial.h</dt>
  <dd>Header file for partial factorial functionality.</dd>
  <dt>factorial.c</dt>
  <dd>Source file for partial factorial functionality.</dd>
  <dt>combinations.h</dt>
  <dd>Header file for combinations (nCk) functionality.</dd>
  <dt>combinations.c</dt>
  <dd>Source file for combinations (nCk) functionality.</dd>
  <dt>factorial_test.c</dt>
  <dd>A C99 program to test that partial factorials are being calculated
  correctly in a limited number of scenarios.</dd>
  <dt>combinations_test.c</dt>
  <dd>A C99 program to test that combinations (nCk) are being calculated
  correctly in a limited number of scenarios.</dd>
</dl>



Copyright & License
-------------------
Refer to LICENSE.md for all pertenant licensing information.

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


Changelog
---------
<dl>
  <dt>v0.0.2</dt>
  <dd>Added partial factorial functionality.</dd>
  <dd>Added combination (nCk) functionality.</dd>
  <dd>Added C99 requirement to configuration because of “unsigned long long”
  functionality.</dd>
  <dt>v0.0.1</dt>
  <dd>Initial README file. Mostly filled out, will be added to as I complete
  the project.</dd>
  <dd>Initial LICENSE file. Completed and finalized.</dd>
  <dd>Inital .gitignore file added.</dd>
</dl>
