#include <iostream>
#include <thread>
#include <chrono>
#include <array>

template<size_t N>
void sleep_with_increment(const std::array<int, N>& arr, size_t& index) {
    if (index < N) {
        std::this_thread::sleep_for(std::chrono::seconds(arr[index]));
        std::cout << "Slept for " << arr[index] << " seconds at index " << index << "\n";
        sleep_with_increment(arr, ++index);  // Pre-increment index
    }
}

int main() {
    std::array<int, 4> hex_array = {0x1, 0x2, 0x3, 0x5};
    size_t i = 0;
    sleep_with_increment(hex_array, i);
    return 0;
}
