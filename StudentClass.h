//
// Created by Anastasija Fedorenko on 2025-03-28.
//

#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H
#include <string>
#include <vector>


class StudentClass {
    public:
      std::string name;
      std::string surname;
    private:
    std::vector<uint8_t> grades;
    uint8_t exam_grade;
    mutable double final_grade;
};



#endif //STUDENTCLASS_H
