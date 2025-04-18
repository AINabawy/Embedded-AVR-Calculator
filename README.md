🚧 This project was built during my early learning phase. I plan to refactor it as I grow.

# 🔢 AVR Calculator Project (Keypad + LCD)

This is a simple calculator built using AVR microcontroller (ATmega32), 4x4 Keypad, and 16x2 LCD. The calculator can perform basic arithmetic operations: addition, subtraction, multiplication, and division.

## 🛠️ Hardware Used

- ATmega32 Microcontroller
- 4x4 Matrix Keypad
- 16x2 LCD Display
- Crystal Oscillator (optional for accurate timing)
- Breadboard, jumper wires, resistors

## ⚙️ Features

- Read user input through the keypad
- Display inputs and results on LCD
- Perform the following operations:
  - Addition (+)
  - Subtraction (−)
  - Multiplication (×)
  - Division (÷)
  - Mod(%)
- Real-time input handling and error checking

## 🧠 How It Works

1. User inputs numbers and operation through the keypad.
2. The microcontroller reads each key press and stores the operands and operator.
3. Once "=" is pressed, the result is calculated and displayed on the LCD.
4. Handles multiple digits and clears screen on demand.
