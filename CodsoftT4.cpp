#include <iostream>
#include <bits/stdc++.h>


using namespace std;

struct Task {

     string description;
     bool completed;
};

void displayTasks(const vector<Task>& tasks) {
    cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {

        cout << i + 1 << ". [" << (tasks[i].completed ? "x" : " ") << "] " << tasks[i].description << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    cout << "Simple To-Do List Manager\n";
    while (true) {
         cout  <<  "\nOptions:\n";
         cout  << "1. Add Task\n";
         cout  << "2. View Tasks\n";
         cout  << "3. Mark Task as Completed\n";
         cout  << "4. Remove Task\n";
         cout  << "5. Exit\n";
         cout  << "Enter your choice: ";
         cin   >> choice;
         cin.ignore(); // Clear newline character from input buffer

        if (choice == 1) {
            Task newTask;
            cout << "Enter task description: ";
            getline (cin, newTask.description);
            newTask.completed  = false;
            tasks.push_back(newTask);


        } else if (choice == 2) {
            displayTasks(tasks);


        } else if (choice == 3) {
            size_t index;
            cout << "Enter the task number to mark as completed: ";
            cin >> index;


            if (index >= 1 && index <= tasks.size()) {
                tasks[index - 1].completed = true;
                cout << "Task marked as completed." << endl;


            } else {
                cout << "Invalid task number!" << endl;

            }
        } else if (choice == 4) {
            size_t index;
            cout << "Enter the task number to remove: ";
            cin >> index;

            if (index >= 1 && index <= tasks.size()) {
                tasks.erase(tasks.begin() + index - 1);
                cout << "Task removed successfully." << endl;

            } else {
                cout << "Invalid task number!" << endl;
            }
        } 
          
          else if (choice == 5) {
            cout << "Exiting..." << endl;
            break;

        } else {
            cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    }
    return 0;
}
