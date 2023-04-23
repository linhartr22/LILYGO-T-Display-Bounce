#include <Arduino.h>
#include <TFT_eSPI.h>

// Create tft display object.
TFT_eSPI tft = TFT_eSPI();
#define TFT_GREY 0x5AEB // New colour

int ts = 2; 		// Text Size
int tsp = ts*12;	// Text Size Pixels
int x = 0;
int xmax = 240 - tsp*3;
int xd = +1;
int y = 0;
int ymax = 135 - tsp*3;
int yd = +1;

void disp(int x, int y, int fill) {
	tft.fillScreen(fill);
	tft.setCursor(x, y);
	tft.println(" Roger");
	tft.setCursor(x, y+tsp);
	tft.println(" Luvs");
	tft.setCursor(x, y+tsp*2);
	tft.println("Bonnie");
}

void setup() {
	Serial.begin(115200);		// Init Serial.
	Serial.println("Bounce!");	// Identify yourself!

	// Init TFT.
	tft.init();
	tft.setRotation(1);			// Landscape TTGO to the left.
	tft.setTextColor(TFT_WHITE, TFT_BLACK);
	tft.setTextSize(ts);
}

void loop() {
	// Display Message.
	disp(x, y, TFT_BLACK);
	
	// Update X.
	x += xd;
	// Hit wall?
	if(x < 0 || x > xmax){
		// Yes, change direction.
		xd *= -1;
		x += xd;
	}
	
	// Update Y.
	y += yd;
	// Hit wall?
	if(y < 0 || y > ymax){
		// Yes, change direction.
		yd *= -1;
		y += yd;
	}
	
	// Delay timer.
	delay(100);
}
