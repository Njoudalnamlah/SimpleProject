#include <Servo.h>
int p=0;
int gripperState = 0;
Servo base ;
Servo shoulder ;
Servo elbow ;
Servo wrist ;
Servo gripper ;
double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;
double gripper_angle=0;
String data;
String data1;
String data2;
String data3;
double angle1;
double angle2;
double angle3;
double angle4;
double prev_base_angle=90;
double prev_shoulder_angle=90;
double prev_elbow_angle=90;
double prev_wrist_angle=90;
void setup() {
Serial.begin(9600);
delay(50);
base.attach(8); 
shoulder.attach(9);
elbow.attach(10);
wrist.attach(11);
gripper.attach(12);
base.write(90); // initial point for all motors
shoulder.write(90);
elbow.write(90);
wrist.write(90);
gripper.write(0);

}

void loop() {
   String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  // 92-0-130

 String command;
    if ( command == "يمين" || command == "Right") {
      base.write(base_angle -= 20);
    }
    if (command == "يسار" || command == "Left") {
     base.write(base_angle += 20);
    }

    if (command == "اعلى" || command == "Top") {
      shoulder.write(shoulder_angle -= 20);
    }

   if (command == "اسفل" || command == "Bottom") {
     shoulder.write(shoulder_angle += 20);
    }
  // use this text format to enter the angles by using the serial monitor:
  // notice that all the angles in degree 
  if (Serial.available() > 0) {
    data = Serial.readString(); //occupies 4 angles
    Serial.print(data);
    angle1 = data.substring(0, data.indexOf(",")).toDouble();
    Serial.print("base angle: ");
    Serial.println(angle1);
    data1 = data.substring(data.indexOf(",")+1, data.indexOf("\n")); //occupies last 3 angles
    angle2 = data1.substring(0, data1.indexOf(",")).toDouble();
    Serial.print("shoulder angle: ");
    Serial.println(angle2);
    data2 = data1.substring(data1.indexOf(",")+1, data1.indexOf("\n")); //occupies last 2 angles
    angle3 = data2.substring(0, data2.indexOf(",")).toDouble();
    Serial.print("elbow angle: ");
    Serial.println(angle3);
    data3 = data2.substring(data2.indexOf(",")+1, data2.indexOf("\n")); //occupies the last angle
    angle4 = data3.substring(0, data3.indexOf(",")).toDouble();
    Serial.print("wrist angle: ");
    Serial.println(angle4);
    
    base_angle=angle1; 
    shoulder_angle=angle2;
    elbow_angle=angle3;
    wrist_angle=angle4;
  
    //wrist
    if (wrist_angle < 90)
    {
      for (p = 90 ; p >= wrist_angle; p-- ) { 
        wrist.write(p);              // tell servo to go to position in variable 'p'
        delay(15);                     
      }
    }
    else if (wrist_angle > 90)
    {
      for (p = 90; p <= wrist_angle; p++) { 
        wrist.write(p);              // tell servo to go to position in variable 'p'
        delay(15);                    
      }
    }
  
    //elbow
    if (elbow_angle < 90)
    {
      for (p = 90; p >= elbow_angle; p--) { 
        elbow.write(p);             
        delay(15);                       
      }
    }
    else if (elbow_angle > 90 )
    {
      for (p = 90; p <= elbow_angle; p++) { 
        elbow.write(p);              
        delay(15);                       
      }
    }
    
    //shoulder
    if (shoulder_angle < 90)
    {
      for (p = 90; p >= shoulder_angle; p--) { 
        shoulder.write(p);             
        delay(15);                     
      }
    }
    else if (shoulder_angle > 90)
    {
      for (p = 90; p <= shoulder_angle; p ++) { 
        shoulder.write(p);
        delay(15);                   
      }
    }
  
    //base
    if (base_angle < 90)
    {
      for (p = 90; p >= base_angle; p--) { 
        base.write(p);              
        delay(15);                     
      }
    }
    else if (base_angle > 90)
    {
      for (p = 90; p <= base_angle;p++) { 
        base.write(p);              
        delay(15);                      
      }
    }
  
    prev_base_angle = base_angle;
    prev_shoulder_angle = shoulder_angle;
    prev_elbow_angle = elbow_angle;
    prev_wrist_angle = wrist_angle;
    switch (gripperState){
      case 0 :
      gripper.write(60);
      gripperState = 1;
      break;
      case 1 :
       gripper.write(0);
      gripperState = 0;
      break;
    }

    Serial.println("Done!");
    Serial.println();
  }
}
