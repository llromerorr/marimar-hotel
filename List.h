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
    struct Reservation* Next;
    struct Reservation* Previous;
}Reservation;

Reservation* FirstReservation;
Reservation* LastReservation;

Reservation* NewReservation(char* name,
                            char*lname, 
                            int ci, 
                            Time input, 
                            Time output, 
                            int number){
    Reservation* NewItem = malloc(sizeof(Reservation));
    if(ReservationQuantity == 0){
        FirstReservation = NewItem;
        LastReservation = NewItem;
        NewItem->Next = NULL;
        NewItem->Previous = NULL;
    }
    LastReservation->Next = NewItem;
    NewItem->Previous = LastReservation;
    LastReservation = NewItem;
    NewItem->Next = NULL;
    ReservationQuantity++;

    strcpy(NewItem->Name, name);
    strcpy(NewItem->LastName, lname);
    NewItem->Input = input;
    NewItem->Output = output;
    NewItem->CI = ci;
    NewItem->Number = number;
}

void NewReservationNull(){
    NewReservation("none", "none", 0, NullTime(), NullTime(), 0);
}

void ShowAllReservation(){
    Reservation* p = FirstReservation;
    while(p){
        printf("%s %s\t",p->Name,p->LastName);
        printf("%d\t", p->CI);
        printf("%s\t%s\t", TimeToString(p->Input), TimeToString(p->Output));
        printf("%d\n", p->Number);
        p = p->Next;
    }
}

void ShowAllReservationReversed(){
    Reservation* p = LastReservation;
    while(p){
        printf("%s %s\t",p->Name,p->LastName);
        printf("%d\t", p->CI);
        printf("%s\t%s\t", TimeToString(p->Input), TimeToString(p->Output));
        printf("%d\n", p->Number);
        p = p->Previous;
    }
}

void SaveReservation(){
    Reservation* p = FirstReservation;
    FILE* file = fopen("reserva.in", "w");
    while(p){
        fprintf(file, "%s %s ",p->Name,p->LastName);
        fprintf(file, "%d ", p->CI);
        fprintf(file, "%s\t%s\t",TimeToString(p->Input),TimeToString(p->Output));
        fprintf(file, "%d\n", p->Number);
        p = p->Next;
    }
    fclose(file);
}

void LoadReservation(){
    char    Name[30];
    char    LastName[30];
    int     CI;
    Time    Input;
    Time    Output;
    int     Number;

    FILE* file = fopen("reserva.in", "r");
    while(!feof(file)){
        //read values
        fscanf(file, "%s %s %d\t", Name, LastName, &CI);
        fscanf(file, "%d/%d/%d\t", &Input.day, &Input.month, &Input.year);
        fscanf(file, "%d/%d/%d\t", &Output.day, &Output.month, &Output.year);
        fscanf(file,"%d\n", &Number);
        //save in memery
        NewReservation (Name, LastName, CI, Input, Output, Number);
        //reset values
        strcpy(Name, "none");
        strcpy(LastName, "none");
        Input = NullTime();
        Output = NullTime();
        CI = 0;
        Number = 0;
    }
    fclose(file);
}

void ClearReservationFile(){
    FILE* file = fopen("reserva.in", "w");
    fclose(file);
}

void ClearReservationMemory(){
    Reservation* p = FirstReservation;
    while(p){
        free(p);
        p = p->Next;
    }
    FirstReservation = NULL;
    LastReservation = NULL;
    ReservationQuantity = 0;
}

void ClearReservationAll(){
    FILE* file = fopen("reserva.in", "w");
    fclose(file);

    Reservation* p = FirstReservation;
    while(p){
        free(p);
        p = p->Next;
    }
    FirstReservation = NULL;
    LastReservation = NULL;
    ReservationQuantity = 0;
}

Reservation* GetReservation(int Selection){
    Reservation *Pointer = FirstReservation;
    if(Selection < 1 || Selection > ReservationQuantity)
        return NULL;
    else{
        for(int i = 2; i <= Selection; i++)
            Pointer = Pointer->Next;
        return Pointer;
    }
}

/*
Revisar esta funcion, que es muy importante
para poder eliminar los usuarios de las
reservaciones posteriormente, cuando el sis-
tema este mas completo.

void DeleteReservation(int Selection){
    Selection--;
    if(Selection < 0 || Selection > ReservationQuantity)
        return;
    else if(Selection == 1){

    }else if(Selection == Reser){

    }
    Reservation *Pointer = FirstReservation;
    for(int i = 0; i < Selection; i++)
        Pointer = Pointer->Next;
    Pointer->Previous->Next = Pointer->Next;
    Pointer->Next->Previous = Pointer->Previous;
    ReservationQuantity--;
    free(Pointer);
}
/*