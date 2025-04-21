#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Radar parameters
#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)
#define RADIUS 30

void setup() {
  // Initialize display
  if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C)) {
    // Display initialization failed
    for (;;);
  }

  display.clearDisplay();
  drawStaticRadar();
}

void drawStaticRadar() {
  // Draw radar circle
  display.drawCircle(CENTER_X, CENTER_Y, RADIUS, SSD1306_WHITE);

  // Draw static needle
  int needleX = CENTER_X + RADIUS;
  int needleY = CENTER_Y;
  display.drawLine(CENTER_X, CENTER_Y, needleX, needleY, SSD1306_WHITE);

  // Draw placeholder dots
  display.fillCircle(CENTER_X + 10, CENTER_Y - 15, 2, SSD1306_WHITE); // Dot 1
  display.fillCircle(CENTER_X - 20, CENTER_Y + 10, 2, SSD1306_WHITE); // Dot 2
  display.fillCircle(CENTER_X + 5, CENTER_Y + 20, 2, SSD1306_WHITE); // Dot 3

  display.display();
}

void loop() {
  // Do nothing (static display)
}