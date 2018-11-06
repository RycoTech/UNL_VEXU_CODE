//#include "tasks-test.c"
#include "tasks.c"
/**
 *
 * This program run the robot autonomously
 * game type: match(blue)
 */
void autonomous2(){

	// const timer
	int waitTime = 3000; // time is in miliSec

	leftLineReached = false;
	rightLineReached = false;
	SensorValue[dgtl6] = 0;
	SensorValue[dgtl8] = 0;

		//pop out numatics
		SensorValue[extendConeLift] = 0;
		wait1Msec(1200);

		motor[liftConeLeft] = 127;
		motor[liftConeRight] = 127;

		//start going forward
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;

		waitUntil(SensorValue[coneAngleLeft] > 1250);
		motor[liftConeLeft] = 0;
		waitUntil(SensorValue[coneAngleRight] > 1150);
		motor[liftConeRight] = 0;

		//when it picks up the goal
		waitUntil(SensorValue[mobleGoalHigher] == 1);
		wait1Msec(150);

		motor[driveTrainLeft] = 0;
		motor[driveTrainRight] = 0;
		wait1Msec(400);

		//Short cotinue forward
		motor[driveTrainLeft] = -40;
		motor[driveTrainRight] = -40;

		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;

		SensorValue[dgtl3] = 1;
		wait1Msec(250);


			//when the goal is lifted- cut the motors
		highLift(3, 127);

		//Backward
		strait(300, 300);

		motor[driveTrainLeft]=-127;
		motor[driveTrainRight]=-127;

		//stop when it reaches the autoloader line
		startTask(lineLeftTest);
		startTask(lineRightTest);

		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);

		//small jolt forwad/kill momentum
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;
		wait1Msec(050);

		//continue back to 5 pt line
		motor[driveTrainLeft]=-127;
		motor[driveTrainRight]=-127;

		//stop when 5pt line reached
		startTask(lineLeftTest);
		startTask(lineRightTest);
		waitUntil(rightLineReached == true);
		motor[driveTrainRight]=127;
		wait1Msec(100);
		motor[driveTrainRight]=0;
		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);
		wait1Msec(500);

		//go forward
		strait(-070, -070);
		wait1Msec(500);

		//90 degree turn left
		//(left target, right target)
		turnLeft(300, -300);
		wait1Msec(500);

		//go forward
		strait(-900, -900);
		wait1Msec(500);

		//45 degree turn right
		turnRight(-125, 125);
		wait1Msec(1000);

		//start going forward
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;

		//wait until lower the lower goal is ready
		waitUntil(SensorValue[mobleGoalLower] == 1);
		startTask(LowLiftUp);
		motor[driveTrainLeft]=0;
		motor[driveTrainRight]=0;
		wait1Msec(1200);

		//Backward
		strait(750, 750);

		motor[driveTrainLeft]=-127;
		motor[driveTrainRight]=-127;

		//stop when it reaches the autoloader line
		startTask(lineLeftTest);
		startTask(lineRightTest);

		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);

		//small jolt forwad/kill momentum
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;
		wait1Msec(050);

		//continue back to 5 pt line
		motor[driveTrainLeft]=-127;
		motor[driveTrainRight]=-127;

		//stop when 5pt line reached
		startTask(lineLeftTest);
		startTask(lineRightTest);
		waitUntil(rightLineReached == true);
		motor[driveTrainRight]=127;
		wait1Msec(100);
		motor[driveTrainRight]=0;
		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);
		wait1Msec(500);

		//go forward
		strait(-010, -010);
		wait1Msec(500);

		//>90 degree turn right
		turnRight(-350, 350);
		wait1Msec(500);

		//go forward
		strait(-175, -175);
		wait1Msec(500);

		//<90 degree turn right
		turnRight(-300, 300);
		wait1Msec(500);

		//Score Preload Cone on Lower Mobile Goal
		motor[liftConeLeft] = -127;
		motor[liftConeRight] = -127;
		waitUntil(SensorValue[coneAngleLeft] < 400);
		motor[liftConeLeft] = 0;
		waitUntil(SensorValue[coneAngleRight] < 400);
		motor[liftConeRight] = 0;
		wait1Msec(500);
		motor[coneIntake] = -127;
		motor[liftConeLeft] = 127;
		motor[liftConeRight] = 127;
		waitUntil(SensorValue[coneAngleLeft] > 1250);
		motor[liftConeLeft] = 0;
		waitUntil(SensorValue[coneAngleRight] > 1150);
		motor[liftConeRight] = 0;
		motor[coneIntake] = 0;

		//forward to score the moble goals
		motor[driveTrainLeft] = 127;
		motor[driveTrainRight] = 127;

		// restart timer
		clearTimer(T1);
		waitUntil(SensorValue[pipeSensor] == 1 || time1[T1] < waitTime ); // or less than a certain amount of time

		motor[driveTrainLeft] = 0;
		motor[driveTrainRight] = 0;
		motor[liftMobileHigherLeft] = -127;
		motor[liftMobileHigherRight] = -127;
		wait1Msec(800);
		motor[liftMobileHigherLeft] = 0;
		motor[liftMobileHigherRight] = 0;
		SensorValue[dgtl3] = 0;


		//score the moble goals
		startTask(rightLowLiftDown);
		startTask(leftLowLiftDown);
		wait1Msec(1000);


		//Backward out of 10pt zone
		strait(375,375);
		wait1Msec(500);

	}
