#include 	<stdio.h>
#include "..\Q1\rt.h"

//int main() {
int main(int argc, char *argv[])
{
	/*int i ;
	for( i = 0; i < 200; i ++) {
		printf("Hello from child process 1....\n") ;
		Sleep(50);
	}*/

	printf("argc count = %d\n", argc);

	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);

	}
}