CONTENTS OF THIS FILE
---------------------
* INTRODUCTION
* INSTALLATION
* DESIGN DECISIONS

INTRODUCTION
------------

Current Maintainer: scarer <s.vardy1@uq.edu.au>

JISCPM is a module that allows users to create "live" documentation for project 
management based on the JISC Project Management framework. This framework is 
particularly useful for educational projects.

When working on documents using this framework, data needed to continually be 
updated manually throughout concurrent locations (i.e. project phases, team 
members, risks etc.). This makes documentation even more tedious than it already 
is and elevates the possibility for error.

This module allows the creation of documentation with only the necessary fields 
and allows users to view linked data - i.e. users assigned to projects, risks, 
issues etc. This encourages a more agile style of working with documentation.

There is also an export function that allows basic data to be exported into 
documents that can be provided to external stakeholders.

The JISC Project Management framework is best suited to educational projects. 
For more information about the JISC Project Management Framework please 
visit: http://www.jisc.ac.uk


INSTALLATION 
------------
To install please upload this directory to your sites/all/modules directory 
in your Drupal install. 

To create projects you will need to enable the JISC PM Project module and 
the JISC PM attribute module. You will also need to install and enable the 
following dependent modules:

date_popup
date_api
ahah_helper


DESIGN DECISIONS
----------------

The data architecture of this module is based on the JISC Project Management 
templates. However, some of the fields have been re-ordered, re-named or removed 
if found to not be appropriate to the data that is required for a project based 
on field testing of the JISC Project Management templates within educational 
projects.

A system design document has also been added which is an amalgamation of a 
software specifications document and a software design document. It has been 
re-named to a system design as it may be used to detail designs for hardware 
and other types of IT systems. 
