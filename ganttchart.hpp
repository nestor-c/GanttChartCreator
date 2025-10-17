#ifndef GANTTCHART_HPP
#define GANTTCHART_HPP
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>

class GanttChart{
	
	private:
		winsize termSize;
		std::istringstream iSS;
		//Print Chart
		void printChart();
		void printTop_Chart();
		void printMid_Chart();
		void printBot_Chart();
		//Helper Functions
		int parse(std::string);
		int getTerminalSize();
	public:
		GanttChart(std::string time1);
		
};
#endif
