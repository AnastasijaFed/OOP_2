//
// Created by Anastasija Fedorenko on 2025-03-28.
//

#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H
#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <iomanip>
using namespace std;

    class StudentClass {
        public:
          string name;
          string surname;
          string getName(){return name;}
          string getSurname(){return surname;}
          const void setName(string name){this->name = name;}
          const void setSurname(string surname){this->surname = surname;}
          const vector<uint8_t> getGrades(){return grades;}
          const uint8_t getExamGrades(){return exam_grade;}
          const void setExamGrades(uint8_t grade){this->exam_grade = grade;}
          const void setGrades(vector<uint8_t> grades){this->grades = grades;}
          const void setFinalGrade(double finalGrade){this->final_grade = finalGrade;}
          const double getFinalGrade(){return final_grade;}
          double average(StudentClass &student);
          double median(StudentClass &student);
          void calculateFinalGradesAverage(StudentClass &student);


          StudentClass();
          StudentClass(string name, string surname, vector<uint8_t> grades, uint8_t exam_grade, double finalGrade){
            this->name = name;
            this->surname = surname;
            this->grades = grades;
            this->exam_grade = exam_grade;
            this->final_grade = finalGrade;

            }
            ~StudentClass();


       private:
        std::vector<uint8_t> grades;
        uint8_t exam_grade;
        mutable double final_grade;
    };



#endif //STUDENTCLASS_H
