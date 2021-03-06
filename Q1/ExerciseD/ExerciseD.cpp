#include <stdio.h>
#include "..\Q1\rt.h"


UINT __stdcall ChildThread(void *args)	// A thread function 
{
	const char *threadData = *(const char **)(args);

	for (int i = 0; i < 10000; i++)
		printf("I am a child thread. My first words are: %s \n", threadData);

	return 0;
}

int main() {
	CThread *Threads[4];
	const char *data[4] = { "who", "reads", "this", "anyways" };

	for (int i = 0; i < 4; i++) {
		Threads[i] = new CThread(ChildThread, SUSPENDED, &data[i]);
	}

	printf("Children have spawned...");
	Sleep(500);

	for (int i = 0; i < 4; i++) {
		Threads[i]->Resume();
	}

	for (int j = 1; j < 5; j++) {
		Threads[j]->WaitForThread();
		printf("Child %d has perished\n", j);
		delete Threads[j];
	}
}