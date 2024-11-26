#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

// Structure to store order details
struct Order {
    int id;            
    string symbol;     
    string type;       
    double order_price; 
    int quantity;      

    bool operator<(const Order& other) const {
        return order_price > other.order_price; 
    }
};

// Structure to store tick details
struct Tick {
    string symbol;     
    double price;      
    string timestamp;  
};

// Class representing the Order Book to manage the orders and ticks
class OrderBook {
private:
    map<string, priority_queue<Order>> order_map; 
    queue<Tick> tick_queue; 
    int order_id_counter = 1; 

public:

    void addOrder(const string& symbol, const string& type, double price, int quantity) {
        Order order = {order_id_counter++, symbol, type, price, quantity};
        order_map[symbol].push(order);
    }

    void newTick(const string& symbol, double price, const string& timestamp) {
        Tick tick = {symbol, price, timestamp};
        tick_queue.push(tick);

        processTick();
    }

private:
    void processTick() {
    
        while (!tick_queue.empty()) {
            Tick current_tick = tick_queue.front();
            tick_queue.pop();

            auto& order_queue = order_map[current_tick.symbol];

            while (!order_queue.empty() && order_queue.top().order_price >= current_tick.price) {
                Order order = order_queue.top();
                order_queue.pop();
                cout << "Order " << order.id << " executed at " << current_tick.timestamp
                     << ", Price: " << current_tick.price
                     << ", Quantity: " << order.quantity << endl;
            }
        }
    }
};


int main() {
    OrderBook order_book;

    // Adding orders
    order_book.addOrder("AAPL", "BL", 100, 10); 
    order_book.addOrder("AAPL", "BL", 105, 5);  
    order_book.addOrder("AAPL", "BL", 102, 15); 
    order_book.addOrder("AAPL", "BL", 98, 15);  
    order_book.addOrder("GOOG", "BL", 200, 10); 
    order_book.addOrder("GOOG", "BL", 201, 15); 
    order_book.addOrder("GOOG", "BL", 198, 10); 

    // Adding ticks
    order_book.newTick("AAPL", 106, "08:58");  
    order_book.newTick("AAPL", 104, "09:00");  
    order_book.newTick("AAPL", 102, "09:01");  
    order_book.newTick("AAPL", 98, "09:02");   
    order_book.newTick("GOOG", 200, "09:03");  

    return 0;
}
