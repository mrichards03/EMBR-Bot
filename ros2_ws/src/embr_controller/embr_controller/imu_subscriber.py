#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
import requests
import json 


class IMUSubscriberNode(Node):

    def __init__(self, data_destination_URL: str):
        super().__init__("IMU Subscriber")
        self.imu_subscriber_ = self.create_subscription(Imu, "/IMU/Readings", self.IMU_callback, 10)
        self.data_destination_ = data_destination_URL # this is where we send the post request


    def IMU_callback(self, msg: Imu):
        self.get_logger().info(msg)
        msg_object = json.loads(msg)
        x = requests.post(self.data_destination_, json = msg_object)



def main(args=None):
    rclpy.init(args=args)
    node = IMUSubscriberNode()
    rclpy.spin(node)
    rclpy.shutdown()
