/**
 * @file pingPongIR.c
 * @author Zachary Todd
 * @date 11 October 2015
 * @brief the IR for the ping pong game
 */

#include "ir_uart.h"
#include "ballMovement.h"

#define INT_SIZE 3
#define PACKET_MASK 7

/**
 * packs the ball in the format: player, 0, previous row, current row
 * @param currBall the ball to be packet
 * @param player the player sending the ball
 * @return the a ball as  uint8_t
 */
uint8_t packBall(ball currBall,int player, int seqNo){
	uint8_t ballInfo = currBall.row << INT_SIZE;
	ballInfo |= PACKET_MASK;
	ballInfo &= ~( ~updateBall(currBall, 0).row & PACKET_MASK);//
	ballInfo |= seqNo << 6;
	ballInfo |= player << PACKET_MASK;
	return ballInfo;
}

/**
 * unpacket to typeball
 * @param BallInfo the information to be unpacket
 * @return the unpacket ball
 * 
 */
ball unpackBall(uint8_t ballInfo){
	ball newBall = initBall();
	newBall.row = ballInfo & PACKET_MASK;
	newBall.angle = ((ballInfo >> INT_SIZE) & PACKET_MASK) - (ballInfo & PACKET_MASK) ;//
	if (newBall.angle < -1) {
		newBall.angle = -1;
	} else if(newBall.angle > 1) {
		newBall.angle = 1;
	}
	return newBall; 
}