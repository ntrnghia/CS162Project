#include"header.h"
int main() {
	char n;
	do {
		system("cls");
		initAndShowUser();
		initAndShowCourse();
		initAndShowClass();
		cout << ' ' << setfill('_') << setw(wholeRange) << ' ' << endl << setfill(' ');
		notifyForm("Welcome to Student Management System");
		menuForm(1, "Sign In");
		menuForm(2, "Sign Up (Academic Staff)");
		menuForm(3, "Exit");
		optionForm("Your choice", n, 20);
		switch (n) {
		case 1:while (!SignIn()); break;
		case 2:while (!SignUp()); break;
		}
		if (n == 1 || n == 2) {
			notifyForm("Press enter to come back log in menu!");
			cin.ignore(INT_MAX, '\n');
		}
		delAndSaveUser();
		delAndSaveCourse();
		delAndSaveClass();
	} while (n != 3);
	start();
	notifyForm("YOU ARE WELCOME - SEE YOU AGAIN!");
	//cin.ignore(INT_MAX, '\n');
}