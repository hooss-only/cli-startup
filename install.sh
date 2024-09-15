#!/bin/sh

echo "[#1] Build"
make

echo "[#2] Clean"
make clean

echo "[#3] Make config"
mkdir ~/.config/cli-startup/

echo "logo_color=cyan" >>~/.config/cli-startup/config

echo "Please add '~/(path to build directory)/cli-startup' to your .zshrc or .bashrc."
