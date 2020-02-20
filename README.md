# amazon-freertos-ble-provisioning-demo
Putting together a demo for Amazon FreeRTOS WiFi provisioning over BLE for the ESP32
Full documentation can be found [here](https://docs.aws.amazon.com/freertos/latest/userguide/ble-demo.html)

## Prerequisites
* an AWS Account
* a user with Administrator rights
* the AWS CLI
* the Python boto3 library

To clone use:

```
git clone https://github.com/massi-ang/amazon-freertos-ble-provisioning-demo.git --recurse-submodules
```

## Build the ESP32 firmware

Ensure you have installed the [ESP toolchain](https://docs.espressif.com/projects/esp-idf/en/v3.3/get-started-cmake/index.html#step-1-set-up-toolchain). 
Do not install the ESP-IDF. 
If you have already installed ESP-IDF make sure that the `IDF_PATH` environment variable is unset before running the commands below.

The AWSSetup.py will create a new Thing and the corresponding certificate and policies in your account.

```
cd AmazonFreeRTOS1/tools/aws_config_quick_start
python AWSSteup.py setup
cd ../..
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
git pull origin no-login
pod install
open AmazonFreeRTOSDemo.xcworkspace
```

You have to set a development team to be able to deploy the app to your device.
* Go to your project, select the **Signing & Capabilities** tab. 
* Select a team and set the Bundle Identifier.
* Build the app and deploy it to a physical device

> NOTE: If you have already run the app and paired the ESP32, go to **Settings | Bluetooth**, select the ESP32 device and forget it.

* Connect to the ESP32 via a serial monitor:

  ```
  screen /dev/tty.SLAB_USBtoUART 115200
  ```

* Reset the ESP32
* The ESP32 will appear in the app. Click on it to pair it
* Type `y` in the screen window and `Pair` in the app. A green bar appears on the right of the device item in the app
* Click on the device entry again and select **Network Config**
* Configure the networks

> NOTE: If not networks appear in the list repeat the process by first forgetting the ESP32 from the Bluetooth list (see above)

Once the network credentials are set on the ESP32, you should see in the serial monitor window that the ESP32 connects to the network and sends a bunch of messages to AWS IoT Core.


