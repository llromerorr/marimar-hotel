#ifndef Room_H
#define Room_H

#include <string.h>
#include <stdlib.h>
#include "Reservation.h"
#include "Guest.h"
#include "Time.h"
#include <stdbool.h>

int RoomQuantity = 0;
int RoomFree = 0;

typedef struct Room{
    int     Number;
    char    Type[30];
    int     Cost;
    struct  Room* Next;
    struct  Room* Previous;
}Room;

Room* Room_FirstRoom;
Room* Room_LastRoom;

void Room_New(int Number, char* Type, int Cost){
    Room* NewItem = malloc(sizeof(Room));
    if(RoomQuantity == 0){
        Room_FirstRoom = NewItem;
        Room_LastRoom = NewItem;
        NewItem->Next = NULL;
        NewItem->Previous = NULL;
    }
    else{
        Room_LastRoom->Next = NewItem;
        NewItem->Previous = Room_LastRoom;
        Room_LastRoom = NewItem;
        NewItem->Next = NULL;
    }

    RoomQuantity++;
    NewItem->Number = Number;
    strcpy(NewItem->Type, Type);
    NewItem->Cost = Cost;
}

void Room_New_Null(){
    Room_New(0, "none", 0);
}

void Room_Show_All(){
    Room* p = Room_FirstRoom;
    for(int i = 1; p; i++){
        printf("%d) ", i);
        printf("%-4d\t", p->Number);
        printf("%-10s\t", p->Type);
        printf("%d\n", p->Cost);
        p = p->Next;
    }
}

void Room_Show_All_Reversed(){
    Room* p = Room_LastRoom;
    for(int i = RoomQuantity; p; i--){
        printf("%d) ", i);
        printf("%d\t", p->Number);
        printf("%s\t", p->Type);
        printf("%d\n", p->Cost);
        p = p->Previous;
    }
}

void Room_Show_Room(Room* Room){
    if(!Room)
        return;
    printf("%d\t", Room->Number);
    printf("%s\t", Room->Type);
    printf("%d\n", Room->Cost);
}

void Room_Memory_Clear(){
    Room* p = Room_FirstRoom;
    while(p){
        free(p);
        p = p->Next;
    }
    Room_FirstRoom = NULL;
    Room_LastRoom = NULL;
    RoomQuantity = 0;
}

void Room_File_Save(){
    Room* p = Room_FirstRoom;
    FILE* file = fopen("habitacion.in", "w");
    while(p){
        fprintf(file, "%d ", p->Number);
        fprintf(file, "%s\t", p->Type);
        fprintf(file, "%d\n", p->Cost);
        p = p->Next;
    }
    fclose(file);
}

void Room_File_Load(){
    //Check existence of file
    FILE* file = fopen("habitacion.in", "r");
    if(file == NULL){
        fclose(file);
        file = fopen("habitacion.in", "w");
        fclose(file);
        return;
    }
    //Check content file
    int count = 0;
    while(!feof(file)){
        fgetc(file);
        count++;
        if(count > 1)
            break;
    } 
    
    if(count == 1)
        return;
    else{
        rewind(file);
        Room_Memory_Clear();
    }

    //Start to read file
    int     Number;
    char    Type[50];
    int     Cost;

    while(!feof(file)){
        //read values
        fscanf(file, "%d\t", &Number);
        fscanf(file,"%s\t", Type);
        fscanf(file,"%d\n", &Cost);
        //save in memory
        Room_New(Number, Type, Cost);
        //reset values of variables in function    
        Number = 0;
        strcpy(Type, "none");
        Cost = 0;
    }
    fclose(file);
}

void Room_File_Clear(){
    FILE* file = fopen("habitacion.in", "w");
    fclose(file);
}

void Room_Delete_ByNumber(int Selection){
    Room *Pointer = NULL;

    if(Selection < 1 || Selection > RoomQuantity){
        return;
    }
    else if(Selection - 1 == 0){
        Pointer = Room_FirstRoom;
        if(RoomQuantity == 1){
            Room_FirstRoom = NULL;
            Room_LastRoom = NULL;
        }
        else{
            Pointer->Next->Previous = NULL;
            Room_FirstRoom = Room_FirstRoom->Next;
        }
        free(Pointer);
        RoomQuantity--;
    }
    else if(Selection == RoomQuantity){
        Pointer = Room_LastRoom;
        Pointer->Previous->Next = NULL;
        Room_LastRoom = Room_LastRoom->Previous;
        free(Pointer);
        RoomQuantity--;
    }
    else{
        Pointer = Room_FirstRoom;
        for(int i = 0; i < Selection - 1; i++){
            Pointer = Pointer->Next;
        }
        Pointer->Next->Previous = Pointer->Previous;
        Pointer->Previous->Next = Pointer->Next;
        free(Pointer);
        RoomQuantity--;
    }
}

void Room_Delete_ByPointer(Room * Selection){
    if(Selection == NULL){
        return;
    }
    else if(Selection == Room_FirstRoom){
        if(RoomQuantity == 1){
            Room_FirstRoom = NULL;
            Room_LastRoom = NULL;
        }
        else{
            Selection->Next->Previous = NULL;
            Room_FirstRoom = Room_FirstRoom->Next;
        }
        free(Selection);
        RoomQuantity--;
    }
    else if(Selection == Room_LastRoom){
        Selection->Previous->Next = NULL;
        Room_LastRoom = Room_LastRoom->Previous;
        free(Selection);
        RoomQuantity--;
    }
    else{
        Selection->Next->Previous = Selection->Previous;
        Selection->Previous->Next = Selection->Next;
        free(Selection);
        RoomQuantity--;
    }
}

void Room_Delete_ByAllPointers(Room ** Selection){
    for(int i = 0; Selection[i]; i++){
        Room_Delete_ByPointer(Selection[i]);
    }
}

//-------------------Setters and Getters---------------------

Room* Room_Get_ByNumber(int Selection){
    Room *Pointer = Room_FirstRoom;
    if(Selection < 1 || Selection > RoomQuantity)
        return NULL;
    else{
        for(int i = 2; i <= Selection; i++)
            Pointer = Pointer->Next;
        return Pointer;
    }
}

int Room_Get_Number_ByNumber(int Selection){
    Room *Pointer = Room_FirstRoom;
    if(Selection < 1 || Selection > RoomQuantity)
        return 0;
    else{
        for(int i = 2; i <= Selection; i++)
            Pointer = Pointer->Next;
        return Pointer->Number;
    }
}

char* Room_Get_Type_ByNumber(int Selection){
    Room *Pointer = Room_FirstRoom;
    if(Selection < 1 || Selection > RoomQuantity)
        return NULL;
    else{
        for(int i = 2; i <= Selection; i++)
            Pointer = Pointer->Next;
        return Pointer->Type;
    }
}

int Room_Get_Cost_ByNumber(int Selection){
    Room *Pointer = Room_FirstRoom;
    if(Selection < 1 || Selection > RoomQuantity)
        return 0;
    else{
        for(int i = 2; i <= Selection; i++)
            Pointer = Pointer->Next;
        return Pointer->Cost;
    }
}

void Room_Set_Number(int Selection, int Number){
    Room * Room = Room_Get_ByNumber(Selection);
    if(Room == NULL)
        return;
    Room->Number = Number;
}

void Room_Set_Type(int Selection, char* Type){
    Room * Room = Room_Get_ByNumber(Selection);
    if(Room == NULL)
        return;
    strcpy(Room->Type, Type);
}

void Room_Set_Cost(int Selection, int Cost){
    Room * Room = Room_Get_ByNumber(Selection);
    if(Room == NULL)
        return;
    Room->Cost = Cost;
}

//-------------------Search and Find---------------------

Room* Room_Search_ByNumber(int Number){
    Room * Pointer = Room_FirstRoom;
    while(Pointer){
        if(Pointer->Number == Number)
            return Pointer;
        Pointer = Pointer->Next;
    }
    return NULL;
}

int * Room_Get_RoomBusy(){
    Reservation_File_Load();
    Guest_File_Load();
    Room_File_Load();

    if((ReservationQuantity + GuestQuantity) == 0)
        return NULL;

    int *RoomUsed = (int*) malloc(sizeof(int) * (ReservationQuantity + GuestQuantity) + 1);

    if(ReservationQuantity){
        Reservation * Reservation_Pointer = Reservation_FirstReservation;
        for(int i = 0; i < ReservationQuantity; i++){
            RoomUsed[i] = Reservation_Pointer->Number;
            Reservation_Pointer = Reservation_Pointer->Next;
        }
    }

    if(GuestQuantity){
        Guest * Guest_Pointer = Guest_FirstGuest;
        for(int i = ReservationQuantity; i < (GuestQuantity + ReservationQuantity); i++){
            RoomUsed[i] = Guest_Pointer->Number;
            Guest_Pointer = Guest_Pointer->Next;
        }
    }

    RoomUsed[ReservationQuantity + GuestQuantity] = 0;
    return RoomUsed;
}

int * Room_Get_RoomFree(){
    Reservation_File_Load();
    Guest_File_Load();
    Room_File_Load();

    if((ReservationQuantity + GuestQuantity) == 0)
        return NULL;

    int *RoomUsed = (int*) malloc(sizeof(int) * (ReservationQuantity + GuestQuantity));
    int *RoomFree = (int*) malloc(sizeof(int) * (RoomQuantity - (ReservationQuantity + GuestQuantity) + 1));

    if(ReservationQuantity){
        Reservation * Reservation_Pointer = Reservation_FirstReservation;
        for(int i = 0; i < ReservationQuantity; i++){
            RoomUsed[i] = Reservation_Pointer->Number;
            Reservation_Pointer = Reservation_Pointer->Next;
        }
    }

    if(GuestQuantity){
        Guest * Guest_Pointer = Guest_FirstGuest;
        for(int i = ReservationQuantity; i < (GuestQuantity + ReservationQuantity); i++){
            RoomUsed[i] = Guest_Pointer->Number;
            Guest_Pointer = Guest_Pointer->Next;
        }
    }

    Room * Room_Pointer = Room_FirstRoom;
    int RoomFreeQuantity = 0;
    
    for(int i = 0; Room_Pointer; i++){
        bool used = false;

        for(int i = 0; i < (GuestQuantity + ReservationQuantity); i++){
            if(Room_Pointer->Number == RoomUsed[i]){
                used = true;
                break;
            }
        }

        if(!used){
            RoomFree[RoomFreeQuantity] = Room_Pointer->Number;
            RoomFreeQuantity++;
            used = false;
        }

        Room_Pointer = Room_Pointer->Next;
    }
    if(RoomFreeQuantity == 0)
        return NULL;
    RoomFree[RoomFreeQuantity] = 0;

    return RoomFree;
}

int Room_Get_RoomFree_Quantity(){
    int RoomsFree = 0;
    int * Pointer = Room_Get_RoomFree();
    
    for(int i = 0; Pointer[i]; i++)
        RoomsFree++;
    
    return RoomsFree;
}

#endif /* Room_H */
