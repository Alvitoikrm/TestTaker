#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <omp.h>
#include "ProsesSoal.h"

int main(){
	int TIME = 0*60 + 15; // M : S
	int ujian_berlangsung = 1;
	int *FLAG = &ujian_berlangsung;
	
	system("cls"); // clear screen
	
	// current issue:
	// 1. (possible) racing antara timer dan proses ujian
	// 2. install clear screen pas enter di pencet
	#pragma omp parallel sections
	{
		#pragma omp section 
        { 
            timer(TIME, FLAG);
        }
        #pragma omp section
        { // ############ PROSES UJIAN ###############
        	Sleep(100); // sleep sementara supaya timer di print duluan 	
			while(ujian_berlangsung){ 


				Sleep(50); 
			}
        } // ############ PROSES UJIAN ###############	
	}

	return 0;
}

