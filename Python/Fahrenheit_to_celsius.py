def fahrenheit_to_celsius(start_temperature, end_temperature):
  '''
  number, number -> float
  
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
    print(str(fahrenheit)+'°F', 'is', str(round((fahrenheit - 32) * 5/9, ndigits=4))+'°C')  # Celsius = (Fahrenheit - 32) * 5/9  (Formula to convert temperature from °Fehrenheit to °Celsius)
    

if __name__=="__main__":
  fahrenheit_to_celsius(32, 212)                              # Here inputs are start_temperature and end_temperature of any desired range
  print('\n')
  fahrenheit_to_celsius(212, 1832)
