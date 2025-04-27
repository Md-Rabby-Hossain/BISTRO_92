Bistro 92 Smart Ordering System

Welcome to the Bistro 92 Smart Ordering System! This project aims to transform the dining experience by allowing customers to place orders directly from their table using a simple, intuitive smart device.

Table of Contents
Overview

How It Works

Features

Installation

Usage

Contributing

License

Overview
At Bistro 92, long dinner lines and busy staff were a challenge. By integrating a smart ordering system with an ESP32, we enhanced the dining experience by enabling customers to place orders directly from their table. The device connects to the cloud, allowing the kitchen staff to receive orders instantly and improve overall service.

How It Works
Main Menu Access: Press Button 1 to open the main menu on the OLED display.

Browse the Menu: Use Buttons 3 and 4 to scroll through the menu.

Select Item & Adjust Quantity: Button 2 brings up a quantity dialog to add items to the cart. Use Button 3 to increase quantity, Button 4 to decrease it.

Place Order: Long-press Button 2 to finalize the order. The data is sent to the cloud for real-time tracking.

Reset Order: Press Button 1 at any time to reset the order and return to the main menu.

Features
Real-time Order Placement: Orders are sent directly to the kitchen via Wi-Fi.

Admin Dashboard: Managers can track order status and total sales in real-time.

Easy-to-Use Interface: Navigation is simple with just four buttons.

Cloud Integration: Orders are instantly updated and displayed on a central system.

Installation
Set Up Your ESP32: Make sure you have the ESP32 board set up in your Arduino IDE.

Upload the Code: Upload the provided code to your ESP32.

Connect to Wi-Fi: Ensure your ESP32 is connected to Wi-Fi.

Set Up Google Sheets: Use the Google Apps Script to receive orders on your admin dashboard.

Usage
Once the system is set up, customers can interact with the device to place orders.

The staff can monitor and process orders efficiently using the admin dashboard, ensuring a smoother service flow.

Contributing
We welcome contributions! Feel free to fork the repository and submit pull requests. For any issues or suggestions, open an issue on the GitHub repository.

License
This project is licensed under the MIT License.
