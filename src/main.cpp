#include <Arduino.h>
#include <TFT_eSPI.h>

// Create tft display object.
TFT_eSPI tft = TFT_eSPI();
#define TFT_GREY 0x5AEB // New Color.

#define ts 2 			// Text Size.
#define tsp ts*12		// Text Size Pixels.
#define tbg TFT_BLACK	// Text Background Color.
int tfg = TFT_WHITE;	// Text Foreground Color.
int x = 0;				// X Position.
#define xmax 240-tsp*3	// X Position Max. (I fudged this. Might not scale.)
int xd = +1;			// X Direction.
int y = 0;				// Y Position.
#define ymax 135-tsp*3	// Y Position Max. (I fudged this. Might not scale.)
int yd = +1;			// Y Direction.

void disp(int x, int y, int fill) {
	tft.fillScreen(fill);
	tft.setTextColor(tfg, tbg);
	tft.setCursor(x, y);
	tft.println(" Roger");
	tft.setCursor(x, y+tsp);
	tft.println(" Luvs");
	tft.setCursor(x, y+tsp*2);
	tft.println("Bonnie");
}

// Text foreground colors.
int fgcolors[] = {TFT_WHITE, TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_GREEN, TFT_BLUE, TFT_PURPLE, TFT_VIOLET, TFT_GREY, TFT_PINK};

int newcolor() {
	return fgcolors[random(0, sizeof(fgcolors)/sizeof(int)-1)];
}

void setup() {
	Serial.begin(115200);		// Init Serial.
	Serial.println("Bounce!");	// Identify yourself!

	// Init TFT.
	tft.init();
	tft.setRotation(1);			// Landscape TTGO to the left.
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
		// Change text color.
		tfg = newcolor();
	}
	
	// Update Y.
	y += yd;
	// Hit wall?
	if(y < 0 || y > ymax){
		// Yes, change direction.
		yd *= -1;
		y += yd;
		// Change text color.
		tfg = newcolor();
	}
	
	// Delay timer.
	delay(100);
}
