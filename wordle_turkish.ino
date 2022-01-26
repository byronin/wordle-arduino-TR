//wordle
String gelen_kelime = "HELLO", kelime[10] = {"TARAK", "SABUN" , "RAKAM", "SAYGI" , "TOPLU", "KURAL", "EKRAN", "BAHAR", "ARMUT", "RAPOR" } , fuck ;
char   secili_kelime[6], CL ;
int CLs = 0 , basari_derecesi = 0 , dongu = 0 , randoma = 0 , tekrar = 1 ;
void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println(">BASLA< yazarak başlayabilirsin.");
}

void loop() {

  while (dongu == 0 ) {

    if (Serial.available() > 0) {
      gelen_kelime = Serial.readString();
      Serial.println(gelen_kelime);
      if (gelen_kelime[0] == 'B' && gelen_kelime[1] == 'A' && gelen_kelime[2] == 'S' && gelen_kelime[3] == 'L' && gelen_kelime[4] == 'A') {

        dongu = 1 ;

      }
    }


    if (dongu == 1 || tekrar == 0 ) {

      dongu = 1 ;
      tekrar = 1 ;
      randoma = random(0 , 10);
      kelime[randoma].toCharArray(secili_kelime , 6);

      Serial.println("5 Harfli kelimeleri kullanarak 5 Hharfli gizli kelimeyi bul. ");
      Serial.println(" _ , _ , _ , _ , _  ");
      Serial.println();

      randoma = 0;
    }

  }



  if (Serial.available() > 0) {

    CL = Serial.read();

    if (CL ==  secili_kelime[CLs]) {
      Serial.print(secili_kelime[CLs]);
    } else {
      if (CL ==  secili_kelime[0]) {
        Serial.print("+");
      } else if (CL ==  secili_kelime[1]) {
        Serial.print("+");
      } else if (CL ==  secili_kelime[2]) {
        Serial.print("+");
      } else if (CL ==  secili_kelime[3]) {
        Serial.print("+");
      }  else if (CL ==  secili_kelime[4]) {
        Serial.print("+");
      } else {
        Serial.print("*");
      }



    }
    gelen_kelime[CLs] = CL;
    CLs++ ;

    if (CLs == 5) {

      Serial.println();
      Serial.println(gelen_kelime);

      basari_derecesi++;
      Serial.println();
      if (gelen_kelime == secili_kelime) {
        if (basari_derecesi == 1) {
          Serial.println("DAHİSİN");
        } else if (basari_derecesi == 2) {
          Serial.println("ÇOK BAŞARILI");
        } else if (basari_derecesi == 3) {
          Serial.println("GÜZEL İŞ");
        } else if (basari_derecesi == 4) {
          Serial.println("BAŞARILI");
        } else if (basari_derecesi == 5) {
          Serial.println("İDARE EDER");
        } else if (basari_derecesi == 6) {
          Serial.println("SONUNDA BAŞARDIN");
        }


        basari_derecesi =  0 ;
        dongu = 0 ;
        tekrar = 0 ;
      } else if ( basari_derecesi == 6 ) {
        Serial.println("MALESEF BİRAZ ŞANSA İHTİYACIN VAR");
        Serial.print("Aradığın Kelime: ");
        Serial.println(secili_kelime);
        basari_derecesi =  0 ;
        dongu = 0 ;
        tekrar = 0 ;
      } else if (basari_derecesi < 7) {
        Serial.print(6 - basari_derecesi);
        Serial.println(" defa daha deneyebilirsin.");
      }


      CLs = 0 ;
      fuck = Serial.readString();

      Serial.println();
      delay(400);
    }

  }

}
