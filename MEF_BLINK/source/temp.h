/*
 * brink.h
 *
 *  Created on: 8 abr. 2020
 *      Author: Joaquin
 */

#ifndef TEMP_H_
#define TEMP_H_
#include "SD2_board.h"

void Temp_increase(void);
//void Temp_set(int32_t);
void Temp_enable(void);
void Temp_disable(void);
int32_t Temp_get(void);
void Temp_reset(void);

//================== TEMPORIZADOR ==================//

int32_t Temp_blink_get(void);
void Temp_blink_reset(void);
//void T_blink_set(int32_t tiempo);
void Temp_blink_increase(void);
void Temp_blink_enable(void);
void Temp_blink_disable(void);
//==================================================//

#endif /* TEMP_H_ */
