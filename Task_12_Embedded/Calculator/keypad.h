/*
 * keypad.h
 *
 *  Created on: ??�/??�/????
 *      Author: Eng Hassan Sameh
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"


#define N_col 4
#define N_row 4


#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA


uint8 KeyPad_getPressedKey(void);



#endif /* KEYPAD_H_ */
