template<typename T = int>
struct FenwickTree {
    int N;
    T *values;

    FenwickTree(int N) {
        this->N = N;
        values = new T[N+5];

        for(int i = 1; i <= N; i++) values[i] = 0;
    }

    void increase(int index, T add) {
        while(index <= N) {
            values[index] += add;
            index += (index & -index);
        }
    }

    void update(int index, T new_value) {
        increase(index, new_value - readSingle(index));
    }

    T read(int index) {
        T sum = 0;

        while(index > 0) {
            sum += values[index];
            index -= (index & -index);
        }

        return sum;
    }

    T readSingle(int index){
        T sum = values[index];
        if(index > 0) {
            int z = index - (index & -index);
            index--;
            while(index != z) {
                sum -= values[index];
                index -= (index & -index);
            }
        }
        return sum;
    }

    T read(int low, int high) {
        return read(high) - read(low - 1);
    }

    void scale(T factor) {
        for(int i = 1; i <= N; i++) {
            values[i] /= factor;
        }
    }

    void power(T factor) {
        for(int i = 1; i <= N; i++) {
            values[i] *= factor;
        }
    }
};
