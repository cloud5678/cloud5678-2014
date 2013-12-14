/*
 * common.c
 *
 *  Created on: Dec 1, 2013
 *      Author: nolan
 */

#include <common.h>
#include <API.h>

void setDrive(int move, int turn) {
#if DEBUG
	sprintf("Set Drive %d %d", move, turn);
#endif
	int moveLeft = move + turn;
	int moveRight = move - turn;
	motorSet(MTR_DLF, moveRight);
	motorSet(MTR_DLB, moveRight);
	motorSet(MTR_DRF, moveLeft);
	motorSet(MTR_DRB, moveLeft);
}

void setArm(int speed) {
#if DEBUG
	sprintf("Set Arm %d", speed);
#endif
	motorSet(MTR_AL1, speed);
	motorSet(MTR_AL2, speed);
	motorSet(MTR_AR1, speed);
	motorSet(MTR_AR2, speed);
}

void setIntake(int speed) {
#if DEBUG
	sprintf("Set Intake %d", speed);
#endif
	motorSet(MTR_IL, speed);
	motorSet(MTR_IR, speed);
}
