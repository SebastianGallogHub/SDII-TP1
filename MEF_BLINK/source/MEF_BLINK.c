/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    MEF_BLINK.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL46Z4.h"
#include "fsl_debug_console.h"

#include "SD2_board.h"
#include "temp.h"


#define T_BLINK 200

void mefBlink(board_ledId_enum);

void main(void) {

	// Se inicializan funciones de la placa
	board_init();
	/* inicializa interrupciÃ³n de systick cada 1 ms */
	SysTick_Config(SystemCoreClock / 1000U);

	Temp_blink_disable();

    while(1) {

    	mefBlink(BOARD_LED_ID_ROJO_LRR);

    	/* POSIBLES VALORES A PASAR COMO ARGUMENTO A LA MEF BLINK
    	 *
    	 	BOARD_LED_ID_ROJO_LRR
    		BOARD_LED_ID_VERDE_LVR
			EXTERNAL_LED_ID_ROJO_LRS   ----> Conectado al pin PORTE22 (de forma tal que se encienda con un cero logico)
			EXTERNAL_LED_ID_VERDE_LVS  ----> Conectado al pin PORTE23 (de forma tal que se encienda con un cero logico)

    	 */

    }

}

typedef enum{
	EST_MEF_BLINK_INICIO = 1,
	EST_MEF_BLINK_ENCENDIENDO,
	EST_MEF_BLINK_APAGANDO,
}estMefBlink_enum;

void mefBlink(board_ledId_enum led_select){

	static estMefBlink_enum estMefBlink = EST_MEF_BLINK_INICIO;

		switch(estMefBlink){

		case EST_MEF_BLINK_INICIO:

			board_setLed(led_select,BOARD_LED_MSG_ON);
			Temp_blink_reset();
			Temp_blink_enable();

			estMefBlink = EST_MEF_BLINK_ENCENDIENDO;

			break;
		case EST_MEF_BLINK_ENCENDIENDO:

			if(Temp_blink_get()==T_BLINK){

				board_setLed(led_select,BOARD_LED_MSG_OFF);
				Temp_blink_reset();
				estMefBlink = EST_MEF_BLINK_APAGANDO;

			}

			break;
		case EST_MEF_BLINK_APAGANDO:

			if(Temp_blink_get()==T_BLINK){

				board_setLed(led_select,BOARD_LED_MSG_ON);
				Temp_blink_reset();
				estMefBlink = EST_MEF_BLINK_ENCENDIENDO;

			}

			break;

		}
}

void SysTick_Handler(void)
{
	Temp_blink_increase();
}
