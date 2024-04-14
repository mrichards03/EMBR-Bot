import spidev
import time

spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz= 1000000

def read_temp():
    adc = spi.xfer([1, 0, 0])
    print(adc)
    temp = ((adc[1] & 0x3) << 8) + adc[2]
    return temp

print("Commencing temp reading")


while True:
    temp = read_temp()
        
    temp_celsius = temp / 18
    if (temp_celsius < 32):
        print("temperature: {:.2f} 'C",format(temp_celsius),"COLD");
    else:
        print("temperature: {:.2f} 'C",format(temp_celsius),"HOT");
            
            
       
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