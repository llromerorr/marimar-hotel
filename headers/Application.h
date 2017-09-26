#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Screen.h"
#include "Console.h"
#include "Guest.h"
#include "Charge.h"
#include "Room.h"
#include "Reservation.h"

//----------------------PROTOTYPES-----------------------
int Application_Menu_Main();

int Application_Menu_Reservation();
void Application_Menu_Reservation_ShowAll();
int Application_Menu_Reservation_New(int CI);
int Application_Menu_Reservation_Edit(Reservation * Pointer);

int Application_Menu_Guest();
int Application_Menu_Guest_New(int CI);
void Application_Menu_Guest_NewFormReservation(Reservation * reservation);
int Application_Menu_Guest_Edit(Guest * Pointer);
void Application_Menu_Guest_Out(Guest * Pointer);
void Application_Menu_Guest_ShowAll();

int Application_Menu_Charge();
int Application_Menu_Charge_New(int CI);
void Application_Menu_Charge_ShowAll();
void Application_Menu_Charge_Edit(Charge * charge);

int Application_Menu_Report();
int Application_Menu_Report_Show(int imonth);
//----------------------FUNCTIONS------------------------

void Application_Pause(){
	printf("\n\t[PRESIONE ENTER PARA CONTINUAR...]");
	while(getchar()!= '\n');
}

void Application_Exit(){
	while(1){
		Console_Clear();
		char letter;
		puts("");
		ScreenResource_DivitionBar_Double(41,1,1);
		printf("\t             | ADVERTENCIA |\n");
		ScreenResource_DivitionBar_Double(41,1,1);
		printf("\n\tEsta  a  punto de  salir del sistema, los");
		printf("\n\tcambios  no  guadados  se  perderan.\n");
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

void Application_Menu_Error_NoFreeRooms(){
	Console_Clear();
	puts("");
	ScreenResource_DivitionBar_Double(41,1,1);
	printf("\t             | ADVERTENCIA |\n");
	ScreenResource_DivitionBar_Double(41,1,1);
	printf("\n\tNo se puden realizar reservaciones, no");
	printf("\n\thay habitaciones disponibles.\n");
	Application_Pause();
}

//-----------------------SCREENS----------------------

void Application_Menu_Welcome(){
	printf("\n");
	ScreenResource_DivitionBar_Double(62,1,1);
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

	ScreenResource_DivitionBar_Double(62,1,1);
	printf("\t   Si tiene algun problema en poder visualizar esta pantalla \n");
	printf("\t    redimensione la consola, presione ENTER para continuar\n");
	Console_Pause();
}

//-----------------------MENUS-----------------------

int Application_Menu_Main(){
	int Selection = 0;
	Reservation_File_Load();
	Guest_File_Load();
	Room_File_Load();
	Charge_File_Load();
	Console_Clear();
	puts("");
	ScreenResource_DivitionBar_Double(62,1,0);
	printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
	printf("\t\t\t        FACYT COMPUTACION\n");
	ScreenResource_DivitionBar_Double(62,1,2);

	printf("\t\t\t         MENU PRINCIPAL\n");
	printf("\n\t[1] RESERVACIONES\t\t->\t[%-6d %-13s]\n", ReservationQuantity,"RESERVADAS"); 
	printf("\t[2] HUESPEDES\t\t\t->\t[%-6d %-13s]\n", GuestQuantity, "OCUPADAS");
	printf("\t[3] CARGOS\t\t\t\t[%-6d %-13s]\n", Room_Get_RoomFree_Quantity() , "LIBRES");
	printf("\t[4] REPORTES\n\n");
	printf("\t[9] SALIR\n\n");
	printf("\tOpcion: ");
	
	Console_Input_Int(&Selection);
	switch(Selection){
		case 1:
			Application_Menu_Reservation();
			return 1;
			break;
		case 2:
			Application_Menu_Guest();
			return 1;
			break;
		case 3:
			Application_Menu_Charge();
			return 1;
			break;
		case 4:
			Application_Menu_Report();
			return 1;
			break;
		case 9:
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
		Guest_File_Load();
		Room_File_Load();
		Charge_File_Load();
		
		int Selection = 0;
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t        -> RESERVACIONES <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);
		puts("\t[1] Mostrar Reservaciones");
		puts("\t[9] Volver\n");
		printf("\tCI: ");
		
		Console_Input_Int(&Selection);
		switch(Selection){
			case 0:
				break;
			case 1:
				Application_Menu_Reservation_ShowAll();
				break;
			case 9:
				return 0;
				break;
			default:
				if(Guest_Search_CI(Selection)){
					puts("\n\tEl cliente ya esta hospedado");
					Application_Pause();
				}
				else if(Reservation_Search_CI(Selection)){
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
	if(!Room_Get_RoomFree()){
		Application_Menu_Error_NoFreeRooms();
		return 0;
	}

	char Name[30] = "";
    char LastName[30] = "";
    Time Input = Time_Null();
    Time Output = Time_Null();
    int Number = -1;
	char PayType[30] = "";

	while(1){
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t            RESERVACIONES\n");
		printf("\t\t\t       -> NUEVA RESERVACION <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);

		printf("\t[0] Cancelar\n\n");
		printf("\tCEDULA:\t\t%d\n", CI);
		printf("\tNOMBRE:\t\t");
		if(strcmp(Name, "") == 0){
			scanf("%s", Name);
			while(getchar() != '\n');
			if(strcmp(Name, "0") == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}
		else{
			puts(Name);
		}
	
		printf("\tAPELLIDO:\t");
		if(strcmp(LastName, "") == 0){
			scanf("%s",LastName);
			while(getchar() != '\n');
			if(strcmp(LastName, "0") == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}	
		else{
			puts(LastName);
		}

		printf("\tFecha Inicio (dia/mes/ano): ");
		if(Time_Compare(Input, Time_Null()) == 0){
			scanf("%d/", &Input.Day);
			if(Input.Day == 0){	
				while(getchar() != '\n');
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			scanf("%d/%d", &Input.Month, &Input.Year);
			while(getchar() != '\n');
			if(!Time_Check(Input)){
				puts("\n\t[FECHA INVALIDA] Presione ENTER para reintentarlo...");
				Input = Time_Null();
				Console_Pause();
				continue;
			}
			continue;
		}
		else{
			puts(Time_ToString(Input));
		}

		printf("\tFecha Salida (dia/mes/ano): ");
		if(Time_Compare(Output, Time_Null()) == 0){
			scanf("%d/", &Output.Day);
			if(Output.Day == 0){
				while(getchar() != '\n');
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			scanf("%d/%d", &Output.Month, &Output.Year);
			while(getchar() != '\n');
			if(!Time_Check(Output) || Time_Compare(Input, Output) == 1 || Time_Compare(Input, Output) == 0 ){
				puts("\n\t[FECHA INVALIDA] Presione ENTER para reintentarlo...");
				Output = Time_Null();
				Console_Pause();
				continue;
			}
			continue;
		}
		else{
			puts(Time_ToString(Output));
		}

		printf("\tNumero Habitacion: ");
		if(Number == -1){
			scanf("%d", &Number);
			while(getchar() != '\n');
			if(Number == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}

			int *RoomFree = Room_Get_RoomFree();
			bool NumberIsOk = false;
			for(int i = 0; RoomFree[i]; i++)
				if(Number == RoomFree[i])
					NumberIsOk = true;
			if(!NumberIsOk){
				printf("\n\t*Habitacion %d no disponible*\n", Number);
				printf("\n\tDisponibles: [ ");
				for(int i = 0; RoomFree[i]; i++)
					printf("%d ", RoomFree[i]);
				printf("]\n");
				printf("\n\tPresione ENTER para continuar...\n");
				Number = -1;
				Console_Pause();
				continue;
			}
		}
		else
			printf("%d\n", Number);

		printf("\tTipo de pago: ");
		if(strcmp(PayType, "") == 0){
			scanf("%s", PayType);
			while(getchar() != '\n');
			if(strcmp(PayType, "0") == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}
		else
			puts(PayType);
		break; // Continuar a la creacion
	}

	Reservation_New(Name, LastName, CI, Input, Output, Number, PayType);
	Reservation_File_Save();
	puts("\n\tRESERVACION CREADA EXITOSAMENTE, presione ENTER para continuar...");
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
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t            RESERVACIONES\n");
		printf("\t\t\t     -> MODIFICAR RESERVACION <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);
	
		printf("\t Nombre Completo:\t%s %s\n",Pointer->Name,Pointer->LastName);
		printf("\t CI:\t\t\t%d\n", Pointer->CI);
		printf("\t Fecha Inicio:\t\t%s\n", Time_ToString(Pointer->Input));
		printf("\t Fecha Salida:\t\t%s\n",Time_ToString(Pointer->Output));
		printf("\t Habitacion:\t\t%d\n", Pointer->Number);
		printf("\t Tipo de pago:\t\t%s\n\n", Pointer->PayType);

		ScreenResource_DivitionBar(62,1,2);

		puts("\t [1]  Cambiar Nombre");
		puts("\t [2]  Cambiar Apellido");
		puts("\t [3]  Cambiar CI");
		puts("\t [4]  Cambiar Fecha Inicio");
		puts("\t [5]  Cambiar Fecha Salida");
		puts("\t [6]  Cambiar N. Habitacion");
		puts("\t [7]  Cambiar Tipo de Pago\n");
		puts("\t -1] CANCELAR RESERVACION");
		puts("\t [8] GUARDAR CAMBIOS");
		printf("\t [9] SALIR\n\n");
		printf("\t Opcion: ");

		Console_Input_Int(&Selection);
		switch(Selection){
			case -1:
				Reservation_Delete_ByPointer(Pointer);
				printf("\t Reservacion ELIMINADA, presione ENTER para continuar.\n");
				Reservation_File_Save();
				Console_Pause();
				return 0;
				break;
			case 1:
				printf("\t Nombre: ");
				scanf("%s", Name);
				Reservation_Set_Name(Pointer, Name);
				break;
			case 2:
				printf("\t Apellido: ");
				scanf("%s", LastName);
				Reservation_Set_LastName(Pointer, LastName);
				break;
			case 3:
				printf("\t CI: ");
				Console_Input_Int(&CI);
				Reservation_Set_CI(Pointer, CI);
				break;
			case 4:
				printf("\t Fecha Inicio (dia/mes/ano): ");
				scanf("%d/%d/%d", &Input.Day, &Input.Month, &Input.Year);
				Reservation_Set_TimeInput(Pointer, Input);
				break;
			case 5:
				printf("\t Fecha Salida (dia/mes/ano): ");
				scanf("%d/%d/%d", &Output.Day, &Output.Month, &Output.Year);
				Reservation_Set_TimeOutput(Pointer, Output);
				break;
			case 6:
				printf("\t Numero Habitacion: ");
				Console_Input_Int(&Number);
				Reservation_Set_Number(Pointer, Number);
				break;
			case 7:
				printf("\t Tipo de Pago: ");
				scanf("%s", PayType);
				Reservation_Set_PayType(Pointer, PayType);
				break;
			case 8:
				Reservation_File_Save();
				printf("\n\tCAMBIOS GUARDADOS EXITOSAMENTE!, presiones ENTER para continuar...\n");
				Console_Pause();
			case 9:
				return 0;
		}
	}
	return 0;
}

void Application_Menu_Reservation_ShowAll(){
	Reservation_File_Load();
	Guest_File_Load();
	Room_File_Load();
	Charge_File_Load();

	Console_Clear();
	int Selection = 0;
	printf("\n\t\t\t\t    "); ScreenResource_DivitionBar_Double(42,0,1);
	printf("\n\t\t\t\t       SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
	printf("\n\t\t\t\t                  RESERVACIONES");
	printf("\n\t\t\t\t                -> REGISTRADAS <-\n");
	printf("\n\t\t\t\t    "); ScreenResource_DivitionBar_Double(42,0,1);
	printf("\n\t\t\t\t            RESERVACIONES REGISTRADAS\n\n\n");
	printf("\t%-5s %-15s %-15s %-10s %-15s %-15s %-8s %-10s\n", 
			"N", "NOMBRE", "APELLIDO", "CI",
			"INICIO", "SALIDA", "N.HAB", "T.PAGO");

	ScreenResource_DivitionBar(98,1,1);
	Reservation_Show_All();		//MOSTRAR RESERVACIONES
	ScreenResource_DivitionBar(98,1,1);
	
	printf("\n\t[ENTER]  VOLVER\n");
	printf("\t[NUMERO] MODIFICAR RESERVACION\n\n");
	printf("\tOpcion: ");
	Console_Input_Int(&Selection);
	Application_Menu_Reservation_Edit(Reservation_Get_Reservation(Selection));
}

//-----------------Guest MENUS-----------------

int Application_Menu_Guest(){
	while(1){	
		Reservation_File_Load();
		Guest_File_Load();
		Room_File_Load();
		Charge_File_Load();

		int Selection = 0;
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t          -> HUESPEDES <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);
		puts("\t[1] MOSTRAR HUESPEDES");
		puts("\t[9] VOLVER\n");
		printf("\tCI: ");
		
		Console_Input_Int(&Selection);
		switch(Selection){
			case 0:
				break;
			case 1:
				Application_Menu_Guest_ShowAll();
				break;
			case 9:
				return 0;
				break;
			default:
				if(Reservation_Search_CI(Selection)){
					Application_Menu_Guest_NewFormReservation(Reservation_Search_CI(Selection));
				}
				else if(Guest_Search_CI(Selection)){
					Console_Clear();
					Application_Menu_Guest_Edit(Guest_Search_CI(Selection));
				}
				else
					Application_Menu_Guest_New(Selection);
		}
	}
	return 0;
}

void Application_Menu_Guest_NewFormReservation(Reservation * reservation){
	while(1){
		Console_Clear();
		char letter;
		puts("");
		ScreenResource_DivitionBar_Double(41,1,1);
		printf("\t             | ADVERTENCIA |\n");
		ScreenResource_DivitionBar_Double(41,1,2);
		Reservation_Show(reservation);
		printf("\n\tEl cliente ya posee una RESERVACION, sera");
		printf("\n\tmovido a la lista de HUESPEDES.\n");
		printf("\n\tQuiere realizar esta operacion? [S/N]: ");
		letter = getc(stdin);
		while(getchar()!='\n');
		if(letter == 's' || letter == 'S'){
			Guest_NewFormReservation(reservation);
			printf("\n\tOPERACION REALIZADA EXITOSAMENTE\n");
			puts("\tPresione ENTER para continuar...");
			Console_Pause();
			break;
		}
		else if(letter == 'n' || letter == 'N')
			break;
	}
}

int Application_Menu_Guest_New(int CI){
	if(!Room_Get_RoomFree()){
		Application_Menu_Error_NoFreeRooms();
		return 0;
	}

	char Name[30] = "";
    char LastName[30] = "";
    Time Input = Time_Null();
    Time Output = Time_Null();
    int Number = -1;
	char PayType[30] = "";

	while(1){
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t              HUESPEDES\n");
		printf("\t\t\t         -> NUEVO HUESPED <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);

		printf("\t[0] Cancelar\n\n");
		printf("\tCEDULA:\t\t%d\n", CI);
		printf("\tNOMBRE:\t\t");
		if(strcmp(Name, "") == 0){
			scanf("%s", Name);
			while(getchar() != '\n');
			if(strcmp(Name, "0") == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}
		else{
			puts(Name);
		}
	
		printf("\tAPELLIDO:\t");
		if(strcmp(LastName, "") == 0){
			scanf("%s",LastName);
			while(getchar() != '\n');
			if(strcmp(LastName, "0") == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}	
		else{
			puts(LastName);
		}

		printf("\tFecha Inicio (dia/mes/ano): ");
		if(Time_Compare(Input, Time_Null()) == 0){
			scanf("%d/", &Input.Day);
			if(Input.Day == 0){	
				while(getchar() != '\n');
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			scanf("%d/%d", &Input.Month, &Input.Year);
			while(getchar() != '\n');
			if(!Time_Check(Input)){
				puts("\n\t[FECHA INVALIDA] Presione ENTER para reintentarlo...");
				Input = Time_Null();
				Console_Pause();
				continue;
			}
			continue;
		}
		else{
			puts(Time_ToString(Input));
		}

		printf("\tFecha Salida (dia/mes/ano): ");
		if(Time_Compare(Output, Time_Null()) == 0){
			scanf("%d/", &Output.Day);
			if(Output.Day == 0){
				while(getchar() != '\n');
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			scanf("%d/%d", &Output.Month, &Output.Year);
			while(getchar() != '\n');
			if(!Time_Check(Output) || Time_Compare(Input, Output) == 1 || Time_Compare(Input, Output) == 0 ){
				puts("\n\t[FECHA INVALIDA] Presione ENTER para reintentarlo...");
				Output = Time_Null();
				Console_Pause();
				continue;
			}
			continue;
		}
		else{
			puts(Time_ToString(Output));
		}

		printf("\tNumero Habitacion: ");
		if(Number == -1){
			scanf("%d", &Number);
			while(getchar() != '\n');
			if(Number == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}

			int *RoomFree = Room_Get_RoomFree();
			bool NumberIsOk = false;
			for(int i = 0; RoomFree[i]; i++)
				if(Number == RoomFree[i])
					NumberIsOk = true;
			if(!NumberIsOk){
				printf("\n\t*Habitacion %d no disponible*\n", Number);
				printf("\n\tDisponibles: [ ");
				for(int i = 0; RoomFree[i]; i++)
					printf("%d ", RoomFree[i]);
				printf("]\n");
				printf("\n\tPresione ENTER para continuar...\n");
				Number = -1;
				Console_Pause();
				continue;
			}
		}
		else
			printf("%d\n", Number);

		printf("\tTipo de pago: ");
		if(strcmp(PayType, "") == 0){
			scanf("%s", PayType);
			while(getchar() != '\n');
			if(strcmp(PayType, "0") == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}
		else
			puts(PayType);
		break; // Continuar a la creacion
	}

	Guest_New(Name, LastName, CI, Input, Output, Number, PayType);
	Guest_File_Save();
	puts("\n\tHOSPEDAJE CREADO EXITOSAMENTE, presione ENTER para continuar...");
	Console_Pause();
	return 0;
}

int Application_Menu_Guest_Edit(Guest * Pointer){
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
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t            HUESPEDES\n");
		printf("\t\t\t     -> MODIFICAR HUESPED <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);
	
		printf("\t Nombre Completo:\t%s %s\n",Pointer->Name,Pointer->LastName);
		printf("\t CI:\t\t\t%d\n", Pointer->CI);
		printf("\t Fecha Inicio:\t\t%s\n", Time_ToString(Pointer->Input));
		printf("\t Fecha Salida:\t\t%s\n",Time_ToString(Pointer->Output));
		printf("\t Habitacion:\t\t%d\n", Pointer->Number);
		printf("\t Tipo de pago:\t\t%s\n\n", Pointer->PayType);

		ScreenResource_DivitionBar(62,1,2);

		puts("\t [1]  Cambiar Nombre");
		puts("\t [2]  Cambiar Apellido");
		puts("\t [3]  Cambiar CI");
		puts("\t [4]  Cambiar Fecha Inicio");
		puts("\t [5]  Cambiar Fecha Salida");
		puts("\t [6]  Cambiar N. Habitacion");
		puts("\t [7]  Cambiar Tipo de Pago\n");
		puts("\t -1] SALIDA DEL HUESPED");
		puts("\t [8] GUARDAR CAMBIOS");
		printf("\t [9] SALIR\n\n");
		printf("\t Opcion: ");

		Console_Input_Int(&Selection);
		switch(Selection){
			case -1:
				Application_Menu_Guest_Out(Pointer);
				break;
			case 1:
				printf("\t Nombre: ");
				scanf("%s", Name);
				Guest_Set_Name(Pointer, Name);
				break;
			case 2:
				printf("\t Apellido: ");
				scanf("%s", LastName);
				Guest_Set_LastName(Pointer, LastName);
				break;
			case 3:
				printf("\t CI: ");
				Console_Input_Int(&CI);
				Guest_Set_CI(Pointer, CI);
				break;
			case 4:
				printf("\t Fecha Inicio (dia/mes/ano): ");
				scanf("%d/%d/%d", &Input.Day, &Input.Month, &Input.Year);
				Guest_Set_TimeInput(Pointer, Input);
				break;
			case 5:
				printf("\t Fecha Salida (dia/mes/ano): ");
				scanf("%d/%d/%d", &Output.Day, &Output.Month, &Output.Year);
				Guest_Set_TimeOutput(Pointer, Output);
				break;
			case 6:
				printf("\t Numero Habitacion: ");
				Console_Input_Int(&Number);
				Guest_Set_Number(Pointer, Number);
				break;
			case 7:
				printf("\t Tipo de Pago: ");
				scanf("%s", PayType);
				Guest_Set_PayType(Pointer, PayType);
				break;
			case 8:
				Guest_File_Save();
				printf("\n\tCAMBIOS GUARDADOS EXITOSAMENTE!, presiones ENTER para continuar...\n");
				Console_Pause();
			case 9:
				return 0;
		}
	}
	return 0;
}


void Application_Menu_Guest_Out(Guest * Pointer){
	while(1){
		Console_Clear();
		char letter;
		puts("");
		ScreenResource_DivitionBar_Double(41,1,1);
		printf("\t             | ADVERTENCIA |\n");
		printf("\t         -> SALIDA DE HUESPED <-\n");
		ScreenResource_DivitionBar_Double(41,1,2);
		Charge_Show_BillByPointer(Pointer);
		printf("\n\tSe procesara la salida de un HUESPED, esto");
		printf("\n\tlimpiara del sistema sus cargos y liberara");
		printf("\n\tsu habitacion, dejandola disponible.\n");
		printf("\n\tQuiere continuar con este proceso? [S/N]: ");
		letter = getc(stdin);
		while(getchar()!='\n');
		if(letter == 's' || letter == 'S'){
			Charge_Delete_ByAllPointers(Charge_Search_ByCI_AllPointers(Pointer->CI));
			Guest_Delete_ByPointer(Pointer);
			Charge_File_Save();
			Guest_File_Save();
			puts("\n\tOPERACION REALIZADA EXITOSAMENTE, presione ENTER para continuar...");
			Console_Pause();
			break;
		}
		else if(letter == 'n' || letter == 'N')
			break;
	}
}

void Application_Menu_Guest_ShowAll(){
	Reservation_File_Load();
	Guest_File_Load();
	Room_File_Load();
	Charge_File_Load();

	Console_Clear();
	int Selection = 0;
	printf("\n\t\t\t\t    "); ScreenResource_DivitionBar_Double(42,0,1);
	printf("\n\t\t\t\t       SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
	printf("\n\t\t\t\t                    HUESPEDES");
	printf("\n\t\t\t\t                -> REGISTRADOS <-\n");
	printf("\n\t\t\t\t    "); ScreenResource_DivitionBar_Double(42,0,1);
	printf("\n\t\t\t\t              HUESPEDES REGISTRADOS\n\n\n");
	printf("\t%-5s %-15s %-15s %-10s %-15s %-15s %-8s %-10s\n", 
			"N", "NOMBRE", "APELLIDO", "CI",
			"INICIO", "SALIDA", "N.HAB", "T.PAGO");

	ScreenResource_DivitionBar(98,1,1);
	Guest_Show_All();		//MOSTRAR HuespedES
	ScreenResource_DivitionBar(98,1,1);
	
	printf("\n\t[ENTER]  VOLVER\n");
	printf("\t[NUMERO] MODIFICAR HUESPED\n\n");
	printf("\tOpcion: ");
	Console_Input_Int(&Selection);
	Application_Menu_Guest_Edit(Guest_Get_Guest(Selection));
}

void Application_Menu_Charge_ShowAll(){
	Charge_File_Load();

	Console_Clear();
	int Selection = 0;
	printf("\n"); ScreenResource_DivitionBar_Double(54,1,1);
	printf("\n\t         SISTEMA ADMINISTRATIVO HOTEL MARIMAR");
	printf("\n\t                       CARGOS");
	printf("\n\t                  -> REGISTRADOS <-\n");
	printf("\n"); ScreenResource_DivitionBar_Double(54,1,1);
	printf("\n\t                  CARGOS REGISTRADOS\n\n\n");
	printf("\t%-5s %-10s %-12s %-15s %-10s\n",
			"N", "CI", "FECHA","TIPO", "COSTO");

	ScreenResource_DivitionBar(54,1,1);
	Charge_Show_All();
	ScreenResource_DivitionBar(54,1,1);
	
	printf("\n\t[ENTER]   VOLVER\n");
	printf("\t[-NUMERO] ELIMINAR CARGO\n\n");
	printf("\tOpcion: ");
	Console_Input_Int(&Selection);
	if(Charge_Delete_ByNumber(Selection * -1)){
		Charge_File_Save();
		puts("\tCARGO ELIMINADO, presione ENTER para continuar...");
		Console_Pause();
	}
		
}

int Application_Menu_Charge_New(int CI){
	Time TimeCharge = Time_Null();
	char Type[30] = "";
	int Cost = -1;
	Guest * guest = Guest_Search_CI(CI);

	while(1){
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t               CARGOS\n");
		printf("\t\t\t         -> NUEVO CARGOS <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);

		printf("\t[0] Cancelar\n\n");
		printf("\tCEDULA:\t\t%d\n", CI);
		printf("\tTipo:\t\t");
		if(strcmp(Type, "") == 0){
			scanf("%s", Type);
			while(getchar() != '\n');
			if(strcmp(Type, "0") == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}
		else{
			puts(Type);
		}

		printf("\tFecha(dia/mes/ano): ");
		if(Time_Compare(TimeCharge, Time_Null()) == 0){
			scanf("%d/", &TimeCharge.Day);
			if(TimeCharge.Day == 0){
				while(getchar() != '\n');
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			scanf("%d/%d", &TimeCharge.Month, &TimeCharge.Year);
			while(getchar() != '\n');
			if(!Time_Check(TimeCharge) || Time_Compare(guest->Input, TimeCharge) == 1){
				puts("\n\t[FECHA INVALIDA] Presione ENTER para reintentarlo...");
				TimeCharge = Time_Null();
				Console_Pause();
				continue;
			}
			continue;
		}
		else{
			puts(Time_ToString(TimeCharge));
		}

		printf("\tCosto del Servicio: ");
		if(Cost == -1){
			scanf("%d", &Cost);
			while(getchar() != '\n');
			if(Cost == 0){
				puts("\n\t[CREACION CANCELADA] Presione ENTER para salir...");
				Console_Pause();
				return 0;
			}
			continue;
		}
		else
			printf("%d\n", Cost);
		break; // Continuar a la creacion
	}

	Charge_New(CI, TimeCharge, Type, Cost);
	Charge_File_Save();
	puts("\n\tCARGO CREADO EXITOSAMENTE, presione ENTER para continuar...");
	Console_Pause();
	return 0;
}

int Application_Menu_Charge(){
	while(1){
		Reservation_File_Load();
		Guest_File_Load();
		Room_File_Load();
		Charge_File_Load();
		
		int Selection = 0;
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t            -> CARGOS <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);
		puts("\t[1] Mostrar Cargos");
		puts("\t[9] Volver\n");
		printf("\tCI: ");
		
		Console_Input_Int(&Selection);
		switch(Selection){
			case 0:
				break;
			case 1:
				Application_Menu_Charge_ShowAll();
				break;
			case 9:
				return 0;
				break;
			default:
				if(Guest_Search_CI(Selection))
					Application_Menu_Charge_New(Selection);
				else{
					puts("\n\tEL CLIENTE NO ESTA HOSPEDADO, presione ENTER para continuar...");
					Console_Pause();
				}	
		}
	}
	return 0;
}

int Application_Menu_Report(){
	while(1){
		Reservation_File_Load();
		Guest_File_Load();
		Room_File_Load();
		Charge_File_Load();
		
		int Selection = 0;
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t      SISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t                 -> REPORTES <-\n");
		ScreenResource_DivitionBar_Double(62,1,2);
		puts("\t[-1] Volver\n");
		printf("\tMes[1-12]: ");
		
		Console_Input_Int(&Selection);
		if(Selection == -1)
			break;
		else if(Selection < 1 || Selection > 12){
			puts("\n\tEL MES NO EXISTE, presione ENTER para continuar...");
			Console_Pause();
		}
		else{
			Application_Menu_Report_Show(Selection);
		}
	}
	return 0;
}
int Application_Menu_Report_Show(int imonth){
	Reservation_File_Load();
	Guest_File_Load();
	Charge_File_Load();
	Room_File_Load();

	int Total = 0;
	Reservation * reservation = Reservation_FirstReservation;
	Guest * guest = Guest_FirstGuest;

	int DaysReservation = 0;
	int DaysGuest = 0;
	printf("\n\t%-15s %-10s\n", "HHABITACION", "DIAS");
	ScreenResource_DivitionBar(20,1,1);
	while(reservation){
		if(reservation->Input.Month == imonth){
			if(reservation->Output.Month == imonth){
				DaysReservation += Time_DaysBetween(reservation->Input, reservation->Output);
				printf("\t%-15d %-10d\n", reservation->Number, Time_DaysBetween(reservation->Input, reservation->Output));
				Total += Time_DaysBetween(reservation->Input, reservation->Output) * 
					Room_Get_Cost_ByNumber(reservation->Number);
			}
			else if(reservation->Output.Month > imonth){
				Time tNull = Time_New(1, reservation->Input.Month + 
					(reservation->Output.Month - reservation->Input.Month), 
					reservation->Input.Year);
				DaysReservation += Time_DaysBetween(reservation->Input, tNull);
				printf("\t%-15d %-10d\n", reservation->Number, Time_DaysBetween(reservation->Input, tNull));
				Total += Time_DaysBetween(reservation->Input, tNull) * Room_Get_Cost_ByNumber(reservation->Number);
			}
		}
		reservation = reservation->Next;
	}

	while(guest){
		if(guest->Input.Month == imonth){
			if(guest->Output.Month == imonth){
				DaysGuest += Time_DaysBetween(guest->Input, guest->Output);
				printf("\t%-15d %-10d\n", guest->Number, Time_DaysBetween(guest->Input, guest->Output));
				Total += Time_DaysBetween(guest->Input, guest->Output) * Room_Get_Cost_ByNumber(guest->Number);
			}
			else if(guest->Output.Month > imonth){
				Time tNull = Time_New(1, guest->Input.Month + 
					(guest->Output.Month - guest->Input.Month), 
					guest->Input.Year);
				DaysGuest += Time_DaysBetween(guest->Input, tNull);
				printf("\t%-15d %-10d\n", guest->Number, Time_DaysBetween(guest->Input, tNull));
				Total += Time_DaysBetween(guest->Input, tNull) * Room_Get_Cost_ByNumber(reservation->Number);
			}
		}
		guest = guest->Next;
	}
	ScreenResource_DivitionBar(20,1,1);
	printf("\tTOTAL: %-d Bsf\n", Total);
	Console_Pause();
	return 0;
}

#endif /* APPLICATION_H */
