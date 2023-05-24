#include <splashkit.h>
#include <vector>
#include <string>

struct Track
{
    std::string title;
    std::string path;
};

struct Album
{
    std::string title;
    std::vector<Track> tracks;
    bitmap artwork;
};

// Global variables
std::vector<Album> albums;
int currentTrackIndex = -1;

// Function to load the albums and tracks
void loadAlbums()
{
    // Add your albums and tracks information here
    // Example:
    Album album1;
    album1.title = "Album 1";
    album1.artwork = load_bitmap(path_to_resource("album1_artwork.png"));

    Track track1;
    track1.title = "Track 1";
    track1.path = path_to_resource("album1_track1.wav");
    album1.tracks.push_back(track1);

    Track track2;
    track2.title = "Track 2";
    track2.path = path_to_resource("album1_track2.wav");
    album1.tracks.push_back(track2);

    albums.push_back(album1);

    // Add more albums and tracks as needed
}

// Function to draw the GUI
void drawGUI()
{
    // Draw the albums
    for (int i = 0; i < albums.size(); ++i)
    {
        // Draw album artwork
        draw_bitmap(albums[i].artwork, 10, 10 + (i * 100));

        // Draw album title
        draw_text(albums[i].title, COLOR_WHITE, "arial", 18, 130, 20 + (i * 100));

        // Draw tracks
        for (int j = 0; j < albums[i].tracks.size(); ++j)
        {
            // Highlight the currently playing track
            if (i == currentTrackIndex)
            {
                if (j == currentTrackIndex)
                {
                    fill_rectangle(COLOR_YELLOW, 130, 50 + (i * 100) + (j * 30), 200, 25);
                }
            }

            // Draw track title
            draw_text(albums[i].tracks[j].title, COLOR_WHITE, "arial", 14, 130, 50 + (i * 100) + (j * 30));
        }
    }
}

// Function to handle track selection
void selectTrack(int albumIndex, int trackIndex)
{
    if (albumIndex >= 0 && albumIndex < albums.size())
    {
        if (trackIndex >= 0 && trackIndex < albums[albumIndex].tracks.size())
        {
            if (currentTrackIndex != -1)
            {
                stop_music();
            }

            currentTrackIndex = trackIndex;

            // Load and play the selected track
            load_music(albums[albumIndex].tracks[trackIndex].path);
            play_music();
        }
    }
}

// Function to handle GUI events
void handleEvents()
{
    // Check for mouse click event
    if (mouse_clicked(LEFT_BUTTON))
    {
        // Get the mouse coordinates
        int mouseX = mouse_x();
        int mouseY = mouse_y();

        // Check for track selection
        for (int i = 0; i < albums.size(); ++i)
        {
            int trackIndex = (mouseY - 50 - (i * 100)) / 30;
            if (trackIndex >= 0 && trackIndex < albums[i].tracks.size())
            {
                selectTrack(i, trackIndex);
                break; // Exit the loop once a track is selected
            }
        }
    }
}

// Function to initialize the music player
void initializeMusicPlayer()
{
    loadAlbums();
    // Additional initialization code if needed
}

// Function to clean up and free resources
void cleanup()
{
    stop_music();
    free_all_music();
    // Additional cleanup code if needed
}

// Main function
int main()
{
    // Initialize the music player
    initializeMusicPlayer();
    // Open a window for the GUI
    open_window("Music Player", 500, 500);

    // Main game loop
    while (!window_close_requested("Music Player"))
    {
        process_events();
        clear_screen(COLOR_BLACK);

        // Draw the GUI
        drawGUI();

        // Handle GUI events
        handleEvents();

        refresh_screen();
    }

    // Clean up and free resources
    cleanup();

    // Close the window
    close_window("Music Player");

    return 0;
}