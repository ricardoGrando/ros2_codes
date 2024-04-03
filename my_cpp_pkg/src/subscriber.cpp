#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class ExampleSubscriber: public rclcpp::Node
{
public:
	ExampleSubscriber(): Node("cpp_test")
	{
		subscriber_ = this->create_subscription<example_interfaces::msg::String>("example_publisher", 10, std::bind(&ExampleSubscriber::callbackSubscriber, this, std::placeholders::_1));
		RCLCPP_INFO(this->get_logger(), "Subscriber Cpp Node");
	}

private:
  void callbackSubscriber(const example_interfaces::msg::String::SharedPtr msg){
  	RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
  }
  
  rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;

};

int main(int argc, char **argv){
	rclcpp::init(argc, argv); // ros2 comunication
	auto node = std::make_shared<ExampleSubscriber>(); // shared pointer for the node
	rclcpp::spin(node); //spin
	rclcpp::shutdown(); //after ctrl+c ends spin and shutdown the ros comunication
	return 0;
}
