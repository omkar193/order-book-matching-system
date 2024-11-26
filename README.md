Here is a README file for your **Order Book Matching System**:

---

# Order Book Matching System

## Description

The **Order Book Matching System** is a simple C++ implementation that simulates order matching in a financial trading system. The system manages buy limit orders and executes them based on incoming market price ticks. It utilizes a priority queue to maintain and match orders by price, ensuring that the highest priority orders (with the lowest price for buy orders) are executed first.

This system can handle multiple symbols and allows for adding orders and processing ticks in real-time.

### Key Features:
- **Add Orders**: Allows adding buy limit orders with specified symbol, price, and quantity.
- **Process Ticks**: Accepts incoming market ticks and processes orders that meet the execution conditions (e.g., a Buy Limit order is filled when the market price is equal to or less than the order price).
- **Efficient Order Matching**: Orders are stored in a priority queue for efficient matching and removal once executed.
- **Execution Output**: When an order is executed, the system prints the order ID, execution timestamp, price, and quantity to the console.

---

## Project Structure

The project consists of a single C++ file (`main.cpp`) which contains the following key components:

- **Order Structure**: Defines order details such as ID, symbol, type, price, and quantity.
- **Tick Structure**: Defines tick details such as symbol, price, and timestamp.
- **OrderBook Class**: Manages orders and ticks. The class provides the methods `addOrder()` to add new orders and `newTick()` to process incoming ticks.
- **Main Function**: Demonstrates the usage of the `OrderBook` class by adding orders and processing ticks for different symbols.

---

## Installation & Usage

### Prerequisites

To compile and run this code, you need:
- A C++ compiler (G++ or similar)
- An IDE (like Dev C++, Code::Blocks) or an online C++ compiler

### Instructions

1. Copy the contents of the provided code into a C++ file (e.g., `main.cpp`).
2. Compile the code using your C++ compiler.
3. Run the executable to see the simulation of order matching with the given input.

Example of adding orders and processing ticks:

```cpp
order_book.addOrder("AAPL", "BL", 100, 10); 
order_book.newTick("AAPL", 106, "08:58");
order_book.newTick("AAPL", 104, "09:00");
```

---

## Example Output

When ticks are processed, the output will show which orders were executed, the price at which they were filled, and the quantity of each order. For example:

```
Order 2 executed at 09:00, Price: 104, Quantity: 5
Order 3 executed at 09:01, Price: 102, Quantity: 15
Order 1 executed at 09:02, Price: 98, Quantity: 10
Order 4 executed at 09:02, Price: 98, Quantity: 15
Order 6 executed at 09:03, Price: 200, Quantity: 15
Order 5 executed at 09:03, Price: 200, Quantity: 10
```

---

## Contribution

Feel free to fork the repository and submit pull requests for any improvements or bug fixes.

---
