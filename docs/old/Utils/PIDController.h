#ifndef PIDController_H
#define PIDController_H

#define DELTA_T 0.001

#include "PID.h"

class PIDController
{
private:
	int diff[2];
	int integral; /* 積分 */

public:
	PIDController();
	int calc_pid_control_pwm_value(PID *pid, unsigned int sensor_val, unsigned int target_val, int absMax);
	int pwm_controller_limit(int pid_value, int absMax);

	virtual ~PIDController();
};
#endif