#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
    int x = 0, y = 0;

    initscr();
    noecho();
    curs_set(FALSE);

    while(x<100) {
        clear(); // Clear the screen
        mvprintw(y, x, "::"); // Print
        refresh();

        usleep(DELAY); // Freq
        x++;
        y=(x%4);
    }

    endwin();
}