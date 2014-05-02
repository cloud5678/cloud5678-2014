#include "User.c"

// Red, facing blue, left is scoring zone, right is hanging zone
// Blue, facing red, left is hanging zone, right is scoring zone

void auton_middle(bool isBlue) {
		setWings(true);		// open wings
		wait1Msec(250);

		driveArcade(128,0);	// drive forward
		wait1Msec(800);
		driveArcade(0,0);

		wait1Msec(100);

		driveArcade(-128,0);	// drive back
		wait1Msec(850);
		driveArcade(0,0);

		setWings(false);		// open wings
		wait1Msec(250);

		wait1Msec(4000);

		setIntakeSpeed(127);// drop bucky ball

		setArmSpeed(120);
		wait1Msec(900);
		setArmSpeed(12);

		driveArcade(128,0);	// drive forward
		wait1Msec(800);
		driveArcade(0,0);

		setIntakeSpeed(0);
		setArmSpeed(20);

		wait1Msec(250);

		driveArcade(-128,0);	// drive back
		wait1Msec(850);
		driveArcade(0,0);

		wait1Msec(3000);

		driveArcade(128,0);	// drive forward
		wait1Msec(900);
		driveArcade(0,0);

		wait1Msec(250);

		driveArcade(-70,0);	// drive back
		wait1Msec(950);
		driveArcade(0,0);
}

void auton_middle_2_pid(bool isBlue) {
		long startTime;
		PIDController auton_turnPID;
		PIDController auton_armPID;
		init(auton_turnPID, -0.267368, 0, 0);
		setThresholds(auton_turnPID, 128, -127);
		init(auton_armPID, 0.564444, 0.009, 0);
		setThresholds(auton_armPID, 128, -127);

		setIntakeSpeed(128); // intake

		setWings(true);		// open wings
		wait1Msec(250);

		driveArcade(128,0);	// drive forward
		wait1Msec(800);
		driveArcade(0,0);

		wait1Msec(1000);

		driveArcade(-128,0);	// drive back
		wait1Msec(850);
		driveArcade(0,0);

		setWings(false);		// close wings
		wait1Msec(250);
		setIntakeSpeed(0);

		wait1Msec(3000);
		SensorValue[gyro] = 0;

		setSetpoint(auton_turnPID, 0);
		startTime = nSysTime; // drive forward, push bump stuff
		while (nSysTime - startTime < 1300) {
			driveArcade(128, calculate(auton_turnPID, SensorValue[gyro]));
		}

		setSetpoint(auton_armPID, 1550);
		while (nSysTime - startTime < 1000) {
			driveArcade(128, calculate(auton_turnPID, SensorValue[gyro]));
			setArmSpeed(calculate(auton_armPID, getPotenValue()));
		}
		driveArcade(0,0);
		setArmSpeed(10);
		setIntakeSpeed(-127);
		wait1Msec(3000);

}

void auton_hanging_special(bool isBlue) { // AUTON FOR TEAM 127C
	PIDController auton_turnPID;
	init(auton_turnPID, 0.20, 0, 0);
	setThresholds(auton_turnPID, 128, -127);
	auton_turnPID.enabled = true;

	long startTime;

	setIntakeSpeed(128);	// eat bucky balls
	wait1Msec(100);

	SensorValue[gyro] = 0;
	setSetpoint(auton_turnPID, 0);
	startTime = nSysTime; // drive forward, eat bucky balls
	while (nSysTime - startTime < 800) {
		driveArcade(128, calculate(auton_turnPID, SensorValue[gyro]));
	}
	driveArcade(0,0);
	wait1Msec(1000);
	startTime = nSysTime; // drive reverse, eat bucky balls
	while (nSysTime - startTime < 850) {
		driveArcade(-120, calculate(auton_turnPID, SensorValue[gyro]));
	}
	driveArcade(0, 0);
	setIntakeSpeed(50);

	wait1Msec(8500);

	setArmSpeed(80);
	driveArcade(127, 0);
	wait1Msec(1000);

	setArmSpeed(-10);
	wait1Msec(1000);

	setArmSpeed(10);
	wait1Msec(1000);

}

void auton_hanging_depreciated_pid(bool isBlue) {
	////////////////////////////////////////////////////////////////// Initialize
	PIDController auton_turnPID;
	init(auton_turnPID, -0.60, 0, 0);
	setThresholds(auton_turnPID, 128, -127);
	auton_turnPID.enabled = true;

	int sideScale = isBlue ? 1 : -1;

	long startTime;
	////////////////////////////////////////////////////////////////// Begin

	SensorValue[gyro] = 475;

	startTime = nSysTime; // drive forward, push bump stuff
	while (nSysTime - startTime < 2000) {
		driveTank(32, 112);
	}

	setSetpoint(auton_turnPID, sideScale * -425);
	startTime = nSysTime; // drive forward, push bump stuff
	while (nSysTime - startTime < 850) {
		driveArcade(-128, calculate(auton_turnPID, SensorValue[gyro]));
	}
	driveArcade(0, 0);

	setWings(false);		// close wings
	wait1Msec(250);

	wait1Msec(4000); 			// wait for user to set position

	setIntakeSpeed(128);	// eat bucky balls
	wait1Msec(100);

	SensorValue[gyro] = 0;
	setSetpoint(auton_turnPID, 0);
	startTime = nSysTime; // drive forward, eat bucky balls
	while (nSysTime - startTime < 800) {
		driveArcade(128, calculate(auton_turnPID, SensorValue[gyro]));
	}
	driveArcade(0,0);
	wait1Msec(1000);
	startTime = nSysTime; // drive reverse, eat bucky balls
	while (nSysTime - startTime < 850) {
		driveArcade(-120, calculate(auton_turnPID, SensorValue[gyro]));
	}
	driveArcade(0, 0);
	setIntakeSpeed(0);
	////////////////////////////////////////////////////////////////// End
}

void auton_hanging_pid(bool isBlue) {
	////////////////////////////////////////////////////////////////// Initialize
	PIDController auton_turnPID;
	init(auton_turnPID, 0.30, 0, 0);
	setThresholds(auton_turnPID, 128, -127);
	auton_turnPID.enabled = true;

	int sideScale = isBlue ? 1 : -1;

	long startTime;
	////////////////////////////////////////////////////////////////// Begin

	SensorValue[gyro] = 0;
	setSetpoint(auton_turnPID, SensorValue[gyro]);

	setWings(true);		// open wings
	wait1Msec(100);

	startTime = nSysTime; // drive forward, push bump stuff
	while (nSysTime - startTime < 2000) {
		driveArcade(128, 0);
	}

	startTime = nSysTime; // drive forward, push bump stuff
	while (nSysTime - startTime < 2000) {
		driveArcade(-128, 0);
	}

	driveArcade(0, 0);
	setWings(false);		// close wings

	wait1Msec(3000); 			// wait for user to set position

	setIntakeSpeed(128);	// eat bucky balls
	wait1Msec(100);

	SensorValue[gyro] = 0;
	setSetpoint(auton_turnPID, 0);
	startTime = nSysTime; // drive forward, eat bucky balls
	while (nSysTime - startTime < 800) {
		driveArcade(128, calculate(auton_turnPID, SensorValue[gyro]));
	}
	driveArcade(0,0);
	wait1Msec(1000);
	startTime = nSysTime; // drive reverse, eat bucky balls
	while (nSysTime - startTime < 2000) {
		driveArcade(-120, calculate(auton_turnPID, SensorValue[gyro]));
	}
	driveArcade(0, 0);
	setIntakeSpeed(0);
	////////////////////////////////////////////////////////////////// End
}
