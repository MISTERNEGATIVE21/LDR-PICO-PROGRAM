from machine import Pin
import time
 
adc = machine.ADC(Pin(27)) # use 4 for esp32
led = Pin("LED", Pin.OUT) #just for indicating its on can be outsid loop
led.toggle()
while True:
    ldr_value = adc.read_u16()
    print (ldr_value )
    if ldr_value < 2000 :
        led = Pin(16, Pin.OUT) # use 27 for esp32
        led.high()
    else:
         led = Pin(16, Pin.OUT) 
         led.low()
        
    
    time.sleep(0.0001)
        
    

    