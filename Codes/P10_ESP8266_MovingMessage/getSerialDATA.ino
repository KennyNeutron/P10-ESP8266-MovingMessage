void get_SerialData() {
  if (Serial.available() > 0) {  // Save message from serial
    Message = Serial.readString();
    //Serial.println("SIZE:" + String(Message.length()));
    HEADER = Message[0];
    FOOTER = Message[Message.length() - 1];



    if (Message[2] >= '1' && Message[2] <= '9') {

      //Serial.println("SIZEITWODIGIT");
      getScrollSpeedTens = Message[1] - 48;
      getScrollSpeedOnes = Message[2] - 48;
      getFONT = Message[3] - 48;
    } else {

      //Serial.println("SIZEISONEDIGIT");
      getScrollSpeedTens = 0;
      getScrollSpeedOnes = Message[1] - 48;
      getFONT = Message[2] - 48;
    }

    switch (getFONT) {
      case 1:
        P10.setFont(FONT1);
        break;
      case 2:
        P10.setFont(FONT2);
        break;
      case 3:
        P10.setFont(FONT3);
        break;
      case 4:
        P10.setFont(FONT4);
        break;
      case 5:
        P10.setFont(FONT5);
        break;
      case 6:
        P10.setFont(FONT6);
        break;
      case 7:
        P10.setFont(FONT7);
        break;
      case 8:
        P10.setFont(FONT8);
        break;
    }



    getScrollSpeed = 100 - ((getScrollSpeedTens * 10) + getScrollSpeedOnes);

    /*
    Serial.print("DT:");
    Serial.println(getScrollSpeedTens);
    Serial.print("DO:");
    Serial.println(getScrollSpeedOnes);
    Serial.print("rcvd SPEED:");Serial.println(((getScrollSpeedTens * 10) + getScrollSpeedOnes));
    Serial.print("FONT:");
    Serial.println(getFONT);
    */

    //Serial.println("SCROLL SPEED:" + String(getScrollSpeed));

    if (HEADER == 0x5B && FOOTER == 0x5D) {
      
      Serial.println("SET!");

      char char_MessageTEMP[Message.length() + 1];

      unsigned int a = 0;
      while (Message[a] != ',') {
        a++;
      }

      a++;
      unsigned int b = 0;
      Serial.println(a);

      while (a != (Message.length() - 2)) {
        char_MessageTEMP[b] = Message[a];
        Serial.println(char_MessageTEMP[b]);

        a++;
        b++;
      }
      

      Message=char_MessageTEMP;

    }
  }
}