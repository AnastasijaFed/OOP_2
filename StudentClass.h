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
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

    class StudentClass {
        public:


            string getName()const{return name;}
            string getSurname()const{return surname;}
            const void setName(const string name){this->name = name;}
            const void setSurname(const string surname){this->surname = surname;}
            const vector<double> getGrades()const{return grades;}
            const double getExamGrades()const{return exam_grade;}
            const void setExamGrades(const double grade){this->exam_grade = grade;}
            const void setGrades(const vector<double> grades){this->grades = grades;}
            void clearGrades(){this->grades.clear();}
            const void setFinalGrade(const double finalGrade){this->final_grade = finalGrade;}
            const double getFinalGrade()const{return final_grade;}
            vector<StudentClass> addStudentsObjects(vector<StudentClass> students);
            double averageClass(StudentClass &student);
            double medianClass(StudentClass &student);
          double calculateFinalGradesMedianClass(StudentClass &student);
            void calculateFinalGradesAverageClass(StudentClass &student);
          void printStudentListClass(vector<StudentClass> &students);
            void generateGradesClass(vector<StudentClass> &students);
        vector<string> loadFromFileClass(const string &filename);
      void writeStudentsToFile(const vector<StudentClass>& students, const string& filename);
          vector<StudentClass> readStudentsFileClass(const string &filename);
        vector<StudentClass> generateRandomStudentsClass(int count);
          vector<StudentClass> testClass();
        bool compareByNameClass(StudentClass a, StudentClass b);
        bool compareBySurnameClass(StudentClass a, StudentClass b);
        bool compareByAverageClass(StudentClass a, StudentClass b);
        vector<StudentClass> sortByNameClass(vector<StudentClass> students);
        vector<StudentClass> sortBySurnameClass(vector<StudentClass> students);
        vector<StudentClass> sortByAverageClass(vector<StudentClass> students);
        void logDuration(const string& message, const std::chrono::high_resolution_clock::time_point& start, const std::chrono::high_resolution_clock::time_point& stop);
        void generateStudentsFileClass(int numberOfStudents);
        void sortStudentsInFileClass(vector<StudentClass>& students,int numberOfStudents);
        void strategyTwoVectorClass(vector<StudentClass>& students, vector<StudentClass>& vargsiukai, int num);
        void strategyThreeVector(vector<StudentClass>& students, vector<StudentClass>& vargsiukai, int num);




          StudentClass();
          StudentClass(string name, string surname, vector<double> grades, double exam_grade, double finalGrade){
            this->name = name;
            this->surname = surname;
            this->grades = grades;
            this->exam_grade = exam_grade;
            this->final_grade = finalGrade;

            }
            ~StudentClass();

          StudentClass(const StudentClass &student) {
            this->name = student.name;
            this->surname = student.surname;
            this->grades = student.grades;
            this->exam_grade = student.exam_grade;
            this->final_grade = student.final_grade;
          }

      StudentClass& operator=(const StudentClass &student) {
            if (this == &student) {
              return *this;
            }
            this->name = student.name;
            this->surname = student.surname;
            this->grades = student.grades;
            this->exam_grade = student.exam_grade;
            this->final_grade = student.final_grade;

            return *this;

          }
      StudentClass(StudentClass&& student) noexcept
        : name(std::move(student.name)),
          surname(std::move(student.surname)),
          grades(std::move(student.grades)),
          exam_grade(student.exam_grade),
          final_grade(student.final_grade)       {}

      friend std::ostream& operator<<(std::ostream& os, const StudentClass& student) {
            os << student.name << " " << student.surname << " " << student.final_grade;
            return os;
          }
      friend std::istream& operator>>(std::istream& is, StudentClass& student) {
            std::cout << "Vardas: ";
            is >> student.name;

            std::cout << "Pavardė: ";
            is >> student.surname;

            int grades_number;
            std::cout << "Kiek tarpinių pažymių (už namų darbus) norite įvesti?: ";
            is >> grades_number;
            while (is.fail() || grades_number < 0) {
              std::cout << "Neteisinga įvestis. Įveskite teigiamą skaičių: ";
              is.clear();
              is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              is >> grades_number;
            }

            std::vector<double> tempGrades;
            if (grades_number > 0) {
              std::cout << "Pažymiai: ";
              for (int i = 0; i < grades_number; i++) {
                int grade;
                is >> grade;
                while (is.fail() || grade < 0 || grade > 10) {
                  std::cout << "Neteisinga įvestis. Įveskite skaičių nuo 0 iki 10: ";
                  is.clear();
                  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                  is >> grade;
                }
                tempGrades.push_back(grade);
              }
            }

            student.setGrades(tempGrades);

            std::cout << "Egzamino pažymys: ";
            is >> student.exam_grade;

            student.calculateFinalGradesAverageClass(student);

            return is;
          }







       private:
        string name;
        string surname;
        std::vector<double> grades;
        double exam_grade;
        mutable double final_grade;
    };



#endif //STUDENTCLASS_H
