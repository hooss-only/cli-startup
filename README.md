# Welcome to CLI-STARTUP

This project is for printing logo, weather, etc. when start up a new terminal.

# Installation

dependencies:
- GCC compiler
- GNU make

Clone this project.
```
$ git clone https://github.com/hooss-only/cli-startup.git --depth=1
```
Move to cli-startup directory, then type the below command.
```
$ ./install.sh
```

And edit your `.zshrc` or `.bashrc`, add a new line to them.
```
(path to build directory)/cli-startup
```

# Configuration

You can customize with configuration file, `~/.config/cli-startup/config`.

```
print_logo=(yes/no)
logo_color=(black/red/green/yellow/blue/purple/cyan/white)
```
