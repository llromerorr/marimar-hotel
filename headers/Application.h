#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Console.h"
#include "Reservation.h"

//----------------------PROTOTYPES-----------------------
int Application_Menu_Main();
int Application_Menu_Reservation();
void Application_Menu_Reservation_ShowAll();
int Application_Menu_Reservation_New(int CI);
int Application_Menu_Reservation_Edit(Reservation * Pointer);
void ScreenResource_DivitionBar();
void ScreenResource_TopBar();

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
		printf("\n\t   SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
		printf("\n\t             | ADVERTENCIA |");
		printf("\n\t==========================================\n");
		printf("\n\tEsta  a  punto de  salir del sistema, los");
		printf("\n\tcambios  no  guadados  se  perderan.\n\n");
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

//-----------------------SCREENS----------------------

void Application_Menu_Welcome(){
	printf("\n");
	ScreenResource_DivitionBar();
	printf("\n");
	printf("\t	   %c%c   %c%c      %c    %c%c%c%c%c%c%c  %c%c%c%c%c  %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t	   %c%c   %c%c    %c%c%c%c%c  %c%c%c%c%c%c%c  %c%c%c%c%c  %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219);
	printf("\t	   %c%c   %c%c   %c%c   %c%c    %c%c    %c%c     %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t	   %c%c   %c%c  %c%c     %c%c   %c%c    %c%c     %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t	   %c%c%c%c%c%c%c  %c%c     %c%c   %c%c    %c%c%c%c%c  %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t	   %c%c%c%c%c%c%c  %c%c     %c%c   %c%c    %c%c%c%c%c  %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t	   %c%c   %c%c  %c%c     %c%c   %c%c    %c%c     %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t	   %c%c   %c%c  %c%c    %c%c    %c%c    %c%c     %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t	   %c%c   %c%c   %c%c%c%c%c%c%c    %c%c    %c%c%c%c%c  %c%c%c%c%c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219);
	printf("\t	   %c%c   %c%c    %c%c%c%c      %c%c    %c%c%c%c%c  %c%c%c%c%c%c\n\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("\t%c%c%c    %c%c%c     %c     %c%c%c%c%c   %c%c  %c%c%c    %c%c%c     %c     %c%c%c%c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219);
	printf("\t%c%c%c%c   %c%c%c    %c %c    %c%c  %c%c%c %c%c  %c%c%c%c   %c%c%c    %c %c    %c%c  %c%c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219);
	printf("\t%c%c %c  %c%c%c%c   %c%c %c%c   %c%c   %c%c %c%c  %c%c %c  %c%c%c%c   %c%c %c%c   %c%c   %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219,219,219);
	printf("\t%c%c %c  %c %c%c  %c%c   %c%c  %c%c   %c%c %c%c  %c%c %c  %c %c%c  %c%c   %c%c  %c%c   %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219);
	printf("\t%c%c %c%c %c %c%c  %c%c   %c%c  %c%c  %c%c  %c%c  %c%c %c%c %c %c%c  %c%c   %c%c  %c%c  %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219,219,219);
	printf("\t%c%c %c%c %c %c%c  %c%c   %c%c  %c%c%c%c%c   %c%c  %c%c %c%c %c %c%c  %c%c   %c%c  %c%c%c%c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219,219,219,219,219);
	printf("\t%c%c  %c%c  %c%c  %c%c%c%c%c%c%c  %c%c  %c%c  %c%c  %c%c  %c%c%c %c%c  %c%c%c%c%c%c%c  %c%c  %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219,219,219,219,219,219,219,219);
	printf("\t%c%c  %c%c  %c%c  %c%c   %c%c  %c%c   %c%c %c%c  %c%c  %c%c  %c%c  %c%c   %c%c  %c%c   %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219);
	printf("\t%c%c  %c%c  %c%c  %c%c   %c%c  %c%c   %c%c %c%c  %c%c  %c%c  %c%c  %c%c   %c%c  %c%c   %c%c\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
	219,219,219,219);
	printf("\t%c%c      %c%c  %c%c   %c%c  %c%c   %c%c %c%c  %c%c      %c%c  %c%c   %c%c  %c%c   %c%c\n\n",
	219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

	ScreenResource_DivitionBar();
	printf("\t   Si tiene algun problema en poder visualizar esta pantalla \n");
	printf("\t    redimensione la consola, presione ENTER para continuar\n");
	Console_Pause();
}

//-----------------------MENUS-----------------------

int Application_Menu_Main(){
	int Selection = 0;
	Reservation_File_Load();
	Console_Clear();
	puts("");
	ScreenResource_DivitionBar();
	printf("\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
	printf("\t\t\t        FACYT COMPUTACION\n");
	printf("\t\t\t           BIENVENIDO\n");
	ScreenResource_DivitionBar();
	//printf("\n\t\t\t         MENU PRINCIPAL\n\n");
	puts("\n\t[1] Reservaciones");
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

//-----------------RESERVATION MENUS-----------------

int Application_Menu_Reservation(){
	while(1){
		Reservation_File_Load();
		int Selection = 0;
		Console_Clear();
		printf("\n\t==========================================");
		printf("\n\t   SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
		printf("\n\t            >|RESERVACIONES|<");
		printf("\n\t==========================================\n");
		printf("\n\t             CREAR O BUSCAR\n");
		printf("\n\tIntroduce una Cedula  de  Identidad, para\n");
		printf("\tcomenzar a buscar, y si no existe crearla.\n\n");
		puts("\t[1] Mostrar Reservaciones");
		puts("\t[9] Volver\n");
		printf("\tCI: ");
		
		Console_Input_Int(&Selection);
		switch(Selection){
			case 0:
				puts("\n\tNumero de CI no valido...");
				break;
			case 1:
				Application_Menu_Reservation_ShowAll();
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

int Application_Menu_Reservation_New(int CI){	
	char Name[30];
    char LastName[30];
    Time Input;
    Time Output;
    int Number;
	char PayType[30];

	Console_Clear();
	printf("\n\t==========================================");
	printf("\n\t   SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
	printf("\n\t            >|RESERVACIONES|<");
	printf("\n\t==========================================\n");
	printf("\n\t           NUEVA RESERVACION\n\n");
	printf("\tRegistrando nueva reservacion a CI:%d\n", CI);
	printf("\tpara cancelarlo escriba \"0\"\n\n");
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
	if(!Pointer)
		return 0;
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
		printf("\n\t   SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
		printf("\n\t            >|RESERVACIONES|<");
		printf("\n\t==========================================\n");
		printf("\n\t           MODIFICAR RESERVACION\n\n");
	
		printf("\tNombre Completo:\t%s %s\n",Pointer->Name,Pointer->LastName);
		printf("\tCI:\t\t\t%d\n", Pointer->CI);
		printf("\tFecha Inicio:\t\t%s\n", Time_ToString(Pointer->Input));
		printf("\tFecha Salida:\t\t%s\n",Time_ToString(Pointer->Output));
		printf("\tHabitacion:\t\t%d\n", Pointer->Number);
		printf("\tTipo de pago:\t\t%s\n", Pointer->PayType);
		printf("\n\t------------------------------------------\n\n");

		puts("\t[ 1 ] Cambiar Nombre");
		puts("\t[ 2 ] Cambiar Apellido");
		puts("\t[ 3 ] Cambiar CI");
		puts("\t[ 4 ] Cambiar Fecha Inicio");
		puts("\t[ 5 ] Cambiar Fecha Salida");
		puts("\t[ 6 ] Cambiar N. Habitacion");
		puts("\t[ 7 ] Cambiar Tipo de Pago\n");
		puts("\t[-1 ] ELIMINAR RESERVACION");
		puts("\t[ 8 ] GUARDAR CAMBIOS");
		printf("\t[ 9 ] SALIR\n\n");
		printf("\tOpcion: ");

		Console_Input_Int(&Selection);
		switch(Selection){
			case -1:
				Reservation_Delete_ByPointer(Pointer);
				printf("\tReservacion ELIMINADA, presione ENTER para continuar.\n");
				Reservation_File_Save();
				Console_Pause();
				return 0;
				break;
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

void Application_Menu_Reservation_ShowAll(){
	Console_Clear();
	int Selection = 0;
	printf("\n\t\t\t\t    ==========================================");
	printf("\n\t\t\t\t       SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
	printf("\n\t\t\t\t                >|RESERVACIONES|<");
	printf("\n\t\t\t\t    ==========================================\n");
	printf("\n\t\t\t\t            RESERVACIONES REGISTRADAS\n\n\n");
	printf("\t%-5s %-15s %-15s %-10s %-15s %-15s %-8s %-10s\n\t", 
			"N", "NOMBRE", "APELLIDO", "CI",
			"INICIO", "SALIDA", "N.HAB", "T.PAGO");

	for(int i = 0; i < 98; i++)	//
		printf("-");			// Barra separadora
	puts("");					//
	
	Reservation_Show_All();		//MOSTRAR RESERVACIONES
	
	putchar('\t');
	for(int i = 0; i < 98; i++)	//
		printf("-");			// Barra separadora
	puts("");					//
	
	printf("\n\t[ENTER]  VOLVER\n");
	printf("\t[NUMERO] MODIFICAR RESERVACION\n\n");
	printf("\tOpcion: ");
	Console_Input_Int(&Selection);
	Application_Menu_Reservation_Edit(Reservation_Get_Reservation(Selection));
}

//==============================================================================

void ScreenResource_DivitionBar(){
	printf("\t");
	for(int i = 0; i < 62; i++)
		printf("%c", 205);
	printf("\n");
}
void ScreenResource_TopBar(){
	printf("\t%c", 200);
	for(int i = 1; i < 61; i++)
		printf("%c", 205);
	printf("%c", 188);
	printf("\n");
}
#endif /* APPLICATION_H */
