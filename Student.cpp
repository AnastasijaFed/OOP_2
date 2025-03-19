#include "functions.h"
#include "StudentList.h"
#include "StudentDeque.h"
using namespace std;




int main() {
    vector<Student> students;
    vector<Student> students2;
    int menu_choice;

    do {
        cout << "\nPasirinkite programos eigą:\n";
        cout << "1 - Įvesti studentų duomenis ranka\n";
        cout << "2 - Generuoti pažymius\n";
        cout << "3 - Generuoti studentų vardus, pavardes ir pažymius\n";
        cout << "4 - Nuskaityti iš failo\n";
        cout << "5 - Rūšiuoti\n";
        cout << "6 - Sukurti failus\n";
        cout << "7 - Testas tik su vektoriais\n";
        cout << "8 - Testas su skirtingais konteineriais\n";
        cout << "9 - Baigti darbą\n";
        cout << "Jūsų pasirinkimas: ";
        cin >> menu_choice;
        while (cin.fail() || menu_choice < 1 || menu_choice > 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
            cin >> menu_choice;
        }

        switch (menu_choice) {
        case 1:
        {
            try {
                students = addStudents(students);
            }
            catch (const std::bad_alloc& e) {
                cerr << "Nepakanka atminties. Programa baigiama.\n";
                return 1;
            }
            break;
        case 2:
            if (students.empty()) {
                cout << "Pirmiausia sugeneruokite studentus arba įveskite ranka.\n";
            }
            else {
                generateGrades(students);
            }
            break;
        }
        case 3:
        {
            int count;
            cout << "Kiek studentų generuoti? ";
            while (!(cin >> count) || count < 0 || cin.peek() != '\n') {
                cout << "Neteisinga įvestis. Įveskite teigiamą skaičių: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            students2 = generateRandomStudents(count);
            generateGrades(students2);
            for (auto& student : students2) {
                students.push_back(student);
            }
            break;
        }
        case 4:
        {
            students2 = readStudentsFile(std::string("kursiokai.txt"));
            for (auto& student : students2) {
                students.push_back(student);
            }
            if (!students2.empty()) {
                printStudentList(students);
            }

            break;
        }
        case 5:
        {
            int answ;
            cout << "\n Pasirinkite rūšiavimo būdą: \n";
            cout << "1-Pagal vardą: \n";
            cout << "2-Pagal pavardę: \n";
            cout << "3-Pagal galutinį vidurkį: \n";
            cout << "4-Pagal medianą: \n";
            if (students.empty()) {
                cout << "Sąraše nėra studentų";
            }
            else {
                cin >> answ;
                while (cin.fail() || answ < 1 || answ > 4) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
                    cin >> answ;
                }
                if (answ == 1) {
                    students = sortByName(students);
                    printStudentList(students);
                }
                else if (answ == 2) {
                    students = sortBySurname(students);
                    printStudentList(students);
                }
                else if (answ == 3) {
                    students = sortByAverage(students);
                    printStudentList(students);
                }
                else if (answ == 4) {
                    students = sortByMedian(students);
                    printStudentList(students);
                }
            }
            break;
        }
        case 6:
        {

            /*generateStudentsFile(1000);
            generateStudentsFile(10000);
            generateStudentsFile(100000);
            generateStudentsFile(1000000);
            generateStudentsFile(10000000);*/
            auto start = high_resolution_clock::now();
            sortStudentsInFile(students,1000);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            double duration_s = duration_ms.count() / 1000.0;
            cout<<"1000 įrašų testo laikas: " << duration_s << "sec" << endl;

            auto start1 = high_resolution_clock::now();
            sortStudentsInFile(students,10000);
            auto stop1 = std::chrono::high_resolution_clock::now();
            auto duration_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
            double duration_s1 = duration_ms.count() / 1000.0;
            cout<<"10000 įrašų testo laikas: " << duration_s1 << "sec" << endl;

            auto start3 = high_resolution_clock::now();
            sortStudentsInFile(students,100000);
            auto stop3 = std::chrono::high_resolution_clock::now();
            auto duration_ms3 = std::chrono::duration_cast<std::chrono::milliseconds>(stop3 - start3);
            double duration_s3 = duration_ms3.count() / 1000.0;
            cout<<"100000 įrašų testo laikas: " << duration_s3 << "sec" << endl;

            auto start4 = high_resolution_clock::now();
            sortStudentsInFile(students,1000000);
            auto stop4 = std::chrono::high_resolution_clock::now();
            auto duration_ms4 = std::chrono::duration_cast<std::chrono::milliseconds>(stop4 - start4);
            double duration_s4 = duration_ms4.count() / 1000.0;
            cout<<"1000000 įrašų testo laikas: " << duration_s4 << "sec" << endl;

            auto start5 = high_resolution_clock::now();
            sortStudentsInFile(students,10000000);
            auto stop5 = std::chrono::high_resolution_clock::now();
            auto duration_ms5 = std::chrono::duration_cast<std::chrono::milliseconds>(stop5 - start5);
            double duration_s5 = duration_ms5.count() / 1000.0;
            cout<<"10000000 įrašų testo laikas: " << duration_s5 << "sec" << endl;



            cout << "Failai sukurti sėkmingai" << endl;
            break;
        }
        case 7:
        {
            students2 = test();
            for (auto& student : students2) {
                students.push_back(student);
            }
            break;
        }
            case 8:
        {
            vector<Student> students;
    vector<Student> vargsiukai3;
    cout << "Vektoriai: "<<endl;
    cout << "-----------------------------------------------------------"<<endl;

    sortStudentsInFile(students, 1000);
    strategyTwoVector(students, vargsiukai3, 1000);
    strategyThreeVector(students, vargsiukai3, 1000);
    students.clear();
    vargsiukai3.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,10000);
    strategyTwoVector(students, vargsiukai3, 10000);
    strategyThreeVector(students, vargsiukai3, 10000);
    students.clear();
    vargsiukai3.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,100000);
    strategyTwoVector(students, vargsiukai3, 100000);
    strategyThreeVector(students, vargsiukai3, 100000);
    students.clear();
    vargsiukai3.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,1000000);
    strategyTwoVector(students, vargsiukai3, 1000000);
    strategyThreeVector(students, vargsiukai3, 1000000);
    students.clear();
    vargsiukai3.clear();
    cout << " "<<endl;

    sortStudentsInFile(students,10000000);
    strategyTwoVector(students, vargsiukai3, 10000000);
    strategyThreeVector(students, vargsiukai3, 10000000);
    students.clear();
    vargsiukai3.clear();
    cout << " "<<endl;



    cout << "-----------------------------------------------------------"<<endl;
    cout << "Listai: "<<endl;
    cout << "-----------------------------------------------------------"<<endl;
    list <StudentList> studentsList;
    list <StudentList> vargsiukai2;

    studentsList = readFileLists(1000);
    studentsList = sortList(studentsList, 1000);
    //splitInTwo(studentsList, 1000);
    strategyTwoList(studentsList, vargsiukai2, 1000);
    strategyThreeList(studentsList, vargsiukai2, 1000);
    studentsList.clear();
    cout << " "<<endl;

    studentsList = readFileLists(10000);
    studentsList = sortList(studentsList, 10000);
    //splitInTwo(studentsList, 10000);
    strategyTwoList(studentsList, vargsiukai2, 10000 );
    strategyThreeList(studentsList, vargsiukai2, 10000);
    studentsList.clear();

    cout << " "<<endl;

    studentsList = readFileLists(100000);
    studentsList = sortList(studentsList, 100000);
    splitInTwo(studentsList, 100000);
    strategyTwoList(studentsList, vargsiukai2, 100000 );
    strategyThreeList(studentsList, vargsiukai2, 100000);
    studentsList.clear();
    cout << " "<<endl;

    studentsList = readFileLists(1000000);
    studentsList = sortList(studentsList, 1000000);
    splitInTwo(studentsList, 1000000);
    strategyTwoList(studentsList, vargsiukai2, 1000000 );
    strategyThreeList(studentsList, vargsiukai2, 1000000);
    studentsList.clear();
    cout << " "<<endl;

    studentsList = readFileLists(10000000);
    studentsList = sortList(studentsList, 10000000);
    splitInTwo(studentsList, 10000000);
    strategyTwoList(studentsList, vargsiukai2, 10000000 );
    strategyThreeList(studentsList, vargsiukai2, 10000000);
    studentsList.clear();

    cout << "-----------------------------------------------------------"<<endl;
    cout << "Deque: "<<endl;
    cout << "-----------------------------------------------------------"<<endl;
    deque<StudentDeque> studentsDeque;
    deque<StudentDeque> kietekai;
    deque<StudentDeque> vargsiukai;
    studentsDeque = readFileDeque(1000);
    sortDeque(studentsDeque, 1000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 1000);
    strategyTwoDeque(studentsDeque, vargsiukai, 1000);
    strategyThreeDeque(studentsDeque, vargsiukai, 1000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(10000);
    sortDeque(studentsDeque, 10000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 10000);
    strategyTwoDeque(studentsDeque, vargsiukai, 10000);
    strategyThreeDeque(studentsDeque, vargsiukai, 10000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(100000);
    sortDeque(studentsDeque, 100000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 100000);
    strategyTwoDeque(studentsDeque, vargsiukai, 100000);
    strategyThreeDeque(studentsDeque, vargsiukai, 100000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(1000000);
    sortDeque(studentsDeque, 1000000);
    splitToGroupsDeque(studentsDeque, kietekai, vargsiukai, 1000000);
    strategyTwoDeque(studentsDeque, vargsiukai, 1000000);
    strategyThreeDeque(studentsDeque, vargsiukai, 1000000);
    studentsDeque.clear();
    cout << " "<<endl;

    studentsDeque = readFileDeque(10000000);
    sortDeque(studentsDeque, 10000000);
   splitToGroupsDeque(studentsDeque, kietekai, vargsiukai,10000000);
    strategyTwoDeque(studentsDeque, vargsiukai, 10000000);
    strategyThreeDeque(studentsDeque, vargsiukai, 10000000);
    studentsDeque.clear();
            break;
        }
        case 9:
        {
            cout << "Programa baigė darbą.\n";
            break;
        }
        default:
        {
            cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
            cin >> menu_choice;
        }

        if (menu_choice >= 1 && menu_choice <= 3) {
            printStudentList(students);
        }
        }
    } while (menu_choice != 9);









    return 0;
}