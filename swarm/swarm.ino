#include <Wire.h>
#include "TimerOne.h"
//#include <Adafruit_Sensor.h>
//#include <Adafruit_HMC5883_U.h>
#include <ros.h>
///#include <nav_msgs/Odometry.h>

#define InputAA 7
#define InputAB 8
#define InputBA 9
#define InputBB 10
#define interruptEncoderPinA 2
#define interruptEncoderPinD 3
#define PWMOutputMotorA 5
#define PWMOutputMotorB 6
//Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

#define wheel_radius 3.0//In cm
#define w2w 13.5//cm
#define CPR 32
#define gear_ratio 19
#define del_t 0.05 //in seconds

volatile float theta=0.0; // Current orientation of the bot.

volatile int ext_counterA=0;
volatile int ext_counterB=0;

#define max_rpmA 479.6
volatile float set_rpmA=200.0;
volatile float curr_rpmA=0;
float errorA=0,preverrorA=0,IA=0;

#define max_rpmB 489.4
volatile float set_rpmB=200.0;
volatile float curr_rpmB=0;
float errorB=0,preverrorB=0,IB=0;

//volatile float sys_dist=0.0;
volatile float curr_pos_x=0.0;
volatile float curr_pos_y=0.0;

volatile float Dl=0,Dr=0,Dc=0;

int motion_direction=0;
int PWMA,PWMB;
uint32_t timer;

ros::NodeHandle nh;
//nav_msgs::Odometry odomsg;
//ros::Publisher odom_pub("odom", &odomsg);   

void setup() {
Serial.begin(57600);
interrupt_init();
//mag_init();
timer = micros();

nh.initNode();
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

forward();
}

void loop(){
  int i;
 // float x= get_theta();
//  nav_msgs::Odometry odom;
//  odomsg.pose.pose.position.x = curr_pos_x;
//  odomsg.pose.pose.position.y = curr_pos_y;
//  odomsg.pose.pose.orientation.z = theta;
//  Serial.println(odomsg.pose.pose.orientation.z);
  i=200;
  PWMA=i;
  PWMB=i;
  //pwm_pid();
  analogWrite(PWMOutputMotorA,PWMA);
  Serial.print(PWMA);
  Serial.print('\t');
  Serial.println(PWMB);
  analogWrite(PWMOutputMotorB,PWMB);

//  forward();
//  delay(2000);
//  backward();
//  delay(2000);
  //odom_pub.publish(& odomsg);
  //nh.spinOnce();
  //delay(1);

  //get_sharpdata();

}
