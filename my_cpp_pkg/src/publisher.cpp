#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class ExamplePublisherNode: public rclcpp::Node
{
public:
	ExamplePublisherNode(): Node("example_publisher"), example_message_("ROS2")
	{
		publisher_ = this->create_publisher<example_interfaces::msg::String>("example_publisher", 10);
		timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&ExamplePublisherNode::publishHello, this));
		RCLCPP_INFO(this->get_logger(), "Hello Cpp Node");
	}

private:
	void publishHello(){
		auto msg = example_interfaces::msg::String();
		msg.data = std::string("His, this is ") + example_message_ + std::string(" saying hello world.");
		publisher_->publish(msg);
	}
	
	std::string example_message_;
	rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
	rclcpp::TimerBase::SharedPtr timer_;
};



int main(int argc, char **argv){
	rclcpp::init(argc, argv); // ros2 comunication
	auto node = std::make_shared<ExamplePublisherNode>(); // shared pointer for the node
	rclcpp::spin(node); //spin
	rclcpp::shutdown(); //after ctrl+c ends spin and shutdown the ros comunication
	return 0;
}
