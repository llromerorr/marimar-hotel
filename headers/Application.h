#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Console.h"
#include "Reservation.h"

//----------------------FUNCTIONS------------------------

void Application_Pause(){
	printf("\n\t[PRESIONE ENTER PARA CONTINUAR...]");
	while(getchar()!= '\n');
}

void Application_Exit(){
	while(1){
		Console_Clear();
		char letter;
		printf("\n\t==========================================");
		printf("\n\t   Sistema Administrativo Hotel Marimar");
		printf("\n\t==========================================\n");
		printf("\n\tEsta a punto de salir del sistema, los");
		printf("\n\tcambios no guadados se perderan.\n\n");
		printf("\n\tEsta seguro que desea salir? [S/N]: ");
		letter = getc(stdin);
		while(getchar()!='\n');
		if(letter == 's' || letter == 'S'){
			Console_Clear();
			exit(0);
		}
		else if(letter == 'n' || letter == 'N')
			break;
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

//-----------------------MENUS-----------------------

int Application_Menu_Reservation_New(int CI){	
	char Name[30];
    char LastName[30];
    Time Input;
    Time Output;
    int Number;
	char PayType[30];

	Console_Clear();
	printf("\n\t==========================================");
	printf("\n\t   Sistema Administrativo Hotel Marimar");
	printf("\n\t==========================================\n");
	printf("\n\t           NUEVA RESERVACION\n\n");
	printf("\tEl cliente portador de la CI %d no\n", CI);
	printf("\tposee ninguna reservacion, se procedera a\n");
	printf("\tsu creacion, para abortar escriba \"0\".\n\n");
	printf("\tNombre y Apellido: ");
	scanf("%s", Name);
	if(strcmp(Name, "0") == 0)
		return 0;
	scanf("%s",LastName);
	printf("\tFecha Inicio (dia/mes/ano): ");
	scanf("%d/%d/%d", &Input.Day, &Input.Month, &Input.Year);
	printf("\tFecha Salida (dia/mes/ano): ");
	scanf("%d/%d/%d", &Output.Day, &Output.Month, &Output.Year);
	printf("\tNumero Habitacion: ");
	scanf("%d", &Number);
	printf("\tTipo de pago: ");
	scanf("%s", PayType);
	Reservation_New(Name, LastName, CI, Input, Output, Number, PayType);
	Reservation_File_Save();
	Console_Pause();
	return 0;
}

int Application_Menu_Reservation_Edit(Reservation * Pointer){
	char Name[30];
	char LastName[30];
	int CI;
	Time Input;
	Time Output;
	int Number;
	char PayType[30];

	while(1){
		int Selection = 0;
		Console_Clear();
		printf("\n\t==========================================");
		printf("\n\t   Sistema Administrativo Hotel Marimar");
		printf("\n\t==========================================\n");
		printf("\n\t           MODIFICAR RESERVACION\n\n");
	
		printf("\tNombre Completo:\t%s %s\n",Pointer->Name,Pointer->LastName);
		printf("\tCI:\t\t\t%d\n", Pointer->CI);
		printf("\tFecha Inicio:\t\t%s\n", Time_ToString(Pointer->Input));
		printf("\tFecha Salida:\t\t%s\n",Time_ToString(Pointer->Output));
		printf("\tHabitacion:\t\t%d\n", Pointer->Number);
		printf("\tTipo de pago:\t\t%s\n", Pointer->PayType);
		printf("\n\t------------------------------------------\n\n");

		puts("\t[1] Cambiar Nombre");
		puts("\t[2] Cambiar Apellido");
		puts("\t[3] Cambiar CI");
		puts("\t[4] Cambiar Fecha Inicio");
		puts("\t[5] Cambiar Fecha Salida");
		puts("\t[6] Cambiar N. Habitacion");
		puts("\t[7] Cambiar Tipo de Pago");
		puts("\t[8] GUARDAR CAMBIOS");
		printf("\t[9] SALIR\n\n");
		printf("\tOpcion: ");

		Console_Input_Int(&Selection);
		switch(Selection){
			case 1:
				printf("\tNombre: ");
				scanf("%s", Name);
				Reservation_Set_Name(Pointer, Name);
				break;
			case 2:
				printf("\tApellido: ");
				scanf("%s", LastName);
				Reservation_Set_LastName(Pointer, LastName);
				break;
			case 3:
				printf("\tCI: ");
				Console_Input_Int(&CI);
				Reservation_Set_CI(Pointer, CI);
				break;
			case 4:
				printf("\tFecha Inicio (dia/mes/ano): ");
				scanf("%d/%d/%d", &Input.Day, &Input.Month, &Input.Year);
				Reservation_Set_TimeInput(Pointer, Input);
				break;
			case 5:
				printf("\tFecha Salida (dia/mes/ano): ");
				scanf("%d/%d/%d", &Output.Day, &Output.Month, &Output.Year);
				Reservation_Set_TimeOutput(Pointer, Output);
				break;
			case 6:
				printf("\tNumero Habitacion: ");
				Console_Input_Int(&Number);
				Reservation_Set_Number(Pointer, Number);
				break;
			case 7:
				printf("\tTipo de Pago: ");
				scanf("%s", PayType);
				Reservation_Set_PayType(Pointer, PayType);
				break;
			case 8:
				Reservation_File_Save();
				printf("\n\tCAMBIOS GUARDADOS EXITOSAMENTE!\n");
				Console_Pause();
			case 9:
				return 0;
		}
	}
	return 0;
}

int Application_Menu_Reservation(){
	while(1){
		Reservation_File_Load();
		int Selection = 0;
		Console_Clear();
		printf("\n\t==========================================");
		printf("\n\t   Sistema Administrativo Hotel Marimar");
		printf("\n\t==========================================\n");
		printf("\n\t            BUSCAR RESERVACION\n\n");
		puts("\tIntruduzca la CI del cliente");
		puts("\t[1] Mostrar Reservaciones");
		puts("\t[9] Volver\n");
		printf("\tCI -> ");
		
		Console_Input_Int(&Selection);
		switch(Selection){
			case 0:
				puts("\n\tNumero de CI no valido...");
				break;
			case 1:
				Console_Clear();
				printf("\n\t==========================================");
				printf("\n\t   Sistema Administrativo Hotel Marimar");
				printf("\n\t==========================================\n");
				printf("\n\t        RESERVACIONES REGISTRADAS\n\n");
				printf("\t%-5s %-15s %-15s %-10s %-15s %-15s %-8s %-10s\n", 
						"N", "NOMBRE", "APELLIDO", "CI",
						"INICIO", "SALIDA", "N.HAB", "T.PAGO");
				Reservation_Show_All();
				Console_Pause();
				break;
			case 9:
				return 0;
				break;
			default:
				if(Reservation_Search_CI(Selection)){
					Console_Clear();
					Application_Menu_Reservation_Edit(
						Reservation_Search_CI(Selection));
				}
				else
					Application_Menu_Reservation_New(Selection);
		}
	}
	return 0;
}

int Application_Menu_Main(){
	int Selection = 0;

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
	
	Console_Input_Int(&Selection);
	switch(Selection){
		case 1:
			Application_Menu_Reservation();
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		case 4:
			return 1;
			break;
		case 5:
			return 1;
			break;
		case 6:
			Application_Exit();
			return 1;
			break;
		default:
			return 1;
	}
	return 0;
}

#endif /* APPLICATION_H */