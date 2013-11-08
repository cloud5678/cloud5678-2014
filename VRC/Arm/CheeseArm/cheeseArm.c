#pragma config(Sensor, in1,   			Base,          	sensorNone)
#pragma config(Sensor, in2,  				Shoulder,       sensorNone)
#pragma config(Sensor, in3,   			Elbow,          sensorNone)
#pragma config(Sensor, in4,   			Wrist,          sensorNone)
#pragma config(Sensor, in5,					Bumper,					sensorTouch)
#pragma config(Motor, port1,				baseMotor1, 			tmotorVex393,	openLoop)
#pragma config(Motor, port10,				baseMotor2, 			tmotorVex393,	openLoop, reversed)
#pragma config(Motor, port2,				shoulderMotor1, 	tmotorVex393,	openLoop)
#pragma config(Motor, port3,				shoulderMotor2, 	tmotorVex393,	openLoop, reversed)
#pragma config(Motor, port4,				elbowMotor1, 			tmotorVex393,	openLoop)
#pragma config(Motor, port5,				elbowMotor2, 			tmotorVex393,	openLoop, reversed)
#pragma config(Motor, port6,				wristMotorVert1,	tmotorVex393,	openLoop)
#pragma config(Motor, port7,				wristMotorVert2,	tmotorVex393,	openLoop,	reversed)
#pragma config(Motor, port8,				wristServo,				tmotorVex269, openLoop)
#pragma config(Motor, port9,				clawServo,				tmotorVex269, openLoop)

#pragma platform(VEX)

#pragma competitionControl(Competition)

//#include "PIDController.c"
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!



typedef struct {
	bool enabled;
	float kP, kI, kD;
	int setpoint;
	int maxOutput, minOutput;
	int error, totalError, prevError;
} PIDController;

void init(PIDController controller, float kP, float kI, float kD) {
	controller.kP = kP;
	controller.kI = kI;
	controller.kD = kD;
}
void setSetpoint(PIDController controller, int setpoint) {
	controller.setpoint = setpoint;
	controller.totalError = 0.0;
	controller.prevError = 0.0;
}
void setThresholds(PIDController controller, int max, int min) {
	controller.maxOutput = max;
	controller.minOutput = min;
}
void setEnabled(PIDController controller, bool en) {
	controller.enabled = en;
}
int calculate(PIDController controller, int input) {
	if (!controller.enabled) {
		return 0.0;
	}
	controller.error = controller.setpoint - input;
	controller.totalError += controller.error;

	int output = controller.kP * controller.error +
               controller.kI * controller.totalError +
               controller.kD * (controller.prevError - controller.error);

	if (controller.maxOutput != 0 && controller.minOutput != 0) {
		if (output > controller.maxOutput) {
			output = controller.maxOutput;
		}
		if (output < controller.minOutput) {
			output = controller.minOutput;
		}
	}

	controller.prevError = controller.error;
	return output;
}




const int upperArm = 29; //cm
const int lowerArm = 0;	 //cm
const int bowlDist = 20; //cm
const int bowlDiam = 10; //cm
int shoulderZero;
int elbowZero;
int wristZero;

PIDController shoulderPID;
PIDController elbowPID;
PIDController basePID;

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
void setWristVertValue(int val)
{
		motor[wristMotorVert1] = motor[wristMotorVert2] = val;
}
void setWristRotValue(int val)
{
		motor[wristServo] = val;
}
void setBaseValue(int val)
{
		motor[baseMotor1] = motor[baseMotor2] = val;
}
void setClawValue(int val)
{
	 	motor[clawServo] = val;
}



void bendArm(int x, int y)
{
		int A = lowerArm;
		int B = upperArm;
		float a1,a2;
		float C = sqrt((x*x)+(y*y));
		a1 = acos(((C*C)+(B*B)-2*C*B)/(A*A));
		a2 = acos(((A*A)+(B*B)-2*A*B)/(C*C));
		setSetpoint(shoulderPID,a1);
		setSetpoint(elbowPID,a2);
		//setSetpoint(wristPID,180-(180-(a1+a2)));
		setEnabled(shoulderPID,true);
		setEnabled(elbowPID,true);
		//setEnabled(wristPID,true);
		while (SensorValue[Shoulder]!=a1*10 && SensorValue[Elbow]!=a2*10)
		{
				setShoulderValue(calculate(shoulderPID, SensorValue[Shoulder]));
				setElbowValue(calculate(elbowPID, SensorValue[Elbow]));
				//setWristValue(calculate(turnPID, SensorValue[])); look up how to use servos
		}
		setEnabled(shoulderPID,false);
		setEnabled(elbowPID,false);
		//setEnabled(wristPID,false);


}
void turnBase()
{

}

task autonomous()
{
		//shoulderZero = SensorValue[Shoulder];
		//elbowZero 	 = SensorValue[Elbow];
		//wristZero		 = SensorValue[Wrist];
		//int x = 0;
		//int y = bowlDist;
		//int count = 0;
		//while (true)
		//{
		//		if(SensorValue(Bumper)==1)
		//		{
		//			break;
		//		}
		//		bendArm(x,y);
		//		x = bowlDiam/2*sin(count);
		//		y = (-1*(bowlDiam/2))*cos(count);
		//		count++;
		//}
}

task usercontrol()
{
		while (true)
		{
				setBaseValue(vexRT[Ch2]/12.7);
				setShoulderValue(vexRT[Ch1]/-12.7);
				setElbowValue(vexRT[Ch1]/12.7);
				setWristVertValue(vexRT[Ch3]/12.7);
				setWristRotValue(vexRT[Ch4]/12.7);
				setClawValue(30*((vexRT[Btn5U]|vexRT[Btn5D])-(vexRT[Btn6U]|vexRT[Btn6D])));


		}
}
