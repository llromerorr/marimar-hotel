#ifndef Guest_H
#define Guest_H

#include <string.h>
#include <stdlib.h>
#include "Time.h"

int GuestQuantity = 0;

typedef struct Guest{
    char Name[30];
    char LastName[30];
    int CI;
    Time Input;
    Time Output;
    int Number;
    char PayType[30];
    struct Guest* Next;
    struct Guest* Previous;
}Guest;

Guest* Guest_FirstGuest;
Guest* Guest_LastGuest;

void Guest_New(char* Name,
                            char* LastName, 
                            int CI, 
                            Time Input, 
                            Time Output, 
                            int Number,
                            char* PayType){
    Guest* NewItem = malloc(sizeof(Guest));
    if(GuestQuantity == 0){
        Guest_FirstGuest = NewItem;
        Guest_LastGuest = NewItem;
        NewItem->Next = NULL;
        NewItem->Previous = NULL;
    }
    else{
        Guest_LastGuest->Next = NewItem;
        NewItem->Previous = Guest_LastGuest;
        Guest_LastGuest = NewItem;
        NewItem->Next = NULL;
    }

    GuestQuantity++;
    strcpy(NewItem->Name, Name);
    strcpy(NewItem->LastName, LastName);
    NewItem->Input = Input;
    NewItem->Output = Output;
    NewItem->CI = CI;
    NewItem->Number = Number;
    strcpy(NewItem->PayType, PayType);
}

void Guest_New_Null(){
    Guest_New("none", "none", 0, Time_Null(), Time_Null(), 0, "none");
}

void Guest_Show(Guest * p){
        printf("\tNombre Completo:\t%s %s\n",p->Name,p->LastName);
        printf("\tCI:\t\t\t%d\n", p->CI);
        printf("\tFecha Inicio:\t\t%s\n", Time_ToString(p->Input));
        printf("\tFecha Salida:\t\t%s\n",Time_ToString(p->Output));
        printf("\tHabitacion:\t\t%d\n", p->Number);
        printf("\tTipo de pago:\t\t%s\n", p->PayType);
}

void Guest_Show_All(){
    Guest* p = Guest_FirstGuest;
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

void Guest_Show_All_Reversed(){
    Guest* p = Guest_LastGuest;
    for(int i = GuestQuantity; p; i--){
        printf("%d) ", i);
        printf("%s %s\t",p->Name,p->LastName);
        printf("%d\t", p->CI);
        printf("%s\t%s\t", Time_ToString(p->Input), Time_ToString(p->Output));
        printf("%d\t", p->Number);
        printf("%s\n", p->PayType);
        p = p->Previous;
    }
}

void Guest_Memory_Clear(){
    Guest* p = Guest_FirstGuest;
    while(p){
        free(p);
        p = p->Next;
    }
    Guest_FirstGuest = NULL;
    Guest_LastGuest = NULL;
    GuestQuantity = 0;
}

void Guest_File_Save(){
    Guest* p = Guest_FirstGuest;
    FILE* file = fopen("huesped.txt", "w");
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

void Guest_File_Load(){
    //Check existence of file
    FILE* file = fopen("huesped.txt", "r");
    if(file == NULL){
        fclose(file);
        file = fopen("huesped.txt", "w");
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
        Guest_Memory_Clear();
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
        Guest_New(Name, LastName, CI, Input, Output, Number, PayType);
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

void Guest_File_Clear(){
    FILE* file = fopen("huesped.txt", "w");
    fclose(file);
}

void Guest_Delete_ByNumber(int Selection){
    Guest *Pointer = NULL;

    if(Selection < 1 || Selection > GuestQuantity){
        return;
    }
    else if(Selection - 1 == 0){
        Pointer = Guest_FirstGuest;
        if(GuestQuantity == 1){
            Guest_FirstGuest = NULL;
            Guest_LastGuest = NULL;
        }
        else{
            Pointer->Next->Previous = NULL;
            Guest_FirstGuest = Guest_FirstGuest->Next;
        }
        free(Pointer);
        GuestQuantity--;
    }
    else if(Selection == GuestQuantity){
        Pointer = Guest_LastGuest;
        Pointer->Previous->Next = NULL;
        Guest_LastGuest = Guest_LastGuest->Previous;
        free(Pointer);
        GuestQuantity--;
    }
    else{
        Pointer = Guest_FirstGuest;
        for(int i = 0; i < Selection - 1; i++){
            Pointer = Pointer->Next;
        }
        Pointer->Next->Previous = Pointer->Previous;
        Pointer->Previous->Next = Pointer->Next;
        free(Pointer);
        GuestQuantity--;
    }
}

void Guest_Delete_ByPointer(Guest * Selection){
    if(Selection == NULL){
        return;
    }
    else if(Selection == Guest_FirstGuest){
        if(GuestQuantity == 1){
            Guest_FirstGuest = NULL;
            Guest_LastGuest = NULL;
        }
        else{
            Selection->Next->Previous = NULL;
            Guest_FirstGuest = Guest_FirstGuest->Next;
        }
        free(Selection);
        GuestQuantity--;
    }
    else if(Selection == Guest_LastGuest){
        Selection->Previous->Next = NULL;
        Guest_LastGuest = Guest_LastGuest->Previous;
        free(Selection);
        GuestQuantity--;
    }
    else{
        Selection->Next->Previous = Selection->Previous;
        Selection->Previous->Next = Selection->Next;
        free(Selection);
        GuestQuantity--;
    }
}

//-------------------Setters and Getters---------------------

Guest* Guest_Get_Guest(int Selection){
    Guest *Pointer = Guest_FirstGuest;
    if(Selection < 1 || Selection > GuestQuantity)
        return NULL;
    else{
        for(int i = 2; i <= Selection; i++)
            Pointer = Pointer->Next;
        return Pointer;
    }
}

char* Guest_Get_Name(Guest * Pointer){
    return Pointer->Name;
}

char* Guest_Get_LastName(Guest * Pointer){
    return Pointer->LastName;
}

int Guest_Get_CI(Guest * Pointer){
    return Pointer->CI;
}

Time Guest_Get_TimeInput(Guest * Pointer){
        return Pointer->Input;
}

Time Guest_Get_TimeOutput(Guest * Pointer){
    return Pointer->Output;
}

int Guest_Get_Number(Guest * Pointer){
    return Pointer->Number;
}

char* Guest_Get_PayType(Guest * Pointer){
    return Pointer->PayType;
}

void Guest_Set_Name(Guest* Guest, char* Name){
    if(Guest == NULL)
        return;
    strcpy(Guest->Name, Name);
}

void Guest_Set_LastName(Guest * Guest, char* LastName){
    if(Guest == NULL)
        return;
    strcpy(Guest->LastName, LastName);
}

void Guest_Set_CI(Guest * Guest, int CI){
    if(Guest == NULL)
        return;
    Guest->CI = CI;
}

void Guest_Set_TimeInput(Guest * Guest, Time time){
    if(Guest == NULL)
        return;
    Time_Copy(&Guest->Input, time);
}

void Guest_Set_TimeOutput(Guest * Guest, Time time){
    if(Guest == NULL)
        return;
    Time_Copy(&Guest->Output, time);
}

void Guest_Set_Number(Guest * Guest, int Number){
    if(Guest == NULL)
        return;
    Guest->Number = Number;
}

void Guest_Set_PayType(Guest * Guest, char* PayType){
    if(Guest == NULL)
        return;
    strcpy(Guest->PayType, PayType);
}

//-------------------Search and Find---------------------

Guest* Guest_Search_CI(int CI){
    Guest * Pointer = Guest_FirstGuest;
    while(Pointer){
        if(Pointer->CI == CI)
            return Pointer;
        Pointer = Pointer->Next;
    }
    return NULL;
}

#endif /* Guest_H */