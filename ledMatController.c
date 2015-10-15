/**
 * @file ledMatController.c
 * @author Zachary Todd
 * @date 8 October 2015
 * @brief allows selection of a rows and columns 
 * within the led matrix of a UCFK4
 */
 
 
#include "pio.h"


/**
 * set all LEDs to high
 */
void ledsOff(void){
	pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_HIGH);
	pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_HIGH);
}

/**
 * set all LEDs to low
 */
void ledsOn(void){
	pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_LOW);
	pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_LOW);
}

/**
 * set the selected row of LEDs to low
 * @param row the row to set to low
 */
void setRow(int row){	
	switch(row){
		case 1:
			pio_output_low(LEDMAT_ROW1_PIO);
			break;
		case 2:
			pio_output_low(LEDMAT_ROW2_PIO);
			break;
		case 3:
			pio_output_low(LEDMAT_ROW3_PIO);
			break;
		case 4:
			pio_output_low(LEDMAT_ROW4_PIO);	
			break;
		case 5:
			pio_output_low(LEDMAT_ROW5_PIO);
			break;
		case 6:
			pio_output_low(LEDMAT_ROW6_PIO);
			break;
		case 7:
			pio_output_low(LEDMAT_ROW7_PIO);
			break;
	} 
}


/**
 * set the selected column of LEDs to low
 * @param col the column to set to low
 */
void setColumn(int col){	
	switch(col){
		case 1:
			pio_output_low(LEDMAT_COL1_PIO);
			break;
		case 2:
			pio_output_low(LEDMAT_COL2_PIO);
			break;
		case 3:
			pio_output_low(LEDMAT_COL3_PIO);
			break;
		case 4:
			pio_output_low(LEDMAT_COL4_PIO);
			break;	
		case 5:
			pio_output_low(LEDMAT_COL5_PIO);
			break;
	} 
}


/**
 * makes a tick shape
 */
void tick(void){
	setColumn(2);
	setRow(3);
	ledsOff();
	setColumn(3);
	setRow(4);
	ledsOff();
	setColumn(4);
	setRow(5);
	ledsOff();
	setColumn(3);
	setRow(6);
	ledsOff();
}


/**
 * makes a cross shape
 */
void cross(void){
	setColumn(2);
	setRow(3);
	setColumn(4);
	ledsOff();
	setRow(4);
	setColumn(3);
	ledsOff();
	setColumn(2);
	setRow(5);
	setColumn(4);
	ledsOff();
}