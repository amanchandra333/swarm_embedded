const float kpA=1000;
const float kiA=22;
const float kdA=1.3;

const float kpB=1000;
const float kiB=22;
const float kdB=1.3;

void pwm_pid(){
 errorA = set_rpmA - curr_rpmA;
 IA+=errorA;
  float x = 0;
 if((kpA*errorA + kiA*IA + kdA*(errorA-preverrorA))<0)
  x = 0;
 else
  x = (kpA*errorA + kiA*IA + kdA*(errorA-preverrorA)); 
 PWMA=map(x, 0, max_rpmA*kpA, 0, 255);
 preverrorA=errorA;

float y = 0;
 errorB = set_rpmB - curr_rpmB;
IB+=errorB;
if((kpB*errorB + kiB*IB + kdB*(errorB-preverrorB))<0)
  y = 0;
  else 
  y = (kpB*errorB + kiB*IB + kdB*(errorB-preverrorB));
 PWMB=map(y, 0, max_rpmB*kpB, 0, 255);
 preverrorB=errorB;

  }


