#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in1,    LineFollowLeft, sensorNone)
#pragma config(Sensor, in2,    LineFollowRight, sensorLineFollower)
#pragma config(Sensor, in3,    PotemtiometerLeft, sensorPotentiometer)
#pragma config(Sensor, in4,    PotentiometerRight, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  ConeEject,      sensorDigitalOut)
#pragma config(Sensor, dgtl2,  LowerMGIn,      sensorTouch)
#pragma config(Sensor, dgtl3,  LowerMGUp,      sensorTouch)
#pragma config(Sensor, dgtl4,  LowerMGDownLeft, sensorTouch)
#pragma config(Sensor, dgtl5,  LowerMGDownRight, sensorTouch)
#pragma config(Sensor, dgtl6,  EncoderRight,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  EncoderLeft,    sensorQuadEncoder)
#pragma config(Motor,  port1,           RightLowerMG,  tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           RightDrive1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RightDrive2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RightUpperMG,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LeftUpperMG,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LeftDrive1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LeftDrive2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          LeftLowerMG,   tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               MAIN CODE                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "SkillsDriver.c"
#include "SkillsAuton.c"

void pre_auton()
{
  bStopTasksBetweenModes = true;
}
