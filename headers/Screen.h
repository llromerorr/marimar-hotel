#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void ScreenResource_DivitionBar(int Width, int Index, int JumpLine);
void ScreenResource_DivitionBar_Double(int Width, int Index, int JumpLine);


void ScreenResource_DivitionBar(int Width, int Index, int JumpLine){
	for(int i = 0; i < Index; i++)
		printf("\t");

	for(int i = 0; i < Width; i++)
		printf("-");

	for(int i = 0; i < JumpLine; i++)
		printf("\n");
}

void ScreenResource_DivitionBar_Double(int Width, int Index, int JumpLine){
	for(int i = 0; i < Index; i++)
		printf("\t");

	for(int i = 0; i < Width; i++)
		printf("=");

	for(int i = 0; i < JumpLine; i++)
		printf("\n");
}
#endif /* SCREEN_H */