#include <bits/stdc++.h>
using namespace std;
void debug() { cout << "]" << endl;} template<class H, class... T> void debug(H h, T... t) { cout << h; if(sizeof...(t)) cout << ", "; debug(t...); }
#define dbg(...) cout << "LINE(" << __LINE__ << ") : [" <<  #__VA_ARGS__ << "] = [", debug(__VA_ARGS__)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
// template<class _T> inline int len(_T&& t){ return (int)t.size(); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("conserve-stack")
// #include <immintrin.h>
#include <x86intrin.h>


long long sum;
double times;
int cntt = 0;

string to_str(__int128_t& x){
    string str;
    while(x){
        str += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

template<class T = int64_t, int N = 18>
struct Bignum{
    alignas(64) vector<T> big; 
    alignas(64) vector<T> big_setpre;
    bool sign = false;

    static constexpr size_t MOD = 1000000;

    #define load(x)  _mm256_loadu_si256((__m256i*) &x)
    #define _add(x, y) _mm256_add_epi64(x, y)
    #define _sub(x, y) _mm256_sub_epi64(x, y)
    #define set64(x) _mm256_set1_epi64x((x))
    #define set32(x) _mm256_set1_epi32(x)
    #define mul32(x, y) _mm256_mul_epi32(x, y)
    #define store(to, from) _mm256_storeu_si256((__m256i*)&to, from)
    #define compare(x, y) _mm256_cmpgt_epi64(x, y)
    #define and_not(x, y) _mm256_andnot_si256(x, y)
    #define set_zero() _mm256_setzero_si256()

    Bignum(){
        big.resize(1);
        big.reserve(100);
        big_setpre.resize(N / 18);
        assert(type() == "int" || type() == "long long" || type() == "double");
        assert(N >= 0);
    }
    template <class H>
    struct is_value {
        static constexpr bool value = std::is_same_v<H, char> || is_same_v<H, int> || is_same_v<H, long long> || is_same_v<H, double>;
    };

    template <class H>
    struct is_string {
        static constexpr bool value = std::is_same_v<H, std::string> || std::is_same_v<T, const char>
                                                    || std::is_same_v<T, char*>;
    };
    constexpr inline long long max_size(){
        if constexpr(sizeof(T) == 2)return 1e4;
        else if constexpr(sizeof(T) == 4) return 1e9;
        return 1e18;
    }
    constexpr inline auto type() const{
        string idx = typeid(T).name();
        if(idx == "i") return "int";
        else if(idx == "d" || idx == "f") return "double";
        else if(idx == "x" || idx == "l" || idx == "m") return "long long";
        else return "type unknown";
    }

    constexpr inline auto operator = (Bignum<T, N>& other) {
        big = other.big;
        return *this;  
    }
    constexpr inline auto operator = (vector<T>& other) {
        big = other;
        return *this;  
    }

    template<typename _H>
    constexpr auto operator = (_H&& b) {
        using H = typename std::remove_cv<
        typename std::remove_reference<_H>::type>::type;
        string other;
        if constexpr(is_value<H>::value){
            other = to_string(b);
        }else{
            other = b;
        }
        big.clear(); big.shrink_to_fit();
        big.resize((int)ceil(((double)other.size() * 1.0 - (other.back() == '-')) / 17));
        for(int i = (int)other.size() - 1, cnt = 0; i >= 0; i -= 17){;
            string val = other.substr(i - min(i, 16), min(i + 1 , 17));
            // assert(cnt < len(big));
            // dbg(val);
            big[cnt++] = (val == "" ? 0LL : stoll(val));
        }
        return *this;
    }

    template<class H> 
    constexpr auto operator () (H& h) { return *this = h; } 
    constexpr auto operator + (const Bignum<T, N> b){
        big.resize(max(big.size(), b.big.size())); 
        const int mxN = b.big.size();
        int i = 0;

        auto mmP = set64(max_size()); // 1e18
        for(; i < mxN - 4; i += 4){
            auto x = load(big[i]); // vector big -> __m256i x
            auto y = load(b.big[i]); // vector b.big -> __m256 y
            auto add = _add(x, y); // add = x + y
            auto cmp = compare(mmP, add);  // compare add and 1e18
            auto result = _sub(add, and_not(cmp, mmP));
            store(big[i], result); // __m256i result -> vector big
            auto cmp2 = compare(add, mmP);  // compare add and 1e18
            auto x2 = load(big[i + 1]); // vector big -> __m256i x
            store(big[i + 1], _sub(x2, cmp2));
        }
        sum += mxN;

        int end = min(i, mxN - 1);
        #pragma GCC ivdep
        for(; end + 1 < mxN ; ){
            big[end] += b.big[end];
            bool ok = big[end] >= max_size();
            big[end] -= ok ? max_size() : 0;
            big[++end] += ok;
        }
        if(end < mxN){
            if ((big[end] += b.big[end]) >= max_size()){ [[unlikely]] 
                big[end] -= max_size();
                if(end + 1 == big.size()) big.emplace_back(1);
                else big[++end]++;
            }
        }
        return *this;
    }
    constexpr inline auto operator + (const T& other){
        Bignum<T, N> x; x = other;
        return *this + x;
    }
    constexpr  auto operator += (const Bignum<T, N>& other){
        return *this + other;
    }
    constexpr inline auto operator += (const T& other){
        Bignum<T, N> x; x = other;
        return *this + x;
    }

    constexpr  bool operator == (const Bignum<T, N>& other){
        if((int)other.big.size() != (int)big.size()) return false;
        for(int i = 0; i < (int)other.big.size(); i++){
            if(other.big[i] ^ big[i]) return false;
        }
        return true;
    }
    constexpr  bool operator == (const T& other){
        Bignum<T, N> x = other;
        return *this == x;
    }
    constexpr  bool operator != (const Bignum<T, N>& other){
        return !(big == other.big);
    }
    constexpr  bool operator < (const Bignum<T, N>& other){
        // if((int)big.size() < other.big.size()) return true;
        // else if((int)big.size() > other.big.size()) return false;
        // for(int i = other.big.size() - 1; ~i; i--){
        //     if(big[i] < other.big[i]) return true;
        //     else if(big[i] > other.big[i]) return false;
        // }
        // return false;
        return big < other.big;
    }
    constexpr  bool operator > (const Bignum<T, N>& other){
        return !(big == other.big) && !(big < other.big);
    }
    constexpr  bool operator >= (const Bignum<T, N>& other){
        return (big == other.big) || (big > other.big);
    }
    constexpr  bool operator <= (const Bignum<T, N>& other){
        return (big == other.big) || (big < other.big);
    }
    constexpr auto operator - (const Bignum<T, N> b){
        big.resize(max(big.size(), b.big.size())); 
        const int mxN = b.big.size();
        int i = 0;

        auto mmP = set(-max_size());
        for(; i < mxN - 4; i += 4){
            auto x = load(big[i]); // vector big -> __m256i x
            auto y = load(b.big[i]); // vector b.big -> __m256 y
            auto sub = _sub(x, y); // add = x + y
            auto cmp = compare(sub, mmP);  // compare add and 1e18
            auto result = _sub(sub, and_not(cmp, mmP));
            store(big[i], result); 
            auto cmp2 = compare(mmP, sub);  // compare add and 1e18
            auto x2 = load(big[i + 1]); // vector big -> __m256i x
            store(big[i + 1], _add(x2, cmp2));
        }
        sum += mxN;

        int end = min(i, mxN - 1);
        #pragma GCC ivdep
        for(; end + 1 < mxN ; ){
            big[end] -= b.big[end];
            bool ok = big[end] <= -max_size();
            big[end] += ok ? max_size() : 0;
            big[++end] -= ok;
        }
        if(end < mxN){
            if ((big[end] -= b.big[end]) <= -max_size()){ [[unlikely]] 
                big[end] += max_size();
                if(end + 1 == big.size()) big.emplace_back(-1);
                else big[++end]--;
            }
        }
        return *this;
    }

    constexpr auto operator - (const T& other){
        Bignum<T, N> x; x = other;
        return *this - x;
    }
    constexpr  auto operator -= (const T& other){
        Bignum<T, N> x; x = other;
        return *this - x;
    }
    constexpr  auto operator -= (const Bignum<T, N>& other){
        return *this - other;
    }
    constexpr inline auto operator ++(int){
        return *this += (T)1;
    }
    constexpr inline auto operator --(int){
        return *this -= (T)1;
    }
    constexpr inline auto operator ++(){
        return *this += (T)1;
    }
    constexpr inline auto operator --(){
        return *this -= (T)1;
    }

    constexpr auto operator * (const Bignum<T, N> other){
        /*LINK:{
            https://everything2.com/title/Comba+multiplication
            https://codeforces.com/blog/entry/74209
            https://iq.opengenus.org/toom-cook-algorithm-multiplication/
        }*/

        const uint32_t Min = min(size(big), size(other.big)) * 3;
        const uint32_t Max = max(size(big), size(other.big)) * 3;
        alignas(64) uint32_t a[Min + 5];
        alignas(64) uint32_t b[Max + 5];
        int cnt = Min + Max - 1;
        alignas(64) uint64_t mul[Min + Max + 3] = {};

        auto copy = [&](uint32_t *__restrict__ aa, size_t n, const vector<T>& bigg){
            for(int i = 0; i < n; ++i){
                aa[i * 3] = bigg[i] % MOD; 
                aa[i * 3 + 1] = (bigg[i] / MOD) % MOD; 
                aa[i * 3 + 2] = bigg[i] / (uint64_t)1e12; 
            }
        };

        if(size(big) > size(other.big)){
            copy(a, size(other.big), other.big);
            copy(b, size(big), big);
        }else{
            copy(a, size(big), big);
            copy(b, size(other.big), other.big);  
        }

        // auto Karatsuba = [&]() 
        sum += Min + Max - 1;

        #pragma GCC ivdep
        for(int i = 0, j = 0; i < Min; ++i, j = 0){
            for(; j < Max; ++j) {
                // assert(mul[i + j] <= 0xFFFFFFFFFFFFFFFF);
                mul[i + j] += ((int64_t)a[i]) * b[j];
                // auto x = load(a[i]);
                // auto y = load(b[j]);
                // auto res = load(mul[i + j]);
                // auto ad = add(res, r)
            }
        }
        for(int i = 0; i + 1 < cnt; ++i){
            mul[i + 1] += mul[i] / MOD;
            mul[i] %= MOD;
        }
        while(mul[cnt-1] >= MOD) {
            mul[cnt] = mul[cnt - 1] / MOD; cnt++;
            mul[cnt - 2] %= MOD;
        }
        big.resize(cnt / 3);
        for(int i = 0; i < big.size(); ++i){
            big[i] = (mul[i * 3 + 2] * MOD + mul[i * 3 + 1]) * MOD + mul[i * 3];
        }
        if((cnt + 1) % 3 == 0) {
            if(mul[cnt - 1] || mul[cnt - 2])
                big.push_back(mul[cnt-1] * MOD + mul[cnt-2]);
        }else if(mul[cnt-1] && ((cnt+1) % 3 == 0)) {
            big.push_back(mul[cnt-1]);
        }
        return *this;
    }
     
    template<class H>
    constexpr auto operator * (const H& h){
        Bignum<T, N> x; x = h;
        return *this * x;
    }
    template<class H>
    constexpr auto operator *= (const H& h){
        Bignum<T, N> x; x = h;
        return *this * x;
    }
    constexpr auto operator *= (const Bignum<T, N>& h){
        return *this * h;
    }
    #define gc getchar_unlocked()
    #define pc putchar_unlocked()

    template<class H>
    constexpr inline void set(const H& h){
        big_setpre.resize(h / 18);
    }
    friend constexpr int len(const Bignum<T, N>& b) {
        int cnt = ((int)b.big.size() - 1) * 18;
        auto x = b.big.back();
        while(x){
            x /= 10, cnt++;
        }
        return max(1, cnt);
    }
    // friend constexpr void write(Bignum<T, N>& b) {
    //     cout << b.back();
    //     auto tmp = b.big.back();
    //     for(int i = (int)b.size() - 2, cnt = 0; ~i; i--){
    //         tmp = b.big[i]; 
    //         while(tmp){cnt++, tmp /= 10;}
    //         for(int j = 1; j <= 18 - cnt; j++) cout << "0"; 
    //         cout << abs(b.big[i]);
    //     }
    // }
    // friend constexpr void print(const Bignum<T, N>& b) {
    //     write(b); cout << "\n";
    // }
    friend constexpr string str(const Bignum<T, N>& h) {
        string str;
        for(int i = (int)h.big.size() - 1; ~i; i--) str += to_string(h.big[i]);
        return str;
    }

    constexpr auto operator &= (const Bignum<T, N>& h){
        big.resize(max(size(h.big), size(big)));
        for(int i = 0; i < size(h.big); i++) big[i] &= h.big[i];
        return *this;
    }
    //  Bignum pow(const &Bignum other) const{
    //     Bignum res = 1;
    //     while(other > 0){
    //         if(other.big[0] & 1) res *= big;
    //         big *= big;
    //         other >>= 1;
    //     }
    //     return big;
    // }
    /*1
     operator = ()
     operator &(const )
     operator << (const &Bignum) const{

    }*/
    constexpr auto operator ~(){
        big.back() < 0 ? *this += 1LL : *this -= 1LL; *this = -*this;
        return *this;
    }
};

template<class T, int N>
istream& operator >> (istream& is, Bignum<T, N>& t){
    string str; is >> str;
    t = str;
    return is;
}


template<class T, int N> 
ostream& operator << (ostream& os, const Bignum<T, N>& t) {
    // os << t.big.back() << "|";
    os << t.big.back();
    for(int i = (int)t.big.size() - 2; ~i; i--){
        string str = to_string(t.big[i]); 
        for(int j = 1; j <= 18 - (int)str.size() + (str[0] == '-'); j++) os << "0"; 
        // os << abs(t.big[i]) << "|";
        os << t.big[i];
    }
    return os;
}
// typedef double v4d __attribute__ (( vector_size(32) ));

// template<class T> constexpr int Max_element(const vector<T>& v){
//     T Max = v[0];
//     int pos = 0;
//     #pragma GCC ivdep
//     for(int begin = 0; begin < size(v); ++begin) {
//         const T MM = max(v[begin], v[(++begin)]);
//         if(MM > Max){ //[[unlikely]]
//             Max = MM;
//             pos = begin - (v[begin] < v[(begin - 1)]);
//         }
//     }
//     return pos;
// }
template<class T> constexpr T Max_element(const vector<T>& v){
    T Max = v[0];
    auto begin = 0;
    const auto set_bit = set32(numeric_limits<uint32_t>::max());
    auto set_Max = set32(Max);
    #pragma GCC ivdep
    for(T tmp = Max; begin + 7 < size(v); begin += 8) {
        const auto now = load(v[begin]);
        if(tmp != Max) set_Max = set32(Max);
        tmp = Max;
        const auto cmp = _mm256_cmpgt_epi32(set_Max, now);
        const auto result = _mm256_testz_si256(set_bit, cmp);
        // if(!result) cout << result << "\n";
        if(result){ 
                #pragma GCC ivdep
            for(int j = begin + 7; j >= begin; --j) {
                Max = max(Max, v[j]);
            }
        }
    }
    // cerr << cnt << "|n";
    for(; begin < size(v); ++begin) Max = max(Max, v[begin]);
    return Max;
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); srand(time(NULL));
    Bignum<int64_t> a, b, c, d, tests;
    cin >> a >> b;
    cout << a.big.size() << "\n";
    cout << len(a) << ' ' << len(b) << "\n";
    assert(a == b);
     FOR(test, 1, 100){
        c = a, d = b;
        FOR(i, 1, 1000){
            d += c;
        }
     }
    cout << len(d) << ' ' << d.big.size() << endl;
    // a &= b;
    // cout << (a) << endl;
    // b = a;
    // cout << (1.0 * clock())/ CLOCKS_PER_SEC << "\n";
    // cout << len(a) << ' ' << len(b) << endl;
    // cout << size(a.big) << " " << size(b.big) << endl;
    //  int cnt = 0;
    //  for(int i = 1; i <= 1000; i++){
    //     //  a.big[rand() % ((int)a.big.size())] = rand() % (int)1e9;
    //     //  b.big[rand() % ((int)a.big.size())] = rand() % (int)1e9;
    //      if(a < b) cnt++;
    //      else cnt--;
    //  }
    //  cout << cnt << endl;
    // cout << (1.0 * clock())/ CLOCKS_PER_SEC << "\n";
    // cout << len(a) << "\n";
    //  cout << a << "\n";
    // dbg(times,  sum);

    cout << typeid(float).name() << " " << typeid(uint64_t).name() << endl;
    // string val = "999999999999999999999999999999999999999999999999999999999999999999999995";

    // cout << (a);


    // cout << pow(a, 5) << endl;
    // Bignum ans1, ans2; ans1 = 1, ans2 = 1;
    // string rhs = "1";
    // vector<int64_t> x((int)5.3e7), y((int)2e7);
    // // x.shrink_to_fit();
    // // y.shrink_to_fit();
    // iota(x.begin(), x.end(), (int64_t)rand() * rand());
    // iota(y.begin(), y.end(), (int64_t) rand() * rand());

    // cout << *x.begin() << ' ' << *y.begin() << endl;

    // auto copy_data = [&](){
    //     ans1.big = vector(x.begin(), x.end());
    //     ans2.big = vector(y.begin(), y.end());
    // };

    // copy_data();

    // cout << len(ans1) << endl;
    // // cout << ans << endl;

    auto checkTimes = [](auto& ans1, auto& 
        ans2, auto&& f){
        cerr << "len of number 1 = " << len(ans1) << endl;
        cerr << "len of number 2 = " << len(ans2) << endl;
        auto begin_times = (1.0 * clock())/ CLOCKS_PER_SEC;
        f(ans1, ans2 );
        // cerr << "len of sum 2 number = " << len(ans1) << endl;
        auto end_times = (1.0 * clock())/ CLOCKS_PER_SEC;
        cout << "times of program = { " << end_times - begin_times << "s }\n";
    };
    // checkTimes(a, b, [](auto x, auto y){
    //     FOR(i, 1, 100) x = y, y += 1LL * rand();
    // });

    
    // cout << x1 + x2 << endl;
    return 0;
}


