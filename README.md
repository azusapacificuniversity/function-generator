# function-generator
Use the M5StickC PLUS as Electronic Test Equipment

## Using CLion with the PlatformIO Plugin

So far, the code in this repository was written in C++ in JetBrain's CLion IDE (info on CLion [here](https://www.jetbrains.com/clion/) and how to get it for free as a student/professor [here](https://www.jetbrains.com/community/education/#students)) with the [PlatformIO Plugin](https://plugins.jetbrains.com/plugin/13922-platformio-for-clion).  If you don't have CLion or a PlatformIO-compatible IDE, the code in the *main.cpp* file can be copy-pasted into the Arduino app and run with one or two very small modifications to remove the C++ specific code (mainly the double colons in the wifi class lines).  If you go this route, you'll also need to download the zip of the M5StickC Plus library [from GitHub](https://github.com/m5stack/M5StickC-Plus) and install it in the Arduino IDE.

So far, the UI has been implemented for every wave except the sine wave.  The fucntions to generate the waves still need to be written.
