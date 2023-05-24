#include "splashkit.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void init_window(void) {
    open_window("Basic Window", WINDOW_WIDTH, WINDOW_HEIGHT);
}

void draw_house(void) {
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen();
}

int main(void) {
    init_window();

    draw_house();

    delay(5000);

    return 0;
}