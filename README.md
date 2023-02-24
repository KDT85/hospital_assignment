MODULE: AI AND CHAT BOTS (COMP40010) 
ASSIGNMENT: C++ Programming
DEADLINE: Monday 8
th May 2023 11:59pm
DEMONSTRATION: The Week Commencing 8th May 2023

1 Introduction
1.1 This document forms the specification for your coursework in this module. This coursework will address and assess Learning Outcomes 1 
to 2 as indicated in the Module Handbook.

2 Specific Requirements
2.1 This coursework is weighted at 60% of the overall module mark. The weighting of the report is 20% and the associated practical element 
is weighted at 80%.
2.2 The report should be structured in accordance with the sections outlined in the Report Requirements and Assessment Scheme below 
(see Section 3 and Section 4). 
2.3 You must use Harvard referencing.
2.4 This coursework should be completed and submitted as an individual piece of work. In other words, it is not group work. You should be 
aware of the rules on academic misconduct. These rules are very clear. To read please click here. The faculty takes a strict line in 
enforcing them.
2.5 You are also required to demonstrate the practical element of the project. This should include a demonstration of the results obtained 
from the practical application. The demonstration would be online and each student has a specific time slot that will be released before 
the above deadline.
2.6 The demonstration will be largely practical with the candidate demonstrating the various stages they performed and employed during 
the project.

3 Assignment Architecture
3.1 Scenario and specifications 
The final project of this module is hospital management system using object-oriented programming. You can see the description of the 
project below. In addition, an execute file of the program is attached to this assignment. You can download it from Blackboard and run it 
to get more acquainted with the program's functionality.

General description
• This program will run in console environment. It will display a main menu showing different options letting the user to choose from 
different sections such as:
o Patient management, 
o Personnel management, 
o Hospital information, and 
o Settings.

This system manages information about two types of people: Patients and Personnel. Information related to each group is managed 
separately by patient management and personnel management section respectively
• The patient management will open a new menu giving following options to the user:
▪ Add: Adds a new patient to the patient list. This information includes: Id, Name, Gender, Illness, Admission date, and 
Address)
▪ Update: Takes the patient name and edits other information.
▪ Delete: Takes the patient name and removes it from the patient list.
▪ Display All Patients: Displays all available patients.
▪ Back to Main Menu: Returns to the main menu.
• The Personnel management will also open a new menu giving following options to the user:
▪ Add: A new person is added to the personnel list. This information includes: (Id, Name, Gender, Address, Staff Post, 
and Staff expertise) 
▪ Update: Takes the personnel name and edits other information.
▪ Delete: Takes the personnel name and removes it from the patient list.
▪ Display All Personnel: Displays all available personnel.
▪ Back to Main Menu: Returns to the main menu.
• Setting is a password protected option and is only accessible by the admin user who has the password to enter this section. Here a 
menu is shown to the user where the admin user can set the hospital information.
▪ Set hospital Info: Sets hospital information. This include Hospital name and address, and Name of the manager. All of 
this information is stored in Hospital file.
▪ Back to Main Menu: Returns to the main menu.
• Hospital info: reads information from the Hospital file and displays it on the screen.

3.2 The Files 
This system will use 4 different files:
• Hospital file: It contains the hospital information which are, Hospital name, Hospital admin name, Hospital address
• Patient file: It contains patients’ information which are Id, Name, Gender, Age, Address, Illness, and Admission date
• Personnel file: It contains personnel information which are Id, Name, Gender, Age, Address, Staff post, and Staff expertise 
• Password file: It is an encrypted file holding the password of the admin

3.3 Data structure
You may use two lists for saving patient (pList) and personnel information (staffList) in main memory.

3.4 Program demo
You may run the sample program EXE file to see how the program might work. You may choose different style as long as you provide all the functionality.

3.5 Class diagram
This program includes following classes:
Hospital class
-pList: Patient
-staffList: Personel
+add()
+save()
+read()
+update()
+remove()
+main_menu()
+patientManagement()
+personnelManagement()
+setting()
+displayInfo()
+infoSet()
+initialize()
Menu class
-data: string
-size: int
+Menu(string [], int)
+Menu(string , int )
+show(string )
+choice():int
int id;

Figure 1. Class Diagram of Our Project. 
Person class
+name: string
+gender: char
+age: int
+address: string
+ Person(const Person& )
+Person(int id, string name, char gender, int age, string address)
+print()
Figure 2. Class Diagram of Our Project. Cont…
Personnel class
+ staff_post: string 
+ staff_expertise: string
+ Personnel():
+ Personnel(int id, string name, char gender, int age, string 
address, string staff_post , string staff_expertise )
+ Personnel (const Personnel &p)
+ print()
Patient class
+ illness: string
+ admission_date: string
+ Patient():
+ Patient(int id, string name, char gender, int age, string 
address, string illness, string admission_date)
+ Patient(const Patient &p)
+ print()

4 Assignment Requirement
Based on the problem specification you need to write an object-oriented program to implement the classes and run and debug the program.
This includes:
▪ Writing tasks 1-7
▪ Writing extra functionalities
▪ Demonstration
▪ Report

The draft code for this project is attached to this document. You need to complete the code by completing the following tasks:
4.1 Task 01:
Implement the classes according to the class diagram
4.2 Task 02:
Write the read and display function. There are two different copies of these functions:
add(Patient p) // reads data for a new patient from keyboard and stores them first at patient list (pList) and then stores them in Patient file. 
display(Patient p) // displays data of all patients which has been stored in patient list (pList)
Note:
You may write a separate function called save to store information of pList into the file. 
add(Personnel p) // reads data for a new personnel from keyboard and stores them first at staff list (staffList) and then stores them in Personnel file. 
display(Personnel p) // displays data of all personnel which has been stored in staff list (staffList)
Note:
You may write a separate function called save to store information of staffList into the personnel file.

4.3 Task 03:
Write the ourinfoset function to set the hospital Info by reading Hospital name and address, and also Name of the manager and storing them in 
Hospital file.
Write the displayinfo function to read information from the Hospital file and displays it on the screen. 
4.4 Task 04:
Write the update function. There are two different copies of this function:
update(Patient p) // reads data for a patient which already exists from keyboard and stores them first at patient list (pList) and then stores them in Patient 
file. 
Note:
Use function save() to store information of pList into the file. 
add(Personnel p) // reads data for an existing personnel from keyboard and stores them first at staff list (staffList) and then stores them in Personnel file. 
Note:
use function save() to store information of staffList into the personnel file.
4.5 Task 05:
Write the remove function. There are two different copies of this function:
remove(Patient p) // reads id of an existing patient and first deletes it from patient list (pList) and then stores new list them in Patient file. 
Note:
Use function save() to store information of pList into the file. 
remove (Personnel p) // reads id of an existing personnel and first deletes it from staff list (staffList) and then stores new list in Personnel file. 
Note:
Use function save() to store information of staffList into the personnel file.

4.6 Task 06:
Write the save function. There are two different copies of this function:
save(Patient p) // Stores information of pList into the file.
4.7 Task 07:
In this task you need to add some new features and innovations to the program. Based on the weight of the work you have done; you will be awarded 
points for this part. You get the maximum points when your innovation has an object-oriented aspect in addition to other innovation aspect. For example:
• Error handling when dealing with input from user or from files
• Efficient code in terms of speed and code length
• OOP: use of inheritance, polymorphism
• Implementing Update(string name) to update information of patient/personnel based on name instead of id

Further guidance would be given in both tutorials and the class.

5 Criteria of Assignment
5.1 In the programming part of the project you need to implement the task 01 to task 07 as listed in the Section 4.
5.2 The demonstration part of the project should include the following
• A review of any key results from the initial investigation
• A review of the code and testing process 
• An overview of the results of your program 
5.3 The report part of the assignment should include the following:
A clear description of the work you have done in each separate task followed by the snapshot of the code and the snapshot of its output. Your 
report should have an academic style. A guideline for academic style reports can be found here.

6 Assessment Scheme 
Task 0-39 (Fail) 40-49 (3rd) 50-59 (2:2) 60-69 (2:1) 70-100 (1st)
Task 01
10 out 
No program or work not done
Program does not compile due to 
errors (which could not be easily 
determined)
Program may not compile due to 
errors or run smoothly when 
executed
Program compile but with errors Program compiles with no errors 
but does not run smoothly
Program compiles with no errors 
Runs smoothly when executed
Task 02 No program or work not done
Program does not compile due to 
errors (which could not be easily 
determined)
Program may not compile due to 
errors or run smoothly when 
executed
Program compile but with errors Program compiles with no errors 
but does not run smoothly
Program compiles with no errors 
Runs smoothly when executed
Task 03 No program or work not done
Program does not compile due to 
errors (which could not be easily 
determined)
Program may not compile due to 
errors or run smoothly when 
executed
Program compile but with errors Program compiles with no errors 
but does not run smoothly
Program compiles with no errors 
Runs smoothly when executed
Task 04 No program or work not done
Program does not compile due to 
errors (which could not be easily 
determined)
Program may not compile due to 
errors or run smoothly when 
executed
Program compile but with errors Program compiles with no errors 
but does not run smoothly
Program compiles with no errors 
Runs smoothly when executed
Task 05 No program or work not done
Program does not compile due to 
errors (which could not be easily 
determined)
Program may not compile due to 
errors or run smoothly when 
executed
Program compile but with errors Program compiles with no errors 
but does not run smoothly
Program compiles with no errors 
Runs smoothly when executed
Task 06 No program or work not done
Program does not compile due to 
errors (which could not be easily 
determined)
Program may not compile due to 
errors or run smoothly when 
executed
Program compile but with errors Program compiles with no errors 
but does not run smoothly 
Program compiles with no errors 
Runs smoothly when executed
Task 07 No work not done • Add appearance features to 
the program such as 
improving user friendly 
environment of the 
program.
• Add appearance features to the 
program such as improving user 
friendly environment of the 
program.
• Improving the current file 
storage structure 
• Adding creativity to the 
reporting system
• Add appearance features to 
the program such as 
improving user friendly 
environment of the program.
• Improving the current file 
storage structure 
• Adding creativity to the 
reporting system. 
• Add appearance features to 
the program such as 
improving user friendly 
environment of the 
program.
• Improving the current file 
storage structure 
• Adding creativity to the 
reporting system. 
Page 12 of 13
• Adding the above feature by 
applying object-oriented 
methods
• Adding the above feature by 
applying object-oriented 
methods.
• Adding super-objectoriented creativity to the 
program and ability to prove 
it.
Demonstrate Not able to answer any question 
posed
Not able to explain the code
No understanding or idea of 
object-oriented concepts
Not able to answer most 
questions indicating poor 
understanding of the work done
Not able to explain nor modify 
code upon request
Has hardly any understanding or 
idea of object-oriented concepts
Able to answer some questions 
indicating some understanding of the 
work done
Able to explain but not able to modify 
code upon request
Hardly able to explain object-oriented 
concepts
Able to answer most questions well 
indicating some clear 
understanding of the work done
Able to explain and modify some 
code upon request
Able to explain some objectoriented concepts incorporated
Able to answer all questions 
posed accurately indicating clear 
understanding of the work done
Able to explain and modify code 
upon request
Able to explain all object-oriented 
concepts incorporated
Report • Documentation not done
• Content of documentation 
does not adhere to any of 
the requirements stipulated 
in the assignment 
requirements
• Screen capture of the 
output of the program does 
not have any explanation to 
describe the program
• Some missing / poor 
documentation standards 
such as table of contents, 
referencing, page 
numbering, captioning, 
poor command of the 
language. Referencing done 
does not adhere to 
Harvard’s Name 
Referencing style.
• programming concept that are 
applied in the solution with 
some evidence of the 
implementation code is 
included.
• Screen capture of the output of 
the program with minimal 
explanation to describe the 
program
• Overall average documentation
standards in table of contents, 
referencing, page numbering, 
captioning, command of the 
language, etc.
• Screen capture of the output 
of the program with some 
explanation to describe the 
program
• Description and evidence of 
at least 1 additional feature 
which has been incorporated 
in the solution
• Good documentation 
standards in most areas such 
as table of contents, 
referencing, page numbering, 
captioning, command of 
language.
• Screen capture of the output 
of the program with 
appropriate explanation to 
sufficiently describe the 
program
• Description and evidence of 
at least 2 additional features 
which have been 
incorporated in the solution
• Excellent documentation 
standards. Overall 
documentation has a 
professional outlook
Page 13 of 13
7 Submission Guidelines
7.1 The primary method of submission is via Blackboard. 
7.2 You should submit a PDF copy of your report alongside with your codes by the submission deadline.
7.3 You need to put the source of your program in an appendix in your report. The mark of the assignment without source code is equal to ‘0’. Therefore,
please note that in addition to submit your program you need to put all sections of your codes in your report as an appendix.
7.4 Your report should have an academic style (for more information refer to: https://grammar.yourdictionary.com/style-and-usage/report-writingformat.html ). To explain each part, you need to take a snapshot of related code and its output and use in your report and discuss on them.
7.5 If necessary, you may be asked to submit via another secondary method – such as email attachment. In this case your Tutor will inform you
accordingly.
7.6 PDF documents should not be password protected or have restricted permissions – specifically, they should allow modifications (for annotations and 
comments). 
7.7 You are advised to keep copies of all your work for your own records.
