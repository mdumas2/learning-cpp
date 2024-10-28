# C++ Libraries

C++ is a systems programming language that has been around for 45 years (and depending on when you're reading this, it may be even longer). Throughout this time, a wealth of powerful libraries has been developed and refined across various fields. These libraries enhance the capabilities of C++ and streamline development in numerous areas, making it a versatile choice for developers. Below are some examples of notable libraries spanning different domains:

## Generic

| Library | Description |
|---------|-------------|
| [Boost](https://www.boost.org/doc/libs) | A large collection of generic libraries. |
| [GSL](https://github.com/Microsoft/GSL) | C++ Core Guidelines Support Library implementation, recommended by Bjarne Stroustrup, Herb Sutter, and Co in [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/). |
| [Qt](https://qt.io/) | A comprehensive framework for developing cross-platform applications with a focus on rich graphical user interfaces. Qt provides a wide range of libraries and tools that facilitate the creation of both desktop and mobile applications, supporting various features such as 2D/3D graphics, multimedia, networking, and more. |

## Benchmarking

| Library | Description |
|---------|-------------|
| [Google Benchmark](https://github.com/google/benchmark) | A microbenchmarking library that helps developers measure and analyze the performance of C++ code with a straightforward API. |

## Communication

| Library | Description |
|---------|-------------|
| [gRPC](https://grpc.io/) | A modern open-source high-performance RPC framework that can run in any environment. |
| [ZeroMQ](https://zeromq.org/) | A high-performance messaging library that provides a simple API for message queuing and communication patterns like publish-subscribe and request-reply. |

## JSON

| Library | Description |
|---------|-------------|
| [nlohmann/json](https://github.com/nlohmann/json) | A modern C++ library for parsing and manipulating JSON data using a simple and intuitive syntax. |
| [RapidJSON](https://github.com/miloyip/rapidjson) | A fast JSON parser and generator for C++ that provides in-memory manipulation and supports both SAX and DOM style parsing. |
| [JsonCpp](https://github.com/open-source-parsers/jsoncpp) | A C++ library for interacting with JSON data, offering features for reading and writing JSON files with ease. |

## Cryptography

| Library | Description |
|---------|-------------|
| [OpenSSL](https://www.openssl.org/) | A robust, commercial-grade, full-featured toolkit for general-purpose cryptography and secure communication. |
| [TomCrypt](https://www.libtom.net/) | A fairly comprehensive, modular, and portable cryptographic toolkit that provides developers with a vast array of well-known published block ciphers, one-way hash functions, chaining modes, pseudo-random number generators, public key cryptography, and a plethora of other routines. |

## Embedded

| Library | Description |
|---------|-------------|
| [ETL](https://www.etlcpp.com/) | Embedded Template Library, a portable template library tailored for low resource platforms. |
| [distortos](https://distortos.org/) | An object-oriented C++11 RTOS for microcontrollers (ARM, STM32). |
| [QP/C++](http://sourceforge.net/projects/qpc/files/QP_C%2B%2B/4.5.04/) | RTOS kernel: Real-Time Embedded Frameworks based on active objects & state machines. |

## Games

| Library | Description |
|---------|-------------|
| [Vulkan](https://www.khronos.org/vulkan/) | A low-level API that removes many of the abstractions found in previous generation graphics APIs. This is great for delivering maximum performance but exposes more complexity to the developer. |
| [OpenGL](https://www.opengl.org/) | 3D language, graphics, and SDK for developing 3D applications. |

## Machine Learning

| Library | Description |
|---------|-------------|
| [libtorch](https://pytorch.org/) | A C++ frontend to the popular PyTorch Python library (backend is written in C++). |
| [TensorFlow](https://github.com/tensorflow/tensorflow) | An open-source machine learning framework for everyone; provides a stable C++ API and is written mainly in C++. |

## Serialization

| Library | Description |
|---------|-------------|
| [protobuf](https://github.com/protocolbuffers/protobuf) | Protocol Buffers (a.k.a., protobuf) is Google's language-neutral, platform-neutral, extensible mechanism for serializing structured data, including .proto files compiler. |

## Testing

| Library | Description |
|---------|-------------|
| [Google Test](https://google.github.io/googletest/) | Google Testing and Mocking Framework. |
| [CppUTest](https://cpputest.github.io/) | CppUTest is a C/C++ based unit xUnit test framework for unit testing and for test-driving your code. It is written in C++ but is used in C and C++ projects, frequently used in embedded systems but works for any C/C++ project. |

If you want to know more libraries, here are some sources that you can search:

- [C++ Reference Libraries](https://en.cppreference.com/w/cpp/links/libs)
- [Awesome C++ GitHub Repository](https://github.com/fffaraz/awesome-cpp?tab=readme-ov-file)

# Difficulties of Using C++ Libraries

But different from other languages like JavaScript and Python, utilizing C++ libraries can be a barrier for beginners. C++ does not have a common package manager like JavaScript with npm and Yarn, or Python with pip. This can complicate the process of effectively managing library dependencies and setup. 

However, one of the most well-known package managers for C++ is [vcpkg](https://vcpkg.io/en/), maintained by Microsoft. vcpkg simplifies the process of managing C++ libraries and dependencies, making it easier for developers to integrate and utilize various packages in their projects.

This is not a text about using a package managers but actually it is about how to take advantage of the whole universe of c++ Libraries.

# Static vs. Dynamic Libraries

**Static Libraries** (or Header-Only Libraries) are built within your project and fully included in your executable. In contrast, **Dynamic Libraries** are pre-built and need to be linked with your project at runtime.

## Advantages and Disadvantages

### Static Libraries:
- **Advantages:**
  - All code is included in the final executable, leading to fewer runtime dependencies.
  - Potentially faster execution since there's no need for dynamic linking at runtime.
- **Disadvantages:**
  - Larger executable size due to the inclusion of all library code.
  - Updates to the library require recompiling the entire project.

### Dynamic Libraries:
- **Advantages:**
  - Smaller executable size since the library code is separate.
  - Easier to update; only the dynamic library needs to be replaced without recompiling the entire project.
- **Disadvantages:**
  - Requires proper version management and compatibility checks.
  - Potential for runtime errors if the library is not found or incompatible.

## Differences Between Static and Header-Only Libraries

- **Static Libraries** are compiled into a binary format (e.g., `.lib` or `.a`) and linked during the linking phase of compilation.
- **Header-Only Libraries** consist of header files that are included in your source code, making them effectively part of your code during compilation. They do not produce a separate binary file.

## Common File Extensions

| Extension | Description                                                                                     |
|-----------|-------------------------------------------------------------------------------------------------|
| `.lib`    | A static library file on Windows; it contains compiled code that can be linked into applications. |
| `.dll`    | A dynamic link library on Windows; it contains code that can be loaded and executed by applications at runtime. |
| `.o`      | An object file produced by compiling a source file; it contains machine code that can be linked into executables or libraries. |
| `.pdb`    | A program database file used by Windows for storing debugging information about a program; it helps in debugging the executable. |
| `.hpp`    | A C++ header file; it typically contains declarations of functions, classes, and variables that can be included in multiple source files. |
| `.a`      | A static library file on Unix-like systems; it contains compiled code that can be linked into applications, similar to `.lib` files on Windows. |