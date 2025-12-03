# Corewar Assembler

A C implementation of an assembler for the Corewar virtual machine. This assembler converts champion source files (`.s`) into executable bytecode (`.cor`) that can be run on the Corewar virtual machine.

## About Corewar

Corewar is a programming game in which two or more programs (called "champions") compete in a virtual arena. Each champion is written in a simplified assembly language and tries to survive by executing a `live` instruction before the end of each cycle period.

## Features

- Full parsing of Corewar assembly language
- Support for all 16 instructions (live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, fork, lld, lldi, lfork, aff)
- Label resolution and management
- Header parsing (.name and .comment directives)
- Binary output generation following the Corewar specification
- Comprehensive error handling with line-specific error messages

## Building

```bash
# Compile the assembler
make

# Clean object files
make clean

# Clean everything including binary
make fclean

# Rebuild from scratch
make re
```

## Usage

```bash
./asm <champion.s>
```

This will generate a `champion.cor` file in the same directory as the source file.

### Example

```bash
./asm Tester/champions/abel.s
```

This creates `Tester/champions/abel.cor`.

## Assembly Language Syntax

### Header

Every champion must declare a name and comment:

```asm
.name "Champion Name"
.comment "Champion description"
```

### Instructions

| Instruction | Description |
|------------|-------------|
| `live %n` | Declare the player n as alive |
| `ld src, reg` | Load value into register |
| `st reg, dst` | Store register value |
| `add r1, r2, r3` | r3 = r1 + r2 |
| `sub r1, r2, r3` | r3 = r1 - r2 |
| `and a, b, reg` | reg = a & b |
| `or a, b, reg` | reg = a \| b |
| `xor a, b, reg` | reg = a ^ b |
| `zjmp %addr` | Jump if carry flag is set |
| `ldi a, b, reg` | Indexed load |
| `sti reg, a, b` | Indexed store |
| `fork %addr` | Create new process |
| `lld src, reg` | Long load |
| `lldi a, b, reg` | Long indexed load |
| `lfork %addr` | Long fork |
| `aff reg` | Display character |

### Labels

Labels can be defined with a colon and referenced with `:label`:

```asm
loop:   live %1
        zjmp %:loop
```

### Parameter Types

- `%n` - Direct value (immediate)
- `rN` - Register (r1-r16)
- `n` - Indirect value (address relative to PC)
- `%:label` - Direct label reference
- `:label` - Indirect label reference

## Project Structure

```
.
├── include/
│   ├── asm.h              # Main structure definitions
│   ├── error_handling.h   # Error handling functions
│   ├── fill.h             # Data filling functions
│   ├── header.h           # Header parsing functions
│   ├── instructions.h     # Instruction definitions
│   ├── lib.h              # Utility functions
│   ├── linked_lists.h     # Linked list implementation
│   ├── op.h               # Opcodes and constants
│   └── write.h            # Binary output functions
├── src/
│   ├── asm/
│   │   ├── error_handling/    # Error detection and reporting
│   │   └── fill_data/         # Parsing logic
│   │       ├── header/        # Name and comment parsing
│   │       └── instructions/  # Instruction parsing
│   ├── lib/
│   │   ├── general/           # String utilities
│   │   └── linked_lists/      # List operations
│   ├── write/                 # Binary output generation
│   ├── cleanup.c              # Memory management
│   └── main.c                 # Entry point
├── Tester/
│   ├── champions/             # Test champion files
│   ├── tester.sh              # Automated testing
│   └── segfaulter.sh          # Crash testing
└── Makefile
```

## Binary Format

The generated `.cor` file follows this format:

1. **Magic number** (4 bytes): `0x00ea83f3`
2. **Program name** (128 bytes): Null-padded
3. **Padding** (4 bytes)
4. **Program size** (4 bytes): Size of the bytecode
5. **Comment** (2048 bytes): Null-padded
6. **Padding** (4 bytes)
7. **Bytecode**: The compiled instructions

## Testing

Run the included test suite:

```bash
./Tester/tester.sh
```

## Technical Details

- Memory size: 6144 bytes (6 * 1024)
- Index modulo: 512
- Maximum program name: 128 characters
- Maximum comment: 2048 characters
- Register count: 16 (r1-r16)

## License

EPITECH Project - Educational purposes only.
