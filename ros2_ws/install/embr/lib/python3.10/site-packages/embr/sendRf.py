import rclpy
import time
from rclpy.node import Node
from msg_interface.msg import Gps
from pymavlink import mavutil
from sensor_msgs.msg import Temperature
from std_msgs.msg import Float32

class CommSubscriber(Node):
    def __init__(self):
        super().__init__('mavlink_subscriber')
        self.subscription = self.create_subscription(Gps, 'gps', self.cube_callback, 10)
        self.subscription_temperature = self.create_subscription(Temperature, 'temperature', self.temperature_callback, 10)
        self.subscription_gas = self.create_subscription(Float32, 'gas_resistance', self.gas_callback, 10)
        self.subscription  # prevent unused variable warning
        self.mavlink_connection = mavutil.mavlink_connection(device='/dev/ttyUL1', baudrate=57600, autoreconnect=False)
        self.get_logger().info('Mavlink Subscriber node initialized')

    def temperature_callback(self, msg):
        timems = int((time.time() - time.mktime(time.gmtime(0))) * 1000) % 4294967296
        self.mavlink_connection.mav.named_value_float_send(
			time_boot_ms = timems,
			name = b'temp',
			value = msg.temperature)
    
    def gas_callback(self, msg):
        timems = int((time.time() - time.mktime(time.gmtime(0))) * 1000) % 4294967296
        self.mavlink_connection.mav.named_value_float_send(
			time_boot_ms = timems,
			name = b'gas',
			value = msg.data)

    def cube_callback(self, msg):
        lat = msg.lat
        lon = msg.lon
        alt = msg.alt
        vel = int(msg.vel * 100)
        timems = int((time.time() - time.mktime(time.gmtime(0))) * 1000) % 4294967296
        self.mavlink_connection.mav.global_position_int_send(timems, lat, lon, alt, 0, vel, 0, 0, 0)

def main(args=None):
    rclpy.init(args=args)
    comm_subscriber = CommSubscriber()
    rclpy.spin(comm_subscriber)
    comm_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
