#!/usr/bin/env sh
echo "[BEGGIN]"
cd Vigiscrap
bash m.bash $1 all
cd ..
sh launcher_analyse.sh
echo "[DONE]"