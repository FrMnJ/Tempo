# Timed Phase Cycle (`tempo`)

`tempo` is a lightweight C program that allows users to define **custom phase cycles** with durations and repeat counts. Each phase executes for a specified time, with an optional **audible signal** at the end. This feature is suitable for productivity timers, workouts, simulations, or any scenario that requires **sequenced timed events**.

## Features

- Define **phases** with custom names and durations (in seconds).  
- Set the number of **repetitions** for the cycle.  
- Wait for the duration of each phase automatically.  
- Emit a **sound** (beep) at the end of each phase.  
- Cross-platform support: works on **Windows** and **Linux/macOS**.  

## Technical Details

- Written in **C**.  
- Uses a `cycle_t` structure to manage a sequence of `phase_t` items.  
- Includes platform-specific handling for waiting and sound:  
  - **Windows:** `Sleep()` and `Beep()`  
  - **Linux/macOS:** `sleep()` and terminal bell (`\a`)  

## Usage

1. **Compile with Makefile:**
```bash
make
```
2. **Run the program:**
```bash
./bin/tempo
```

## Error Codes
The program returns standard error codes defined in tempo_errors.h:
- `CYCLE_MEM_ERR` – Memory allocation failed for cycle.
- `PHASE_MEM_ERR` – Memory allocation failed for phase.

## Integration

You can extract the core logic into the following functions for reuse in other C projects:

- `cycle_t* make_cycle(void)` – Creates a new cycle.
- `phase_t* make_phase(const char* name, int seconds)` – Creates a phase.
- `void cycle_add_phase(cycle_t* cycle, phase_t* phase)` – Adds a phase to a cycle.
- `void next_phase(cycle_t* cycle)` – Moves to the next phase.
- `void del_cycle(cycle_t* cycle)` – Cleans up memory.