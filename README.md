# A C++ library for trading technical analysis

This is a C++20 library for trading, using technical indicators and other tools
of the technical analysis.

The project is designed to deliver a dynamic library that shall be linked
afterwards with any C++ program, which aims to use any of the delivered 
classes. 

> **Warning:**
> This library is in an early stage.

## Dependencies

- [Meson](https://github.com/mesonbuild/meson) (version 1.3.0 or newer).
- [Ninja](https://ninja-build.org/) (version 1.11.1 or newer).
- [Boost C++ Library](https://www.boost.org/) (version 1.81.0)

## Compiling from source

To compile the library, simply go to the root folder of the project and type:

```bash
$ meson setup build
$ ninja -C build
```

## Running the tests

Unit tests are included for the developed classes. In order to run the tests,
either exectute a precompiled test application (you'd find it under 
`build/run_tests`) or run:

```bash
$ cd build
$ ninja test
```

