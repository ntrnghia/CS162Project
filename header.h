#pragma once
#include<iostream> //print to screen
#include<limits.h>	//INT_MAX
#include<cstring>	//strcat, strcpy
#include<iomanip> //format output
#include<fstream> //file operation
#include<sstream> //print table in view course and show score easily
#include<time.h> //get real time in check-in function
#include<direct.h> //create directory
using namespace std;

const int wholeRange = 80, numRange = 6;

const int usernameLimit = 10, fullnameLimit = 30, emailLimit = 27,
mobileLimit = 12, passwordLimit = 10, ClassLimit = 10;

const int courseCodeLimit = 10, yearLimit = 5, semesterLimit = 2, courseNameLimit = 50,
dayLimit = 11, timeLimit = 6;

const int checktimeLimit = 30;

const char pathMain[]{ "data" };

const char pathCourse[]{ "course" }, pathClass[]{ "class" },
pathScore[]{ "score" }, pathPresence[]{ "presence" };

const char fileUser[]{ "users" }, fileCourse[]{ "courses" }, fileClass[]{ "classes" };

struct user {
	char username[usernameLimit]{};
	char fullname[fullnameLimit]{};
	char email[emailLimit]{};
	char mobile[mobileLimit]{};
	enum category { student, academicStaff, lecturer }type;
	char password[passwordLimit]{};
	char Class[ClassLimit]{};
	user*next = NULL;
};
struct course {
	char courseCode[courseCodeLimit]{};
	char year[yearLimit]{};
	char semester[semesterLimit]{};
	char courseName[courseNameLimit]{};
	char lecturerUsername[usernameLimit]{};
	char startAt[dayLimit]{};
	char endAt[dayLimit]{};
	struct {
		char from[timeLimit]{};
		char to[timeLimit]{};
	}day[6]{};
	struct student {
		char ID[usernameLimit]{};
		float mid = 0;
		float lab = 0;
		float final = 0;
		int timecheck = 0;
		time_t checktime[checktimeLimit]{};
		student*next = NULL;
	}*stuhead = NULL;
	course*next = NULL;
};
struct classes {
	char Class[ClassLimit]{};
	struct student {
		char ID[usernameLimit]{};
		student*next = NULL;
	}*stuhead = NULL;
	classes*next = NULL;
};

extern user*User;
extern course*Course;
extern classes*Classes;

void optionForm(char*title, char &var, int titleRange);
void menuForm(int num, char*title);
void notifyForm(char*title);
void start();

bool SignIn();
bool SignUp();

void initAndShowUser();
void initAndShowCourse();
void initAndShowClass();
void delAndSaveUser();
void delAndSaveCourse();
void delAndSaveClass();