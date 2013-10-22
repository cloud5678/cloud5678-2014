/* PID Controller for Vex
 *
 * P: Proportional
 * I: Integral
 * D: Derivative
 *
 * PID Controllers are used to calulate the error between a sensor value and a setpoint.
 * It then calculates the appropriate output to reach the target. You will need to define
 * three constants the P, I, and D.
 *
 * Based on how large the error is, the P constant will proportionally increase or decrease
 *  the output. For example, if the error is very large, the output will be very large.
 *  If the error is small, the output will be small. The output for Vex motors range from
 *  -128 to 127 therefore you need to scale the input of a gyroscope for example (-3600 to
 *  3600) to match the motors. Basically P will proportionally jump you to your setpoint based
 *  on how much farther you need to go to reach it.
 *
 * The I part of PID uses previous error values to give an accumulated offset that should have
 *  been corrected previously. This can reduce the time it takes to reach the setpoint, but
 *  may lead to overshooting! The I constant reduces the output of this and scales it
 *  appropriately. You should use an I constant that reduces the time it takes to reach the
 *  setpoint but doesn't make yit overshoot to much.
 *
 * The D part of PID calculates the slope of error over time (derivative) and multiplies this
 *  by by the D constant. This improves stability and settling time.
 *
 * To summarize this, P jumps you to your setpoint, I gives you a boost, and D stabilizes you!
 */

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
