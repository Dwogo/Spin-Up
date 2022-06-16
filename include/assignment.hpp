#include "main.h"

// Global variables
int rev = 1;
bool blue = true;

// Controller
Controller OLEANA(CONTROLLER_MASTER);

// Optical Sensor
Vision LOKI(18);

// Motors
// Drivetrain
Motor GFM(1, MOTOR_GEARSET_18, false);
Motor GBM(2, MOTOR_GEARSET_18, false);
Motor RBM(3, MOTOR_GEARSET_18, true);
Motor RFM(6, MOTOR_GEARSET_18, true);

// Shootingtrain
Motor CON(10, MOTOR_GEARSET_18, true);
Motor FW(9, MOTOR_GEARSET_36, false);

// Widetrain
Motor GWM(18, MOTOR_GEARSET_18, false);
Motor RWM(19, MOTOR_GEARSET_18, false);