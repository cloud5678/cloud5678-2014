#pragma config(Motor,  port1,           leftFront,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           leftRear,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightRear,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           leftArm,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           rightArm,      tmotorVex393, openLoop)
#pragma config(Motor,  port7,           leftArm2,      tmotorVex393, openLoop)
#pragma config(Motor,  port8,           rightArm2,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           leftIntake,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rightIntake,   tmotorVex393, openLoop)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

void driveSpeed(int x)
	{
		motor[leftFront] = x;
    motor[leftRear] = x;
    motor[rightFront] = x;
    motor[rightRear] = x;
	}
void armLift(int x)
	{
		motor[leftArm] = x;
		motor[rightArm] = x;
    motor[leftArm2] = x;
    motor[rightArm2] = x;
 }
 void intake (int x)
 {
   motor[leftIntake] = x;
   motor[rightIntake] = x;
 }
 void turn (int x, int y)
 {
   motor[leftFront] = x;
   motor[leftRear] = x;
   motor[rightFront] = y;
   motor[rightRear] = y;
 }

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

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
 	//Hits first large ball into goal zone. (Total time: 1 second)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
  driveSpeed(127);
  armLift(70);
	}
	//Keeps arm lifted, turns to the right 90 degrees. (Total time: 1.5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 500)
	{
	turn(127,-127);
	armLift(0);
	}
	//Hits remaining large balls into goal zone. (Total time: 4.5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 3000)
	{
  driveSpeed(127);
	}
	//Keeps arm lifted, turns to the right 90 degrees. (Total time: 5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 500)
	{
	turn(127,-127);
	}
	//Lowers arm, opens intake, drives forward to pick up two small balls. (Total time: 7.5 seconds)
	ClearTimer(T1);
	while(time1[T1] < 2500)
	{
  driveSpeed(127);
  armLift(-40);
  intake(127);
	}
	//Turns to the right 162 degrees. (Total time: 8.4 seconds)
	ClearTimer(T1);
	while(time1[T1] < 900)
	{
	turn(127,-127);
	intake(0);
	armLift(0);
 }
 //Goes forward to the goal. (Total time: 11.4 seconds)
 ClearTimer(T1);
	while(time1[T1] < 3000)
	{
	driveSpeed(127);
 }
 //Lifts arm. (Total time: 12.4 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
		driveSpeed(0);
		armLift(80);
	}
	//Deposits balls in goal. (Total time: 13.9 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1500)
	{
		armLift(0);
		intake(-127);
	}
	//Lowers arm. (Total time: 14.9 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
		armLift(-40);
		intake(0);
	}
	//Turns to the right 162 degrees. (Total time: 15.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 900)
	{
	turn(127,-127);
	armLift(0);
 }
	//Opens intake, drives forward to pick up two small balls. (Total time: 20.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 5000)
	{
 driveSpeed(127);
  intake(127);
	}
	//Turns to the right 180 degrees. (Total time: 21.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
	turn(127,-127);
	intake(0);
 }
 	//Drives forward to goal. (Total time: 26.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 5000)
	{
  driveSpeed(127);
}
//Lifts arm. (Total time: 27.8 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1000)
	{
		driveSpeed(0);
		armLift(80);
	}
	//Deposits balls in goal. (Total time: 29.3 seconds)
	ClearTimer(T1);
	while(time1[T1] < 1500)
	{
		intake(-127);
		armLift(0);
	}
	intake(0);
}
