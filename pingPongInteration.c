/**
 * @file pingPongInteration.c
 * @author Zachary Todd
 * @date 8 October 2015
 * @brief interaction between the user and the display
 */
 
 
#include "navswitch.h"
#include "pio.h"
#include "ledMatController.h"
#include "ballMovement.h"

#define PADDLE_MIN 2
#define PADDLE_MAX 6



/**
 * displays the paddle musing a selected paddle position
 * @param pos the position to be set
 */
void setPaddlePosition(int pos){
	setColumn(PADDLE_LOCATION);
	switch(pos){
		case 2:
			pio_output_low(LEDMAT_ROW1_PIO);
			pio_output_low(LEDMAT_ROW2_PIO);
			pio_output_low(LEDMAT_ROW3_PIO);
			break;
		case 3:
			pio_output_low(LEDMAT_ROW2_PIO);
			pio_output_low(LEDMAT_ROW3_PIO);
			pio_output_low(LEDMAT_ROW4_PIO);
			break;
		case 4:
			pio_output_low(LEDMAT_ROW3_PIO);
			pio_output_low(LEDMAT_ROW4_PIO);
			pio_output_low(LEDMAT_ROW5_PIO);
			break;
		case 5:
			pio_output_low(LEDMAT_ROW4_PIO);
			pio_output_low(LEDMAT_ROW5_PIO);
			pio_output_low(LEDMAT_ROW6_PIO);
			break;
		case 6:
			pio_output_low(LEDMAT_ROW5_PIO);
			pio_output_low(LEDMAT_ROW6_PIO);
			pio_output_low(LEDMAT_ROW7_PIO);
			break;
	} 
	ledsOff();
}


/**
 * displays the current ball based on it's row and column
 * @param currBall the current ball
 */
void displayBall(ball currBall){
	setColumn(currBall.column);
	setRow(currBall.row);
	ledsOff();
}

	
/**
 * displays the paddle base on the navswitch
 * @param paddlePos the current paddle position
 * @return the new paddle position
 */
int updatePaddle(int paddlePos){
	navswitch_update();
	if (navswitch_push_event_p (NAVSWITCH_NORTH) && paddlePos > 
		PADDLE_MIN){;
		setPaddlePosition(--paddlePos);
	}
    else if (navswitch_push_event_p (NAVSWITCH_SOUTH) && 
		paddlePos < PADDLE_MAX){
        setPaddlePosition(++paddlePos);
    } else {
		setPaddlePosition(paddlePos);
	}
    return paddlePos;
}