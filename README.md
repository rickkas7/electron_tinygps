# electron_tinygps

*Using the Particle Electron AssetTracker with TinyGPS++*

I prefer to use the [TinyGPS++ library] (https://github.com/mikalhart/TinyGPSPlus) for handing the GPS on the Particle Electron AssetTracker GPS module. It seems more reliable at parsing the GPS data. 


## 01simple

This example uses both the GPS and cellular and every 2 minutes either publishes the current latitude and longitude or "no location" if there is no location.


## 02cellularonoff

This example program is a test that specifically mixes in cellular modes. When you first start the program cellular will be off and the GPS will try to get a fix. 

Status information is printed to the USB serial port, including the latitude and longitude every 5 seconds.

When you press the MODE button on the Electron, it will turn on the cellular modem and try to connect to the cloud. It will then publish the current GPS coordinates every 2 minutes (assuming it has a fix).

When you press the MODE button again, it will disconnect.




