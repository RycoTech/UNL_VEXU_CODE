#include "autonTasks.c"
task autonomous()
{
	bool leftReached = false;
	bool rightReached = false;


//lift the high lift
startTask(leftLiftUp);
startTask(rightLiftUp);

//drive until first mobile goal
	//left
	motor[LeftDrive1] =  127;
	motor[LeftDrive2] =  127;
	motor[LeftDrive3] =  127;

	//right
	motor[RightDrive1] = 80;
	motor[RightDrive2] = 80;
	motor[RightDrive3] = 80;

	waitUntil(SensorValue[LowerMGIn] == 1);
	wait1Msec(200);
	motor[LeftDrive1] =  0;
	motor[LeftDrive2] =  0;
	motor[LeftDrive3] =  0;
	//right
	motor[RightDrive1] = 0;
	motor[RightDrive2] = 0;
	motor[RightDrive3] = 0;


//pick up first moblile goal
	startTask(rightLiftDown);
	startTask(leftLiftDown);
	wait1Msec(100);

	motor[LeftLowerMG] = 127;
	motor[RightLowerMG] = 127;
			//lower high lift

	waitUntil(SensorValue[LowerMGUp]);
	motor[LeftLowerMG] = 0;
	motor[RightLowerMG] = 0;





	//left
	motor[LeftDrive1] =  127;
	motor[LeftDrive2] =  127;
	motor[LeftDrive3] =  127;
	//right
	motor[RightDrive1] = 85;
	motor[RightDrive2] = 85;
	motor[RightDrive3] = 85;




//pick up second moble goal
	waitUntil(SensorValue(HighMGIn));



//lift upper moble goal
	startTask(rightLiftUp);
	startTask(leftLiftUp);


	wait1Msec(1000);

	//drive until the line
	startTask(lineLeftTest);
	startTask(lineRightTest);

	waitUntil(rightLineReached && leftLineReached);
// go to center
		//45 degree turn left
		//(left target, right target)


		turnLeft(200, 200);
		wait10Msec(100);

		//go forward

		strait(425, 425);
		wait10Msec(100);

		//45 degree turn right
		turnRight(250, 250);
		wait10Msec(100);

		//go forward
	//left
	motor[LeftDrive1] =  127;
	motor[LeftDrive2] =  127;
	motor[LeftDrive3] =  127;
	//right
	motor[RightDrive1] = 85;
	motor[RightDrive2] = 85;
	motor[RightDrive3] = 85;

	//aproach goal until sensor
	waitUntil(SensorValue[PipeSensor]);

	motor[LeftDrive1] = 0;
	motor[LeftDrive2] =  0;
	motor[LeftDrive3] =  0;
	//right
	motor[RightDrive1] = 0;
	motor[RightDrive2] = 0;
	motor[RightDrive3] = 0;


//deliver goals

	//eject high goal
	//extend the pistons
		SensorValue[ConeEject] = 1;
		wait1Msec(1000);
		//retract the pistons
		SensorValue[ConeEject] = 0;

	//lower moble goal into place
	//goes down
		motor[RightLowerMG] = -127;
		motor[LeftLowerMG] = -127;


		wait1Msec(250);

		motor[RightLowerMG] = 0;
		motor[LeftLowerMG] = 0;

		wait1Msec(500);

		strait(-450,-450);

		 leftReached = false;
		 rightReached = false;

		motor[RightLowerMG] = -127;
		motor[LeftLowerMG] = -127;

		while(true){
			if(SensorValue[LowerMGDownLeft]){
				motor[LeftLowerMG] = 0;
				leftReached = true;
			}
			if(SensorValue[LowerMGDownRight]){
				motor[RightLowerMG] = 0;
				rightReached = true;
			}
			if(leftReached && rightReached){
				break;
			}
		}

//reverse

//turn around and line up
	turnLeft(300,300);
	strait(225,225);
	turnLeft(300,300);

	//repeat /********************************************************/

//drive until first mobile goal
	//left
	motor[LeftDrive1] =  127;
	motor[LeftDrive2] =  127;
	motor[LeftDrive3] =  127;

	//right
	motor[RightDrive1] = 80;
	motor[RightDrive2] = 80;
	motor[RightDrive3] = 80;

	waitUntil(SensorValue[LowerMGIn] == 1);
	wait1Msec(200);
	motor[LeftDrive1] =  0;
	motor[LeftDrive2] =  0;
	motor[LeftDrive3] =  0;
	//right
	motor[RightDrive1] = 0;
	motor[RightDrive2] = 0;
	motor[RightDrive3] = 0;


//pick up first moblile goal
	startTask(rightLiftDown);
	startTask(leftLiftDown);
	wait1Msec(100);

	motor[LeftLowerMG] = 127;
	motor[RightLowerMG] = 127;
			//lower high lift

	waitUntil(SensorValue[LowerMGUp]);
	motor[LeftLowerMG] = 0;
	motor[RightLowerMG] = 0;





	//left
	motor[LeftDrive1] =  127;
	motor[LeftDrive2] =  127;
	motor[LeftDrive3] =  127;
	//right
	motor[RightDrive1] = 85;
	motor[RightDrive2] = 85;
	motor[RightDrive3] = 85;




//pick up second moble goal
	waitUntil(SensorValue(HighMGIn));



//lift upper moble goal
	startTask(rightLiftUp);
	startTask(leftLiftUp);


	wait1Msec(1000);

	//drive until the line
	startTask(lineLeftTest);
	startTask(lineRightTest);

	waitUntil(rightLineReached && leftLineReached);
// go to center
		//45 degree turn left
		//(left target, right target)


		turnLeft(200, 200);
		wait10Msec(100);

		//go forward

		strait(425, 425);
		wait10Msec(100);

		//45 degree turn right
		turnRight(250, 250);
		wait10Msec(100);

		//go forward
	//left
	motor[LeftDrive1] =  127;
	motor[LeftDrive2] =  127;
	motor[LeftDrive3] =  127;
	//right
	motor[RightDrive1] = 85;
	motor[RightDrive2] = 85;
	motor[RightDrive3] = 85;

	//aproach goal until sensor
	waitUntil(SensorValue[PipeSensor]);

	motor[LeftDrive1] = 0;
	motor[LeftDrive2] =  0;
	motor[LeftDrive3] =  0;
	//right
	motor[RightDrive1] = 0;
	motor[RightDrive2] = 0;
	motor[RightDrive3] = 0;


//deliver goals

	//eject high goal
	//extend the pistons
		SensorValue[ConeEject] = 1;
		wait1Msec(1000);
		//retract the pistons
		SensorValue[ConeEject] = 0;

	//lower moble goal into place
	//goes down
		motor[RightLowerMG] = -127;
		motor[LeftLowerMG] = -127;


		wait1Msec(250);

		motor[RightLowerMG] = 0;
		motor[LeftLowerMG] = 0;

		wait1Msec(500);

		strait(-450,-450);

		leftReached = false;
		rightReached = false;

		motor[RightLowerMG] = -127;
		motor[LeftLowerMG] = -127;

		while(true){
			if(SensorValue[LowerMGDownLeft]){
				motor[LeftLowerMG] = 0;
				leftReached = true;
			}
			if(SensorValue[LowerMGDownRight]){
				motor[RightLowerMG] = 0;
				rightReached = true;
			}
			if(leftReached && rightReached){
				break;
			}
		}







}
