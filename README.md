Evenings at Bistro 92 – Smart Ordering System
Description
The Smart Ordering System for Bistro 92 transforms the traditional dining experience by placing an intuitive ordering device on each table. This system empowers customers to interact with the menu, select items, adjust quantities, and submit their orders directly to the kitchen via a cloud-based system, making the ordering process smooth and hassle-free.

With this system:

Customers can browse the menu, select items, adjust quantities, and place their orders without waiting in line.

Kitchen staff receive orders instantly, ensuring faster food preparation and better service.

Managers can track order statuses, completed meals, and total sales in real time via an admin dashboard.

The goal is to reduce wait times, improve service efficiency, and increase customer satisfaction.

Features
Menu Access and Navigation:

Button 1: Opens the main menu, interrupting any ongoing process.

Button 3 and Button 4: Used to scroll through the menu items.

Item Selection and Quantity Adjustment:

Button 2: Confirms item selection and opens the quantity dialog.

Button 3: Increases the quantity of the selected item.

Button 4: Decreases the quantity of the selected item.

Button 2: Adds the selected item to the cart and returns to the main menu.

Order Finalization:

Long press on Button 2: Submits the order to the cloud system.

Cloud Integration: Order data, including table number, items, and quantities, is transmitted to the cloud and displayed on the admin dashboard.

Order Reset:

Button 1: Cancels the current order and returns to the main menu for a fresh start.

Requirements
Hardware:

ESP32 Development Board

OLED Display (128x64)

4 Push Buttons for menu navigation and item selection

Wi-Fi Connection

Google Apps Script Web App for cloud data handling

Software:

Arduino IDE

Adafruit SSD1306 and Adafruit GFX libraries

WiFi and HTTPClient libraries for ESP32

Setup and Installation
Install Libraries:

Open Arduino IDE, go to Sketch > Include Library > Manage Libraries.

Install the following libraries:

Adafruit SSD1306

Adafruit GFX

WiFi

HTTPClient

Connect Hardware:

Connect the ESP32 to your computer and ensure the OLED display is connected to the appropriate pins.

The buttons should be connected to the pins: Button1 (D12), Button2 (D14), Button3 (D27), Button4 (D26).

Upload Code:

Open the Arduino IDE, select the correct ESP32 board and port.

Copy and paste the code into the IDE and click Upload.

Wi-Fi Setup:

Modify the ssid and password variables in the code to match your Wi-Fi credentials.

Google Apps Script Web App:

Set up a Google Apps Script Web App to handle the order data and send it to the cloud.

Update the serverName variable in the code with the correct URL for the Google Apps Script Web App.

How to Use
Start: When the system starts, the OLED display shows the main menu.

Select Items: Use Button 3 and Button 4 to scroll through the menu and press Button 2 to select an item.

Adjust Quantity: After selecting an item, adjust the quantity with Button 3 (increase) and Button 4 (decrease).

Add to Cart: Once the quantity is set, press Button 2 again to add the item to the cart.

Place Order: After selecting all items, hold Button 2 for a long press to submit the order.

Order Reset: At any time, press Button 1 to cancel the current order and return to the main menu.

Future Improvements
Payment Integration: Add functionality for online payment or cash payment confirmation.

Order Modification: Allow customers to modify the order after placement before the food is prepared.

Advanced User Interface: Improve the user interface with more interactive options, such as images for each menu item.

Mobile App Integration: Extend the functionality by creating a mobile app that interacts with the ordering system.

License
This project is open-source under the MIT License. You are free to modify and distribute it as long as you credit the original author.
