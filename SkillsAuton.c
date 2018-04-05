#include "autonTasks.c"
task autonomous()
{
//lift the high lift
startTask(leftLiftUp);
startTask(rightLiftUp);

//drive until first mobile goal
	//left
	motor[LeftDrive1] =  127;
	motor[LeftDrive2] =  127;
	motor[LeftDrive3] =  127;
//motor[LeftDrive3] = 127;
	//right
	motor[RightDrive1] = 85;
	motor[RightDrive2] = 85;
	motor[RightDrive3] = 85;

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




	motor[LeftLowerMG] = 127;
	motor[RightLowerMG] = 127;
			//lower high lift

	waitUntil(SensorValue[LowerMGUp]);
	motor[LeftLowerMG] = 0;
	motor[RightLowerMG] = 0;


	startTask(rightLiftDown);
	startTask(leftLiftDown);

	wait10Msec(1);


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
//drive until the line
	startTask(lineLeftTest);
	startTask(lineRightTest);

	waitUntil(rightLineReached && leftLineReached);
// go to center
		//45 degree turn left
		//(left target, right target)


		turnLeft(250, 250);
		wait10Msec(100);

		//go forward

		strait(-425, -425);
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

		while(true){
		bool leftReached = false;
		bool rightReached = false;
		if(leftReached && rightReached){
		break;
		}

		if(SensorValue[LowerMGDownLeft]){
				motor[LeftLowerMG] = 0;
				leftReached = true;
			}
		if(SensorValue[LowerMGDownRight]){
				motor[RightLowerMG] = 0;
				rightReached = true;
			}
		}

//reverse
		strait(425,425);
//turn around
	//90 degrees right
	//forward till__Encoder value here___
	//left 90 degrees

//repeat
}
