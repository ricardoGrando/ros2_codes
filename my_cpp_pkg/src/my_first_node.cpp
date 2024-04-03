#include "rclcpp/rclcpp.hpp"

class MyNode: public rclcpp::Node
{
public:
	MyNode(): Node("cpp_test")
	{
		RCLCPP_INFO(this->get_logger(), "Hello Cpp Node");
	}

private:

};



int main(int argc, char **argv){
	rclcpp::init(argc, argv); // ros2 comunication
	auto node = std::make_shared<MyNode>(); // shared pointer for the node
	rclcpp::spin(node); //spin
	rclcpp::shutdown(); //after ctrl+c ends spin and shutdown the ros comunication
	return 0;
}
