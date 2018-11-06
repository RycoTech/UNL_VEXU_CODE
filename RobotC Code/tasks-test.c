
#include"VexU2017-18V5-main.c"
bool leftLineReached = false;
bool rightLineReached = false;
int rightEncoderTarget = 0;
int leftEncoderTarget = 0;
bool rightEncoderReached = false;
bool leftEncoderReched = false;
int targetLiftPosition = 0;
int leftLiftPosition = 1;
int rightLiftPosition = 1;
int highLiftSpeed;

task lineLeftTest(){
	leftLineReached = false;
while(true){
  	if(SensorValue[frontLeftLine] < 2000){
 			motor[driveTrainLeft] = 0;
 			leftLineReached = true;
 			break;
		}
	}
}


task lineRightTest(){
rightLineReached = false;
	while(true){
  	if(SensorValue[frontRightLine] < 2000){
 			motor[driveTrainRight] = 0;
 			rightLineReached = true;
 			break;
		}
	}
}

task rightForwardEncoderTest(){

	waitUntil(SensorValue[rightEncoder] < rightEncoderTarget);
	motor[driveTrainRight] = 0;
	rightEncoderReached = true;
}

task rightBackwardEncoderTest(){

	waitUntil(SensorValue[rightEncoder] > rightEncoderTarget);
	motor[driveTrainRight] = 0;
	rightEncoderReached = true;
}


task leftForwardEncoderTest(){

	waitUntil(SensorValue[leftEncoder] < leftEncoderTarget);
	motor[driveTrainLeft] = 0;
	leftEncoderReched = true;
}

task leftBackwardEncoderTest(){

	waitUntil(SensorValue[leftEncoder] > leftEncoderTarget);
	motor[driveTrainLeft] = 0;
	leftEncoderReched = true;
}



void turnLeft(int leftTarget, int rightTarget){


		//reset encoder results flag
		rightEncoderReached = false;
		leftEncoderReched = false;

		//reset encoders
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;

		//set encoder targets
		leftEncoderTarget = leftTarget;
		rightEncoderTarget = rightTarget;


		//set motors in the proper direction
		motor[driveTrainLeft] = -127;
		motor[driveTrainRight] = 127;


		//startEncoders for testing
		startTask(leftBackwardEncoderTest);
		startTask(rightForwardEncoderTest);

		//when the encoders return the results, then stop the tasks, and end the function
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightBackwardEncoderTest);
		stopTask(leftForwardEncoderTest);
		return;
}

void turnRight(int leftTarget, int rightTarget){

		//reset encoder results
		rightEncoderReached = false;
		leftEncoderReched = false;

		//reset encoder values
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;

		//set encoder targets
		leftEncoderTarget = leftTarget;
		rightEncoderTarget = rightTarget;


		//set motors in proper direction
		motor[driveTrainLeft] = 127;
		motor[driveTrainRight] = -127;

		//when the encoders return the results, then stop the tasks, and end the function
		startTask(leftForwardEncoderTest);
		startTask(rightBackwardEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightForwardEncoderTest);
		stopTask(leftBackwardEncoderTest);
		return;
}

void strait(int leftTarget, int rightTarget){
		//reset encoder results
		rightEncoderReached = false;
		leftEncoderReched = false;

		//reset encoder values
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;

		//set encoder targets
		rightEncoderTarget = rightTarget;
		leftEncoderTarget = leftTarget;

		if(leftTarget < 0 && rightTarget < 0){
		//set motors in proper direction
		motor[driveTrainLeft] = 127;
		motor[driveTrainRight] = 127;

		//when the encoders return the results, then stop the tasks, and end the function
		startTask(rightForwardEncoderTest);
		startTask(leftForwardEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightForwardEncoderTest);
		stopTask(leftForwardEncoderTest);
		return;
	}
	else if(leftTarget > 0 && rightTarget > 0)
		//set motors in proper direction
		motor[driveTrainLeft] = -127;
		motor[driveTrainRight] = -127;

		//when the encoders return the results, then stop the tasks, and end the function
		startTask(rightBackwardEncoderTest);
		startTask(leftBackwardEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightBackwardEncoderTest);
		stopTask(leftBackwardEncoderTest);
		return;

}


//LIFT CONTOL TASKS
//controls the left side of the high lift
task leftHighLift(){
			if(targetLiftPosition == 3){ //Hight state
				//goes up
			while(SensorValue[liftAngleLeft] < 910);{
				motor[liftMobileHigherLeft] = highLiftSpeed;
				if(mobileForward){
					motor[port8] = vexRT[Ch3];
					motor[port2] = vexRT[Ch2];
				}
				else{
					motor[port8] = -(vexRT[Ch2]);
					motor[port2] = -(vexRT[Ch3]);
				}
			}
				motor[liftMobileHigherLeft] = 0;
				rightLiftPosition = 3;
			}
		else if(targetLiftPosition == 1){
			//goes down
			while(SensorValue[liftAngleLeft] > 2200){
				motor[liftMobileHigherLeft] = -highLiftSpeed;
				if(mobileForward){
					motor[port8] = vexRT[Ch3];
					motor[port2] = vexRT[Ch2];
				}
				else{
					motor[port8] = -(vexRT[Ch2]);
					motor[port2] = -(vexRT[Ch3]);
				}
			}
			// set motor speed to zero once requested distance is reached.
			leftLiftPosition = 1;
			motor[liftMobileHigherLeft] = 0;
		}
		else if(leftLiftPosition == 3 && targetLiftPosition == 2){ //middle state going down

		while(SensorValue[liftAngleLeft] > 1955){
			motor[liftMobileHigherLeft] = -highLiftSpeed;
			if(mobileForward){
				motor[port8] = vexRT[Ch3];
				motor[port2] = vexRT[Ch2];
			}
			else{
				motor[port8] = -(vexRT[Ch2]);
				motor[port2] = -(vexRT[Ch3]);
			}
		}

		// set motor speed zero once requested distance is reached.
		motor[liftMobileHigherLeft] = 0;
		leftLiftPosition = 2;

		}else if(leftLiftPosition == 1 && targetLiftPosition == 2){ //middle state going up
		while(SensorValue[liftAngleLeft] < 1955){
			motor[liftMobileHigherLeft] = highLiftSpeed;
			if(mobileForward){
				motor[port8] = vexRT[Ch3];
				motor[port2] = vexRT[Ch2];
			}
			else{
				motor[port8] = -(vexRT[Ch2]);
				motor[port2] = -(vexRT[Ch3]);
			}
		}

		// set motor speed equal to zero once requested distance is reached.
		motor[liftMobileHigherRight] = 0;
		rightLiftPosition = 2;
		}

}



//controls the right side of the high lift
task rightHighLift(){
			if(targetLiftPosition == 3){ //Hight state
				//goes up
			while(SensorValue[liftAngleRight] < 910);{
				motor[liftMobileHigherRight] = highLiftSpeed;
				if(mobileForward){
					motor[port8] = vexRT[Ch3];
					motor[port2] = vexRT[Ch2];
				}
				else{
					motor[port8] = -(vexRT[Ch2]);
					motor[port2] = -(vexRT[Ch3]);
				}
			}
				motor[liftMobileHigherRight] = 0;
				rightLiftPosition = 3;
			}
		else if(targetLiftPosition == 1){
			//goes down
			while(SensorValue[liftAngleRight] > 2200){
				motor[liftMobileHigherRight] = -highLiftSpeed;
				if(mobileForward){
					motor[port8] = vexRT[Ch3];
					motor[port2] = vexRT[Ch2];
				}
				else{
					motor[port8] = -(vexRT[Ch2]);
					motor[port2] = -(vexRT[Ch3]);
				}
			}
			// set motor speed to zero once requested distance is reached.
			rightLiftPosition = 1;
			motor[liftMobileHigherRight] = 0;
		}
		else if(rightLiftPosition == 3 && targetLiftPosition == 2){ //middle state going down

		while(SensorValue[liftAngleRight] > 1955){
			motor[liftMobileHigherRight] = -highLiftSpeed;
			if(mobileForward){
				motor[port8] = vexRT[Ch3];
				motor[port2] = vexRT[Ch2];
			}
			else{
				motor[port8] = -(vexRT[Ch2]);
				motor[port2] = -(vexRT[Ch3]);
			}
		}

		// set motor speed zero once requested distance is reached.
		motor[liftMobileHigherRight] = 0;
		rightLiftPosition = 2;

		}else if(rightLiftPosition == 1 && targetLiftPosition == 2){ //middle state going up
		while(SensorValue[liftAngleRight] < 1955){
			motor[liftMobileHigherRight] = highLiftSpeed;
			if(mobileForward){
				motor[port8] = vexRT[Ch3];
				motor[port2] = vexRT[Ch2];
			}
			else{
				motor[port8] = -(vexRT[Ch2]);
				motor[port2] = -(vexRT[Ch3]);
			}
		}

		// set motor speed equal to zero once requested distance is reached.
		motor[liftMobileHigherRight] = 0;
		rightLiftPosition = 2;
		}

}


//start function for lift
void highLift(int targetHight,int speed){
	highLiftSpeed = speed;
	targetLiftPosition = targetHight;
	startTask(rightHighLift);
	startTask(leftHighLift);

	waitUntil(rightLiftPosition == targetLiftPosition && leftLiftPosition == targetLiftPosition);
	stopTask(rightHighLift);
	stopTask(leftHighLift);
	return;
}

task LowLiftUp(){
	while(SensorValue[lowerMobileGoalLimitUP] == 0){
		motor[liftMobileLowerLeft] = 127;
		motor[liftMobileLowerRight] = 127;
	}
	motor[liftMobileLowerLeft] = 0;
	motor[liftMobileLowerRight] = 0;
	stopTask(LowLiftUp);
}

task leftLowLiftDown(){
	while(SensorValue[leftLowMGDown] == 0){
		motor[liftMobileLowerLeft] = -30;
	}
	motor[liftMobileLowerLeft] = 0;
	stopTask(leftLowLiftDown);
}

task rightLowLiftDown(){
	while(SensorValue[rightLowMGDown] == 0){
		motor[liftMobileLowerRight] = -30;
	}
	motor[liftMobileLowerRight] = 0;
	stopTask(rightLowLiftDown);
}
