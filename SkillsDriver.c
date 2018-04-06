#include "PotSensors.c"
#include "encoderTasks.c"
task usercontrol()
{
	while(true){

	displayLCDCenteredString(0, "SkyNet");
	displayLCDCenteredString(1, "Running...");

	//drive controls
	//left
	motor[LeftDrive1] =  vexRT[Ch3];
	motor[LeftDrive2] =  vexRT[Ch3];
	motor[LeftDrive3] =  vexRT[Ch3];
	//right
	motor[RightDrive1] = (vexRT[Ch2]);
	motor[RightDrive2] = (vexRT[Ch2]);
	motor[RightDrive3] = (vexRT[Ch2]);

	//High lift
		if(vexRT[Btn6U]){
			//goes up
				startTask(rightPotSensor);
				startTask(leftPotSensor);
		}else if(vexRT[Btn6D]){
			//goes down
				startTask(rightPotSensor);
				startTask(leftPotSensor);
		}else{
			stopTask(rightPotSensor);
			stopTask(leftPotSensor);
			motor[RightUpperMG] = 0;
			motor[LeftUpperMG] = 0;
		}



	//low lift
		if(vexRT[Btn5U]){
			//goes up
			if(SensorValue[LowerMGUp]){
				motor[RightLowerMG] = 0;
				motor[LeftLowerMG] = 0;
			}else{
				motor[RightLowerMG] = 127;
				motor[LeftLowerMG] = 127;
			}
		}else if(vexRT[Btn5D]){
			//goes down
			if(SensorValue[LowerMGDownLeft]){
				motor[LeftLowerMG] = 0;
			}else{
			motor[LeftLowerMG] = -127;
			}

			if(SensorValue[LowerMGDownRight]){
				motor[RightLowerMG] = 0;
			}else{
			motor[RightLowerMG] = -127;
			}
		}else{
			motor[RightLowerMG] = 0;
			motor[LeftLowerMG] = 0;
		}


		//7 buttons
		if(vexRT[Btn7D]){
		SensorValue[leftEncoder] = 0;
		SensorValue[rightEncoder] = 0;
		}

		if(vexRT[Btn7L]){
		turnLeft(250, 250);
		}

		if(vexRT[Btn7R]){
		turnRight(250,250);
		}

		if(vexRT[Btn7D]){
		strait(-425,-425);
		}

	//mobile goal eject
	if(vexRT[Btn8D]){

		//extend the pistons
		SensorValue[ConeEject] = 1;
		wait1Msec(10);
		//retract the pistons
		SensorValue[ConeEject] = 0;
	}
	}
}
