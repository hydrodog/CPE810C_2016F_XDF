
#include <fstream>
#include <string>
#include <string.h>
#include <locale>
#include <wchar.h>
#include <cstdio>
#include <cstdlib>
#include <qstring.h>
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <page.h>
#include <qdir.h>
#include <text.h>

using namespace std;
wstring ncx[500][2];//windows组做目录用,name and src
struct Set{
    string color = "default";
    string font = "default";
    string size = "16px";
    string bold = "0";
    string italic = "0";
    string underline = "0";
};
Set bodydefault;
class TRANS{
private:
    string path;
    wstring bodytrans;
    string allsetting;
    QString qimgset;
public:
    TRANS(wstring bodytrans,string allsetting,QString qimgset):bodytrans(bodytrans),allsetting(allsetting),qimgset(qimgset){}
    string getallsetting(){return allsetting;}
    wstring getbodytrans(){return bodytrans;}
    QString getqimgset(){return qimgset;}
};

string wtos(wstring wstr);
wstring stow(string str);
TRANS texttrans(string htmlpath1);
string wtos(wstring wstr){
    QString qstr = QString::fromStdWString(wstr);
    string str = qstr.toStdString();
    return str;
}
wstring stow(string str){
    QString qstr = QString::fromStdString(str);
    wstring wstr = qstr.toStdWString();
    return wstr;
}
string settingdetail(string fullsetting,string settingname);
string getsetting(string cssfile, string settingname);
wstring wopenfile(string path);
string openfile(string path);
string openfile(string path){
    string buf;
    ifstream file;
    file.open(path);
    if(!file){
        cout<<"open file err";
    }
    string src = "";
    while(!file.eof()){
        getline(file,buf);
        if(buf.length() == 0)
        {
            continue;
        }
        src+=buf;
        //cout << src<<endl;
    }
    //cout << src<<endl;
    file.close();
    return src;
}
wstring wopenfile(string path){
    wstring wbuf;
    wifstream wfile;
    wfile.open(path);
    if(!wfile){
        cout<<"open wfile err";
    }
    wstring src = L"";
    while(!wfile.eof()){
        getline(wfile,wbuf);
      /*  if(wbuf.length() == 0)
        {
            continue;
        }*/
        src+=wbuf;
        //wcout << src<<endl;
    }
    //wcout << src<<endl;
    wfile.close();
    return src;
}
void getncx(wstring fullncx,int pos,int i){
    if(fullncx.find(L"playOrder",pos) != wstring::npos){
        int postext1 = fullncx.find(L"<text>",fullncx.find(L"playOrder",pos));
        int postext2 = fullncx.find(L"</text>",postext1+6);
        ncx[i][0] = fullncx.substr(postext1+6,postext2-postext1-6);
        int possrc1 = fullncx.find(L"src=",fullncx.find(L"playOrder",pos));
        int possrc2 = fullncx.find(L"\"",possrc1+5);
        ncx[i][1] = fullncx.substr(possrc1+5,possrc2-possrc1-5);
        //wcout << ncx[i][0]<<'\n'<<ncx[i][1]<<endl;
        if(fullncx.find(L"playOrder",possrc2)!=wstring::npos){
            i++;
            getncx(fullncx,possrc2,i);
        }
        return;
    }
    return;
}

int main(int argc, char *argv[]) {
    //Get the defalut path, then make it convenient for us to put the file
    QString path = QDir::currentPath();
    string st=path.toStdString();
    cout<<st<<endl;

    string htmlpath1= "content2478944_41850213.html";//Address of html file
    TRANS output = texttrans(htmlpath1);//Function to transfer html to given standard

    QApplication a(argc, argv);
    MainWindow w;
    //Put the output to a txt file
    wofstream testf;
    testf.open("testfile.txt");
    testf << output.getbodytrans();
    testf.close();

   //Start test

#if 0
    cout<<"*********************"<<endl;
    wcout<<output.getbodytrans()<<endl;
     cout<<"*********************"<<endl;
    cout<<output.getallsetting()<<endl;
     cout<<"*********************"<<endl;

 #endif
    const wstring allwords1=L" 第20章 危机降临 \n<stylechange> \nPS：亲，求几张推荐票！\n“你确定需要接受这个任务？不再更改其它任务？你要知道，这是三星任务，黑水山脉，猎杀五阶妖兽风火熊？现在的你，绝对不是对手。”\n工作台上，一位貌相不错的白衣女子，忍不住提醒对方。\n五级妖兽，风火熊，黑水山脉，群居的一种妖兽，拥有强悍防御能力，又具有风火双系攻击，名声非常响亮。\n一般上，外门弟子，不到武道六重天，绝对不单独挑战这一类妖兽。\n“不需要，三星任务，我接了！”\n<stylechange>众多任务之中，林飞选择三星任务，因为这一门任务，奖励丰富，又可以提升实力，这其中，重要一点，通过挑战群居妖兽，修炼《金刚不坏之身》，提升自己的防御能力。\n.......\n登记三星任务后。\n林飞转身离开，不打算继续留在这里。\n“喂，你忘了拿东西！”\n背后，忽然响起女子的声音。\n“东西？”林飞恍然大悟，自己真的忘记拿东西，那是关于风火熊的具体资料记载。\n悬赏区相关事情，林飞不过是前任“林飞”留下来，了解并不算太多。忽略资料的事情，再正常不过。\n<stylechange>果然，女子递上来一份资料，美眸里带着一抹的好奇。\n“这位师弟，风火熊不是这么好对付，师姐还是劝你，放弃这个任务，你要明白，任务失败，必须扣除功勋值，失去功勋值，将会影响到玄功，黄阶玄功，兑换…..”\n工作台上的女子，年约十七八岁，身穿一套淡白色衣裙，容貌尚不算出色，却也是难得一见的美女，樱桃小嘴上，挂着淡淡的欢笑，透着少女活泼气氛。\n“谢谢师姐的好意，我这个人喜欢各种挑战，有挑战才有各种生活。”林飞开口笑道，说罢，拿着资料，直接离开。\n白衣女孩，嘴上哼了哼，“哼哼，好狂妄的小子，本小姐劝你，不给脸色，诅咒你倒霉！”\n话音落下，白衣女孩身后再次出现一个女子，旋即响起空灵一般的声音，宛如山水之间，叮咚流过的溪水。\n“悠悠，你在气什么呢？”\n“青幽姐，你出关啦！”\n<stylechange>白衣女孩跑出来，一下子抱住青衣女子，好不高兴的样子，惹来旁边不少人羡慕妒忌的眼光，恨不得自己成为那一个女子。\n“当然啦，要是不出来，我怎么会知道，咱们的悠悠，好像看上什么人，莫非是在思春，想男人？”青衣女子嫣然一笑，如百花盛开。\n“哼哼，青幽姐，你好坏啊，你才想男人了。”\n……\n从悬赏区出来。\n外面仍然有不少人前来悬赏区接受悬赏任务，争取完成各种任务，获取足够的功勋值，要么便是获得大量银子。\n玄天大陆，一个武者的世界。\n一个武者想要出人头地，威震大陆，各种强横玄功，首要立足之本，黄阶玄功还是其次，作为外门弟子，修炼合适自己的玄功，需要天文数字的银两，同样需要打量功勋值。\n<stylechange>一本二三流玄功，动不动几千银子。\n一本黄阶玄功，动不动上万银子。\n仅仅玄功之上，花费的银子，想来都是一件恐怖的数字。\n武者玄功修炼少，对敌上将会吃很大的亏，两人相同实力，结果另外一方，修炼几门玄功，再加上黄阶玄功，足够压制对方。\n神武门之中，家族弟子，寒门弟子，想要获取玄功，需要获取各种功勋值。\n悬赏区，才会如今的繁荣。\n神武门通过弟子，完成各种任务，双方都可以获得好处。\n林飞很明白，刚才那女子的提醒，一般人真不敢去对付风火熊，其中危险性很大。弄不好死在上面。\n<stylechange>“谁让低阶妖兽经验值不给力，老子何苦猎杀五阶妖兽，纯粹自己给自己找不自在，可惜了….对了，貌似刚才那女孩不错，粉嫩可爱，若是可以勾搭一下，一尝芳泽那就爽了。”\n……\n“林飞，你终于舍得出来，不枉费我一直在这等你。”\n正当林飞想入非非的时候，一声低沉带着愤怒的声音，从正前方传过来。\n愤怒的声音，立刻引起众多弟子的注意。\n因为，这里是悬赏区门口。\n“天那，那不是林飞吗？”\n“林飞算什么，你不如看看，那边站着什么人？”\n<stylechange>“什么人，值得….什么，他怎么来了，难道是冲着林飞来的？”\n“张万山师兄怎么可能出现在这，最近不是传闻，他不是在修炼一门玄功吗，莫非因为弟弟张重山之事？”\n“一定是这样的，林飞曾经大发神威打伤张重山，后来又打败张风浪，想不到将张万山这一尊外门高手逼迫出来！”\n“林飞要倒霉了，张万山师兄一生气，谁都挡不住怒火。”\n……..\n当众外门弟子，目光落在那散发着冷冽气息的年轻人身上时，全都下意识打了一身寒颤，宛如深处在冰天雪地之中，不由自主离开这范围。躲避那冰冷气息。\n张万山，武道八重天，罡气高手！\n提起这个名字，外门弟子之中，无人不知，无人不晓，凡是达到武道八重天，罡气护身，都有望成为玄者。\n<stylechange>张万山亲自出面，在场的人都明白是怎么一回事。\n“张重山师兄，莫非你的伤好的差不多，又想继续回去修养？如果这样，师弟不客气了。”\n林飞嘴上浮起一抹笑容，露出一口洁白牙齿，轻轻踏前一步，说出一番让人无法相信的话。\n这林飞是不是吃错药了。\n先前喝斥林飞，正是伤势渐好的张重山。\n“不要过来，给我站住，不要动。”\n闻言，张重山眼中闪过一抹惧意，下意识退开一步，仅仅是一步，暴露出内心之中的害怕。\n自己输在林飞这废物手上，大哥的帮手张风浪，同样被打败，如今还躺在床上养伤，下意识对林飞产生一股惧意，连他自己都不知道。\n<stylechange>林飞不在意张重山，当见到这家伙伤势恢复的如此之快，心里不由暗暗惊讶，真不愧是有一个外门高手大哥，疗伤丹药服用下去，伤势恢复神速。\n目光一转，转向某人身上，脸上表情微微一动，一颗心沉下来。\n“这人应该就是张万山，罡气护身高手，外门弟子之中，位居前三十的存在，张重山的大哥。”\n视野之中，一位貌相和张重山相差无几的年轻人，冷如冰山，周身之内，寒气逼人，尚未接近，寒气袭来，无形之中，空出一个位置。\n林飞脑中，第一时间浮现出，关于张万山的个人信息。\n\n手机用户请到m.qidian.com阅读。\n手机阅读器、看书更方便。【<stylechange>安卓版】 <stylechange>";
    const wstring allwords2=L" 第21章 半年大比之约 \n<stylechange> \nPS：亲，求几张推荐票！\n“你确定需要接受这个任务？不再更改其它任务？你要知道，这是三星任务，黑水山脉，猎杀五阶妖兽风火熊？现在的你，绝对不是对手。”\n工作台上，一位貌相不错的白衣女子，忍不住提醒对方。\n五级妖兽，风火熊，黑水山脉，群居的一种妖兽，拥有强悍防御能力，又具有风火双系攻击，名声非常响亮。\n一般上，外门弟子，不到武道六重天，绝对不单独挑战这一类妖兽。\n“不需要，三星任务，我接了！”\n<stylechange>众多任务之中，林飞选择三星任务，因为这一门任务，奖励丰富，又可以提升实力，这其中，重要一点，通过挑战群居妖兽，修炼《金刚不坏之身》，提升自己的防御能力。\n.......\n登记三星任务后。\n林飞转身离开，不打算继续留在这里。\n“喂，你忘了拿东西！”\n背后，忽然响起女子的声音。\n“东西？”林飞恍然大悟，自己真的忘记拿东西，那是关于风火熊的具体资料记载。\n悬赏区相关事情，林飞不过是前任“林飞”留下来，了解并不算太多。忽略资料的事情，再正常不过。\n<stylechange>果然，女子递上来一份资料，美眸里带着一抹的好奇。\n“这位师弟，风火熊不是这么好对付，师姐还是劝你，放弃这个任务，你要明白，任务失败，必须扣除功勋值，失去功勋值，将会影响到玄功，黄阶玄功，兑换…..”\n工作台上的女子，年约十七八岁，身穿一套淡白色衣裙，容貌尚不算出色，却也是难得一见的美女，樱桃小嘴上，挂着淡淡的欢笑，透着少女活泼气氛。\n“谢谢师姐的好意，我这个人喜欢各种挑战，有挑战才有各种生活。”林飞开口笑道，说罢，拿着资料，直接离开。\n白衣女孩，嘴上哼了哼，“哼哼，好狂妄的小子，本小姐劝你，不给脸色，诅咒你倒霉！”\n话音落下，白衣女孩身后再次出现一个女子，旋即响起空灵一般的声音，宛如山水之间，叮咚流过的溪水。\n“悠悠，你在气什么呢？”\n“青幽姐，你出关啦！”\n<stylechange>白衣女孩跑出来，一下子抱住青衣女子，好不高兴的样子，惹来旁边不少人羡慕妒忌的眼光，恨不得自己成为那一个女子。\n“当然啦，要是不出来，我怎么会知道，咱们的悠悠，好像看上什么人，莫非是在思春，想男人？”青衣女子嫣然一笑，如百花盛开。\n“哼哼，青幽姐，你好坏啊，你才想男人了。”\n……\n从悬赏区出来。\n外面仍然有不少人前来悬赏区接受悬赏任务，争取完成各种任务，获取足够的功勋值，要么便是获得大量银子。\n玄天大陆，一个武者的世界。\n一个武者想要出人头地，威震大陆，各种强横玄功，首要立足之本，黄阶玄功还是其次，作为外门弟子，修炼合适自己的玄功，需要天文数字的银两，同样需要打量功勋值。\n<stylechange>一本二三流玄功，动不动几千银子。\n一本黄阶玄功，动不动上万银子。\n仅仅玄功之上，花费的银子，想来都是一件恐怖的数字。\n武者玄功修炼少，对敌上将会吃很大的亏，两人相同实力，结果另外一方，修炼几门玄功，再加上黄阶玄功，足够压制对方。\n神武门之中，家族弟子，寒门弟子，想要获取玄功，需要获取各种功勋值。\n悬赏区，才会如今的繁荣。\n神武门通过弟子，完成各种任务，双方都可以获得好处。\n林飞很明白，刚才那女子的提醒，一般人真不敢去对付风火熊，其中危险性很大。弄不好死在上面。\n<stylechange>“谁让低阶妖兽经验值不给力，老子何苦猎杀五阶妖兽，纯粹自己给自己找不自在，可惜了….对了，貌似刚才那女孩不错，粉嫩可爱，若是可以勾搭一下，一尝芳泽那就爽了。”\n……\n“林飞，你终于舍得出来，不枉费我一直在这等你。”\n正当林飞想入非非的时候，一声低沉带着愤怒的声音，从正前方传过来。\n愤怒的声音，立刻引起众多弟子的注意。\n因为，这里是悬赏区门口。\n“天那，那不是林飞吗？”\n“林飞算什么，你不如看看，那边站着什么人？”\n<stylechange>“什么人，值得….什么，他怎么来了，难道是冲着林飞来的？”\n“张万山师兄怎么可能出现在这，最近不是传闻，他不是在修炼一门玄功吗，莫非因为弟弟张重山之事？”\n“一定是这样的，林飞曾经大发神威打伤张重山，后来又打败张风浪，想不到将张万山这一尊外门高手逼迫出来！”\n“林飞要倒霉了，张万山师兄一生气，谁都挡不住怒火。”\n……..\n当众外门弟子，目光落在那散发着冷冽气息的年轻人身上时，全都下意识打了一身寒颤，宛如深处在冰天雪地之中，不由自主离开这范围。躲避那冰冷气息。\n张万山，武道八重天，罡气高手！\n提起这个名字，外门弟子之中，无人不知，无人不晓，凡是达到武道八重天，罡气护身，都有望成为玄者。\n<stylechange>张万山亲自出面，在场的人都明白是怎么一回事。\n“张重山师兄，莫非你的伤好的差不多，又想继续回去修养？如果这样，师弟不客气了。”\n林飞嘴上浮起一抹笑容，露出一口洁白牙齿，轻轻踏前一步，说出一番让人无法相信的话。\n这林飞是不是吃错药了。\n先前喝斥林飞，正是伤势渐好的张重山。\n“不要过来，给我站住，不要动。”\n闻言，张重山眼中闪过一抹惧意，下意识退开一步，仅仅是一步，暴露出内心之中的害怕。\n自己输在林飞这废物手上，大哥的帮手张风浪，同样被打败，如今还躺在床上养伤，下意识对林飞产生一股惧意，连他自己都不知道。\n<stylechange>林飞不在意张重山，当见到这家伙伤势恢复的如此之快，心里不由暗暗惊讶，真不愧是有一个外门高手大哥，疗伤丹药服用下去，伤势恢复神速。\n目光一转，转向某人身上，脸上表情微微一动，一颗心沉下来。\n“这人应该就是张万山，罡气护身高手，外门弟子之中，位居前三十的存在，张重山的大哥。”\n视野之中，一位貌相和张重山相差无几的年轻人，冷如冰山，周身之内，寒气逼人，尚未接近，寒气袭来，无形之中，空出一个位置。\n林飞脑中，第一时间浮现出，关于张万山的个人信息。\n\n手机用户请到m.qidian.com阅读。\n手机阅读器、看书更方便。【<stylechange>安卓版】 <stylechange>";





    /*
     * After transfering html to two string. pass these two string to text
     * Then create two frames to contain these text(Only one constructor to call)
     * Add these two frames to the page,
     * then call the function in mainWindow to display them on the screen.
     */

    Text test1;
    test1.readInText(allwords1,output.getallsetting());
    Text test2;
    test2.readInText(allwords2,output.getallsetting());
    Frame f(100,20,800,600,1);
    f.text(test1);
    Page pg(1000,1600,1);
    Frame f2(100,630,800,600,2);
    f2.text(test2);
    pg.addFrame(f);
    pg.addFrame(f2);
    w.addFrame(pg);
    w.show();

    return a.exec();
}
TRANS texttrans(string htmlpath1){

    wstring wsrc = wopenfile(htmlpath1);
    wstring body;
    while(true){
        int pos1 = wsrc.find(L"body>");//head of body
        if(pos1<0)
            break;
        int pos2 = wsrc.find(L"/body>",pos1+5);//tail of body
        if (pos2<0)
            break;
        body = wsrc.substr(pos1+5,pos2-pos1-6);//text of body
        wsrc.erase(wsrc.begin()+pos1,wsrc.begin()+pos2+1);
            //wcout<<body<<endl;
    }
    //wcout<<body<<endl;
    string src = openfile(htmlpath1);
    string sub;
    while(true){
        int pos1 = src.find("link");//find css head
        if(pos1<0)
            break;
        int pos2 = src.find("href=\"",pos1+4);//head of css
        if (pos2<0)
            break;
        int pos3 = src.find(".css",pos2+6);  // tail of css
        sub = src.substr(pos2+6,pos3-pos2-2);//text of body
        if(sub.find(">",pos2)>pos3)
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            //cout<<sub<<endl;
            break;
    }
    string csspath = sub;
    string csssub =openfile(csspath);
    //cout << csssub<<endl;
    string bodysetting = getsetting(csssub,"body")+"end<stylechange>";
    string h1setting = getsetting(csssub,"h1")+"end<stylechange>";
    string h2setting = getsetting(csssub,"h2")+"end<stylechange>";
    string h3setting = getsetting(csssub,"h3")+"end<stylechange>";
    string h4setting = getsetting(csssub,"h4")+"end<stylechange>";
    string h5setting = getsetting(csssub,"h5")+"end<stylechange>";
    string h6setting = getsetting(csssub,"h6")+"end<stylechange>";
    string divsetting = getsetting(csssub,"div")+"end<stylechange>";
    string asetting = getsetting(csssub,"a ")+"end<stylechange>";//lack of href
    //cout << h1setting;
    wstring stylechange = L"<stylechange>";
    wstring bodytrans = L"";
    string allsetting = "";
    wstring imgset = L"";
    int countendl = 0;
    string setbuf;
    for(int i = 0; i < body.size();i++){
        if(body[i]=='<'){
            if(body[i+1]==L'p'){
                if(body[i+2]==L'>'){
                    countendl++;
                    if(countendl%8 == 7){
                       bodytrans += L"\\n"+ stylechange;
                       allsetting += setbuf;
                    }
               else  bodytrans += L"\\n";

                }
            }
            else if(body[i+1]==L'/'){
                if(body[i+2]==L'b'){
                    if(body[i+3]==L'r'){
                        if(body[i+4]==L'/'){
                            countendl++;
                            if(countendl%8 == 7){
                               bodytrans += L"\\n"+ stylechange;
                               allsetting += setbuf;
                            }
                            else bodytrans += L"\\n";
                            }
                        }
                    }
                }
            else if(body[i+1]==L'h'){
                if(body[i+2]==L'1'){
                    bodytrans += stylechange;
                allsetting += h1setting;
                setbuf = h1setting;}
                else if(body[i+2]==L'2'){
                    bodytrans += stylechange;
                allsetting += h2setting;
                setbuf = h2setting;}
                else if(body[i+2]==L'3'){
                    bodytrans += stylechange;
                allsetting += h3setting;
                setbuf = h3setting;}
                else if(body[i+2]==L'4'){
                    bodytrans += stylechange;
                allsetting += h4setting;
                setbuf = h4setting;}
                else if(body[i+2]==L'5'){
                    bodytrans += stylechange;
                allsetting += h5setting;
                setbuf = h5setting;}
                else if(body[i+2]==L'6'){
                    bodytrans += stylechange;
                allsetting += h6setting;
                setbuf = h6setting;}
            }
            else if(body[i+1]==L'd'){
                if(body[i+2]==L'i'){
                    if(body[i+3]==L'v'){
                        bodytrans += L"\\n"+stylechange;
                        if(body.find(L"class=",i)<body.find(L">",i)){
                            int pos1 = body.find(L"class=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wclassname = body.substr(pos1+7,pos2-pos1-7);
                            string classname = "."+wtos(wclassname)+" ";
                            allsetting += getsetting(csssub,classname)+"end<stylechange>";
                            setbuf = getsetting(csssub,classname)+"end<stylechange>";
                        }
                        else if(body.find(L"style=",i)<body.find(L">",i)){
                            int pos1 = body.find(L"style=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wstyle = body.substr(pos1+7,pos2-pos1-7);
                            string style = wtos(wstyle);
                            allsetting += settingdetail(style,"div") + "end<stylechange>";
                            setbuf = settingdetail(style,"div") + "end<stylechange>";
                        }
                       else {allsetting += divsetting;
                            setbuf = divsetting;}
                    }
                }
            }
            else if(body[i+1]==L'a'){
                int pos1 = body.find(L"href=",i);
                //int pos2 = body.find(L"\"",pos1+6);
                if(body.find(L">",i)>pos1)
                {//wstring href = body.substr(pos1 + 6,pos2 - pos1 - 6);
                //cout << href;
                bodytrans += stylechange;
                allsetting += asetting;
                setbuf = asetting;}
            }
            else if(body[i+1]==L'i'){
                if(body[i+2]==L'm'){
                    if(body[i+3]==L'g'){
                        bodytrans += stylechange + L"<img>";
                        int pos1 = body.find(L"src=");
                        int pos2 = body.find(L"\"",pos1 + 5);
                        imgset = body.substr(pos1+5,pos2-pos1-5);//wcout<<imgset;
                        if(body.find(L"style=",i)<body.find(L">",i)){
                            int posstyle1 = body.find(L"style=",i);
                            int posstyle2 = body.find(L"\"",posstyle1+7);
                            imgset += body.substr(posstyle1+7,posstyle2-posstyle1-7);
                                        //wcout << imgset;
                        }
                        else if(body.find(L"class=",i)<body.find(L">",i)){
                            int posclass1 = body.find(L"class=",i);
                            int posclass2 = body.find(L"\"",posclass1+7);
                            wstring wclassname = body.substr(posclass1+7,posclass2-posclass1-7);
                            string sclassname = "."+wtos(wclassname)+" ";
                            //cout << sclassname;
                            string fullsetting;
                            if(csssub.find(sclassname)!=string::npos){
                                    int pos1 = csssub.find("{",csssub.find(sclassname));
                                    int pos2 = csssub.find("}",pos1 + 1);
                                    fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
                                    string buf1;
                                    string setting = "height=";
                                    if(fullsetting.find("height")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("height"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"width=";
                                    }
                                    else
                                        setting += "100%width=";
                                    if(fullsetting.find("width")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("width"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"align=";
                                    }
                                    else
                                        setting += "100%align=";
                                    if(fullsetting.find("align")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("align"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2;
                                    }
                                    else
                                        setting += "middle";
                                    //cout << setting;
                                    imgset += stow(setting);
                                    //wcout << imgset;
                                }
                        }else{
                        if(body.find(L"height=",i)<body.find(L">",i)){
                            int posheight1 = body.find(L"height=",i);
                            int posheight2 = body.find(L"\"",posheight1+8);
                            imgset += body.substr(posheight1+8,posheight2-posheight1-8);
                        }else
                            imgset += L"height:100%";
                        if(body.find(L"width=",i)<body.find(L">",i)){
                            int poswidth1 = body.find(L"width=",i);
                            int poswidth2 = body.find(L"\"",poswidth1+7);
                            imgset += body.substr(poswidth1+7,poswidth2-poswidth1-7);
                        }else
                            imgset += L"width:100%";
                        if(body.find(L"align=",i)<body.find(L">",i)){
                            int posalign1 = body.find(L"align=",i);
                            int posalign2 = body.find(L"\"",posalign1+7);
                            imgset += body.substr(posalign1+7,posalign2-posalign1-7);
                        }else
                            imgset += L"align:middle";
                        }
                    }
                }
            }
            i = body.find(L'>',i);
        }
        else
        {
           bodytrans += body[i];}

    }
    bodytrans += stylechange;
    bodytrans = bodytrans.substr(14);
    //wcout <<bodytrans;
    //cout << allsetting;
    //wcout << imgset;

    QString qimgset = QString::fromStdWString(imgset);//
    TRANS output(bodytrans, allsetting, qimgset);
    //rename(htmlpath2.c_str(),htmlpath1.c_str());
    wofstream test;

    test.open("testfile.txt");
    test << bodytrans;
    test.close();
    wcout<<wopenfile("testfile.txt");
    ofstream test2;
    test2.open("testfile2.txt");
    test2 << allsetting;
    test2.close();
    wcout<<wopenfile("testfile2.txt");
    //system("pause");
    return output;
}

string getsetting(string csssub, string settingname){
    string fullsetting;
    if(csssub.find(settingname)!=string::npos){
            int pos1 = csssub.find("{",csssub.find(settingname));
            int pos2 = csssub.find("}",pos1 + 1);
            fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
            //cout << fullsetting;
        }
       string setting = settingdetail(fullsetting,settingname);
       return setting;
}
string settingdetail(string fullsetting,string settingname){
    string buf1;
    string setting = "color";
    if(fullsetting.find("color")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("color"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" font";
        if(settingname == "body"){
            bodydefault.color = buf2;}
    }
    else{
        setting += bodydefault.color+" font";
    }
    if(fullsetting.find("font-family")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("font-family"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" size";
        if(settingname == "body"){
            bodydefault.font = buf2;}
    }
    else{
        setting += bodydefault.font+" size";
    }if(fullsetting.find("font-size")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("font-size"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" bold";
        if(settingname == "body"){
            bodydefault.size = buf2;}
    }
    else{
        setting += bodydefault.size+" bold";
    }if(fullsetting.find("bold")!=string::npos){
        setting += "1 italic";
        if(settingname == "body"){
            bodydefault.bold = "1";}
    }
    else{
        setting += bodydefault.bold+" italic";
    }if(fullsetting.find("italic")!=string::npos){
        setting += "1 underline";
        if(settingname == "body"){
            bodydefault.italic = "1";}
    }
    else{
        setting += bodydefault.italic+" underline";
    }if(fullsetting.find("underline")!=string::npos){
        setting += "1";
        if(settingname == "body"){
            bodydefault.underline = "1";}
    }
    else{
        setting += bodydefault.underline;
    }


return setting;
}


