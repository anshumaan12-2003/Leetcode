class LUPrefix {
public:
    vector<bool> uploaded;
    int prefix;

    LUPrefix(int n) {
        uploaded.resize(n + 1, false);
        prefix = 0;
    }

    void upload(int video) {
        uploaded[video] = true;

        while (prefix + 1 < uploaded.size() && uploaded[prefix + 1]) {
            prefix++;
        }
    }

    int longest() {
        return prefix;
    }
};
/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */