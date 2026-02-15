template <typename T>
DoublyList<T>::DoublyList() {
    header = new Node();
    trailer = new Node();
    header->next = trailer;
    trailer->prev = header;
    this->length = 0;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& other) {
    header = new Node();
    trailer = new Node();
    header->next = trailer;
    trailer->prev = header;
    this->length = 0;
    copy(other);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& other) {
    Node* curr = other.header->next;
    while (curr != other.trailer) {
        append(curr->value);
        curr = curr->next;
    }
}

template <typename T>
typename DoublyList<T>::Node* DoublyList<T>::getNode(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("position out of bounds");
    }

    Node* curr = header->next;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    return curr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    Node* last = trailer->prev;
    Node* n = new Node(elem, trailer, last);

    last->next = n;
    trailer->prev = n;

    this->length++;
}

template <typename T>
void DoublyList<T>::clear() {
    Node* curr = header->next;
    while (curr != trailer) {
        Node* doomed = curr;
        curr = curr->next;
        delete doomed;
    }
    header->next = trailer;
    trailer->prev = header;
    this->length = 0;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    return getNode(position)->value;
}

template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}

template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("insert: error, position out of bounds");
    }

    Node* after = (position == this->length) ? trailer : getNode(position);
    Node* before = after->prev;

    Node* n = new Node(elem, after, before);
    before->next = n;
    after->prev = n;

    this->length++;
}

template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    Node* doomed = getNode(position);

    doomed->prev->next = doomed->next;
    doomed->next->prev = doomed->prev;

    delete doomed;
    this->length--;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    getNode(position)->value = elem;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    Node* curr = header->next;
    while (curr != trailer) {
        if (curr->value == elem) return true;
        curr = curr->next;
    }
    return false;
}

template <typename T>
ostream& operator<<(ostream& out, const DoublyList<T>& list) {
    if (list.isEmpty()) {
        out << "List is empty, no elements to display.\n";
        return out;
    }

    typename DoublyList<T>::Node* curr = list.header->next;
    while (curr != list.trailer) {
        out << curr->value;
        if (curr->next != list.trailer) out << " <-> ";
        curr = curr->next;
    }
    out << endl;
    return out;
}
