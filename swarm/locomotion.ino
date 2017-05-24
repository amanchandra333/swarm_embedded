/*
 Motion Direction Legend:
 1. Forward
 2. Right
 3. Backward
 4. Left
 5. Free Run ( this is just for our perception. Do not use it anywhere to denoe it.)
 6. Brake
*/


void leftTurn() {
  motion_direction=2;
  digitalWrite(InputAA, HIGH);
  digitalWrite(InputBA, HIGH);
  digitalWrite(InputBB, LOW);
  digitalWrite(InputAB, LOW);
}


void rightTurn() {
  motion_direction=3;
  digitalWrite(InputAA, LOW);
  digitalWrite(InputBA, LOW);
  digitalWrite(InputBB, HIGH);
  digitalWrite(InputAB, HIGH);
}


void forward() {
  motion_direction=1;
  digitalWrite(InputAA, HIGH);
  digitalWrite(InputBA, LOW);
  digitalWrite(InputBB, HIGH);
  digitalWrite(InputAB, LOW);
}


void backward() {
  motion_direction=4;
  digitalWrite(InputAA, LOW);
  digitalWrite(InputBA, HIGH);
  digitalWrite(InputBB, LOW);
  digitalWrite(InputAB, HIGH);
}

void brake() {
  motion_direction=6;
  digitalWrite(InputAA, HIGH);
  digitalWrite(InputBA, HIGH);
  digitalWrite(InputBB, HIGH);
  digitalWrite(InputAB, HIGH);
}

void motorA_forward(){
  motion_directionA=1;
  digitalWrite(InputAA, HIGH);
  digitalWrite(InputBB, LOW);
  }

void motorB_forward(){
  motion_directionB=1;
  digitalWrite(InputAB, HIGH);
  digitalWrite(InputBA, LOW);
  }

void motorA_backward(){
  motion_directionA=0;
  digitalWrite(InputAA, LOW);
  digitalWrite(InputBB, HIGH);
  }

void motorB_backward(){
  motion_directionB=0;
  digitalWrite(InputAB, LOW);
  digitalWrite(InputBA, HIGH);
  }
