#include "dc_motor.h"
#include "avr/io.h"
#include "gpio.h"
#include "pwm.h"
void DcMotor_init(){
	/*setting the control pins of the motor to output*/
	GPIO_setupPinDirection(OUT1_PORT_ID,OUT1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(OUT2_PORT_ID,OUT2_PIN_ID,PIN_OUTPUT);
	/*turning off the motor at the beginning */
	GPIO_writePin(OUT1_PORT_ID, OUT1_PIN_ID, 0);
	GPIO_writePin(OUT2_PORT_ID, OUT2_PIN_ID, 0);
}
void DcMotor_Rotate(DcMotorState state,uint8 speed){
	/*setting motor direction as required*/
	GPIO_writePin(OUT1_PORT_ID, OUT1_PIN_ID, BIT_IS_SET(state,0));
	GPIO_writePin(OUT2_PORT_ID, OUT2_PIN_ID, BIT_IS_SET(state,1));
	/*setting duty cycle*/
	if(speed>=0&&speed<=100) /*checking that the value is a percentage*/
	{
		PWM_setDutyCycle((uint8)(((float)speed*255)/100));
	}

}
