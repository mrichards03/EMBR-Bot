# ROS2 Terminology 
## Messages
These are ROS2 Datatypes. There are many kinds of messages. Sensors may have unique message types associated with them.

## Topics
You can think of these as channels for messages to be sent and received by. Publishers publish to topics, subscribers "tune in" to topics and see messages that are sent to them.

## Nodes
Nodes are entities that communicate with other nodes. 

### Subscriber Nodes
These listen to a topic.

### Publisher Nodes
These send messages to topics.


### Misconceptions

1. Each node has to be in one file. No, you can have multiple nodes in one python file. That said, don't put all nodes in a single file.


# Data Flow
1. The sensor data is read by python, ideally in the publisher node. 
2. The publisher node publishes the data to a topic.
3. Each subscriber node reads data from the respective topic and performs actions as needed.