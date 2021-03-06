 /*******************************************************************************
 User Parameters interface file

  Company:
    Microchip Technology Inc.

  File Name:
    userparams.h

  Summary:
    Motor control parameters interface

  Description:
    This file contains the motor parameters and hardware board parameters
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _USER_HEADER
#define _USER_HEADER

/***********************************************************************************************/
/*                    include files                                                            */
/***********************************************************************************************/

/***********************************************************************************************/
/*                    DEFINATIONS                                                              */
/***********************************************************************************************/
#define MOTOR_1_EL5_M0400_1_24                     (1U)    /* AC300025 - Leadshine 400W 220VAC Servo Motor*/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - START                                                        */
/***********************************************************************************************/
/* Configuration for file inlining */

#undef USE_FILE_INLINING
#define POTENTIOMETER_INPUT_ENABLED               1U

#ifdef       USE_FILE_INLINING
  #define INLINE_FUNCTION                         __STATIC_INLINE 
#else 
  #define INLINE_FUNCTION     
#endif

/**********************************************************************************************************************/
/*                                           ALGORITHM                                                                */
/**********************************************************************************************************************/
#define TORQUE_MODE                                (0U)  /* If enabled - torque control            */

/**********************************************************************************************************************/
/*                                           MOTOR PARAMETERS                                                         */
/**********************************************************************************************************************/



/* Motor selection from above mentioned predefined motors */
#define MOTOR                                       ( MOTOR_1_EL5_M0400_1_24 )

#if(MOTOR == MOTOR_1_EL5_M0400_1_24)
/* AC Servo Motor EL5-M0400-1-24  */
#define MOTOR_PER_PHASE_RESISTANCE                  ((float)1.39)
#define MOTOR_PER_PHASE_INDUCTANCE                  ((float)0.00253)
#define MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH        ((float)44.38)
#define NUM_POLE_PAIRS                              ((float)5)
#define RATED_SPEED_RPM                             ((float)3000)
#define MAX_SPEED_RPM                               ((float)5000)
#define MAX_MOTOR_CURRENT                           ((float)(5))
#define ENCODER_PULSES_PER_REV                      ((float)10000)
#define ELECTRICAL_TIME_CONSTANT                    ((float)0.001123)
#define MECHANICAL_TIME_CONSTANT                    ((float)0.002882)
#endif

/**********************************************************************************************************************/
/*                                           CONTROL PARAMETERS                                                         */
/**********************************************************************************************************************/


/** PWM frequency in Hz */
#define PWM_FREQUENCY                              (20000U)
#define FAST_LOOP_TIME_SEC                         (float)(1/(float)PWM_FREQUENCY) /* Always runs in sync with PWM */

/* Motor Start-up configuration parameters */
#define LOCK_TIME_IN_SEC                            (2)          /* Startup - Rotor alignment time                              */
#define OPEN_LOOP_END_SPEED_RPM                     (10)        /* Startup - Control loop switches to close loop at this speed */
#define OPEN_LOOP_RAMP_TIME_IN_SEC                  (5)          /* Startup - Time to reach OPEN_LOOP_END_SPEED_RPM in seconds  */
#define Q_CURRENT_REF_OPENLOOP                      (float)0.2   /* Startup - Motor start to ramp up in current control mode    */

/* Current ramp parameters for open loop to close loop transition  */
#define Q_CURRENT_OPENLOOP_STEP                     (float)0.001
#define CLOSING_LOOP_TIME_COUNTS                    (uint32_t)( Q_CURRENT_REF_OPENLOOP / Q_CURRENT_OPENLOOP_STEP)                           


/*__________________________________________________ PI CONTROLLER PARAMETERS  ____________________________________________________ */

#if(MOTOR == MOTOR_1_EL5_M0400_1_24)

/*________________________________________________ D Control Loop Coefficients  ___________________________________________________ */

#define D_CURRCNTR_PTERM                           ((float)(0.025)/MAX_MOTOR_CURRENT)
#define D_CURRCNTR_ITERM                           ((float)(0.0005) /MAX_MOTOR_CURRENT)
#define D_CURRCNTR_CTERM                           ((float)(0.5)/MAX_MOTOR_CURRENT)
#define D_CURRCNTR_OUTMAX                          ((float)(0.98))

/*________________________________________________ Q Control Loop Coefficients  ___________________________________________________ */

#define Q_CURRCNTR_PTERM                           ((float)(0.025)/MAX_MOTOR_CURRENT)
#define Q_CURRCNTR_ITERM                           ((float)(0.0005) /MAX_MOTOR_CURRENT)
#define Q_CURRCNTR_CTERM                           ((float)(0.5)/MAX_MOTOR_CURRENT)
#define Q_CURRCNTR_OUTMAX                          ((float)(0.98))

/*________________________________________________ Speed Control Loop Coefficients  ________________________________________________ */

#define SPEEDCNTR_PTERM                            ((float)0.004)
#define SPEEDCNTR_ITERM                            ((float)0.000005)
#define SPEEDCNTR_CTERM                            ((float)(0.999))
#define SPEEDCNTR_OUTMAX                           ((float)MAX_MOTOR_CURRENT)
#endif 


#define KFILTER_ESDQ                                (float)((float)4000/(float)32767)
#define KFILTER_BEMF_AMPLITUDE                      (float)((float)4000/(float)32767)
#define KFILTER_VELESTIM                            (float)((float)4000/(float)32767)
#define KFILTER_POT                                 (float)((float)50/(float)32767)

/* Encoder pulses per electrical revolution */
#define ENCODER_PULSES_PER_EREV                     (uint16_t)(ENCODER_PULSES_PER_REV/NUM_POLE_PAIRS)
#define QEI_VELOCITY_COUNT_PRESCALER                (float)100.0f
/**********************************************************************************************************************/
/*                                           BOARD PARAMETERS                                                         */
/**********************************************************************************************************************/

#define MCHV3
#define MAX_CURRENT                                      (float)(16.4)   /*        Max Board Current in A                                    */
#define MAX_ADC_COUNT                                    (float)4095     /*        12-bit ADC */
#define MAX_ADC_INPUT_VOLTAGE                            (float)3.3      /*        volts */

/** Dead time in micro seconds */
#define DEAD_TIME_uS                                     (1U)           /*        Dead time in uS.                                          */

#define DCBUS_SENSE_TOP_RESISTOR                         (float)285     /*        300K Ohm but due to temperature it is considered as 276K  */
#define DCBUS_SENSE_BOTTOM_RESISTOR                      (float)2.2     /*        2.2K Ohm                                                  */
#define STATOR_VOLTAGE_LIMIT                             (float)0.98    /*        In percentage                                             */

 
#define ACBUS_SENSE_TOP_RESISTOR                         (float)300     /*        300K Ohm                                                  */
#define ACBUS_SENSE_BOTTOM_RESISTOR                      (float)1.1     /*        1.1K Ohm                                                  */

/***********************************************************************************************/
/* Peripheral Configuration parameters */
/***********************************************************************************************/
#define INTERRUPT_SOURCE                                 INT_SOURCE_ADC_DATA3          
 
/**********************************************************************************************/

/***********************************************************************************************/
/* USER CONFIGURABLE PARAMETERS - END                                                          */
/***********************************************************************************************/

/*******************************************************************************/
/* Configuration Parameters Calculations*/
/*******************************************************************************/
#define One_MHz                                           (1000000U)


#define SLOW_LOOP_TIME_SEC                                (float)(FAST_LOOP_TIME_SEC * 100) /* 100 times slower than Fast Loop */

/**********************************************************************************************************************/
/*                                           DERIVED PARAMETERS                                                       */
/**********************************************************************************************************************/
#define MAX_CURRENT_SQUARED                               (float)( MAX_MOTOR_CURRENT * MAX_MOTOR_CURRENT )

#define ADC_CURRENT_SCALE                                 (float)(MAX_CURRENT/(float)(2048))
#define DCBUS_SENSE_RATIO                                 (float)(DCBUS_SENSE_BOTTOM_RESISTOR/(DCBUS_SENSE_BOTTOM_RESISTOR + DCBUS_SENSE_TOP_RESISTOR))
#define VOLTAGE_ADC_TO_PHY_RATIO                          (float)(MAX_ADC_INPUT_VOLTAGE/(MAX_ADC_COUNT * DCBUS_SENSE_RATIO))
#define SPEED_LOOP_PWM_COUNT                              (int32_t)(SLOW_LOOP_TIME_SEC / FAST_LOOP_TIME_SEC) /* 100 times slower than Fast Loop */
#define LOCK_COUNT_FOR_LOCK_TIME                          (uint32_t)((float)LOCK_TIME_IN_SEC/(float)FAST_LOOP_TIME_SEC)
#define OPEN_LOOP_END_SPEED_RPS                           ((float)OPEN_LOOP_END_SPEED_RPM/60)

/*____________________________ Rated speed of the motor in RPM___________________________________________ */
#define RATED_SPEED_RAD_PER_SEC_ELEC                      (float)(RATED_SPEED_RPM *(2*(float)M_PI/60) * NUM_POLE_PAIRS)
#define CLOSE_LOOP_RAMP_RATE                              (600) /* RPM per sec */
#define RAMP_RAD_PER_SEC_ELEC                             (float)(CLOSE_LOOP_RAMP_RATE * NUM_POLE_PAIRS * PI/30.0)
#define SPEED_RAMP_INC_SLOW_LOOP                          (float)(RAMP_RAD_PER_SEC_ELEC*SLOW_LOOP_TIME_SEC)

/*_____________________________ Open loop end speed conversions__________________________________________ */
#define SINGLE_ELEC_ROT_RADS_PER_SEC                      ((float)((float)(2.0) * (float)M_PI))
#define END_SPEED_RADS_PER_SEC_MECH                       (float)(OPEN_LOOP_END_SPEED_RPS * SINGLE_ELEC_ROT_RADS_PER_SEC)
#define OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC             (float)(END_SPEED_RADS_PER_SEC_MECH * NUM_POLE_PAIRS)
#define OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME (float)(OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC * FAST_LOOP_TIME_SEC)
#define OPEN_LOOP_RAMPSPEED_INCREASERATE                  (float)(OPEN_LOOP_END_SPEED_RADS_PER_SEC_ELEC_IN_LOOPTIME/(OPEN_LOOP_RAMP_TIME_IN_SEC/FAST_LOOP_TIME_SEC))

/*________________________________ BEMF constant___________________________________________________ */
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH        (float)((MOTOR_BEMF_CONST_V_PEAK_LL_KRPM_MECH/SQRT3)/1000.0)
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH    (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_PER_RPM_MECH / (float)(2.0 * M_PI/60.0))
#define MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_ELEC    (float)(MOTOR_BEMF_CONST_V_PEAK_PHASE_RAD_PER_SEC_MECH / NUM_POLE_PAIRS)
#define MAX_SPEED_RAD_PER_SEC_ELEC                        (float)(((RATED_SPEED_RPM/60)*2*(float)M_PI)*NUM_POLE_PAIRS)
#define MAX_STATOR_VOLT_SQUARE                            (float)(0.98 * 0.98)
#define POT_ADC_COUNT_FW_SPEED_RATIO                      (float)(MAX_SPEED_RAD_PER_SEC_ELEC/MAX_ADC_COUNT)

#endif
