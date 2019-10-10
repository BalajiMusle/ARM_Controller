#include "i2c.h"
#include "uart.h"

void i2c_init(void)
{
	// enable i2c0 pins
	LPC_PINCON->PINSEL1 &= ~(BV(25)|BV(24)|BV(23)|BV(22));
	LPC_PINCON->PINSEL1 |= BV(22) | BV(24);
	// setup prescalar
	I2_SCLL = SCLL_VAL;
	I2_SCLH = SCLH_VAL;
	// clear all flags
	I2_CONCLR = BV(CON_ACK) | BV(CON_SIF) | BV(CON_START) | BV(CON_EN);
	// enable I2C
	I2_CONSET = BV(CON_EN);
}	

void i2c_start(void)
{
	// clear SI flag
	I2_CONCLR = BV(CON_ACK) | BV(CON_SIF) | BV(CON_START);
	// send start signal
	I2_CONSET = BV(CON_EN) | BV(CON_START);
	// wait for transmission
	while((I2_CONSET & BV(CON_SIF))==0);
}

void i2c_rep_start(void)
{
	i2c_start();
}

void i2c_stop(void)
{
	// clear SI flag
	I2_CONCLR = BV(CON_SIF);
	// send start signal
	I2_CONSET = BV(CON_EN) | BV(CON_ACK) | BV(CON_STOP);	
}

void i2c_send_addr(uint8_t addr)
{
	// send address
	I2_DAT = addr;
	// clear SI flag
	I2_CONCLR = BV(CON_SIF) | BV(CON_START);
	// set i2c en
	I2_CONSET = BV(CON_EN);	
	// wait for transmission
	while((I2_CONSET & BV(CON_SIF))==0);
}

void i2c_send_data(uint8_t data)
{
	// send data
	I2_DAT = data;
	// clear SI flag
	I2_CONCLR = BV(CON_SIF) | BV(CON_START);
	// set i2c en
	I2_CONSET = BV(CON_EN);	
	// wait for transmission
	while((I2_CONSET & BV(CON_SIF))==0);	
}

uint8_t i2c_recv_ack(void)
{
	uint8_t data;
	// clear SI flag 
	I2_CONCLR = BV(CON_SIF);
	// set i2c en
	I2_CONSET = BV(CON_EN) | BV(CON_ACK);	
	// wait for receive
	while((I2_CONSET & BV(CON_SIF))==0);	
	// recv data
	data = I2_DAT;
	return data;
}

uint8_t i2c_recv_nack(void)
{
	uint8_t data;
	// clear SI flag 
	I2_CONCLR = BV(CON_SIF) | BV(CON_ACK);	
	// set i2c en
	I2_CONSET = BV(CON_EN);	
	// wait for receive
	while((I2_CONSET & BV(CON_SIF))==0);	
	// recv data
	data = I2_DAT;
	return data;
}


