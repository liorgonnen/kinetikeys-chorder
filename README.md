# Kinetikeys Chorder

Kinetikeys Chorder (aka Kinetikeys-Concept1) is a wearable, wireless, mechanical chording keyboard with one main goal in mind:

**Allow You To Type While Walking**

![](readme/KinetikeysChorder.jpg)

# Work-in-Progress!
I'll be updating the repo in the upcoming days with more detailed information. If you're reading this, it's quite likely that you're coming from the [Reddit thread](https://www.reddit.com/r/MechanicalKeyboards/comments/j3jyt3/type_while_walking_are_you_thinking_about_this_too/).

I uploaded the STL files for the left hand. You can already 3D print and use them as-is.

### Parts / Materials
* 3D Printer (or access to one)
* 2 x [Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062) microcontrollers
* 2 x [LiPoly 3.7v 350mAh](https://www.adafruit.com/product/2750) batteries
* 10 x [Kailh Choc Low-Profile](https://novelkeys.xyz/collections/switches/products/kailh-low-profile-switches?variant=3747939680296) switches
* 16 x [M2.5 screws](https://www.amazon.com/HVAZI-Metric-Stainless-Socket-Assortment/dp/B07F14J7X8)
* [Thin wire](https://www.amazon.com/StrivedayTM-Flexible-Silicone-electronic-electrics/dp/B01KQ2JNLI) to connect the switches to the microcontroller
* Grip adhesive tape
* Optional: [Terminal Block Kit](https://www.adafruit.com/product/3173) for Feather
* Optional: 5-wire block connector (for all ground wires)

### How to Build
* Print all the STL files using regular PLA
* Attach the Hand Rest to the Main Body using two M2.5 screws
* Put the Hand Strap in water of about 160 degrees F or 70 degrees C for a few seconds until it softens and quickly pull it out of the water and mold around you hand (just the 4 fingers in front of the thumb). It should be snuggly and comfotable, with a firm, yet not tight grip.
* Attach the Hand Strap to the Hand Rest using 2 screws, washers and flush nuts
* Connect the battery to the microcontroller (note: An updated version of the MainBody will be uploaded - it will allow you to place the battery under the controller)
* Connect the microcontroller to the Main Body using 4 screws
* For each key switch, solder two wires, one will go directly to the microcontroller, and the other will be used as joint ground
* Attach each of the swtiches with the soldered wires to the designated socket in the Main Body
* Connect the 5 wires, 1 from each key to the microcontroller (I used pins A0-A4)
* Solder all 5 ground wires together, or use a 5-wire block connector
* Connect a single wire from all joined ground wires, to the GND pin on the microcontroller
* Attach the Cover (note: I need to redesign the way it connects to the main body. In the meanwhile, use some additional adhesive tape to secure it to place.
* Wrap the hand-strap in adhesive tape so that it feels nicer and more secure on your hand
* Flash the firmware (It's an Arduino-compatible [PlatformIO](https://platformio.org/) project


# Previous Work
Check out my previous attempt at a wearable keyboard: [Kinetikeys-Concept0](https://github.com/liorgonnen/kinetikeys-concept0).
