/**
 * @file ballMovement.h
 * @author Zachary Todd
 * @date 8 October 2015
 * @brief simple ball simulation with a bowl shaped paddle 
 */
 
 
#ifndef BALL_H
#define BALL_H

#define INIT_BALL_POSITION 4
#define PADDLE_LOCATION 5
#define MAX_ROW 7
#define MAX_COLUMN 5

/**
 * ball structure containing the row position , 
 * column position angle and direction 
 */
typedef struct {
	int column;
	int row;
	int angle;
	int direction;
}ball;


/**
 * create a ball with init row and column as well as 
 * seting the angle to 0 and the direction to 1
 * @return the inital ball
 */
ball initBall(void);


/**
 * checks if the ball hits the paddle 
 * @param currBall the current ball's information
 * @param paddlePos the current paddle position
 * @return 1 if the ball hits the paddle and 0 if it doesnt
 */ 
int isPaddleHit(ball currBall, int paddlePos);


/**
 * moves the ball based on its current information
 * @param currBall the current ball information
 * @return the ball with update infomation
 */
ball moveBall(ball currBall);


/**
 * update the balls angle based on where hits the paddle
 * @param currBall the current ball
 * @param paddlePos the current paddle position
 * @return the update ball
 */ 
ball angleUpdatePaddleHit(ball currBall, int paddlePos);


/**
 * checks if the ball hit the paddle and updates the
 * ball 
 * @param currBall the current ball
 * @param paddlePos the current paddle position
 * @return the update ball
 */ 
ball updateOnPaddleCollision(ball currBall, int paddlePos);


/**
 * changes the angle of the ball if it his a wall
 * @param currBall the current ball's information
 * @return the update ball
 */
ball updateOnHittingWall(ball currBall);


/**
 * updates the ball based on its current information
 * @param currBall the current ball information
 * @param paddlePos the current paddle position
 * @return the ball with update infomation
 */
ball updateBall(ball currBall, int paddlePos);


/**
 * checks if the ball misses the paddle
 * @param currBall the current ball's information
 * @param paddlePos the current paddle position
 * @return 0 if the ball hits the paddle and 0 if it does not
 */
int isPaddleMissed(ball currBall, int paddlePos);
#endif