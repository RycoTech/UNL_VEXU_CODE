bool leftLineReached = false;
bool rightLineReached = false;


task leftLiftUp(){
			//goes up
			motor[LeftUpperMG] = 127;
			while(true){
				if(SensorValue[PotemtiometerLeft]   <  100  ){
					motor[LeftUpperMG] = 0;
					stopTask(leftLiftUp);
				}
				wait10Msec(1);
			}
}


task rightLiftUp(){

			//goes up
				motor[RightUpperMG] = 127;

	while(true){
		if(SensorValue[PotentiometerRight] > 3900 ){
			motor[RightUpperMG] = 0;
			stopTask(rightLiftUp);
		}
		wait10Msec(1);
	}
}

task leftLiftDown(){
			//goes down
				motor[LeftUpperMG] = -127;

			while(true){
				if(SensorValue[PotemtiometerLeft]   >  1000 ){
					motor[LeftUpperMG] = 0;
					stopTask(leftLiftDown);
				}
				wait10Msec(1);
			}
}


task rightLiftDown(){
	//goes down
	motor[RightUpperMG] = -127;

	while(true){
		if(SensorValue[PotentiometerRight] < 2999 ){
			motor[RightUpperMG] = 0;
			stopTask(rightLiftDown);
		}
		wait10Msec(1);
	}
}


task lineLeftTest(){
	rightLineReached = false;
while(true){
  	if(SensorValue[LineFollowLeft] < 2000){
 		motor[LeftDrive1] =  0;
		motor[LeftDrive2] =  0;
		rightLineReached = true;
 			stopTask(lineLeftTest);
		}
		wait1Msec(1);

	}
}





task lineRightTest(){
leftLineReached = false;
	while(true){
  	if(SensorValue[LineFollowRight] < 2000){
 				motor[RightDrive1] = 0;
				motor[RightDrive2] = 0;
				motor[RightDrive3] = 0;
				leftLineReached = true;
 			stopTask(lineRightTest);
		}
		wait1Msec(1);
	}
}
