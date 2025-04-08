/*
The user’s input is used to compute the CGPA, which includes information like the number of courses taken and
the grades earned in each one. The program also shows each student’s overall course grade. CGPA Calculator calculates a
student’s Cumulative Grade Point Average (CGPA) from the given exam results. The program can show the individual
grades of each course, calculate total credits and total grade points achieved, determine the GPA for the semester, and
based on all the data, it can generate and present the CGPA of the student.
*/

#include <iostream>
using namespace std;

// Function to calculate SGPA (Semester Grade Point Average)
float SGPA() {
    int num;
    cout << "Enter the number of courses: ";
    cin >> num;

    string subjectName[num];
    char grade[num];
    float credit[num];
    float creditPoint[num];

    cout << "Enter the values as directed:\n";
    for (int i = 0; i < num; i++) {
        cout << "Enter Subject Name, Grade (O/E/A/B/C/D/F), Credit Point: ";
        cin >> subjectName[i] >> grade[i] >> credit[i];
    }

    // Calculate the credit points based on grade
    for (int i = 0; i < num; i++) {
        switch (grade[i]) {
            case 'O': creditPoint[i] = credit[i] * 10; break;
            case 'E': creditPoint[i] = credit[i] * 9;  break;
            case 'A': creditPoint[i] = credit[i] * 8;  break;
            case 'B': creditPoint[i] = credit[i] * 7;  break;
            case 'C': creditPoint[i] = credit[i] * 6;  break;
            case 'D': creditPoint[i] = credit[i] * 5;  break;
            case 'F': creditPoint[i] = credit[i] * 2;  break;
            default: 
                cout << "Invalid grade for " << subjectName[i] << ". Assuming 0 points.\n";
                creditPoint[i] = 0;
        }
    }

    // Sum credits and grade points
    float sumCredit = 0.0, sumCreditPoint = 0.0;
    for (int i = 0; i < num; i++) {
        sumCredit += credit[i];
        sumCreditPoint += creditPoint[i];
    }

    return sumCreditPoint / sumCredit;
}

int main() {
    cout<<"============Semester 1============"<<endl;
    cout << "Enter the details for 1st Semester:\n";
    float sem1 = SGPA();
    cout << "Sem 1 SGPA: " << sem1 << "\n\n";

    cout<<"============Semester 2============"<<endl;

    cout << "Enter the details for 2nd Semester:\n";
    float sem2 = SGPA();
    cout << "Sem 2 SGPA: " << sem2 << "\n\n";

    cout<<"==============Result=============="<<endl;

    float CGPA = (sem1 + sem2) / 2;
    cout << "Overall CGPA: " << CGPA << endl;

    return 0;
}