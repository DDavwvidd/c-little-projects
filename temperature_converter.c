#include <stdio.h>


float celsiusToFahrenheit(int celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}
float fahrenheitToCelsius(int fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}


float celsiusToKelvin(int celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}
float kelvinToCelsius(int kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}


float fahrenheitToKelvin(int fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    float kelvin = celsiusToKelvin(celsius);
    return kelvin;
}
float kelvinToFahrenheit(int kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    float fahrenheit = celsiusToFahrenheit(celsius);
    return fahrenheit;
}

int main() {
    int operation, valueToConvert = 0;
    float result = 0;

    printf("\033[0;32mTemperature coverter\n\033[0m"
    "1. Celsius to Fahrenheit\n"
    "2. Fahrenheit to Celsius\n"
    "3. Celsius to Kelvin\n"
    "4. Kelvin to Celsius\n"
    "5. Fahrenheit to Kelvin\n"
    "6. Kelvin to Fahrenheit\n"
    "> "
    );
    scanf("%d", &operation);
    
    if (operation != 1 && operation != 2 && operation != 3 && operation != 4 && operation != 5 && operation != 6) {
        printf("\033[0;31mError - wrong option\n\033[0m");
        return 1;      
    }
    
    printf("\033[0;32mEnter value of unit you want to covert\n\033[0m> ");
    if (scanf("%d", &valueToConvert) != 1) {
        printf("\033[0;31mError - string entered instead of number\n\033[0m");
        return 1;
    }


    switch (operation) {
    case 1:
        result = celsiusToFahrenheit(valueToConvert);
        break;
    case 2:
        result = fahrenheitToCelsius(valueToConvert);
        break;
    case 3:
        result = celsiusToKelvin(valueToConvert);
        break;
    case 4:
        result = kelvinToCelsius(valueToConvert);
        break;
    case 5:
        result = fahrenheitToKelvin(valueToConvert);
        break;
    case 6:
        result = kelvinToFahrenheit(valueToConvert);
        break;
    default:
        break;
    }
    
    printf("\033[0;32mResult is: %f\n\033[0m>", result);
    return 0;
}
