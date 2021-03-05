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
void Market::print(vector<T> *list,  int length, int from) {
    int size = (*list).size();
    if (from < size) {
        length = length < size - from ? length: size - from;
        for (int i = from; i < length; i++) {
            (*list).at(i).printInfo();
        }
    } else {
        cout << "From index <" << from << "> is out of bound. size of list <" << (*list).size() << ">" << endl;
    }
}