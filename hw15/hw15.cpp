#include <iostream>

const int SIZE = 4;
const int MAX_MARK = 5;

// 1
struct Student
{
    std::string name;
    unsigned marks[SIZE];
};

// 2
double calculateAverageMark(const Student& student)
{
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        sum += student.marks[i];
    }

    return static_cast<double>(sum) / SIZE;
}

// 3
void bubbleSortStudentsByAverageMark(Student* students, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (calculateAverageMark(students[j]) < calculateAverageMark(students[j + 1]))
            {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}

// 4
Student* findTopStudent(Student* students, int size)
{
    if (size <= 0)
        return nullptr;

    Student* topStudent = &students[0];
    double topAverageMark = calculateAverageMark(*topStudent);

    for (int i = 1; i < size; i++)
    {
        double currentAverageMark = calculateAverageMark(students[i]);
        if (currentAverageMark > topAverageMark)
        {
            topAverageMark = currentAverageMark;
            topStudent = &students[i];
        }
    }

    return topStudent;
}

// 5
int countHighPerformingStudents(Student* students, int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (calculateAverageMark(students[i]) > (0.75 * MAX_MARK))
        {
            count++;
        }
    }

    return count;
}



int main()
{
    // 1
    Student student1{ "Anton", {4, 5, 3, 2 } };
    Student student2{ "Vika", {3, 3, 3, 5} };
    Student student3{ "Dima", {5, 5, 5, 5} };
    std::cout << "Average mark: " << calculateAverageMark(student1);

    // 2
    const int numStudents = 3;
    Student students[numStudents] = {
        {"Anton", {4, 5, 3, 2}},
        {"Vika", {3, 3, 4, 5}},
        {"Dima", {5, 5, 5, 5}}
    };
    for (int i = 0; i < numStudents; i++)
    {
        std::cout << "Average mark for " << students[i].name << ": " << calculateAverageMark(students[i]) << std::endl;
    }

    // 3
    bubbleSortStudentsByAverageMark(students, numStudents);
    std::cout << "Sorted Students by Average Mark:\n";
    for (int i = 0; i < numStudents; i++)
    {
        std::cout << students[i].name << ": " << calculateAverageMark(students[i]) << std::endl;
    }

    // 4
    Student* topStudent = findTopStudent(students, numStudents);

    if (topStudent != nullptr)
    {
        std::cout << "Top Student: " << topStudent->name << " with average mark " << calculateAverageMark(*topStudent) << std::endl;
    }

    // 5
    int highPerformingCount = countHighPerformingStudents(students, numStudents);

    std::cout << "Number of High-Performing Students: " << highPerformingCount << std::endl;

}
