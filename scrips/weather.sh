curl -sf "wttr.in/China,Jiangxi?format=1" > "$HOME/.local/share/weatherreport" || exit 1 ;
rain=$(cat ~/.local/share/weatherreport)
echo $rain
sleep 3600
