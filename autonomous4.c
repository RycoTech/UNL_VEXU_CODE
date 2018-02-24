//#include "tasks-test.c"
#include "tasks.c"
void autonomous4(){

		//Lower cone arms
		motor[liftConeLeft] = -127;
		motor[liftConeRight] = -127;
		waitUntil(SensorValue[coneAngleLeft] < 800);
		motor[liftConeLeft] = 0;
		waitUntil(SensorValue[coneAngleRight] < 800);
		motor[liftConeRight] = 0;
		wait1Msec(0);

		//Release cone
		motor[coneIntake]  = -127;
		wait1Msec(100);
		motor[coneIntake]	=	0;

		motor[liftConeLeft] = 127;
		motor[liftConeRight] = 127;
		waitUntil(SensorValue[coneAngleLeft] > 1250);
		motor[liftConeLeft] = 0;
		waitUntil(SensorValue[coneAngleRight] > 1150);
		motor[liftConeRight] = 0;
	}
