#ifndef INC_01_LAB__STUDENTS_H_
#define INC_01_LAB__STUDENTS_H_
#include <exception>
#include <algorithm>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <vector>
#include <iomanip>
#include <map>
#include <fstream>
#include <codecvt>
#include <regex>
#include <memory>
#include <unordered_set>
#include <set>
class Student {
 public:
  std::string surname;
  std::string name;
  std::string patronymic;
  std::string rank;
  int course;
  std::string id;

  Student(): surname(),name(),patronymic(),rank(),course(0),id(){}

  friend std::ostream &operator<<(std::ostream &out, const std::shared_ptr<Student> &arg) {
    std::string full = arg->surname + " " + arg->name + " " + arg->patronymic + " "
        + arg->rank + " "+ std::to_string(arg->course) + " kursa " + arg->id;
    out << full;
    return out;
  }
};

class Line
{
  std::string _data;

 public:
  friend std::istream& operator >> (std::istream& inputStream, Line& line)
  {
    std::getline(inputStream, line._data);
    return inputStream;
  }

  operator std::string() const { return _data; }
};

class Hash {
 public:
  std::size_t operator()(std::shared_ptr<Student> const &stud) const noexcept{
    std::string fullName = stud->surname + " " + stud->name + " "
        + " " + stud->patronymic;
    size_t result = 0;
    for (auto letter : fullName) {
      result += letter;
    }
    return result;
  }
};

class Compare {
 public:
  bool operator()(const std::shared_ptr<Student> &stud1, const std::shared_ptr<Student> &stud2) const {
    std::string fullName1 = stud1->surname + " " + stud1->name + " "
        + " " + stud1->patronymic;
    std::string fullName2 = stud2->surname + " " + stud2->name + " "
        + " " + stud2->patronymic;
    return fullName1 == fullName2;
  }
};

class Program
{
  auto CreateUnorderedSet(std::vector<std::shared_ptr<Student>> const students) {
    std::unordered_set<std::shared_ptr<Student>, Hash, Compare> result;
    for (auto stud : students) {
      result.insert(stud);
    }
    return result;
  }

 public:
  void Run()
  {
    auto lines = ReadAllLines("L1_ANSI.txt");
    auto lines2 = InformationRecovery(lines);
    auto students = Transformation(lines2);
    _smartPointers = SmartPointer(students);
    auto newStudents = Filtration(_smartPointers);
    auto newStudents2 = Sort(newStudents);
    ConsoleOutput(newStudents2);
    auto setStudents = CreateUnorderedSet(newStudents2);
    while(true)
    {
      std::string Surname;
      std::cout << "Enter the surname of the student."<<std::endl;
      std::cin >> Surname;

      std::string Name;
      std::cout << "Enter the name of the student."<<std::endl;
      std::cin >> Name;

      std::string Patronymic;
      std::cout << "Enter the patronymic of the student."<<std::endl;
      std::cin >> Patronymic;
      std::string FullName = Surname + " " + Name + " " + Patronymic;

      Student studentX;
      studentX.surname = Surname;
      studentX.name = Name;
      studentX.patronymic = Patronymic;
      auto data = setStudents.find(std::make_shared<Student>(studentX));
      if (data == setStudents.end()) {
        std::cout << "Mistake. The student is not listed."<<std::endl;
      } else {
        std::cout << (*data)->id << std::endl;
      }
    }
  }

 private:

  std::vector<std::shared_ptr<Student>> _smartPointers;

  std::vector<std::string> ReadAllLines(const std::string& filePath)
  {
    auto fileStream = std::ifstream(filePath);
    auto lines = ReadAllLines(fileStream);
    fileStream.close();
    return lines;
  }

  std::vector<std::string> ReadAllLines(std::istream& fileStream)
  {
    auto lines = std::vector<std::string>();
    std::copy(
        std::istream_iterator<Line, char>(fileStream),
        std::istream_iterator<Line, char>(),
        std::back_inserter(lines));
    return lines;
  }

  std::vector<std::string> InformationRecovery(std::vector<std::string>& lines){
    auto result = std::vector<std::string>();
    std::string str;
    std::regex regExpression(R"(^(\D+)\d+(\D+)\d+(\D+)\d+(\D+)\d+(\d)\D+(kursa)\d+(\d{8})$)");
    for (int kI = 0; kI < lines.size(); ++kI) {
      std::regex_replace(std::back_inserter(str), lines[kI].begin(),
                         lines[kI].end(), regExpression, "$1 $2 $3 $4 $5 $6 $7");
      result.push_back(str);
      str.clear();
    }
    return result;
  }

  std::vector<Student> Transformation(std::vector<std::string>& lines){
    auto result = std::vector<Student>();
    Student x;
    for (int kI = 0; kI <lines.size() ; ++kI) {
      std::stringstream ss;
      ss << lines[kI];
      ss >> x.surname >> x.name >> x.patronymic >>
      x.rank >> x.course;
      ss >> x.id;
      ss >> x.id;
      result.push_back(x);
    }
    return result;
  }

  std::vector<std::shared_ptr<Student>> SmartPointer(std::vector<Student>& students){
    std::vector<std::shared_ptr<Student>> result;
    for (auto & line : students) {
      result.push_back(std::make_shared<Student>(line));
    }
    return result;
  }
  std::vector<std::shared_ptr<Student>> Filtration(std::vector<std::shared_ptr<Student>> students) {
    int courseNumber;
    std::cout << "Enter the minimum allowed course number: " << std::endl;
    std::cin >> courseNumber;
    auto end = std::remove_if(students.begin(), students.end(),
                              [courseNumber](const std::shared_ptr<Student> &ptr) {
                                return (ptr->course < courseNumber);
                              });
    students.erase(end, students.end());
    return students;
  }

  std::vector<std::shared_ptr<Student>> Sort(std::vector<std::shared_ptr<Student>> students) {
    std::sort(students.begin(), students.end(),
              [](const std::shared_ptr<Student> &ptr1, const std::shared_ptr<Student> &ptr2) {
                if (ptr1->surname == ptr2->surname) {
                  if (ptr1->name == ptr2->name){
                    return ptr1->patronymic < ptr2->patronymic;
                  } else {
                    return ptr1->name < ptr2->name;
                  }
                } else {
                  return ptr1->surname < ptr2->surname;
                }
              });
    return students;
  }

  void ConsoleOutput(std::vector<std::shared_ptr<Student>> const students){
    std::copy(students.begin(), students.end(),
              std::ostream_iterator<std::shared_ptr<Student>>(std::cout, "\n"));
  }


};
#endif //INC_01_LAB__STUDENTS_H_
