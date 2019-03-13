/*
 Name:		RFID_Essai_2.ino
 Created:	29/01/2019 17:06:08
 Author:	adri_
*/

// the setup function runs once when you press reset or power the board

#include "Arduino.h"
#include "RFID.h"
#include "SPI.h"

RFID rfid(10, 9);
int UID[5];

void setup() {
	Serial.begin(9600);
	SPI.begin();
	rfid.init();
	Serial.println("HELLO!");
}

// the loop function runs over and over again until power down or reset
void loop() {
	//Serial.println("Debut loop");
	if (rfid.isCard()) {
		Serial.println("isCard");
		if (rfid.readCardSerial()) {
			Serial.println("L'UID est: ");
			for (int i = 0;i <= 4;i++)
			{
				UID[i] = rfid.serNum[i];
				Serial.println(UID[i], DEC);
				//Serial.println(".");
			}
				if (UID[0] == 192 && UID[1] == 40 && UID[2] == 126 && UID[3] == 122 && UID[4] == 236)
				{
					Serial.println("Carte");
				}
				if (UID[0] == 196 && UID[1] == 201 && UID[2] == 78 && UID[3] == 57 && UID[4] == 122)
				{
					Serial.println("Badge");
				}
			
			Serial.println("");
		}
		rfid.halt();
	}
	delay(10);
}
