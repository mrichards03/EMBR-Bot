import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Temperature
import spidev
import time

class TemperaturePublisher(Node):
    def __init__(self):
        super().__init__('temperature_publisher')
        self.publisher_ = self.create_publisher(Temperature, 'temperature', 10)
        self.timer = self.create_timer(1, self.publish_temperature)
        # Load the SPI object
        self.spi = spidev.SpiDev()   
        # Open the SPI device in the Bus 3 and the device 0
        self.spi.open(3, 0)  
        self.spi.mode = 0b00
        self.spi.bits_per_word = 8  
        self.get_logger().info('Temperature Publisher node initialized')

    def read_temp(self):
        self.spi.xfer([0x01])  # Start temperature conversion
        time.sleep(0.3)  # Wait for conversion to complete (TC1 typically takes around 250 ms)
        adc_data = self.spi.xfer([0x00, 0x00])  # Read temperature data from TC1
        # Convert ADC data to temperature in degrees Celsius
        raw_adc = ((adc_data[0] & 0x0F) << 8) + adc_data[1]
        temperature = ((raw_adc / 4096) * 3300 - 500) / 10  # Formula from TC1 datasheet
        return temperature


    def publish_temperature(self):
        while True:            
            temperature_msg = Temperature()
            temperature_msg.header.stamp = self.get_clock().now().to_msg()
            temperature_msg.temperature = self.read_temp()
            self.publisher_.publish(temperature_msg)
            time.sleep(1)

def main(args=None):
    rclpy.init(args=args)
    temperature_publisher = TemperaturePublisher()
    rclpy.spin(temperature_publisher)
    temperature_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
