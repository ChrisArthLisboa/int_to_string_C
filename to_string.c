#include<stdbool.h>
#include<math.h>
#include <stdio.h>


int int_digit_amount(int num) {
    int amount_digits = 0;

    if (num < 0) {

				num*=-1;
		}

    while(num >= pow(10, amount_digits)) {
        amount_digits++;
    }
    return amount_digits;
}

/* 
 * this function doesnt returns anything only takes the array provided and overwrites it with the digits at the number.
 * The size of the array needs to have the amount of the digits.
 * if the number is negative the string needs a byte up (String[position+1])
 */
void int_to_string(int num, int amount_digits, char* buf) {

    int base = 0;
    if (num<0) {

				buf[0] = '-';
				base = 1;
				num*=-1;

		}

    for (int i = base; i < amount_digits; i++) {
        buf[i] = '0';
    }

    buf[amount_digits+base] = '\0'; 

    int values = 0;
    int power_10 = amount_digits - 1;
		int holder = amount_digits;

		for (int i=power_10; i >= 0; i--) {

        buf[power_10 - i + base] = ( num/pow(10, i)  )+ '0';
        num = num%( (int)pow(10, i) );

		}
}

/* 
 * Finds the full amount of digits in a float
 * but the predefined size that is 47 positions
 */
int float_digit_amount(float num) {

				if (num < 0) {
								num*=-1;
				}

				int amount_digits = 0;
				
				int bigger_position = int_digit_amount((int)num);
				while (true) {
								
            bigger_position--;
            printf("%.44f | %.44f | %d\n", num, pow(10,bigger_position), amount_digits);
            if (num == 0) {
                    break;
            }
            while (num >= pow(10,bigger_position)) {
                    num = num - pow(10, bigger_position);
            }
            printf("%.3f\n", num);

            amount_digits++;

				}

				return amount_digits;

}

/* 
 * this function doesnt returns anything only takes the array provided and overwrites it with the digits at the number.
 * The size of the array needs to have the amount of the digits+1
 * if the float is negative it needs to have a byte up
 */
void float_to_string(float num, unsigned int num_of_digits, char* buf) {

    unsigned int buf_Pos = 0;
    unsigned int num_of_digits_before_dot = int_digit_amount((int) num);
    unsigned int base = 0;
    int bigger_number_pos = num_of_digits_before_dot;
    int positional_value;

    if (num < 0) {
        num *= -1;
        buf[buf_Pos] = '-';
        buf_Pos++;
        base = 1;
    }


    for ( ;buf_Pos<num_of_digits; buf_Pos++ ) {
        
        if (buf_Pos == num_of_digits_before_dot) {
            buf[buf_Pos] = '.';
            continue;
        }

        positional_value = 0;
        while (num >= pow(10, bigger_number_pos-1)) {
            positional_value++;
            num -= pow(10, bigger_number_pos-1);
        }
        buf[buf_Pos] = positional_value + '0';
        bigger_number_pos--;


    }

    buf[num_of_digits+1+base] = '\0';
}
