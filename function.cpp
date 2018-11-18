#include"header.h"
//main linked list
user*User = NULL;
course*Course = NULL;
classes*Classes = NULL;
//support function
void checkcinfail() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
int lengthNum(int a) {
	return a == 0 ? 0 : lengthNum(a / 10) + 1;
}
char lowercase(char a) {
	return (a > 64 && a < 91) ? a + 32 : a;
}
char changecase(char a) {
	return (a > 64 && a < 91) ? a + 32 : a - 32;
}
bool compareWithOutCase(char*a, char*b) {
	if (strlen(a) > strlen(b) || strlen(b) > strlen(a)) return false;
	for (int i = 0; i < strlen(a); ++i)
		if (a[i] != b[i] && a[i] != changecase(b[i])) return false;
	return true;
}
void makesortname(char*name, char*username) {
	int i = 0, j = 0, k; //i vs name, j vs username, k vs end.
	char end[10];
	while (i < strlen(name)) {
		while (i < strlen(name) && name[i] == ' ') ++i;
		if (i < strlen(name)) username[j++] = lowercase(name[i++]);
		for (k = 0; i < strlen(name) && name[i] != ' '; ++i, ++k) end[k] = lowercase(name[i]);
		end[k] = '\0';
	}
	for (int k = 0; k < strlen(end); ++k, ++j) username[j] = end[k];
	username[j] = '\0';
}
//form function
void inputForm(char*title, char*var, int varLimit, int titleRange) {
	cout << '|' << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl;
	cout << '|' << setw(titleRange / 2 + strlen(title) / 2) << title << setw(titleRange / 2 + titleRange % 2 - strlen(title) / 2) << '|' << setw((wholeRange - titleRange) / 2 - varLimit / 2) << "  ";
	cin.getline(var, varLimit); checkcinfail();
	cout << '|' << setfill('_') << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl << setfill(' ');
}
void inputForm(char*title, float &var, int titleRange) {
	cout << '|' << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl;
	cout << '|' << setw(titleRange / 2 + strlen(title) / 2) << title << setw(titleRange / 2 + titleRange % 2 - strlen(title) / 2) << '|' << "  ";
	cin >> var; cin.clear(); cin.ignore(INT_MAX, '\n');
	cout << '|' << setfill('_') << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl << setfill(' ');
}
void optionForm(char*title, char &var, int titleRange) {
	cout << '|' << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl;
	cout << '|' << setw(titleRange / 2 + strlen(title) / 2) << title << setw(titleRange / 2 + titleRange % 2 - strlen(title) / 2) << '|' << "  ";
	cin >> var; cin.ignore(INT_MAX, '\n'); var -= 48;
	cout << '|' << setfill('_') << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl << setfill(' ');
}
void showForm(char*title, char*var, int titleRange) {
	cout << '|' << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl;
	cout << '|' << setw(titleRange / 2 + strlen(title) / 2) << title << setw(titleRange / 2 + titleRange % 2 - strlen(title) / 2) << '|' << setw((wholeRange - titleRange) / 2 + strlen(var) / 2) << var << setw((wholeRange - titleRange) / 2 + (wholeRange - titleRange) % 2 - strlen(var) / 2) << '|' << endl;
	cout << '|' << setfill('_') << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl << setfill(' ');
}
void showForm(char*title, float var, int titleRange) {
	cout << '|' << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl;
	cout << '|' << setw(titleRange / 2 + strlen(title) / 2) << title << setw(titleRange / 2 + titleRange % 2 - strlen(title) / 2) << '|' << setw((wholeRange - titleRange) / 2 + 1) << var << setw((wholeRange - titleRange) / 2 + (wholeRange - titleRange) % 2 - 1) << '|' << endl;
	cout << '|' << setfill('_') << setw(titleRange) << '|' << setw(wholeRange - titleRange) << '|' << endl << setfill(' ');
}
void showForm(char*title) {
	cout << '|' << setw(wholeRange) << '|' << endl;
	cout << '|' << setw(wholeRange / 2 + strlen(title) / 2) << title << setw(wholeRange / 2 + wholeRange % 2 - strlen(title) / 2) << '|' << endl;
	cout << '|' << setfill('_') << setw(wholeRange) << '|' << endl << setfill(' ');
}
void menuForm(int num, char*title) {
	cout << '|' << setw(numRange) << '|' << setw(wholeRange - numRange) << '|' << endl;
	cout << '|' << setw(numRange / 2 + lengthNum(num) / 2) << num << setw(numRange / 2 - lengthNum(num) / 2) << '|' << setw((wholeRange - numRange) / 2 + strlen(title) / 2) << title << setw((wholeRange - numRange) / 2 - strlen(title) / 2) << '|' << endl;
	cout << '|' << setfill('_') << setw(numRange) << '|' << setw(wholeRange - numRange) << '|' << endl << setfill(' ');
}
void notifyForm(char*title) {
	cout << R"(| /\    /\ )" << setw(wholeRange - 10) << '|' << endl;
	cout << R"(| \/ /\ \/ )" << setw(wholeRange / 2 + strlen(title) / 2 - 10) << title << setw(wholeRange / 2 - strlen(title) / 2) << '|' << endl;
	cout << R"(|____\/____)" << setfill('_') << setw(wholeRange - 10) << '|' << endl << setfill(' ');
}
void start() {
	system("cls");
	cout << ' ' << setfill('_') << setw(wholeRange) << ' ' << endl << setfill(' ');
}
void start(user admin) {
	system("cls");
	cout << "Welcome " << admin.fullname << "!\n";
	cout << ' ' << setfill('_') << setw(wholeRange) << ' ' << endl << setfill(' ');
}
void done() {
	notifyForm("Your procedure has been done!");
	cin.ignore(INT_MAX, '\n');
}
//check function
bool isExistUser(char*username) {
	for (user*cur = User; cur != NULL; cur = cur->next)
		if (!strcmp(username, cur->username)) return true;
	return false;
}
bool isExistUserLecturer(char*fullname) {
	for (user*cur = User; cur != NULL; cur = cur->next)
		if (compareWithOutCase(fullname, cur->fullname) && cur->type == user::lecturer) return true;
	return false;
}
bool isExistStudentInCourse(course*cur, char*ID) {
	for (course::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next)
		if (!strcmp(curstu->ID, ID)) return true;
	return false;
}
bool isExistStudentInCourse(course*cur, char*ID, course::student *&match) {
	for (course::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next)
		if (!strcmp(curstu->ID, ID)) {
			match = curstu;
			return true;
		}
	return false;
}
bool isExistStudentInClass(classes*cur, char*ID) {
	for (classes::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next)
		if (!strcmp(curstu->ID, ID)) return true;
	return false;
}
bool isExistStudent(char*ID) {
	for (classes*cur = Classes; cur != NULL; cur = cur->next)
		for (classes::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next)
			if (!strcmp(curstu->ID, ID)) return true;
	return false;
}
bool isExistCourse(char*courseCode, char*year) {
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) return true;
	return false;
}
bool isExistClass(char*classCode, classes*&match) {
	for (classes*curcla = Classes; curcla != NULL; curcla = curcla->next)
		if (compareWithOutCase(curcla->Class, classCode)) {
			match = curcla;
			return true;
		}
	return false;
}
//file and linked list function
void initAndShowUser() {
	cout << "FILE " << fileUser << endl;
	char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, fileUser);
	ifstream fin(file, ios_base::binary);
	for (user tmp, *cur; fin.read((char*)(&tmp), sizeof(user) - sizeof(user*));) {
		if (User == NULL) {
			cout << setw(14) << "Catagory" << ' ';
			cout << setw(usernameLimit) << "Username" << ' ';
			cout << setw(fullnameLimit) << "Fullname" << ' ';
			cout << setw(emailLimit) << "Email" << ' ';
			cout << setw(mobileLimit) << "Mobile" << ' ';
			cout << setw(passwordLimit) << "Password" << ' ';
			cout << setw(ClassLimit) << "Class" << endl;
			cur = User = new user;
		}
		else cur = cur->next = new user;
		*cur = tmp;
		switch (cur->type) {
		case 0:cout << setw(14) << "Student" << ' '; break;
		case 1:cout << setw(14) << "Academic Staff" << ' '; break;
		case 2:cout << setw(14) << "Lecturer" << ' '; break;
		}
		cout << setw(usernameLimit) << cur->username << ' ';
		cout << setw(fullnameLimit) << cur->fullname << ' ';
		cout << setw(emailLimit) << cur->email << ' ';
		cout << setw(mobileLimit) << cur->mobile << ' ';
		cout << setw(passwordLimit) << cur->password << ' ';
		if (cur->type == 0) cout << setw(ClassLimit) << cur->Class;
		cout << endl;
	}
	fin.close();
}
void initAndShowCourse() {
	cout << "FILE " << fileCourse << endl;
	char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, fileCourse);
	ifstream fin(file, ios_base::binary);
	for (course tmp, *cur; fin.read((char*)(&tmp), sizeof(course) - sizeof(course::student*) - sizeof(course*));) {
		if (Course == NULL) {
			cout << setw(courseCodeLimit) << "Coursecode" << ' ';
			cout << setw(yearLimit) << "Year" << ' ';
			cout << setw(8) << "Semester" << ' ';
			cout << setw(courseNameLimit) << "Course name" << ' ';
			cout << setw(16) << "LecturerUsername" << ' ';
			cout << setw(dayLimit) << "Start at" << ' ';
			cout << setw(dayLimit) << "End at" << ' ' << endl;
			cur = Course = new course;
		}
		else cur = cur->next = new course;
		*cur = tmp;
		cout << setw(courseCodeLimit) << cur->courseCode << ' ';
		cout << setw(yearLimit) << cur->year << ' ';
		cout << setw(8) << cur->semester << ' ';
		cout << setw(courseNameLimit) << cur->courseName << ' ';
		cout << setw(16) << cur->lecturerUsername << ' ';
		cout << setw(dayLimit) << cur->startAt << ' ';
		cout << setw(dayLimit) << cur->endAt << ' ' << endl;
		for (int i = 0; i < 6; ++i)
			if (strcmp(cur->day[i].from, "") && strcmp(cur->day[i].to, ""))
				cout << "Thu " << i + 2 << ": " << cur->day[i].from << ' ' << cur->day[i].to << endl;
		char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, pathCourse);
		strcat(file, "/"); strcat(file, cur->courseCode); strcat(file, "-"); strcat(file, cur->year);
		ifstream finstu(file, ios_base::binary);
		for (course::student tmpstu, *curstu; finstu.read((char*)(&tmpstu), sizeof(course::student) - sizeof(course::student*));) {
			if (cur->stuhead == NULL) curstu = cur->stuhead = new course::student;
			else curstu = curstu->next = new course::student;
			*curstu = tmpstu;
			cout << curstu->ID << ' ' << curstu->mid << ' ' << curstu->lab << ' ' << curstu->final << ' ' << curstu->timecheck << endl;
			for (int i = 0; i < curstu->timecheck; ++i) {
				char*time=ctime(&curstu->checktime[i]);
				cout << "Time " << i + 1 << ": " << time;
			}
		}
		finstu.close();
	}
	fin.close();
}
void initAndShowClass() {
	cout << "FILE " << fileClass << endl;
	char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, fileClass);
	ifstream fin(file);
	classes *cur;
	for (char Class[ClassLimit]; fin.getline(Class, ClassLimit);) {
		if (Classes == NULL) cur = Classes = new classes;
		else cur = cur->next = new classes;
		strcpy(cur->Class, Class);
		cout << cur->Class << ' ';
		char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, pathClass);
		strcat(file, "/"); strcat(file, cur->Class);
		ifstream finstu(file);
		classes::student *curstu;
		int num = 0;
		for (char ID[usernameLimit]; finstu.getline(ID, usernameLimit); ++num) {
			if (cur->stuhead == NULL) curstu = cur->stuhead = new classes::student;
			else curstu = curstu->next = new classes::student;
			strcpy(curstu->ID, ID);
		}
		cout << "The number of students: " << num << endl;
		finstu.close();
	}
	fin.close();
}
void delAndSaveUser() {
	if (User != NULL) {
		_mkdir(pathMain);
		char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, fileUser);
		ofstream fout(file, ios_base::binary);
		while (User != NULL) {
			fout.write((char*)User, sizeof (user) - sizeof(user*));
			user *tmp = User;
			User = User->next;
			delete tmp;
		}
		fout.close();
	}
}
void delAndSaveCourse() {
	if (Course != NULL) {
		char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, fileCourse);
		ofstream fout(file, ios_base::binary);
		while (Course != NULL) {
			fout.write((char*)Course, sizeof(course) - sizeof(course::student*) - sizeof(course*));
			if (Course->stuhead != NULL) {
				char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, pathCourse);
				_mkdir(file);
				strcat(file, "/"); strcat(file, Course->courseCode); strcat(file, "-"); strcat(file, Course->year);
				ofstream foutstu(file, ios_base::binary);
				while (Course->stuhead != NULL) {
					foutstu.write((char*)Course->stuhead, sizeof(course::student) - sizeof(course::student*));
					course::student *tmp = Course->stuhead;
					Course->stuhead = Course->stuhead->next;
					delete tmp;
				}
				foutstu.close();
			}
			course *tmp = Course;
			Course = Course->next;
			delete tmp;
		}
		fout.close();
	}
}
void delAndSaveClass() {
	if (Classes != NULL) {
		char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, fileClass);
		ofstream fout(file);
		while (Classes != NULL) {
			fout << Classes->Class << endl;
			if (Classes->stuhead != NULL) {
				char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, pathClass);
				_mkdir(file);
				strcat(file, "/"); strcat(file, Classes->Class);
				ofstream foutstu(file);
				while (Classes->stuhead != NULL) {
					foutstu << Classes->stuhead->ID << endl;
					classes::student *tmp = Classes->stuhead;
					Classes->stuhead = Classes->stuhead->next;
					delete tmp;
				}
				foutstu.close();
			}
			classes *tmp = Classes;
			Classes = Classes->next;
			delete tmp;
		}
		fout.close();
	}
}
//add to linked list function
void creatAcc(user::category type, char*username, char*fullname, char*Class) {
	if (!isExistUser(username)) {
		user*cur = User;
		while (cur->next != NULL) cur = cur->next;
		cur->next = new user;
		cur->next->type = type;
		strcpy(cur->next->username, username);
		strcpy(cur->next->password, "123123");
		strcpy(cur->next->fullname, fullname);
		strcpy(cur->next->Class, Class);
	}
}
void addCourse(course tmp, char*fullname) {
	course*cur = Course;
	if (Course == NULL) cur = Course = new course, *Course = tmp;
	else {
		while (cur->next != NULL) cur = cur->next;
		cur = cur->next = new course;
		*cur = tmp;
	}
	if (!isExistUserLecturer(fullname)) {
		if (isExistUser(cur->lecturerUsername)) {
			char username[usernameLimit], n[]{ "0" };
			do {
				++n[0];
				strcpy(username, cur->lecturerUsername);
				strcat(username, n);
			} while (isExistUser(username));
			strcpy(cur->lecturerUsername, username);
		}
		creatAcc(user::lecturer, cur->lecturerUsername, fullname, "");
	}
}
void addStudentToClass(classes*cur, char*ID) {
	if (cur->stuhead == NULL) cur->stuhead = new classes::student, strcpy(cur->stuhead->ID, ID);
	else {
		classes::student*curstu = cur->stuhead;
		while (curstu->next != NULL) curstu = curstu->next;
		curstu->next = new classes::student;
		strcpy(curstu->next->ID, ID);
	}
	creatAcc(user::student, ID, "", cur->Class);
}
void addStudentToCourse(course*cur, course::student tmp) {
	if (cur->stuhead == NULL) cur->stuhead = new course::student, *cur->stuhead = tmp;
	else {
		course::student*curstu = cur->stuhead;
		while (curstu->next != NULL) curstu = curstu->next;
		curstu->next = new course::student;
		*curstu->next = tmp;
	}
}
//import course
bool addNewCourse() {
	start();
	notifyForm("Add a new course");
	course tmp;
	inputForm("Course code", tmp.courseCode, courseCodeLimit, 16);
	inputForm("Academic year", tmp.year, yearLimit, 16);
	if (isExistCourse(tmp.courseCode, tmp.year)) {
		notifyForm("This course is existed in database!");
		char isContinue;
		optionForm("Do you want to continue import course(0 is no, 1 is yes)", isContinue, 60);
		if (!isContinue) return true;
		return false;
	}
	inputForm("Semester", tmp.semester, semesterLimit, 16);
	inputForm("Course name", tmp.courseName, courseNameLimit, 16);
	char fullname[fullnameLimit];
	inputForm("Lecturer name", fullname, fullnameLimit, 16);
	makesortname(fullname, tmp.lecturerUsername);
	inputForm("This course start at (yyyy-mm-dd)", tmp.startAt, dayLimit, 35);
	inputForm("This course finish at (yyyy-mm-dd)", tmp.endAt, dayLimit, 35);
	notifyForm("Import Course Successful!");
	addCourse(tmp, fullname);
	return true;
}
bool importCourseCsv() {
	start();
	notifyForm("Import course from csv");
	char path[200];
	inputForm("Direct path(Each line is courseCode, year, semester, courseName, lecturerUsername, startAt, endAt)", path, 200, 60);
	ifstream finIm(path);
	if (finIm.is_open()) {
		for (course tmp; finIm.getline(tmp.courseCode, courseCodeLimit, ',') && strcmp(tmp.courseCode, "");) {
			finIm.getline(tmp.year, yearLimit, ',');
			if (isExistCourse(tmp.courseCode, tmp.year)) {
				finIm.ignore(INT_MAX, '\n');
				char notify[100]{ "Course " };
				strcat(notify, tmp.courseCode); strcat(notify, "-"); strcat(notify, tmp.year);
				strcat(notify, " has been existed!");
				notifyForm(notify);
			}
			else {
				finIm.getline(tmp.semester, semesterLimit, ',');
				finIm.getline(tmp.courseName, courseNameLimit, ',');
				char fullname[fullnameLimit];
				finIm.getline(fullname, fullnameLimit, ',');
				makesortname(fullname, tmp.lecturerUsername);
				finIm.getline(tmp.startAt, dayLimit, ',');
				finIm.getline(tmp.endAt, dayLimit);
				addCourse(tmp, fullname);
				char notify[100]{};
				strcat(notify, tmp.courseCode); strcat(notify, "-"); strcat(notify, tmp.year);
				strcat(notify, " has been added!");
				notifyForm(notify);
			}
		}
		finIm.close();
		return true;
	}
	else notifyForm("Can't open this file!");
	finIm.close();
	char isContinue;
	optionForm("Do you want to continue import course(0 is no, 1 is yes)", isContinue, 60);
	if (!isContinue) return true;
	return false;
}
void viewCourse() {
	start();
	notifyForm("View list of course");
	if (Course == NULL) {
		notifyForm("No course has been imported yet!");
	}
	else {
		ostringstream str;
		str << setw(courseCodeLimit) << "Coursecode" << " | ";
		str << setw(yearLimit) << "Year" << " | ";
		str << setw(8) << "Semester" << " | ";
		str << setw(35) << "Course name" << " | ";
		str << setw(16) << "LecturerUsername" << " | ";
		str << setw(dayLimit) << "Start at" << " | ";
		str << setw(dayLimit) << "End at";
		char notify[200]{};
		strcpy(notify, str.str().c_str());
		showForm(notify);
		for (course*cur = Course; cur != NULL; cur = cur->next) {
			ostringstream str;
			str << setw(courseCodeLimit) << cur->courseCode << " | ";
			str << setw(yearLimit) << cur->year << " | ";
			str << setw(8) << cur->semester << " | ";
			str << setw(35) << cur->courseName << " | ";
			str << setw(16) << cur->lecturerUsername << " | ";
			str << setw(dayLimit) << cur->startAt << " | ";
			str << setw(dayLimit) << cur->endAt;
			strcpy(notify, str.str().c_str());
			showForm(notify);
		}
	}
}
bool importCourse() {
	start();
	notifyForm("Import Course");
	menuForm(1, "Add a new course");
	menuForm(2, "Import course from csv");
	menuForm(3, "View list of course");
	menuForm(4, "Back");
	char inputStyle;
	optionForm("Your choice", inputStyle, 20);
	switch (inputStyle) {
	case 1:while (!addNewCourse()); break;
	case 2:while (!importCourseCsv()); break;
	case 3:viewCourse(); break;
	case 4:return true;
	default:return false;
	}
	done();
	return false;
}
//import student to a class and view
bool importListClass() {
	start();
	notifyForm("Import list of students in a class");
	char Class[ClassLimit];
	inputForm("Class which you want to import students", Class, ClassLimit, 55);
	char path[200];
	inputForm("Direct path (Each line is student ID)", path, 200, 40);
	ifstream fin(path);
	if (fin.is_open()) {
		classes*curcla;
		if (!isExistClass(Class, curcla)) {
			if (Classes == NULL) curcla = Classes = new classes;
			else {
				classes*cur = Classes;
				while (cur->next != NULL) cur = cur->next;
				curcla = cur->next = new classes;
			}
			strcpy(curcla->Class, Class);
		}
		for (char ID[usernameLimit]; fin.getline(ID, usernameLimit);) {
			if (isExistStudentInClass(curcla, ID)) {
				char notify[100]{ "Student " };
				strcat(notify, ID); strcat(notify, " has been existed in this class!");
				notifyForm(notify);
			}
			else if (isExistStudent(ID)) {
				char notify[100]{ "Student " };
				strcat(notify, ID); strcat(notify, " has been existed in other class!");
				notifyForm(notify);
			}
			else {
				addStudentToClass(curcla, ID);
				char notify[100]{ "Imported " };
				strcat(notify, ID); strcat(notify, " to "); strcat(notify, Class);
				strcat(notify, " successful!");
				notifyForm(notify);
			}
		}
		fin.close();
		return true;
	}
	else notifyForm("This file cannot open!");
	fin.close();
	char isContinue;
	optionForm("Do you want to continue import students(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool viewStudentsCourse() {
	start();
	notifyForm("View students in a course");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to view students", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			if (cur->stuhead == NULL) notifyForm("This course doesn't have any students!");
			else for (course::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next) notifyForm(curstu->ID);
			return true;
		}
	notifyForm("Cannot found your course!");
	char isContinue;
	optionForm("Do you want to continue view students(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool viewStudentsClass() {
	start();
	notifyForm("View students in a class");
	char Class[ClassLimit];
	inputForm("Class which you want to view students", Class, courseCodeLimit, 55);
	classes*cur;
	if (isExistClass(Class, cur)) {
		if (cur->stuhead == NULL) notifyForm("This class doesn't have any students!");
		else for (classes::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next) notifyForm(curstu->ID);
		return true;
	}
	notifyForm("Cannot found your class!");
	char isContinue;
	optionForm("Do you want to continue view students(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
//import student to a course
bool assignWholeClass(course*admin) {
	start();
	char notify[100]{ "Assign students to " };
	strcat(notify, admin->courseCode); strcat(notify, "-"); strcat(notify, admin->year);
	notifyForm(notify);
	notifyForm("Choose an existing class");
	char Class[ClassLimit];
	inputForm("Class which you want to assign students", Class, courseCodeLimit, 55);
	classes*cur;
	if (isExistClass(Class, cur)) {
		if (cur->stuhead == NULL) notifyForm("This class doesn't have any students!");
		else for (classes::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next) {
			if (isExistStudentInCourse(admin, curstu->ID)) {
				char notify[100]{ "Student " };
				strcat(notify, curstu->ID);
				strcat(notify, " has been existed in this course!");
				notifyForm(notify);
			}
			else {
				course::student tmp;
				strcpy(tmp.ID, curstu->ID);
				addStudentToCourse(admin, tmp);
				char notify[100]{ "Assigned " };
				strcat(notify, curstu->ID); strcat(notify, " to ");
				strcat(notify, admin->courseCode); strcat(notify, "-"); strcat(notify, admin->year);
				notifyForm(notify);
			}
		}
		return true;
	}
	notifyForm("Cannot found your class!");
	char isContinue;
	optionForm("Do you want to continue view students(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool addnewImportCsv(course*admin) {
	start();
	char notify[100]{ "Assign students to " };
	strcat(notify, admin->courseCode); strcat(notify, "-"); strcat(notify, admin->year);
	notifyForm(notify);
	notifyForm("Add a new class name and import student from csv");
	char Class[ClassLimit];
	inputForm("Class which you want to import students", Class, ClassLimit, 55);
	classes*curcla;
	if (!isExistClass(Class, curcla)) {
		char path[200];
		inputForm("Direct path (Each line is student ID)", path, 200, 40);
		ifstream fin(path);
		if (fin.is_open()) {
			if (Classes == NULL) curcla = Classes = new classes;
			else {
				classes*cur = Classes;
				while (cur->next != NULL) cur = cur->next;
				curcla = cur->next = new classes;
			}
			strcpy(curcla->Class, Class);
			char ID[usernameLimit];
			while (fin.getline(ID, usernameLimit)) {
				if (isExistStudent(ID)) {
					char notify[100]{ "Student " };
					strcat(notify, ID); strcat(notify, " has been existed in other class!");
					notifyForm(notify);
				}
				else {
					addStudentToClass(curcla, ID);
					course::student tmp;
					strcpy(tmp.ID, ID);
					addStudentToCourse(admin, tmp);
					char notify[100]{ "Imported " };
					strcat(notify, ID); strcat(notify, " to "); strcat(notify, Class);
					strcat(notify, " & "); strcat(notify, admin->courseCode);
					strcat(notify, "-"); strcat(notify, admin->year);
					strcat(notify, " successful!");
					notifyForm(notify);
				}
			}
			fin.close();
			return true;
		}
		else notifyForm("This file cannot open!");
		fin.close();
	}
	else notifyForm("This class has been existed!");
	char isContinue;
	optionForm("Do you want to continue import students(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool manuallyAddExist(course*admin) {
	start();
	char notify[100]{ "Assign students to " };
	strcat(notify, admin->courseCode); strcat(notify, "-"); strcat(notify, admin->year);
	notifyForm(notify);
	notifyForm("Manually search and add an existing student");
	char ID[usernameLimit];
	inputForm("Student ID", ID, usernameLimit, 55);
	for (classes*curcla = Classes; curcla != NULL; curcla = curcla->next)
		if (isExistStudentInClass(curcla, ID)) {
			if (isExistStudentInCourse(admin, ID)) {
				char notify[100]{ "Student " };
				strcat(notify, ID); strcat(notify, " has been existed in this course!");
				notifyForm(notify);
			}
			else {
				course::student tmp;
				strcpy(tmp.ID, ID);
				addStudentToCourse(admin, tmp);
				char notify[100]{ "Imported " };
				strcat(notify, ID); strcat(notify, "-"); strcat(notify, curcla->Class);
				strcat(notify, " to ");
				strcat(notify, admin->courseCode); strcat(notify, "-"); strcat(notify, admin->year);
				strcat(notify, " successful!");
				notifyForm(notify);
			}
			return true;
		}
	notifyForm("Cannot found this student from any classes!");
	char isContinue;
	optionForm("Do you want to continue import students(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool assignStudentsMenu(course*admin) {
	start();
	char notify[100]{ "Assign students to " };
	strcat(notify, admin->courseCode); strcat(notify, "-"); strcat(notify, admin->year);
	notifyForm(notify);
	menuForm(1, "Choose an existing class");
	menuForm(2, "Add a new class name and import student from csv");
	menuForm(3, "Manually search and add an existing student");
	menuForm(4, "Back");
	char inputStyle;
	optionForm("Your choice", inputStyle, 20);
	switch (inputStyle) {
	case 1:while (!assignWholeClass(admin)); break;
	case 2:while (!addnewImportCsv(admin)); break;
	case 3:while (!manuallyAddExist(admin)); break;
	case 4:return true;
	default:return false;
	}
	done();
	return false;
}
bool assignStudentsToCourse() {
	start();
	notifyForm("Assign students to a course");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to assign students", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			while (!assignStudentsMenu(cur));
			return true;
		}
	notifyForm("Cannot found your course!");
	char isContinue;
	optionForm("Do you want to continue assign students to a course(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool importStudents() {
	start();
	notifyForm("Import Students");
	menuForm(1, "Import list of students in a class");
	menuForm(2, "Assign students to a course");
	menuForm(3, "View students in a course");
	menuForm(4, "View students in a class");
	menuForm(5, "Back");
	char inputStyle;
	optionForm("Your choice", inputStyle, 20);
	switch (inputStyle) {
	case 1:while (!importListClass()); break;
	case 2:while (!assignStudentsToCourse()); break;
	case 3:while (!viewStudentsCourse()); break;
	case 4:while (!viewStudentsClass()); break;
	case 5:return true;
	default:return false;
	}
	done();
	return false;
}
//import schedules - input "" and "" not overwrite old schedules
bool importSchedules() {
	start();
	notifyForm("Import Schedules");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to import schedules", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			for (int i = 0; i < 6; i++) {
				switch (i) {
				case 0:notifyForm("Monday"); break;
				case 1:notifyForm("Tuesday"); break;
				case 2:notifyForm("Wednesday"); break;
				case 3:notifyForm("Thursday"); break;
				case 4:notifyForm("Friday"); break;
				case 5:notifyForm("Saturday"); break;
				}
				char tmp[timeLimit];
				inputForm("Starting time (HH:MM)", tmp, timeLimit, 30);
				if (strcmp(tmp, "")) strcpy(cur->day[i].from, tmp);
				inputForm("Ending time   (HH:MM)", tmp, timeLimit, 30);
				if (strcmp(tmp, "")) strcpy(cur->day[i].to, tmp);
			}
			notifyForm("Import Schedules Successful!");
			return true;
		}
	notifyForm("Cannot found your course!");
	char isContinue;
	optionForm("Do you want to continue import schedules(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
//export score
bool exportScoreCourse() {
	start();
	notifyForm("Export score of a course");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to show score", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			if (cur->stuhead == NULL) notifyForm("This course hasn't been imported students yet!");
			else {
				char n;
				optionForm("Which score do you want to export?(0 is midterm score, 1 is laboratory score, 2 is final score, 3 is all score)", n, 60);
				if (n != 0 && n != 1 && n != 2 && n != 3) {
					notifyForm("This option is not available! - Press Enter to come back!");
					return true;
				}
				char exportForm;
				optionForm("Export to screen(0) or file(1)", exportForm, 55);
				if (exportForm == 0) {
					switch (n) {
					case 0:showForm("Student ID | Midterm score"); break;
					case 1:showForm("Student ID | Laboratory score"); break;
					case 2:showForm("Student ID | Final score"); break;
					case 3:showForm("Student ID | Midterm score | Laboratory score | Final score"); break;
					}
					for (course::student*tmp = cur->stuhead; tmp != NULL; tmp = tmp->next) {
						ostringstream str;
						str << setw(10) << tmp->ID << " | ";
						switch (n) {
						case 0:str << setw(13) << tmp->mid; break;
						case 1:str << setw(16) << tmp->lab; break;
						case 2:str << setw(11) << tmp->final; break;
						case 3:str << setw(13) << tmp->mid << " | ";
							str << setw(16) << tmp->lab << " | ";
							str << setw(11) << tmp->final;
							break;
						}
						char notify[100]{};
						strcpy(notify, str.str().c_str());
						showForm(notify);
					}
				}
				else if (exportForm == 1) {
					char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, pathScore);
					_mkdir(file);
					strcat(file, "/"); strcat(file, courseCode); strcat(file, "-"); strcat(file, year);
					switch (n) {
					case 0:strcat(file, "(mid)"); break;
					case 1:strcat(file, "(lab)"); break;
					case 2:strcat(file, "(final)"); break;
					case 3:strcat(file, "(all)"); break;
					}
					strcat(file, ".csv");
					ofstream fout(file);
					switch (n) {
					case 0:fout << "Student ID,Mid score\n"; break;
					case 1:fout << "Student ID,Lab score\n"; break;
					case 2:fout << "Student ID,Final score\n"; break;
					case 3:fout << "Student ID,Mid score,Lab score,Final score\n"; break;
					}
					for (course::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next)
						switch (n) {
						case 0:fout << curstu->ID << ',' << curstu->mid << endl; break;
						case 1:fout << curstu->ID << ',' << curstu->lab << endl; break;
						case 2:fout << curstu->ID << ',' << curstu->final << endl; break;
						case 3:fout << curstu->ID << ',' << curstu->mid << ',' << curstu->lab << ',' << curstu->final << endl; break;
						}
					fout.close();
					char notify[100]{ "File has been saved in " };
					strcat(notify, file);
					notifyForm(notify);
				}
				else notifyForm("This option is not available! - Press Enter to come back!");
			}
			return true;
		}
	notifyForm("This course is not existed in database!");
	char isContinue;
	optionForm("Do you want to try export score again (0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool exportScoreStudent() {
	start();
	notifyForm("Export score of a student");
	char ID[usernameLimit];
	inputForm("Student ID which you want to export score", ID, usernameLimit, 55);
	bool anyCourse = false;
	char exportForm;
	for (course*cur = Course; cur != NULL; cur = cur->next) {
		course::student*curstu;
		if (isExistStudentInCourse(cur, ID, curstu)) {
			if (!anyCourse) optionForm("Export to screen(0) or file(1)", exportForm, 55);
			if (exportForm == 0) {
				if (!anyCourse) showForm("Course code | Course year | Midterm score | Laboratory score | Final score");
				ostringstream str;
				str << setw(11) << cur->courseCode << " | ";
				str << setw(11) << cur->year << " | ";
				str << setw(13) << curstu->mid << " | ";
				str << setw(16) << curstu->lab << " | ";
				str << setw(11) << curstu->final;
				char notify[100]{};
				strcpy(notify, str.str().c_str());
				showForm(notify);
			}
			else if (exportForm == 1) {
				char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, pathScore);
				_mkdir(file);
				strcat(file, "/"); strcat(file, ID); strcat(file, ".csv");
				ofstream fout;
				if (!anyCourse) fout.open(file);
				else fout.open(file, ios_base::app);
				if (!anyCourse) fout << "Course code,Course year,Mid score,Lab score,Final score\n";
				fout << cur->courseCode << ',' << cur->year << ',' << curstu->mid << ',' << curstu->lab << ',' << curstu->final << endl;
				fout.close();
			}
			else {
				notifyForm("This option is not available! - Press Enter to come back!");
				return true;
			}
			anyCourse = true;
		}
	}
	if (anyCourse) {
		if (exportForm == 1) {
			char notify[100]{ "File has been saved in data/score/" };
			strcat(notify, ID); strcat(notify, ".csv");
			notifyForm(notify);
		}
		return true;
	}
	notifyForm("No course has this student!");
	char isContinue;
	optionForm("Do you want to try export score again (0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool exportScore() {
	start();
	notifyForm("Export score");
	menuForm(1, "Score of a course");
	menuForm(2, "Score of a student");
	menuForm(3, "Back");
	char inputStyle;
	optionForm("Your choice", inputStyle, 20);
	switch (inputStyle) {
	case 1:while (!exportScoreCourse()); break;
	case 2:while (!exportScoreStudent()); break;
	case 3:return true;
	default:return false;
	}
	done();
	return false;
}
//export presence
bool exportPresence() {
	start();
	notifyForm("Export lists of student who was present or absent in a course");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to show score", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			if (cur->stuhead == NULL) notifyForm("This course hasn't been imported students yet!");
			else {
				char exportForm;
				optionForm("Export to screen(0) or file(1)", exportForm, 55);
				if (exportForm == 0) {
					showForm("Student ID | Time check |  Last check");
					for (course::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next) {
						ostringstream str;
						str << setw(10) << curstu->ID << " | ";
						str << setw(10) << curstu->timecheck << " | ";
						if (curstu->timecheck != 0) {
							tm*past=localtime(&curstu->checktime[curstu->timecheck - 1]);
							char thatday[dayLimit];
							strftime(thatday, dayLimit, "%Y-%m-%d", past);
							str << setw(dayLimit) << thatday;
						}
						else str << setw(dayLimit) << ' ';
						char notify[100]{};
						strcpy(notify, str.str().c_str());
						showForm(notify);
					}
				}
				else if (exportForm == 1) {
					char file[100]{}; strcat(file, pathMain); strcat(file, "/"); strcat(file, pathPresence);
					_mkdir(file);
					strcat(file, "/"); strcat(file, courseCode); strcat(file, "-"); strcat(file, year);
					strcat(file, ".csv");
					ofstream fout(file);
					fout << "Student ID,Time check,Last check\n";
					for (course::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next) {
						fout << curstu->ID << ',' << curstu->timecheck << ',';
						if (curstu->timecheck != 0) {
							tm*past=localtime(&curstu->checktime[curstu->timecheck - 1]);
							char thatday[dayLimit];
							strftime(thatday, dayLimit, "%Y-%m-%d", past);
							fout << thatday;
						}
						fout << endl;
					}
					fout.close();
					char notify[100]{ "File has been saved in " };
					strcat(notify, file);
					notifyForm(notify);
				}
				else notifyForm("This option is not available! - Press Enter to come back!");
			}
			return true;
		}
	notifyForm("This course is not existed in database!");
	char isContinue;
	optionForm("Do you want to try export score again (0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
//import score
bool importScoreExam(user admin) {
	start();
	notifyForm("Import score of an exam in a course");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to import score", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			if (compareWithOutCase(admin.username, cur->lecturerUsername)) {
				char n;
				optionForm("Which score do you want to import?(0 is midterm score, 1 is laboratory score, 2 is final score, 3 is all score)", n, 60);
				switch (n) {
				case 0:notifyForm("MIDTERM SCORE"); break;
				case 1:notifyForm("LABORATORY SCORE"); break;
				case 2:notifyForm("FINAL SCORE"); break;
				case 3:notifyForm("ALL SCORE"); break;
				default:notifyForm("This option is not available! - Press Enter to come back!");
					return true;
				}
				char m;
				optionForm("Import manually (0) or from file (1)", m, 60);
				if (m == 0)
					for (course::student*curstu = cur->stuhead; curstu != NULL; curstu = curstu->next)
						switch (n) {
						case 0:inputForm(curstu->ID, curstu->mid, 20); break;
						case 1:inputForm(curstu->ID, curstu->lab, 20); break;
						case 2:inputForm(curstu->ID, curstu->final, 20); break;
						case 3:notifyForm(curstu->ID);
							inputForm("Midterm score", curstu->mid, 20);
							inputForm("Laboratory score", curstu->lab, 20);
							inputForm("Final score", curstu->final, 20);
							break;
						}
				else if (m == 1) {
					char path[200];
					switch (n) {
					case 0:inputForm("Direct path (Each line is student ID, midterm score)", path, 200, 60); break;
					case 1:inputForm("Direct path (Each line is student ID, laboratory score)", path, 200, 60); break;
					case 2:inputForm("Direct path (Each line is student ID, final score)", path, 200, 60); break;
					case 3:inputForm("Direct path (Each line is student ID, mid, lab, final)", path, 200, 60); break;
					}
					ifstream finIm(path);
					if (finIm.is_open()) {
						for (char ID[usernameLimit]; finIm.getline(ID, usernameLimit, ',');) {
							course::student*tmp;
							if (isExistStudentInCourse(cur, ID, tmp)) {
								switch (n) {
								case 0:finIm >> tmp->mid; finIm.get(); break;
								case 1:finIm >> tmp->lab; finIm.get(); break;
								case 2:finIm >> tmp->final; finIm.get(); break;
								case 3:finIm >> tmp->mid; finIm.get();
									finIm >> tmp->lab; finIm.get();
									finIm >> tmp->final; finIm.get();
									break;
								}
								char notify[100]{ "Student " };
								strcat(notify, ID); strcat(notify, " has been imported score!");
								notifyForm(notify);
							}
							else {
								finIm.ignore(INT_MAX, '\n');
								char notify[100]{ "Student " };
								strcat(notify, ID); strcat(notify, " is not exist in this course!");
								notifyForm(notify);
							}
						}
						notifyForm("Import Score Successful!");
					}
					else notifyForm("This file cannot open!");
					finIm.close();
				}
				else notifyForm("This option is not available! - Press Enter to come back!");
			}
			else notifyForm("You are not lecturer of this course!");
			return true;
		}
	notifyForm("This course is not existed in database!");
	char isContinue;
	optionForm("Do you want to continue import scores(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool showScoreLecturer(user admin) {
	start();
	notifyForm("Show score");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to show score", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			if (compareWithOutCase(admin.username, cur->lecturerUsername))
				if (cur->stuhead == NULL) notifyForm("This course hasn't been imported students yet!");
				else {
					showForm("Student ID | Midterm score | Laboratory score | Final score");
					for (course::student*tmp = cur->stuhead; tmp != NULL; tmp = tmp->next) {
						ostringstream str;
						str << setw(10) << tmp->ID << " | ";
						str << setw(13) << tmp->mid << " | ";
						str << setw(16) << tmp->lab << " | ";
						str << setw(11) << tmp->final;
						char notify[100]{};
						strcpy(notify, str.str().c_str());
						showForm(notify);
					}
				}
			else notifyForm("You are not lecturer of this course!");
			return true;
		}
	notifyForm("This course is not existed in database!");
	char isContinue;
	optionForm("Do you want to continue check in(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool editScore(user admin) {
	start();
	notifyForm("Edit Score");
	char courseCode[courseCodeLimit];
	inputForm("Course code that has student you want to edit score", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			if (compareWithOutCase(admin.username, cur->lecturerUsername)) {
				char ID[usernameLimit];
				inputForm("Student ID who you want to edit score", ID, usernameLimit, 55);
				course::student*curstu;
				if (isExistStudentInCourse(cur, ID, curstu)) {
					showForm("Current Midterm score", curstu->mid, 30);
					showForm("Current Laboratory score", curstu->lab, 30);
					showForm("Current Final score", curstu->final, 30);
					char n;
					optionForm("Which score do you want to edit?(0 is midterm score, 1 is laboratory score, 2 is final score, 3 is all score)", n, 60);
					switch (n) {
					case 0:inputForm("New Midterm score", curstu->mid, 30); break;
					case 1:inputForm("New Laboratory score", curstu->lab, 30); break;
					case 2:inputForm("New Final score", curstu->final, 30); break;
					case 3:
						inputForm("New Midterm score", curstu->mid, 30);
						inputForm("New Laboratory score", curstu->lab, 30);
						inputForm("New Final score", curstu->final, 30);
						break;
					default:notifyForm("This option is not available! - Press Enter to come back!");
					}
				}
				else {
					char notify[100]{ "Student " };
					strcat(notify, ID); strcat(notify, " haven't enrolled to this course yet!");
					notifyForm(notify);
				}
				return true;
			}
			else notifyForm("You are not lecturer of this course!");
			return true;
		}
	notifyForm("This course is not existed in database!");
	char isContinue;
	optionForm("Do you want to continue check in(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
bool importScore(user admin) {
	start();
	notifyForm("Import Scores");
	menuForm(1, "Import score of an exam in a course");
	menuForm(2, "Show scores");
	menuForm(3, "Edit a score");
	menuForm(4, "Back");
	char inputStyle;
	optionForm("Your choice", inputStyle, 20);
	switch (inputStyle) {
	case 1:while (!importScoreExam(admin)); break;
	case 2:while (!showScoreLecturer(admin)); break;
	case 3:while (!editScore(admin)); break;
	case 4:return true;
	default:return false;
	}
	done();
	return false;
}
//check in
bool checkInNow(user admin) {
	start();
	notifyForm("Check in right now");
	char courseCode[courseCodeLimit];
	inputForm("Course code which you want to check in", courseCode, courseCodeLimit, 55);
	char year[yearLimit];
	inputForm("Year of your course", year, yearLimit, 55);
	for (course*cur = Course; cur != NULL; cur = cur->next)
		if (compareWithOutCase(cur->courseCode, courseCode) && compareWithOutCase(cur->year, year)) {
			course::student*tmp;
			if (isExistStudentInCourse(cur, admin.username, tmp)) {
				time_t timer = time(NULL);
				tm*now=localtime(&timer);
				int thathu = now->tm_wday - 1;
				char thisday[dayLimit], thistime[timeLimit];
				strftime(thisday, dayLimit, "%Y-%m-%d", now);
				strftime(thistime, timeLimit, "%H:%M", now);
				if (strcmp(thisday, cur->startAt) < 0) notifyForm("Your course hasn't start yet!");
				else if (strcmp(thisday, cur->endAt) > 0)
					notifyForm("Your course has been finished!");
				else if (!strcmp(cur->day[thathu].from, "") || !strcmp(cur->day[thathu].to, ""))
					notifyForm("Today don't have this course!");
				else if (strcmp(thistime, cur->day[thathu].from) < 0 || strcmp(thistime, cur->day[thathu].to) > 0)
					cout << "Check in wrong time! Please go to school and check in from " << cur->day[thathu].from << " to " << cur->day[thathu].to << endl;
				else {
					char lastday[dayLimit];
					if (tmp->timecheck > 0) {
						now=localtime(&tmp->checktime[tmp->timecheck - 1]);
						strftime(lastday, dayLimit, "%Y-%m-%d", now);
						if (!strcmp(thisday, lastday)) {
							notifyForm("You has checked in today!");
							return true;
						}
					}
					tmp->checktime[tmp->timecheck++] = timer;
					notifyForm("Check-In Successful!");
				}
			}
			else notifyForm("You haven't enrolled in this course yet!");
			return true;
		}
	notifyForm("This course is not existed in database!");
	notifyForm("Check-In fail!");
	char isContinue;
	optionForm("Do you want to continue check in(0 is no, 1 is yes)", isContinue, 60);
	if (isContinue) return false;
	return true;
}
void viewCheckIn(user admin) {
	start();
	notifyForm("View personal check in result");
	bool anyCourse = false;
	for (course*cur = Course; cur != NULL; cur = cur->next) {
		course::student*curstu;
		if (isExistStudentInCourse(cur, admin.username, curstu)) {
			if (!anyCourse) showForm("Course code | Course year | Time check |  Last check");
			ostringstream str;
			str << setw(11) << cur->courseCode << " | ";
			str << setw(11) << cur->year << " | ";
			str << setw(10) << curstu->timecheck << " | ";
			if (curstu->timecheck != 0) {
				tm*past=localtime(&curstu->checktime[curstu->timecheck - 1]);
				char thatday[dayLimit];
				strftime(thatday, dayLimit, "%Y-%m-%d", past);
				str << setw(dayLimit) << thatday;
			}
			else str << setw(dayLimit) << ' ';
			char notify[100]{};
			strcpy(notify, str.str().c_str());
			showForm(notify);
			anyCourse = true;
		}
	}
	if (!anyCourse) notifyForm("You haven't enrolled any courses yet!");
}
bool checkIn(user admin) {
	start();
	notifyForm("Check-In");
	menuForm(1, "Check in right now");
	menuForm(2, "View my check in result");
	menuForm(3, "Back");
	char inputStyle;
	optionForm("Your choice", inputStyle, 20);
	switch (inputStyle) {
	case 1:while (!checkInNow(admin)); break;
	case 2:viewCheckIn(admin); break;
	case 3:return true;
	default:return false;
	}
	done();
	return false;
}
//show score student
void showScoreStudent(user admin) {
	start();
	notifyForm("View personal exam result");
	bool anyCourse = false;
	for (course*cur = Course; cur != NULL; cur = cur->next) {
		course::student*curstu;
		if (isExistStudentInCourse(cur, admin.username, curstu)) {
			if (!anyCourse) showForm("Course code | Course year | Midterm score | Laboratory score | Final score");
			ostringstream str;
			str << setw(11) << cur->courseCode << " | ";
			str << setw(11) << cur->year << " | ";
			str << setw(13) << curstu->mid << " | ";
			str << setw(16) << curstu->lab << " | ";
			str << setw(11) << curstu->final;
			char notify[100]{};
			strcpy(notify, str.str().c_str());
			showForm(notify);
			anyCourse = true;
		}
	}
	if (!anyCourse) notifyForm("You haven't enrolled any courses yet!");
}
//show account infomation - input "" not overwrite old information
bool changeAccInfo(user*&admin) {
	start();
	notifyForm("Change account information");
	user tmp;
	inputForm("Fullname", tmp.fullname, fullnameLimit, 40);
	if (strcmp(tmp.fullname, "")) {
		if (admin->type == admin->academicStaff) {
			makesortname(tmp.fullname, tmp.username);
			if (strcmp(tmp.username, admin->username) && isExistUser(tmp.username)) {
				char username[usernameLimit], n[]{ "0" };
				do {
					++n[0];
					strcpy(username, tmp.username);
					strcat(username, n);
				} while (isExistUser(username));
				strcpy(tmp.username, username);
			}
			showForm("Your username will be created by name", tmp.username, 40);
		}
		strcpy(admin->fullname, tmp.fullname);
		if (admin->type == admin->academicStaff) strcpy(admin->username, tmp.username);
	}
	inputForm("Password", tmp.password, passwordLimit, 40);
	if (strcmp(tmp.password, "")) strcpy(admin->password, tmp.password);
	inputForm("Email", tmp.email, emailLimit, 40);
	if (strcmp(tmp.email, "")) strcpy(admin->email, tmp.email);
	inputForm("Mobile", tmp.mobile, mobileLimit, 40);
	if (strcmp(tmp.mobile, "")) strcpy(admin->mobile, tmp.mobile);
	notifyForm("Change information successful!");
	return true;
}
bool showacc(user*&admin) {
	start();
	notifyForm("Account Information");
	switch (admin->type) {
	case 0:notifyForm("STUDENT"); break;
	case 1:notifyForm("ACADEMIC STAFF"); break;
	case 2:notifyForm("LECTURER"); break;
	}
	showForm("Fullname", admin->fullname, 12);
	showForm("Username", admin->username, 12);
	showForm("Password", admin->password, 12);
	showForm("Email", admin->email, 12);
	showForm("Mobile", admin->mobile, 12);
	if (admin->type == 0) showForm("Class", admin->Class, 12);
	menuForm(1, "Change your account infomation");
	menuForm(2, "Back");
	char n;
	optionForm("Your choice", n, 20);
	switch (n) {
	case 1:while (!changeAccInfo(admin)); break;
	case 2:return true;
	default:return false;
	}
	done();
	return false;
}
//main menu
bool AcademicStaff(user*&admin) {
	start(*admin);
	notifyForm("Welcome Academic Staff");
	menuForm(1, "Inport courses");
	menuForm(2, "Import student list");
	menuForm(3, "Import schedules");
	menuForm(4, "Export scores of student or course");
	menuForm(5, "Export lists of student who was present or absent in a course");
	menuForm(6, "Show your account information");
	menuForm(7, "Sign out");
	char n;
	optionForm("Your choice", n, 20);
	switch (n) {
	case 1:while (!importCourse()); break;
	case 2:while (!importStudents()); break;
	case 3:while (!importSchedules()); break;
	case 4:while (!exportScore()); break;
	case 5:while (!exportPresence()); break;
	case 6:while (!showacc(admin)); break;
	case 7:return true;
	default:return false;
	}
	done();
	return false;
}
bool menustudent(user*&admin) {
	start(*admin);
	notifyForm("Welcome Student");
	menuForm(1, "Check-in class");
	menuForm(2, "View my score");
	menuForm(3, "Show your account information");
	menuForm(4, "Sign out");
	char n;
	optionForm("Your choice", n, 20);
	switch (n) {
	case 1:while (!checkIn(*admin)); break;
	case 2:showScoreStudent(*admin); break;
	case 3:while (!showacc(admin)); break;
	case 4:return true;
	default:return false;
	}
	done();
	return false;
}
bool lecturer(user*&admin) {
	start(*admin);
	notifyForm("Welcome Lecturer");
	menuForm(1, "Import scores");
	menuForm(2, "Show your account information");
	menuForm(3, "Sign out");
	char n;
	optionForm("Your choice", n, 20);
	switch (n) {
	case 1:while (!importScore(*admin)); break;
	case 2:while (!showacc(admin)); break;
	case 3:return true;
	default:return false;
	}
	done();
	return false;
}
bool SignIn() {
	start();
	notifyForm("LOGIN");
	user tmp;
	inputForm("Username", tmp.username, usernameLimit, 22);
	inputForm("Password", tmp.password, passwordLimit, 22);
	for (user*cur = User; cur != NULL; cur = cur->next)
		if (!strcmp(cur->username, tmp.username) && !strcmp(cur->password, tmp.password)) {
			notifyForm("Login Successful!");
			notifyForm("Press Enter to go to Main Menu!");
			cin.ignore(INT_MAX, '\n');
			switch (cur->type) {
			case 0:while (!menustudent(cur)); break;
			case 1:while (!AcademicStaff(cur)); break;
			case 2:while (!lecturer(cur)); break;
			}
			return true;
		}
	notifyForm("Login Fail!");
	char isContinue;
	optionForm("Do you want to continue sign in (0 is no, 1 is yes)", isContinue, 60);
	if (!isContinue) return true;
	return false;
}
bool SignUp() {
	start();
	notifyForm("SIGN UP - ACADEMIC STAFF");
	user tmp;
	tmp.type = tmp.academicStaff;
	inputForm("Fullname", tmp.fullname, fullnameLimit, 40);
	if (strcmp(tmp.fullname, "")) {
		makesortname(tmp.fullname, tmp.username);
		if (isExistUser(tmp.username)) {
			char username[usernameLimit], n[]{ "0" };
			do {
				++n[0];
				strcpy(username, tmp.username);
				strcat(username, n);
			} while (isExistUser(username));
			strcpy(tmp.username, username);
		}
		showForm("Your username will be created by name", tmp.username, 40);
		inputForm("Password", tmp.password, passwordLimit, 40);
		inputForm("Email", tmp.email, emailLimit, 40);
		inputForm("Mobile", tmp.mobile, mobileLimit, 40);
		notifyForm("Sign Up Successful!");
		if (User == NULL) User = new user, *User = tmp;
		else {
			user*cur = User;
			while (cur->next != NULL) cur = cur->next;
			cur->next = new user;
			*cur->next = tmp;
		}
		return true;
	}
	notifyForm("Fullname can't not be empty!");
	char isContinue;
	optionForm("Do you want to continue sign up (0 is no, 1 is yes)", isContinue, 60);
	if (!isContinue) return true;
	return false;
}