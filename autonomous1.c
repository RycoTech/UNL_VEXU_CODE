#include "tasks.c"

void autonomous1(){

	leftLineReached = false;
	rightLineReached = false;
	SensorValue[dgtl6] = 0;
	SensorValue[dgtl8] = 0;

		//pop out numatics
		SensorValue[extendConeLift] = 0;
		wait1Msec(800);


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
		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;

			//decrease drive speed
		motor[driveTrainLeft]=50;
		motor[driveTrainRight]=50;

			//when the goal is lifted- cut the motors
		highLift(3, 127);

			//wait until lower the lower goal is ready
		waitUntil(SensorValue[mobleGoalLower] == 1);
		startTask(LowLiftUp);
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;


			//stop when it reaches the line
		startTask(lineLeftTest);
		startTask(lineRightTest);

		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);

			//45 degree turn left
			//(left target, right target)
		turnLeft(250, -250);
		wait1Msec(500);

			//go forward
		strait(-425, -425);
		wait1Msec(500);

			//45 degree turn right
		turnRight(-250, 250);
		wait1Msec(500);

			//Forward into 10pt zone
		strait(-375,-375);
		motor[liftMobileHigherLeft] = -127;
		motor[liftMobileHigherRight] = -127;
		wait1Msec(500);
		motor[liftMobileHigherLeft] = 0;
		motor[liftMobileHigherRight] = 0;
		strait(-50,-50);



		//score the moble goals
		startTask(rightLowLiftDown);
		startTask(leftLowLiftDown);
		wait1Msec(1000);


			//Backward out of 10pt zone
		strait(325,325);
		wait1Msec(500);

																																	//part 2



			//135 degree turn left
		turnLeft(550, -550);
		wait1Msec(1000);

		//reset lifts
		startTask(leftLowLiftDown);
		startTask(rightLowLiftDown);
		highLift(1, 127);


			//Go forward
		strait(-425, -425);
		wait1Msec(1000);

			//45 drgree turn left
		turnLeft(250, -250);
		wait1Msec(1000);

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
		highLift(3, 127);


			//wait until lower the lower goal is ready
		waitUntil(SensorValue[mobleGoalLower] == 1);
		startTask(LowLiftUp);
		motor[driveTrainLeft]=127;
		motor[driveTrainRight]=127;


			//stop when it reaches the line
		startTask(lineLeftTest);
		startTask(lineRightTest);

		waitUntil(leftLineReached == true && rightLineReached == true);
		stopTask(lineLeftTest);
		stopTask(lineRightTest);

			//45 degree turn left
			//(left target, right target)
		turnLeft(250, -250);
		wait1Msec(500);

			//go forward
		strait(-525, -525);
		wait1Msec(500);

		//avoid cone by going backwards
		strait(100, 100);
		wait1Msec(500);

			//45 degree turn right
		turnRight(-250, 250);
		wait1Msec(500);

			//Forward into 10pt zone
		highLift(2, 60);
		strait(-425,-425);
		wait1Msec(500);



		//score the moble goals
		startTask(rightLowLiftDown);
		startTask(leftLowLiftDown);


			//Backward out of 10pt zone
		strait(425,425);
		wait1Msec(500);

			//90 degree turn left
		turnLeft(500, -500);
		wait1Msec(1000);

			//Go forward
		strait(-200, -200);
		wait1Msec(1000);

			//45 drgree turn left
		turnLeft(250, -250);
		wait1Msec(1000);

}
