//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#include "StudentDeque.h"
#include <ctime>

//
// Created by Anastasija Fedorenko on 2025-03-12.
//


#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>


using namespace std;
using namespace std::chrono;

deque<StudentDeque> readFileDeque(int num){
    deque<StudentDeque> students;
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
                StudentDeque student;
                std::istringstream iss(line);
                iss >> student.name >> student.surname;
                double grade;
                while (iss >> grade) {
                    student.grades.push_back(grade);
                }

                student.exam_grade = static_cast<int>(student.grades.back());
                student.grades.pop_back();
                calculateFinalGradesAverageDeque(student);

                students.push_back(student);
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            double duration_s = duration_ms.count() / 1000.0;
          cout << to_string(num) + " irasu skaitymas i deque: "<< duration_s << "s" << endl;

            file.close();
        }
    }
    catch (const runtime_error &e) {
        cerr << "Klaida skaitant failą: " << e.what() << endl;
    }
    return students;
}
double averageDeque(const StudentDeque &student) {
    if (student.grades.empty()) {
        return 0.0;
    }
    double average = accumulate(student.grades.begin(), student.grades.end(), 0.0) / student.grades.size();
    return average;
}
void calculateFinalGradesAverageDeque(const StudentDeque &student) {
    double average_grade = averageDeque(student);
    double final = average_grade * 0.4 + student.exam_grade * 0.6;
    student.final_grade = final;
}

void sortDeque(deque<StudentDeque>& students, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    sort(students.begin(), students.end(), [](StudentDeque &a, StudentDeque &b) {
        return a.final_grade < b.final_grade;
    });
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + " irasu rusiavimas i deque: "<< elapsed_seconds << "s" << endl;

}
void splitToGroupsDeque(deque<StudentDeque>& students, deque<StudentDeque>& kietekai, deque<StudentDeque>& vargsiukai, int num) {

    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for (int i = 0; i < num; i++) {
        if (students[i].final_grade < 5) {
            vargsiukai.push_back(std::move(students[i]));
        }
        else {
            kietekai.push_back(std::move(students[i]));
        }
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + " irasu dalijimas i deque: "<< elapsed_seconds << "s" << endl;

}
void strategyTwoDeque(deque<StudentDeque>& students, deque<StudentDeque>& vargsiukai, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    int numS = 0;
    for (int i = 0; i < num; i++) {
        if (students[i].final_grade < 5) {
            vargsiukai.push_back(std::move(students[i]));
            numS++;

        }
    }
    students.erase(students.begin(), students.begin()+numS);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 2 irasu dalijimas i deque: "<< elapsed_seconds << "s" << endl;
}
void strategyThreeDeque(deque<StudentDeque>& students, deque<StudentDeque>& vargsiukai, int num) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    auto bound = stable_partition(students.begin(), students.end(), [](const StudentDeque& s){return s.final_grade < 5.00;});
    copy(students.begin() , bound, back_inserter(vargsiukai));
    students.erase(students.begin(), bound);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed_seconds =
        (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << to_string(num) + "  str 3 irasu dalijimas i deque: "<< elapsed_seconds << "s" << endl;


}
