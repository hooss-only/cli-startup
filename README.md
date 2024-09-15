# Welcome to CLI-STARTUP

This project is for printing logo, weather, etc. when start up a new terminal.

# Installation

dependencies:
- GCC compiler
- GNU make

```
git clone https://github.com/hooss-only/cli-startup.git --depth=1
cd cli-startup
./install.sh
```

And edit your `.zshrc` or `.bashrc`, add a new line to them.
```
(path to build directory)/cli-startup
```

# Configuration

You can customize with configuration file, `~/.config/cli-startup/config`.

```
// you can change logo in .config/cil-startup/logo
print_logo=(yes/no)
logo_color=(black/red/green/yellow/blue/purple/cyan/white)
// you can change it in .config/cli-startup/wise_texts
wise_saying=(yes/no)
```
