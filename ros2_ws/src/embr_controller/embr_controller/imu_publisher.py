#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu 


class PublishIMUSensorData(Node):
    def __init__(self):
        super().__init__("IMU Publisher Activated")


def main(args=None):
    rclpy.init(args=args)
    node = DrawCircleNode()
    rclpy.spin(node)
    rclpy.shutdown

