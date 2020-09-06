# Sample LilyGo T5 project

This is a minimal sample for the Lilygo T5 display.  This sample might
work with other boards.  In order to choose your board you have to
alter the line that reads:

    GxEPD2_BW<GxEPD2_213_B72, GxEPD2_213_B72::HEIGHT> display(GxEPD2_213_B72(ELINK_SS, ELINK_DC, ELINK_RESET, ELINK_BUSY));
	
to whatever fits your board.  In order to figure out what board you
have you can have a look at this page:
https://github.com/Xinyuan-LilyGO/T5-Ink-Screen-Series

