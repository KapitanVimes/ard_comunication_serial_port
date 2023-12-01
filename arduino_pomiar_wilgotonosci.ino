int moist_sensor = A0;

void setup() {

  Serial.begin(9600);

}
void pomiar(){
  int measure,measure_mapped;
  measure = analogRead(moist_sensor);
  measure_mapped = map(measure,1023,0,0,100);
  Serial.println(measure_mapped);
 

}

void loop() {
if (Serial.available()){
 int data = Serial.read();
  if(data=='A'){
  pomiar();
  }
}
}
