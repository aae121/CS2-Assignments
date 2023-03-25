// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Appointment
{
    int hours;
    int mins;
};
class Person 
{
    protected: string name;
         string id;
         int age;

    public: Person(){}
      Person ( string n, string i, int a) : name(n), id(i), age(a) {}

      void setName(string n) { name = n; }
      void setID(string i) { id = i; }
      void setAge(int a) { age = a; }

      string getName() { return name; }
      string getID() { return id; }
      int getAge() { return age; }

      virtual void printInfo() = 0;
};

class Customer : public Person
{
private:
    int mechanicID;
    Appointment appointment;

public:
    Customer() {}
    Customer(string n, string i, int a, int mID, Appointment appt) : Person(n, i, a), mechanicID(mID), appointment(appt) {}
    void setMechanicID(int mID) {
        mechanicID = mID;
    }
    void setAppointment(Appointment appt) {
        appointment = appt;
    }
    int getMechanicID() {
        return mechanicID;
    }
    Appointment getAppointment() {
        return appointment;
    }
    bool operator<( Customer& other) 
    {
        if (appointment.hours < other.appointment.hours)
            return true;
        else if (appointment.hours > other.appointment.hours)
            return false;
        else
            return (appointment.mins < other.appointment.mins);
    }

    bool operator>( Customer& other) 
    {
        if (appointment.hours > other.appointment.hours)
            return true;
        else if (appointment.hours < other.appointment.hours)
            return false;
        else
            return (appointment.mins > other.appointment.mins);
    }

    bool operator==( Customer& other) 
    {
        return ((appointment.hours == other.appointment.hours) && (appointment.mins == other.appointment.mins));
    }

    void printInfo() override
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Mechanic ID: " << mechanicID << endl;
        cout << "Appointment: " << appointment.hours << ":" << appointment.mins << endl;
    }

    class Mechanic : public Person
    {
    private: int counter;
    public: 
        Mechanic(){}
        Mechanic(string n, string i, int a, int c) : Person(n, i, a), counter(c)
          {}
          void setCounter(int c) { counter = c; }
          int getCounter() { return counter; }

          bool isAvailable(Appointment appt)
          {
              if (counter >= 5)
                  return false;
              time_t now = time(nullptr);
              tm* ltm = localtime(&now);
              if ((appt.hours < ltm->tm_hour) || ((appt.hours == ltm->tm_hour) && (appt.mins < (ltm->tm_min + 30))))
                  return false;

              return true;
          }
       
          };


          template <typename T>
          class MyQueue {
          private:
              queue<T> q;

          public:
              void push(T val) {
                  q.push(val);
              }

              void pop() {
                  if (!q.empty()) {
                      q.pop();
                  }
              }

              T front() {
                  return q.front();
              }

              bool empty() {
                  return q.empty();
              }

              int size() {
                  return q.size();
              }
          };


};
using namespace std;
int main()
{

    vector<Mechanic> mechanics;
    int numMechanics;
    cout << "Enter the number of mechanics: ";
    cin >> numMechanics;
    for (int i = 0; i < numMechanics; ++i)
    {
        string name, id;
        int age, counter;
        cout << "Mechanic " << i + 1 << ":\\n";
        cout << "Name: ";
        cin >> name;
        cout << "ID: ";
        cin >> id;
        cout << "Age: ";
        cin >> age;
        cout << "Appointment Counter: ";
        cin >> counter;

        Mechanic m(name, id, age, counter);
        mechanics.push_back(m);
    }

    vector<Customer> customers;
    int numCustomers;
    cout << "Enter the number of customers: ";
    cin >> numCustomers;
    for (int i = 0; i < numCustomers; ++i)
    {
        std::string name, id;
        int age, mechanicID, hours, mins;
        cout << "Customer " << i + 1 << ":\\n";
        cout << "Name: ";
        cin >> name;
        cout << "ID: ";
        cin >> id;
        cout << "Age: ";
        cin >> age;
        cout << "Mechanic ID: ";
        cin >> mechanicID;
        cout << "Appointment Time (hours mins): ";
        cin >> hours >> mins;

        Appointment appt = { hours, mins };
        Customer c(name, id, age, mechanicID, appt);
        customers.push_back(c);
    }


    MyQueue<Customer> customerQueue;
    for (auto& c : customers)
    {
        bool foundMechanic = false;
        for (auto& m : mechanics)
        {
            if (m.isAvailable(c.getAppointment()))
            {
                c.setMechanicID(m.getID());
                m.setCounter(m.getCounter() + 1);
                foundMechanic = true;
                break;
            }
        }
    }


    while (!customerQueue.empty())
    {
        Customer c = customerQueue.front();
        customerQueue.pop();
        cout << "Customer:\\n";
        c.printInfo();
        cout << "Mechanic:\\n";
        for (auto& m : mechanics)
        {
            if (m.getID() == c.getMechanicID())
            {
                m.printInfo();
                break;
            }
        }
        cout << endl;
    }

    return 0;
}
