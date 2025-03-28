//
// Created by Anastasija Fedorenko on 2025-03-28.
//

#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H
#include <string>
#include <vector>
using namespace std;

class StudentClass {
    public:
      string name;
      string surname;
      string getName(){return name;}
      string getSurname(){return surname;}
      void setName(string name){this->name = name;}
      void setSurname(string surname){this->surname = surname;}
      vector<uint8_t> getGrades(){return grades;}
      void setGrades(vector<uint8_t> grades){this->grades = grades;}
      void setFinalGrade(double finalGrade){this->final_grade = finalGrade;}
      double getFinalGrade(){return final_grade;}


   private:
    std::vector<uint8_t> grades;
    uint8_t exam_grade;
    mutable double final_grade;
};



#endif //STUDENTCLASS_H
