/**
 * @file pingPongInteration.h
 * @author Zachary Todd
 * @date 8 October 2015
 * @brief interaction between the user and the display
 */


#ifndef PINGPONGINTERACTION_H
#define PINGPONGINTERACTION_H


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
void setPaddlePosition(int pos);


/**
 * displays the current ball based on it's row and column
 * @param currBall the current ball
 */
void displayBall(ball currBall);


/**
 * displays the paddle base on the navswitch
 * @param paddlePos the current paddle position
 * @return the new paddle position
 */
int updatePaddle(int paddlePos);
#endif