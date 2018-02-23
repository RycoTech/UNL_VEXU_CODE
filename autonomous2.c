#include "tasks.c"

void autonomous2(){

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
		wait1Msec(050);
		motor[driveTrainLeft] = 0;
		motor[driveTrainRight] = 0;

		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;

		wait1Msec(350);
		SensorValue[dgtl3] = 1;

			//when the goal is lifted- cut the motors
		highLift(3, 127);

		//Backward
		strait(500, 500);

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
		turnLeft(290, -290);
		wait1Msec(500);

		//go forward
		strait(-1000, -1000);
		wait1Msec(500);

		//45 degree turn right
		turnRight(-80, 80);
		wait1Msec(1500);

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
		strait(500, 500);

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
		strait(-050, -050);
		wait1Msec(500);

		//90 degree turn right
		turnRight(-475, 475);
		wait1Msec(500);

		//go forward
		strait(-500, -500);
		wait1Msec(500);

		//90 degree turn right
		turnRight(-475, 475);
		wait1Msec(500);

		//forward to score the moble goals
		motor[driveTrainLeft] = 127;
		motor[driveTrainRight] = 127;
		waitUntil(SensorValue[pipeSensor] == 1);
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
