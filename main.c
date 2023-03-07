/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <windows.h>

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/
int Threadcount = 3;

int arr[30];
int length;  

DWORD WINAPI Average()
{ //Function that sums user input, and then divides by length of user input to obtain average
	int sum;  
	for(int i = 0; i < length; i++)
		{
		sum += arr[i]; 
		}
	float avg = (float)sum/(float)length;
	 
	printf("The average is %f \n", avg); 

	return 0;//returns for position in threads array
}

DWORD WINAPI Minimum()
{//Function that finds the minimum value of input by comparing each value with current smallest
	int min = arr[0];
	for(int i = 0; i < length; i++)
	{
		if(min > arr[i])
		{
			min = arr[i];
		}
	}
	printf("The minimum is %d \n", min);
	return 1;  
}

DWORD WINAPI Maximum()
	{//Function that finds maximum value of input by comparing each value with current larges
	int max = arr[0];
	for(int i = 0; i < length; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("The maximum is %d \n", max);
	return 2;  
}


int main(int argc, char *argv[])//main function populates array with user input and creates threads 
{ 
 
 	int b;
	printf("How many values would you like to insert? "); 
	scanf("%d", &length);  

	for(int i = 0; i < length; i ++)
		{
		printf("please type a number: "); 
		scanf("%d", &b);
		arr[i] = b; 
		}
	HANDLE Thread[Threadcount];
	DWORD ThreadID;

	Thread[0] = CreateThread(NULL, 0, Average, NULL, 0, &ThreadID);
	Thread[1] =  CreateThread(NULL, 0, Minimum, NULL, 0, &ThreadID);
	Thread[2] = CreateThread(NULL, 0, Maximum, NULL, 0, &ThreadID);
	
	WaitForMultipleObjects(Threadcount, Thread, TRUE, INFINITE); //waits for all threads to activate
	for(int i = 0; i < Threadcount; i++){
		CloseHandle(Thread[i]);

}
	
	





}

