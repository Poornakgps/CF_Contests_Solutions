#include<iostream>
#include<string.h>

using namespace std;

class Student
{
    public:
        string name;
        int roll_number;
        char grade;

        Student(const string& name, int roll_number, char grade)
            :name(name), roll_number(roll_number), grade(grade) {}

        Student(){
            
        }
        void setDetails(const string& name, int roll_number, char grade){
            this->name = name;
            this->roll_number = roll_number;
            this->grade = grade;
        }
        // The displayDetails method does not modify any class members. Marking it as const ensures immutability
        void displayDetails() const { // 
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << roll_number << endl;
            cout << "Grade: " << grade << endl; 
            cout << endl;
        }

};
// Avoid using namespace std (Optional)
// While it's fine in small programs, using namespace std can lead to name conflicts in larger projects. Instead, qualify standard library elements explicitly:

int main(){
    Student student1;
    Student student2;

    student1.setDetails("Chandu", 2, 'B');
    student2.setDetails("Janu", 1, 'A');
    student1.displayDetails();
    student2.displayDetails();

    return 0;
}