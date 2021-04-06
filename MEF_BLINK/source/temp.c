/*
 * brink.c
 *
 *  Created on: 8 abr. 2020
 *      Author: Joaquin
 */

#include <temp.h>
#include "SD2_board.h"

bool temp_enable = false;

//============ TEMPORIZADOR SECUENCIA =============//

int32_t temp;

int32_t Temp_get(void){return temp;}

void Temp_increase(void){
   if(temp_enable==true){
      temp++;
   }
}

void Temp_enable(void){
	temp_enable = true;
}

void Temp_disable(void){
	temp_enable = false;
}

//void Temp_set(int32_t tiempo){temp = tiempo;}

void Temp_reset(void){
	temp = 0;
}

//========================================//

//================== TEMPORIZADOR FRECUENCIA ==================//

int32_t temp_blink;
bool t_blink_enable = false;

int32_t Temp_blink_get(void){return temp_blink;}

void Temp_blink_reset(void){temp_blink = 0;}

//void T_blink_set(int32_t tiempo){T_Destello = tiempo;}

void Temp_blink_increase(void){
   if(t_blink_enable==true){
	   temp_blink++;
   }
}

void Temp_blink_enable(void){
	t_blink_enable = true;
}

void Temp_blink_disable(void){
	t_blink_enable = false;
}

//==================================================//


