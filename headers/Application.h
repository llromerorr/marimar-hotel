#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Console.h"

int Application_Menu_Main(){
	int select = 0;
	Console_Clear();
	printf("\n\t==========================================\n");
	printf("                  Sistema administrativo\n");
	printf("                       Hotel Marimar\n");
	printf("                     Facyt Computacion\n");
	printf("                           2017");
	printf("\n\t==========================================\n");
	printf("\n                      MENU PRINCIPAL\n\n");
	puts("\t[1] Reservaciones");
	puts("\t[2] Huespedes");
	puts("\t[3] Servicios Especiales");
	puts("\t[4] Salida de Huespedes");
	puts("\t[5] Reportes Mensuales");
	printf("\t[6] Salir\n\n");
	printf("\tOpcion: ");
	
	Console_Input_Int(&select);
	if(select > -1 && select < 7)
		return select;
	else
		return 0;
}

void Application_Pause(){
	printf("\n\t[PRESIONE ENTER PARA CONTINUAR...]");
	while(getchar()!= '\n');
}

void Application_Exit(){
	char letter;
	printf("\n\tEsta seguro que desea salir? [S/N]: ");
    letter = getc(stdin);
    while(getchar()!='\n');
    if(letter == 's' || letter == 'S'){
		Console_Clear();
		exit(0);
	}
}

void Application_Message_EmptyProcess(){
	printf("\n\t**Empty Process**");
	Application_Pause();
}

void Application_Message_Error(){
	printf("\n\t**ERROR 400:34_2f**");
	Application_Pause();
}

#endif /* APPLICATION_H */