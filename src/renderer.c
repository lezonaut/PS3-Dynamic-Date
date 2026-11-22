#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "clock.h"

#define WIDTH 1920
#define HEIGHT 1080

static unsigned char canvas[HEIGHT][WIDTH][3];

void draw_text(
    FT_Face face,
    const char *text,
    int x,
    int baseline,
    int size,
    unsigned char color
) {
    FT_Set_Pixel_Sizes(face, 0, size);

    int pen_x = x;

    while (*text) {
        if (FT_Load_Char(face, *text, FT_LOAD_RENDER)) {
            text++;
            continue;
        }

        FT_GlyphSlot glyph = face->glyph;
        FT_Bitmap *bitmap = &glyph->bitmap;

        for (unsigned int y = 0; y < bitmap->rows; y++) {
            for (unsigned int bx = 0; bx < bitmap->width; bx++) {
                int px = pen_x + glyph->bitmap_left + bx;
                int py = baseline - glyph->bitmap_top + y;

                if (px < 0 || px >= WIDTH ||
                    py < 0 || py >= HEIGHT)
                    continue;

                unsigned char alpha =
                    bitmap->buffer[y * bitmap->pitch + bx];

                unsigned char value =
                    (color * alpha) / 255;

                canvas[py][px][0] = value;
                canvas[py][px][1] = value;
                canvas[py][px][2] = value;
            }
        }

        pen_x += glyph->advance.x >> 6;
        text++;
    }
}

int main(void)
{
    FT_Library library;
    FT_Face face;
    DateInfo date;

    const char *font =
        "assets/fonts/Roboto-Regular.ttf";

    if (get_current_date(&date) != 0) {
        printf("Date error!\n");
        return 1;
    }

    if (FT_Init_FreeType(&library))
        return 1;

    if (FT_New_Face(library, font, 0, &face)) {
        printf("Font loading failed!\n");
        FT_Done_FreeType(library);
        return 1;
    }

    memset(canvas, 0, sizeof(canvas));

    char month_year[64];
    char day_text[64];

    snprintf(month_year, sizeof(month_year),
             "%s %d", date.month_name, date.year);

    snprintf(day_text, sizeof(day_text),
             "%s / %02d", date.weekday_name, date.day);

    draw_text(face, "T o d a y",
              110, 170, 28, 160);

    draw_text(face, month_year,
              110, 270, 76, 235);

    draw_text(face, day_text,
              110, 320, 24, 155);

    FILE *file = fopen("wallpaper.ppm", "wb");

    if (!file) {
        printf("Cannot create wallpaper!\n");
        FT_Done_Face(face);
        FT_Done_FreeType(library);
        return 1;
    }

    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(canvas, 3, WIDTH * HEIGHT, file);

    fclose(file);

    FT_Done_Face(face);
    FT_Done_FreeType(library);

    printf("Dynamic Date Wallpaper generated!\n");
    printf("%s\n", month_year);
    printf("%s\n", day_text);

    return 0;
}
