 #include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Display config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Button pins
const int button1 = 12;
const int button2 = 14;
const int button3 = 27;
const int button4 = 26;

// Wi-Fi credentials
const char* ssid = "Wokwi-GUEST";  // Using Wokwi-GUEST instead of your SSID because this simulation app doesn't support connwcting wifi But using REAL ESP32 can solve this problem and we have verified that.......
const char* password = "";  // No password required for Wokwi-GUEST but password will be needed when using the real ESP32

// Google Apps Script Web App URL
const char* serverName = "https://script.google.com/macros/s/AKfycby6T_YuRErwIDHleRHBt9mqP0LmGeUPIQMmg01-mtt26R_NlHThF8cQJHoHCgpvtE0/exec";

// Menu and order details
String menu[] = {"Burger", "Pizza", "Pasta", "Sandwich"}; // can add whatever items you want
int numItems = 4;
int selectedItem = 0;
int cartQuantity[4] = {0, 0, 0, 0};
bool inMenu = false;
bool inQuantityDialog = false;
unsigned long buttonPressStart = 0;
const unsigned long longPressDuration = 1000;  // 1 second for long press

void setup() {
  Serial.begin(115200);

  // OLED setup
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Button setup
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  // Connect Wi-Fi
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.display();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  display.println("WiFi Connected");
  display.display();
  delay(1000);

  displayMainMenu();
}

void loop() {
  if (digitalRead(button1) == LOW) {
    handleButton1();
    delay(500);
  }
  if (digitalRead(button2) == LOW) {
    handleButton2();
    delay(500);
  }
  if (digitalRead(button3) == LOW) {
    handleButton3();
    delay(500);
  }
  if (digitalRead(button4) == LOW) {
    handleButton4();
    delay(500);
  }

  if (digitalRead(button2) == LOW) {
    if (millis() - buttonPressStart > longPressDuration) {
      placeOrder();
    }
  } else {
    buttonPressStart = millis();
  }
}

void handleButton1() {
  if (inQuantityDialog) {
    resetOrder();
  } else {
    displayMainMenu();
  }
}

void handleButton2() {
  if (inMenu) {
    displayQuantityDialog();
  } else if (inQuantityDialog) {
    addToCart();
  }
}

void handleButton3() {
  if (inMenu) {
    selectedItem = (selectedItem - 1 + numItems) % numItems;
    displayMainMenu();
  } else if (inQuantityDialog) {
    cartQuantity[selectedItem]++;
    displayQuantityDialog();
  }
}

void handleButton4() {
  if (inMenu) {
    selectedItem = (selectedItem + 1) % numItems;
    displayMainMenu();
  } else if (inQuantityDialog) {
    if (cartQuantity[selectedItem] > 0) {
      cartQuantity[selectedItem]--;
    }
    displayQuantityDialog();
  }
}

void displayMainMenu() {
  inMenu = true;
  inQuantityDialog = false;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Main Menu:");
  display.println("-----------");
  for (int i = 0; i < numItems; i++) {
    if (i == selectedItem) {
      display.setTextSize(2);
      display.setTextColor(SSD1306_INVERSE);
      display.println(menu[i]);
      display.setTextColor(WHITE);
      display.setTextSize(1);
    } else {
      display.println(menu[i]);
    }
  }
  display.display();
}

void displayQuantityDialog() {
  inMenu = false;
  inQuantityDialog = true;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Select Quantity:");
  display.print(menu[selectedItem]);
  display.println();
  display.print("Qty: ");
  display.println(cartQuantity[selectedItem]);
  display.display();
}

void addToCart() {
  displayMainMenu();
}

void placeOrder() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Order Placed!");
  display.display();

  String orderData = "Table: 1\n";
  for (int i = 0; i < numItems; i++) {
    if (cartQuantity[i] > 0) {
      orderData += menu[i] + " x" + String(cartQuantity[i]) + "\n";
    }
  }
  Serial.println("Order Data:");
  Serial.println(orderData);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(serverName) + "?order=" + urlencode(orderData);
    http.begin(url);
    int httpResponseCode = http.GET();
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    http.end();
  } else {
    Serial.println("WiFi Disconnected!");
  }

  delay(2000);
  resetOrder();
}

void resetOrder() {
  for (int i = 0; i < numItems; i++) {
    cartQuantity[i] = 0;
  }
  displayMainMenu();
}

String urlencode(String str) {
  String encodedString = "";
  char c;
  char code0;
  char code1;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (c == ' ') {
      encodedString += '+';
    } else if (isalnum(c)) {
      encodedString += c;
    } else {
      code1 = (c & 0xf) + '0';
      if ((c & 0xf) > 9) code1 = (c & 0xf) - 10 + 'A';
      c = (c >> 4) & 0xf;
      code0 = c + '0';
      if (c > 9) code0 = c - 10 + 'A';
      encodedString += '%';
      encodedString += code0;
      encodedString += code1;
    }
  }
  return encodedString;
}
