#include "headers/Reservation.h"
#include "headers/Charge.h"
#include "headers/Application.h"

int main(void){
    Charge_File_Load();
    Charge_Delete_ByAllPointers(Charge_Search_CI_ByAllPointers(3654876));
    Charge_File_Save();
    Charge_Show_All();
    puts("\nAll is ok :D");
    return 0;
}