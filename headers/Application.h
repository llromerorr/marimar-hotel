#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Console.h"
#include "Guest.h"
#include "Reservation.h"

//----------------------PROTOTYPES-----------------------
int Application_Menu_Main();
int Application_Menu_Reservation();
void Application_Menu_Reservation_ShowAll();
int Application_Menu_Reservation_New(int CI);
int Application_Menu_Reservation_Edit(Reservation * Pointer);

int Application_Menu_Guest();
int Application_Menu_Guest_New(int CI);
int Application_Menu_Guest_Edit(Guest * Pointer);
void Application_Menu_Guest_ShowAll();

void ScreenResource_DivitionBar(int Width, int Index, int JumpLine);
void ScreenResource_DivitionBar_Double(int Width, int Index, int JumpLine);

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
	Console_Clear();
	puts("");
	ScreenResource_DivitionBar_Double(62,1,0);
	printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
	printf("\t\t\t        FACYT COMPUTACION\n");
	ScreenResource_DivitionBar_Double(62,1,2);

	printf("\t\t\t         MENU PRINCIPAL\n");
	//ScreenResource_DivitionBar(22,6,0);
	printf("\n\t[1] RESERVACIONES\t\t->\t[%-6d %-13s]\n", ReservationQuantity,"RESERVADAS"); 
	printf("\t[2] HUESPEDES\t\t\t->\t[%-6d %-13s]\n", GuestQuantity, "OCUPADAS");
	printf("\t[3] REPORTES MENSUALES\t\t->\t[%-6d %-13s]\n", 0, "BSF GANANCIAS");
	printf("\t[9] SALIR\n\n");
	//ScreenResource_DivitionBar(62,1,2);
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
			return 1;
			break;
		case 4:
			return 1;
			break;
		case 5:
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
			if(!Time_Check(Output)){
				puts("\n\t[FECHA INVALIDA] Presione ENTER para reintentarlo...");
				Input = Time_Null();
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
			continue;
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
		puts("\t -1] ELIMINAR RESERVACION");
		puts("\t [8] GUARDAR CAMBIOS");
		printf("\t [9] SALIR\n\n");
		printf("\t Opcion: ");

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
		Guest_File_Load();
		int Selection = 0;
		Console_Clear();
		puts("");
		ScreenResource_DivitionBar_Double(62,1,0);
		printf("\n\t\t\tSISTEMA ADMINISTRATIVO HOTEL MARIMAR\n");
		printf("\t\t\t        -> HUESPEDES <-\n");
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
				if(Guest_Search_CI(Selection)){
					Console_Clear();
					Application_Menu_Guest_Edit(
						Guest_Search_CI(Selection));
				}
				else
					Application_Menu_Guest_New(Selection);
		}
	}
	return 0;
}

int Application_Menu_Guest_New(int CI){	
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
			if(!Time_Check(Output)){
				puts("\n\t[FECHA INVALIDA] Presione ENTER para reintentarlo...");
				Input = Time_Null();
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
			continue;
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
	puts("\n\tHospedaje CREADO EXITOSAMENTE, presione ENTER para continuar...");
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
		puts("\t -1] ELIMINAR HUESPED");
		puts("\t [8] GUARDAR CAMBIOS");
		printf("\t [9] SALIR\n\n");
		printf("\t Opcion: ");

		Console_Input_Int(&Selection);
		switch(Selection){
			case -1:
				Guest_Delete_ByPointer(Pointer);
				printf("\tHUESPED ELIMINADO, presione ENTER para continuar.\n");
				Guest_File_Save();
				Console_Pause();
				return 0;
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

void Application_Menu_Guest_ShowAll(){
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


//==============================================================================

void ScreenResource_DivitionBar(int Width, int Index, int JumpLine){
	for(int i = 0; i < Index; i++)
		printf("\t");

	for(int i = 0; i < Width; i++)
		printf("%c", 196);

	for(int i = 0; i < JumpLine; i++)
		printf("\n");
}

void ScreenResource_DivitionBar_Double(int Width, int Index, int JumpLine){
	for(int i = 0; i < Index; i++)
		printf("\t");

	for(int i = 0; i < Width; i++)
		printf("%c", 205);

	for(int i = 0; i < JumpLine; i++)
		printf("\n");
}

#endif /* APPLICATION_H */
