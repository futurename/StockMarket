#include <iomanip>

template<typename T>
void Market::addOne(vector<T> *list, T &t) {
    list->push_back(t);
}

template<typename T>
void Market::removeOne(vector<T> *list, int uniqueId) {
    bool found = false;
    for (int i = 0; i < list->size(); i++) {
        if (list->at(i).getUniqueId() == uniqueId) {
            list->erase(list->begin() + i);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No such item id [" << uniqueId << "] can be found!" << endl;
    }
}

template<typename T>
void Market::print(vector<T> *list, int length, int from) {
    int size = (*list).size();
    if (length <= 0) {
        length = size;
    }

    string name = (*list).at(0).getName();
    int titleWidth = name == "Stock"? 36 : 17;

    if (from < size) {
        length = length < size - from ? length : size - from;
        cout << setw(titleWidth) << setfill('*') << "" << " " << name
             << " " << setw(titleWidth) << setfill('*') << "" << endl;
        cout << setfill(' ');
        for (int i = from; i < length; i++) {
            (*list).at(i).printInfo();
        }
    } else {
        cout << "From index <" << from << "> is out of bound. size of list <" << (*list).size() << ">" << endl;
    }
    cout << endl;
}