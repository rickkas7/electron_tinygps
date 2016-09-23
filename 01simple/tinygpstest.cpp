
#include "Particle.h"

// Port of TinyGPS for the Particle AssetTracker
// https://github.com/mikalhart/TinyGPSPlus

#include "TinyGPS++.h"

/*
   This sample sketch demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object.
 */

void displayInfo(); // forward declaration

const unsigned long PUBLISH_PERIOD = 120000;

// The TinyGPS++ object
TinyGPSPlus gps;
unsigned long lastPublish = 0;

void setup()
{
	Serial.begin(9600);

	// The GPS module on the AssetTracker is connected to Serial1 and D6
	Serial1.begin(9600);

	// Settings D6 LOW powers up the GPS module
    pinMode(D6, OUTPUT);
    digitalWrite(D6, LOW);
}

void loop()
{
	while (Serial1.available() > 0) {
		if (gps.encode(Serial1.read())) {
			displayInfo();
		}
	}

}

void displayInfo()
{
	if (millis() - lastPublish >= PUBLISH_PERIOD) {
		lastPublish = millis();
		if (Particle.connected()) {
			char buf[128];
			if (gps.location.isValid()) {
				snprintf(buf, sizeof(buf), "%f,%f", gps.location.lat(), gps.location.lng());
				Particle.publish("gps", buf);
			}
			else {
				Particle.publish("gps", "no location");
			}
		}
	}
}
