# Workspace Setup 

## Step 1: Add the requite repositories and sources  

> ALL COMMANDS ARE INTENDED FOR UBUNTU DESKTOP


These set of commands make sure your locale uses UFT-8 encoding.
```bash
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
```

These set of commands add the package repository to apt. Without these, you won't be able to install the required packages.
```bash
sudo apt install software-properties-common
sudo add-apt-repository universe
```

These commands add the GPG key. I *think* it  verifies packages? Not sure, do it anyway.
```bash
sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

This adds the repository to your sources list
```
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
> This is all on one line, don't be misled by formatting


Now, update and upgrade your system
```bash
sudo apt upgrade && sudo apt update
```

## Step2: ROS2 Installation 
Now, we can install ROS2 and GUI stuff.
```
sudo apt install ros-humble-desktop
```

Now: You have to edit your `.bashrc` or `.zshrc` files to setup the environment. The string gets added to the bottom of the `.bashrc` file.


```
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
```

> Note, if you're using ZSH you will have to follow different instruction since `~/.bashrc` doesn't exist for you. However if you have ZSH set up on Ubuntu you already know this 😬.

Now, execute bash (or ZSH).
```bash
exec bash
```

Open another terminal. 

In the first terminal, run a C++ `talker`:
```bash
ros2 run demo_nodes_cpp talker
```
In the new terminal, run a Python `listener`:
```bash
ros2 run demo_nodes_py listener
```
You should see the talker send messages and the listener receive them.

## Step 3: Colcon
```bash
sudo apt install python3-colcon-common-extensions
```

Set up the autocompletion. You don't have to but it's more convenient. 
```bash
echo "source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash" >> ~/.bashrc
```

This is where we create a package, but I've already done this. Navigate to the `ros2_ws` folder.

```bash
# From repo root
cd ros2_ws
```

**Only** run `colcon build` **here**.

To build the files, run:
```bash
source ~/.bashrc
colcon build --symlink-install
```

