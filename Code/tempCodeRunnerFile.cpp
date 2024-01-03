class RegistrationTable {
public:
    Student* student;
    Course* course;
    time_t registrationTime;

    RegistrationTable(Student* s, Course* c) : student(s), course(c) {
        registrationTime = time(0); // Lấy thời gian hệ thống
    }
};