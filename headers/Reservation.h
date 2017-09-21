#ifndef RESERVATION_H
#define RESERVATION_H

#include <string.h>
#include <stdlib.h>
#include "Time.h"

int ReservationQuantity = 0;

typedef struct Reservation{
    char Name[30];
    char LastName[30];
    int CI;
    Time Input;
    Time Output;
    int Number;
    char PayType[30];
    struct Reservation* Next;
    struct Reservation* Previous;
}Reservation;

Reservation* Reservation_FirstReservation;
Reservation* Reservation_LastReservation;

void Reservation_New(char* Name,
                            char* LastName, 
                            int CI, 
                            Time Input, 
                            Time Output, 
                            int Number,
                            char* PayType){
    Reservation* NewItem = malloc(sizeof(Reservation));
    if(ReservationQuantity == 0){
        Reservation_FirstReservation = NewItem;
        Reservation_LastReservation = NewItem;
        NewItem->Next = NULL;
        NewItem->Previous = NULL;
    }
    else{
        Reservation_LastReservation->Next = NewItem;
        NewItem->Previous = Reservation_LastReservation;
        Reservation_LastReservation = NewItem;
        NewItem->Next = NULL;
    }

    ReservationQuantity++;
    strcpy(NewItem->Name, Name);
    strcpy(NewItem->LastName, LastName);
    NewItem->Input = Input;
    NewItem->Output = Output;
    NewItem->CI = CI;
    NewItem->Number = Number;
    strcpy(NewItem->PayType, PayType);
}

void Reservation_New_Null(){
    Reservation_New("none", "none", 0, Time_Null(), Time_Null(), 0, "none");
}

void Reservation_Show(Reservation * p){
        printf("\tNombre Completo:\t%s %s\n",p->Name,p->LastName);
        printf("\tCI:\t\t\t%d\n", p->CI);
        printf("\tFecha Inicio:\t\t%s\n", Time_ToString(p->Input));
        printf("\tFecha Salida:\t\t%s\n",Time_ToString(p->Output));
        printf("\tHabitacion:\t\t%d\n", p->Number);
        printf("\tTipo de pago:\t\t%s\n", p->PayType);
}

void Reservation_Show_All(){
    Reservation* p = Reservation_FirstReservation;
    for(int i = 1; p; i++){
        printf("\t%-5d ", i);
        printf("%-15s %-15s ",p->Name,p->LastName);
        printf("%-10d ", p->CI);
        printf("%-15s %-15s ", Time_ToString(p->Input), Time_ToString(p->Output));
        printf("%-8.2d ", p->Number);
        printf("%-10s\n", p->PayType);
        p = p->Next;
    }
}

void Reservation_Show_All_Reversed(){
    Reservation* p = Reservation_LastReservation;
    for(int i = ReservationQuantity; p; i--){
        printf("%d) ", i);
        printf("%s %s\t",p->Name,p->LastName);
        printf("%d\t", p->CI);
        printf("%s\t%s\t", Time_ToString(p->Input), Time_ToString(p->Output));
        printf("%d\t", p->Number);
        printf("%s\n", p->PayType);
        p = p->Previous;
    }
}

void Reservation_Memory_Clear(){
    Reservation* p = Reservation_FirstReservation;
    while(p){
        free(p);
        p = p->Next;
    }
    Reservation_FirstReservation = NULL;
    Reservation_LastReservation = NULL;
    ReservationQuantity = 0;
}

void Reservation_File_Save(){
    Reservation* p = Reservation_FirstReservation;
    FILE* file = fopen("reserva.in", "w");
    while(p){
        fprintf(file, "%s %s ",p->Name,p->LastName);
        fprintf(file, "%d ", p->CI);
        fprintf(file, "%s\t%s\t",Time_ToString(p->Input),Time_ToString(p->Output));
        fprintf(file, "%d\t", p->Number);
        fprintf(file, "%s\n", p->PayType);
        p = p->Next;
    }
    fclose(file);
}

void Reservation_File_Load(){
    //Check existence of file
    FILE* file = fopen("reserva.in", "r");
    if(file == NULL){
        fclose(file);
        file = fopen("reserva.in", "w");
        fclose(file);
        return;
    }
    //Check content file
    int count = 0;
    while(!feof(file)){
        fgetc(file);
        count++;
    } 
    
    if(count == 1)
        return;
    else{
        rewind(file);
        Reservation_Memory_Clear();
    }

    //Start to read file
    char    Name[30];
    char    LastName[30];
    int     CI;
    Time    Input;
    Time    Output;
    int     Number;
    char    PayType[30];

    while(!feof(file)){
        //read values
        fscanf(file, "%s %s %d\t", Name, LastName, &CI);
        fscanf(file, "%d/%d/%d\t", &Input.Day, &Input.Month, &Input.Year);
        fscanf(file, "%d/%d/%d\t", &Output.Day, &Output.Month, &Output.Year);
        fscanf(file,"%d\t", &Number);
        fscanf(file,"%s\n", PayType);
        //save in memory
        Reservation_New(Name, LastName, CI, Input, Output, Number, PayType);
        //reset values of variables in function
        strcpy(Name, "none");
        strcpy(LastName, "none");
        Input = Time_Null();
        Output = Time_Null();
        CI = 0;
        Number = 0;
        strcpy(PayType, "none");
    }
    fclose(file);
}

void Reservation_File_Clear(){
    FILE* file = fopen("reserva.in", "w");
    fclose(file);
}

void Reservation_Delete_ByNumber(int Selection){
    Reservation *Pointer = NULL;

    if(Selection < 1 || Selection > ReservationQuantity){
        return;
    }
    else if(Selection - 1 == 0){
        Pointer = Reservation_FirstReservation;
        if(ReservationQuantity == 1){
            Reservation_FirstReservation = NULL;
            Reservation_LastReservation = NULL;
        }
        else{
            Pointer->Next->Previous = NULL;
            Reservation_FirstReservation = Reservation_FirstReservation->Next;
        }
        free(Pointer);
        ReservationQuantity--;
    }
    else if(Selection == ReservationQuantity){
        Pointer = Reservation_LastReservation;
        Pointer->Previous->Next = NULL;
        Reservation_LastReservation = Reservation_LastReservation->Previous;
        free(Pointer);
        ReservationQuantity--;
    }
    else{
        Pointer = Reservation_FirstReservation;
        for(int i = 0; i < Selection - 1; i++){
            Pointer = Pointer->Next;
        }
        Pointer->Next->Previous = Pointer->Previous;
        Pointer->Previous->Next = Pointer->Next;
        free(Pointer);
        ReservationQuantity--;
    }
}

void Reservation_Delete_ByPointer(Reservation * Selection){
    if(Selection == NULL){
        return;
    }
    else if(Selection == Reservation_FirstReservation){
        if(ReservationQuantity == 1){
            Reservation_FirstReservation = NULL;
            Reservation_LastReservation = NULL;
        }
        else{
            Selection->Next->Previous = NULL;
            Reservation_FirstReservation = Reservation_FirstReservation->Next;
        }
        free(Selection);
        ReservationQuantity--;
    }
    else if(Selection == Reservation_LastReservation){
        Selection->Previous->Next = NULL;
        Reservation_LastReservation = Reservation_LastReservation->Previous;
        free(Selection);
        ReservationQuantity--;
    }
    else{
        Selection->Next->Previous = Selection->Previous;
        Selection->Previous->Next = Selection->Next;
        free(Selection);
        ReservationQuantity--;
    }
}

//-------------------Setters and Getters---------------------

Reservation* Reservation_Get_Reservation(int Selection){
    Reservation *Pointer = Reservation_FirstReservation;
    if(Selection < 1 || Selection > ReservationQuantity)
        return NULL;
    else{
        for(int i = 2; i <= Selection; i++)
            Pointer = Pointer->Next;
        return Pointer;
    }
}

char* Reservation_Get_Name(Reservation * Pointer){
    return Pointer->Name;
}

char* Reservation_Get_LastName(Reservation * Pointer){
    return Pointer->LastName;
}

int Reservation_Get_CI(Reservation * Pointer){
    return Pointer->CI;
}

Time Reservation_Get_TimeInput(Reservation * Pointer){
        return Pointer->Input;
}

Time Reservation_Get_TimeOutput(Reservation * Pointer){
    return Pointer->Output;
}

int Reservation_Get_Number(Reservation * Pointer){
    return Pointer->Number;
}

char* Reservation_Get_PayType(Reservation * Pointer){
    return Pointer->PayType;
}

void Reservation_Set_Name(Reservation* reservation, char* Name){
    if(reservation == NULL)
        return;
    strcpy(reservation->Name, Name);
}

void Reservation_Set_LastName(Reservation * reservation, char* LastName){
    if(reservation == NULL)
        return;
    strcpy(reservation->LastName, LastName);
}

void Reservation_Set_CI(Reservation * reservation, int CI){
    if(reservation == NULL)
        return;
    reservation->CI = CI;
}

void Reservation_Set_TimeInput(Reservation * reservation, Time time){
    if(reservation == NULL)
        return;
    Time_Copy(&reservation->Input, time);
}

void Reservation_Set_TimeOutput(Reservation * reservation, Time time){
    if(reservation == NULL)
        return;
    Time_Copy(&reservation->Output, time);
}

void Reservation_Set_Number(Reservation * reservation, int Number){
    if(reservation == NULL)
        return;
    reservation->Number = Number;
}

void Reservation_Set_PayType(Reservation * reservation, char* PayType){
    if(reservation == NULL)
        return;
    strcpy(reservation->PayType, PayType);
}

//-------------------Search and Find---------------------

Reservation* Reservation_Search_CI(int CI){
    Reservation * Pointer = Reservation_FirstReservation;
    while(Pointer){
        if(Pointer->CI == CI)
            return Pointer;
        Pointer = Pointer->Next;
    }
    return NULL;
}

#endif /* RESERVATION_H */