//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#include "StudentList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>
#include <ctime>
using namespace std;
using namespace std::chrono;

list<StudentList> readFileLists(int num){
  list<StudentList> students;
  string filename = "students" + to_string(num) + ".txt";
    ifstream file(filename);
    try{
        if (!file.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo.");
        } else {
            string header, line;
            getline(file, header);

            auto start = high_resolution_clock::now();
            while (getline(file, line)) {
                StudentList student;
                std::istringstream iss(line);
                iss >> student.name >> student.surname;
                double grade;
                while (iss >> grade) {
                    student.grades.push_back(grade);
                }

                student.exam_grade = static_cast<int>(student.grades.back());
                student.grades.pop_back();
                calculateFinalGradesAverageList(student);

                students.push_back(student);
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            double duration_s = duration_ms.count() / 1000.0;
            cout << to_string(num) + " irasu skaitymas i list: "<< duration_s << "s" << endl;

            file.close();
        }
    }
    catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }
    return students;
  }
double averageList(const StudentList &student) {
    if (student.grades.empty()) {
        return 0.0;
    }
    double average = accumulate(student.grades.begin(), student.grades.end(), 0.0) / student.grades.size();
    return average;
}
void calculateFinalGradesAverageList(const StudentList &student) {
    double average_grade = averageList(student);
    double final = average_grade * 0.4 + student.exam_grade * 0.6;
    student.final_grade = final;
}

list<StudentList> sortList(list<StudentList> students, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    students.sort([](const StudentList &a, const StudentList &b) {return a.final_grade<b.final_grade;});
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + " irasu rusiavimas i list: "<< elapsed_seconds << "s" << endl;


    return students;
}
void splitInTwo(list<StudentList> &students, int num) {
    list<StudentList> kietekai;
    list<StudentList> vargsiukai;
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    auto it = students.begin();
    while (it != students.end()) {
        if (it->final_grade < 5) {
            vargsiukai.push_back(*it);
            it = students.erase(it);
        }
        else {
            kietekai.push_back(*it);
            it = students.erase(it);
        }
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + " irasu dalijimas i list: "<< elapsed_seconds << "s" << endl;
}
void strategyTwoList(list<StudentList> &students, list<StudentList> &vargsiukai,int num) {

    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    list<StudentList>::const_iterator it = students.begin();
    while (it != students.end()) {
        if (it->final_grade < 5) {
            vargsiukai.push_back(move(*it));
            it = students.erase(it);
        } else {
            ++it;
        }
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 2 irasu dalijimas i list: "<< elapsed_seconds << "s" << endl;
}
void strategyThreeList(list<StudentList>& students, list<StudentList>& vargsiukai, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    auto bound = stable_partition(students.begin(), students.end(), [](const StudentList& s){return s.final_grade < 5.00;});
    copy(students.begin() , bound, back_inserter(vargsiukai));
    students.erase(students.begin(), bound);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 3 irasu dalijimas i list: "<< elapsed_seconds << "s" << endl;

}

