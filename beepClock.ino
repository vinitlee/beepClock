#define SPEAKER 2

void setup() {
  pinMode(SPEAKER, OUTPUT);
}
int now[3] = {2,48,0};
void loop() {
  // beep(SPEAKER,1000,4000,0.2);
  // delay(100);
  // time(5,12);
  time();
  delay(1000);
}
void time() {
  now[2] = (now[2] + 1)%60;
  if (now[2]==0) {
    now[1] = (now[1] + 1)%60;
    if (now[1]==0) {
      now[0] = (now[0] + 1)%24;
      hours();
    }
    minutes();
  }
  else {
    seconds();
  }
}
void hours() {
  int h = now[0];
  for(int i=0; i<h; i++) {
    beep(SPEAKER,1000,2000+(2*(i%2)-1)*i*50,0.2);
    delay(10);
  }
}
void minutes() {
  int m = now[1];
  for(int i=0; i<m; i++) {
    beep(SPEAKER,1000,2000+i*50,0.2);
    delay(10);
  }
}
void seconds() {
  int s = now[2];
  if (s%15 == 0) {
    beep(SPEAKER,10,6000,0.4);
  }
  // for(int i=0; i<s; i++) {
  //   beep(SPEAKER,1000,6000+1000*sin(4*PI*i/60),0.2);
  //   delay(10);
  // }
}

void beep(int pin, int t,int f,float d) {
  // beep(SPEAKER,1000,4000,0.2);
  int p = 1000000/f;
  // p = 1000000/4000 = 250

  int p1 = d*p;
  // p1 = 0.2 * 250 = 50
  int p2 = p - p1;
  // p2 = 250 - 50 = 200

  for (int c=0; c<t*1000/p; c++) {
    // c=0; c<(1000*1000/250 = 4000); c++
    digitalWrite(pin, HIGH);
    delayMicroseconds(p1);
    digitalWrite(pin, LOW);
    delayMicroseconds(p2);
  }
}
