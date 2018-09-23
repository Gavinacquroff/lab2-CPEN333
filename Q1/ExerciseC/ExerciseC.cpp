#include 	<stdio.h>
#include 	"..\Q1\rt.h"			// change pathlist to this header file according to where it is stored

int 	main()
{
	printf("Creating Child Processes.....\n") ;
	 
	/*Create process objects p1,p2 and p3. Arguments are as follows
	1)	Pathlist to the child process executable i.e. the runnable child program
	2)	The process priority. Allowable values are
		HIGH_PRIORITY_CLASS	
		IDLE_PRIORITY_CLASS
		NORMAL_PRIORITY_CLASS	(this is the default if you do not specify). 
		REALTIME_PRIORITY_CLASS 	(use with extreme caution)
	3)	Whether the child process uses its own window or uses that of the parent. Values are
		OWN_WINDOW or PARENT_WINDOW. Default is PARENT_WINDOW	 if not specified
	4)	The initial processing state of the process, Allowable values are
		ACTIVE or SUSPENDED. Default is ACTIVE if not specifie
*/

	CProcess p1("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\lab2-CPEN333\\Q1\\Release\\Q1Child1.exe I LIKE SOUP",	// pathlist to child program executable				
			NORMAL_PRIORITY_CLASS,			// priority
		PARENT_WINDOW,						// process has its own window					
			ACTIVE							// process is active immediately
	) ;

	CProcess p2("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\lab2-CPEN333\\Q1\\Release\\Q1Child2.exe 512 1024 2048",	// pathlist to child program executable				
			NORMAL_PRIORITY_CLASS,			// priority
		PARENT_WINDOW,						// process has its own window					
			ACTIVE							// process is active immediately
	) ;

	CProcess p3("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\lab2-CPEN333\\Q1\\Release\\Q1Child3.exe WHY?????",	// pathlist to child program executable	plus some arguments		
			NORMAL_PRIORITY_CLASS,			// priority
		PARENT_WINDOW,						// process has its own window					
			ACTIVE
	);
			
	printf("Child Processes Activated.....\n") ;

	printf("Waiting For Child1 to Terminate.....\n") ;
	p1.WaitForProcess() ;	
	
	printf("Waiting For Child2 to Terminate.....\n") ;
	p2.WaitForProcess() ;					// wait for the child process to end

	printf("Waiting For Child3 to Terminate.....\n") ;
	p3.WaitForProcess() ;					// wait for the child process to end

  	return 0 ;
	
}