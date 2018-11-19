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
    map<string, int> base;

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
        tmp="";
        for (int i = 0; i < body.size(); i++) {
            int nowC = body[i];

            if ('a'<=nowC && nowC <='z'){
                tmp+=nowC;
            }else {
                if (tmp==word){
                    score++;
                }
                tmp="";
            }
        }
//        printf("score[%d] : %d\n",page_num,score);

        base.insert({url,score});




    }


    return answer;
}

int main() {
    vector<string> pages;
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                    "<head>\n"
                    "  <meta charset=\"utf-8\">\n"
                    "  <meta property=\"og:url\" content=\"https://a.com\"/>\n"
                    "</head>  \n"
                    "<body>\n"
                    "Blind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n"
                    "<a href=\"https://b.com\"> Link to b </a>\n"
                    "</body>\n"
                    "</html>");
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                    "<head>\n"
                    "  <meta charset=\"utf-8\">\n"
                    "  <meta property=\"og:url\" content=\"https://b.com\"/>\n"
                    "</head>  \n"
                    "<body>\n"
                    "Suspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n"
                    "<a href=\"https://a.com\"> Link to a </a>\n"
                    "blind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n"
                    "<a href=\"https://c.com\"> Link to c </a>\n"
                    "</body>\n"
                    "</html>");
    pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n"
                    "<head>\n"
                    "  <meta charset=\"utf-8\">\n"
                    "  <meta property=\"og:url\" content=\"https://c.com\"/>\n"
                    "</head>  \n"
                    "<body>\n"
                    "Ut condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n"
                    "<a href=\"https://a.com\"> Link to a </a>\n"
                    "</body>\n"
                    "</html>");
    int ans = solution("blind", pages);

    cout << ans << '\n';

    return 0;
}