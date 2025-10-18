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
		
	std::cout << "Hours: " << hours << ", Minutes: " << minutes << ", Meridian: " << meridian << "\n\n";
	printChart();
	return 0;
}

void GanttChart::printChart(){
	printTop_Chart();
	printMid_Chart();
	printBot_Chart();
}

void GanttChart::printTop_Chart(){
	std::string  tl_corner = u8"┏";
	std::string  tr_corner = u8"┓";
	std::string  bridge = u8"━";
	int halfway = termSize.ws_col * .5;

	for (int i=0;i<halfway;i++){
		if(i==0){std::cout << tl_corner;}
		else if(i==halfway-1){std::cout << tr_corner << std::endl;}
		else {std::cout << bridge;}
	}
	
}

void GanttChart::printMid_Chart(){
	std::string div = u8"┃";
	int half_screenWidth = termSize.ws_col * .5;
	int half_screenHeight = termSize.ws_row;
		
	//Determines how far out to go	
	auto printAcross = [half_screenWidth, div](){
		int twentyFourHourBlocks = (half_screenWidth*2)/24;
		
		std::cout << "half_screenWidth: " << half_screenWidth << std::endl;
		
		std::cout << "TwentyFourHourBlocks: " << twentyFourHourBlocks << std::endl;
			
		for(int i=0;i<(half_screenWidth);i++){
			if(i==0 ){std::cout << div;}
			else if(i == (half_screenWidth-1)) {std::cout << div <<std::endl;}
			else { std::cout<< " ";}
		}
	};
	//Determines how far down to go
	for(int i=0;i<((half_screenHeight*.25)-3);i++){
		printAcross();	
	}
}

void GanttChart::printBot_Chart(){
	std::string  bl_corner = u8"┗";
	std::string  br_corner = u8"┛";
	std::string  bridge = u8"━";
	int halfway = termSize.ws_col * .5;

	for (int i=0;i<halfway;i++){
		if(i==0){std::cout << bl_corner;}
		else if(i==halfway-1){std::cout << br_corner << std::endl;}
		else {std::cout << bridge;}
	}
}
	
int GanttChart::getTerminalSize(){
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &termSize) == -1) {
            std::cerr << "Error getting terminal size." << std::endl;
            return 1;
        }
	return 0;
}


