class Array {
    private:
        int *items;
        int count=0;
        void resize();
        bool isFull();
        bool isEmpty();

    public:
        Array() { items = new int[count]; }
        void insert(int item);
        void insertAt(int item, int index);
        void remove();
        void removeAt(int index);
        void reverse();
        void print();
        int indexOf(int item);
        Array intersect(Array other);
};