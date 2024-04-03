#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

class Subscriber(Node):
	def __init__(self):
		super().__init__("publisher")
		
		self.subscriber = self.create_subscription(String, "publisher", self.callback_subscribe, 10) 		
		self.get_logger().info("Subscriber is working")
		
		
	def callback_subscribe(self, msg):
		self.get_logger().info(msg.data)

def main(args=None):
	rclpy.init(args=args)
	node = Subscriber()	
	rclpy.spin(node)
	rclpy.shutdown()

if __name__ == "__main__":
	main()
