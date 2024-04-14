import spidev
from gpiozero import PWMOutputDevice
import time

# define SPI connection
spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz= 1000000

# define linaer actuator pin
actuator_pin = 18
actuator = PWMOutputDevice(actuator_pin)


# Read Temperature
def read_temp():
    adc = spi.xfer([1, 0, 0])
    print(adc)
    temp = ((adc[1] & 0x3) << 8) + adc[2]
    return temp

print("Commencing temp reading")

# main temp collibration/reading and actuator 
while True:
    temp = read_temp()
        
    temp_celsius = temp / 19
    if (temp_celsius < 32 and temp_celsius >20):
        print("temperature: {:.2f} 'C",format(temp_celsius),"COLD");
        actuator.value = 0   # this is the lowest value for retracting the actuator
        print("Actuator retracting")
        time.sleep(2)
        continue
    if(temp_celsius >0 and temp_celsius <18):
        print("temperature: {:.2f} 'C",format(temp_celsius+60),"TOO HOT");
        actuator.value = 0.5  # this is halfway for expanding the actuator
        print("Actuator expanding")
    else:
        print("temperature: {:.2f} 'C",format(temp_celsius),"HOT");
        actuator.value = 0.5
        print("Actuator expanding")
        
    time.sleep(2)
            
            
       
    
#except keyboardInterrupt:
    #spi.close()
    #print("SPI Connection Closed")
#num_cnt =0;
#while True:
#    print(num_cnt)
#    to_send = [0x19, 0x21, 0x20]
#    print(spi.xfer(to_send))
#    print(spi.readbytes(3))
#    time.sleep(2)
#    num_cnt+=1;
          
#print("-----------------out of loop-------------------")