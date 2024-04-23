import rclpy
from rclpy.node import Node
import time
from dronekit import connect
import geometry_msgs.msg

class AttitudePublisher(Node):
    def __init__(self):
        super().__init__('attitude_publisher')
        self.publisher_ = self.create_publisher(geometry_msgs.msg.PoseStamped, 'attitude', 10)
        self.vehicle = connect("/dev/ttyUL0", wait_ready=False, baud=57600)
        self.get_logger().info('Attitude Publisher node initialized')

    def publish_attitude(self):
        while True:
            attitude = self.vehicle.attitude
            roll = attitude.roll
            pitch = attitude.pitch
            yaw = attitude.yaw
            pose_msg = geometry_msgs.msg.PoseStamped()
            pose_msg.header.stamp = self.get_clock().now().to_msg()
            pose_msg.pose.orientation.x = roll
            pose_msg.pose.orientation.y = pitch
            pose_msg.pose.orientation.z = yaw
            self.publisher_.publish(pose_msg)
            time.sleep(1)

def main(args=None):
    rclpy.init(args=args)
    attitude_publisher = AttitudePublisher()
    attitude_publisher.publish_attitude()
    rclpy.spin(attitude_publisher)
    attitude_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
