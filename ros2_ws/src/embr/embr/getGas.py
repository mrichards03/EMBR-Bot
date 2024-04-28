import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32  # Change to use Float32 message type
import bme680
import smbus

class GasSensorNode(Node):
    def __init__(self):
        super().__init__('gas_sensor_node')
        self.publisher_ = self.create_publisher(Float32, 'gas_resistance', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        deviceAddr = 0x77
        busNum = self.find_device(deviceAddr)
        if busNum != None:
            self.sensor = bme680.BME680(i2c_addr=deviceAddr, i2c_device=smbus.SMBus(busNum))
            self.initialize_sensor()
        else:
            self.get_logger().error("No device found")
    
    def find_device(self, deviceAddr):
        if self.check_device(8, deviceAddr):
           return 8
        if self.check_device(7, deviceAddr):
            return 7
        return None            

    def check_device(self, busNum, deviceAddr):
        try:
            bus = smbus.SMBus(busNum)
            bus.read_byte(deviceAddr)
            bus.close()
            self.get_logger().info(f"Device found on I2C bus {busNum}")
            return True
        except FileNotFoundError:
            self.get_logger().error(f"I2C bus {busNum} not found")
        except IOError:
            self.get_logger().info(f"No device found at address {hex(deviceAddr)} on I2C bus {busNum}")
        except Exception as e:
            self.get_logger().error(f"An error occurred: {e}")
        finally:
            if 'bus' in locals():
                bus.close()
        return False

    def initialize_sensor(self):
        self.sensor.set_humidity_oversample(bme680.OS_2X)
        self.sensor.set_pressure_oversample(bme680.OS_4X)
        self.sensor.set_temperature_oversample(bme680.OS_8X)
        self.sensor.set_filter(bme680.FILTER_SIZE_3)
        self.sensor.set_gas_status(bme680.ENABLE_GAS_MEAS)
        self.sensor.set_gas_heater_temperature(320)
        self.sensor.set_gas_heater_duration(150)
        self.sensor.select_gas_heater_profile(0)

    def timer_callback(self):
        if self.sensor.get_sensor_data():
            if self.sensor.data.heat_stable:
                # Publish the gas resistance as a float
                gas_resistance = Float32(data=float(self.sensor.data.gas_resistance))
                self.publisher_.publish(gas_resistance)
                self.get_logger().info(f'Published Gas Resistance: {gas_resistance.data:.2f} Ohms')

def main(args=None):
    rclpy.init(args=args)
    gas_sensor_node = GasSensorNode()
    rclpy.spin(gas_sensor_node)
    gas_sensor_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
