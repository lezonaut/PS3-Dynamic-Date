#!/data/data/com.termux/files/usr/bin/bash

set -eu

echo "================================"
echo "      PS3 DYNAMIC DATE"
echo "================================"

mkdir -p output assets/backgrounds

echo "[1/4] Compiling renderer..."

clang -O2 -Wall -Wextra -Iinclude \
    src/renderer.c src/clock.c \
    $(pkg-config --cflags --libs freetype2) \
    -o renderer

echo "[2/4] Generating date..."

./renderer

echo "[3/4] Converting image..."

magick wallpaper.ppm wallpaper.png

echo "[4/4] Combining background..."

if [ ! -f assets/backgrounds/background.png ]; then
    echo "Background not found!"
    exit 1
fi

magick assets/backgrounds/background.png \
    wallpaper.png \
    -compose Screen -composite \
    output/date-wallpaper.png

echo "================================"
echo "       BUILD SUCCESS!"
echo "================================"
echo "Output: output/date-wallpaper.png"
