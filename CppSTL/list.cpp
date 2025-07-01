
template<class T>
struct Node{
    Node<T>* pre;
    Node<T>* next;
    T node;
    Node(T val){
        node = val;
        pre = next = null;
    }
    Node<T>* insertNext(T val){
        auto cur  = new Node<T>(val);
        cur->next = this->next;
        this->next->pre = cur;
        cur->pre = this;
        this->next = cur;
    }
    Node<T>* insertPre(T val){
        auto cur = new Node<T>(val);
        cur->pre = this->pre;
        this->pre->next = cur;
        cur->next = this;
        this->pre = cur;
    }
    void removeNext(){
        if(this->next==null){
            throw new out_of_range("Your visit to %s out of range",typeof(Node<T>));
        }
        auto cur = this->next;
        if(this->next->next!=null){
            this->next->next->pre=this;
        }
        this->next=this->next->next;
        delete cur;
    }
    void removePre(){
        if(this->next==null){
            throw new out_of_range("Your visit to %s out of range",typeof(Node<T>));
        }
        auto cur = this->pre;
        if(this->pre->pre!=null){
            this->pre->pre->next=this;
        }
        this->pre=this->pre->pre;
        delete cur;
    }
}

template<class T>
struct list{
    const int N = 1e5+100;
    Node<T>* head,end;
    list(T val){
        end = head = new Node<T>(val);
    }

    void push_back(T val){
        end = end->insertNext();
    }

    void push_front(T val){
        head = head->insertFront();
    }

    const T& operator[](int val){
        return ;
    }

    list<T> 
}