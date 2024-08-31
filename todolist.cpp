#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayMenu() {
    cout << "-----------------------" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Display all tasks" << endl;
    cout << "3. Delete a task" << endl;
    cout << "4. Exit" << endl;
    cout << "-----------------------" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task: ";
    cin.ignore(); // To ignore the leftover newline character in the input buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added!" << endl;
}

void displayTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Your tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted!" << endl;
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
