const int tombol = 2;
const int lampu = 3;

int kondisitombol = 0;
int kondisitombolterakhir = 0;
int kondisilampu = 0;

int mati = 0;
int redup = 128;
int terang = 255;

void setup() {
  pinMode(tombol, INPUT_PULLUP);
  pinMode(lampu, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  kondisitombol = digitalRead(tombol);
  if (kondisitombol == LOW && kondisitombolterakhir == HIGH){
    kondisilampu++;
    if (kondisilampu > 2){
      kondisilampu = 0;
     } 
     if (kondisilampu == 0){
      analogWrite(lampu, mati);
     }
     if (kondisilampu == 1){
      analogWrite(lampu, redup);
     }
     if (kondisilampu == 2){
      analogWrite(lampu, terang);
     }
     delay(50);
  }
  Serial.println(kondisilampu);
  kondisitombolterakhir = kondisitombol;  
}
