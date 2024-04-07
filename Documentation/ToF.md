# ToF Documentation
> You're welcome

The following commands will be run in the "base directory"

## Step 1: Get camera working on Ubuntu
### Make directory and enter it
```bash
mkdir baseDirectory
cd baseDirectory
```

### Set up Glog
> No I don't know what Glog is
```bash
pushd .
git clone --branch v0.6.0 --depth 1 https://github.com/google/glog
cd glog
mkdir build_0_6_0 && cd build_0_6_0
cmake -DWITH_GFLAGS=off -DCMAKE_INSTALL_PREFIX=/opt/glog ..
sudo cmake --build . --target install
popd
```

### Libwebsockets
```bash
pushd .
git clone --branch v3.1-stable --depth 1 https://github.com/warmcat/libwebsockets
cd libwebsockets
mkdir build_3_1 && cd build_3_1
cmake -DLWS_WITH_SSL=OFF -DLWS_STATIC_PIC=ON -DCMAKE_INSTALL_PREFIX=/opt/websockets ..
sudo cmake --build . --target install
popd
```

### Protobuf
```bash
pushd .
git clone --branch v3.9.0 --depth 1 https://github.com/protocolbuffers/protobuf
cd protobuf
mkdir build_3_9_0 && cd build_3_9_0
cmake -Dprotobuf_BUILD_TESTS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_INSTALL_PREFIX=/opt/protobuf ../cmake
sudo cmake --build . --target install
cd ../..
popd
```

## Now install OpenGL and OpenCV
```bash
sudo apt install libopencv-contrib-dev
sudo apt install libopencv-dev
sudo apt install libgl1-mesa-dev libglfw3-dev
```

### Download and build SDK only
Please read the following carefully.
The github instructions say to clone the repository's v5.0.0 branch. Do NOT do this. You actually can't, since the v5.0.0 branch does NOT exist.

Download this: https://github.com/analogdevicesinc/ToF/archive/refs/tags/v5.0.0-rc1.zip

Extract the folder

Rename folder to `ToF`.

Move `ToF` to `baseDirectory` Folder.

```bash
cd ToF
mkdir build && cd build
cmake -DWITH_EXAMPLES=off -DCMAKE_PREFIX_PATH="/opt/glog;/opt/protobuf;/opt/websockets" ..
make -j4
```

### Now try to open the GPU
Now,
```bash
cd ToF/build/examples/tof-viewer
nautilus .
```

You should now see a GUI pop up. Click `ADIToFGUI`. You should be able to figure it out now.