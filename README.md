# ExVectrHAL
Part of the ExVeCtr project. 
ExVectrHAL's main purpose is to add a hardware abstraction layer interface to allow EXVECTR projects to run on different platforms and systems seamlessly or with little implementation. The hardware abstraction layer interface only defines a set of functions and structures that must be implemented by each platform. With these given, any ExVeCtr project can assume these functions exist with a specific interface and be used on any supported platform from linux to Arduino to bare metal.
## **This project is under initial development. Things will probably break.**
## Current goal roadmap:
- [X] Plan hardware abstraction layer (HAL). (Main stuff was planned)
- [ ] Implement Basic HAL interfaces.
    - [X] Input/Output.
    - [X] Bus Device.
    - [X] Basic pin types (GPIO, PWM, ADC, DAC etc.).
- [ ] ~~Create Windows HAL Implementation for main testing (In external library. Not part of ExVectrHAL).~~ Currently not needed for windows platform.
- [X] Create Arduino HAL Implementation for embedded testing (In external library. Not part of ExVectrHAL).
- [ ] Add interrupt system.
- [ ] Documentation.
## To implement onto a platform:##
- A library must be made to implement multiple functions in the hardware abstraction layer:
    - These will be named in the future once basic implementation is finished.
