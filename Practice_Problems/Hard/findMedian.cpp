class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
    }

    void addNum(int num) {
        arr.insert(std::upper_bound(arr.begin(), arr.end(), num), num);
    }
    double findMedian() {
        if (arr.size() % 2 == 0)
        {
            int indx1 = arr.size() / 2;
            int indx2 = indx1 - 1;
            return (arr[indx1] * 1.0 + arr[indx2] * 1.0) / 2 * 1.0;
        }
        return arr[arr.size() / 2];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */