import rclpy
import time
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from pymavlink import mavutil
import serial
from sensor_msgs.msg import Temperature

class MavlinkSubscriber(Node):
    def __init__(self):
        super().__init__('mavlink_subscriber')
        self.subscription = self.create_subscription(PoseStamped, 'attitude', self.cube_callback, 10)
        self.subscription_temperature = self.create_subscription(Temperature, 'temperature', self.temperature_callback, 10)
        self.subscription  # prevent unused variable warning
        self.radio = serial.Serial(port='/dev/ttyUL1', baudrate=57600)
        self.mavlink_connection = mavutil.mavlink_connection('udpout:localhost:14550', autoreconnect=False)
        self.get_logger().info('Mavlink Subscriber node initialized')

    def temperature_callback(self, msg):
        print("Temperature: {:.2f} °C".format(msg.temperature))

    def cube_callback(self, msg):
        roll = msg.pose.orientation.x
        pitch = msg.pose.orientation.y
        yaw = msg.pose.orientation.z
        timems = int((time.time() - time.mktime(time.gmtime(0))) * 1000) % 4294967296
        mav_msg = self.mavlink_connection.mav.attitude_encode(timems, roll, pitch, yaw, 0, 0, 0)
        self.radio.write(mav_msg.pack(self.mavlink_connection.mav))

def main(args=None):
    rclpy.init(args=args)
    mavlink_subscriber = MavlinkSubscriber()
    rclpy.spin(mavlink_subscriber)
    mavlink_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
