#include <chrono>
#include <memory>
#include <functional>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("dr_circles_node")
    {
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("a200_0000/cmd_vel", 1);
      //i = 0.0;
      timer_ = this->create_wall_timer(0.05ms, std::bind(&MinimalPublisher::publish_message, this));
      
      this->declare_parameter("my_parameter", double(0.0));
      this->declare_parameter("ang_velocity", double(0.0));
      this->declare_parameter("run_the_code", false);
     // _zmienna = this->get_parameter("my_parameter").as_double();
    }

  private:
  //double _zmienna = 0.0;
    void publish_message()
    {
      auto message = geometry_msgs::msg::Twist();
      if(this->get_parameter("run_the_code").as_bool() == true)
      {
      	
      if(this->get_parameter("my_parameter").as_double() == 0.0 && this->get_parameter("ang_velocity").as_double() == 0.0)
      {
      	message.linear.x = 2.0;
      	message.linear.y = 2.0;
      	message.angular.z = 4;
      	RCLCPP_INFO(this->get_logger(), "Sending - Linear Velocity : '%f', Angular Velocity : '%f'", message.linear.x, message.angular.z);
      	publisher_->publish(message);
      }
      else
      {
      	message.linear.x = this->get_parameter("my_parameter").as_double();
      	message.linear.y = this->get_parameter("my_parameter").as_double();
      	message.angular.z = this->get_parameter("ang_velocity").as_double();
      	RCLCPP_INFO(this->get_logger(), "Sending - Linear Velocity : '%f', Angular Velocity : '%f'", message.linear.x, message.angular.z);
      	publisher_->publish(message);
      }
      
      }
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    float i;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
