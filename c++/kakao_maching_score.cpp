//
// Created by SUN on 2018-11-19.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string UpperToLower(string word) {
    for (int i = 0; i < word.size(); i++) {
        if ('A' <= word[i] && word[i] <= 'Z') {
            word[i] = word[i] - 'A' + 'a';
        }
    }
    return word;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    map<string, int> base; // 기본점수
    map<string, vector<string>> external; // 외부링크
    map<string, double> linkScore; // 외부링크 점수
    map<string, double> total;

    //word의 문자열을 전부 소문자로
    word = UpperToLower(word);

    //search page base url
    //head 안에서 찾아야 한다.
    for (int page_num = 0; page_num < pages.size(); page_num++) {
        string html = pages[page_num];

        //base url을 찾는다.
        int head_start = html.find("<head>");
        int head_end = html.find("</head>");
        string head = "";
        for (int i = head_start + 6; i < head_end; i++) { //
            head += html[i];
        }
        int url_start = head.find("https://");
        int url_end;
        string tmp = head.substr(url_start);
        url_end = tmp.find("\"");


        string url = ""; // base_url
        for (int i = 0; i < url_end; i++) {
            url += tmp[i];
        }

        //body에서 문자열을 찾는다.
        int score = 0;
        int body_start = html.find("<body>");
        int body_end = html.find("</body>");
        string body = html.substr(body_start + 7, body_end - body_start - 7);

        //base에 찾은 문자열의 기본점수를 넣는다.
        body = UpperToLower(body);
        tmp = "";
        for (int i = 0; i < body.size(); i++) {
            int nowC = body[i];

            if ('a' <= nowC && nowC <= 'z') {
                tmp += nowC;
            } else {
                if (tmp == word) {
                    score++;
                }
                tmp = "";
            }
        }
        if (tmp==word){
            score++;
        }
      printf("score[%d] : %d\n",page_num,score);

        base.insert({url, score});

        //외부 링크를 찾는다.
        int link_num = 0;
        tmp = body;

        while (true) {
            int link_start = tmp.find("<a href=");

            if (link_start == -1) {
                break;
            }
            string link = "";
            for (int i = link_start + 9;; i++) {
                if (tmp[i] == '\"') {
                    break;
                }
                link += tmp[i];

            }

            external[url].push_back(link);
            link_num++;
            tmp = tmp.substr(link_start + 8);

        }

        //외부링크 점수를 계산한다.
        double link_score = (double) base[url] / link_num;
        linkScore.insert({url, link_score});


    }

    // total을 계산하자.
    for (int page_num = 0; page_num < pages.size(); page_num++) {
        string html = pages[page_num];

        //base url을 찾는다.
        int head_start = html.find("<head>");
        int head_end = html.find("</head>");
        string head = "";
        for (int i = head_start + 6; i < head_end; i++) { //
            head += html[i];
        }
        int url_start = head.find("https://");
        int url_end;
        string tmp = head.substr(url_start);
        url_end = tmp.find("\"");


        string url = ""; // base_url
        for (int i = 0; i < url_end; i++) {
            url += tmp[i];
        }

        int external_size = external[url].size();
        vector<string> ex_urls = external[url];
        for (auto x: ex_urls) {
            total[x] += linkScore[url];
        }


        total[url] += base[url];
//        cout << ' ' << endl;
    }

    // 어떤게 가장 큰지 추출하자
    int max = 0;
    for (int page_num = 0; page_num < pages.size(); page_num++) {
        string html = pages[page_num];

        //base url을 찾는다.
        int head_start = html.find("<head>");
        int head_end = html.find("</head>");
        string head = "";
        for (int i = head_start + 6; i < head_end; i++) { //
            head += html[i];
        }
        int url_start = head.find("https://");
        int url_end;
        string tmp = head.substr(url_start);
        url_end = tmp.find("\"");


        string url = ""; // base_url
        for (int i = 0; i < url_end; i++) {
            url += tmp[i];
        }

        if (total[url] > max) {
            max = total[url];
            answer = page_num;
        }

    }


    return answer;
}

int main() {
    vector<string> pages;
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                    "<head>\n"
                    "  <meta charset=\"utf-8\">\n"
                    "  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n"
                    "</head>  \n"
                    "<body>\n"
                    "abab abababa\n"
                    "\n"
                    "</body>\n"
                    "</html>");
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                    "<head>\n"
                    "  <meta charset=\"utf-8\">\n"
                    "  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n"
                    "</head>  \n"
                    "<body>\n"
                    "con%    muzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n"
                    "\n"
                    "    ^\n"
                    "</body>\n"
                    "</html>");

    int ans = solution("aba", pages);

    cout << ans << '\n';

    return 0;
}