//
// Created by Anastasija Fedorenko on 2025-05-05.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST(StudentClassTest, AverageCalculation) {
    StudentClass student;
    student.setGrades({10, 8, 6, 4, 2});
    EXPECT_DOUBLE_EQ(StudentClass::averageClass(student), 6.0);
}

TEST(StudentClassTest, MedianCalculationOdd) {
    StudentClass student;
    student.setGrades({5, 1, 9});
    EXPECT_DOUBLE_EQ(StudentClass::medianClass(student), 5.0);
}

TEST(StudentClassTest, MedianCalculationEven) {
    StudentClass student;
    student.setGrades({4, 2, 8, 6});
    EXPECT_DOUBLE_EQ(StudentClass::medianClass(student), 5.0);  // (4+6)/2
}

TEST(StudentClassTest, FinalGradeWithAverage) {
    StudentClass student;
    student.setGrades({10, 10, 10});
    student.setExamGrades(5);
    StudentClass::calculateFinalGradesAverageClass(student);
    EXPECT_DOUBLE_EQ(student.getFinalGrade(), 0.4 * 10 + 0.6 * 5);  // 7.0
}

TEST(StudentClassTest, FinalGradeWithMedian) {
    StudentClass student;
    student.setGrades({6, 6, 6, 6});
    student.setExamGrades(10);
    double finalGrade = StudentClass::calculateFinalGradesMedianClass(student);
    EXPECT_DOUBLE_EQ(finalGrade, 0.4 * 6 + 0.6 * 10);  // 8.4
}

