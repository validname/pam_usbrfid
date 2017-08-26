It's a simple concept of using a RFID-reader imitating USB-HID device (aka USB keyboard). You may unlock screen locked by XScreenSaver or log in into console via login.

# How to use.

1. Insert you cretendtial into DEFINE's (USER and PASSWORD).
1. Compile by running `make`
1. Place `pam_usbrfid.so` to where all PAM modules located.
1. Mention module for your programs (in `/etc/pam.d/{program_name}`) using `sufficient` directive. You should place it at the top of stack, probably.

# Hardware.
It's just a chinese reader that I've bought [here](https://www.aliexpress.com/item/125Khz-RFID-Reader-EM4100-USB-Proximity-Sensor-Smart-Card-Reader-no-drive-issuing-device-EM-ID/32788346694.html). It "enters" 10 first digits from RFID card as decimal number and sends `'\n'` at last.
Here is some info from `lsusb`:
```
Bus 001 Device 006: ID 08ff:0009 AuthenTec, Inc. 
Device Descriptor:
  bLength                18
  bDescriptorType         1
  bcdUSB               1.10
  bDeviceClass            0 
  bDeviceSubClass         0 
  bDeviceProtocol         0 
  bMaxPacketSize0         8
  idVendor           0x08ff AuthenTec, Inc.
  idProduct          0x0009 
  bcdDevice            0.08
  iManufacturer           1 
  iProduct                2 
  iSerial                 3 
  bNumConfigurations      1
  Configuration Descriptor:
    bLength                 9
    bDescriptorType         2
    wTotalLength           34
    bNumInterfaces          1
    bConfigurationValue     1
    iConfiguration          0 
    bmAttributes         0xa0
      (Bus Powered)
      Remote Wakeup
    MaxPower              100mA
    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        0
      bAlternateSetting       0
      bNumEndpoints           1
      bInterfaceClass         3 Human Interface Device
      bInterfaceSubClass      1 Boot Interface Subclass
      bInterfaceProtocol      1 Keyboard
      iInterface              4 
        HID Device Descriptor:
          bLength                 9
          bDescriptorType        33
          bcdHID               1.10
          bCountryCode           33 US
          bNumDescriptors         1
          bDescriptorType        34 Report
          wDescriptorLength      65
         Report Descriptors: 
           ** UNAVAILABLE **
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x81  EP 1 IN
        bmAttributes            3
          Transfer Type            Interrupt
          Synch Type               None
          Usage Type               Data
        wMaxPacketSize     0x0008  1x 8 bytes
        bInterval              10


```
