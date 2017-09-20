#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Console_Input_Int(int* var){
	char 	input[12];
	char*	point;

	fgets(input, 12, stdin);
	point = strchr(input, '\n');

	if(point == NULL) while(getchar()!= '\n');
	*var = atoi(input);
}

void Console_Clear(){
    system("cls");
}

void Console_Pause(){
	printf("\t");
	while(getchar()!= '\n');
}

#endif /* CONSOLE_H */