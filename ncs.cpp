#include <iostream>
#include <ncurses.h>
#include <ctime>



using namespace std;

int main(int argc,char *argv[]){
    initscr();
    
    // window Box Border Box
    int yMax , xMax;
    getmaxyx(stdscr,yMax,xMax);

    WINDOW *TimeWin = newwin(7,50,yMax/5,xMax/4);
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    wattron(TimeWin,COLOR_PAIR(1));
    box(TimeWin,'*','*');
    wattroff(TimeWin,COLOR_PAIR(1));
    wrefresh(TimeWin);

    // Get Time
    while(1){
        time_t curr_time;
        curr_time = time(NULL);

        tm *tm_local = localtime(&curr_time);
        mvwprintw(TimeWin,3,20,"%d:%d:%d",tm_local->tm_hour,tm_local->tm_min,tm_local->tm_sec);
	wrefresh(TimeWin);
    }
    endwin();
    return 0;
}
