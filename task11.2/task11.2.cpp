#include "splashkit.h"

int main()
{
    // Load music file
    music my_music = load_music("my_music", "my_music.mp3");

    // Open window
    open_window("Music Player", 400, 300);

    // Play music
    play_music(my_music);

    // Main loop
    while (not quit_requested())
    {
        // Handle input
        process_events();

        // Draw interface
        clear_screen(COLOR_WHITE);
        draw_text("Music Player", COLOR_BLACK, "arial", 24, 10, 10);
        refresh_screen(60);
    }

    // Stop music and free resources
    stop_music();
    free_all_music();

    return 0;
}