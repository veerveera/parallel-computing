#include <iostream>
#include <thread>

int k;
int number;
unsigned long long it1 = 1;
unsigned long long it2 = 1;
int num1, num2;

void emae() {

    std::cout << "Введите число для вычисления факториала: ";
    std::cin >> number;
    
    if (number <=0){
    
        std::cout << "Введите положительное число больше нуля!" << std::endl;
        abort();
    }else{
    
        if (number % 2 == 0) {
            num1 = number / 2;
            //std::cout << "От 1 до " << num1 << std::endl;
            num2 = (number - num1) + 1;
            //std::cout << "От " << num2 << "до " << number << std::endl;
        }
        else {
            num1 = number / 2;
            //std::cout << "От 1 до " << num1 << std::endl;
            num2 = (number - num1);
            //std::cout << "От " << num2 << "до " << number << std::endl;
        }
    }
}

void func(){
    
    for (k = 1; k <= num1; k++) {
        it1 = it1 * k;
    }
    for (num2; num2 <= number; num2++) {
        it2 = it2 * num2;
    }
}

int main() {

    emae();
    
    std::thread emae1Thread(func);
    std::thread emae2Thread(func);
    
    emae1Thread.join();
    emae2Thread.join();

    std::cout << number << "! = " << it1 * it2 << std::endl;
    
    return 0;

}
