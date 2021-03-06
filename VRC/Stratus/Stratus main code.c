#pragma config(Motor,  port1,           rightRear,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port2,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftIntake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightIntake,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightArmTwo,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftArmTwo,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          leftRear,      tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void driveArcade(int y, int x)
{
	motor[leftFront] = motor[leftRear] = y - x;
	motor[rightFront] = motor[rightRear] = y + x;
}
void setArmSpeed(int z)
{
	motor[rightArm] = motor[rightArmTwo] = motor[leftArmTwo] = motor[leftArm] = z;
	//to other programmers, "leftArm" refers to both left arm motors and "rightArm" refers to both right arm motors --Mason
	//UPDATE: Now leftArmTwo and rightArmTwo because previous namings may have caused issues
}
void setIntakeSpeed(int speed)
{
	motor[leftIntake] = motor[rightIntake] = speed;
}
void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	//if (SensorValue(touchSensor) == 0)
	//{
	//Hits first friendly large ball into goal zone. (Total time: 1 second)
	//bool outside=true;//set to false if behind bump,set to true if doing autonomous infront
	//	if(outside == true)
	//		{
	//		ClearTimer(T1);
	//	while(time1[T1] < 1000)
	//	{
	//  	motor[leftFront] = 80;
	//  	motor[leftRear] = 80;
	//  	motor[rightFront] = 80;
	//  	motor[rightRear] = 80;
	//  	motor[leftArm] = 70;
	//  	motor[rightArm] = 70;
	//  	motor[leftArm] = 70;
	//  	motor[rightArm] = 70;

	//	}
	//		motor[leftFront] = 0;
	//  	motor[leftRear] = 0;
	//  	motor[rightFront] = 0;
	//  	motor[rightRear] = 0;
	//		//If a ball is in the robot, outtake
	//	ClearTimer(T1);
	//	while(time1[T1] < 2000)
	//	{
	//		motor[leftIntake] = 127;
	//		motor[rightIntake] = 127;

	//	}

	//	ClearTimer(T1);
	//	while(time1[T1] < 2000)
	//	{
	//		motor[leftIntake] = -127;
	//		motor[rightIntake] = -127;
	//	}

	//	//5 point code. Confirmed to work for 5+, 10+ potential.
	//	//Go back with arm up.
	//	ClearTimer(T1);
	//	while(time1[T1] < 900)
	//	{
	//  	motor[leftFront] = -100;
	//  	motor[leftRear] = -100;
	//  	motor[rightFront] = -100;
	//  	motor[rightRear] = -100;
	//  	motor[leftArm] = 10;
	//  	motor[rightArm] = 10;
	//  	motor[leftArm] = 10;
	//  	motor[rightArm] = 10;
	//	}
	//	//Wait for five seconds and point robot in the direction of next ball.
	//	ClearTimer(T1);
	//	while(time1[T1] < 3000)
	//	{
	//  	motor[leftFront] = 0;
	//  	motor[leftRear] = 0;
	//		motor[rightFront] = 0;
	//		motor[rightRear] = 0;
	//		motor[leftArm] = 10;
	//		motor[rightArm] = 10;
	//		motor[leftArm] = 10;
	//		motor[rightArm] = 10;
	//		motor[leftIntake] = 0;
	//		motor[rightIntake] = 0;
	//	}
	//	ClearTimer(T1);
	//	while(time1[T1] < 200)
	//	{
	//		motor[leftArm] = -70;
	//  	motor[rightArm] = -70;
	//  	motor[leftArm] = -70;
	//  	motor[rightArm] = -70;
	//	}

	//	//Go forward for two seconds.
	//		ClearTimer(T1);
	//	while(time1[T1] < 2200)
	//	{
	//		motor[leftArm] = 2;
	//  	motor[rightArm] = 2;
	//  	motor[leftArm] = 2;
	//  	motor[rightArm] = 2;
	//  motor[leftFront] = 80;
	//  motor[leftRear] = 80;
	//    motor[rightFront] = 80;
	//    motor[rightRear] = 80;
	//    motor[leftArm] = 30;
	//  motor[rightArm] = 30;
	//  motor[leftArm] = 30;
	//  motor[rightArm] = 30;
	//	}

	//	motor[leftFront] = 0;
	//  motor[leftRear] = 0;
	//    motor[rightFront] = 0;
	//  motor[rightRear] = 0;
	//    motor[leftArm] = 0;
	//  motor[rightArm] = 0;
	//  motor[leftArm] = 0;
	//  motor[rightArm] = 0;
	//  motor[leftIntake] = 0;
	//		motor[rightIntake] = 0;
	//}




	//else //if behind bump (inside)
	//{
	//	//raise arm
	//		motor[leftArm] = 65;
	//		motor[rightArm] = 65;
	//  	motor[leftArm] = 65;
	//  	motor[rightArm] = 65;
	//	wait1Msec(500);
	//	//intake
	//		motor[leftIntake] = 127;
	//		motor[rightIntake] = 127;
	//	wait1Msec(1000);
	//	//outtake
	//		motor[leftIntake] = -127;
	//		motor[rightIntake] = -127;
	//	wait1Msec(2000);
	//		motor[leftIntake] = 0;
	//		motor[rightIntake] = 0;
	//	//move forward and hit 3 buckyballs
	//		wait1Msec(2000);
	//		motor[leftArm] = -22;
	//		motor[rightArm] = -22;
	//  	motor[leftArm] = -22;
	//  	motor[rightArm] = -22;
	//  wait1Msec(800);
	//  	motor[leftArm] = 9;
	//		motor[rightArm] = 9;
	//  	motor[leftArm] = 9;
	//  	motor[rightArm] = 9;
	//  	motor[leftFront] = 80;
	// 	  motor[leftRear] = 80;
	//    motor[rightFront] = 80;
	// 	  motor[rightRear] = 80;
	//	wait1Msec(1500);
	//	  motor[leftArm] = 0;
	//		motor[rightArm] = 0;
	//  	motor[leftArm] = 0;
	//  	motor[rightArm] = 0;
	//		motor[leftFront] = 0;
	// 	  motor[leftRear] = 0;
	//    motor[rightFront] = 0;
	// 	  motor[rightRear] = 0;
	// 	  motor[leftIntake] = 0;
	//		motor[rightIntake] = 0;
	//}


	bool outside = true; // Where Is the robot positioned????????????????????????????


	if (outside == true)			//if in front of bump
	{
		setIntakeSpeed(127);				//drop intake and outtakes
		setArmSpeed(-105);

		wait1Msec(1000);
		setArmSpeed(-25);
		driveArcade(75,0);					//drive forward

		wait1Msec(1100);
		driveArcade(0,0);
		setIntakeSpeed(127);
		setArmSpeed(-25);

		wait1Msec(1000);						//drop buckyball
		setIntakeSpeed(-127);

		wait1Msec(3000);
		setIntakeSpeed(-127);
		driveArcade(-80,0);				//drive back

		wait1Msec(1300);
		driveArcade(0,0);
		setIntakeSpeed(0);

		wait1Msec(4000);
		driveArcade(100,0);					//drive forward

		wait1Msec(1300);
		driveArcade(0,0);

		wait1Msec(1000);
		driveArcade(-90,0);				//drive back

		wait1Msec(1300);
		driveArcade(0,0);
	}

	/* AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS
	AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS
	AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS AUTONOMOUS */


	else if (outside == false) //If behind bump
	{

		setIntakeSpeed(127);
		setArmSpeed(-63);

		wait1Msec(1200);
		wait1Msec(900);
		setIntakeSpeed(-127); //lowers intakes attempts to shoot buckyball as far as posssible in given direction
		setArmSpeed(-25);

		wait1Msec(6000);
		setIntakeSpeed(127);

		wait1Msec(1000);
		setIntakeSpeed(-127);

		wait1Msec(2000);
		setArmSpeed(60);
		setIntakeSpeed(0);

		wait1Msec(2000);
		setArmSpeed(0);

		wait1Msec(750);
		driveArcade(100, 0);		//	drive forward


		wait1Msec(1300);
		driveArcade(0,0);

		wait1Msec(1000);
		driveArcade(-90,0);				//drive back

		wait1Msec(1300);
		driveArcade(0,0);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{        while (true)
	{

		int driveX = vexRT[Ch4];
		int driveY = vexRT[Ch3];
		int armSpeed = -vexRT[Ch2];
		int intakeSpeed = 127*((vexRT[Btn5U]|vexRT[Btn5D])-(vexRT[Btn6U]|vexRT[Btn6D]));

		if (abs(driveY) < 5) driveY = 0; // Deadband
			if (abs(driveX) < 5) driveX = 0;

		driveArcade(driveY, driveX);
		setArmSpeed(armSpeed);
		setIntakeSpeed(intakeSpeed);


		//if (vexRT[Btn6U] == 1)
		//{
		//        motor[leftIntake] = 127;
		//        motor[rightIntake] = 127;
		//}
		//else if (vexRT[Btn6D] == 1)
		//{
		//        motor[leftIntake] = -127;
		//        motor[rightIntake] = -127;
		//}
		//else
		//{
		//        motor[leftIntake] = 0;
		//        motor[rightIntake] = 0;
		//}
		////arm up and down Channel 3
		//motor[leftArm] = vexRT[Ch3];
		//motor[rightArm] = vexRT[Ch3];
		////Turning/Straight driving
		////Use Right-Stick


		//        motor[rightFront] = (vexRT[Ch2] + vexRT[Ch1]);
		//        motor[rightRear] = (vexRT[Ch2] + vexRT[Ch1]);
		//        motor[leftRear] = (vexRT[Ch2] - vexRT[Ch1]);
		//        motor[leftFront]= (vexRT[Ch2] - vexRT[Ch1]);
	}
}
