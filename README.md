# to_string_C

This code transform number types into strings in C.
> OBS: It uses a lot of the hardware for extreme numbers

---

## Functions


### int_digit_number(int number) -> unsigned int

### float_digit_number(float number) -> unsigned int

### int_to_string(int number, unsigned int amount_of_digits, char* string)
this function doesnt returns anything only takes the array provided and overwrites it with the digits of the number.  
The size of the array needs to have the amount of the digits.  
if the number is negative the string needs a byte up ( `String[size+1]` )  

### float_to_string(float number, unsigned int amount_of_digits, char* string)
this function doesnt returns anything only takes the array provided and overwrites it with the digits of the number.  
The size of the array needs to have the amount of the digits +1.  
if the number is negative the string needs a byte up ( `String[size+1]` )  

## About

This code is made as a small project for training my abilities and redoing the wheel.
