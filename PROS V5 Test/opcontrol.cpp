#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (true) {

			//split arcade
			LeftDrive1.move(Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + (0.5*Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));
			LeftDrive2.move(Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + (0.5*Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));
			LeftDrive3.move(Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + (0.5*Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));

			RightDrive1.move(Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - (0.5*Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));
			RightDrive2.move(Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - (0.5*Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));
			RightDrive3.move(Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - (0.5*Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)));


			//intake
			 if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
           rollIntake(90);
       }else if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
           rollIntake(-90);
       }else{
           rollIntake(0);
       }


			 //fine tune turn
       if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
           turnDeg(-5,50);
           while(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT));
       }else if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
           turnDeg(5,50);
           while(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
       }


       //toggle pnumatics
       if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
           pneumToggle();
           while(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
       }

			 //shoot ball
       if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
           shootBall();
           while(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
       }
		}
}
