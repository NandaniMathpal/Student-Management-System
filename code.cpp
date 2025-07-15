#include<iostream>
#include<vector>
using namespace std;

class Student {
    int rollno, age;
    string name;
public:
    Student(int stdRollno, int stdAge, string stdName) {
        rollno = stdRollno;
        age = stdAge;
        name = stdName;
    }
    void setRollno(int stdRollno) { rollno = stdRollno; }
    int getRollno() { return rollno; }

    void setName(string stdName) { name = stdName; }
    string getName() { return name; }

    void setAge(int stdAge) { age = stdAge; }
    int getAge() { return age; }

// function to display student record
    void displayStudent(){
            cout<<"Roll no : "<<rollno<<endl;
            cout<<"Name :"<<name<<endl;
            cout<<"Age :"<<age<<endl;
        }
};

// function to update student record
void updateStudent(vector<Student>& Students){
    string sname;
    bool found = false;
    int choice;

    cout<<"Enter Name to Update Record : ";
    cin.ignore();
    getline(cin,sname);

    for(int i=0;i<Students.size();i++){
        if(Students[i].getName()==sname){
            found = true;

            cout<<"-------Student Found---------"<<endl;
            cout<<"1. Update Rollno\n";
            cout<<"2. Update Name\n";
            cout<<"3. Update Age\n";
            cout<<"Enter your Choice :";
            cin>>choice;

            switch (choice){
            case 1:{
                int rno;
                cout<<"Enter New Rollno :";
                cin>>rno;
                Students[i].setRollno(rno);
                break;
            }
            case 2:{
                string name;
                cout<<"Enter New Name :";
                cin.ignore();
                getline(cin,name);
                Students[i].setName(name);
                break;
            }
            case 3:{
                int age;
                cout<<"Ente New Age :";
                cin>>age;
                Students[i].setAge(age);
                break;
            }
            default:
                cout<<"Invalid Number\n";
            }
            cout<<"Student Record Updated Successfully ..";
        }
    }
}

// function to search students
void searchStudent(vector<Student>& Students){
    int rollno;
    cout<<"Enter Roll no: ";
    cin>>rollno;

    for(int i=0; i<Students.size();i++){
        if(Students[i].getRollno()==rollno){
            cout<<"--------Student Found----------\n";
            Students[i].displayStudent();
            return;
        }
    }
}

// function to display all students record
void displayAllStudent(vector<Student>& Students){
    if(Students.empty()){
        cout<<"No Student Found\n";
        return;
    }
    for(int i=0; i<Students.size();i++){
        Students[i].displayStudent();
        cout<<"\n";
    }
}
// Function to add a new student
void addNewStudent(vector<Student>& Students) {
    int rollno, age;
    string name;
    cout << "Enter Your Rollno : ";
    cin >> rollno;

    for (int i = 0; i < Students.size(); i++) {
        if (Students[i].getRollno() == rollno) {
            cout << "Student Already Exists...." << endl;
            return;
        }
    }

    cin.ignore();  // Important: clear buffer before getline
    cout << "Enter Your Name : ";
    getline(cin, name);
    cout << "Enter your Age : ";
    cin >> age;

    Student newStudent(rollno, age, name);
    Students.push_back(newStudent);

    cout << "Student added successfully...\n";
}

// function to delete students in list
void deleteStudent(vector<Student>& Students){
    string name;
    cout<<"Enter Name to Delete :";
    cin.ignore();
    getline(cin,name);

    for(int i=0; i<Students.size(); i++){
        if(Students[i].getName()==name){
            Students.erase((Students.begin()+i));
            cout<<"Student Remove Successfully\n";
        }
    }
}

int main() {
    vector<Student> Students;
    Students.push_back(Student(1, 20, "Raj"));

    char choice;

    do {
        system("cls");
        int opt;
        cout << "-----------------------------" << endl;
        cout << "  STUDENT MANAGEMENT SYSTEM " << endl;
        cout << "-----------------------------" << endl;

        cout << "1. Add New Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Students" << endl;
        cout << "4. Update Students" << endl;
        cout << "5. Delete Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> opt;

        switch (opt) {
            case 1:
                addNewStudent(Students);
                break;
            case 2:
                displayAllStudent(Students);
                break;
            case 3:
                searchStudent(Students);
                break;
            case 4:
                updateStudent(Students);
                break;
            case 5:
                deleteStudent(Students);
                break;
            case 6:
                exit(1);
            default:
                cout << "Invalid Number..." << endl;
        }

        cout << "\t\tDo You Want to Continue [Y/N] ? : ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}
