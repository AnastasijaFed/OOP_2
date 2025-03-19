//
// Created by Anastasija Fedorenko on 2025-03-12.
//

#ifndef STUDENTDEQUE_H
#define STUDENTDEQUE_H

#include <deque>
#include <string>
using namespace std;

struct StudentDeque {
    std::string name;
    std::string surname;
    std::deque<double> grades;
    int exam_grade;
    mutable double final_grade;

};

deque<StudentDeque> readFileDeque(int num);

double averageDeque(const StudentDeque &student);
void calculateFinalGradesAverageDeque(const StudentDeque &student);
void sortDeque(deque<StudentDeque>& students, int num);
void splitToGroupsDeque(deque<StudentDeque>& students, deque<StudentDeque>& kietekai, deque<StudentDeque>& vargsiukai, int num);
void strategyTwoDeque(deque<StudentDeque>& students, deque<StudentDeque>& vargsiukai, int num);
void strategyThreeDeque(deque<StudentDeque>& students, deque<StudentDeque>& vargsiukai, int num);


#endif //STUDENTDEQUE_H
