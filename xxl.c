#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/utsname.h>

const char *Detect()
{
    #ifdef _WIN32
    return "windows";
    #elif __linux__
    return "linux";
    #elif __apple__
    return "MacOS";
    #endif
}
void LinuxInf(WINDOW *win){
    struct utsname uname_pointer;
    uname(&uname_pointer);
    mvwprintw(win,2,2,"%s %s","Your Os: ",uname_pointer.sysname);
    mvwprintw(win,3,2,"%s %s","Your Machne platform: ",uname_pointer.machine);
}





int main(){
    initscr();
    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);
    WINDOW *InfoWin = newwin(17,55,yMax/3,xMax/3);
    box(InfoWin,0,0);
    //char os[7] = Detect();
    if(Detect() == "linux")
	LinuxInf(InfoWin);
    if(Detect() == "windows")
	mvwprintw(InfoWin,2,2,"Your os: Windows");
    if(Detect() == "MacOS")
	mvwprintw(InfoWin,2,2,"Your os: Apple MacOS");
    wrefresh(InfoWin);


    getchar();
    endwin();
    return 0;
}
