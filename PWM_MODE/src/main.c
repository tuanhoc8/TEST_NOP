#include "s32k144.h"
#include "project.h"

int main(void){
	Project_Config();
	while(1){
		ChangeDutyMode();
	}

}
