celsiusToFahrenheit :: Float -> Float 
celsiusToFahrenheit celsius = (celsius * 9/5) + 32

fahrenheitToCelsius :: Float -> Float
fahrenheitToCelsius fahrenheit = (fahrenheit - 32) * 5/9

celciusToKelvin :: Float -> Float
celciusToKelvin celsius = celsius +  273.15

kelvinToCelsius :: Float -> Float
kelvinToCelsius kelvin = kelvin - 273.15

fahrenheitToKelvin :: Float -> Float
fahrenheitToKelvin fahrenheit = celciusToKelvin(fahrenheitToCelsius fahrenheit)

kelvinToFahrenheit :: Float -> Float
kelvinToFahrenheit kelvin = celsiusToFahrenheit( kelvinToCelsius kelvin)


main = do
    print(celsiusToFahrenheit 20)
    print(fahrenheitToCelsius 20)
    print(celciusToKelvin 20)
    print(kelvinToCelsius 20)
    print(fahrenheitToKelvin 20)
    print(kelvinToFahrenheit 20)
