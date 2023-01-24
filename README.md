# VectrHAL
Part of the VECTR project. 
VectrHAl's main purpose is to add a hardware abstraction layer interface to allow VECTR projects to run on different platforms and systems seamlessly or with little implementation. The hardware abstraction layer interface only defines a set of functions and structures that must be implemented by each platform. With these given, any VECTR project can assume these functions exist with a specific interface and be used on any supported platform from Windows to Arduino to bare metal.
## **This project is under initial development. Things will probably break.**
## Current goal roadmap:
- [ ] Plan hardware abstraction layer (HAL).
- [ ] Implement Basic HAL functions
- [ ] Create Arduino HAL Implementation for testing (In external library. Not part of VectrCore).
- [ ] Documentation.
## To implement onto a platform:##
- A library must be made to implement multiple functions in the hardware abstraction layer:
    - These will be named in the future once basic implementation is finished.