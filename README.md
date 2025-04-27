# Bistro 92 Smart Ordering System

## Overview
Welcome to **Bistro 92’s Smart Ordering System**! This system brings a modern twist to restaurant service, allowing customers to place their orders directly from the table. With the help of an ESP32-based device, the entire dining experience becomes smoother and more efficient. Say goodbye to long wait times and hello to a more enjoyable dining experience.

## Features
- **Instant Order Placement**: Customers can browse the menu, select items, adjust quantities, and place orders all from the table.
- **Admin Dashboard**: Kitchen staff and restaurant managers can track live orders and manage them seamlessly from a real-time dashboard.
- **User-Friendly Interface**: With just four buttons, customers can easily navigate through the menu, select items, and finalize their orders.
- **Real-Time Cloud Sync**: Orders are transmitted to the cloud and displayed on the kitchen's system, ensuring no order is missed.
- **Order Reset**: If needed, customers can cancel or reset their order at any time by pressing a button.

## How It Works
1. **Main Menu Navigation**: 
   - Press Button 1 to access the main menu.
   - Use Buttons 3 and 4 to scroll through the menu items.
2. **Select Item & Adjust Quantity**: 
   - Press Button 2 to select a menu item.
   - Adjust quantity by using Buttons 3 (increase) or 4 (decrease).
3. **Finalizing the Order**: 
   - Press and hold Button 2 to submit the order.
   - The order data is sent to the cloud, where it’s instantly updated in the kitchen's dashboard.
4. **Resetting the Order**: 
   - Press Button 1 at any time to reset the order and return to the main menu.

## Installation Guide
1. **Setup**: Install the necessary libraries and configure your Arduino IDE to work with the ESP32.
2. **Upload the Code**: Upload the provided code to your ESP32.
3. **Wi-Fi Connection**: Connect the ESP32 to your local Wi-Fi network for cloud integration.
4. **Google Sheets Integration**: Use Google Apps Script to set up a cloud-based admin dashboard that tracks orders in real-time.

## Benefits
- **Faster Service**: With orders sent directly to the kitchen, food preparation is faster.
- **Reduced Wait Times**: No need to wait for a waiter, customers can place their orders as soon as they’re ready.
- **Improved Order Accuracy**: Direct interaction with the ordering system reduces the chances of mistakes.
- **Real-Time Monitoring**: Managers and staff can monitor the entire process and ensure a smooth operation.

## Contributing
We’re always open to improvements! If you have any ideas or would like to contribute, feel free to fork the repository and submit a pull request. If you find any issues, please report them via GitHub Issues.

## License
This project is licensed under the MIT License. Feel free to use, modify, and share it!
