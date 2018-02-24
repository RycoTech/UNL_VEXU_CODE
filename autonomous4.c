//#include "tasks-test.c"
#include "tasks.c"
void autonomous4(){


			//90 degree turn right
		turnRight(-275, 275);
		wait1Msec(500);


			//go forward
		strait(-260, -260);
		wait1Msec(500);

			//45 degree turn right
		turnRight(-250, 250);
		wait1Msec(500);

			//when it picks up the goal
		waitUntil(SensorValue[mobleGoalHigher] == 1);
		motor[driveTrainLeft] = 0;
		motor[driveTrainRight] = 0;
		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;
		wait1Msec(250);
		SensorValue[dgtl3] = 1;

			//45 degree turn right
		turnRight(-250, 250);
		wait1Msec(500);

			//go forward
		strait(-100, -100);
		wait1Msec(500);

		//wait until lower the lower goal is ready
		waitUntil(SensorValue[mobleGoalLower] == 1);
		startTask(LowLiftUp);
		motor[driveTrainLeft]=0;
		motor[driveTrainRight]=0;
		wait1Msec(250);
		SensorValue[dgtl3] = 1;

	}
