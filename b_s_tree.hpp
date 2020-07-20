
template<typename T>
typename Tree<T>::Iterator Tree<T>::begin() const{
    Tree<T>::Iterator begin;
    begin.pushRightChildToStack(this->m_root);
    return begin;
}

template<typename T>
typename Tree<T>::Iterator &Tree<T>::Iterator::operator=(const Tree::Iterator &other) {
    m_treeStack = other.m_treeStack;
    return *this;
}

template<typename T>
typename Tree<T>::Iterator &Tree<T>::Iterator::operator++() {
    Node* current = m_treeStack.top();
    m_treeStack.pop();

    if(current->m_right){
        pushRightChildToStack(current->m_right);
    }

    return *this;
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator++(int) {
    Tree<T>::Iterator temp = *this;
    ++this;
    return temp;
}

template<typename T>
bool Tree<T>::Iterator::operator==(const Tree::Iterator &other) const{
    return other.m_treeStack == m_treeStack;
}

template<typename T>
bool Tree<T>::Iterator::operator!=(const Tree::Iterator &other) const{
    return other.m_treeStack != m_treeStack;
}

template<typename T>
void Tree<T>::Iterator::pushRightChildToStack(Tree::Node *node) {

    while(node){
        m_treeStack.push(node);
        node = node -> m_left;
    }
}


template<class T>
void Tree<T>::insert(const T& val) {

    Node *newNode = new Node(val);

    if (!m_root) {
        m_root = newNode;
        return;
    }

    Node *trip = m_root;

    while ((val < trip->m_val && trip->m_left) || (val > trip->m_val && trip->m_right)) {
        val < trip->m_val ? trip = trip->m_left : trip = trip->m_right;
    }

    val < trip->m_val ? trip->m_left = newNode : trip->m_right = newNode;
}



template<class T>
void printBST(const Tree<T>& tree){

    for(Tree<int>::Iterator iter = tree.begin(); iter != tree.end(); ++iter){
        std::cout<<*iter <<" ";
    }
    std::cout << std::endl;
}