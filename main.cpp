#include <iostream>
#include <thread>
#include <chrono>
#include <array>
//add delay before packet emission
void regular_function() {
    int index = 0;
    std::array<int, 4> hex_array = {0x1, 0x2, 0x3, 0x5};
         
    for (int i = 0; i < 100; i++) {
        if (index < hex_array.size()) { 
            std::this_thread::sleep_for(std::chrono::microseconds(hex_array[index]));  // Fixed variable name
            std::cout << "Simulated signal sent at " << hex_array[index] << " microseconds for array index " << index << "\n";
            index++;  // Added increment to progress through array
        }
        
        std::cout << i << "\n";  // Added newline for better readability
    }
}

int main() {
    regular_function();
    return 0;
}
