task usercontrol()
{
	while(true){


	//drive controls
		//right side-right joystick is Ch2
		motor[RightDrive1] = vexRT[Ch2];
		motor[RightDrive2] = vexRT[Ch2];

		//left side-left joystick is Ch3
		motor[LeftDrive1] = vexRT[Ch3];
		motor[RightDrive2] = vexRT[Ch3];


		//High lift
		if(vexRT[Btn6U]){
			//goes up

			//left
			if(SensorValue[PotemtiometerLeft] < 3200)
  			motor[LeftUpperMG] = 0;
			else
  			motor[LeftUpperMG] = 127;

  		//right
  		if (SensorValue[PotentiometerRight] > 4080)
      	motor[RightUpperMG] = 0;
    	else
     	 motor[RightUpperMG] = 127;
		}else if(vexRT[Btn6D]){

			//goes down
  			motor[LeftUpperMG] = -127;
      	motor[RightUpperMG] = -127;
		}else	{
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






	//cone eject
	if(vexRT[Btn8D]){
		//extend the pistons
		SensorValue[ConeEject] = 1;
		wait1Msec(1000);
		//retract the pistons
		SensorValue[ConeEject] = 0;
	}
	}
}
