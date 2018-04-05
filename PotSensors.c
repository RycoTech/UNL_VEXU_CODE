task leftPotSensor(){
		if(vexRT[Btn6U] && SensorValue[PotemtiometerLeft] > 100 ){
			//goes up
				motor[LeftUpperMG] = 127;
		}

		if(vexRT[Btn6D] && SensorValue[PotemtiometerLeft] < 1000  ){
			motor[LeftUpperMG] = -127;
		}

		while(vexRT[Btn6U]){
			if(SensorValue[PotemtiometerLeft] < 100){
			motor[LeftUpperMG] = 0;
			wait10Msec(1);
			}
		}

		while(vexRT[Btn6D]){
			if(SensorValue[PotemtiometerLeft] > 1000){
			motor[LeftUpperMG] = 0;
			wait10Msec(1);
			}
		}
}

task rightPotSensor(){
		if(vexRT[Btn6U] && SensorValue[PotentiometerRight] < 3900){
			//goes up
				motor[RightUpperMG] = 127;
		}

		if(vexRT[Btn6D] && SensorValue[PotentiometerRight] > 3000){
			motor[RightUpperMG] = -127;
		}

		while(vexRT[Btn6U]){
			if(SensorValue[PotentiometerRight] > 3900){
			motor[RightUpperMG] = 0;
			}
			wait10Msec(1);
		}

			while(vexRT[Btn6D]){
			if(SensorValue[PotentiometerRight] < 2999){
			motor[RightUpperMG] = 0;
			}
			wait10Msec(1);
		}
}
