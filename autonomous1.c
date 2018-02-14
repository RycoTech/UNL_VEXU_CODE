#include "tasks.c"

void autonomous1(){
		leftLineReached = false;
		rightLineReached = false;

		SensorValue[dgtl6] = 0;
		SensorValue[dgtl8] = 0;

		displayLCDCenteredString(0, "Test autonomous");
		displayLCDCenteredString(1, "running...");

			//start going forward
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;

			//when it picks up the goal
		waitUntil(SensorValue[mobleGoalHigher] == 1);
		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;

			//decrease drive speed
		motor[driveTrainLeft]=50;
		motor[driveTrainRight]=50;

			//when the goal is lifted- cut the motors
		if(SensorValue[liftAngleLeft] > 4000){
			motor[liftMobileHigherLeft] = 0;
		}
		if(SensorValue[liftAngleRight] < 2000){
			motor[liftMobileHigherRight] = 0;
		}

			//wait until lower the lower goal is ready
		waitUntil(SensorValue[mobleGoalLower] == 1);
		motor[liftMobileLowerLeft] = 127;
		motor[liftMobileLowerRight] = 127;
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;

			//wait for lift to go up
		waitUntil(SensorValue[lowerMobileGoalLimit]== 1);
		motor[liftMobileLowerLeft] =0;
		motor[liftMobileLowerRight] =0;


			//stop when it reaches the line
		startTask(lineLeftTest);
		startTask(lineRightTest);

		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);

			//45 degree turn left
			//(left target, right target)
		turnLeft(250, -250);
		wait10Msec(100);

			//go forward
		strait(-425, -425);
		wait10Msec(100);

			//45 degree turn right
		turnRight(-250, 250);
		wait10Msec(100);

			//Forward into 10pt zone
		motor[liftMobileHigherLeft] = -70;
		motor[liftMobileHigherRight] = -72;
		strait(-425,-425);
		motor[liftMobileHigherLeft] = 0;
		motor[liftMobileHigherRight] = 0;
		wait10Msec(100);

			//Backward out of 10pt zone
		strait(425,425);
		wait10Msec(100);

			//135 degree turn left
		turnLeft(750, -750);
		wait10Msec(100);

			//Go forward
		strait(-425, -425);
		wait10Msec(100);

			//45 drgree turn left
		turnLeft(250, -250);
		wait10Msec(100);

			//start going forward
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;

			//when it picks up the goal
		waitUntil(SensorValue[mobleGoalHigher] == 1);
		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;

			//decrease drive speed
		motor[driveTrainLeft]=50;
		motor[driveTrainRight]=50;

			//when the goal is lifted- cut the motors
		if(SensorValue[liftAngleLeft] > 4000){
			motor[liftMobileHigherLeft] = 0;
		}
		if(SensorValue[liftAngleRight] < 2000){
			motor[liftMobileHigherRight] = 0;
		}

			//wait until lower the lower goal is ready
		waitUntil(SensorValue[mobleGoalLower] == 1);
		motor[liftMobileLowerLeft] = 127;
		motor[liftMobileLowerRight] = 127;
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;

			//wait for lift to go up
		waitUntil(SensorValue[lowerMobileGoalLimit]== 1);
		motor[liftMobileLowerLeft] =0;
		motor[liftMobileLowerRight] =0;


			//stop when it reaches the line
		startTask(lineLeftTest);
		startTask(lineRightTest);

		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);

			//45 degree turn left
			//(left target, right target)
		turnLeft(250, -250);
		wait10Msec(100);

			//go forward
		strait(-425, -425);
		wait10Msec(100);

			//45 degree turn right
		turnRight(-250, 250);
		wait10Msec(100);

			//Forward into 10pt zone
		motor[liftMobileHigherLeft] = -70;
		motor[liftMobileHigherRight] = -72;
		strait(-425,-425);
		motor[liftMobileHigherLeft] = 0;
		motor[liftMobileHigherRight] = 0;
		wait10Msec(100);

			//Backward out of 10pt zone
		strait(425,425);
		wait10Msec(100);

			//90 degree turn left
		turnLeft(500, -500);
		wait10Msec(100);

			//Go forward
		strait(-200, -200);
		wait10Msec(100);

			//45 drgree turn left
		turnLeft(250, -250);
		wait10Msec(100);

}
