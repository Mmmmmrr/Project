#include <iostream>
#include <cstdio>
#include <memory>
#include <sstream>
#include <json/json.h>
using namespace std;

int main()
{

    
 //   string cmd = "ls -a -l";
  // string cmd = "while :; do echo hello; sleep 1; done";
   string cmd = "arecord -t wav -c 1 -r 16000 -d 5 -f S16_LE demo.wav";
    FILE *fp = popen(cmd.c_str(),"r");
    if(nullptr == fp)
    {
        perror("popen");
        return 1;
    }
    char c;
    while(fread(&c,1,1,fp) > 0)
    {
        fwrite(&c,1,1,stdout);
    }
    pclose(fp);
    return 0;
}





//void JsonParse(string &s)
//{
//   JSONCPP_STRING errs;
//    Json::Value root;
//    Json::CharReaderBuilder rb;
//    unique_ptr<Json::CharReader>const cr(rb.newCharReader());
//    bool res = cr->parse(s.data(),s.data()+s.size(),&root,&errs);
//    if(!res || !errs.empty())
//    {
//        cerr<<"parse Error!" << endl;
//    }
//    cout << "age:" << root["age"].asInt() << endl;
//    cout << "date:" << root["date"].asString() << endl;
//    cout << "message:" << root["message"].asString() << endl;
//    cout << "high:" << root["high"].asFloat() << endl;
//}
//
//int main()
//{
//    string s = "{\"age\":12, \"date\":\"2019-7-24/4/5/6\", \"message\":\"nihao\", \"high\":189.9}";
//       JsonParse(s);
//   // Json::Value root;
//   // Json::StreamWriterBuilder wb;
//   // ostringstream ss;
//   // Json::Value item;
//   // item["school"] = "qinghua";
//   // item["high"] = 180.9f;
//   // root["nick_name"] = "hello";
//   // root["data"] = "2019-7-24/4/5/6";
//   // root["message"] = "你好";
//   // root["age"] = 12;
//   // root["info"][0] = item;
//   // root["info"][1] = item;
//   // root["info"][2] = item;
//   // unique_ptr<Json::StreamWriter> sw(wb.newStreamWriter());
//   // sw->write(root,&ss);
//   // string str = ss.str();
//   // cout << str << endl;
//    return 0;
//}
