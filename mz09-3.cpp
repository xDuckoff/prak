#include <iostream>
#include <vector>
#include <algorithm>

constexpr char ZERO = static_cast<unsigned char>(0);

class Sufmass
{
    int real_len;
    std::string s;
    std::vector<int> arr;

public:
    explicit Sufmass(std::string &input);
    void build();
    void write() const;
    //void write_suf() const;
};

std::vector<int> cls;
int l;

bool cmp(const int &a, const int &b) {
    if (cls[a] < cls[b]) {
        return true;
    } else if (cls[a] > cls[b]) {
        return false;
    } else {
        return cls[(a + (1 << l)) % cls.size()] < cls[(b + (1 << l)) % cls.size()];
    }
}

bool cmp1(const char &a, const char &b) {
    return static_cast<unsigned char>(a) < static_cast<unsigned char>(b);
}

Sufmass::Sufmass(std::string &in) : real_len(in.size()), s(in + std::string(1, ZERO))
{
    cls.resize(real_len + 1);
    std::vector<char> srt(real_len + 1);
    for (int i = 0; i < real_len + 1; ++i) {
        srt[i] = this->s[i];
    }

    sort(srt.begin(), srt.end(), cmp1);
    auto last = std::unique(srt.begin(), srt.end());

    int cls_num[256];
    int cur = 0;

    for (auto it = srt.begin(); it != last; ++it) {
        cls_num[static_cast<unsigned char>(*it)] = cur++;
    }

    for (int i = 0; i < static_cast<int>(in.size()); ++i) {
        cls[i] = cls_num[static_cast<unsigned char>(in[i])];
    }

    for (int i = 0; i < real_len + 1; ++i) {
        arr.push_back(i);
    }
}

void Sufmass::write() const
{
    for (int i = 1; i < static_cast<int>(arr.size()); ++i) {
        std::cout << arr[i] << std::endl;
    }
}

/*void Sufmass::write_suf() const
{
    std::vector<std::pair<int, size_t>> out;
    for (size_t i = 0; i < cls.size(); i++) {
        out.emplace_back(cls[i], i);
    }

    std::sort(out.begin(), out.end());
    for (auto x : out) {
        if (real_len == x.second) {
            continue;
        }
        std::cout << s.substr(x.second, real_len - x.second) << "\n";
    }
}*/

void Sufmass::build()
{
    std::vector<int> _c(cls.size());
    for (l = 0; (1 << l) <= real_len; ++l) {
        std::sort(arr.begin(), arr.end(), cmp);
        int len = 1 << l;

        cls[arr[0]] = 0;
        for (int i = 1; i < real_len + 1; ++i) {
            int l1 = arr[i - 1];
            int r1 = (arr[i - 1] + len) % (real_len + 1);
            int l2 = arr[i];
            int r2 = (arr[i] + len) % (real_len + 1);

            if (cls[l1] != cls[l2] || cls[r1] != cls[r2]) {
                _c[l2] = _c[l1] + 1;
            } else {
                _c[l2] = _c[l1];
            }
        }
        std::copy(_c.begin(), _c.end(), cls.begin());
    }
}

int main()
{
    std::string s;

    std::getline(std::cin, s, '\0');

    size_t k = s.size();
    while (isspace(static_cast<unsigned char>(s[--k])));
    s.resize(k + 1);

    Sufmass res(s);

    res.build();
    res.write();
}
