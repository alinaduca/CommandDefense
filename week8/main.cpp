#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
std::ifstream fin("D:/SursePOO/CommandDefense/week8/phrase.in");
std::string s, sep(" ,?!.");
std::map<std::string, int> nrAparitii;
typedef std::pair<std::string, int> stringAndInt;

struct Comp {
    bool operator()(stringAndInt const& a, stringAndInt const& b) {
        if(a.second != b.second)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};

std::priority_queue<stringAndInt, std::vector<stringAndInt>, Comp> C;

int main() {
    std::getline(fin, s);
    fin.close();
    int cuv1 = s.find_first_of(sep), ucuv = 0;
    while(cuv1 != std::string::npos) {
        if(cuv1 != ucuv) {
            std::string cuv = s.substr(ucuv, cuv1 - ucuv);
            for(auto& i : cuv)
                if(i <= 'Z' && i >= 'A')
                    i -= 'A' - 'a';
            nrAparitii[cuv]++;
        }
        ucuv = cuv1 + 1;
        cuv1 = s.find_first_of(sep, ucuv);
    }
    for(auto const& i : nrAparitii)
        C.push(make_pair(i.first, i.second));
    while(!C.empty()) {
        std::cout << C.top().first << " => " << C.top().second << '\n';
        C.pop();
    }
    return 0;
}
