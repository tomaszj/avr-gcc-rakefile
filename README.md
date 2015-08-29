# avr-gcc-rakefile

Simple rakefile which allows easy compilation of .c sources to a single .hex file that can be flashed to your AVR.

All products (intermediate files and .hex file) are placed in `build` folder.

## Installation

Make sure your avr-libc and avr-gcc are properly installed and are in the path. For OSX, simply follow the instructions here: https://github.com/osx-cross/homebrew-avr

## Build time!

Simply run:

    rake

and look what's in `build` folder!

I'm building for `attiny85` device. If you use different one, simply change the `mcu` value at the top of the Rakefile.

## Example

Example, dead-simple project is located in `example` folder.

## Caveats

Right now, all .c files need to be in the root folder.

## TODO

Add flash task to upload binary using avrdude

## License

Usual MIT, see LICENSE file.

