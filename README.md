1. Design tasks

	1.1 purpose of design

		Through the program, teachers and users can log in to the system with the account and password to log in, enter and save the students' scores, and at the same time, realize some basic functions, conduct simple student performance management, and optimize the user experience through the improvement of the human-computer interaction interface.

	1.2 design content

	 	Requires information from both teachers and students.
	 
	 	Function of the program: view, find, input, edit, modify, delete, and sort student records, in order to ensure information security, also need to login and log out function.
	 
		Interface design: login interface, the main function interface, and the interface after entering the main functions.

2. Design Process

	2.1 Program function

		Each student record is composed of the name, student number/ID, major, class, math score, Chinese score, English score, and Average score.
	
	 	The program functions are provided as follows:		
	 
			（1） Login interface: Teachers log in to the system by entering their name, user ID, and password.
			
			（2） View all student information: display the information of all students one by one, and provide the search function.
			
			（3） Search function: find the corresponding student record according to the input name or student number. When entering the name and student number at the same time, only the student information will be displayed if the name and student number match with the corresponding record at the same time.
			
			（4） Enter the student record: Enter the student's name, student number, major, class, and three scores. The average score is automatically generated according to the average of the three scores to form a complete student record, then save the data.
			
			（5） Modify student records: use the search function to change the student records after searching the student information.
			
			（6） Delete the student record: use the search function to query the student record and delete the record.
			
			（7） Ranking of students' grades: the students' names, student numbers, and scores can be sorted through the click of a button, and the ranking order can be changed by clicking the rank button again.
			
			（8）Cancel: quit the teacher's account and return to the login interface.

	2.2 Principle of the algorithm

		(1) Search principle: According to the name or student number of the search, go through the value of this item in each data of the array, and return the number of the consistent data. If the consistent data is not found, return -1, and then display the corresponding data according to the number of the returned data. If it is -1, the data does not exist.

		(2) Sorting principle: by defining the number of flags as 1 and -1 to sort in ascending and descending order, and change the number of flags * (-1), so as to change the sorting method.

			In ascending order, define the parameter min to i, compare the item of the i-th record with the record from and after the (i + 1)-th, find the k record where the corresponding item is greater than the i-th record, min=k, and exchange the i-th record with the k record. Then do the same again  for (i + 1) (i range from 0 to n - 1). The same goes for the descending-order ordering.

	2.3 Program Flowchart
	
		<img src="flowchart.png" alt = "Flowchart">

	2.4 Main modules or functions of the program
		data structure (Objects):
  
			（1）Person: Made up of Name (string) and ID Number(string):
   
			（2） Teacher: Inherit the data of the **Person class**, and have the Password (string) data. (data storage in the " Teachers.txt" file)
   
			（3）Course: Made up of Course name (string) and Score (double), with a static variable count used to record the number of courses.
   
			（4）Student: Inherit the **Person class**, including Class (string) and Major (string), three variables of **Course class** (Mathematics, Chinese, and English), and Average Score (double). Student entries are stored in the file of the format "[teacher's name].txt".


		 Main modules:
			（1） Login: Display the login interface. After pressing the login button, the input name, user ID, and password are compared with that in the database (Teachers.txt ) to determine whether the user is allowed to enter the main function interface.
   
			（2） Home: Main function interface that provides buttons for various functions and log-off. Go into different modules by clicking the corresponding buttons.
   
			（3） Sign out: After pressing the cancel button and confirming, return to the login interface, and select "No" to stay in the Main Menu.
   
			（4） View: display the viewing interface to read the student information from the txt file corresponding to the login teacher name to enable the user	You can enter your name or student number in the dialog box and click the query function to query the corresponding students, and provide the return button and click the return	Back to the Main Menu.
   
			（5） Add Student: Display the add interface, provide the dialog box to input the students' information, and press the save button. The data is then stored in the txt file of the teacher. After pressing the continue button, the input content is cleared in the dialog box. Continue to add data and click on the return button to return to the Main Menu.
   
			（6） Edit: display the editing interface, provide the search function, and display the student information in the editable dialog box for repair. Change, after pressing the save button, store the change data in the corresponding file, and provide the return button, click and return to the Main Menu.
   
			（7） Delete Student: Display the delete interface, provide the search function, and can click after displaying the found student records. The Delete button will Delete the current record, and click on the provided return button to return to the Main Menu.
   
			（8）Sort: display the sorting interface, provides the button sorted by student number, name, and average score, and can change the drop after pressing	Order sorting mode, providing the return button to return to the Main Menu.


3. Software operation or test results
	3.1 Login interface:

		"This user does not exist" appears after entering the wrong user name.
	
		The Password Error appears after entering the wrong password.

		Show "password or ID number incorrect".

	3.2 Main function interface
	
	3.3 View function


		Enter a name to search for:
		
		Enter a different name and student number to search "No student found":
		
		After the name and student number:


	3.4 Input function

		After entering each data, click the save button and save the button to turn gray. The continue button can be used:
		
		After pressing the continue button, the chat box is cleared to continue entering data:
		
		Enter the view function to find the new student record


	3.5 Modification function
	
		Search for the name where you want to delete the record:
		
		Modify the English scores:
		
		
		The recorded English scores have changed:


	3.6 Delete the function
	
		Search for the name of the object to delete:
		
		Click the Delete button to delete this record:

	3.7 Sort function
	
		Sort them by name:
		
		Sort them by student number:
		
		Sort them by average score:

	3.8 Logging Out
	
		Select Yes and return to the login screen:


4. Some Problems encountered in the software design process and solutions

	Problem 1: Data retention, We wanted to save data so you can see it in time.
	
	Solution: Create a txt file write.
	
	
	Problem 2: unclear data storage location
	
	Solution: Make the path.h header file, then create the file directory. For example
	
		#ifndef PATH_H
		
		#define PATH H
		
		#include <string>
		
		#include <fstream>
		
		#include <direct.h>
		
		
		std::string path="c:\\学生成绩管理\\”;
		
		int makedir(){
			return _mkdir("c:\\学生成绩管理"); //创硅文件夹
		}
		
		
		std: :string getCurrentUsername(){
			std: :string currentUsername;
		 	std::ifstream file(path+"temp.txt");
		  	file>>currentUsername;
			file.close();
			return currentUsername;
		    }
		
		
		std::string getPath(){return path;}
		#endif
	
	 
	 	Need to write or read to include "path.h ”。
	
	 		#include "path.h"
	
	
	Problem 3: How to identify which teacher is logged in, and how does the system match and correspond to the teacher's personal information with the relevant data in the system.
	
	Solution: Using the temp.txt document.
	
	The access process is as follows
	
	
	Problem 4: Read the data from the file
	
	Solution: Commas are used to separate the data, create functions that process the data, and put the information into the vector
	
	
	Problem 5: Program optimization and data protection
	
	Solution: many places use the selection and loop statements to determine whether to make data access. This speeds up the software runtime and protects the data.
	
	
	Problem 6: Different functions need to use the same allStudents class v ector, it is too troublesome to pass the pointer or the value
	
	 Solution: A global allStudents class v ector is used, so that there is no transfer.
	
	 
	Problem 7: student class members, one input and output inconvenience.
	
	Solution: Overloaded the in-and-out output operators for iostream and fstream
	
	
	Problem 8: Want to know how many courses there are
	
	Solution: abstraction of the course class, add the static members of count, different hard coding
	
	
	Problem 9: Students are ordered in ascending and descending order
	
	Solution: The static variable is used
	
	
	Problem 10: Students find up
	 
	 Solution: Create the up function.
	
	
		In the process of creating the APP, we also encountered more detailed problems. Due to the complicated and complicated process, only the main problems and solutions are shown here. In addition, there are some bugs to be solved in the APP, and we will continue to study them in depth.
	


5. Brief description of the self-study content

	· Embarcadero c++ Builder, which is used to make a GUI.
	
	· How to make the file directory _mkdir().
	
	· Write and read the file fstream.
	
	· String, Headfiles, including strcmp(),.
	
	· Vector The header file and its member function e.g. front() The swap(), push_back(), pop_back(), size(), etc.
	
	·sstream And its member functions.
	
	·Overloading of the iostream and stream input and output operators
	
	·windows. And h and its member function e.g. system(), Sleep(), color()。
	
	·fmx.h


6 Summary

	With a strong interest in C + + and C language, I took the two courses, from the language and theory knowledge do not understand, do not understand to use them to code, from a simple code to understand to now can code a program alone, in this process have pain, happiness, anxiety, excitement, but I learned a lot. C + + language is a kind of compilation language compatible with C language and oriented to processes and objects. It is highly theoretical, comprehensive, and practical, involving many aspects such as ideas, methods, grammar, and algorithms of programming, which makes people find it difficult to learn. I am a cross-major student, but I want to increase my knowledge and expand my development in more aspects, so I persisted with my strong interest in C + +. In the beginning, I would be very frustrated and find it difficult, but when I wrote a small program for the first time, my happy feeling was indescribable. I made sure I paid attention to the teacher's class, and when I still didn't understand I continued to find relevant videos and documents to learn, I slowly understood the class and the problems in programming. Through this program design, I once again reviewed and got familiar with the theoretical knowledge of C++ language, especially when it came to pointers and OOP. In addition, I learned about the use of Embarcadero, learned about the interface button and function code connection, and learned about the operation and application of tags, list boxes, editing boxes, and other contents.
