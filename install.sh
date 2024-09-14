#!/bin/sh

echo "[#1] Build"
make

echo "[#2] Clean"
make clean

echo "[#3] Change bashrc"
echo "$PWD/build/cli-startup" >>~/.bashrc
echo "$PWD/build/cli-startup" >>~/.zshrc

echo "[#4] Make config"
mkdir ~/.config/cli-startup/

echo "logo_color=cyan" >>~/.config/cli-startup/config

echo " ██████╗██╗     ██╗      ███████╗████████╗ █████╗ ██████╗ ████████╗██╗   ██╗██████╗ 
██╔════╝██║     ██║      ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██╔══██╗
██║     ██║     ██║█████╗███████╗   ██║   ███████║██████╔╝   ██║   ██║   ██║██████╔╝
██║     ██║     ██║╚════╝╚════██║   ██║   ██╔══██║██╔══██╗   ██║   ██║   ██║██╔═══╝ 
╚██████╗███████╗██║      ███████║   ██║   ██║  ██║██║  ██║   ██║   ╚██████╔╝██║     
 ╚═════╝╚══════╝╚═╝      ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝     
                                                                                    " >~/.config/cli-startup/logo
