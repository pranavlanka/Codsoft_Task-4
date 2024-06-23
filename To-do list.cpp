#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Task {
    string description;
    int priority;
    string dueDate;
};

vector<Task> todoList;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Add this line
    getline(cin, newTask.description);
    cout << "Enter task priority (1-5): ";
    cin >> newTask.priority;
    cout << "Enter task due date (dd/mm): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Add this line
    getline(cin, newTask.dueDate);
    todoList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (int i = 0; i < todoList.size(); i++) {
            cout << "Task " << i + 1 << ":" << endl;
            cout << "Description: " << todoList[i].description << endl;
            cout << "Priority: " << todoList[i].priority << endl;
            cout << "Due Date: " << todoList[i].dueDate << endl;
            cout << endl;
        }
    }
}

void deleteTask() {
    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= todoList.size()) {
        todoList.erase(todoList.begin() + taskNumber - 1);
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
