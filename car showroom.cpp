#include <iostream>
#include <string>
using namespace std;

struct Car {
    int id;
    string model;
    string brand;
    float price;
    Car* next;
};

class CarShowroom {
private:
    Car* top;
    int carsSold;

public:
    CarShowroom() {
        top = NULL;
        carsSold = 0;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int id, string model, string brand, float price) {
        Car* newCar = new Car;
        newCar->id = id;
        newCar->model = model;
        newCar->brand = brand;
        newCar->price = price;
        newCar->next = top;
        top = newCar;
        cout << "Car added successfully.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Showroom is empty! No car to remove.\n";
            return;
        }
        Car* temp = top;
        cout << "Selling car: " << top->brand << " " << top->model << endl;
        top = top->next;
        delete temp;
        carsSold++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Showroom is empty!\n";
            return;
        }
        cout << "\nTop Car in Showroom:\n";
        cout << "ID: " << top->id << "\nModel: " << top->model
             << "\nBrand: " << top->brand << "\nPrice: $" << top->price << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No cars in the showroom.\n";
            return;
        }
        cout << "\nCars in Showroom (Top to Bottom):\n";
        Car* temp = top;
        int count = 1;
        while (temp != NULL) {
            cout << count++ << ". ID: " << temp->id
                 << ", Model: " << temp->model
                 << ", Brand: " << temp->brand
                 << ", Price: $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void searchCar() {
        if (isEmpty()) {
            cout << "Showroom is empty!\n";
            return;
        }
        int choice;
        cout << "\nSearch by:\n1. Car ID\n2. Car Brand\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        bool found = false;
        Car* temp = top;

        if (choice == 1) {
            int id;
            cout << "Enter Car ID: ";
            cin >> id;
            while (temp != NULL) {
                if (temp->id == id) {
                    found = true;
                    cout << "\nCar Found:\nID: " << temp->id
                         << "\nModel: " << temp->model
                         << "\nBrand: " << temp->brand
                         << "\nPrice: $" << temp->price << endl;
                    break;
                }
                temp = temp->next;
            }
        } 
        else if (choice == 2) {
            string brand;
            cout << "Enter Car Brand: ";
            getline(cin, brand);
            cout << "\nCars of Brand '" << brand << "':\n";
            while (temp != NULL) {
                if (temp->brand == brand) {
                    found = true;
                    cout << "ID: " << temp->id << ", Model: " << temp->model
                         << ", Price: $" << temp->price << endl;
                }
                temp = temp->next;
            }
        }
        if (!found)
            cout << "No matching car found.\n";
    }

    void showSales() {
        cout << "\nCars Sold: " << carsSold << endl;
    }

    ~CarShowroom() {
        while (!isEmpty()) {
            Car* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    CarShowroom showroom;
    int choice;

    do {
        cout << "\n--- Car Showroom Management System ---\n";
        cout << "1. Add Car\n2. Remove (Sell) Car\n3. Display Cars\n4. Show Top Car\n"
             << "5. Search Car\n6. Show Sales Stats\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id;
        string model, brand;
        float price;

        switch (choice) {
        case 1:
            cout << "Enter Car ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Car Model: ";
            getline(cin, model);
            cout << "Enter Car Brand: ";
            getline(cin, brand);
            cout << "Enter Car Price: ";
            cin >> price;
            showroom.push(id, model, brand, price);
            break;
        case 2:
            showroom.pop();
            break;
        case 3:
            showroom.display();
            break;
        case 4:
            showroom.peek();
            break;
        case 5:
            showroom.searchCar();
            break;
        case 6:
            showroom.showSales();
            break;
        case 7:
            cout << "Exiting system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
