
//#include <OneWire.h>
//#include <DallasTemperature.h>
/*
  Character analysis operators

  Examples using the character analysis operators.
  Send any byte and the sketch will tell you about it.

  created 29 Nov 2010
  modified 2 Apr 2012
  by Tom Igoe

  This example code is in the public domain.
  Added printing in HEX and Binary - 25 March 2021
  Also changed it's to it is and that's to that is
*/
//#include <MicroView.h>
void setup()
{
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_BUILTIN, OUTPUT);
	// Open serial communications and wait for port to open:
	Serial.begin(9600);
	while (!Serial) {
		;		// wait for serial port to connect. Needed for native USB port only
	}

	// send an intro:
	Serial.
	    println
	    ("send any byte and I'll tell you everything I can about it");
	Serial.println();
}

void loop()
{
	// wait for a second
	// get any incoming bytes:
	if (Serial.available() > 0) {
		digitalWrite(LED_BUILTIN, HIGH);	// turn the LED on (HIGH is the voltage level)
		delay(100);	// wait for a second
		digitalWrite(LED_BUILTIN, LOW);	// turn the LED off by making the voltage LOW
		delay(100);
		int thisChar = Serial.read();

		// say what was sent:
		Serial.println("You sent me: \'");
		Serial.write(thisChar);
		Serial.print("\'            ASCII Value: ");
    Serial.println(thisChar);
    
    Serial.print("              ASCII HEX Value: ");
    Serial.println(thisChar,HEX);
    
    Serial.print("              ASCII BIN Value: ");
    Serial.println(thisChar,BIN);
    
    Serial.print("              ASCII OCT Value: ");
    Serial.println(thisChar,OCT);
//		Serial.println(thisChar);

		// analyze what was sent:
		if (isAlphaNumeric(thisChar)) {
			Serial.println("it is alphanumeric");
		}
		if (isAlpha(thisChar)) {
			Serial.println("it is alphabetic");
		}
		if (isAscii(thisChar)) {
			Serial.println("it is ASCII");
		}
		if (isWhitespace(thisChar)) {
			Serial.println("it is whitespace");
		}
		if (isControl(thisChar)) {
			Serial.println("it is a control character");
		}
		if (isDigit(thisChar)) {
			Serial.println("it is a numeric digit");
		}
		if (isGraph(thisChar)) {
			Serial.
			    println
			    ("it is a printable character that is not whitespace");
		}
		if (isLowerCase(thisChar)) {
			Serial.println("it is lower case");
		}
		if (isPrintable(thisChar)) {
			Serial.println("it is printable");
		}
		if (isPunct(thisChar)) {
			Serial.println("it is punctuation");
		}
		if (isSpace(thisChar)) {
			Serial.println("it is a space character");
		}
		if (isUpperCase(thisChar)) {
			Serial.println("it is upper case");
		}
		if (isHexadecimalDigit(thisChar)) {
			Serial.
			    println
			    ("it is a valid hexadecimaldigit (i.e. 0 - 9, a - F, or A - F)");
		}
		// add some space and ask for another byte:
		Serial.println();
		Serial.println("Give me another byte:");
		Serial.println();
	}
}
