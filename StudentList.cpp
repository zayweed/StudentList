//Program that creates a list of students. User is able to add and delete students, print all students in the list, and quit. Commands are "ADD", "DELETE", "PRINT", "QUIT".
//Zayeed Saffat
//11.7.2021

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

//struct of student
struct Student {
  char first[200];
  char last[200];
  char id[200];
  char GPA[200];
};

//function that adds student to student list
void add(vector <Student*> &s) {
  Student* student = new Student();

  cout << "First name: ";
  cin >> student->first;

  cout << "Last name: ";
  cin >> student->last;

  cout << "Student id: ";
  cin >> student->id;

  cout << "GPA: ";
  cin >> student->GPA;

  s.push_back(student);
}

//function that prints all students stored in the studentlist
void print(vector <Student*> &s) {
  vector <Student*>::iterator it;
  
  //iterates through vector and prints each student
  for (it = s.begin(); it < s.end(); it++) {
    cout << (*it)->first << " " << (*it)->last << ", " << (*it)->id << ", " << (*it)->GPA << endl;
  }
}

//function that deletes a student
void del(vector <Student*> &s) {
  
  char idnum[200];
  cout << "ID number of student: ";
  cin >> idnum;

  vector <Student*>::iterator it;

  //iterates through vector and deletes student with matching id number
  for (it = s.begin(); it < s.end(); it++) {
    if (strcmp((*it)->id,idnum) == 0) {
      s.erase(it);
    }
  }

}

int main() {

  vector <Student*> studentlist;
  
  int a = 0;
  
  //inputs commands and calls the respective functions
  while (a == 0) {

    cout << "Enter your command: ";

    char input[20];
    cin >> input;

    if (strcmp(input, "ADD") == 0) {
      add(studentlist);
    }

    else if (strcmp(input, "PRINT") == 0) {
      print(studentlist);
    }

    else if (strcmp(input, "DELETE") == 0) {
      del(studentlist);
    }

    else if (strcmp(input, "QUIT") == 0) {
      a = 1;
    }

    else {
      cout << "Invalid input" << endl;
    }
  }

  return 0;
}
