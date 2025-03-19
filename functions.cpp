

#include "functions.h"
vector<Student> addStudents(vector<Student> students) {
    char answer;
    cout << "Ar norite pridėti naują studentą? (t/n)";
    cin >> answer;
    while (std::tolower(answer) != 't' && std::tolower(answer) != 'n') {
        cout << "Toks atsakymas negalimas. Bandykite iš naujo.";
        cout << "Ar norite pridėti naują studentą? (t/n)";
        cin >> answer;
    }

    while (std::tolower(answer) == 't') {
        Student student;

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
            for (int i = 1; i <= grades_number; i++) {
                int grade = 0;
                cin >> grade;
                while (cin.fail() || grade < 0 || grade > 10) {
                    cout << "Neteisinga įvestis. Įveskite skaičių nuo 0 iki 10: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> grade;
                }
                student.grades.push_back(grade);
            }
        } else {
            cout << "Studentas neturi tarpinių pažymių." << endl;
        }
        cout << "Egzamino pažymys: " << endl;
        cin>>student.exam_grade;
        while (cin.fail() || student.exam_grade < 0 || student.exam_grade > 10) {
            cout << "Neteisinga įvestis. Įveskite skaičių: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> student.exam_grade;
        }


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


double average(const Student &student) {
    if (student.grades.empty()) {
        return 0.0;
    }
    double average = accumulate(student.grades.begin(), student.grades.end(), 0.0) / student.grades.size();
    return average;
}

double median(const Student &student) {
    if (student.grades.empty()) {
        return 0.0;
    }
    std::vector<uint8_t> sorted_grades = student.grades;
    std::sort(sorted_grades.begin(), sorted_grades.end());

    size_t middle = sorted_grades.size() / 2;

    if (sorted_grades.size() % 2 == 0) {
        return (sorted_grades[middle - 1] + sorted_grades[middle]) / 2.0;
    } else {
        return sorted_grades[middle];
    }
}

double calculateFinalGradesMedian(const Student &student) {
    double median_grade = median(student);
    return median_grade * 0.4 + student.exam_grade * 0.6;
}

void calculateFinalGradesAverage(const Student &student) {
    double average_grade = average(student);
    double final = average_grade * 0.4 + student.exam_grade * 0.6;;
    student.final_grade = final;
}

void printStudentList(vector<Student> &students) {
    cout << left << setw(15) << "Pavardė" << setw(10) << "Vardas"
            << setw(15) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
    cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl; // Increased width

    for (size_t i = 0; i < students.size(); ++i) {
        cout << left << setw(15) << students[i].surname << setw(10) << students[i].name;


        double medFinal = calculateFinalGradesMedian(students[i]);

        cout << fixed << setprecision(2) << right << setw(15) << students[i].final_grade
                << fixed << setprecision(2) << right << setw(15) << medFinal << endl;
    }
}

void generateGrades(vector<Student> &students) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    for (auto &student: students) {
        int grades_number = 5;
        student.grades.clear();
        for (int i = 0; i < grades_number; ++i) {
            student.grades.push_back(rand() % 10 + 1);
        }
        student.exam_grade = rand() % 10 + 1;
    }
}

vector<string> loadFromFile(const string &filename) {
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

vector<Student> readStudentsFile(const string &filename) {
    vector<Student> students;
    ifstream file(filename);
    try{
    if (!file.is_open()) {
        throw runtime_error("Nepavyko atidaryti failo.");
    } else {
        string header, line;
        getline(file, header);


        while (getline(file, line)) {
            Student student;
            std::istringstream iss(line);
            iss >> student.name >> student.surname;
            double grade;
            while (iss >> grade) {
                student.grades.push_back(grade);
            }

            student.exam_grade = static_cast<int>(student.grades.back());
            student.grades.pop_back();
            calculateFinalGradesAverage(student);

            students.push_back(student);
        }

        file.close();
    }
    }
    catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }

    return students;
}


vector<Student> generateRandomStudents(int count) {
    vector<string> first_names = loadFromFile("first_names.txt");
    vector<string> last_names = loadFromFile("surnames.txt");
    vector<Student> students;

    if (first_names.empty() || last_names.empty()) {
        for (int i = 1; i <= count; ++i) {
            Student student;
            student.name = "Vardas" + to_string(rand() % count + 1);
            student.surname = "Pavarde" + to_string(rand() % count + 1);
            students.push_back(student);
        }
        return students;
    } else {
        /*random_shuffle(first_names.begin(), first_names.end());
        random_shuffle(last_names.begin(), last_names.end());*/
        for (int i = 0; i < count; ++i) {
            Student student;
            student.name = first_names[i % first_names.size()];
            student.surname = last_names[i % last_names.size()];
            students.push_back(student);
        }

        return students;
    }
}

vector<Student> test() {
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
    vector<Student> students;
    ifstream file(filename);
    try{
    if (!file.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
    }

    std::string line, header;
    getline(file, header);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Student student;

        iss >> student.name >> student.surname;

        double grade;
        while (iss >> grade) {
            student.grades.push_back(grade);
        }

        if (!student.grades.empty()) {
            student.exam_grade = static_cast<int>(student.grades.back());
            student.grades.pop_back();
        } else {
            std::cerr << "Warning: No grades found for student " << student.name << " " << student.surname << std::endl;
        }

        students.push_back(student);
    }

    file.close();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    double duration_s = duration_ms.count() / 1000.0;
    printStudentList(students);

    cout << "Duration (seconds): " << duration_s << endl;
    }catch (const runtime_error& e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;

        }
    return students;
}

bool compareByName(const Student a, const Student b) {
    return a.name < b.name;
}

bool compareBySurname(const Student a, const Student b) {
    return a.surname < b.surname;
}

bool compareByAverage(const Student a, const Student b) {
    return a.final_grade < b.final_grade;
}

bool compareByMedian(const Student a, const Student b) {
    return a.final_grade < b.final_grade;
}

vector<Student> sortByName(vector<Student> students) {
    sort(students.begin(), students.end(), compareByName);
    printStudentList(students);
    return students;
}

vector<Student> sortBySurname(vector<Student> students) {
    sort(students.begin(), students.end(), compareBySurname);
    printStudentList(students);
    return students;
}

vector<Student> sortByAverage(vector<Student> students) {
    sort(students.begin(), students.end(), compareByAverage);
    return students;
}

vector<Student> sortByMedian(vector<Student> students) {
    sort(students.begin(), students.end(), compareByMedian);
    return students;
}
void logDuration(const string& message, const high_resolution_clock::time_point& start, const high_resolution_clock::time_point& stop) {
    auto duration_ms = duration_cast<milliseconds>(stop - start);
    double duration_s = duration_ms.count() / 1000.0;
    cout << message << fixed << setprecision(10) << duration_s << " sec" << endl;
}

void generateStudentsFile(int numberOfStudents){
  string filename = "students" + to_string(numberOfStudents) + ".txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Nepavyko sukurti failo: " << filename << endl;
        return;
    }

    auto start = high_resolution_clock::now();
    vector<Student> students = generateRandomStudents(numberOfStudents);
    generateGrades(students);

    for (const Student& student : students) {
        file << student.name << " " << student.surname << "       ";
        for (const double& grade : student.grades) {
            file << grade << " ";
        }
        file << student.exam_grade << endl;
    }

    auto stop = high_resolution_clock::now();
    logDuration(filename + " sukūrimo laikas: ", start, stop);
    file.close();
  }

void sortStudentsInFile(vector<Student>& students,int numberOfStudents) {

  string studentsFilename = "students" + to_string(numberOfStudents) + ".txt";
  string kietekaiFilename = "kietekai" + to_string(numberOfStudents) + ".txt";
  string vargsiukaiFilename = "vargsiukai" + to_string(numberOfStudents) + ".txt";

  ofstream file1(kietekaiFilename);
  ofstream file2(vargsiukaiFilename);

  auto startRead = high_resolution_clock::now();
    students = readStudentsFile(studentsFilename);
  auto stopRead = high_resolution_clock::now();
  logDuration(to_string(numberOfStudents) + " įrašų iš failo nuskaitymo laikas: ", startRead, stopRead);


    auto startSort = high_resolution_clock::now();
     students = sortByAverage(students);

	auto stopSort = high_resolution_clock::now();
    logDuration(to_string(numberOfStudents) + " įrašų rūšiavimo laikas: ", startSort, stopSort);
    /*
    vector<Student> kietekai;
    vector<Student> vargsiukai;
    auto startSplit = high_resolution_clock::now();
    for (const Student& student : students) {
        if (student.final_grade < 5.00) {
            vargsiukai.push_back(student);
        } else {
            kietekai.push_back(student);
        }
    }
    auto stopSplit = high_resolution_clock::now();
    logDuration(to_string(numberOfStudents) + " įrašų padalijimo į du konteinerius laikas vector: ", startSplit, stopSplit);
  	students.erase(students.begin(), students.end());



 auto startWrite1 = high_resolution_clock::now();
  for(Student student : kietekai) {
    file1 << student.name << " " << student.surname << "       " << student.final_grade<<endl;
  }
  auto stopWrite1 = high_resolution_clock::now();
        logDuration(to_string(numberOfStudents) + " įrašymo į " + kietekaiFilename + " laikas: ", startWrite1, stopWrite1);


  auto startWrite2 = high_resolution_clock::now();
  for(Student student : vargsiukai) {
    file2 << student.name << " " << student.surname << "       " << student.final_grade<<endl;
  }
  auto stopWrite2 = high_resolution_clock::now();
  logDuration(to_string(numberOfStudents) + " įrašymo į " + vargsiukaiFilename + " laikas: ", startWrite2, stopWrite2);
  */




  file1.close();
  file2.close();
  }
void strategyTwoVector(vector<Student>& students, vector<Student>& vargsiukai, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    int blogiukai = 0;

    for (int i = 0; i < num; i++) {
        if (students[i].final_grade < 5.00) {
            blogiukai++;
        }
    }
    vargsiukai.reserve(blogiukai);
    vargsiukai.assign(students.begin() , students.begin()+blogiukai);
    students.erase(students.begin() , students.begin()+blogiukai);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 2 irasu dalijimas i vector: "<< elapsed_seconds << "s" << endl;

}
void strategyThreeVector(vector<Student>& students, vector<Student>& vargsiukai, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    vector<Student>::iterator bound;
    bound = stable_partition(students.begin(), students.end(), [](const Student& s){return s.final_grade < 5.00;});
    copy(students.begin() , bound, back_inserter(vargsiukai));
    students.erase(students.begin(), bound);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 3 irasu dalijimas i vector: "<< elapsed_seconds << "s" << endl;


}



