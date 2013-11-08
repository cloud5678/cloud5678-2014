#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(2000)
#pragma config(Motor, port1,	baseMotor1, 			tmotorVex393,	openLoop)
#pragma config(Motor, port10,	baseMotor2, 			tmotorVex393,	openLoop, reversed)
#pragma config(Motor, port2,	shoulderMotor1, 	tmotorVex393,	openLoop)
#pragma config(Motor, port3,	shoulderMotor2, 	tmotorVex393,	openLoop, reversed)
#pragma config(Motor, port4,	elbowMotor1, 			tmotorVex393,	openLoop)
#pragma config(Motor, port5,	elbowMotor2, 			tmotorVex393,	openLoop, reversed)
#pragma config(Motor, port6,	wristMotorVert1,	tmotorVex269,	openLoop)
#pragma config(Motor, port7,	wristMotorVert2,	tmotorVex269,	openLoop,	reversed)
#pragma config(Motor, port8,	wristMotorRot,		tmotorVex269,	openLoop)
#pragma config(Motor, port9,	clawMotor,				tmotorVex269,	openLoop)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

const int upperArm = 29; //cm
const int lowerArm = 0;	 //cm
const int bowlDist = 10; //cm
const int bowlDiam = 10; //cm

PIDController shoulderPID;
PIDController elbowPID;
PIDController wristPID;

void pre_auton()
{

  bStopTasksBetweenModes = true;

}

void setShoulderValue(int val)
{
		motor[shoulderMotor1] = motor[shoulderMotor2] = val;
}

void setElbowValue(int val)
{
		motor[elbowMotor1] = motor[elbowMotor2] = val;
}
void setWristValue(int val)
{
		motor[wristMotorVert1] = motor[wristMotorVert2] = val;
}

void keepHandLevel(int insideAngle)
{
	 //180-insideAngle;
}

void bendArm(int x, int y)
{
		int A = lowerArm;
		int B = upperArm;
		double a1,a2,a3;
		double C = sqrt((x*x)+(y*y));
		a1 = acos(((C*C)+(B*B)-2*C*B)/(A*A));
		a2 = acos(((A*A)+(B*B)-2*A*B)/(C*C));
		setSetpoint(shoulderPID,a1);
		setEnabled(shoulderPID,true);
		setSetpoint(elbowPID,a2);
		setEnabled(elbowPID,true);
		setSetpoint(wristPID,180-(180-(a1+a2)));
		setEnabled(wristPID,true);
		wait1Msec(1000);
		setEnabled(shoulderPID,false);
		setEnabled(elbowPID,false);
		setEnabled(wristPID,false);

		//keepHandLevel(180-(a1+a2))

}
void turnBase()
{

}

task autonomous()
{
	int x = 0;
	int y = bowlDist;
	int count = 0;
	while (true)
	{
			bendArm(x,y);
			x = bowlDiam/2*sin(count);
			y = (-1*(bowlDiam/2))*cos(count);
			count++;
	}
}
task usercontrol()
{
}
