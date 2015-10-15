/**
 * @file ballMovement.c 
 * @author Zachary Todd
 * @date 8 October 2015
 * @brief simple ball simulation with a bowl shaped paddle 
 */

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
ball initBall(void){
	ball newBall;
	newBall.column = 1;
	newBall.row = INIT_BALL_POSITION;
	newBall.angle = 0;
	newBall.direction = 1;
	return newBall;
}

/**
 * checks if the ball hits the paddle 
 * @param currBall the current ball's information
 * @param paddlePos the current paddle position
 * @return 1 if the ball hits the paddle and 0 if it doesnt
 */ 
int isPaddleHit(ball currBall, int paddlePos){
	return currBall.row == paddlePos - 1 || 
		currBall.row == paddlePos + 1 || currBall.row == paddlePos;
}

/**
 * moves the ball based on its current information
 * @param currBall the current ball information
 * @return the ball with update infomation
 */
ball moveBall(ball currBall){
	currBall.column += currBall.direction;
	currBall.row += currBall.angle;
	return currBall;
}

/**
 * update the balls angle based on where hits the paddle
 * @param currBall the current ball
 * @param paddlePos the current paddle position
 * @return the update ball
 */ 
ball angleUpdateOnPaddleHit(ball currBall, int paddlePos){
	if(currBall.angle == 0){
		currBall.angle = paddlePos - currBall.row;
	}else if(currBall.angle == paddlePos - currBall.row){
		currBall.angle = 0;
	}
	return currBall;
}

/**
 * checks if the ball hit the paddle and updates the
 * ball 
 * @param currBall the current ball
 * @param paddlePos the current paddle position
 * @return the update ball
 */ 
ball updateOnPaddleCollision(ball currBall, int paddlePos){
	if(currBall.column == PADDLE_LOCATION
		&& isPaddleHit(currBall, paddlePos)){
		currBall.direction *= -1;
		currBall = angleUpdateOnPaddleHit(currBall, paddlePos);
	}
	return currBall;
}

/**
 * changes the angle of the ball if it his a wall
 * @param currBall the current ball's information
 * @return the update ball
 */
ball updateOnHittingWall(ball currBall){
	if(currBall.row == MAX_ROW || currBall.row == 1 ){
		currBall.angle *= -1;
	}
	//used in a single 
	//if(currBall.column == 1){
		//currBall.direction = 1;
	//}
	return currBall;
}

/**
 * updates the ball based on its current information
 * @param currBall the current ball information
 * @param paddlePos the current paddle position
 * @return the ball with update infomation
 */
ball updateBall(ball currBall, int paddlePos){
	currBall = updateOnPaddleCollision(moveBall(currBall), paddlePos);
	currBall = updateOnHittingWall(currBall);
	return currBall;	
}


/**
 * checks if the ball misses the paddle
 * @param currBall the current ball's information
 * @param paddlePos the current paddle position
 * @return 0 if the ball hits the paddle and 0 if it does not
 */
int isPaddleMissed(ball currBall, int paddlePos){
	if(currBall.column == PADDLE_LOCATION && 
		! isPaddleHit(currBall, paddlePos)){
		return 0;
	}
	return 1;
}