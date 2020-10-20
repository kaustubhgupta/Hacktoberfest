def fahrenheit_to_celsius(start_temperature, end_temperature):
  '''
  number -> float
  
  Return temperature converted to °Celsius where input is in °Fahrenheit
  
  >>> fahrenheit_to_celsius(-32, -30)
  -32°F is -35.5556°C
  -31°F is -35.0000°C
  -30°F is -34.4444°C
  
  >>> fahrenheit_to_celsius(32, 35)
  32°F is 0.0000°C
  33°F is 0.5556°C
  34°F is 1.1111°C
  35°F is 1.6667°C
  '''
  for fahrenheit in range (start_temperature, end_temperature + 1):
    print(str(fahrenheit)+'°F', 'is', str(round((fahrenheit - 32) * 5/9, ndigits=4))+'°C')  #Celsius = (Fahrenheit - 32) * 5/9  (Formula to convert temperature from °Fehrenheit to °Celsius)
    

if __name__=="__main__":
  fahrenheit_to_celsius(32, 212)                           #We pass the range of 32°F to 212°F which will output as 0°C and 100°C
  print('\n')
  fahrenheit_to_celsius(212, 1832)                         #Second example of range from 212°F to 1832°F which will output as 100°C to 1000°C
