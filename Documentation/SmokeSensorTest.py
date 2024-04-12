#BME680 Temperature, Humidity and Gas Sensor 

import time
import bme680

#initialize the sensor
smokeSensor = bme680.BME680(i2c_addr=0x77)

#adjust sensor settings
smokeSensor.set_humidity_oversample(bme680.OS_2X)
smokeSensor.set_pressure_oversample(bme680.OS_4X)
smokeSensor.set_temperature_oversample(bme680.OS_8X)
smokeSensor.set_filter(bme680.FILTER_SIZE_3)
    
#initialize the filters
smokeSensor.set_gas_status(bme680.ENABLE_GAS_MEAS)
#set gas heater to 320C for 150ms 
smokeSensor.set_gas_heater_temperature(320)
smokeSensor.set_gas_heater_duration(150)
smokeSensor.select_gas_heater_profile(0)
    
    
    

print('\n\nPolling:')
try:
  while True:
    if smokeSensor.get_sensor_data():
       print("Temperature: {:.2f} C".format(smokeSensor.data.temperature))
       print("Pressure: {:.2f} hPa ".format(smokeSensor.data.pressure))
       print("Humidity: {:.2f} %".format(smokeSensor.data.humidity))

       if smokeSensor.data.heat_stable:
                print("Gas resistance: {:.2f} Ohms".format(
                     smokeSensor.data.gas_resistance))
       else:
                print("Gas resistance: sensor heating up...")
    time.sleep(1)
except KeyboardInterrupt:
   print("Measurement stopped")
         




