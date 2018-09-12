int rightEncoderTarget = 0;
int leftEncoderTarget = 0;
bool rightEncoderReached = false;
bool leftEncoderReched = false;


task rightForwardEncoderTest(){

	waitUntil(SensorValue[rightEncoder] > rightEncoderTarget);
	motor[RightDrive1] = 0;
	motor[RightDrive2] = 0;
	motor[RightDrive3] = 0;
	rightEncoderReached = true;
}

task rightBackwardEncoderTest(){

	waitUntil(SensorValue[rightEncoder] < rightEncoderTarget);
	motor[RightDrive1] = 0;
	motor[RightDrive2] = 0;
	motor[RightDrive3] = 0;
	rightEncoderReached = true;
}


task leftForwardEncoderTest(){

	waitUntil(SensorValue[leftEncoder] > leftEncoderTarget);
	motor[LeftDrive1] =  0;
	motor[LeftDrive2] =  0;
	motor[LeftDrive3] = 0;
	leftEncoderReched = true;
}

task leftBackwardEncoderTest(){

	waitUntil(SensorValue[leftEncoder] < leftEncoderTarget);
	motor[LeftDrive1] =  0;
	motor[LeftDrive2] =  0;
  motor[LeftDrive3] = 0;
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
		leftEncoderTarget = -leftTarget;
		rightEncoderTarget = rightTarget;


		//set motors in the proper direction
		motor[LeftDrive1] =  -127;
		motor[LeftDrive2] =  -127;
		motor[LeftDrive3] = -127;
		motor[RightDrive1] = 127;
		motor[RightDrive2] = 127;
		motor[RightDrive3] = 127;


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
		rightEncoderTarget = -rightTarget;


		//set motors in proper direction
		motor[LeftDrive1] =  127;
		motor[LeftDrive2] =  127;
		motor[LeftDrive3] = 127;

		motor[RightDrive1] = -127;
		motor[RightDrive2] = -127;
		motor[RightDrive3] = -127;

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

		if(leftTarget > 0 && rightTarget > 0){
		//set motors in proper direction
		motor[LeftDrive1] =  127;
		motor[LeftDrive2] =  127;
	  motor[LeftDrive3] =  127;
		motor[RightDrive1] = 127;
		motor[RightDrive2] = 127;
		motor[RightDrive3] = 127;


		//when the encoders return the results, then stop the tasks, and end the function
		startTask(rightForwardEncoderTest);
		startTask(leftForwardEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightForwardEncoderTest);
		stopTask(leftForwardEncoderTest);
		return;
	}
	else if(leftTarget < 0 && rightTarget < 0)
		//set motors in proper direction
		motor[LeftDrive1] =  -127;
		motor[LeftDrive2] =  -127;
	  motor[LeftDrive3] =  -127;
		motor[RightDrive1] = -127;
		motor[RightDrive2] = -127;
		motor[RightDrive3] = -127;

		//when the encoders return the results, then stop the tasks, and end the function
		startTask(rightBackwardEncoderTest);
		startTask(leftBackwardEncoderTest);
		waitUntil(rightEncoderReached == true && leftEncoderReched == true);
		stopTask(rightBackwardEncoderTest);
		stopTask(leftBackwardEncoderTest);
		return;

}
