#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)

//**VARIABLES**//
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
bool displayOverride=false;
bool LCDUserInput=false;
int UserResult=0;
string overrideString1,overrideString2;
int peBatteryLevel=0;
string mainBattery, backupBattery, peBattery;
string line1,line2;

//**STRINGS - 16 CHAR LIMIT**//
static string sInit="Initializing...";
static string sNoMove="DO NOT MOVE";
static string sTarget="Targeting:";
static string sError="Error: ";
static string sDead="DEADBEEFDEADBEEF";
static string sLeft="LEFT";
static string sRight="RIGHT";
static string sDoNothing="Do Nothing";
static string sChoice="<     Enter    >";


//**FUNCTIONS**//

void clearLCD(){
	clearLCDLine(0);
	clearLCDLine(1);
}

void setOverrideStrings(string L1,string L2){
	overrideString1=L1;
	overrideString2=L2;
	displayOverride = true;
}

void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}//end waitForPress


void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}//end waitForRelease

void displayString(string L1,string L2){
	string blank = "";
	if(L1!=blank || L2!=blank){
		line1=L1;
		line2=L2;
		displayLCDCenteredString(0,line1);
		displayLCDCenteredString(1,line2);
	}
}

void displayBattery(){
	//Display main battery voltage
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
	line1="M: ";
	strcat(line1,mainBattery);

	//Display Power Expander battery voltage
	sprintf(peBattery, "%1.1f%c", peBatteryLevel/182.4,'V'); //Build the value to be displayed
	string line1Part2 = " E: ";
	strcat(line1Part2, peBattery);
	strcat(line1,line1Part2);
	displayLCDString(0,0,line1);

	//Display the Backup battery voltage
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
	line2="Backup: ";
	strcat(line2,backupBattery);
	displayLCDString(1,0,line2);
}//end displayBattery

//turn on the backlight when user presses button
task backlightTimer(){
	bLCDBacklight=true;
	wait1Msec(8000);
	bLCDBacklight=false;
}

//Variables for Auton Chooser
const short k_LeftAuton=1;
const short k_RightAuton=2;
const short k_DoNothingAuton=3;
const static short numOptions=3;

//The LCD Auton Chooser Itself
int chooseAuton()
{
	int choice = 0;
	clearLCD();
	//Let user choose with buttons
	while(nLCDButtons != centerButton)
	{
		switch(choice){
		case 0:
			//Display first choice
			setOverrideStrings(sLeft,sChoice);
			displayString(overrideString1,overrideString2);
			//Wait for choice
			waitForPress();
			if(nLCDButtons == leftButton){
				waitForRelease();
				choice = numOptions-1;
			}
			else if(nLCDButtons == rightButton){
				waitForRelease();
				choice++;
			}
			break;
		case 1:
			setOverrideStrings(sRight,sChoice);
			displayString(overrideString1,overrideString2);
			//Wait for choice
			waitForPress();
			if(nLCDButtons == leftButton){
				waitForRelease();
				choice--;
			}
			else if(nLCDButtons == rightButton){
				waitForRelease();
				choice++;
			}
			break;
		case 2:
			setOverrideStrings(sDoNothing,sChoice);
			displayString(overrideString1,overrideString2);
			//Wait for choice
			waitForPress();
			if(nLCDButtons == leftButton){
				waitForRelease();
				choice--;
			}
			else if(nLCDButtons == rightButton){
				waitForRelease();
				choice=0;
			}
			break;
		default:
			choice = 0;
			break;
		}//end switch
	}//end while

	//Return the result after the loop
	clearLCD();
	switch(choice){
	case 0:
		return k_LeftAuton;
		break;
	case 1:
		return k_RightAuton;
		break;
	case 2:
		return k_DoNothingAuton;
		break;
	default:
		return k_DoNothingAuton;
		break;
	}//end switch
}//end chooseAuton


//Main LCD execution
task startLCD()
{
	//first startup
	StartTask(backlightTimer,5);
	clearLCD();

	while(true){
		clearLCD();

		//decide what to display
		if(displayOverride){
			bLCDBacklight=true;
			displayString(overrideString1,overrideString2);
			if(LCDUserInput){
				UserResult=chooseAuton();
				LCDUserInput=false;
				displayOverride=false;
			}
		}
		if(!displayOverride){
			//turn on backlight if button pressed
			if(nLCDButtons != 0){
				StartTask(backlightTimer);
				waitForRelease();
			}
			displayBattery();
		}
		wait1Msec(100);
	}//end while
}//end startLCD
