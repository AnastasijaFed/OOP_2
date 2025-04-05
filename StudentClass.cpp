#include "functions.h"
#include "StudentClass.h"

vector<StudentClass> StudentClass::addStudentsObjects(vector<StudentClass> students) {
    char answer;
    cout << "Ar norite pridėti naują studentą? (t/n)";
    cin >> answer;
    while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
        cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
        cout << "Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
    }

    while (std::tolower(answer) == 't') {
        StudentClass student;

        cout << "Vardas: " << endl;
        cin >> student.name;

        cout << "Pavardė: " << endl;
        cin >> student.surname;
        int grades_number;
        cout << "Kiek tarpinių pažymių (už namų darbus) norite įvesti?: " << endl;
        cin >> grades_number;
        while (cin.fail() || grades_number < 0) {
            cout << "Neteisinga įvestis. Įveskite teigiamą skaičių: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> grades_number;
        }

        if (grades_number > 0) {
            cout << "Pažymiai: " << endl;
            vector<double> tempGrades;
            for (int i = 1; i <= grades_number; i++) {
                int grade = 0;
                cin >> grade;
                while (cin.fail() || grade < 0 || grade > 10) {
                    cout << "Neteisinga įvestis. Įveskite skaičių nuo 0 iki 10: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> grade;
                }
                tempGrades.push_back(grade);
            }
            student.setGrades(tempGrades);
        } else {
            cout << "Studentas neturi tarpinių pažymių." << endl;
        }
        cout << "Egzamino pažymys: " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> student.exam_grade;
        /*while (cin.fail() || student.exam_grade < 0 || student.exam_grade > 10) {
            cout << "Neteisinga įvestis. Įveskite skaičių: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> student.exam_grade;
        }*/
        calculateFinalGradesAverageClass(student);
        students.push_back(student);

        cout << "Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
        while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
            cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
            cout << "Ar norite pridėti naują studentą? (t/n)";
            cin >> answer;
        }
        if (answer == 'n') { break; }
    }
    return students;
}

double StudentClass::averageClass(StudentClass &student) {

    if (student.getGrades().empty()) {
        return 0.0;
    }
    double average = 0;
    for (int i = 0; i < student.getGrades().size(); i++) {
        average += student.getGrades()[i];
    }
    average /= student.getGrades().size();



    return average;
}

double StudentClass::medianClass(StudentClass &student) {
    if (student.getGrades().empty()) {
        return 0.0;
    }
    std::vector<double> sorted_grades = student.getGrades();
    std::sort(sorted_grades.begin(), sorted_grades.end());

    size_t middle = sorted_grades.size() / 2;

    if (sorted_grades.size() % 2 == 0) {
        return (sorted_grades[middle - 1] + sorted_grades[middle]) / 2.0;
    } else {
        return sorted_grades[middle];
    }
}

double StudentClass::calculateFinalGradesMedianClass(StudentClass &student) {
    double median_grade = medianClass(student);
    return median_grade * 0.4 + student.getExamGrades() * 0.6;
}

void StudentClass::calculateFinalGradesAverageClass(StudentClass &student) {
    double average_grade = averageClass(student);
    double finalGrade = average_grade * 0.4 + student.getExamGrades() * 0.6;
    student.setFinalGrade(finalGrade);
}

void StudentClass::printStudentListClass(vector<StudentClass> &students) {
    cout << left << setw(15) << "Pavardė" << setw(10) << "Vardas"
         << setw(15) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
    cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl; // Increased width

    for (size_t i = 0; i < students.size(); ++i) {
        cout << left << setw(15) << students[i].getSurname() << setw(10) << students[i].getName();

        double medFinal = calculateFinalGradesMedianClass(students[i]);

        cout << fixed << setprecision(2) << right << setw(15) << students[i].getFinalGrade()
             << fixed << setprecision(2) << right << setw(15) << medFinal << endl;
    }
}

void StudentClass::generateGradesClass(vector<StudentClass> &students) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    for (auto &student : students) {
        int grades_number = 5;
        student.clearGrades();
        for (int i = 0; i < grades_number; ++i) {
            vector<double> newGrades = student.getGrades();
            newGrades.push_back(rand() % 10 + 1);
            student.setGrades(newGrades);
        }
        student.setExamGrades(rand() % 10 + 1);
        calculateFinalGradesAverageClass(student);
    }
}

vector<string> StudentClass::loadFromFileClass(const string &filename) {
    vector<string> list;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            list.push_back(line);
        }
        file.close();
    }
    return list;
}

vector<StudentClass> StudentClass::readStudentsFileClass(const string &filename) {
    vector<StudentClass> students;
    ifstream file(filename);
    try {
        if (!file.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        } else {
            string header, line;
            getline(file, header);

            while (getline(file, line)) {
                StudentClass student;
                std::istringstream iss(line);
                iss >> student.name >> student.surname;
                double grade;
                vector<double> tempGrades;
                while (iss >> grade) {
                    tempGrades.push_back(grade);
                }

                student.setExamGrades((tempGrades.back()));
                tempGrades.pop_back();
                student.setGrades(tempGrades);
                calculateFinalGradesAverageClass(student);

                students.push_back(student);
            }

            file.close();
        }
    } catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }

    return students;
}

vector<StudentClass> StudentClass::generateRandomStudentsClass(int count) {
    vector<StudentClass> students;


        for (int i = 1; i <= count; ++i) {
            StudentClass student;
            student.name = "Vardas" + to_string(rand() % count + 1);
            student.surname = "Pavarde" + to_string(rand() % count + 1);
            students.push_back(student);
        }
        return students;


    }


vector<StudentClass> StudentClass::testClass() {
    std::string filename;
    cout << "Kiek studentų norite pridėti? (10000/100000/1000000)" << endl;
    int n;
    cin >> n;
    while (n != 10000 && n != 100000 && n != 1000000) {
        cout << "Neteisinga įvestis, bandykite dar kartą" << endl;
        cin >> n;
    }
    auto start = high_resolution_clock::now();
    if (n == 10000) {
        filename.assign("studentai10000.txt");
    } else if (n == 100000) {
        filename.assign("studentai100000.txt");
    } else if (n == 1000000) {
        filename.assign("studentai1000000.txt");
    }
    vector<StudentClass> students;
    ifstream file(filename);
    try {
        if (!file.is_open()) {
            throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
        }

        std::string line, header;
        getline(file, header);
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            StudentClass student;

            iss >> student.name >> student.surname;

            double grade;
            vector<double> tempGrades;
            while (iss >> grade) {
                tempGrades.push_back(grade);
            }

            if (!tempGrades.empty()) {
                student.setExamGrades(static_cast<int>(tempGrades.back()));
                tempGrades.pop_back();
                student.setGrades(tempGrades);
            } else {
                std::cerr << "Warning: No grades found for student " << student.name << " " << student.surname << std::endl;
            }

            students.push_back(student);
        }

        file.close();

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        double duration_s = duration_ms.count() / 1000.0;
        printStudentListClass(students);

        cout << "Duration (seconds): " << duration_s << endl;
    } catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }
    return students;
}

bool StudentClass::compareByNameClass(StudentClass a, StudentClass b) {
    return a.name < b.name;
}

bool StudentClass::compareBySurnameClass(StudentClass a, StudentClass b) {
    return a.surname < b.surname;
}

bool StudentClass::compareByAverageClass(StudentClass a, StudentClass b) {
    return a.getFinalGrade() < b.getFinalGrade();
}

vector<StudentClass> StudentClass::sortByNameClass(vector<StudentClass> students) {
    sort(students.begin(), students.end(), [this](StudentClass a, StudentClass b) { return this->compareByNameClass(a, b); });
    printStudentListClass(students);
    return students;
}

vector<StudentClass> StudentClass::sortBySurnameClass(vector<StudentClass> students) {
    sort(students.begin(), students.end(), [this](StudentClass a, StudentClass b) { return this->compareBySurnameClass(a, b); });
    printStudentListClass(students);
    return students;
}

vector<StudentClass> StudentClass::sortByAverageClass(vector<StudentClass> students) {
    sort(students.begin(), students.end(), [this](StudentClass a, StudentClass b) { return this->compareByAverageClass(a, b); });
    return students;
}

void StudentClass::logDuration(const string &message, const high_resolution_clock::time_point &start, const high_resolution_clock::time_point &stop) {
    auto duration_ms = duration_cast<milliseconds>(stop - start);
    double duration_s = duration_ms.count() / 1000.0;
    cout << message << fixed << setprecision(10) << duration_s << " sec" << endl;
}

void StudentClass::generateStudentsFileClass(int numberOfStudents) {
    string filename = "students" + to_string(numberOfStudents) + ".txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Nepavyko sukurti failo: " << filename << endl;
        return;
    }

    auto start = high_resolution_clock::now();
    vector<StudentClass> students = generateRandomStudentsClass(numberOfStudents);
    generateGradesClass(students);

    for (StudentClass &student : students) {
        file << student.getName() << " " << student.getSurname() << "       ";
        for (const double &grade : student.getGrades()) {
            file << grade << " ";
        }
        file << student.getExamGrades() << endl;
    }

    auto stop = high_resolution_clock::now();
    logDuration(filename + " sukūrimo laikas: ", start, stop);
    file.close();
}

void StudentClass::sortStudentsInFileClass(vector<StudentClass> &students, int numberOfStudents) {
    string studentsFilename = "students" + to_string(numberOfStudents) + ".txt";
    string kietekaiFilename = "kietekai" + to_string(numberOfStudents) + ".txt";
    string vargsiukaiFilename = "vargsiukai" + to_string(numberOfStudents) + ".txt";

    ofstream file1(kietekaiFilename);
    ofstream file2(vargsiukaiFilename);

    auto startRead = high_resolution_clock::now();
    students = readStudentsFileClass(studentsFilename);
    auto stopRead = high_resolution_clock::now();
    logDuration(to_string(numberOfStudents) + " įrašų iš failo nuskaitymo laikas: ", startRead, stopRead);

    auto startSort = high_resolution_clock::now();
    students = sortByAverageClass(students);

    auto stopSort = high_resolution_clock::now();
    logDuration(to_string(numberOfStudents) + " įrašų rūšiavimo laikas: ", startSort, stopSort);

    vector<StudentClass> kietekai;
    vector<StudentClass> vargsiukai;
    auto startSplit = high_resolution_clock::now();
    for (StudentClass &student : students) {
        if (student.getFinalGrade() < 5.00) {
            vargsiukai.push_back(student);
        } else {
            kietekai.push_back(student);
        }
    }
    auto stopSplit = high_resolution_clock::now();
    logDuration(to_string(numberOfStudents) + " įrašų padalijimo į du konteinerius laikas vector: ", startSplit, stopSplit);
    students.erase(students.begin(), students.end());

    auto startWrite1 = high_resolution_clock::now();
    for (StudentClass student : kietekai) {
        file1 << student.getName() << " " << student.getSurname() << "       " << student.getFinalGrade() << endl;
    }
    auto stopWrite1 = high_resolution_clock::now();
    logDuration(to_string(numberOfStudents) + " įrašymo į " + kietekaiFilename + " laikas: ", startWrite1, stopWrite1);

    auto startWrite2 = high_resolution_clock::now();
    for (StudentClass student : vargsiukai) {
        file2 << student.getName() << " " << student.getSurname() << "       " << student.getFinalGrade() << endl;
    }
    auto stopWrite2 = high_resolution_clock::now();
    logDuration(to_string(numberOfStudents) + " įrašymo į " + vargsiukaiFilename + " laikas: ", startWrite2, stopWrite2);

    file1.close();
    file2.close();
}

void StudentClass::strategyTwoVectorClass(vector<StudentClass> &students, vector<StudentClass> &vargsiukai, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    int blogiukai = 0;

    for (int i = 0; i < num; i++) {
        if (students[i].getFinalGrade() < 5.00) {
            blogiukai++;
        }
    }
    vargsiukai.reserve(blogiukai);
    vargsiukai.assign(students.begin(), students.begin() + blogiukai);
    students.erase(students.begin(), students.begin() + blogiukai);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 2 irasu dalijimas i vector: " << elapsed_seconds << "s" << endl;
}

void StudentClass::strategyThreeVector(vector<StudentClass> &students, vector<StudentClass> &vargsiukai, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    vector<StudentClass>::iterator bound;
    bound = stable_partition(students.begin(), students.end(), [](StudentClass &s) { return s.getFinalGrade() < 5.00; });
    copy(students.begin(), bound, back_inserter(vargsiukai));
    students.erase(students.begin(), bound);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 3 irasu dalijimas i vector: " << elapsed_seconds << "s" << endl;
}

StudentClass::StudentClass() : final_grade(0) {}

StudentClass::~StudentClass() {}