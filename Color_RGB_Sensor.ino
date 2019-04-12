//Tawfiq Jawhar
//Dawson Hackathon 2019
//Color RGB Sensor sample code

#define S0 4
#define S1 5
#define S2 6
#define S3 7

#define sensorOut 9


int redFrequency = 0;
int greenFrequency =0;
int blueFrequency=0;

void setup() {
  // put your setup code here, to run once:


  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);

  pinMode(S2, OUTPUT);

  pinMode(S3, OUTPUT);

  pinMode(sensorOut, INPUT);


  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  redFrequency = pulseIn(sensorOut, LOW);

  
  Serial.print(redFrequency);
  Serial.print(" ");

  delay(100);


  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  greenFrequency = pulseIn(sensorOut, LOW);

  Serial.print(greenFrequency);
  Serial.print(" ");


  delay(100);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  blueFrequency = pulseIn(sensorOut, LOW);

  Serial.print(blueFrequency);
  Serial.print("\n");

  delay(100);


  //479  1064  1050
  //696 1572  1563
  //651.5 1496  1457
  //635.7 1453  1427.35

  if(redFrequency >= 470 && redFrequency <= 700)
    Serial.print("RED\n");
  else
    Serial.print("NOT RED\n");



  
  delay(1000);
  
}
