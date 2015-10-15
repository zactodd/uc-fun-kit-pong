/**
 * @file game.c
 * @author Zachary Todd
 * @date 8 October 2015
 * @brief ping pong on UCFK04
 */
 
 
#include "pio.h"
#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "pacer.h"
#include "ballMovement.h"
#include "pingPongInteraction.h"
#include "pingPongIR.h"

#define LED_PIO PIO_DEFINE(PORT_C, 2)
#define INIT_PADDLE_POSETION 4
#define BAll_UPDATE_RATE 39
#define INIT_BALL_SPEED 1200
#define MAX_BALL_SPEED 300
#define BALL_SPEED_UPDATE 0.9
#define START_CODE 128

/**
 * update the balls speed
 * @param currSpeed the current speed of the ball 
 * @return the new ball speed
 */
int updateBallSpeed(int currSpeed){
	int speed = currSpeed * BALL_SPEED_UPDATE;
	if(speed <= MAX_BALL_SPEED){
		speed = MAX_BALL_SPEED;
	}
	return speed;
}


/**
 * initalizes the rally
 */
void initRally(void){
	setPaddlePosition(INIT_PADDLE_POSETION);
}


/**
 * initalizes the game
 */
void initGame(void){
	system_init();
	navswitch_init();
	initRally();
	ir_uart_init();
}


/**
 * plays the game
 * @param player used to deterimine starting position
 */
void playGame(int player){
	int paddlePos = INIT_PADDLE_POSETION;
	ball gameBall = initBall(); 
	int loops = 0;
	int ballSpeed = INIT_BALL_SPEED;
	int inPlay = 1;
	int isntFinalDisplay = 1;
	int	 hasData = player;
	int seqNo = 0;
	if(! hasData){
		gameBall.column = -1;
	}
	while (inPlay){
		paddlePos = updatePaddle(paddlePos);
		if(hasData){	
			if(loops++ > ballSpeed){
				gameBall = updateBall(gameBall, paddlePos);
				loops = 0;
				inPlay = isntFinalDisplay;
				isntFinalDisplay = isPaddleMissed(gameBall, paddlePos);	
			}
		}else{
			//recives data 
			if(ir_uart_read_ready_p()){
				uint8_t ballData = ir_uart_getc();
				if(ballData >> 6 != (player << 1 | seqNo)
				   && (ballData & 7) > -1 && (ballData & 7) < 7
				   && ((ballData >> 3) & 7) > -1 && ((ballData >> 3) & 7) < 7 ){
						gameBall = unpackBall(ballData);
						hasData = 1;
						seqNo = 1 - seqNo; 
						pio_output_toggle(LED_PIO);
				}
			}
		}
		if(gameBall.column == 0){
			//sends data
			if(ir_uart_write_ready_p()){
				pio_output_toggle(LED_PIO);
				ir_uart_putc(packBall(gameBall, player, seqNo));
				hasData = 0;
			}
		}
		displayBall(gameBall);
	}
}


int main (void)
{	
	initGame();
	playGame(1);
	return 0;
}