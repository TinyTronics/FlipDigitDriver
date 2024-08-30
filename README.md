# FlipDigitDriver

Library for the [FlipDigit Driver](https://www.tinytronics.nl/index.php?route=product/product&product_id=6398) for the [mechanical 7-segment display from Alfa-Zeta](https://www.tinytronics.nl/index.php?route=product/product&product_id=6270), better known as a FlipDigit. 



## How Does it Work?

The mechanical display from Alfa-Zeta consists of 7 mechanical segments with a black and a white side. These segments can be turned very quickly by means of built-in electromagnets to form different characters. Each coil can be controlled individually with a pulse signal, whereby the direction of the current determines whether the segment is 'set' or 'reset'. Thanks to the built-in permanent magnets, the segments remain in the set position without tension on the coils. The driver in combination with these library provides a simple way to control the segments.



Flipdigits can be connected in series and this library can be used to display numbers and letters onto the display. 

Note that not all patterns are included in this library. You can add any pattern you want by adding them in the .cpp file. The lay-out is as follows: 

   

              /---A---/       

             /       /

            F       B

           /       /

          /---G---/

         /       /

        E       C

       /       /

      /---D---/





## Installing

To install this library from GitHub to Arduino, download the library as a ZIP file from the repository, then import it into Arduino IDE.



## Compatibility

This library has been tested with an ESP32 and with an Arduino Uno. Other MCU's are probably compatible too.



## License

Written by TinyTronics.

MIT license, check license.txt for more information

All text above must be included in any redistribution
