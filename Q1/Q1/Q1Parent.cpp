#include 	<stdio.h>
#include 	"rt.h"			// change pathlist to this header file according to where it is stored

int 	main()
{
	//printf("Creating Child Processes.....\n") ;
	 
//	Create process objects p1,p2 and p3. Arguments are as follows
//	1)	Pathlist to the child process executable i.e. the runnable child program
//	2)	The process priority. Allowable values are
//		HIGH_PRIORITY_CLASS	
//		IDLE_PRIORITY_CLASS
//		NORMAL_PRIORITY_CLASS	(this is the default if you do not specify). 
//		REALTIME_PRIORITY_CLASS 	(use with extreme caution)
//	3)	Whether the child process uses its own window or uses that of the parent. Values are
//		OWN_WINDOW or PARENT_WINDOW. Default is PARENT_WINDOW	 if not specified
//	4)	The initial processing state of the process, Allowable values are
//		ACTIVE or SUSPENDED. Default is ACTIVE if not specifie


	//CProcess p1("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\Q1\\Release\\Q1Child1.exe",	// pathlist to child program executable				
	//		NORMAL_PRIORITY_CLASS,			// priority
	//		OWN_WINDOW,						// process has its own window					
	//		ACTIVE							// process is active immediately
	//) ;


	//CProcess p2("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\Q1\\Release\\Q1Child2.exe",	// pathlist to child program executable				
	//		NORMAL_PRIORITY_CLASS,			// priority
	//		OWN_WINDOW,						// process has its own window					
	//		ACTIVE							// process is active immediately
	//) ;

	//CProcess p3("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\Q1\\Release\\Q1Child3.exe",	// pathlist to child program executable	plus some arguments		
	//		NORMAL_PRIORITY_CLASS,			// priority
	//		OWN_WINDOW,						// process has its own window					
	//		ACTIVE
	//);
	//		
	//printf("Child Processes Activated.....\n") ;

	//printf("Waiting For Child1 to Terminate.....\n") ;
	//p1.WaitForProcess() ;	
	//
	//printf("Waiting For Child2 to Terminate.....\n") ;
	//p2.WaitForProcess() ;					// wait for the child process to end

	//printf("Waiting For Child3 to Terminate.....\n") ;
	//p3.WaitForProcess() ;					// wait for the child process to end

 // 	return 0 ;
	
	UINT flags = NORMAL_PRIORITY_CLASS;
	flags |= CREATE_NEW_CONSOLE;

	const string Name1 = "ChildProcess1";
	PROCESS_INFORMATION p1Info;

	const string Name2 = "ChildProcess2";
	PROCESS_INFORMATION p2Info;

	const string Name3 = "ChildProcess3";
	PROCESS_INFORMATION p3Info;

	printf("Creating Child Processes.....\n");

	STARTUPINFO	StartupInfo1 = {sizeof(STARTUPINFO), NULL, NULL, (char *)(Name1.c_str()), 0,0,0,0,0,0,0,0,0,0,NULL,0,0,0};
	if (!CreateProcess("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\Q1\\Release\\Q1Child1.exe",(char *)(Name1.c_str()),NULL,NULL,TRUE,flags,NULL,NULL,&StartupInfo1,&p1Info))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 0;
	}

	STARTUPINFO	StartupInfo2 = { sizeof(STARTUPINFO), NULL, NULL, (char *)(Name2.c_str()), 0,0,0,0,0,0,0,0,0,0,NULL,0,0,0 };
	if (!CreateProcess("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\Q1\\Release\\Q1Child1.exe", (char *)(Name2.c_str()), NULL, NULL, TRUE, flags, NULL, NULL, &StartupInfo2, &p2Info))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 0;
	}

	STARTUPINFO	StartupInfo3 = { sizeof(STARTUPINFO), NULL, NULL, (char *)(Name3.c_str()), 0,0,0,0,0,0,0,0,0,0,NULL,0,0,0 };
	if (!CreateProcess("C:\\Users\\Gavin\\Documents\\UBC 2018-19\\CPEN 333\\lab 2\\code\\Q1\\Release\\Q1Child1.exe", (char *)(Name3.c_str()), NULL, NULL, TRUE, flags, NULL, NULL, &StartupInfo3, &p3Info))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 0;
	}

	printf("Child Processes Activated.....\n");
	
	printf("Waiting For Child1 to Terminate.....\n");
	
	DWORD waitresult1	= WaitForSingleObject(p1Info.hThread, 0x000000FF);

	printf("wait result 1 = %08x\n", waitresult1);

	printf("Waiting For Child2 to Terminate.....\n");
	DWORD waitresult2 = WaitForSingleObject(p2Info.hThread, 0xFFFFFFFF);

	printf("wait result 2 = %08x\n", waitresult2);

	printf("Waiting For Child3 to Terminate.....\n");
	DWORD waitresult3 = WaitForSingleObject(p3Info.hThread, 0xFFFFFFFF);

	printf("wait result 3 = %08x\n", waitresult3);
}