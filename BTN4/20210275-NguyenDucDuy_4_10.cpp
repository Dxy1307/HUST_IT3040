// Nguyễn Đức Duy - 20210275
#include<bits/stdc++.h>
using namespace std;

int n, q;
vector< vector<string> > vector_train;
vector< vector<string> > vector_test;
vector<int> f_max; // tần suất xuất hiện từ xuất hiện nhiều nhất trong văn bản i
map<string, int> df; // tính xem từ word nằm trong bao nhiêu văn bản
map<pair<string, int>, int> fe; // tính xem từ word xuất hiện bao nhiêu lần trong văn bản i <word, i> = int

// tách mảng
vector<string> split_string(string str){
    vector<string> vt;

    while (!str.empty()){
        string tmp = str.substr(0, str.find(","));
        int pos = tmp.find(" ");

        if(pos > tmp.size())
            vt.push_back(tmp);
        else {
            while(pos <= tmp.size()){
                tmp.erase(pos,1);
                pos = tmp.find(" ");
            }
            vt.push_back(tmp);
        }
        if (str.find(",") > str.size()){
            break;
        } else {
            str.erase(0, str.find(",") + 1);
        }
    }

    return vt;
}

// input
void input(){
    vector<string> document_train;
    vector<string> document_test;

    cin >> n;
    string str_tmp;
    getline(cin, str_tmp);

    for(int i=0; i<n; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_train.push_back(str_tmp);
    }

    cin >> q;
    getline(cin, str_tmp);
    for(int i=0; i<q; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_test.push_back(str_tmp);
    }

    for(string v : document_train){
        vector<string> element = split_string(v);

        vector_train.push_back(element);
    }

    for(string v : document_test){
        vector<string> element = split_string(v);

        vector_test.push_back(element);
    }
}

// xử lý
void pre_processing(){
    // tính tần suất từ xuất hiện nhiều nhất trong văn bản i
    for(vector<string> str_tmp : vector_train){
        map<string, int> m;

        // thiết lập từ điển mini m với chỉ số : [sotu] [tansuatxuathien]
        int max_f = 0;
        for(string word_tmp : str_tmp){
            map<string, int>::iterator ite = m.find(word_tmp);
            if(ite == m.end()){ // nếu từ này chưa có trong từ điển mini
                m.insert({word_tmp, 1});
            } else {
                ite->second += 1;
            }

            max_f = max(m[word_tmp], max_f);
        }
        f_max.push_back(max_f);
    }
}

// tính xem word xuất hiện bao nhiêu lần trong văn bản i
int frequence_word_int_document_i(string word, int i){
    if(fe.find({word, i}) != fe.end()){ // nếu đã có trong kho lưu trữ thì lấy ra và trả về
        return fe[{word, i}];
    }

    int index = 0;
    vector<string> str_tmp = vector_train[i];

    for(string v : str_tmp){
        if(word == v) index++;
    }

    fe.insert({{word, i}, index});
    return index;
}

// tính xem từ word nằm trong bao nhiêu văn bản
int count_document_contain_word(string word){ // nếu đã có trong kho lưu trữ thì lấy ra và trả về
    if(df.find(word) != df.end()){
        return df[word];
    }

    int index = 0;
    for(vector<string> str_tmp : vector_train){

        vector<string>::iterator ite = find(str_tmp.begin(), str_tmp.end(), word);
        if(ite != str_tmp.end()){
            index++;
        }
    }

    df.insert({word,index});
    return index;
}

// Dự đoán văn bản
int search_engine(vector<string> list_word){
    double score_max = -1000;
    int predict_label = -1;
    for(int i=0; i<n; i++){
        vector<string> list_word_train_doc = vector_train[i];

        double score = 0;
        for(string word : list_word){
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word) == list_word_train_doc.end()){ // tu nay khong xuat hien trong van ban
                continue;
            } else {
                int ftd = frequence_word_int_document_i(word, i);
                int dft = count_document_contain_word(word);
                int maxfd = f_max[i];

                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n / dft);

                score += tf_word * idf_word;
            }
        }

        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }

    return predict_label + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    pre_processing();

    for(int i=0; i<q; i++)
        cout << search_engine(vector_test[i]) << endl;

    return 0;
}
// Nguyễn Đức Duy - 20210275