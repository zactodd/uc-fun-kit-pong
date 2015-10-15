/**
 * @file ledMatController.h
 * @author Zachary Todd
 * @date 8 October 2015
 * @brief allows selection of a rows and columns 
 * within the led matrix of a UCFK4
 */


#ifndef LEDMATCONTROLLER_H
#define LEDMATCONTROLLER_H

#include "pio.h"



/**
 * set all LEDs to high
 */
void ledsOff(void);

/**
 * set all LEDs to low
 */
void ledsOn(void);

/**
 * set the selected row of LEDs to low
 * @param row the row to set to low
 */
void setRow(int row);


/**
 * set the selected column of LEDs to low
 * @param col the column to set to low
 */
void setColumn(int col);


/**
 * makes a tick shape
 */
void tick(void);


/**
 * makes a cross shape
 */
void cross(void);
#endif