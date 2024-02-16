#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <functional> // function library to define a function in a function
#include <fstream>
#include <algorithm>

using namespace std;

void mergeSort(int* vA, int N)
{
    int* vM = vA;
    int* vMt = new int[N];
    function<void(int, int, int)> merge = [&](int left, int mid, int right) { // lambda function.
    // このラムダ関数を使えば，再帰関数を定義するのに，わざわざグローバル領域に関数を宣言せずにすむ．
    // ラムダ関数は関数の中に宣言できる特別な関数である．
    // 宣言された関数内のローカル変数を参照できる．
    // 構文は，14行目のとおりである．
    // - function: ラムダ関数を入れる特別なクラス
    // - void(int, int, int): 関数の型．int の引数がmergeソートの要件から3つほしいため，このように定義している．返り値必要ないため void とした．
    // = [&](int left, int mid, int right){}: 関数の処理内容の定義．& はローカル変数をラムダ関数の中で改変可能とする宣言．ほかは普通の関数と同様の意味
        int il = 0;
        int ir = 0;
        int el = mid - left;
        int er = right - mid;
        while (true) {
            if (il == el) {
                if (ir == er) {
                    return;
                } else {
                    vMt[left + il + ir] = vM[mid + ir];
                    ++ir;
                }
            } else {
                if (ir == er) {
                    vMt[left + il + ir] = vM[left + il];
                    ++il;
                } else {
                    auto tl = vM[left + il];
                    auto tr = vM[mid + ir];
                    if (tl <= tr) {
                        vMt[left + il + ir] = tl;
                        ++il;
                    } else {
                        vMt[left + il + ir] = tr;
                        ++ir;
                    }
                }
            }
        }
    };
    function<void(int, int)> mergeSort = [&](int left, int right) {
        //ラムダ関数は関数内で複数定義可能．
        if (right - left <= 1) {
            return;
        }
        auto mid = (left + right) / 2;
        mergeSort(left, mid); // 普通の関数と同じように，ラムダ関数を呼び出し可能．ただし，宣言された関数（スコープ）外からラムダ関数を呼び出すことはできない．この性質はローカル変数と同じものである．ラムダ関数の枠組みでは関数を変数のように扱うことが可能となっている．
        mergeSort(mid, right);
        merge(left, mid, right);
        for (int i = left; i < right; ++i) {
            vM[i] = vMt[i];
        }
    };
    mergeSort(0, N);
    delete [] vMt;
}
void quickSort(int* vA, int N)
{

    function<void(int, int)> sort = [&](int is, int ie) {
        auto n = ie - is + 1;
        if (n <= 1) {
            return;
        }
        auto mid = is;
        auto tail = ie;
        for (int k = 1; k < n; ++k) {
            if (vA[mid] > vA[mid + 1]) {
                auto t = vA[mid];
                vA[mid] = vA[mid + 1];
                vA[mid + 1] = t;
                ++mid;
            } else {
                auto t = vA[tail];
                vA[tail] = vA[mid + 1];
                vA[mid + 1] = t;
                --tail;
            }
        }
        sort(is, mid - 1);
        sort(mid + 1, ie);
    };
    sort(0, N - 1);
}
void bubbleSort(int* vA, int N)
{
    // ************ Bubble sort *****************
    int nflip = 1;
    for (int i = 0; nflip != 0; ++i) {
        nflip = 0;
        for (int j = 0; j < N; ++j) {
            if (vA[j] < vA[j - 1]) {
                auto t = vA[j];
                vA[j] = vA[j - 1];
                vA[j - 1] = t;
                ++nflip;
            }
        }
    }
}
int main(){
    random_device o_rd;
    int seed = o_rd();
    std::mt19937 engine(seed);

    ofstream f_time("sort.time.tsv"); // TSV ファイルで結果を出力する．計算時間の確認用
    f_time << "N\tmerge\tbubble\tquick\tSTL\n";
    // 普通CSVファイルといえばカンマ「,」で要素を区切るが，カンマの代わりに実はタブ\tをつかったTSVもだいたいの環境で使える．
    // タブ（\t）にしておくと，後でC++言語から読み取りやすい．
    int N = 4098;
    float M = 32;
    int A_B[N], A_Q[N], A_M[N], A_STL[N], B[N];
    // 何度も実行するのが面倒であれば，ここから(3)のあたりまでを繰り返し文とするといい．
    for(int i =0 ; i< 30 ; i++){
    M = M*1.2;
    N = int(M);
    if(N>=4000)break;
    uniform_int_distribution<int> dist(0, N - 1);
    for(int i=0;i<N;++i){
        B[i] = i;
    }
    for(int i=0;i<N;++i){
        int j = dist(engine); // randomize the state
        int t = B[j];
        B[j] = B[i];
        B[i] = t;
    }
    for(int i=0;i<N;++i){
        A_B[i] = B[i]; // Initialize.
        A_Q[i] = B[i]; // Memorize initial state.
        A_M[i] = B[i]; // Memorize initial state.
        A_STL[i] = B[i]; // Memorize initial state.
    }

    auto t0 = std::chrono::steady_clock::now();
    mergeSort(A_M, N);
    auto t1 = std::chrono::steady_clock::now();
    bubbleSort(A_B, N);
    auto t2 = std::chrono::steady_clock::now();
    quickSort(A_Q, N);
    auto t3 = std::chrono::steady_clock::now();
    sort(A_STL, A_STL + N);
    auto t4 = std::chrono::steady_clock::now();
    std::chrono::duration<double> d01 = t1-t0;
    std::chrono::duration<double> d12 = t2-t1;
    std::chrono::duration<double> d23 = t3-t2;
    std::chrono::duration<double> d34 = t4-t3;
    f_time << N << "\t" << d01.count() << "\t" << d12.count() << "\t" << d23.count() << "\t" << d34.count() <<"\n";
    
}
    // (3)
    ofstream f_array("sort.res.tsv"); // 整列結果の確認用
    f_array << "merge\tbubble\tquick\tSTL\n";
    for(int i=0;i<N;++i){
        f_array << A_M[i] << "," << A_B[i] << "," << A_M[i] <<"," << A_STL[i]<< "\n";
    }
    
    return 0;
}