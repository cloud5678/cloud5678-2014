/*
 * common.h
 *
 *  Created on: Dec 1, 2013
 *      Author: nolan
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <API.h>

#define DEBUG 1

#define MTR_DLF 8
#define MTR_DLB 9
#define MTR_DRF 7
#define MTR_DRB 6
#define MTR_AL1 5
#define MTR_AL2 4
#define MTR_AR1 1
#define MTR_AR2 10
#define MTR_IL 3
#define MTR_IR 2
#define SNR_ACC 1 // Maybe remove acceleromenter
#define SNR_POT 2
#define SNR_GYR 3
#define SNR_PEX 4

void debug(char* a);
void setDrive(int move, int turn);
void setArm(int speed);
void setIntake(int speed);

Gyro* gyro;
Encoder* encLeft;
Encoder* encRight;

#endif /* COMMON_H_ */
