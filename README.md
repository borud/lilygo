# Sample Lilygo T5 project

This is a minimal sample for the Lilygo T5 display.  This sample might
work with other boards.  In order to choose your board you have to
alter the line that reads:

`GxEPD2_BW<GxEPD2_213_B72, GxEPD2_213_B72::HEIGHT> display(GxEPD2_213_B72(ELINK_SS, ELINK_DC, ELINK_RESET, ELINK_BUSY));`
	
to whatever fits your board.  In order to figure out what board you
have you can have a look at this page:
https://github.com/Xinyuan-LilyGO/T5-Ink-Screen-Series

# Uploading

In order to build and upload you first have to make sure that the USB
port setup is correct in the `platformio.ini` file. Make sure
`upload_port` and `monitor_port` is set correctly.  Then you run the
following to build the firmware, upload it and start the serial
monitor:

    pio run -t upload -t monitor


# Other notes

This has been tested with Platformio 4 and 5.  When upgrading to
Platformio 5 I had to add a dependency to Adafruit BusIO, so the
dependency section looks like this:

    lib_deps = 
        GxEPD2@1.2.12
        adafruit/Adafruit BusIO@^1.4.2

