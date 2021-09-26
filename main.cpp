/** cs124 project2 by Eyu on 6/7/21 */

#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include "Course.h"
#include "Stack.h"
#include "Queue.h"

/**
 * Main
 */
int main() {

        //queue test for integer object
        Queue<int> queue = Queue<int>();
        assert(!queue.find(13));
        assert(queue.isEmpty());
        queue.push(13);
        assert(queue.find(13));
        assert(!queue.isEmpty());
        queue.push(7);
        assert(queue.pop() == 13);
        assert(queue.pop() == 7);
        assert(queue.isEmpty());
        queue.push(2021);
        queue.push(6);
        queue.print();


    std::cout << std::endl;


        //queue test for string object
        Queue<std::string> queue2 = Queue<std::string>();
        assert(!queue2.find("CLion"));
        assert(queue2.isEmpty());
        queue2.push("Clion");
        assert(queue2.find("Clion"));
        assert(!queue2.isEmpty());
        queue2.push("Java");
        assert(queue2.pop() == "Clion");
        assert(queue2.pop() == "Java");
        assert(queue2.isEmpty());
        queue2.push("Pycharm");
        queue2.push("VS Code");
        queue2.print();


    std::cout << std::endl;


        // read the csv file
        std::vector<Course> course;
        std::string fn = "../uvm_fall2021_courses.csv";

        if (loadFromFile(fn, course)) {
            std::cout << course.size()
                      << " records read from file" << std::endl;
        } else {
            std::cout << "Something went wrong." << std::endl;
        }

        // queue test for Course object
        /**
         * push 10 objects into queue
         * pop them out onto the stack
         * take the 10 objects from queue
         * pop them out and print
         **/
        Queue<Course> queueCourse = Queue<Course>();
        Stack<Course> stackCourse = Stack<Course>();
        for (int i = 0; i <= 9; i += 1) {
            queueCourse.push(course.at(i));
        }
        queueCourse.print();
        std::cout << std::endl;
        for (int i = 0; i <= 9; i += 1) {
            stackCourse.push(queueCourse.pop());
        }
        stackCourse.print();


    return 0;
}