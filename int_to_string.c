#include<stdbool.h>
#include<math.h>

int find_digit_amount_over_1(int num) {
    int amount_digits = 0;
    while(num >= pow(10, amount_digits)) {
        amount_digits++;
    }
    return amount_digits;
}

void int_to_string(int num, int amount_digits, char* buf) {
    for (int i = 0; i < amount_digits; i++) {
        buf[i] = '0';
    }
    buf[amount_digits] = '\0'; 

    int values = 0;
    int power_10 = amount_digits - 1;

    while(num > 0) {
        if (num >= pow(10, power_10)) {
            num -= pow(10, power_10);
            values++;
        } else {
            buf[amount_digits - power_10 - 1] = values + '0'; 
            power_10--;
            values = 0;
        }
    }
}

