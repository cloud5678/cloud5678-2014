#include "LCD.c"

void robotShutdown();
void robotInit();
void robotDisabled();
task robotAutonomous();
task robotTeleop();

task main()
{
	// Master CPU will not let competition start until powered on for at least 2-seconds
	StartTask(LCDController);

	wait1Msec(2000);

	robotInit();

	while (true) {
		while (bIfiRobotDisabled) {
			while (true) {
				if (!bIfiRobotDisabled)
				  break;
				robotDisabled();
				robotShutdown();
				wait1Msec(100);
			}
	  }
		if (bIfiAutonomousMode) {
		  StartTask(robotAutonomous);

			// Waiting for autonomous phase to end
			while (bIfiAutonomousMode && !bIfiRobotDisabled) {
				if (!bVEXNETActive) {
				  if (nVexRCReceiveState == vrNoXmiters)
					  robotShutdown();
				}
				wait1Msec(25);
			}
		  	StopTask(robotAutonomous);
		} else {
			StartTask(robotTeleop);
			while (!bIfiAutonomousMode && !bIfiRobotDisabled) {
				if (nVexRCReceiveState == vrNoXmiters)
					robotShutdown();
				wait1Msec(25);
		  }
			StopTask(robotTeleop);
		}
	}
}
