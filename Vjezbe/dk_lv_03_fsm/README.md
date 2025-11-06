# FSM Header Library

This directory contains the Finite State Machine (FSM) header files extracted from the C++ Actor Framework (CAF) for standalone use in other projects.

## Files

- `caf/detail/parser/fsm.hpp` - Main FSM DSL definitions
- `caf/detail/parser/fsm_undef.hpp` - Cleanup header to undefine FSM macros
- `caf/detail/pp.hpp` - Preprocessor utilities
- `caf/config.hpp` - Minimal configuration for standalone usage

## Usage

Include the FSM header in your project and use the FSM DSL to define state machines. After using the FSM, include the fsm_undef.hpp header to clean up the macro definitions.

```cpp
#include "caf/detail/parser/fsm.hpp"

// Your FSM code here

#include "caf/detail/parser/fsm_undef.hpp"
```

## Origin

Extracted from: https://github.com/actor-framework/actor-framework

## License

This code is part of CAF, the C++ Actor Framework. See the LICENSE file in the main CAF distribution directory for license terms and copyright.
