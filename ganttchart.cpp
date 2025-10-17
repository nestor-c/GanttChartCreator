#include "ganttchart.hpp"

GanttChart::GanttChart(std::string time1){
	 parse(time1);
};

int GanttChart::parse(std::string time1){
	int hours, minutes;
	char colon;
	std::string meridian;
	std::istringstream ss(time1);
	ss >> hours >> colon >> minutes >> meridian;
	
	if(colon != ':'){
		std::cerr << "Invalid format\n";
		return 1;
	}
	getTerminalSize();
	
	for(int i = 1;i<=termSize.ws_col;i++){
		if (i==1) std::cout << "\n\n";		
		std::cout << "=";
	}
	
	std::cout << "Hours: " << hours << ", Minutes: " << minutes << ", Meridian: " << meridian << "\n\n";
	printChart();
	return 0;
}

void GanttChart::printChart(){
	
	std::string  tl_corner = u8"┏";
	std::string  tr_corner = u8"┓";
	std::string  bl_corner = u8"┗";
	std::string  br_corner = u8"┛";
	std::string  bridge = u8"━";
	for(int i = 0; i < termSize.ws_col;i++){
		if(i==0) std::cout << tl_corner;
		
		if(i==termSize.ws_col-2) {std::cout<<tr_corner; return;}
		std::cout << bridge;
		

	}	
}

int GanttChart::getTerminalSize(){
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &termSize) == -1) {
            std::cerr << "Error getting terminal size." << std::endl;
            return 1;
        }
	return 0;
}


