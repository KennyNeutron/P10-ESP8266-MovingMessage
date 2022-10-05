void get_SerialData() {
  if (Serial.available() > 0) {  // Save message from serial
    Message = Serial.readString();
    Serial.println("MESSAGE:" + String(Message));


    HEADER = Message[0];
    FOOTER = Message[Message.length() - 1];



    if (Message[2] >= '1' && Message[2] <= '9') {
      //Serial.println("SPEED IS TWO DIGIT");
      getScrollSpeedTens = Message[1] - 48;
      getScrollSpeedOnes = Message[2] - 48;
      getFONT = Message[3] - 48;
    } else {
      //Serial.println("SPEED IS ONE DIGIT");
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

      Serial.println("M:" + Message);
    }

    int Len_HUDS = 0;
    int Len_TENS = 0;  //MessageLength Tens
    int Len_ONES = 0;  //MessageLength Ones

    int Len_MSG;  //Total Length of MESSAGE

    Len_HUDS = Message[4] - 48;
    Len_TENS = Message[5] - 48;
    Len_ONES = Message[6] - 48;



    Len_MSG = (Len_HUDS * 100) + (Len_TENS * 10) + Len_ONES;

    Serial.println("MLen:" + String(Len_MSG));

    char MessageTemp[Message.length() + 1];
    int len_UART = Message.length();  //Total Length of message in UART

    int a = 0;
    while (a < len_UART) {
      MessageTemp[a] = Message[a];
      a++;
    }

    char *numStrings[6];
    char *ptr = NULL;

    byte index = 0;
    ptr = strtok(MessageTemp, ",");  // delimiter
    while (ptr != NULL) {
      numStrings[index] = ptr;
      index++;
      ptr = strtok(NULL, ",");
    }



    Serial.print("MTemp:");
    Serial.println(numStrings[1]);

    Message=numStrings[1];
  }
}