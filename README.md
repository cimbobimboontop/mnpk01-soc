# MNPK01-System: Full-Stack 8-bit RISC Microcomputer

![Status](https://img.shields.io/badge/Status-Development-orange)
![License](https://img.shields.io/badge/License-GPLv3-green)
![Arch](https://img.shields.io/badge/Architecture-8--bit_RISC-blue)

## 📌 Project Overview
MNPK01-System is a comprehensive 8-bit microcomputer design developed as a graduation thesis. This project encompasses a custom CPU core architecture (RTL), physical PCB hardware design, and low-level firmware development.

The primary goal is to demonstrate a deep, vertical understanding of computer systems—from hardware description and logic gates to physical PCB fabrication.

---

## 🏗 Technical Specifications
- **CPU Core:** MNPK-01 (Custom RISC Architecture)
- **Data Width:** 8-bit
- **Address Bus:** 16-bit (Addressing up to 64KB)
- **ISA:** Custom Instruction Set (Arithmetic, Logic, Flow Control)
- **Memory Model:** Harvard Architecture (Dedicated Instruction and Data paths)
- **Physical Design:** Custom PCB (KiCad) with SPI Flash (cFeon compatible) and External RAM support

---

## 📂 Repository Structure
The project follows industrial SoC (System-on-Chip) development standards:

- `rtl/` – Verilog HDL source files (ALU, Registers, Control Unit)
- `sim/` – Simulation environment, testbenches, and VCD wave captures
- `hardware/` – KiCad project files (Schematics, Layout, Production BOM)
- `firmware/` – Software and bootloaders written for the MNPK-01 architecture
- `docs/` – Technical documentation for ISA and Memory Mapping
- `scripts/` – Automation bash scripts for compilation and simulation

---

## 🛠 Toolchain
- **Logic Design:** Icarus Verilog (`iverilog`)
- **Simulation:** GTKWave
- **Hardware Design:** KiCad 8.0
- **Primary Editor:** Neovim (on Arch Linux)
- **Research/Reversing:** Ghidra (used for analyzing BIOS structures)

---

## 🚀 Getting Started (Simulation)
To verify the CPU logic or ALU operations in a simulated environment:
1. Open your terminal in the root directory.
2. Execute the simulation script: `./scripts/run_sim.sh`
3. Analyze the results in GTKWave: `gtkwave sim/dump.vcd`

---

## 📜 License
This project is licensed under the **GPLv3 License**. You are free to fork and modify this project, provided that original authorship is credited and derivatives are shared under the same license.

**© 2026 Matus Krivanik**
