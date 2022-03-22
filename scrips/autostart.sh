#!/bin/sh

#######################################################################################
########## Start Software
# HDMI
# xrandr --auto --output HDMI1 --same-as eDP1 --size 2560x1600

# Power Manager
xfce4-power-manager &

# NetworkManager
nm-applet &

# Volume Manager
# xfce4-volumed-pulse &

# FCITX
fcitx5 -d &

# Wallpaper
feh --randomize --bg-fill ~/Pictures/wallpaper/Personal/0239.jpg &

# picom
picom -b -c &

# Goldendict
goldendict &

# Keybinds
xbindkeys &

#######################################################################################
########## DWM Status Bar 

# Status bar
slstatus


