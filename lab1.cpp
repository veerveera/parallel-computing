#include <iostream>
#include <thread>
#include <mutex>

int number;
unsigned long long it = 1;
int num1, num2;

std::mutex myMutex;

void emae() {

    std::cout << "Введите число для вычисления факториала: ";
    std::cin >> number;
    
    if (number <=0){
    
        std::cout << "Введите положительное число больше нуля!" << std::endl;
        abort();
    }else{
    
        if (number % 2 == 0) {
            num1 = number / 2;
            std::cout << "От 1 до " << num1 << std::endl;
            num2 = (number - num1) + 1;
            std::cout << "От " << num2 << " до " << number << std::endl;
        }
        else {
            num1 = number / 2;
            std::cout << "От 1 до " << num1 << std::endl;
            num2 = (number - num1);
            std::cout << "От " << num2 << " до " << number << std::endl;
        }
    }
}

void func(int a, int b){
    
    
    for (int k = a; k <= b; k++) {
        myMutex.lock();
        it = it * k;
        myMutex.unlock();
        std::cout << it << std::endl;
    }
}

int main() {

    emae();
    
    std::thread emae1Thread(func, 1, num1);
    std::thread emae2Thread(func, num2, number);
    
    emae1Thread.join();
    emae2Thread.join();

    std::cout << number << "! = " << it << std::endl;
    
    return 0;

}
