void bubble_sort (vector <int> &v)
{
    int n = v.size();
    int s;
    
    for(int j = n-1; j>0; j--)
    {
        s=0;
        for(int i = 0; i<j; i++)
        {
            if (v[i] > v[i+1])
            {
                swap(v[i] , v[i+1]);
                s++;
            }
        }
        if (s==0) return;
    }
        
}

void quick_sort(vector<int> &v, int start, int end)
{
    if(start>=end) return;
    swap(v[random(start, end)],v[end]);

    int pivet  = end, p1 =start, p2 = end-1;

    while (p2>p1)
    {
        if (v[p1] <= v[pivet])p1++;
        else if (v[p2] > v[pivet])p2--;
        else if (v[p1] > v[pivet] && v[p2] <= v[pivet]) swap(v[p1++],v[p2--]);
    }
    if (v[p1]>v[pivet] && p1<pivet) swap(v[p1],v[pivet]);
    else p1++;

    quick_sort(v, start, p1-1); quick_sort(v, p1, end);
}



void merge_sort(vector<int> &v, int start, int end)
{
    if(start==end) return;

    int mid = (start+end)/2;
    merge_sort(v,  start,  mid);  merge_sort(v,  mid+1,  end);

    vector<int> temp(end-start+1,0);
    int p1=start, p2 = mid+1,i=0;

    fori(end-start+1)
    {
        if ((p2==end+1 || v[p1]<= v[p2] ) && p1!=mid+1)  temp[i] = v[p1++];
        else temp[i] = v[p2++];
    }

    for(int i = start; i<= end;i++ ) v[i] = temp[i-start];
}


class Node
{
    private:
        int value;
        Node* next;

        Node()
        {
            this->value = 0;
            this->next = nullptr;
        }
        Node(int value)
        {
            this->value = value;
            this->next = nullptr;
        }

        ~Node()
        {
            this->next = nullptr;
        }

        friend class LinkedList;
};


class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        this->head = nullptr;
    }
    LinkedList(int x)
    {
        this->head = new Node(x);
    }
    bool empty ()
    {
        return this->head == nullptr;
    }


    void push_front(int d)
    {
        Node* n = new Node(d);
        n->next = this->head;
        this->head = n;
    }
    void pop_front()
    {
        if (empty()) return;

        Node* n = this->head;
        this->head = this->head->next;
        delete n;
    }

    void push_back(int d)
    {
        if (empty()) push_front( d);
        else
        {
            Node* add = new Node(d);
            Node* n = this->head;
            while (n->next!= nullptr) n = n->next;
            n->next = add;
        }
    }

    void pop_back()
    {
        if (empty()) return;

        Node* p1 = this->head;
        Node* p0=new Node();
        while (p1->next!= nullptr)
        {
            p0 = p1;
            p1 = p1->next;
        }
        if (p1 == this->head) this->head = nullptr;
        else delete p1;
        p0->next = nullptr;
    }
    void print()
    {
        if (empty()) cout<<"empty"<<endl;
        else
        {
            Node* n = this->head;
            do
            {
                cout<<n->value<<' ';
                n = n->next;
            } while (n != nullptr) ;
        }
    }
    void foo(Node * n)
    {
        if (n == nullptr) return;
        foo(n->next);
        cout<<n->value<<' ';
    }

    void print_reverse()
    {
        if (empty()) cout<<"empty"<<endl;
        else foo(this->head);
    }



    bool contains (int d)
    {
        if (empty()) return false;

        Node* n = this->head;
        do
        {
            if (n->value == d )return true;
            n = n->next;
        } while (n != nullptr) ;

        return false;
    }

    void  clear()
    {
        while (!empty()) this->pop_front();
    }

    void  bubblesort()
    {
        if (empty() || this->head->next == nullptr) return;

        int c = 1;
        while (c)
        {
            c = 0;
            Node* p1 = this->head;
            Node* p2 = p1->next;

            while (p2 != nullptr)
            {
                if (p1->value > p2->value) swap(p1->value , p2->value),c++;
                p1 = p1->next;
                p2 = p2->next;
            }
        }

    }

    ~LinkedList()
    {
        clear();
    }
}
