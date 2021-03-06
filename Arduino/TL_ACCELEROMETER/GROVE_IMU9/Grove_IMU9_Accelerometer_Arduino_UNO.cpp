#include "Grove_IMU9_Accelerometer_Arduino_UNO.h"

Grove_9DOF_Accelerometer::Grove_9DOF_Accelerometer(){
	state = 0;
}

int Grove_9DOF_Accelerometer::read(){
	if (state == 0){
		Wire.begin();
		accelgyro.initialize();
		if(accelgyro.testConnection()){
			status = 1;
		}else{
			status = 0;
		}
		state = 1;
	}
	if(status == 1){
		ax = accelgyro.getAccelerationX();
		ay = accelgyro.getAccelerationY();
		az = accelgyro.getAccelerationZ();
		return 0;
	}else{
		return -1;
	}
}

double Grove_9DOF_Accelerometer::data_x(){
	return (double) ax / 16384;
}

double Grove_9DOF_Accelerometer::data_y(){
	return (double) ay / 16384;
}

double Grove_9DOF_Accelerometer::data_z(){
	return (double) az / 16384;
}


#if ACCELEROMETER == GROVE_IMU9
	Grove_9DOF_Accelerometer TL_Accelerometer;
#endif
