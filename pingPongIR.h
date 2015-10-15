/**
 * @file pingPongIR.c
 * @author Zachary Todd
 * @date 11 October 2015
 * @brief the IR for the ping pong game
 */


#ifndef PINGPONGIR_H
#define PINGPONGIR_H

#include "ir_uart.h"
#include "ballMovement.h"

#define INT_SIZE 4
#define PACKET_MASK 15

/**
 * packs the ball in the format: player, 0, previous row, current row
 * @param currBall the ball to be packet
 * @param player the player sending the ball
 * @return the a ball as  uint8_t
 */
uint8_t packBall(ball currBall, int player, int seqNo);

/**
 * unpacket to typeball
 * @param BallInfo the information to be unpacket
 * @return the unpacket ball
 * 
 */
ball unpackBall(uint8_t ballInfo);
#endif