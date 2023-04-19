int main() {
    vector<int> v;
    int n, firstValue, secondValue;
    cout << "Enter number of integers: ";
    cin >> n;
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    cout << "Enter first value and second value to insert: ";
    cin >> firstValue >> secondValue;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == firstValue) {
            v.insert(v.begin() + i + 1, secondValue);
            i++;
        }
    }
    LinkedList list;
    for (int i = 0; i < v.size(); i++) {
        int count = 1;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] == v[j]) {
                count++;
            }
        }
        list.addNode(v[i], count);
    }
    cout << "Linked List: ";
    list.printList();
    cout << "Sum of all nodes: " << list.sumNodes() << endl;
    return 0;
}