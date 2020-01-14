
int kasnjenje=1;

void setup() {
  pinMode(13, OUTPUT); //D1
  pinMode(12, OUTPUT); //D2
  pinMode(11, OUTPUT); //D3
  pinMode(10, OUTPUT); //D4
  
  pinMode(8, OUTPUT); //g
  pinMode(7, OUTPUT); //f
  pinMode(6, OUTPUT); //e
  pinMode(5, OUTPUT); //d
  pinMode(4, OUTPUT); //c
  pinMode(3, OUTPUT); //b
  pinMode(2, OUTPUT); //a

}

void zero(){
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
  digitalWrite(8,HIGH);
  }

void one(){
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);

  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(8,HIGH);
  }

void two(){
  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
   digitalWrite(6,LOW);
  digitalWrite(8,LOW);
 
  }

void three(){
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(8,LOW);
  
  }

void four(){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(2,HIGH);

    digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  
  }

void five(){
  digitalWrite(3,HIGH);
  digitalWrite(6,HIGH);
  
   digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
 
  }

void six(){
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(2,LOW);

    digitalWrite(3,HIGH);

  }

void seven(){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);

    digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
  
  }

void eight(){
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
  }

void nine(){
  digitalWrite(6,HIGH);
  
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);


  }
  
void error(){
  digitalWrite(13,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(2,LOW);
  delay(kasnjenje);
  pogasi();
  digitalWrite(12,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(2,LOW);
  delay(kasnjenje);
  pogasi();
  digitalWrite(11,HIGH);
  
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(2,LOW);
  delay(kasnjenje);
  pogasi();
  }

  void pogasi(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
    }

  void upalicifru(int cifra, int brcif){  //ako je broj veci od 9 ili od 4 ili manji od 1 izbaci gresku
        if(cifra > 9 || brcif > 4 || brcif < 1) {
            error(); 
            return;  
          }
        digitalWrite(brcif+9,HIGH); //br cifara prima ova fja i max iznosi 3 tako da se ova naredba pali segmente do ,9+1,9+2,9+3 tj pali segmente 10,11,12,13 tj cifre d1 d2 d3 jer su one na tim pinovima
        if(cifra == 0) zero(); // parametar cifra isto prima ova fja i ovisno koja je pozivaju se one gore fje koje pale segmente ovisno koja je cifra u pitanju
        else if(cifra == 1) one();
        else if(cifra == 2) two();
        else if(cifra == 3) three();
        else if(cifra == 4) four();
        else if(cifra == 5) five();
        else if(cifra == 6) six();
        else if(cifra == 7) seven();
        else if(cifra == 8) eight();
        else if(cifra == 9) nine();
        delay(kasnjenje);
    }

  void ispisi(int n){ 
       if(n > 9999) {
         pogasi();
          error(); 
          return;
        }
        int i=0;
        if(n<10) i=180; //postavljamo brojace u ovisnosti parametra n
        else if(n>10 && n < 100) i=90;
        else if(n>100 && n < 1000) i =60;
        else i=50; 
        for(; i>0; i--){  //
       int brcif=1;
       int br=n;
       do{
          pogasi();
          upalicifru(br%10,brcif);
          brcif++; //   uvecavamo br cifara
          br=br/10; // dijelimo da bismo otkinuli cifru cifra % 10, pa cifra /10 je nacin kako izdvajamo cifru ovo sa % smo vec poslali fji
        }while(br != 0); // vrti petlju sve dok sve cifre ne dobijemo
        }
    }

void loop() { // petlja za ispisivanje 
 
  for(int i=0; i<10000; i++){
       ispisi(i);
    } 
}
