# amazon-freertos-ble-provisioning-demo
Putting together a demo for Amazon FreeRTOS WiFi provisioning over BLE for the ESP32
Full documentation can be found [here](https://docs.aws.amazon.com/freertos/latest/userguide/ble-demo.html)

To clone use:

```
git clone https://github.com/massi-ang/amazon-freertos-ble-provisioning-demo.git --recurse-submodules
```

## Build the ESP32 firmware

Ensure you have installed the [ESP toolchain](https://docs.espressif.com/projects/esp-idf/en/v3.3/get-started-cmake/index.html#step-1-set-up-toolchain). 
Do not install the ESP-IDF. 
If you have already installed ESP-IDF make sure that the `IDF_PATH` environment variable is unset before running the commands below.

```
cd AmazonFreeRTOS1
mkdir build
cmake -DVENDOR=espressif -DBOARD=esp32_wrover_kit -DCOMPILER=xtensa-esp32 -S . -B build
cd build
make all -j4
make flash
```

## Build the iOS app

Run the following commands to open the project in XCode

```
cd amazon-freertos-ble-ios-sdk/Example/AmazonFreeRTOSDemo/
open AmazonFreeRTOSDemo.xcworkspace
```

Build the app and deploy it to a physical phone

