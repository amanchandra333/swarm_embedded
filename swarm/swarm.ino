#include <Wire.h>
#include "TimerOne.h"
//#include <Adafruit_Sensor.h>
//#include <Adafruit_HMC5883_U.h>
//#include <ros.h>
///#include <nav_msgs/Odometry.h>

#define InputAA 8
#define InputAB 7
#define InputBA 4
#define InputBB 9
#define interruptEncoderPinA 3    
#define interruptEncoderPinD 2    
#define PWMOutputMotorA 6         //right
#define PWMOutputMotorB 5         //left
//Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

#define wheel_radius 3.5//In cm
#define w2w 20//cm
#define CPR 32
#define gear_ratio 19
#define del_t 0.05 //in seconds

volatile float theta=0.0; // Current orientation of the bot.

volatile int ext_counterA=0;
volatile int ext_counterB=0;

#define max_rpmA 479.6
volatile float set_rpmA=0;
volatile float curr_rpmA=0;
float errorA=0,preverrorA=0,IA=0;

#define max_rpmB 489.4
volatile float set_rpmB=0;
volatile float curr_rpmB=0;
float errorB=0,preverrorB=0,IB=0;

//volatile float sys_dist=0.0;
volatile float curr_pos_x=0.0;
volatile float curr_pos_y=0.0;
volatile float set_pos_x=1000.0;
volatile float set_pos_y=1000.0;


volatile float Dl=0,Dr=0,Dc=0;

int motion_direction=0;
bool motion_directionA=0;
bool motion_directionB=0;

int PWMA,PWMB;
uint32_t timer;


volatile float set_theta=0;
volatile float set_velocity=0;
volatile float omega;

//ros::NodeHandle nh;
//nav_msgs::Odometry odomsg;
//ros::Publisher odom_pub("odom", &odomsg);   

void setup() {
Serial.begin(9600);
interrupt_init();
//mag_init();
timer = micros();

//nh.initNode();
//nh.advertise(odom_pub);

pinMode(PWMOutputMotorA,OUTPUT);
pinMode(PWMOutputMotorB,OUTPUT);
pinMode(InputAA,OUTPUT);
pinMode(InputAB,OUTPUT);
pinMode(InputBA,OUTPUT);
pinMode(InputBB,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A6,INPUT);
pinMode(A7,INPUT);

//motorB_forward();
//motorA_forward();
}

void loop(){

//    int i=120;
//    PWMA=i;
//    PWMB=i;
//  calculateRPM();
  pwm_pid();
  analogWrite(PWMOutputMotorA,PWMA);
  analogWrite(PWMOutputMotorB,PWMB);
//  Serial.print(curr_rpmA);
//  Serial.print('\t');
//  Serial.println(curr_rpmB);
 
}
